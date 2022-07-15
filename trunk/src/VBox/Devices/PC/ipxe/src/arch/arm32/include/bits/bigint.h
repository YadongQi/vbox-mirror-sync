#ifndef _BITS_BIGINT_H
#define _BITS_BIGINT_H

/** @file
 *
 * Big integer support
 */

FILE_LICENCE ( GPL2_OR_LATER_OR_UBDL );

#include <stdint.h>
#include <string.h>
#include <strings.h>

/** Element of a big integer */
typedef uint32_t bigint_element_t;

/**
 * Initialise big integer
 *
 * @v value0		Element 0 of big integer to initialise
 * @v size		Number of elements
 * @v data		Raw data
 * @v len		Length of raw data
 */
static inline __attribute__ (( always_inline )) void
bigint_init_raw ( uint32_t *value0, unsigned int size,
		  const void *data, size_t len ) {
	size_t pad_len = ( sizeof ( bigint_t ( size ) ) - len );
	uint8_t *value_byte = ( ( void * ) value0 );
	const uint8_t *data_byte = ( data + len );

	/* Copy raw data in reverse order, padding with zeros */
	while ( len-- )
		*(value_byte++) = *(--data_byte);
	while ( pad_len-- )
		*(value_byte++) = 0;
}

/**
 * Add big integers
 *
 * @v addend0		Element 0 of big integer to add
 * @v value0		Element 0 of big integer to be added to
 * @v size		Number of elements
 */
static inline __attribute__ (( always_inline )) void
bigint_add_raw ( const uint32_t *addend0, uint32_t *value0,
		 unsigned int size ) {
	bigint_t ( size ) __attribute__ (( may_alias )) *value =
		( ( void * ) value0 );
	uint32_t *discard_addend;
	uint32_t *discard_value;
	uint32_t *discard_end;
	uint32_t discard_addend_i;
	uint32_t discard_value_i;

	__asm__ __volatile__ ( "adds %2, %0, %8, lsl #2\n\t" /* clear CF */
			       "\n1:\n\t"
			       "ldmia %0!, {%3}\n\t"
			       "ldr %4, [%1]\n\t"
			       "adcs %4, %3\n\t"
			       "stmia %1!, {%4}\n\t"
			       "teq %0, %2\n\t"
			       "bne 1b\n\t"
			       : "=l" ( discard_addend ),
				 "=l" ( discard_value ),
				 "=l" ( discard_end ),
				 "=l" ( discard_addend_i ),
				 "=l" ( discard_value_i ),
				 "+m" ( *value )
			       : "0" ( addend0 ), "1" ( value0 ), "l" ( size )
			       : "cc" );
}

/**
 * Subtract big integers
 *
 * @v subtrahend0	Element 0 of big integer to subtract
 * @v value0		Element 0 of big integer to be subtracted from
 * @v size		Number of elements
 */
static inline __attribute__ (( always_inline )) void
bigint_subtract_raw ( const uint32_t *subtrahend0, uint32_t *value0,
		      unsigned int size ) {
	bigint_t ( size ) __attribute__ (( may_alias )) *value =
		( ( void * ) value0 );
	uint32_t *discard_subtrahend;
	uint32_t *discard_value;
	uint32_t *discard_end;
	uint32_t discard_subtrahend_i;
	uint32_t discard_value_i;

	__asm__ __volatile__ ( "add %2, %0, %8, lsl #2\n\t"
			       "cmp %2, %0\n\t" /* set CF */
			       "\n1:\n\t"
			       "ldmia %0!, {%3}\n\t"
			       "ldr %4, [%1]\n\t"
			       "sbcs %4, %3\n\t"
			       "stmia %1!, {%4}\n\t"
			       "teq %0, %2\n\t"
			       "bne 1b\n\t"
			       : "=l" ( discard_subtrahend ),
				 "=l" ( discard_value ),
				 "=l" ( discard_end ),
				 "=l" ( discard_subtrahend_i ),
				 "=l" ( discard_value_i ),
				 "+m" ( *value )
			       : "0" ( subtrahend0 ), "1" ( value0 ),
				 "l" ( size )
			       : "cc" );
}

/**
 * Rotate big integer left
 *
 * @v value0		Element 0 of big integer
 * @v size		Number of elements
 */
static inline __attribute__ (( always_inline )) void
bigint_rol_raw ( uint32_t *value0, unsigned int size ) {
	bigint_t ( size ) __attribute__ (( may_alias )) *value =
		( ( void * ) value0 );
	uint32_t *discard_value;
	uint32_t *discard_end;
	uint32_t discard_value_i;

	__asm__ __volatile__ ( "adds %1, %0, %5, lsl #2\n\t" /* clear CF */
			       "\n1:\n\t"
			       "ldr %2, [%0]\n\t"
			       "adcs %2, %2\n\t"
			       "stmia %0!, {%2}\n\t"
			       "teq %0, %1\n\t"
			       "bne 1b\n\t"
			       : "=l" ( discard_value ),
				 "=l" ( discard_end ),
				 "=l" ( discard_value_i ),
				 "+m" ( *value )
			       : "0" ( value0 ), "1" ( size )
			       : "cc" );
}

/**
 * Rotate big integer right
 *
 * @v value0		Element 0 of big integer
 * @v size		Number of elements
 */
static inline __attribute__ (( always_inline )) void
bigint_ror_raw ( uint32_t *value0, unsigned int size ) {
	bigint_t ( size ) __attribute__ (( may_alias )) *value =
		( ( void * ) value0 );
	uint32_t *discard_value;
	uint32_t *discard_end;
	uint32_t discard_value_i;

	__asm__ __volatile__ ( "adds %1, %0, %5, lsl #2\n\t" /* clear CF */
			       "\n1:\n\t"
			       "ldmdb %1!, {%2}\n\t"
			       "rrxs %2, %2\n\t"
			       "str %2, [%1]\n\t"
			       "teq %0, %1\n\t"
			       "bne 1b\n\t"
			       : "=l" ( discard_value ),
				 "=l" ( discard_end ),
				 "=l" ( discard_value_i ),
				 "+m" ( *value )
			       : "0" ( value0 ), "1" ( size )
			       : "cc" );
}

/**
 * Test if big integer is equal to zero
 *
 * @v value0		Element 0 of big integer
 * @v size		Number of elements
 * @ret is_zero		Big integer is equal to zero
 */
static inline __attribute__ (( always_inline, pure )) int
bigint_is_zero_raw ( const uint32_t *value0, unsigned int size ) {
	const uint32_t *value = value0;
	uint32_t value_i;

	do {
		value_i = *(value++);
		if ( value_i )
			break;
	} while ( --size );

	return ( value_i == 0 );
}

/**
 * Compare big integers
 *
 * @v value0		Element 0 of big integer
 * @v reference0	Element 0 of reference big integer
 * @v size		Number of elements
 * @ret geq		Big integer is greater than or equal to the reference
 */
static inline __attribute__ (( always_inline, pure )) int
bigint_is_geq_raw ( const uint32_t *value0, const uint32_t *reference0,
		    unsigned int size ) {
	const uint32_t *value = ( value0 + size );
	const uint32_t *reference = ( reference0 + size );
	uint32_t value_i;
	uint32_t reference_i;

	do {
		value_i = *(--value);
		reference_i = *(--reference);
		if ( value_i != reference_i )
			break;
	} while ( --size );

	return ( value_i >= reference_i );
}

/**
 * Test if bit is set in big integer
 *
 * @v value0		Element 0 of big integer
 * @v size		Number of elements
 * @v bit		Bit to test
 * @ret is_set		Bit is set
 */
static inline __attribute__ (( always_inline )) int
bigint_bit_is_set_raw ( const uint32_t *value0, unsigned int size,
			unsigned int bit ) {
	const bigint_t ( size ) __attribute__ (( may_alias )) *value =
		( ( const void * ) value0 );
	unsigned int index = ( bit / ( 8 * sizeof ( value->element[0] ) ) );
	unsigned int subindex = ( bit % ( 8 * sizeof ( value->element[0] ) ) );

	return ( value->element[index] & ( 1 << subindex ) );
}

/**
 * Find highest bit set in big integer
 *
 * @v value0		Element 0 of big integer
 * @v size		Number of elements
 * @ret max_bit		Highest bit set + 1 (or 0 if no bits set)
 */
static inline __attribute__ (( always_inline )) int
bigint_max_set_bit_raw ( const uint32_t *value0, unsigned int size ) {
	const uint32_t *value = ( value0 + size );
	int max_bit = ( 8 * sizeof ( bigint_t ( size ) ) );
	uint32_t value_i;

	do {
		value_i = *(--value);
		max_bit -= ( 32 - fls ( value_i ) );
		if ( value_i )
			break;
	} while ( --size );

	return max_bit;
}

/**
 * Grow big integer
 *
 * @v source0		Element 0 of source big integer
 * @v source_size	Number of elements in source big integer
 * @v dest0		Element 0 of destination big integer
 * @v dest_size		Number of elements in destination big integer
 */
static inline __attribute__ (( always_inline )) void
bigint_grow_raw ( const uint32_t *source0, unsigned int source_size,
		  uint32_t *dest0, unsigned int dest_size ) {
	unsigned int pad_size = ( dest_size - source_size );

	memcpy ( dest0, source0, sizeof ( bigint_t ( source_size ) ) );
	memset ( ( dest0 + source_size ), 0, sizeof ( bigint_t ( pad_size ) ) );
}

/**
 * Shrink big integer
 *
 * @v source0		Element 0 of source big integer
 * @v source_size	Number of elements in source big integer
 * @v dest0		Element 0 of destination big integer
 * @v dest_size		Number of elements in destination big integer
 */
static inline __attribute__ (( always_inline )) void
bigint_shrink_raw ( const uint32_t *source0, unsigned int source_size __unused,
		    uint32_t *dest0, unsigned int dest_size ) {

	memcpy ( dest0, source0, sizeof ( bigint_t ( dest_size ) ) );
}

/**
 * Finalise big integer
 *
 * @v value0		Element 0 of big integer to finalise
 * @v size		Number of elements
 * @v out		Output buffer
 * @v len		Length of output buffer
 */
static inline __attribute__ (( always_inline )) void
bigint_done_raw ( const uint32_t *value0, unsigned int size __unused,
		  void *out, size_t len ) {
	const uint8_t *value_byte = ( ( const void * ) value0 );
	uint8_t *out_byte = ( out + len );

	/* Copy raw data in reverse order */
	while ( len-- )
		*(--out_byte) = *(value_byte++);
}

extern void bigint_multiply_raw ( const uint32_t *multiplicand0,
				  const uint32_t *multiplier0,
				  uint32_t *value0, unsigned int size );

#endif /* _BITS_BIGINT_H */
