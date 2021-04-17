# Links

- [PhysFs official page](https://icculus.org/physfs/)

- [PhysFs documentation](https://icculus.org/physfs/docs/html/globals.html)

- [Handout](https://github.com/unaidiaz/Assets-ZIP-management-with-PhysFS/tree/main/Handout)

- [Solution](https://github.com/unaidiaz/Assets-ZIP-management-with-PhysFS/tree/main/Solution)

- [Release](https://github.com/unaidiaz/Assets-ZIP-management-with-PhysFS/releases/tag/1.0)

# Main objectives

The general objective of using this library is to have the assest in a zip to get the advantages mentioned in the previous point.

Our goal will be to move from the first image to the second.

- First image (what we have):

![Image](https://github.com/unaidiaz/Assets-ZIP-management-with-PhysFS/blob/main/Docs/images/old.PNG?raw=true)

- Second image (our objetive):

![Image](https://github.com/unaidiaz/Assets-ZIP-management-with-PhysFS/blob/main/Docs/images/new.PNG?raw=true)

# What is PhysFs?

PhysFs is a library that allows us to access files in an abstract way. This will be very useful for video games.

![Image](http://www.alegsa.com.ar/Imagen/jerarquia_directorios.jpg)

The programmer must indicate to the PhysFs library the directory with which he wants to work, in this way no writing or reading that comes from the library will be able to leave the indicated directory, with this we gain security, also thanks to the flexibility of the library we will be able to work with all types of files, including Zip files that will be very useful to reduce the memory of the files without losing anything.

One of the main points and features of a filesystem is abstraction. With a filesystem, we can organize our data into files, directories, and other constructs, and manipulate them in various ways. To open a file, you need only its path; it's not necessary to figure out the exact location on disk and instruct the hard drive controller to move the read head to that position.

This data abstraction is important for several reasons:

- Portability; it's not necessary to port every program for all hardware, only the device drivers need to be changed.
- Security; the user is not relied on ‒ or even allowed ‒ to access the drive directly.
- Convenience; files don't actually exist as separate entities on disk, but it sure makes it easier for people to use computers.

In summary, using this library we obtain these advantages:

- Security, the library will not allow reading or writing outside of the given directory.
- Flexibility, we can use Zip files as a directory. 
- Saving space, by using a zip file to save assets we achieve that our game takes up less memory space.

This library is supported by the following archives:

- ZIP (pkZip/WinZip/Info-ZIP compatible)                                                                 
- 7Z (7zip archives)
- ISO (ISO9660 files, CD-ROM images)
- GRP (Build Engine groupfile archives)
- PAK (Quake I/II archive format)
- HOG (Descent I/II HOG file archives)
- MVL (Descent II movielib archives)
- WAD (DOOM engine archives)
- VDF (Gothic I/II engine archives)
- SLB (Independence War archives)

# PhysFs

## PHYSFS functions

### PHYSFS_init(const char* argv0): 

This function initializes the library, and should be called at the beginning.

+ Input: 

**argv0:** The argv[0] string passed to your program's mainline. This may be NULL on most platforms.

+ Output:

 Nonzero on success, zero on error, the error can be specified with the function PHYSFS_getLastError().

### PHYSFS_deinit(): 

Deinitialize the PhysicsFS library, closes any files opened via PhysicsFS, blanks the search/write paths, frees memory.

+ Input: 

Don't need any element per parameter.

+ Output: 

Nonzero on success, zero on error, the error can be specified with the function PHYSFS_getLastError().

### PHYSFS_mount(const char * newDir,const char * mountPoint,int appendToPath ):

Add an archive or directory to the search path.

+ Input:

**NewDir:** Directory or archive to add to the path.

**MountPoint:** Location in the interpolated tree that this archive will be "mounted". NULL or "" is equivalent to "/".

**AppendToPath:** Nonzero to append to search path, zero to prepend.

+ Output: 

Nonzero if added to path, zero on failure (bogus archive, dir missing, etc). Use PHYSFS_getLastErrorCode() to obtain the specific error.

### PHYSFS_openRead(const char* filename):

Open a file for reading.

+ Input: 

**Filename:** File to open.

+ Output:

A valid  PHYSFS_File *  on success, NULL on error. Use PHYSFS_getLastErrorCode() to obtain the specific error.

### PHYSFS_close(PHYSFS_file* handle):

Close a PhysicsFS filehandle.

+ Input: 

**handle:** File to close.

+ Output:

Nonzero on success, zero on error. Use PHYSFS_getLastErrorCode() to obtain the specific error.

### PHYSFS_fileLength(PHYSFS_file* handle):

Get total length of a file in bytes.

+ Input: 

**Handle:** handle returned from PHYSFS_open*() -  (PHYSFS_File *).

+ Output:

size in bytes of the file, -1 if can't be determined.

### PHYSFS_Read (PHYSFS_File* handle, void* buffer, PHYSFS_uint32 objSize, PHYSFS_uint32 objCount):

Read data from a PhysicsFS filehandle, the file must be opened for reading with PHYSFS_openRead(const char* filename).

+ Input: 

**Handle:** handle returned from PHYSFS_openRead().

**Buffer:** buffer to store read data into.obj

**Size:** size in bytes of objects being read from (handle).

**ObjCount:** number of (objSize) objects to read from (handle).

+ Output:

number of objects read, -1 if complete failure.

# TODOS

do all the TODOS to make sure you have understood the concepts that have been explained and the functions of Phys Fs.

## Handout (Before TODOS)

This is what you will find when you compile the handout.

![Image](https://github.com/unaidiaz/Assets-ZIP-management-with-PhysFS/blob/main/Docs/images/im01.PNG?raw=true)

## Expected solution

This is the solution that is expected after doing the TODOS.

## TODO 1

Initialize the Phys Fs library.

## TODO 2

Deinitialize the phys Fs library.

## TODO 3

Add a path to the library.

## TODO 4

Call the function MakeLoad to obtain the information buffer and be able to return a SDL_RWops structure for the textures and the audio.

## TODO 5

Obtain the information buffer with the library functions and return the size of this.

## TODO 6

Get only the information buffer, then load the XML file, finally delete the information buffer.
