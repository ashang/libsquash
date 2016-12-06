# Libsquash

User-land SquashFS that can be linked and embedded within your application.

[![Build status: Linux and Darwin](https://travis-ci.org/enclose-io/libsquash.svg?branch=master)](https://travis-ci.org/enclose-io/libsquash)
[![Build status: Windows](https://ci.appveyor.com/api/projects/status/idimki81u783uab0?svg=true)](https://ci.appveyor.com/project/pmq20/libsquash)
[![Coverity Scan](https://scan.coverity.com/projects/11025/badge.svg)](https://scan.coverity.com/projects/pmq20-libsquash)

## Building

On most systems you could build and test the library using the following commands,

    mkdir build
    cd build
    cmake ..
    cmake --build .
    ctest

## API

### `squash_opendisk(data, data_size)`

Creates a new `squash_disk_t` instance by reading from `data`, which is of length `data_size`.
`data` should point to a `const uint8_t` array holding the binary content of the SquashFS file,
which could be generated by an independently installed `mksquashfs` tool and loaded into the memory in advance.
The returned resource should later be closed by `squash_closedisk()`.

### `squash_closedisk(disk)`

Frees the memory allocated for `disk`.
Note that the original referenced SquashFS data when creating `disk` will not be freed.

### `squash_stat(disk, path, buf)`

Obtains information about the file pointed to by `path` of the SquashFS `disk`.
The `buf` argument is a pointer to a stat structure as defined by
`<sys/stat.h>` and into which information is placed concerning the file.
Upon successful completion a value of `0` is returned.
Otherwise, a value of `-1` is returned.

### `squash_lstat(disk, path, buf)`

Acts like `squash_stat()` except in the case where the named file is a symbolic link;
`squash_lstat()` returns information about the link,
while `squash_stat()` returns information about the file the link references.

### `squash_fstat(disk, fildes, buf)`

Obtains the same information as `squash_stat()`
about an open file known by the Libsquash file descriptor `fildes`.

### `squash_open(disk, path)`

The file name specified by `path` of the SquashFS `disk` is opened for reading.
If successful, `squash_open()` returns a non-negative integer, termed a Libsquash file descriptor.
It returns `-1` on failure.
The file pointer (used to mark the current position within the file) is set to the beginning of the file.
The returned resource should later be closed by `squash_close()`.

### `squash_close(fildes)`

Deletes a Libsquash file descriptor from the per-SquashFS-disk object reference table.
If this is the last reference to the underlying object, the object will be deactivated.
For example, on the last close of a file the current seek pointer associated with the file is lost.
Upon successful completion, a value of `0` is returned.
Otherwise, a value of `-1` is returned and the global integer variable `squash_errno` is set to indicate the error.

### `squash_opendir(disk, filename)`

Opens the directory named by `filename` of the SquashFS `disk`,
associates a directory stream with it and returns a pointer
to be used to identify the directory stream in subsequent operations.
The pointer `NULL` is returned if `filename` cannot be accessed,
or if it cannot allocate enough memory to hold the whole thing,
and sets the global variable `squash_errno` to indicate the error.
The returned resource should later be closed by `squash_closedir()`.

### `squash_closedir(dirp)`

Closes the named directory stream and frees the structure associated with the `dirp` pointer,
returning `0` on success.
On failure, `-1` is returned and the global variable `squash_errno` is set to indicate the error.

### `squash_readdir(dirp)`

Returns a pointer to the next directory entry.
It returns `NULL` upon reaching the end of the directory or on error. 
In the event of an error, the global variable `squash_errno` is set to indicate the error.

### `squash_rewinddir(dirp)`

Resets the position of the named directory stream to the beginning of the directory.

### `squash_dirfd(dirp)`

Returns the integer Libsquash file descriptor associated with the named directory stream.
On failure, `-1` is returned and the global variable `squash_errno` is set to indicate the error.

### `squash_telldir(dirp)`

Returns the current location associated with the named directory stream.

### `squash_seekdir(dirp, loc)`

Sets the position of the next `squash_readdir()` operation on the directory stream.
The new position reverts to the one associated with the directory stream
when the `squash_telldir()` operation was performed.

### `squash_chdir(disk, path)`

Causes the named directory to become the current working directory of the SquashFS `disk`,
that is, the starting point for path searches of pathnames not beginning with a slash, `/`.
Upon successful completion, a value of `0` is returned. Otherwise, a value of `-1` is returned
and `squash_errno` is set to indicate the error.

### `squash_getcwd(disk, buf, size)`

Copies the absolute pathname of the current working directory of the SquashFS `disk`
into the memory referenced by `buf` and returns a pointer to `buf`.
The `size` argument is the size, in bytes, of the array referenced by `buf`.
If `buf` is `NULL`, space is allocated as necessary to store the pathname.
This space may later be `free`'d.

### `squash_chroot(disk, dirname)`

Causes `dirname` to become the root directory of the SquashFS `disk`,
that is, the starting point for path searches of pathnames beginning with `/`.

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/enclose-io/libsquash.

## Contributors

* [pmq20](https://github.com/pmq20) - **Minqi Pan** &lt;pmq2001@gmail.com&gt;

## License

Copyright (c) 2016 Libsquash contributers, under terms of the [MIT License](http://opensource.org/licenses/MIT).
