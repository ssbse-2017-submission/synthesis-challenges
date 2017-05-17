#ifndef __PLINY_FILL__H
#define __PLINY_FILL__H

#include <stdarg.h>

/* the following API is used to indicate a hole */
void __pliny_fill__(int number_of_args, ...) { }

/* if READ_FROM is passed as an argument to __pliny_fill__()
then all the variables following it are expected to be read from
in the code that will be synthesized */ 
#define READ_FROM 0
/* if READ_FROM is passed as an argument to __pliny_fill__()
then all the variables following it are expected to be written to
in the code that will be synthesized */ 
#define WRITE_TO 1
/* if USE_VARS is passed as an argument to __pliny_fill__()
then a subset of the variables following it are expected to be "used"
in the code that will be synthesized */ 
#define USE_VARS 2
/* if ALL_VARS is passed as an argument to __pliny_fill__()
then a subset of all the variables available in scope at that program point 
will be attempted to be used in the code that will be synthesized */ 
#define ALL_VARS 3
/* if ALLOW_EARLY_RETURN is passed as an argument to __pliny_fill__()
then the code that will be synthesized may include early returns;
by default, early returns are not allowed in synthesized code */ 
#define ALLOW_EARLY_RETURN 4

#endif /* __PLINY_FILL__H */
