# Links

- [PhysFs official page](https://icculus.org/physfs/)

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

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/unaidiaz/Assets-ZIP-management-with-PhysFS/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.
