DEBUG
=====

This is a simple C function for general debugging. You simply call it like DEBUG(5, "i = %d", i); where 5 is the debug level and all the rest is just like the printf family. Afterwards set the variable debug to some value through either a configuration file, command line arguments or hell even hard code it. All DEBUG()'s with a debug level either the same or higher will be printed. If performance is important and it is fully debugged you can simply #define NO_DEBUG to remove all the debug statements.
