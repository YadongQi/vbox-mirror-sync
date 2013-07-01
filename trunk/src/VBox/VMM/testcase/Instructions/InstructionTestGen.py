#!/usr/bin/env python
# -*- coding: utf-8 -*-
# $Id$

"""
Instruction Test Generator.
"""

from __future__ import print_function;

__copyright__ = \
"""
Copyright (C) 2012-2013 Oracle Corporation

Oracle Corporation confidential
All rights reserved
"""
__version__ = "$Revision$";


# Standard python imports.
import io;
import os;
from optparse import OptionParser
import random;
import sys;


## @name Exit codes
## @{
RTEXITCODE_SUCCESS = 0;
RTEXITCODE_SYNTAX  = 2;
## @}

## @name Various C macros we're used to.
## @{
UINT8_MAX  = 0xff
UINT16_MAX = 0xffff
UINT32_MAX = 0xffffffff
UINT64_MAX = 0xffffffffffffffff
def RT_BIT_32(iBit): # pylint: disable=C0103
    """ 32-bit one bit mask. """
    return 1 << iBit;
def RT_BIT_64(iBit): # pylint: disable=C0103
    """ 64-bit one bit mask. """
    return 1 << iBit;
## @}


## @name ModR/M
## @{
X86_MODRM_RM_MASK   = 0x07;
X86_MODRM_REG_MASK  = 0x38;
X86_MODRM_REG_SMASK = 0x07;
X86_MODRM_REG_SHIFT = 3;
X86_MODRM_MOD_MASK  = 0xc0;
X86_MODRM_MOD_SMASK = 0x03;
X86_MODRM_MOD_SHIFT = 6;
## @}

## @name SIB
## @{
X86_SIB_BASE_MASK   = 0x07;
X86_SIB_INDEX_MASK  = 0x38;
X86_SIB_INDEX_SMASK = 0x07;
X86_SIB_INDEX_SHIFT = 3;
X86_SIB_SCALE_MASK  = 0xc0;
X86_SIB_SCALE_SMASK = 0x03;
X86_SIB_SCALE_SHIFT = 6;
## @}

## @name Prefixes
## @
X86_OP_PRF_CS       = 0x2e;
X86_OP_PRF_SS       = 0x36;
X86_OP_PRF_DS       = 0x3e;
X86_OP_PRF_ES       = 0x26;
X86_OP_PRF_FS       = 0x64;
X86_OP_PRF_GS       = 0x65;
X86_OP_PRF_SIZE_OP  = 0x66;
X86_OP_PRF_SIZE_ADDR = 0x67;
X86_OP_PRF_LOCK     = 0xf0;
X86_OP_PRF_REPZ     = 0xf2;
X86_OP_PRF_REPNZ    = 0xf3;
X86_OP_REX_B        = 0x41;
X86_OP_REX_X        = 0x42;
X86_OP_REX_R        = 0x44;
X86_OP_REX_W        = 0x48;
## @}


## @name General registers
## @
X86_GREG_xAX        = 0
X86_GREG_xCX        = 1
X86_GREG_xDX        = 2
X86_GREG_xBX        = 3
X86_GREG_xSP        = 4
X86_GREG_xBP        = 5
X86_GREG_xSI        = 6
X86_GREG_xDI        = 7
X86_GREG_x8         = 8
X86_GREG_x9         = 9
X86_GREG_x10        = 10
X86_GREG_x11        = 11
X86_GREG_x12        = 12
X86_GREG_x13        = 13
X86_GREG_x14        = 14
X86_GREG_x15        = 15
## @}


## @name Register names.
## @{
g_asGRegs64NoSp = ('rax', 'rcx', 'rdx', 'rbx', None,  'rbp', 'rsi', 'rdi', 'r8', 'r9', 'r10', 'r11', 'r12', 'r13', 'r14', 'r15');
g_asGRegs64     = ('rax', 'rcx', 'rdx', 'rbx', 'rsp', 'rbp', 'rsi', 'rdi', 'r8', 'r9', 'r10', 'r11', 'r12', 'r13', 'r14', 'r15');
g_asGRegs32NoSp = ('eax', 'ecx', 'edx', 'ebx', None,  'ebp', 'esi', 'edi',
                   'r8d', 'r9d', 'r10d', 'r11d', 'r12d', 'r13d', 'r14d', 'r15d');
g_asGRegs32     = ('eax', 'ecx', 'edx', 'ebx', 'esp', 'ebp', 'esi', 'edi',
                   'r8d', 'r9d', 'r10d', 'r11d', 'r12d', 'r13d', 'r14d', 'r15d');
g_asGRegs16NoSp = ('ax',  'cx',  'dx',  'bx',  None,  'bp',  'si',  'di',
                   'r8w', 'r9w', 'r10w', 'r11w', 'r12w', 'r13w', 'r14w', 'r15w');
g_asGRegs16     = ('ax',  'cx',  'dx',  'bx',  'sp',  'bp',  'si',  'di',
                   'r8w', 'r9w', 'r10w', 'r11w', 'r12w', 'r13w', 'r14w', 'r15w');
g_asGRegs8      = ('al',  'cl',  'dl',  'bl',  'ah',  'ch',  'dh',  'bh');
g_asGRegs8Rex   = ('al',  'cl',  'dl',  'bl',  'spl', 'bpl', 'sil',  'dil',
                   'r8b', 'r9b', 'r10b', 'r11b', 'r12b', 'r13b', 'r14b', 'r15b',
                   'ah',  'ch',  'dh',  'bh');
## @}


## @name Random
## @{
g_oMyRand = random.SystemRandom()
def randU16():
    """ Unsigned 16-bit random number. """
    return g_oMyRand.getrandbits(16);

def randU32():
    """ Unsigned 32-bit random number. """
    return g_oMyRand.getrandbits(32);

def randU64():
    """ Unsigned 64-bit random number. """
    return g_oMyRand.getrandbits(64);

def randUxx(cBits):
    """ Unsigned 8-, 16-, 32-, or 64-bit random number. """
    return g_oMyRand.getrandbits(cBits);

def randUxxList(cBits, cElements):
    """ List of unsigned 8-, 16-, 32-, or 64-bit random numbers. """
    return [randUxx(cBits) for _ in range(cElements)];
## @}




## @name Instruction Emitter Helpers
## @{

def calcRexPrefixForTwoModRmRegs(iReg, iRm, bOtherRexPrefixes = 0):
    """
    Calculates a rex prefix if neccessary given the two registers
    and optional rex size prefixes.
    Returns an empty array if not necessary.
    """
    bRex = bOtherRexPrefixes;
    if iReg >= 8:
        bRex |= X86_OP_REX_R;
    if iRm >= 8:
        bRex |= X86_OP_REX_B;
    if bRex == 0:
        return [];
    return [bRex,];

def calcModRmForTwoRegs(iReg, iRm):
    """
    Calculate the RM byte for two registers.
    Returns an array with one byte in it.
    """
    bRm = (0x3   << X86_MODRM_MOD_SHIFT) \
        | ((iReg << X86_MODRM_REG_SHIFT) & X86_MODRM_REG_MASK) \
        | (iRm   &  X86_MODRM_RM_MASK);
    return [bRm,];

## @}


## @name Misc
## @{

def convU32ToSigned(u32):
    """ Converts a 32-bit unsigned value to 32-bit signed. """
    if u32 < 0x80000000:
        return u32;
    return u32 - UINT32_MAX - 1;

def rotateLeftUxx(cBits, uVal, cShift):
    """ Rotate a xx-bit wide unsigned number to the left. """
    assert cShift < cBits;

    if cBits == 16:
        uMask = UINT16_MAX;
    elif cBits == 32:
        uMask = UINT32_MAX;
    elif cBits == 64:
        uMask = UINT64_MAX;
    else:
        assert cBits == 8;
        uMask = UINT8_MAX;

    uVal &= uMask;
    uRet = (uVal << cShift) & uMask;
    uRet |= (uVal >> (cBits - cShift));
    return uRet;

def rotateRightUxx(cBits, uVal, cShift):
    """ Rotate a xx-bit wide unsigned number to the right. """
    assert cShift < cBits;

    if cBits == 16:
        uMask = UINT16_MAX;
    elif cBits == 32:
        uMask = UINT32_MAX;
    elif cBits == 64:
        uMask = UINT64_MAX;
    else:
        assert cBits == 8;
        uMask = UINT8_MAX;

    uVal &= uMask;
    uRet = (uVal >> cShift);
    uRet |= (uVal << (cBits - cShift)) & uMask;
    return uRet;

def gregName(iReg, cBits, fRexByteRegs = True):
    """ Gets the name of a general register by index and width. """
    if cBits == 64:
        return g_asGRegs64[iReg];
    if cBits == 32:
        return g_asGRegs32[iReg];
    if cBits == 16:
        return g_asGRegs16[iReg];
    assert cBits == 8;
    if fRexByteRegs:
        return g_asGRegs8Rex[iReg];
    return g_asGRegs8[iReg];

## @}


class TargetEnv(object):
    """
    Target Runtime Environment.
    """

    ## @name CPU Modes
    ## @{
    ksCpuMode_Real      = 'real';
    ksCpuMode_Protect   = 'prot';
    ksCpuMode_Paged     = 'paged';
    ksCpuMode_Long      = 'long';
    ksCpuMode_V86       = 'v86';
    ## @}

    ## @name Instruction set.
    ## @{
    ksInstrSet_16       = '16';
    ksInstrSet_32       = '32';
    ksInstrSet_64       = '64';
    ## @}

    def __init__(self, sName,
                 sInstrSet = ksInstrSet_32,
                 sCpuMode = ksCpuMode_Paged,
                 iRing = 3,
                 ):
        self.sName          = sName;
        self.sInstrSet      = sInstrSet;
        self.sCpuMode       = sCpuMode;
        self.iRing          = iRing;
        self.asGRegs        = g_asGRegs64     if self.is64Bit() else g_asGRegs32;
        self.asGRegsNoSp    = g_asGRegs64NoSp if self.is64Bit() else g_asGRegs32NoSp;

    def isUsingIprt(self):
        """ Whether it's an IPRT environment or not. """
        return self.sName.startswith('iprt');

    def is64Bit(self):
        """ Whether it's a 64-bit environment or not. """
        return self.sInstrSet == self.ksInstrSet_64;

    def getDefOpBits(self):
        """ Get the default operand size as a bit count. """
        if self.sInstrSet == self.ksInstrSet_16:
            return 16;
        return 32;

    def getDefOpBytes(self):
        """ Get the default operand size as a byte count. """
        return self.getDefOpBits() / 8;

    def getMaxOpBits(self):
        """ Get the max operand size as a bit count. """
        if self.sInstrSet == self.ksInstrSet_64:
            return 64;
        return 32;

    def getMaxOpBytes(self):
        """ Get the max operand size as a byte count. """
        return self.getMaxOpBits() / 8;

    def getDefAddrBits(self):
        """ Get the default address size as a bit count. """
        if self.sInstrSet == self.ksInstrSet_16:
            return 16;
        if self.sInstrSet == self.ksInstrSet_32:
            return 32;
        return 64;

    def getDefAddrBytes(self):
        """ Get the default address size as a byte count. """
        return self.getDefAddrBits() / 8;

    def getGRegCount(self, cbEffBytes = 4):
        """ Get the number of general registers. """
        if self.sInstrSet == self.ksInstrSet_64:
            if cbEffBytes == 1:
                return 16 + 4;
            return 16;
        return 8;

    def randGRegNoSp(self, cbEffBytes = 4):
        """ Returns a random general register number, excluding the SP register. """
        iReg = randU16() % self.getGRegCount(cbEffBytes);
        while iReg == X86_GREG_xSP:
            iReg = randU16() % self.getGRegCount(cbEffBytes);
        return iReg;

    def randGRegNoSpList(self, cItems, cbEffBytes = 4):
        """ List of randGRegNoSp values. """
        aiRegs = [];
        for i in range(cItems):
            aiRegs.append(self.randGRegNoSp(cbEffBytes));
        return aiRegs;

    def getAddrModes(self):
        """ Gets a list of addressing mode (16, 32, or/and 64). """
        if self.sInstrSet == self.ksInstrSet_16:
            return [16, 32];
        if self.sInstrSet == self.ksInstrSet_32:
            return [32, 16];
        return [64, 32];

    def is8BitHighGReg(self, cbEffOp, iGReg):
        """ Checks if the given register is a high 8-bit general register (AH, CH, DH or BH). """
        assert cbEffOp in [1, 2, 4, 8];
        if cbEffOp == 1:
            if iGReg >= 16:
                return True;
            if iGReg >= 4 and not self.is64Bit():
                return True;
        return False;



## Target environments.
g_dTargetEnvs = {
    'iprt-r3-32':   TargetEnv('iprt-r3-32', TargetEnv.ksInstrSet_32, TargetEnv.ksCpuMode_Protect, 3),
    'iprt-r3-64':   TargetEnv('iprt-r3-64', TargetEnv.ksInstrSet_64, TargetEnv.ksCpuMode_Long,    3),
};


class InstrTestBase(object):
    """
    Base class for testing one instruction.
    """

    def __init__(self, sName, sInstr = None):
        self.sName = sName;
        self.sInstr = sInstr if sInstr else sName.split()[0];

    def isApplicable(self, oGen):
        """
        Tests if the instruction test is applicable to the selected environment.
        """
        _ = oGen;
        return True;

    def generateTest(self, oGen, sTestFnName):
        """
        Emits the test assembly code.
        """
        oGen.write(';; @todo not implemented. This is for the linter: %s, %s\n' % (oGen, sTestFnName));
        return True;

    def generateInputs(self, cbEffOp, cbMaxOp, oGen, fLong = False):
        """ Generate a list of inputs. """
        if fLong:
            #
            # Try do extremes as well as different ranges of random numbers.
            #
            auRet = [0, 1, ];
            if cbMaxOp >= 1:
                auRet += [ UINT8_MAX  / 2, UINT8_MAX  / 2 + 1, UINT8_MAX  ];
            if cbMaxOp >= 2:
                auRet += [ UINT16_MAX / 2, UINT16_MAX / 2 + 1, UINT16_MAX ];
            if cbMaxOp >= 4:
                auRet += [ UINT32_MAX / 2, UINT32_MAX / 2 + 1, UINT32_MAX ];
            if cbMaxOp >= 8:
                auRet += [ UINT64_MAX / 2, UINT64_MAX / 2 + 1, UINT64_MAX ];

            if oGen.oOptions.sTestSize == InstructionTestGen.ksTestSize_Tiny:
                for cBits, cValues in ( (8, 4), (16, 4), (32, 8), (64, 8) ):
                    if cBits < cbMaxOp * 8:
                        auRet += randUxxList(cBits, cValues);
                cWanted = 16;
            elif oGen.oOptions.sTestSize == InstructionTestGen.ksTestSize_Medium:
                for cBits, cValues in ( (8, 8), (16, 8), (24, 2), (32, 16), (40, 1), (48, 1), (56, 1), (64, 16) ):
                    if cBits < cbMaxOp * 8:
                        auRet += randUxxList(cBits, cValues);
                cWanted = 64;
            else:
                for cBits, cValues in ( (8, 16), (16, 16), (24, 4), (32, 64), (40, 4), (48, 4), (56, 4), (64, 64) ):
                    if cBits < cbMaxOp * 8:
                        auRet += randUxxList(cBits, cValues);
                cWanted = 168;
            if len(auRet) < cWanted:
                auRet += randUxxList(cbEffOp * 8, cWanted - len(auRet));
        else:
            #
            # Short list, just do some random numbers.
            #
            auRet = [];
            if oGen.oOptions.sTestSize == InstructionTestGen.ksTestSize_Tiny:
                auRet += randUxxList(cbMaxOp, 1);
            elif oGen.oOptions.sTestSize == InstructionTestGen.ksTestSize_Medium:
                auRet += randUxxList(cbMaxOp, 2);
            else:
                auRet = [];
                for cBits in (8, 16, 32, 64):
                    if cBits < cbMaxOp * 8:
                        auRet += randUxxList(cBits, 1);
        return auRet;


class InstrTest_MemOrGreg_2_Greg(InstrTestBase):
    """
    Instruction reading memory or general register and writing the result to a
    general register.
    """

    def __init__(self, sName, fnCalcResult, sInstr = None, acbOpVars = None):
        InstrTestBase.__init__(self, sName, sInstr);
        self.fnCalcResult = fnCalcResult;
        self.acbOpVars    = [ 1, 2, 4, 8 ] if not acbOpVars else list(acbOpVars);

    ## @name Test Instruction Writers
    ## @{

    def writeInstrGregGreg(self, cbEffOp, iOp1, iOp2, oGen):
        """ Writes the instruction with two general registers as operands. """
        fRexByteRegs = oGen.oTarget.is64Bit();
        oGen.write('        %s %s, %s\n'
                   % (self.sInstr, gregName(iOp1, cbEffOp * 8, fRexByteRegs),  gregName(iOp2, cbEffOp * 8, fRexByteRegs),));
        return True;

    def writeInstrGregPureRM(self, cbEffOp, iOp1, cAddrBits, iOp2, iMod, offDisp, oGen):
        """ Writes the instruction with two general registers as operands. """
        oGen.write('        ');
        if iOp2 == 13 and iMod == 0 and cAddrBits == 64:
            oGen.write('altrexb '); # Alternative encoding for rip relative addressing.
        if cbEffOp == 8:
            oGen.write('%s %s, [' % (self.sInstr, g_asGRegs64[iOp1],));
        elif cbEffOp == 4:
            oGen.write('%s %s, [' % (self.sInstr, g_asGRegs32[iOp1],));
        elif cbEffOp == 2:
            oGen.write('%s %s, [' % (self.sInstr, g_asGRegs16[iOp1],));
        elif cbEffOp == 1:
            oGen.write('%s %s, [' % (self.sInstr, g_asGRegs8Rex[iOp1],));
        else:
            assert False;

        if (iOp2 == 5 or iOp2 == 13) and iMod == 0:
            oGen.write('VBINSTST_NAME(g_u%sData)' % (cbEffOp * 8,))
            if oGen.oTarget.is64Bit():
                oGen.write(' wrt rip');
        else:
            if iMod == 1:
                oGen.write('byte %d + ' % (offDisp,));
            elif iMod == 2:
                oGen.write('dword %d + ' % (offDisp,));
            else:
                assert iMod == 0;

            if cAddrBits == 64:
                oGen.write(g_asGRegs64[iOp2]);
            elif cAddrBits == 32:
                oGen.write(g_asGRegs32[iOp2]);
            elif cAddrBits == 16:
                assert False; ## @todo implement 16-bit addressing.
            else:
                assert False, str(cAddrBits);

        oGen.write(']\n');
        return True;

    def writeInstrGregSibLabel(self, cbEffOp, iOp1, cAddrBits, iBaseReg, iIndexReg, iScale, offDisp, oGen):
        """ Writes the instruction taking a register and a label (base only w/o reg), SIB form. """
        assert offDisp is None; assert iBaseReg in [5, 13]; assert iIndexReg == 4; assert cAddrBits != 16;
        if cAddrBits == 64:
            # Note! Cannot test this in 64-bit mode in any sensible way because the disp is 32-bit
            #       and we cannot (yet) make assumtions about where we're loaded.
            ## @todo Enable testing this in environments where we can make assumptions (boot sector).
            oGen.write('        %s %s, [VBINSTST_NAME(g_u%sData) xWrtRIP]\n'
                       % ( self.sInstr, gregName(iOp1, cbEffOp * 8), cbEffOp * 8,));
        else:
            oGen.write('        altsibx%u %s %s, [VBINSTST_NAME(g_u%sData) xWrtRIP]\n'
                       % ( iScale, self.sInstr, gregName(iOp1, cbEffOp * 8), cbEffOp * 8,));
        return True;

    def writeInstrGregSibScaledReg(self, cbEffOp, iOp1, cAddrBits, iBaseReg, iIndexReg, iScale, offDisp, oGen):
        """ Writes the instruction taking a register and disp+scaled register (no base reg), SIB form. """
        assert iBaseReg in [5, 13]; assert iIndexReg != 4;  assert cAddrBits != 16;
        # Note! Using altsibxN to force scaled encoding. This is only really a
        #       necessity for iScale=1, but doesn't hurt for the rest.
        oGen.write('        altsibx%u %s %s, [%s * %#x'
                   % (iScale, self.sInstr, gregName(iOp1, cbEffOp * 8), gregName(iIndexReg, cAddrBits), iScale,));
        if offDisp is not None:
            oGen.write(' + %#x' % (offDisp,));
        oGen.write(']\n');
        _ = iBaseReg;
        return True;

    def writeInstrGregSibBase(self, cbEffOp, iOp1, cAddrBits, iBaseReg, iIndexReg, iScale, offDisp, oGen):
        """ Writes the instruction taking a register and base only (with reg), SIB form. """
        oGen.write('        altsibx%u %s %s, [%s'
                   % (iScale, self.sInstr, gregName(iOp1, cbEffOp * 8), gregName(iBaseReg, cAddrBits),));
        if offDisp is not None:
            oGen.write(' + %#x' % (offDisp,));
        oGen.write(']\n');
        _ = iIndexReg;
        return True;

    def writeInstrGregSibBaseAndScaledReg(self, cbEffOp, iOp1, cAddrBits, iBaseReg, iIndexReg, iScale, offDisp, oGen):
        """ Writes tinstruction taking a register and full featured SIB form address. """
        # Note! From the looks of things, yasm will encode the following instructions the same way:
        #           mov eax, [rsi*1 + rbx]
        #           mov eax, [rbx + rsi*1]
        #       So, when there are two registers involved, the '*1' selects
        #       which is index and which is base.
        oGen.write('        %s %s, [%s + %s * %u'
                   % ( self.sInstr, gregName(iOp1, cbEffOp * 8),
                       gregName(iBaseReg, cAddrBits), gregName(iIndexReg, cAddrBits), iScale,));
        if offDisp is not None:
            oGen.write(' + %#x' % (offDisp,));
        oGen.write(']\n');
        return True;

    ## @}


    ## @name Memory setups
    ## @{
    def generateMemSetupReadByLabel(self, oGen, cbEffOp, uInput):
        """ Sets up memory for a memory read. """
        oGen.pushConst(uInput);
        oGen.write('        call    VBINSTST_NAME(Common_SetupMemReadU%u)\n' % (cbEffOp*8,));
        return True;

    def generateMemSetupReadByReg(self, oGen, cAddrBits, cbEffOp, iReg1, uInput, offDisp = None):
        """ Sets up memory for a memory read indirectly addressed thru one register and optional displacement. """
        oGen.pushConst(uInput);
        oGen.write('        call    VBINSTST_NAME(%s)\n'
                   % (oGen.needGRegMemSetup(cAddrBits, cbEffOp, iBaseReg = iReg1, offDisp = offDisp),));
        oGen.write('        push    %s\n' % (oGen.oTarget.asGRegs[iReg1],));
        return True;

    def generateMemSetupReadByScaledReg(self, oGen, cAddrBits, cbEffOp, iIndexReg, iScale, uInput, offDisp = None):
        """ Sets up memory for a memory read indirectly addressed thru one register and optional displacement. """
        oGen.pushConst(uInput);
        oGen.write('        call    VBINSTST_NAME(%s)\n'
                   % (oGen.needGRegMemSetup(cAddrBits, cbEffOp, offDisp = offDisp, iIndexReg = iIndexReg, iScale = iScale),));
        oGen.write('        push    %s\n' % (oGen.oTarget.asGRegs[iIndexReg],));
        return True;

    def generateMemSetupReadByBaseAndScaledReg(self, oGen, cAddrBits, cbEffOp, iBaseReg, iIndexReg, iScale, uInput, offDisp):
        """ Sets up memory for a memory read indirectly addressed thru two registers with optional displacement. """
        oGen.pushConst(uInput);
        oGen.write('        call    VBINSTST_NAME(%s)\n'
                   % (oGen.needGRegMemSetup(cAddrBits, cbEffOp, iBaseReg = iBaseReg, offDisp = offDisp,
                                            iIndexReg = iIndexReg, iScale = iScale),));
        oGen.write('        push    %s\n' % (oGen.oTarget.asGRegs[iIndexReg],));
        oGen.write('        push    %s\n' % (oGen.oTarget.asGRegs[iBaseReg],));
        return True;

    def generateMemSetupPureRM(self, oGen, cAddrBits, cbEffOp, iOp2, iMod, uInput, offDisp = None):
        """ Sets up memory for a pure R/M addressed read, iOp2 being the R/M value. """
        oGen.pushConst(uInput);
        assert offDisp is None or iMod != 0;
        if (iOp2 != 5 and iOp2 != 13) or iMod != 0:
            oGen.write('        call    VBINSTST_NAME(%s)\n'
                       % (oGen.needGRegMemSetup(cAddrBits, cbEffOp, iOp2, offDisp),));
        else:
            oGen.write('        call    VBINSTST_NAME(Common_SetupMemReadU%u)\n' % (cbEffOp*8,));
        oGen.write('        push    %s\n' % (oGen.oTarget.asGRegs[iOp2],));
        return True;

    ## @}

    def generateOneStdTestGregGreg(self, oGen, cbEffOp, cbMaxOp, iOp1, iOp1X, iOp2, iOp2X, uInput, uResult):
        """ Generate one standard instr greg,greg test. """
        oGen.write('        call VBINSTST_NAME(Common_LoadKnownValues)\n');
        oGen.write('        mov     %s, 0x%x\n' % (oGen.oTarget.asGRegs[iOp2X], uInput,));
        if iOp1X != iOp2X:
            oGen.write('        push    %s\n' % (oGen.oTarget.asGRegs[iOp2X],));
        self.writeInstrGregGreg(cbEffOp, iOp1, iOp2, oGen);
        oGen.pushConst(uResult);
        oGen.write('        call VBINSTST_NAME(%s)\n' % (oGen.needGRegChecker(iOp1X, iOp2X if iOp1X != iOp2X else None),));
        _ = cbMaxOp;
        return True;

    def generateOneStdTestGregGreg8BitHighPain(self, oGen, cbEffOp, cbMaxOp, iOp1, iOp2, uInput):
        """ High 8-bit registers are a real pain! """
        assert oGen.oTarget.is8BitHighGReg(cbEffOp, iOp1) or oGen.oTarget.is8BitHighGReg(cbEffOp, iOp2);
        # Figure out the register indexes of the max op sized regs involved.
        iOp1X = iOp1 & 3;
        iOp2X = iOp2 & 3;
        oGen.write('        ; iOp1=%u iOp1X=%u iOp2=%u iOp2X=%u\n' % (iOp1, iOp1X, iOp2, iOp2X,));

        # Calculate unshifted result.
        if iOp1X != iOp2X:
            uCur = oGen.auRegValues[iOp1X];
            if oGen.oTarget.is8BitHighGReg(cbEffOp, iOp1):
                uCur = rotateRightUxx(cbMaxOp * 8, uCur, 8);
        else:
            uCur = uInput;
            if oGen.oTarget.is8BitHighGReg(cbEffOp, iOp1) != oGen.oTarget.is8BitHighGReg(cbEffOp, iOp2):
                if oGen.oTarget.is8BitHighGReg(cbEffOp, iOp1):
                    uCur = rotateRightUxx(cbMaxOp * 8, uCur, 8);
                else:
                    uCur = rotateLeftUxx(cbMaxOp * 8, uCur, 8);
        uResult = self.fnCalcResult(cbEffOp, uInput, uCur, oGen);


        # Rotate the input and/or result to match their max-op-sized registers.
        if oGen.oTarget.is8BitHighGReg(cbEffOp, iOp2):
            uInput = rotateLeftUxx(cbMaxOp * 8, uInput, 8);
        if oGen.oTarget.is8BitHighGReg(cbEffOp, iOp1):
            uResult = rotateLeftUxx(cbMaxOp * 8, uResult, 8);

        # Hand it over to an overridable worker method.
        return self.generateOneStdTestGregGreg(oGen, cbEffOp, cbMaxOp, iOp1, iOp1X, iOp2, iOp2X, uInput, uResult);


    def generateOneStdTestGregMemNoSib(self, oGen, cAddrBits, cbEffOp, cbMaxOp, iOp1, iOp2, uInput, uResult):
        """ Generate mode 0, 1 and 2 test for the R/M=iOp2. """
        if cAddrBits == 16:
            _ = cbMaxOp;
        else:
            iMod = 0; # No disp, except for i=5.
            oGen.write('        call    VBINSTST_NAME(Common_LoadKnownValues)\n');
            self.generateMemSetupPureRM(oGen, cAddrBits, cbEffOp, iOp2, iMod, uInput);
            self.writeInstrGregPureRM(cbEffOp, iOp1, cAddrBits, iOp2, iMod, None, oGen);
            oGen.pushConst(uResult);
            oGen.write('        call    VBINSTST_NAME(%s)\n' % (oGen.needGRegChecker(iOp1, iOp2),));

            if iOp2 != 5 and iOp2 != 13:
                iMod = 1;
                for offDisp in oGen.getDispForMod(iMod):
                    oGen.write('        call    VBINSTST_NAME(Common_LoadKnownValues)\n');
                    self.generateMemSetupPureRM(oGen, cAddrBits, cbEffOp, iOp2, iMod, uInput, offDisp);
                    self.writeInstrGregPureRM(cbEffOp, iOp1, cAddrBits, iOp2, iMod, offDisp, oGen);
                    oGen.pushConst(uResult);
                    oGen.write('        call    VBINSTST_NAME(%s)\n' % (oGen.needGRegChecker(iOp1, iOp2),));

                iMod = 2;
                for offDisp in oGen.getDispForMod(iMod):
                    oGen.write('        call    VBINSTST_NAME(Common_LoadKnownValues)\n');
                    self.generateMemSetupPureRM(oGen, cAddrBits, cbEffOp, iOp2, iMod, uInput, offDisp);
                    self.writeInstrGregPureRM(cbEffOp, iOp1, cAddrBits, iOp2, iMod, offDisp, oGen);
                    oGen.pushConst(uResult);
                    oGen.write('        call    VBINSTST_NAME(%s)\n' % (oGen.needGRegChecker(iOp1, iOp2),));

        return True;

    def generateOneStdTestGregMemSib(self, oGen, cAddrBits, cbEffOp, cbMaxOp, iOp1, iMod, # pylint: disable=R0913
                                     iBaseReg, iIndexReg, iScale, uInput, uResult):
        """ Generate one SIB variations. """
        for offDisp in oGen.getDispForMod(iMod, cbEffOp):
            if ((iBaseReg == 5 or iBaseReg == 13) and iMod == 0):
                if iIndexReg == 4:
                    if cAddrBits == 64:
                        continue; # skipping.
                    oGen.write('        call    VBINSTST_NAME(Common_LoadKnownValues)\n');
                    self.generateMemSetupReadByLabel(oGen, cbEffOp, uInput);
                    self.writeInstrGregSibLabel(cbEffOp, iOp1, cAddrBits, iBaseReg, iIndexReg, iScale, offDisp, oGen);
                    sChecker = oGen.needGRegChecker(iOp1);
                else:
                    oGen.write('        call    VBINSTST_NAME(Common_LoadKnownValues)\n');
                    self.generateMemSetupReadByScaledReg(oGen, cAddrBits, cbEffOp, iIndexReg, iScale, uInput, offDisp);
                    self.writeInstrGregSibScaledReg(cbEffOp, iOp1, cAddrBits, iBaseReg, iIndexReg, iScale, offDisp, oGen);
                    sChecker = oGen.needGRegChecker(iOp1, iIndexReg);
            else:
                oGen.write('        call    VBINSTST_NAME(Common_LoadKnownValues)\n');
                if iIndexReg == 4:
                    self.generateMemSetupReadByReg(oGen, cAddrBits, cbEffOp, iBaseReg, uInput, offDisp);
                    self.writeInstrGregSibBase(cbEffOp, iOp1, cAddrBits, iBaseReg, iIndexReg, iScale, offDisp, oGen);
                    sChecker = oGen.needGRegChecker(iOp1, iBaseReg);
                else:
                    if iIndexReg == iBaseReg and iScale == 1 and offDisp is not None and (offDisp & 1):
                        if offDisp < 0: offDisp += 1;
                        else:           offDisp -= 1;
                    self.generateMemSetupReadByBaseAndScaledReg(oGen, cAddrBits, cbEffOp, iBaseReg,
                                                                iIndexReg, iScale, uInput, offDisp);
                    self.writeInstrGregSibBaseAndScaledReg(cbEffOp, iOp1, cAddrBits, iBaseReg, iIndexReg, iScale, offDisp, oGen);
                    sChecker = oGen.needGRegChecker(iOp1, iBaseReg, iIndexReg);
            oGen.pushConst(uResult);
            oGen.write('        call    VBINSTST_NAME(%s)\n' % (sChecker,));
        _ = cbMaxOp;
        return True;

    def generateStdTestGregMemSib(self, oGen, cAddrBits, cbEffOp, cbMaxOp, iOp1, auInputs, oBaseRegRange, oIndexRegRange):
        """ Generate all SIB variations for the given iOp1 (reg) value. """
        assert cAddrBits in [32, 64];
        for iBaseReg in oBaseRegRange:
            for iIndexReg in oIndexRegRange:
                if iBaseReg == X86_GREG_xSP: # no RSP testing atm.
                    continue;

                for iMod in [0, 1, 2]:
                    if iBaseReg == iOp1 and ((iBaseReg != 5 and iBaseReg != 13) or iMod != 0) and cAddrBits != cbMaxOp:
                        continue; # Don't know the high bit of the address ending up the result - skip it for now.
                    if iIndexReg == iOp1 and iIndexReg != 4 and cAddrBits != cbMaxOp:
                        continue; # Don't know the high bit of the address ending up the result - skip it for now.

                    for iScale in (1, 2, 4, 8):
                        for uInput in auInputs:
                            oGen.newSubTest();
                            uResult = self.fnCalcResult(cbEffOp, uInput, oGen.auRegValues[iOp1], oGen);
                            self.generateOneStdTestGregMemSib(oGen, cAddrBits, cbEffOp, cbMaxOp, iOp1, iMod,
                                                              iBaseReg, iIndexReg, iScale, uInput, uResult);

        return True;


    def generateStandardTests(self, oGen):
        """ Generate standard tests. """

        # Parameters.
        cbDefOp       = oGen.oTarget.getDefOpBytes();
        cbMaxOp       = oGen.oTarget.getMaxOpBytes();
        auShortInputs = self.generateInputs(cbDefOp, cbMaxOp, oGen);
        auLongInputs  = self.generateInputs(cbDefOp, cbMaxOp, oGen, fLong = True);
        iLongOp1      = oGen.oTarget.randGRegNoSp();
        iLongOp2      = oGen.oTarget.randGRegNoSp();
        oOp2Range     = None;
        if oGen.oOptions.sTestSize == InstructionTestGen.ksTestSize_Tiny:
            oOp2Range    = [iLongOp2,];

        # Register tests
        if False:
            for cbEffOp in self.acbOpVars:
                if cbEffOp > cbMaxOp:
                    continue;
                oOp2Range = range(oGen.oTarget.getGRegCount(cbEffOp));
                if oGen.oOptions.sTestSize == InstructionTestGen.ksTestSize_Tiny:
                    oOp2Range = [iLongOp2,];
                oGen.write('; cbEffOp=%u\n' % (cbEffOp,));

                for iOp1 in range(oGen.oTarget.getGRegCount(cbEffOp)):
                    if iOp1 == X86_GREG_xSP:
                        continue; # Cannot test xSP atm.
                    for iOp2 in oOp2Range:
                        if   (iOp2 >= 16 and iOp1 in range(4, 16)) \
                          or (iOp1 >= 16 and iOp2 in range(4, 16)):
                            continue; # Any REX encoding turns AH,CH,DH,BH regs into SPL,BPL,SIL,DIL.
                        if iOp2 == X86_GREG_xSP:
                            continue; # Cannot test xSP atm.

                        oGen.write('; iOp2=%u cbEffOp=%u\n' % (iOp2, cbEffOp));
                        for uInput in (auLongInputs if iOp1 == iLongOp1 and iOp2 == iLongOp2 else auShortInputs):
                            oGen.newSubTest();
                            if not oGen.oTarget.is8BitHighGReg(cbEffOp, iOp1) and not oGen.oTarget.is8BitHighGReg(cbEffOp, iOp2):
                                uCur = oGen.auRegValues[iOp1 & 15] if iOp1 != iOp2 else uInput;
                                uResult = self.fnCalcResult(cbEffOp, uInput, uCur, oGen);
                                self.generateOneStdTestGregGreg(oGen, cbEffOp, cbMaxOp, iOp1, iOp1 & 15, iOp2, iOp2 & 15,
                                                                uInput, uResult);
                            else:
                                self.generateOneStdTestGregGreg8BitHighPain(oGen, cbEffOp, cbMaxOp, iOp1, iOp2, uInput);

        # Memory test.
        if True:
            for cAddrBits in oGen.oTarget.getAddrModes():
                for cbEffOp in self.acbOpVars:
                    if cbEffOp > cbMaxOp:
                        continue;

                    oOp1MemRange   = range(oGen.oTarget.getGRegCount());
                    oOp2MemRange   = range(oGen.oTarget.getGRegCount(cAddrBits / 8))
                    oBaseRegRange  = range(oGen.oTarget.getGRegCount(cAddrBits / 8));
                    oIndexRegRange = range(oGen.oTarget.getGRegCount(cAddrBits / 8));
                    if oGen.oOptions.sTestSize == InstructionTestGen.ksTestSize_Tiny:
                        oOp1MemRange   = [iLongOp1,];
                        oOp2MemRange   = [iLongOp2,];
                        oBaseRegRange  = oGen.oTarget.randGRegNoSpList(2, cAddrBits / 8);
                        oIndexRegRange = oGen.oTarget.randGRegNoSpList(2, cAddrBits / 8);
                    elif oGen.oOptions.sTestSize == InstructionTestGen.ksTestSize_Medium:
                        oOp1MemRange   = oGen.oTarget.randGRegNoSpList(3 if oGen.oTarget.is64Bit() else 1, cbEffOp);
                        oOp2MemRange   = oGen.oTarget.randGRegNoSpList(3 + (cAddrBits == 64) * 2, cAddrBits / 8);
                        oBaseRegRange  = oGen.oTarget.randGRegNoSpList(4 + (cAddrBits == 64) * 3, cAddrBits / 8);
                        oIndexRegRange = oGen.oTarget.randGRegNoSpList(4 + (cAddrBits == 64) * 3, cAddrBits / 8);
                    if iLongOp2 not in oOp1MemRange:
                        oOp1MemRange.append(iLongOp2);
                    if cAddrBits != 16 and 4 not in oOp2MemRange:
                        oOp2MemRange.append(4)

                    for iOp1 in oOp1MemRange:
                        if iOp1 == X86_GREG_xSP:
                            continue; # Cannot test xSP atm.
                        if iOp1 > 15:
                            continue; ## TODO AH,CH,DH,BH
                        auInputs = auLongInputs if iOp1 == iLongOp1 and False else auShortInputs;

                        for iOp2 in oOp2MemRange:
                            if iOp2 != 4 or cAddrBits == 16:
                                for uInput in auInputs:
                                    oGen.newSubTest();
                                    if iOp1 == iOp2 and iOp2 != 5 and iOp2 != 13 and cbEffOp != cbMaxOp:
                                        continue; # Don't know the high bit of the address ending up the result - skip it for now.
                                    uResult = self.fnCalcResult(cbEffOp, uInput, oGen.auRegValues[iOp1 & 15], oGen);
                                    self.generateOneStdTestGregMemNoSib(oGen, cAddrBits, cbEffOp, cbMaxOp,
                                                                        iOp1, iOp2, uInput, uResult);
                            else:
                                # SIB.
                                self.generateStdTestGregMemSib(oGen, cAddrBits, cbEffOp, cbMaxOp, iOp1, auInputs,
                                                               oBaseRegRange, oIndexRegRange);
                    break;
                break;


        return True;

    def generateTest(self, oGen, sTestFnName):
        oGen.write('VBINSTST_BEGINPROC %s\n' % (sTestFnName,));
        #oGen.write('        int3\n');

        self.generateStandardTests(oGen);

        #oGen.write('        int3\n');
        oGen.write('        ret\n');
        oGen.write('VBINSTST_ENDPROC   %s\n' % (sTestFnName,));
        return True;



class InstrTest_Mov_Gv_Ev(InstrTest_MemOrGreg_2_Greg):
    """
    Tests MOV Gv,Ev.
    """
    def __init__(self):
        InstrTest_MemOrGreg_2_Greg.__init__(self, 'mov Gv,Ev', self.calc_mov);

    @staticmethod
    def calc_mov(cbEffOp, uInput, uCur, oGen):
        """ Calculates the result of a mov instruction."""
        if cbEffOp == 8:
            return uInput & UINT64_MAX;
        if cbEffOp == 4:
            return uInput & UINT32_MAX;
        if cbEffOp == 2:
            return (uCur & 0xffffffffffff0000) | (uInput & UINT16_MAX);
        assert cbEffOp == 1; _ = oGen;
        return (uCur & 0xffffffffffffff00) | (uInput & UINT8_MAX);


class InstrTest_MovSxD_Gv_Ev(InstrTest_MemOrGreg_2_Greg):
    """
    Tests MOVSXD Gv,Ev.
    """
    def __init__(self):
        InstrTest_MemOrGreg_2_Greg.__init__(self, 'movsxd Gv,Ev', self.calc_movsxd, acbOpVars = [ 8, 4, 2, ]);

    def writeInstrGregGreg(self, cbEffOp, iOp1, iOp2, oGen):
        if cbEffOp == 8:
            oGen.write('        %s %s, %s\n' % (self.sInstr, g_asGRegs64[iOp1], g_asGRegs32[iOp2]));
        elif cbEffOp == 4 or cbEffOp == 2:
            abInstr = [];
            if cbEffOp != oGen.oTarget.getDefOpBytes():
                abInstr.append(X86_OP_PRF_SIZE_OP);
            abInstr += calcRexPrefixForTwoModRmRegs(iOp1, iOp2);
            abInstr.append(0x63);
            abInstr += calcModRmForTwoRegs(iOp1, iOp2);
            oGen.writeInstrBytes(abInstr);
        else:
            assert False;
            assert False;
        return True;

    def isApplicable(self, oGen):
        return oGen.oTarget.is64Bit();

    @staticmethod
    def calc_movsxd(cbEffOp, uInput, uCur, oGen):
        """
        Calculates the result of a movxsd instruction.
        Returns the result value (cbMaxOp sized).
        """
        _ = oGen;
        if cbEffOp == 8 and (uInput & RT_BIT_32(31)):
            return (UINT32_MAX << 32) | (uInput & UINT32_MAX);
        if cbEffOp == 2:
            return (uCur & 0xffffffffffff0000) | (uInput & 0xffff);
        return uInput & UINT32_MAX;


## Instruction Tests.
g_aoInstructionTests = [
    InstrTest_Mov_Gv_Ev(),
    #InstrTest_MovSxD_Gv_Ev(),
];


class InstructionTestGen(object):
    """
    Instruction Test Generator.
    """

    ## @name Test size
    ## @{
    ksTestSize_Large  = 'large';
    ksTestSize_Medium = 'medium';
    ksTestSize_Tiny   = 'tiny';
    ## @}
    kasTestSizes = ( ksTestSize_Large, ksTestSize_Medium, ksTestSize_Tiny );



    def __init__(self, oOptions):
        self.oOptions = oOptions;
        self.oTarget  = g_dTargetEnvs[oOptions.sTargetEnv];

        # Calculate the number of output files.
        self.cFiles  = 1;
        if len(g_aoInstructionTests) > self.oOptions.cInstrPerFile:
            self.cFiles = len(g_aoInstructionTests) / self.oOptions.cInstrPerFile;
            if self.cFiles * self.oOptions.cInstrPerFile < len(g_aoInstructionTests):
                self.cFiles += 1;

        # Fix the known register values.
        self.au64Regs       = randUxxList(64, 16);
        self.au32Regs       = [(self.au64Regs[i] & UINT32_MAX) for i in range(8)];
        self.au16Regs       = [(self.au64Regs[i] & UINT16_MAX) for i in range(8)];
        self.auRegValues    = self.au64Regs if self.oTarget.is64Bit() else self.au32Regs;

        # Declare state variables used while generating.
        self.oFile          = sys.stderr;
        self.iFile          = -1;
        self.sFile          = '';
        self.dCheckFns      = dict();
        self.dMemSetupFns   = dict();
        self.d64BitConsts   = dict();


    #
    # Methods used by instruction tests.
    #

    def write(self, sText):
        """ Writes to the current output file. """
        return self.oFile.write(unicode(sText));

    def writeln(self, sText):
        """ Writes a line to the current output file. """
        self.write(sText);
        return self.write('\n');

    def writeInstrBytes(self, abInstr):
        """
        Emits an instruction given as a sequence of bytes values.
        """
        self.write('        db %#04x' % (abInstr[0],));
        for i in range(1, len(abInstr)):
            self.write(', %#04x' % (abInstr[i],));
        return self.write('\n');

    def newSubTest(self):
        """
        Indicates that a new subtest has started.
        """
        self.write('        mov     dword [VBINSTST_NAME(g_uVBInsTstSubTestIndicator) xWrtRIP], __LINE__\n');
        return True;

    def needGRegChecker(self, iReg1, iReg2 = None, iReg3 = None):
        """
        Records the need for a given register checker function, returning its label.
        """
        if iReg2 is not None:
            if iReg3 is not None:
                sName = '%s_%s_%s' % (self.oTarget.asGRegs[iReg1], self.oTarget.asGRegs[iReg2], self.oTarget.asGRegs[iReg3],);
            else:
                sName = '%s_%s' % (self.oTarget.asGRegs[iReg1], self.oTarget.asGRegs[iReg2],);
        else:
            sName = '%s' % (self.oTarget.asGRegs[iReg1],);
            assert iReg3 is None;

        if sName in self.dCheckFns:
            self.dCheckFns[sName] += 1;
        else:
            self.dCheckFns[sName]  = 1;

        return 'Common_Check_' + sName;

    def needGRegMemSetup(self, cAddrBits, cbEffOp, iBaseReg = None, offDisp = None, iIndexReg = None, iScale = 1):
        """
        Records the need for a given register checker function, returning its label.
        """
        sName = '%ubit_U%u' % (cAddrBits, cbEffOp * 8,);
        if iBaseReg is not None:
            sName += '_%s' % (gregName(iBaseReg, cAddrBits),);
        sName += '_x%u' % (iScale,);
        if iIndexReg is not None:
            sName += '_%s' % (gregName(iIndexReg, cAddrBits),);
        if offDisp is not None:
            sName += '_%#010x' % (offDisp & UINT32_MAX, );
        if sName in self.dMemSetupFns:
            self.dMemSetupFns[sName] += 1;
        else:
            self.dMemSetupFns[sName]  = 1;
        return 'Common_MemSetup_' + sName;

    def need64BitConstant(self, uVal):
        """
        Records the need for a 64-bit constant, returning its label.
        These constants are pooled to attempt reduce the size of the whole thing.
        """
        assert uVal >= 0 and uVal <= UINT64_MAX;
        if uVal in self.d64BitConsts:
            self.d64BitConsts[uVal] += 1;
        else:
            self.d64BitConsts[uVal]  = 1;
        return 'g_u64Const_0x%016x' % (uVal, );

    def pushConst(self, uResult):
        """
        Emits a push constant value, taking care of high values on 64-bit hosts.
        """
        if self.oTarget.is64Bit() and uResult >= 0x80000000:
            self.write('        push    qword [%s wrt rip]\n' % (self.need64BitConstant(uResult),));
        else:
            self.write('        push    dword 0x%x\n' % (uResult,));
        return True;

    def getDispForMod(self, iMod, cbAlignment = 1):
        """
        Get a set of address dispositions for a given addressing mode.
        The alignment restriction is for SIB scaling.
        """
        assert cbAlignment in [1, 2, 4, 8];
        if iMod == 0:
            aoffDisp = [ None, ];
        elif iMod == 1:
            aoffDisp = [ 127 & ~(cbAlignment - 1), -128 ];
        elif iMod == 2:
            aoffDisp = [ 2147483647 & ~(cbAlignment - 1), -2147483648 ];
        else: assert False;
        return aoffDisp;


    #
    # Internal machinery.
    #

    def _calcTestFunctionName(self, oInstrTest, iInstrTest):
        """
        Calc a test function name for the given instruction test.
        """
        sName = 'TestInstr%03u_%s' % (iInstrTest, oInstrTest.sName);
        return sName.replace(',', '_').replace(' ', '_').replace('%', '_');

    def _generateFileHeader(self, ):
        """
        Writes the file header.
        Raises exception on trouble.
        """
        self.write('; $Id$\n'
                   ';; @file %s\n'
                   '; Autogenerate by %s %s. DO NOT EDIT\n'
                   ';\n'
                   '\n'
                   ';\n'
                   '; Headers\n'
                   ';\n'
                   '%%include "env-%s.mac"\n'
                   % ( os.path.basename(self.sFile),
                       os.path.basename(__file__), __version__[11:-1],
                       self.oTarget.sName,
                   ) );
        # Target environment specific init stuff.

        #
        # Global variables.
        #
        self.write('\n\n'
                   ';\n'
                   '; Globals\n'
                   ';\n');
        self.write('VBINSTST_BEGINDATA\n'
                   'VBINSTST_GLOBALNAME_EX g_pvLow16Mem4K, data hidden\n'
                   '        dq      0\n'
                   'VBINSTST_GLOBALNAME_EX g_pvLow32Mem4K, data hidden\n'
                   '        dq      0\n'
                   'VBINSTST_GLOBALNAME_EX g_pvMem4K, data hidden\n'
                   '        dq      0\n'
                   'VBINSTST_GLOBALNAME_EX g_uVBInsTstSubTestIndicator, data hidden\n'
                   '        dd      0\n'
                   'VBINSTST_BEGINCODE\n'
                   );
        self.write('%ifdef RT_ARCH_AMD64\n');
        for i in range(len(g_asGRegs64)):
            self.write('g_u64KnownValue_%s: dq 0x%x\n' % (g_asGRegs64[i], self.au64Regs[i]));
        self.write('%endif\n\n')

        #
        # Common functions.
        #

        # Loading common values.
        self.write('\n\n'
                   'VBINSTST_BEGINPROC Common_LoadKnownValues\n'
                   '%ifdef RT_ARCH_AMD64\n');
        for i in range(len(g_asGRegs64NoSp)):
            if g_asGRegs64NoSp[i]:
                self.write('        mov     %s, 0x%x\n' % (g_asGRegs64NoSp[i], self.au64Regs[i],));
        self.write('%else\n');
        for i in range(8):
            if g_asGRegs32NoSp[i]:
                self.write('        mov     %s, 0x%x\n' % (g_asGRegs32NoSp[i], self.au32Regs[i],));
        self.write('%endif\n'
                   '        ret\n'
                   'VBINSTST_ENDPROC   Common_LoadKnownValues\n'
                   '\n');

        self.write('VBINSTST_BEGINPROC Common_CheckKnownValues\n'
                   '%ifdef RT_ARCH_AMD64\n');
        for i in range(len(g_asGRegs64NoSp)):
            if g_asGRegs64NoSp[i]:
                self.write('        cmp     %s, [g_u64KnownValue_%s wrt rip]\n'
                           '        je      .ok_%u\n'
                           '        push    %u         ; register number\n'
                           '        push    %s         ; actual\n'
                           '        push    qword [g_u64KnownValue_%s wrt rip] ; expected\n'
                           '        call    VBINSTST_NAME(Common_BadValue)\n'
                           '.ok_%u:\n'
                           % ( g_asGRegs64NoSp[i], g_asGRegs64NoSp[i], i, i, g_asGRegs64NoSp[i], g_asGRegs64NoSp[i], i,));
        self.write('%else\n');
        for i in range(8):
            if g_asGRegs32NoSp[i]:
                self.write('        cmp     %s, 0x%x\n'
                           '        je      .ok_%u\n'
                           '        push    %u         ; register number\n'
                           '        push    %s         ; actual\n'
                           '        push    dword 0x%x ; expected\n'
                           '        call    VBINSTST_NAME(Common_BadValue)\n'
                           '.ok_%u:\n'
                           % ( g_asGRegs32NoSp[i], self.au32Regs[i], i, i, g_asGRegs32NoSp[i], self.au32Regs[i], i,));
        self.write('%endif\n'
                   '        ret\n'
                   'VBINSTST_ENDPROC   Common_CheckKnownValues\n'
                   '\n');

        return True;

    def _generateMemSetupFunctions(self):
        """
        Generates the memory setup functions.
        """
        cDefAddrBits = self.oTarget.getDefAddrBits();
        for sName in self.dMemSetupFns:
            # Unpack it.
            asParams = sName.split('_');
            cAddrBits  = int(asParams[0][:-3]); assert asParams[0][-3:] == 'bit';
            cEffOpBits = int(asParams[1][1:]);  assert asParams[1][0]   == 'U';
            if cAddrBits == 64:   asAddrGRegs = g_asGRegs64;
            elif cAddrBits == 32: asAddrGRegs = g_asGRegs32;
            else:                 asAddrGRegs = g_asGRegs16;

            i = 2;
            iBaseReg = None;
            sBaseReg = None;
            if i < len(asParams) and asParams[i] in asAddrGRegs:
                sBaseReg = asParams[i];
                iBaseReg = asAddrGRegs.index(sBaseReg);
                i += 1

            assert i < len(asParams); assert asParams[i][0] == 'x';
            iScale = iScale = int(asParams[i][1:]); assert iScale in [1, 2, 4, 8];
            i += 1;

            sIndexReg = None;
            iIndexReg = None;
            if i < len(asParams) and asParams[i] in asAddrGRegs:
                sIndexReg = asParams[i];
                iIndexReg  = asAddrGRegs.index(sIndexReg);
                i += 1;

            u32Disp = None;
            if i < len(asParams) and len(asParams[i]) == 10:
                u32Disp = long(asParams[i], 16);
                i += 1;

            assert i == len(asParams), 'i=%d len=%d len[i]=%d (%s)' % (i, len(asParams), len(asParams[i]), asParams[i],);
            assert iScale == 1 or iIndexReg is not None;

            # Find a temporary register.
            iTmpReg1 = X86_GREG_xCX;
            while iTmpReg1 in [iBaseReg, iIndexReg]:
                iTmpReg1 += 1;

            # Prologue.
            self.write('\n\n'
                       '; cAddrBits=%s cEffOpBits=%s iBaseReg=%s u32Disp=%s iIndexReg=%s iScale=%s\n'
                       'VBINSTST_BEGINPROC Common_MemSetup_%s\n'
                       '        MY_PUSH_FLAGS\n'
                       '        push    %s\n'
                       % ( cAddrBits, cEffOpBits, iBaseReg, u32Disp, iIndexReg, iScale,
                           sName, self.oTarget.asGRegs[iTmpReg1], ));

            # Figure out what to use.
            if cEffOpBits == 64:
                sTmpReg1 = g_asGRegs64[iTmpReg1];
                sDataVar = 'VBINSTST_NAME(g_u64Data)';
            elif cEffOpBits == 32:
                sTmpReg1 = g_asGRegs32[iTmpReg1];
                sDataVar = 'VBINSTST_NAME(g_u32Data)';
            elif cEffOpBits == 16:
                sTmpReg1 = g_asGRegs16[iTmpReg1];
                sDataVar = 'VBINSTST_NAME(g_u16Data)';
            else:
                assert cEffOpBits == 8; assert iTmpReg1 < 4;
                sTmpReg1 = g_asGRegs8Rex[iTmpReg1];
                sDataVar = 'VBINSTST_NAME(g_u8Data)';

            # Special case: reg + reg * [2,4,8]
            if iBaseReg == iIndexReg and iBaseReg is not None and iScale != 1:
                iTmpReg2 = X86_GREG_xBP;
                while iTmpReg2 in [iBaseReg, iIndexReg, iTmpReg1]:
                    iTmpReg2 += 1;
                sTmpReg2 = gregName(iTmpReg2, cAddrBits);
                self.write('        push    sAX\n'
                           '        push    %s\n'
                           '        push    sDX\n'
                           % (self.oTarget.asGRegs[iTmpReg2],));
                if cAddrBits == 16:
                    self.write('        mov     %s, [VBINSTST_NAME(g_pvLow16Mem4K) xWrtRIP]\n' % (sTmpReg2,));
                else:
                    self.write('        mov     %s, [VBINSTST_NAME(g_pvLow32Mem4K) xWrtRIP]\n' % (sTmpReg2,));
                self.write('        add     %s, 0x200\n' % (sTmpReg2,));
                self.write('        mov     %s, %s\n' % (gregName(X86_GREG_xAX, cAddrBits), sTmpReg2,));
                if u32Disp is not None:
                    self.write('        sub     %s, %d\n' % ( gregName(X86_GREG_xAX, cAddrBits), convU32ToSigned(u32Disp), ));
                self.write('        xor     edx, edx\n'
                           '%if xCB == 2\n'
                           '        push    0\n'
                           '%endif\n');
                self.write('        push    %u\n' % (iScale + 1,));
                self.write('        div     %s [xSP]\n' % ('qword' if cAddrBits == 64 else 'dword',));
                self.write('        sub     %s, %s\n' % (sTmpReg2, gregName(X86_GREG_xDX, cAddrBits),));
                self.write('        pop     sDX\n'
                           '        pop     sDX\n'); # sTmpReg2 is eff address; sAX is sIndexReg value.
                # Note! sTmpReg1 can be xDX and that's no problem now.
                self.write('        mov     %s, [xSP + sCB*3 + MY_PUSH_FLAGS_SIZE + xCB]\n' % (sTmpReg1,));
                self.write('        mov     [%s], %s\n' % (sTmpReg2, sTmpReg1,)); # Value in place.
                self.write('        pop     %s\n' % (self.oTarget.asGRegs[iTmpReg2],));
                if iBaseReg == X86_GREG_xAX:
                    self.write('        pop     %s\n' % (self.oTarget.asGRegs[iTmpReg1],));
                else:
                    self.write('        mov     %s, %s\n' % (sBaseReg, gregName(X86_GREG_xAX, cAddrBits),));
                    self.write('        pop     sAX\n');

            else:
                # Load the value and mem address, storing the value there.
                # Note! ASSUMES that the scale and disposition works fine together.
                sAddrReg = sBaseReg if sBaseReg is not None else sIndexReg;
                self.write('        mov     %s, [xSP + sCB + MY_PUSH_FLAGS_SIZE + xCB]\n' % (sTmpReg1,));
                if cAddrBits >= cDefAddrBits:
                    self.write('        mov     [%s xWrtRIP], %s\n' % (sDataVar, sTmpReg1,));
                    self.write('        lea     %s, [%s xWrtRIP]\n' % (sAddrReg, sDataVar,));
                else:
                    if cAddrBits == 16:
                        self.write('        mov     %s, [VBINSTST_NAME(g_pvLow16Mem4K) xWrtRIP]\n' % (sAddrReg,));
                    else:
                        self.write('        mov     %s, [VBINSTST_NAME(g_pvLow32Mem4K) xWrtRIP]\n' % (sAddrReg,));
                    self.write('        add     %s, %s\n' % (sAddrReg, (randU16() << cEffOpBits) & 0xfff, ));
                    self.write('        mov     [%s], %s\n' % (sAddrReg, sTmpReg1, ));

                # Adjust for disposition and scaling.
                if u32Disp is not None:
                    self.write('        sub     %s, %d\n' % ( sAddrReg, convU32ToSigned(u32Disp), ));
                if iIndexReg is not None:
                    if iBaseReg == iIndexReg:
                        assert iScale == 1;
                        assert u32Disp is None or (u32Disp & 1) == 0;
                        self.write('        shr     %s, 1\n' % (sIndexReg,));
                    elif sBaseReg is not None:
                        uIdxRegVal = randUxx(cAddrBits);
                        if cAddrBits == 64:
                            self.write('        mov     %s, %u\n'
                                       '        sub     %s, %s\n'
                                       '        mov     %s, %u\n'
                                       % ( sIndexReg, (uIdxRegVal * iScale) & UINT64_MAX,
                                           sBaseReg, sIndexReg,
                                           sIndexReg, uIdxRegVal, ));
                        else:
                            assert cAddrBits == 32;
                            self.write('        mov     %s, %u\n'
                                       '        sub     %s, %#06x\n'
                                       % ( sIndexReg, uIdxRegVal, sBaseReg, (uIdxRegVal * iScale) & UINT32_MAX, ));
                    elif iScale == 2:
                        assert u32Disp is None or (u32Disp & 1) == 0;
                        self.write('        shr     %s, 1\n' % (sIndexReg,));
                    elif iScale == 4:
                        assert u32Disp is None or (u32Disp & 3) == 0;
                        self.write('        shr     %s, 2\n' % (sIndexReg,));
                    elif iScale == 8:
                        assert u32Disp is None or (u32Disp & 7) == 0;
                        self.write('        shr     %s, 3\n' % (sIndexReg,));
                    else:
                        assert iScale == 1;

            # Set upper bits that's supposed to be unused.
            if cDefAddrBits > cAddrBits or cAddrBits == 16:
                if cDefAddrBits == 64:
                    assert cAddrBits == 32;
                    if iBaseReg is not None:
                        self.write('        mov     %s, %#018x\n'
                                   '        or      %s, %s\n'
                                   % ( g_asGRegs64[iTmpReg1], randU64() & 0xffffffff00000000,
                                       g_asGRegs64[iBaseReg], g_asGRegs64[iTmpReg1],));
                    if iIndexReg is not None and iIndexReg != iBaseReg:
                        self.write('        mov     %s, %#018x\n'
                                   '        or      %s, %s\n'
                                   % ( g_asGRegs64[iTmpReg1], randU64() & 0xffffffff00000000,
                                       g_asGRegs64[iIndexReg], g_asGRegs64[iTmpReg1],));
                else:
                    assert cDefAddrBits == 32; assert cAddrBits == 16; assert iIndexReg is None;
                    if iBaseReg is not None:
                        self.write('        or      %s, %#010x\n'
                                   % ( g_asGRegs32[iBaseReg], randU32() & 0xffff0000, ));

            # Epilogue.
            self.write('        pop     %s\n'
                       '        MY_POP_FLAGS\n'
                       '        ret sCB\n'
                       'VBINSTST_ENDPROC   Common_MemSetup_%s\n'
                       % ( self.oTarget.asGRegs[iTmpReg1], sName,));


    def _generateFileFooter(self):
        """
        Generates file footer.
        """

        # Register checking functions.
        for sName in self.dCheckFns:
            asRegs = sName.split('_');
            sPushSize = 'dword';

            # Prologue
            self.write('\n\n'
                       '; Checks 1 or more register values, expected values pushed on the stack.\n'
                       '; To save space, the callee cleans up the stack.'
                       '; Ref count: %u\n'
                       'VBINSTST_BEGINPROC Common_Check_%s\n'
                       '        MY_PUSH_FLAGS\n'
                       % ( self.dCheckFns[sName], sName, ) );

            # Register checks.
            for i in range(len(asRegs)):
                sReg = asRegs[i];
                iReg = self.oTarget.asGRegs.index(sReg);
                if i == asRegs.index(sReg): # Only check once, i.e. input = output reg.
                    self.write('        cmp     %s, [xSP + MY_PUSH_FLAGS_SIZE + xCB + sCB * %u]\n'
                               '        je      .equal%u\n'
                               '        push    %s %u      ; register number\n'
                               '        push    %s         ; actual\n'
                               '        mov     %s, [xSP + sCB*2 + MY_PUSH_FLAGS_SIZE + xCB]\n'
                               '        push    %s         ; expected\n'
                               '        call    VBINSTST_NAME(Common_BadValue)\n'
                               '.equal%u:\n'
                           % ( sReg, i, i, sPushSize, iReg, sReg, sReg, sReg, i, ) );


            # Restore known register values and check the other registers.
            for sReg in asRegs:
                if self.oTarget.is64Bit():
                    self.write('        mov     %s, [g_u64KnownValue_%s wrt rip]\n' % (sReg, sReg,));
                else:
                    iReg = self.oTarget.asGRegs.index(sReg)
                    self.write('        mov     %s, 0x%x\n' % (sReg, self.au32Regs[iReg],));
            self.write('        MY_POP_FLAGS\n'
                       '        call    VBINSTST_NAME(Common_CheckKnownValues)\n'
                       '        ret     sCB*%u\n'
                       'VBINSTST_ENDPROC   Common_Check_%s\n'
                       % (len(asRegs), sName,));

        # memory setup functions
        self._generateMemSetupFunctions();

        # 64-bit constants.
        if len(self.d64BitConsts) > 0:
            self.write('\n\n'
                       ';\n'
                       '; 64-bit constants\n'
                       ';\n');
            for uVal in self.d64BitConsts:
                self.write('g_u64Const_0x%016x: dq 0x%016x ; Ref count: %d\n' % (uVal, uVal, self.d64BitConsts[uVal], ) );

        return True;

    def _generateTests(self):
        """
        Generate the test cases.
        """
        for self.iFile in range(self.cFiles):
            if self.cFiles == 1:
                self.sFile = '%s.asm' % (self.oOptions.sOutputBase,)
            else:
                self.sFile = '%s-%u.asm' % (self.oOptions.sOutputBase, self.iFile)
            self.oFile = sys.stdout;
            if self.oOptions.sOutputBase != '-':
                self.oFile = io.open(self.sFile, 'w', buffering = 65536, encoding = 'utf-8');

            self._generateFileHeader();

            # Calc the range.
            iInstrTestStart = self.iFile * self.oOptions.cInstrPerFile;
            iInstrTestEnd   = iInstrTestStart + self.oOptions.cInstrPerFile;
            if iInstrTestEnd > len(g_aoInstructionTests):
                iInstrTestEnd = len(g_aoInstructionTests);

            # Generate the instruction tests.
            for iInstrTest in range(iInstrTestStart, iInstrTestEnd):
                oInstrTest = g_aoInstructionTests[iInstrTest];
                self.write('\n'
                           '\n'
                           ';\n'
                           '; %s\n'
                           ';\n'
                           % (oInstrTest.sName,));
                oInstrTest.generateTest(self, self._calcTestFunctionName(oInstrTest, iInstrTest));

            # Generate the main function.
            self.write('\n\n'
                       'VBINSTST_BEGINPROC TestInstrMain\n'
                       '        MY_PUSH_ALL\n'
                       '        sub xSP, 40h\n'
                       '\n');

            for iInstrTest in range(iInstrTestStart, iInstrTestEnd):
                oInstrTest = g_aoInstructionTests[iInstrTest];
                if oInstrTest.isApplicable(self):
                    self.write('%%ifdef ASM_CALL64_GCC\n'
                               '        lea  rdi, [.szInstr%03u wrt rip]\n'
                               '%%elifdef ASM_CALL64_MSC\n'
                               '        lea  rcx, [.szInstr%03u wrt rip]\n'
                               '%%else\n'
                               '        mov  xAX, .szInstr%03u\n'
                               '        mov  [xSP], xAX\n'
                               '%%endif\n'
                               '        VBINSTST_CALL_FN_SUB_TEST\n'
                               '        call VBINSTST_NAME(%s)\n'
                               % ( iInstrTest, iInstrTest, iInstrTest, self._calcTestFunctionName(oInstrTest, iInstrTest)));

            self.write('\n'
                       '        add  xSP, 40h\n'
                       '        MY_POP_ALL\n'
                       '        ret\n\n');
            for iInstrTest in range(iInstrTestStart, iInstrTestEnd):
                self.write('.szInstr%03u: db \'%s\', 0\n' % (iInstrTest, g_aoInstructionTests[iInstrTest].sName,));
            self.write('VBINSTST_ENDPROC TestInstrMain\n\n');

            self._generateFileFooter();
            if self.oOptions.sOutputBase != '-':
                self.oFile.close();
            self.oFile = None;
        self.sFile = '';

        return RTEXITCODE_SUCCESS;

    def _runMakefileMode(self):
        """
        Generate a list of output files on standard output.
        """
        if self.cFiles == 1:
            print('%s.asm' % (self.oOptions.sOutputBase,));
        else:
            print(' '.join('%s-%s.asm' % (self.oOptions.sOutputBase, i) for i in range(self.cFiles)));
        return RTEXITCODE_SUCCESS;

    def run(self):
        """
        Generates the tests or whatever is required.
        """
        if self.oOptions.fMakefileMode:
            return self._runMakefileMode();
        return self._generateTests();

    @staticmethod
    def main():
        """
        Main function a la C/C++. Returns exit code.
        """

        #
        # Parse the command line.
        #
        oParser = OptionParser(version = __version__[11:-1].strip());
        oParser.add_option('--makefile-mode', dest = 'fMakefileMode', action = 'store_true', default = False,
                           help = 'Special mode for use to output a list of output files for the benefit of '
                                  'the make program (kmk).');
        oParser.add_option('--split', dest = 'cInstrPerFile', metavar = '<instr-per-file>', type = 'int', default = 9999999,
                           help = 'Number of instruction to test per output file.');
        oParser.add_option('--output-base', dest = 'sOutputBase', metavar = '<file>', default = None,
                           help = 'The output file base name, no suffix please. Required.');
        oParser.add_option('--target', dest = 'sTargetEnv', metavar = '<target>',
                           default = 'iprt-r3-32',
                           choices = g_dTargetEnvs.keys(),
                           help = 'The target environment. Choices: %s'
                                % (', '.join(sorted(g_dTargetEnvs.keys())),));
        oParser.add_option('--test-size', dest = 'sTestSize', default = InstructionTestGen.ksTestSize_Medium,
                           choices = InstructionTestGen.kasTestSizes,
                           help = 'Selects the test size.');

        (oOptions, asArgs) = oParser.parse_args();
        if len(asArgs) > 0:
            oParser.print_help();
            return RTEXITCODE_SYNTAX
        if oOptions.sOutputBase is None:
            print('syntax error: Missing required option --output-base.', file = sys.stderr);
            return RTEXITCODE_SYNTAX

        #
        # Instantiate the program class and run it.
        #
        oProgram = InstructionTestGen(oOptions);
        return oProgram.run();


if __name__ == '__main__':
    sys.exit(InstructionTestGen.main());

