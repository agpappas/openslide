/*
 *  OpenSlide, a library for reading whole slide image files
 *
 *  Copyright (c) 2007-2012 Carnegie Mellon University
 *  All rights reserved.
 *
 *  OpenSlide is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, version 2.1.
 *
 *  OpenSlide is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with OpenSlide. If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#ifndef OPENSLIDE_OPENSLIDE_FEATURES_H_
#define OPENSLIDE_OPENSLIDE_FEATURES_H_


// for exporting from shared libraries or DLLs
#if defined _WIN32
#  ifdef _OPENSLIDE_BUILDING_DLL
#    define OPENSLIDE_PUBLIC() __declspec(dllexport)
#  else
#    define OPENSLIDE_PUBLIC() __declspec(dllimport)
#  endif
#elif __GNUC__ > 3
# define OPENSLIDE_PUBLIC() __attribute__ ((visibility("default")))
#else
# define OPENSLIDE_PUBLIC()
#endif


// if possible, produce compiler warnings when deprecated functions
// are used
#if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1)
# define OPENSLIDE_DEPRECATED() __attribute__((deprecated))
#else
# define OPENSLIDE_DEPRECATED()
#endif

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5)
# define OPENSLIDE_DEPRECATED_FOR(f) \
  __attribute__((deprecated("Use " #f " instead")))
#else
# define OPENSLIDE_DEPRECATED_FOR(f) OPENSLIDE_DEPRECATED()
#endif


#endif
