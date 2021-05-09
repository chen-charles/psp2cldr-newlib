Compiling Newlib for `psp2cldr`
========
 * Configure: `CFLAGS_FOR_TARGET="-g -O2 -fPIC" ../newlib-cygwin/configure --target=arm-vita-eabi`
 * Compile `libc.a` to `libc.so` with `arm-vita-eabi-gcc -shared -o libc.so -Wl,--hash-style=sysv,--whole-archive arm-vita-eabi/newlib/libc.a -nostdlib`  
 * Compile `libm.a` to `libm.so`  


```sh
cd /root

mkdir autotools_build
cd autotools_build
wget http://ftp.gnu.org/gnu/m4/m4-1.4.17.tar.gz
wget http://ftp.gnu.org/gnu/autoconf/autoconf-2.64.tar.gz
wget http://ftp.gnu.org/gnu/automake/automake-1.11.1.tar.gz
wget http://ftp.gnu.org/gnu/libtool/libtool-2.4.tar.gz
gzip -dc m4-1.4.17.tar.gz | tar xvf -
gzip -dc autoconf-2.64.tar.gz | tar xvf -
gzip -dc automake-1.11.1.tar.gz | tar xvf -
gzip -dc libtool-2.4.tar.gz | tar xvf -
cd m4-1.4.17
./configure -C && make && make install
cd ../autoconf-2.64
./configure -C && make && make install
cd ../automake-1.11.1
./configure -C && make && make install
cd ../libtool-2.4
./configure -C && make && make install

# modify newlib as needed, then regenerate Makefiles for sys/vita if you need more files

cd ../..
mkdir newlib-build
cd newlib-build

../newlib-cygwin/configure "CFLAGS_FOR_TARGET=-g -O2 -fPIC -ffunction-sections -fdata-sections" --prefix=/root/newlib-build/out --target=arm-vita-eabi --enable-newlib-io-long-long --enable-newlib-register-fini --disable-newlib-supplied-syscalls --disable-nls
make && make install

# ideally you need "-lgcc", but libgcc.a is not compiled with "-fPIC" ...
arm-vita-eabi-gcc -shared -o libc.so -Wl,--hash-style=sysv,--whole-archive arm-vita-eabi/newlib/libc.a -nostdlib
arm-vita-eabi-gcc -shared -o libm.so -Wl,--hash-style=sysv,--whole-archive arm-vita-eabi/newlib/libm.a -nostdlib
```
