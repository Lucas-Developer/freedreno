/*
 * Copyright (c) 2012 Rob Clark <robdclark@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef INSTR_H_
#define INSTR_H_

#define PACKED __attribute__((__packed__))

typedef enum {
	ADDs = 0,
	ADD_PREVs = 1,
	MULs = 2,
	MUL_PREVs = 3,
	MUL_PREV2s = 4,
	MAXs = 5,
	MINs = 6,
	SETEs = 7,
	SETGTs = 8,
	SETGTEs = 9,
	SETNEs = 10,
	FRACs = 11,
	TRUNCs = 12,
	FLOORs = 13,
	EXP_IEEE = 14,
	LOG_CLAMP = 15,
	LOG_IEEE = 16,
	RECIP_CLAMP = 17,
	RECIP_FF = 18,
	RECIP_IEEE = 19,
	RECIPSQ_CLAMP = 20,
	RECIPSQ_FF = 21,
	RECIPSQ_IEEE = 22,
	MOVAs = 23,
	MOVA_FLOORs = 24,
	SUBs = 25,
	SUB_PREVs = 26,
	PRED_SETEs = 27,
	PRED_SETNEs = 28,
	PRED_SETGTs = 29,
	PRED_SETGTEs = 30,
	PRED_SET_INVs = 31,
	PRED_SET_POPs = 32,
	PRED_SET_CLRs = 33,
	PRED_SET_RESTOREs = 34,
	KILLEs = 35,
	KILLGTs = 36,
	KILLGTEs = 37,
	KILLNEs = 38,
	KILLONEs = 39,
	SQRT_IEEE = 40,
	MUL_CONST_0 = 42,
	MUL_CONST_1 = 43,
	ADD_CONST_0 = 44,
	ADD_CONST_1 = 45,
	SUB_CONST_0 = 46,
	SUB_CONST_1 = 47,
	SIN = 48,
	COS = 49,
	RETAIN_PREV = 50,
} instr_scalar_opc_t;

typedef enum {
	ADDv = 0,
	MULv = 1,
	MAXv = 2,
	MINv = 3,
	SETEv = 4,
	SETGTv = 5,
	SETGTEv = 6,
	SETNEv = 7,
	FRACv = 8,
	TRUNCv = 9,
	FLOORv = 10,
	MULADDv = 11,
	CNDEv = 12,
	CNDGTEv = 13,
	CNDGTv = 14,
	DOT4v = 15,
	DOT3v = 16,
	DOT2ADDv = 17,
	CUBEv = 18,
	MAX4v = 19,
	PRED_SETE_PUSHv = 20,
	PRED_SETNE_PUSHv = 21,
	PRED_SETGT_PUSHv = 22,
	PRED_SETGTE_PUSHv = 23,
	KILLEv = 24,
	KILLGTv = 25,
	KILLGTEv = 26,
	KILLNEv = 27,
	DSTv = 28,
	MOVAv = 29,
} instr_vector_opc_t;

typedef struct PACKED {
	/* dword0: */
	uint8_t             vector_dest              : 6;
	uint8_t             vector_dest_rel          : 1;
	uint8_t             low_precision_16b_fp     : 1;
	uint8_t             scalar_dest              : 6;
	uint8_t             scalar_dest_rel          : 1;
	uint8_t             export_data              : 1;
	uint8_t             vector_write_mask        : 4;
	uint8_t             scalar_write_mask        : 4;
	uint8_t             vector_clamp             : 1;
	uint8_t             scalar_clamp             : 1;
	instr_scalar_opc_t  scalar_opc               : 6;
	/* dword1: */
	uint8_t             src3_swiz                : 8;
	uint8_t             src2_swiz                : 8;
	uint8_t             src1_swiz                : 8;
	uint8_t             src3_reg_negate          : 1;
	uint8_t             src2_reg_negate          : 1;
	uint8_t             src1_reg_negate          : 1;
	uint8_t             pred_select              : 2;
	uint8_t             relative_addr            : 1;
	uint8_t             const_1_rel_abs          : 1;
	uint8_t             const_0_rel_abs          : 1;
	/* dword2: */
	uint8_t             src3_reg                 : 6;
	uint8_t             src3_reg_select          : 1;
	uint8_t             src3_reg_abs             : 1;
	uint8_t             src2_reg                 : 6;
	uint8_t             src2_reg_select          : 1;
	uint8_t             src2_reg_abs             : 1;
	uint8_t             src1_reg                 : 6;
	uint8_t             src1_reg_select          : 1;
	uint8_t             src1_reg_abs             : 1;
	instr_vector_opc_t  vector_opc               : 5;
	uint8_t             src3_sel                 : 1;
	uint8_t             src2_sel                 : 1;
	uint8_t             src1_sel                 : 1;
} instr_alu_t;


#endif /* INSTR_H_ */