#ifndef DYNLIB_GLOBAL_H
#define DYNLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DYNLIB_LIBRARY)
#  define DYNLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DYNLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DYNLIB_GLOBAL_H
