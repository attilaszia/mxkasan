mv build-magenta-qemu-arm64 build-magenta-qemu-arm64-clang
make -j32 magenta-qemu-arm64 USE_CLANG=yes
mv build-magenta-qemu-arm64-clang/ build-magenta-qemu-arm64
