/* dlg header file
 *
 * SOFTWARE RIGHTS
 *
 * We reserve no LEGAL rights to the Purdue Compiler Construction Tool
 * Set (PCCTS) -- PCCTS is in the public domain.  An individual or
 * company may do whatever they wish with source code distributed with
 * PCCTS or the code generated by PCCTS, including the incorporation of
 * PCCTS, or its output, into commerical software.
 *
 * We encourage users to develop software with PCCTS.  However, we do ask
 * that credit is given to us for developing PCCTS.  By "credit",
 * we mean that if you incorporate our source code into one of your
 * programs (commercial product, research project, or otherwise) that you
 * acknowledge this fact somewhere in the documentation, research report,
 * etc...  If you like PCCTS and have developed a nice tool with the
 * output, please mention that you developed it using PCCTS.  In
 * addition, we ask that this header remain intact in our source code.
 * As long as these guidelines are kept, we expect to continue enhancing
 * this system and expect to make other tools available as they are
 * completed.
 *
 * DLG 1.33
 * Will Cohen
 * With mods by Terence Parr; AHPCRC, University of Minnesota
 * 1989-2001
 */

/* MR1 Move pcctscfg.h to top of file 					*/

#include "pcctscfg.h"						

/* turn off warnings for unreferenced labels */

#ifdef _MSC_VER
#pragma warning(disable:4102)
#endif

#include "set.h"

#define TRUE	1
#define FALSE	0

/***** output related stuff *******************/
#define IN	input_stream
#define OUT	output_stream

#define MAX_MODES	50	/* number of %%names allowed */
#define MAX_ON_LINE	10

#define NFA_MIN		64	/* minimum nfa_array size */
#define DFA_MIN		64	/* minimum dfa_array size */

#define DEFAULT_CLASSNAME "DLGLexer"

/* these macros allow the size of the character set to be easily changed */
/* NOTE: do NOT change MIN_CHAR since EOF is the lowest char, -1 */
#define MIN_CHAR (-1)	/* lowest possible character possible on input */
#define MAX_CHAR 255	/* highest possible character possible on input */
#define CHAR_RANGE (1+(MAX_CHAR) - (MIN_CHAR))

/* indicates that the not an "array" reference */
#define NIL_INDEX 0

/* size of hash table used to find dfa_states quickly */
#define HASH_SIZE 211

#define nfa_node struct _nfa_node
nfa_node {
	int		node_no;
	int		nfa_set;
	int		accept;	/* what case to use */
	nfa_node	*trans[2];
	set		label;	/* one arc always labelled with epsilon */
};

#define dfa_node struct _dfa_node
dfa_node {
	int		node_no;
	int		dfa_set;
	int		alternatives;	/* used for interactive mode */
					/* are more characters needed */
	int		done;
	set		nfa_states;
	int		trans[1];/* size of transition table depends on
				  * number of classes required for automata.
				  */


};

/******** macros for accessing the NFA and DFA nodes ****/
#define NFA(x)	(nfa_array[x])
#define DFA(x)	(dfa_array[x])
#define DFA_NO(x) ( (x) ? (x)->node_no : NIL_INDEX)
#define NFA_NO(x) ( (x) ? (x)->node_no : NIL_INDEX)

/******** wrapper for memory checking ***/
/*#define malloc(x)	dlg_malloc((x),__FILE__,__LINE__)*/

/*#define calloc(x,y)	dlg_calloc((x),(y),__FILE__,__LINE__)*/

/******** antlr attributes *************/
typedef struct {
	unsigned char letter;
	nfa_node *l,*r;
	set label;
	} Attrib;

#define zzcr_attr(attr, token, text) {					\
	(attr)->letter = text[0]; (attr)->l = NULL;			\
	(attr)->r = NULL; (attr)->label = empty;			\
}
#define zzd_attr(a)	set_free((a)->label);

/******************** Variable ******************************/
extern char	program[];	/* tells what program this is */
extern char	version[];	/* tells what version this is */
extern char	*file_str[];	/* file names being used */
extern int	err_found;	/* flag to indicate error occured */
extern int	action_no;	/* last action function printed */
extern int	func_action;	/* should actions be turned into functions?*/
extern set	used_chars;	/* used to label trans. arcs */
extern set	used_classes;	/* classes or chars used to label trans. arcs */
extern int	class_no;	/* number of classes used */
extern set	class_sets[];	/* shows char. in each class */
extern set	normal_chars;	/* mask off unused portion of set */
extern int	comp_level;	/* what compression level to use */
extern int	interactive;	/* interactive scanner (avoid lookahead)*/
extern int	mode_counter;	/* keeps track of the number of %%name */
extern int	dfa_basep[];	/* start of each group of dfa */
extern int	dfa_class_nop[];/* number of transistion arcs in */
				/* each dfa in each mode */
extern int	nfa_allocated;
extern int	dfa_allocated;
extern nfa_node	**nfa_array;	/* start of nfa "array" */
extern dfa_node	**dfa_array;	/* start of dfa "array" */
extern int	operation_no;	/* unique number for each operation */
extern FILE	*input_stream;	/* where description read from */
extern FILE	*output_stream; /* where to put the output */
extern FILE	*mode_stream;	/* where to put the mode output */
extern FILE	*class_stream;
extern char	*mode_file;	/* name of file for mode output */
extern int	gen_ansi;	/* produce ansi compatible code */
extern int	case_insensitive;/* ignore case of input spec. */
extern int	warn_ambig;	/* show if regular expressions ambiguous */
extern int	gen_cpp;
extern char *cl_file_str;
extern int	firstLexMember;	/* MR1 */
extern char *OutputDirectory;
extern char	*class_name;

/******************** Functions ******************************/
#ifdef __USE_PROTOS
extern char 	*dlg_malloc(int, char *, int); /* wrapper malloc */
extern char 	*dlg_calloc(int, int, char *, int); /* wrapper calloc */
extern int	reach(unsigned *, register int, unsigned *);
extern set	closure(set *, unsigned *);
extern dfa_node *new_dfa_node(set);
extern nfa_node *new_nfa_node(void);
extern dfa_node *dfastate(set);
extern dfa_node **nfa_to_dfa(nfa_node *);
extern void	internal_error(char *, char *, int);    /* MR9 23-Sep-97 */
extern FILE	*read_stream(char *);	/* opens file for reading */
extern FILE	*write_stream(char *);	/* opens file for writing */
extern void	make_nfa_model_node(void);
extern void	make_dfa_model_node(int);
extern char *ClassName(char *);
extern char *OutMetaName(char *);
extern void error(char*, int);
extern void warning(char*, int);
extern void p_head(void);
extern void p_class_hdr(void);
extern void p_includes(void);
extern void p_tables(void);
extern void p_tail(void);					/* MR1 */
extern void p_class_def1(void);				/* MR1 */
extern void new_automaton_mode(void);			/* MR1 */
extern int  relabel(nfa_node *,int);			/* MR1 */
extern void p_shift_table(int);				/* MR1 */
extern void p_bshift_table(void);				/* MR1 */
extern void p_class_table(void);				/* MR1 */
extern void p_mode_def(char *,int);			/* MR1 */
extern void init(void);					/* MR1 */
extern void p_class_def2(void);				/* MR1 */
extern void clear_hash(void);				/* MR1 */
extern void p_alternative_table(void);			/* MR1 */
extern void p_node_table(void);				/* MR1 */
extern void p_dfa_table(void);				/* MR1 */
extern void p_accept_table(void);				/* MR1 */
extern void p_action_table(void);				/* MR1 */
extern void p_base_table(void);				/* MR1 */
extern void p_single_node(int,int);			/* MR1 */
extern char * minsize(int);				/* MR1 */
extern void close1(nfa_node *,int,set *);		/* MR1 */
extern void partition(nfa_node *,int);			/* MR1 */
extern void intersect_nfa_labels(nfa_node *,set *);	/* MR1 */
extern void r_intersect(nfa_node *,set *);		/* MR1 */
extern void label_node(nfa_node *);			/* MR1 */
extern void label_with_classes(nfa_node *);		/* MR1 */

#else
extern char *dlg_malloc();	/* wrapper malloc */
extern char *dlg_calloc();	/* wrapper calloc */
extern int	reach();
extern set	closure();
extern dfa_node *new_dfa_node();
extern nfa_node *new_nfa_node();
extern dfa_node *dfastate();
extern dfa_node **nfa_to_dfa();
extern void	internal_error();   /* MR9 23-Sep-97 */
extern FILE	*read_stream();		/* opens file for reading */
extern FILE	*write_stream();	/* opens file for writing */
extern void	make_nfa_model_node();
extern void	make_dfa_model_node();
extern char *ClassName();
extern char *OutMetaName();
extern void error();
extern void warning();
extern void p_head();                   /* MR9 */
extern void p_class_hdr();              /* MR9 */
extern void p_includes();               /* MR9 */
extern void p_tables();                 /* MR9 */
extern void p_tail();					/* MR1 */
extern void p_class_def1();				/* MR1 */
extern void new_automaton_mode();			/* MR1 */
extern int  relabel();					/* MR1 */
extern void p_shift_table();				/* MR1 */
extern void p_bshift_table();				/* MR1 */
extern void p_class_table();				/* MR1 */
extern void p_mode_def();				/* MR1 */
extern void init();					/* MR1 */
extern void p_class_def2();				/* MR1 */
extern void clear_hash();				/* MR1 */
extern void p_alternative_table();			/* MR1 */
extern void p_node_table();				/* MR1 */
extern void p_dfa_table();				/* MR1 */
extern void p_accept_table();				/* MR1 */
extern void p_action_table();				/* MR1 */
extern void p_base_table();				/* MR1 */
extern void p_single_node();				/* MR1 */
extern char * minsize();				/* MR1 */
extern void close1();					/* MR1 */
extern void partition();				/* MR1 */
extern void intersect_nfa_labels();			/* MR1 */
extern void r_intersect();				/* MR1 */
extern void label_node();				/* MR1 */
extern void label_with_classes();			/* MR1 */

#endif
