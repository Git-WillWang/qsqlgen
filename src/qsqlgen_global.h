#ifndef QSQLGEN_GLOBAL_H
#define QSQLGEN_GLOBAL_H


#if defined(QSQLGEN_LIBRARY)
#define QSQLGEN_EXPORT Q_DECL_EXPORT
#else
#define QSQLGEN_EXPORT Q_DECL_IMPORT
#endif


#endif // QSQLGEN_GLOBAL_H
