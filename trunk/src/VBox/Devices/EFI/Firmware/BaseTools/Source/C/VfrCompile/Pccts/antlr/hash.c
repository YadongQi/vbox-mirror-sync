/*
 * hash.c
 *
 * Manage hash tables.
 *
 * The following functions are visible:
 *
 *		char	*mystrdup(char *);		Make space and copy string
 *		Entry 	**newHashTable();		Create and return initialized hash table
 *		Entry	*hash_add(Entry **, char *, Entry *)
 *		Entry	*hash_get(Entry **, char *)
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
 * ANTLR 1.33
 * Terence Parr
 * Parr Research Corporation
 * with Purdue University and AHPCRC, University of Minnesota
 * 1989-2001
 */

#include <stdio.h>
#include "pcctscfg.h"
#include "hash.h"

#ifdef __USE_PROTOS
#include <stdlib.h>
#else
#ifdef VAXC
#include <stdlib.h>
#else
#include <malloc.h>
#endif
#endif
#include <string.h>

#define StrSame		0

#define fatal(err)															\
			{fprintf(stderr, "%s(%d):", __FILE__, __LINE__);				\
			fprintf(stderr, " %s\n", err); exit(PCCTS_EXIT_FAILURE);}
#define require(expr, err) {if ( !(expr) ) fatal(err);}

static unsigned size = HashTableSize;
static char *strings = NULL;
static char *strp;
static unsigned strsize = StrTableSize;

/* create the hash table and string table for terminals (string table only once) */
Entry **
#ifdef __USE_PROTOS
newHashTable( void )
#else
newHashTable( )
#endif
{
	Entry **table;

	table = (Entry **) calloc(size, sizeof(Entry *));
	require( table != NULL, "cannot allocate hash table");
	if ( strings == NULL )
	{
		strings = (char *) calloc(strsize, sizeof(char));
		require( strings != NULL, "cannot allocate string table");
		strp = strings;
	}
	return table;
}

void
#ifdef __USE_PROTOS
killHashTable( Entry **table )
#else
killHashTable( table )
Entry **table;
#endif
{
	/* for now, just free table, forget entries */
	free( (char *) table );     /* MR10 cast */
}

/* Given a table, add 'rec' with key 'key' (add to front of list). return ptr to entry */
Entry *
#ifdef __USE_PROTOS
hash_add( Entry **table, char *key, Entry *rec )
#else
hash_add( table, key, rec )
Entry **table;
char *key;
Entry *rec;
#endif
{
	unsigned h=0;
	char *p=key;
	require(table!=NULL && key!=NULL && rec!=NULL, "add: invalid addition");

	Hash(p,h,size);
	rec->next = table[h];			/* Add to singly-linked list */
	table[h] = rec;
	return rec;
}

/* Return ptr to 1st entry found in table under key (return NULL if none found) */
Entry *
#ifdef __USE_PROTOS
hash_get( Entry **table, char *key )
#else
hash_get( table, key )
Entry **table;
char *key;
#endif
{
	unsigned h=0;
	char *p=key;
	Entry *q;
/*	require(table!=NULL && key!=NULL, "get: invalid table and/or key");*/
	if ( !(table!=NULL && key!=NULL) ) *((char *) 34) = 3;

	Hash(p,h,size);
	for (q = table[h]; q != NULL; q = q->next)
	{
		if ( strcmp(key, q->str) == StrSame ) return( q );
	}
	return( NULL );
}

#ifdef DEBUG_HASH
void
#ifdef __USE_PROTOS
hashStat( Entry **table )
#else
hashStat( table )
Entry **table;
#endif
{
	static unsigned short count[20];
	int i,n=0,low=0, hi=0;
	Entry **p;
	float avg=0.0;

	for (i=0; i<20; i++) count[i] = 0;
	for (p=table; p<&(table[size]); p++)
	{
		Entry *q = *p;
		int len;

		if ( q != NULL && low==0 ) low = p-table;
		len = 0;
		if ( q != NULL ) fprintf(stderr, "[%d]", p-table);
		while ( q != NULL )
		{
			len++;
			n++;
			fprintf(stderr, " %s", q->str);
			q = q->next;
			if ( q == NULL ) fprintf(stderr, "\n");
		}
		count[len]++;
		if ( *p != NULL ) hi = p-table;
	}

	fprintf(stderr, "Storing %d recs used %d hash positions out of %d\n",
					n, size-count[0], size);
	fprintf(stderr, "%f %% utilization\n",
					((float)(size-count[0]))/((float)size));
	for (i=0; i<20; i++)
	{
		if ( count[i] != 0 )
		{
			avg += (((float)(i*count[i]))/((float)n)) * i;
			fprintf(stderr, "Bucket len %d == %d (%f %% of recs)\n",
							i, count[i], ((float)(i*count[i]))/((float)n));
		}
	}
	fprintf(stderr, "Avg bucket length %f\n", avg);
	fprintf(stderr, "Range of hash function: %d..%d\n", low, hi);
}
#endif

/* Add a string to the string table and return a pointer to it.
 * Bump the pointer into the string table to next avail position.
 */
char *
#ifdef __USE_PROTOS
mystrdup( char *s )
#else
mystrdup( s )
char *s;
#endif
{
	char *start=strp;
	require(s!=NULL, "mystrdup: NULL string");

	while ( *s != '\0' )
	{
		require( strp <= &(strings[strsize-2]),
				 "string table overflow\nIncrease StrTableSize in hash.h and recompile hash.c\n");
		*strp++ = *s++;
	}
	*strp++ = '\0';

	return( start );
}
