#ifndef tools_h
#define tools_h


#define MPRINT(x)   	Serial.print((x))
#define MPRINTLN(x) 	Serial.println((x))

#define MPRINTS(x)   	MPRINT(F(x))
#define MPRINTLNS(x)    MPRINTLN(F(x))

#define MPRINTSVAL(s,x)  	MPRINTS(s);MPRINTLN(x)
#define MPRINTSVALS(s,x,z)  MPRINTS(s);MPRINT(x);MPRINTLNS(z)

int freeRam ();

#endif
