import subprocess
import time
import re
import os

result = [os.path.join(dp, f)[2:] for dp, dn, filenames in os.walk("./kernel/lib/magenta") for f in filenames if f[-3:]=='cpp'  ] #possible filter

print result


def build_source(sourcetobuild, revert = False):

    output = subprocess.check_output("make -j32 magenta-qemu-arm64 USE_CLANG=yes --just-print | grep "+ sourcetobuild, shell=True)

    sanitizer = " -fsanitize=kernel-address -mllvm -asan-stack=0"

    if (revert):
        sanitizer = ""

    print "Compiling " + sourcetobuild

    command = output.split('\n',1)[1]
    command = re.findall("(.*)echo",command, flags=re.DOTALL)[0][:-1]
    print command

    print subprocess.check_output(command +sanitizer, shell=True)

    print "Linking it in"

    print subprocess.check_output("make -j32 magenta-qemu-arm64 USE_CLANG=yes", shell =True)

for filetobuild in result:
    build_source(filetobuild)

    print "Starting up kernel"

    p = subprocess.Popen("./scripts/run-magenta-arm64 -C", shell=True, stdout=subprocess.PIPE)
    data = p.stdout.read(10000)
    p.kill()

    if ( len(re.findall("MXKASAN", data)) > 0):
        print "Success"
    else:
        print "Did not boot correctly, revert"
        build_source(filetobuild, True)





