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

The programmer must indicate to the PhysFs library the directory with which he wants to work, in this way no writing or reading that comes from the library will be able to leave the indicated directory, with this we gain security, also thanks to the flexibility of the library we will be able to work with all types of files, including Zip files that will be very useful to reduce the memory of the files without losing anything

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

### PHYSFS_init(): 

This function initializes the library, and should be called at the beginning.

+ Input: 

Don't need any element per parameter.

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

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List
```markdown
```
**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)


For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/unaidiaz/Assets-ZIP-management-with-PhysFS/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.
