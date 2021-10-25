/* yvals.h values header -- UNIX 680X0 version */
#define _YVALS
		/* errno properties */
#define _EDOM	33
#define _ERANGE	34
#define _EFPOS	35
#define _ERRMAX	36
		/* float properties */
#define _D0		0
#define _DBIAS	0x3fe
#define _DLONG	0
#define _DOFF	4
#define _FBIAS	0x7e
#define _FOFF	7
#define _FRND	1
#define _LBIAS	0x3fe
#define _LOFF	4
		/* integer properties */
#define _C2		1
#define _CSIGN	1
#define _ILONG	1
#define _MBMAX	8
typedef unsigned short _Wchart;
		/* pointer properties */
#define _NULL	(void *)0
typedef int _Ptrdifft;
typedef unsigned int _Sizet;
		/* setjmp properties */
#define _NSETJMP	80
extern int _Setjmp(int *);
		/* signal properties */
#define _SIGABRT	6
#define _SIGMAX		32
		/* stdio properties */
#define _FNAMAX	64
#define _FOPMAX	16
#define _TNAMAX	16
		/* stdlib properties */
#define _EXFAIL	1
		/* storage alignment properties */
#define _AUPBND 3U
#define _ADNBND 0U
#define _MEMBND	3U
		/* time properties */
#define _CPS	1
#define _TBIAS	((70 * 365LU + 17) * 86400)
