// pseudo-C decompilation of trustos.elf
/* ===== start @ 0x94020000 size 612 ===== */
// write access to const memory has been detected, the output may be wrong!
void __fastcall start(unsigned __int64 a1)
{
  unsigned __int64 StatusReg; // x19
  __int64 i; // x9
  __int64 (__fastcall **j)(); // x22
  unsigned __int64 v4; // x23
  __int64 (__fastcall *v5)(); // x24
  __int64 (__fastcall *v6)(); // x9
  unsigned __int64 v7; // x26
  unsigned __int64 v8; // x25
  __int64 v9; // x27
  unsigned __int64 v11; // x23
  __int64 *v12; // x13
  unsigned __int64 v13; // x12
  unsigned __int64 v14; // x11
  __int64 v15; // x9
  unsigned __int64 v16; // x14
  __int64 *v17; // x10
  unsigned __int64 v18; // x9
  __int64 k; // x9

  _WriteStatusReg(SCTLR_EL1, _ReadStatusReg(SCTLR_EL1) & 0xFFFFFFFFFFFFEFF3LL | 0x1004);
  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  if ( (StatusReg & 0xFFF) != 0 )
  {
    while ( 1 )
      ;
  }
  for ( i = 0; i != 256; ++i )
    qword_9405D000[i] = 0;
  for ( j = &off_9405A000; ; j += 5 )
  {
    v5 = *j;
    v4 = (unsigned __int64)j[1];
    v7 = (unsigned __int64)j[2];
    v6 = j[3];
    if ( ((unsigned __int8)v6 & 8) != 0 )
    {
      v5 = start;
      if ( a1 != 0 )
        v7 = a1;
      *j = start;
      j[2] = (__int64 (__fastcall *)())v7;
    }
    if ( v7 == 0 )
    {
      for ( k = 0; k < 256; ++k )
        qword_9405D800[k] = 0;
      qword_9405D800[(unsigned __int64)&loc_94020258 >> 30] = ((unsigned __int64)&loc_94020258 & 0xFFFFFFFFC0000000LL)
                                                            + 1801;
      dword_9405A0C8 = 0;
      __asm { TLBI            VMALLE1IS }
      __isb(0xFu);
      __dsb(0xFu);
      _WriteStatusReg(MAIR_EL1, 0xFF0400u);
      _WriteStatusReg(TCR_EL1, 0x2B523351AuLL);
      __isb(0xFu);
      _WriteStatusReg(TTBR0_EL1, (unsigned __int64)qword_9405D800);
      _WriteStatusReg(TTBR1_EL1, (unsigned __int64)qword_9405D000);
      __isb(0xFu);
      _WriteStatusReg(SCTLR_EL1, _ReadStatusReg(SCTLR_EL1) | 1);
      __isb(0xFu);
      JUMPOUT(0xFFFFFFFFE0000264LL);
    }
    v8 = v7;
    if ( ((unsigned __int8)v6 & 2) != 0 )
    {
      v9 = 0x60000000000400LL;
      goto LABEL_22;
    }
    if ( ((unsigned __int8)v6 & 4) != 0 )
      break;
    do
    {
      v9 = 0x40000000000788LL;
      v7 = -536682496LL - v4;
      if ( v4 >= 0xFFFFFFFFE002E000LL )
      {
        v9 = 0x60000000000788LL;
        v7 = -536633344LL - v4;
        if ( v4 >= 0xFFFFFFFFE003A000LL )
        {
          v9 = 0x60000000000708LL;
          while ( v4 > 0xFFFFFFFFE03E0000LL )
            ;
          while ( v8 < -532807680LL - v4 )
            ;
          v7 = v8;
        }
      }
LABEL_22:
      _CF = v8 >= v7;
      v8 -= v7;
      while ( !_CF )
        ;
      while ( (((unsigned __int16)(v4 | (unsigned __int16)v5) | (unsigned __int16)v7) & 0xFFF) != 0 )
        ;
      v11 = v4 ^ 0xFFFFFFFFE0000000LL;
      while ( (v11 & 0xFFFFFFFFE0000000LL) != 0 )
        ;
      do
      {
        v12 = qword_9405D000;
        v13 = 21;
        v14 = v11 >> 21;
        while ( v13 > 0x1E
             || (v11 | (unsigned __int64)v5) >> v13 << v13 != (v11 | (unsigned __int64)v5)
             || v7 >> v13 == 0 )
        {
          v16 = v12[v14];
          if ( v16 == 0 )
          {
            qword_9405CA78 = -532803584;
            v17 = &qword_943FF020[508];
            do
            {
              *v17 = 0;
              v17[1] = 0;
              v17 += 2;
            }
            while ( (unsigned __int64)v17 < 0x94401000 );
            v16 = (unsigned __int64)&qword_943FF020[508] + 3;
            v12[v14] = (__int64)&qword_943FF020[508] + 3;
          }
          while ( (v16 & 3) != 3 )
            ;
          v12 = (__int64 *)(v16 & 0xFFFFFFFFFFFFFFFCLL);
          v18 = v11 & ~(-1LL << v13);
          v13 -= 9LL;
          v14 = v18 >> v13;
        }
        v15 = v9 | 3;
        if ( v13 != 12 )
          v15 = v9 | 1;
        v12[v14] = v15 | (unsigned __int64)v5;
        v11 += 1LL << v13;
        v5 = (__int64 (__fastcall *)())((char *)v5 + (1LL << v13));
        v7 -= 1LL << v13;
      }
      while ( v7 != 0 );
      v4 = v11 ^ 0xFFFFFFFFE0000000LL;
    }
    while ( v8 != 0 );
  }
  v9 = 0x60000000000404LL;
  goto LABEL_22;
}

/* ===== sub_94020264 @ 0x94020264 size 128 ===== */
void __noreturn sub_94020264()
{
  __int64 v0; // x19
  __int64 v5; // x9
  __int64 i; // x10
  signed __int64 v7; // x19

  _WriteStatusReg(TCR_EL1, 0x2B52335A7uLL);
  __isb(0xFu);
  __asm { TLBI            VMALLE1 }
  __isb(0xFu);
  if ( v0 == 0 )
  {
    v5 = -536600576;
    for ( i = 140408; i != 0; i -= 8 )
    {
      *(_QWORD *)v5 = 0;
      v5 += 8;
    }
    sub_940235C0();
  }
  if ( (unsigned __int8)v0 < 4uLL )
  {
    v7 = (unsigned __int8)v0 | ((v0 & 0xFFFFFFFFFFFFFF00LL) >> 6);
    if ( v7 < 4 )
      sub_94022500(v7);
  }
  while ( 1 )
    __wfe();
}

/* ===== sub_94022000 @ 0x94022000 size 88 ===== */
__int64 __fastcall sub_94022000(__int64 result)
{
  result = (unsigned __int8)result;
  if ( (unsigned __int8)result == 10 )
  {
    while ( (MEMORY[0xFFFFFFFFFF10000C] & 0x7F00) != 0 )
      ;
    MEMORY[0xFFFFFFFFFF100000] = 13;
  }
  while ( (MEMORY[0xFFFFFFFFFF10000C] & 0x7F00) != 0 )
    ;
  MEMORY[0xFFFFFFFFFF100000] = (unsigned __int8)result;
  return result;
}

/* ===== sub_94022058 @ 0x94022058 size 156 ===== */
__int64 __fastcall sub_94022058(_BYTE *a1, char a2)
{
  unsigned int v3; // w1

  if ( a2 != 0 )
  {
    while ( (MEMORY[0xFFFFFFFFFF10000C] & 0x10) != 0 )
      sub_94025F90();
    v3 = 0;
    *a1 = MEMORY[0xFFFFFFFFFF100000];
    return v3;
  }
  if ( (MEMORY[0xFFFFFFFFFF10000C] & 0x10) != 0 )
    return (unsigned int)-1;
  *a1 = MEMORY[0xFFFFFFFFFF100000];
  return 0;
}

/* ===== sub_940220F4 @ 0x940220F4 size 332 ===== */
__int64 sub_940220F4()
{
  __int64 v0; // x24
  __int64 v1; // x23
  int v2; // w2
  int v3; // w2
  __int64 v5; // [xsp+48h] [xbp+48h] BYREF

  v0 = sub_94022304(-50331647, 1, 0, 0);
  v1 = sub_94022304(-50331647, 0, 0, 0);
  if ( MEMORY[0xFFFFFFFFE003CB98] > 0 )
    sub_9404B2FC("gicc 0x%lx, gicd 0x%lx\n", v0, v1);
  v5 = -65536;
  v2 = sub_9404A878(-536460256, "gic", 4096, &v5, 0, v0, 1, 2);
  if ( v2 != 0 && (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
    sub_9404B2FC("%s: failed %d\n", "generic_arm64_map_regs", v2);
  v5 = -61440;
  v3 = sub_9404A878(-536460256, "gic", 4096, &v5, 0, v1, 1, 2);
  if ( v3 != 0 && (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
    sub_9404B2FC("%s: failed %d\n", "generic_arm64_map_regs", v3);
  sub_94023D9C();
  return sub_94024B9C(29, 0);
}

/* ===== sub_94022240 @ 0x94022240 size 196 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_94022240()
{
  __int64 v0; // x20
  __int64 (__fastcall *v1)(); // x2

  v0 = -536633344;
  if ( (MEMORY[0xFFFFFFFFE003A018] & 8) != 0 && (unsigned int)sub_9404CED8(MEMORY[0xFFFFFFFFE003A020], -536682352) == 0 )
    goto LABEL_8;
  if ( (MEMORY[0xFFFFFFFFE003A040] & 8) != 0 && (unsigned int)sub_9404CED8(MEMORY[0xFFFFFFFFE003A048], -536682352) == 0 )
  {
    v0 = -536633304;
LABEL_8:
    v1 = *(__int64 (__fastcall **)())v0;
    qword_9405A0A0 = *(_QWORD *)(v0 + 16);
    off_9405A098 = v1;
    dword_9405A090 = 1;
    return sub_94049900(qword_9405A078);
  }
  if ( (MEMORY[0xFFFFFFFFE003A068] & 8) != 0 )
  {
    v0 = -536633264;
    if ( (unsigned int)sub_9404CED8(MEMORY[0xFFFFFFFFE003A070], -536682352) == 0 )
      goto LABEL_8;
  }
  return sub_94049900(qword_9405A078);
}

/* ===== sub_94022304 @ 0x94022304 size 8 ===== */
void sub_94022304()
{
  __asm { SMC             #0 }
}

/* ===== sub_9402230C @ 0x9402230C size 72 ===== */
_QWORD *__fastcall sub_9402230C(_QWORD *result)
{
  __int64 v1; // [xsp+0h] [xbp-68h] BYREF

  *result = &v1;
  return result;
}

/* ===== sub_94022354 @ 0x94022354 size 68 ===== */
void __fastcall __noreturn sub_94022354(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  _WriteStatusReg(SCR_EL3, _ReadStatusReg(SCR_EL3) | 0x400);
  _WriteStatusReg(HCR_EL2, 0x80000000);
  _WriteStatusReg(CPTR_EL2, 0x33FFu);
  _WriteStatusReg(CPACR_EL1, 0x300000u);
  _WriteStatusReg(SP_EL1, (unsigned __int64)&a9);
  _WriteStatusReg(ELR_EL3, (unsigned __int64)nullsub_1);
  _WriteStatusReg(SPSR_EL3, 0x3C5u);
  __isb(0xFu);
  __asm { ERET }
}

/* ===== nullsub_1 @ 0x94022398 size 4 ===== */
void nullsub_1()
{
  ;
}

/* ===== sub_9402239C @ 0x9402239C size 24 ===== */
unsigned __int64 __fastcall sub_9402239C(unsigned __int64 *a1)
{
  unsigned __int64 result; // x0

  result = __ldaxr(a1);
  if ( result == 0 )
    return __stxr(1u, a1);
  return result;
}

/* ===== sub_940223B4 @ 0x940223B4 size 32 ===== */
unsigned __int64 *__fastcall sub_940223B4(unsigned __int64 *result)
{
  unsigned __int64 v1; // x2

  __sevl();
  do
  {
    do
    {
      __wfe();
      v1 = __ldaxr(result);
    }
    while ( v1 != 0 );
  }
  while ( __stxr(1u, result) != 0 );
  return result;
}

/* ===== sub_940223D4 @ 0x940223D4 size 8 ===== */
unsigned __int64 *__fastcall sub_940223D4(unsigned __int64 *result)
{
  atomic_store(0, result);
  return result;
}

/* ===== sub_940223FC @ 0x940223FC size 32 ===== */
__int64 __fastcall sub_940223FC(__int64 result, __int64 a2)
{
  unsigned __int64 v2; // x3

  v2 = result & 0xFFFFFFFFFFFFFFE0LL;
  do
  {
    __asm { DC              CIVAC, X3 }
    v2 += 32LL;
  }
  while ( v2 < result + a2 );
  __dsb(0xFu);
  return result;
}

/* ===== sub_9402241C @ 0x9402241C size 32 ===== */
__int64 __fastcall sub_9402241C(__int64 result, __int64 a2)
{
  unsigned __int64 v2; // x3

  v2 = result & 0xFFFFFFFFFFFFFFE0LL;
  do
  {
    __asm { DC              IVAC, X3 }
    v2 += 32LL;
  }
  while ( v2 < result + a2 );
  __dsb(0xFu);
  return result;
}

/* ===== sub_9402243C @ 0x9402243C size 60 ===== */
__int64 __fastcall sub_9402243C(__int64 result, __int64 a2)
{
  unsigned __int64 v2; // x3
  unsigned __int64 v7; // x3

  v2 = result & 0xFFFFFFFFFFFFFFE0LL;
  do
  {
    __asm { DC              CVAU, X3 }
    v2 += 32LL;
  }
  while ( v2 < result + a2 );
  __dsb(0xFu);
  v7 = result & 0xFFFFFFFFFFFFFFE0LL;
  do
  {
    __asm { IC              IVAU, X3 }
    v7 += 32LL;
  }
  while ( v7 < result + a2 );
  __dsb(0xFu);
  return result;
}

/* ===== sub_94022478 @ 0x94022478 size 56 ===== */
__int64 __fastcall sub_94022478(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v8; // x0
  __int64 vars0; // [xsp+0h] [xbp+0h]

  _WriteStatusReg(VBAR_EL1, 0xFFFFFFFFE0001000LL);
  __isb(0xFu);
  v8 = _ReadStatusReg(CurrentEL) >> 2;
  if ( (unsigned int)v8 > 1 )
    sub_94022354(v8, a2, a3, a4, a5, a6, a7, a8, vars0);
  __asm { MSR             DAIFClr, #1 }
  return sub_94022240();
}

/* ===== sub_940224B0 @ 0x940224B0 size 72 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 *sub_940224B0()
{
  unsigned __int64 v0; // x3
  __int64 *result; // x0

  nullsub_2();
  dword_94062000 = 3;
  sub_94023828(0);
  sub_940223D4((unsigned __int64 *)&qword_9405A0D0);
  result = &qword_9405A0D0;
  v0 = (unsigned __int64)&qword_9405A0D0 & 0xFFFFFFFFFFFFFFE0LL;
  do
  {
    __asm { DC              CVAC, X3 }
    v0 += 32LL;
  }
  while ( v0 < (unsigned __int64)qword_9405A0D8 );
  __dsb(0xFu);
  return result;
}

/* ===== sub_940224F8 @ 0x940224F8 size 8 ===== */
void sub_940224F8()
{
  __wfi();
}

/* ===== sub_94022500 @ 0x94022500 size 188 ===== */
__int64 __fastcall sub_94022500(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x1
  __int64 v9; // x3
  __int64 v10; // x2
  unsigned __int64 v11; // x1
  unsigned __int64 v12; // x0
  __int64 v18; // x0
  unsigned int v19; // w1
  __int64 v20; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(MPIDR_EL1);
  v9 = StatusReg & 0x1000000;
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  v10 = (StatusReg >> 8) & 0xF;
  v11 = (unsigned __int8)StatusReg | (unsigned __int64)(4 * v10);
  if ( v11 == result )
  {
    _WriteStatusReg(VBAR_EL1, 0xFFFFFFFFE0001000LL);
    __isb(0xFu);
    v12 = _ReadStatusReg(CurrentEL) >> 2;
    if ( (unsigned int)v12 > 1 )
      sub_94022354(v12, v11, v10, v9, a5, a6, a7, a8, v20);
    __asm { MSR             DAIFClr, #1 }
    sub_940223B4((unsigned __int64 *)&qword_9405A0D0);
    sub_940223D4((unsigned __int64 *)&qword_9405A0D0);
    v18 = sub_94023388(2, 1, 458751);
    nullsub_2(v18);
    do
      v19 = __ldxr((unsigned int *)&dword_94062000);
    while ( __stxr(v19 - 1, (unsigned int *)&dword_94062000) != 0 );
    __sev();
    return sub_9402377C(&dword_94062000);
  }
  return result;
}

/* ===== sub_940225BC @ 0x940225BC size 296 ===== */
__int64 __fastcall sub_940225BC(_QWORD *a1)
{
  sub_9404CB4C("iframe %p:\n", a1);
  sub_9404CB4C("x0  0x%16llx x1  0x%16llx x2  0x%16llx x3  0x%16llx\n", *a1, a1[1], a1[2], a1[3]);
  sub_9404CB4C("x4  0x%16llx x5  0x%16llx x6  0x%16llx x7  0x%16llx\n", a1[4], a1[5], a1[6], a1[7]);
  sub_9404CB4C("x8  0x%16llx x9  0x%16llx x10 0x%16llx x11 0x%16llx\n", a1[8], a1[9], a1[10], a1[11]);
  sub_9404CB4C("x12 0x%16llx x13 0x%16llx x14 0x%16llx x15 0x%16llx\n", a1[12], a1[13], a1[14], a1[15]);
  sub_9404CB4C("x16 0x%16llx x17 0x%16llx x18 0x%16llx x19 0x%16llx\n", a1[16], a1[17], a1[18], a1[19]);
  sub_9404CB4C("x20 0x%16llx x21 0x%16llx x22 0x%16llx x23 0x%16llx\n", a1[20], a1[21], a1[22], a1[23]);
  sub_9404CB4C("x24 0x%16llx x25 0x%16llx x26 0x%16llx x27 0x%16llx\n", a1[24], a1[25], a1[26], a1[27]);
  sub_9404CB4C("x28 0x%16llx x29 0x%16llx lr  0x%16llx sp  0x%16llx\n", a1[28], a1[29], a1[30], a1[31]);
  sub_9404CB4C("elr 0x%16llx\n", a1[32]);
  return sub_9404CB4C((const char *)sub_9404E298, a1[33]);
}

/* ===== sub_940226E4 @ 0x940226E4 size 332 ===== */
long double __fastcall sub_940226E4(_QWORD *a1)
{
  unsigned int StatusReg; // w20
  unsigned int v3; // w19
  __int64 v4; // x0
  __int64 v5; // x6
  __int64 v6; // x0
  __int64 v7; // x1
  _QWORD *v8; // x2
  long double result; // q0
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x0
  unsigned __int64 v18; // x1
  __int64 v19; // x0
  int v20; // w1
  unsigned __int64 v21; // x2
  unsigned __int64 v22; // x4

  StatusReg = _ReadStatusReg(ESR_EL1);
  v3 = StatusReg >> 26;
  if ( ((StatusReg >> 26) & 0xFFFFFFFB) == 0x11 )
  {
    __asm { MSR             DAIFClr, #1 }
    sub_9404D188();
    __asm { MSR             DAIFSet, #1 }
    return result;
  }
  if ( v3 == 7 )
    goto LABEL_16;
  v4 = -536682496;
  v5 = a1[32];
  if ( MEMORY[0xFFFFFFFFE002E000] == v5 )
    goto LABEL_10;
  v6 = -536682480;
  v7 = 0;
  while ( 1 )
  {
    v8 = (_QWORD *)v6;
    if ( v7 == 2 )
      break;
    ++v7;
    v6 += 16;
    if ( *v8 == v5 )
      goto LABEL_11;
  }
  sub_9404CB4C("sync_exception\n");
  sub_940225BC(a1);
  sub_9404CB4C(
    "ESR 0x%x: ec 0x%x, il 0x%x, iss 0x%x\n",
    StatusReg,
    v3,
    (StatusReg & 0x2000000) != 0,
    StatusReg & 0xFFFFFF);
  if ( v3 == 21 )
  {
    sub_9404CB4C("syscall\n");
    return result;
  }
  if ( (a1[33] & 0xFLL) != 0 )
  {
    sub_94028A08(0, 9);
LABEL_16:
    v16 = _ReadStatusReg(CPACR_EL1);
    if ( ((v16 >> 20) & 3) != 3 )
    {
      _WriteStatusReg(CPACR_EL1, (unsigned int)v16 | 0x300000);
      __isb(0xFu);
      v17 = _ReadStatusReg(TPIDR_EL1);
      v18 = _ReadStatusReg(MPIDR_EL1);
      if ( (v18 & 0x1000000) != 0 )
        v18 >>= 8;
      v19 = v17 + 88;
      v20 = (unsigned __int8)v18 | (4 * ((v18 >> 8) & 0xF));
      if ( v19 != qword_94062008[v20] || v20 != *(_DWORD *)(v19 + 520) )
      {
        *(_DWORD *)(v19 + 520) = v20;
        v21 = *(unsigned int *)(v19 + 512);
        v22 = *(unsigned int *)(v19 + 516);
        qword_94062008[v20] = v19;
        result = *(long double *)v19;
        _WriteStatusReg(FPCR, v21);
        _WriteStatusReg(FPSR, v22);
      }
    }
    return result;
  }
  v4 = sub_94028A08(3, 9);
LABEL_10:
  v8 = (_QWORD *)v4;
LABEL_11:
  a1[32] = v8[1];
  return result;
}

/* ===== sub_94022830 @ 0x94022830 size 72 ===== */
__int64 __fastcall sub_94022830(_QWORD *a1, int a2)
{
  __int64 v3; // x0

  sub_9404CB4C("invalid exception, which 0x%x\n", a2);
  sub_940225BC(a1);
  if ( (a1[33] & 0xFLL) == 0 )
    sub_94028A08(3, 9);
  v3 = sub_94028A08(0, 9);
  return sub_94022878(v3);
}

/* ===== sub_94022878 @ 0x94022878 size 88 ===== */
__int64 __fastcall sub_94022878(
        __int64 a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7,
        long double a8,
        long double a9)
{
  __int128 v9; // q8
  __int128 v10; // q9
  __int128 v11; // q10
  __int128 v12; // q11
  __int128 v13; // q12
  __int128 v14; // q13
  __int128 v15; // q14
  __int128 v16; // q15
  __int128 v17; // q16
  __int128 v18; // q17
  __int128 v19; // q18
  __int128 v20; // q19
  __int128 v21; // q20
  __int128 v22; // q21
  __int128 v23; // q22
  __int128 v24; // q23
  __int128 v25; // q24
  __int128 v26; // q25
  __int128 v27; // q26
  __int128 v28; // q27
  __int128 v29; // q28
  __int128 v30; // q29
  __int128 v31; // q30
  __int128 v32; // q31
  __int64 result; // x0
  int StatusReg; // w2
  int v35; // w1

  result = a1 + 88;
  *(long double *)result = a2;
  *(long double *)(result + 16) = a3;
  *(long double *)(result + 32) = a4;
  *(long double *)(result + 48) = a5;
  *(long double *)(result + 64) = a6;
  *(long double *)(result + 80) = a7;
  *(long double *)(result + 96) = a8;
  *(long double *)(result + 112) = a9;
  *(_OWORD *)(result + 128) = v9;
  *(_OWORD *)(result + 144) = v10;
  *(_OWORD *)(result + 160) = v11;
  *(_OWORD *)(result + 176) = v12;
  *(_OWORD *)(result + 192) = v13;
  *(_OWORD *)(result + 208) = v14;
  *(_OWORD *)(result + 224) = v15;
  *(_OWORD *)(result + 240) = v16;
  *(_OWORD *)(result + 256) = v17;
  *(_OWORD *)(result + 272) = v18;
  *(_OWORD *)(result + 288) = v19;
  *(_OWORD *)(result + 304) = v20;
  *(_OWORD *)(result + 320) = v21;
  *(_OWORD *)(result + 336) = v22;
  *(_OWORD *)(result + 352) = v23;
  *(_OWORD *)(result + 368) = v24;
  *(_OWORD *)(result + 384) = v25;
  *(_OWORD *)(result + 400) = v26;
  *(_OWORD *)(result + 416) = v27;
  *(_OWORD *)(result + 432) = v28;
  *(_OWORD *)(result + 448) = v29;
  *(_OWORD *)(result + 464) = v30;
  *(_OWORD *)(result + 480) = v31;
  *(_OWORD *)(result + 496) = v32;
  StatusReg = _ReadStatusReg(FPCR);
  v35 = _ReadStatusReg(FPSR);
  *(_DWORD *)(result + 512) = StatusReg;
  *(_DWORD *)(result + 516) = v35;
  return result;
}

/* ===== sub_94022998 @ 0x94022998 size 48 ===== */
__int64 sub_94022998()
{
  unsigned __int64 StatusReg; // x19
  __int64 v6; // x0
  __int64 v7; // x0

  StatusReg = _ReadStatusReg(TPIDR_EL1);
  sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
  __asm { MSR             DAIFClr, #2 }
  v6 = (*(__int64 (__fastcall **)(_QWORD))(StatusReg + 632))(*(_QWORD *)(StatusReg + 640));
  v7 = sub_9402753C(v6);
  return sub_940229C8(v7);
}

/* ===== sub_940229C8 @ 0x940229C8 size 88 ===== */
__int64 (*__fastcall sub_940229C8(_QWORD *a1))()
{
  unsigned __int64 v2; // x19

  v2 = (a1[77] + a1[78]) & 0xFFFFFFFFFFFFFFF0LL;
  sub_9404CDC4(v2 - 104, 0, 104);
  *(_QWORD *)(v2 - 104) = sub_94022998;
  a1[10] = v2 - 104;
  return sub_94022998;
}

/* ===== sub_94022A20 @ 0x94022A20 size 76 ===== */
_QWORD *__fastcall sub_94022A20(
        __int64 a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7,
        long double a8,
        long double a9)
{
  unsigned __int64 StatusReg; // x19

  StatusReg = _ReadStatusReg(CPACR_EL1);
  if ( ((StatusReg >> 20) & 3) != 0 )
  {
    sub_94022878(a1, a2, a3, a4, a5, a6, a7, a8, a9);
    _WriteStatusReg(CPACR_EL1, StatusReg & 0xFFCFFFFF);
    __isb(0xFu);
  }
  __dsb(0xFu);
  return sub_9402230C((_QWORD *)(a1 + 80));
}

/* ===== nullsub_2 @ 0x94022A6C size 4 ===== */
void nullsub_2()
{
  ;
}

/* ===== sub_94022A70 @ 0x94022A70 size 504 ===== */
__int64 __fastcall sub_94022A70(
        __int64 result,
        unsigned __int64 a2,
        unsigned __int64 a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6,
        unsigned int a7)
{
  unsigned __int64 v8; // x20
  unsigned __int64 v9; // x22
  __int64 v13; // x24
  __int64 v14; // x10
  __int64 v15; // x25
  unsigned __int64 v16; // x23
  unsigned __int64 v17; // x19
  __int64 v22; // t1
  __int64 v23; // x0
  __int64 v24; // [xsp+60h] [xbp+60h]
  __int64 v25; // [xsp+68h] [xbp+68h]
  __int64 v26; // [xsp+78h] [xbp+78h]
  __int64 v27; // [xsp+80h] [xbp+80h]
  __int64 *v28; // [xsp+88h] [xbp+88h]
  unsigned int v29; // [xsp+98h] [xbp+98h]
  int v30; // [xsp+9Ch] [xbp+9Ch]

  v8 = a3;
  v9 = result;
  v13 = a7;
  if ( a3 != 0 )
  {
    v14 = 1LL << a4;
    v30 = 1 << (a5 - 3);
    v15 = (1LL << a4) - 1;
    v29 = 1 << a5;
    do
    {
      v16 = a2 >> a4;
      v17 = v14 - (a2 & v15);
      if ( v17 > v8 )
        v17 = v8;
      result = *(_QWORD *)(a6 + 8 * v16);
      if ( a4 <= a5 || (*(_QWORD *)(a6 + 8 * v16) & 3LL) != 3 )
      {
        if ( result != 0 )
        {
          *(_QWORD *)(a6 + 8 * v16) = 0;
          if ( (_DWORD)v13 == -1 )
          {
            result = v9 >> 12;
            __asm { TLBI            VAAE1IS, X0 }
          }
          else
          {
            result = (v13 << 48) | (v9 >> 12);
            __asm { TLBI            VAE1IS, X0 }
          }
          __isb(0xFu);
        }
        goto LABEL_11;
      }
      v26 = a6;
      v27 = v14;
      v24 = result & 0xFFFFFFFFF000LL;
      v28 = (__int64 *)sub_9404A1F0();
      sub_94022A70(v9, a2 & v15, v17, 3 - a5 + a4, a5, v28, (unsigned int)v13);
      v14 = v27;
      a6 = v26;
      if ( v17 != v27 && v30 > 0 )
      {
        result = *v28;
        if ( *v28 != 0 )
          goto LABEL_11;
        result = (__int64)v28;
        while ( (__int64 *)result != &v28[v30 - 1] )
        {
          v22 = *(_QWORD *)(result + 8);
          result += 8;
          if ( v22 != 0 )
            goto LABEL_11;
        }
      }
      *(_QWORD *)(v26 + 8 * v16) = 0;
      __dmb(0xAu);
      if ( v29 <= 0xFFF )
      {
        result = sub_9404BBD0(v28);
        v14 = v27;
        a6 = v26;
      }
      else
      {
        if ( sub_9404989C(v24) == 0 )
        {
          v23 = sub_9404B508(v25, "bad page table paddr 0x%lx\n", v24);
          return sub_94022C68(v23);
        }
        result = sub_94049D74();
        v14 = v27;
        a6 = v26;
      }
LABEL_11:
      v8 -= v17;
      v9 += v17;
      a2 += v17;
    }
    while ( v8 != 0 );
  }
  return result;
}

/* ===== sub_94022C68 @ 0x94022C68 size 424 ===== */
__int64 __fastcall sub_94022C68(unsigned __int64 a1, _QWORD *a2, int *a3)
{
  __int64 v3; // x30
  __int64 v4; // x20
  unsigned __int64 v7; // x1
  unsigned __int64 v8; // x19
  __int64 v9; // x1
  int v10; // w2
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x2
  int v15; // w0
  __int64 v16; // x0

  v4 = v3;
  if ( a1 <= 0xFFFFFFFFDFFFFFFFLL )
  {
    sub_9404CB4C("%s:%d: vaddr 0x%lx < base 0x%lx\n", "arch_mmu_query", 104, a1, -536870912);
    return 4294967288LL;
  }
  v7 = (a1 + 0x20000000) >> 21;
  v8 = a1 + 0x20000000 - (v7 << 21);
  v9 = *(_QWORD *)(8 * v7 - 536621056);
  v10 = v9 & 3;
  v11 = v9 & 0xFFFFFFFFF000LL;
  if ( (v9 & 3) != 0 )
  {
    if ( v10 == 1 )
      goto LABEL_11;
    if ( v10 != 3 )
    {
LABEL_7:
      sub_9404B508(v4, "%s unimplemented\n", "arch_mmu_query");
      return 4294967294LL;
    }
    v12 = sub_9404A1F0(v11);
    v13 = (unsigned int)(v8 >> 12);
    v9 = *(_QWORD *)(v12 + 8 * v13);
    if ( (v9 & 3) != 0 )
    {
      if ( (v9 & 3) != 3 )
        goto LABEL_7;
      v8 -= v13 << 12;
      v11 = v9 & 0xFFFFFFFFF000LL;
LABEL_11:
      if ( a2 != nullptr )
        *a2 = v11 + v8;
      if ( a3 != nullptr )
      {
        v15 = v9 & 0x20;
        *a3 = v15;
        switch ( v9 & 0x1C )
        {
          case 4LL:
            *a3 = v15 | 2;
            break;
          case 8LL:
            break;
          case 0LL:
            *a3 = v15 | 1;
            break;
          default:
            goto LABEL_7;
        }
        v16 = (unsigned __int8)v9 & 0xC0;
        switch ( v16 )
        {
          case 128LL:
            *a3 |= 8u;
            break;
          case 192LL:
            *a3 |= 0xCu;
            break;
          case 64LL:
            *a3 |= 4u;
            break;
          default:
            break;
        }
        if ( (v9 & 0x60000000000000LL) == 0x60000000000000LL )
        {
          *a3 |= 0x10u;
          return 0;
        }
      }
      return 0;
    }
  }
  return 4294967294LL;
}

/* ===== sub_94022E10 @ 0x94022E10 size 772 ===== */
__int64 __fastcall sub_94022E10(
        __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        unsigned __int64 a4,
        __int64 a5,
        unsigned int a6,
        unsigned int a7,
        __int64 a8,
        unsigned int a9)
{
  __int64 v10; // x22
  unsigned __int64 v11; // x28
  __int64 v12; // x27
  unsigned __int64 v13; // x24
  __int64 v14; // x25
  __int64 v15; // x23
  unsigned __int64 v17; // x20
  unsigned __int64 v18; // x5
  __int64 v19; // x4
  __int64 v20; // x0
  __int64 v22; // x0
  __int64 v23; // x7
  unsigned int v24; // w27
  unsigned __int64 v25; // x0
  int v26; // w0
  unsigned __int64 v27; // x5
  int v28; // w0
  unsigned __int64 v29; // [xsp+70h] [xbp+60h]
  unsigned __int64 v30; // [xsp+70h] [xbp+60h]
  unsigned __int64 v31; // [xsp+78h] [xbp+68h]
  __int64 v32; // [xsp+78h] [xbp+68h]
  unsigned __int64 v33; // [xsp+78h] [xbp+68h]
  unsigned int v34; // [xsp+84h] [xbp+74h]
  __int64 v35; // [xsp+90h] [xbp+80h]
  __int64 v36; // [xsp+98h] [xbp+88h]
  unsigned int v40; // [xsp+B8h] [xbp+A8h]
  unsigned int v41; // [xsp+BCh] [xbp+ACh]
  __int64 v44; // [xsp+D8h] [xbp+C8h] BYREF

  if ( ((a3 | a4 | a2) & ((1LL << a7) - 1)) != 0 )
  {
    sub_9404CB4C("%s:%d: not page aligned\n", "arm64_mmu_map_pt", 363);
    return 4294967288LL;
  }
  if ( a4 == 0 )
    return 0;
  v40 = 1 << a7;
  v36 = (unsigned int)(1 << a7);
  v10 = 1LL << a6;
  v34 = (unsigned int)(1 << a7) >> 12;
  v11 = a4;
  v12 = a1;
  v13 = a2;
  v14 = a3;
  v41 = a6 + 3 - a7;
  v15 = (1LL << a6) - 1;
  while ( 1 )
  {
    v17 = v10 - (v13 & v15);
    v18 = v13 >> a6;
    if ( v17 > v11 )
      v17 = v11;
    if ( ((v14 | v13) & v15) == 0 && v17 == v10 && a6 <= 0x1E )
      break;
    v22 = *(_QWORD *)(a8 + 8 * v18);
    if ( (v22 & 3) == 1 )
      goto LABEL_21;
    if ( (v22 & 3) == 0 )
      goto LABEL_24;
    if ( (v22 & 3) != 3 )
    {
      sub_9404B508(v35, "%s unimplemented\n", (const char *)&loc_9404E478);
LABEL_24:
      if ( v40 > 0xFFF )
      {
        v33 = v18;
        v28 = sub_94049DA4(v34, a7, &v44, 0);
        v27 = v33;
        if ( v34 != v28 )
        {
LABEL_29:
          v24 = a6;
LABEL_31:
          sub_9404CB4C("%s:%d: failed to allocate page table\n", (const char *)&loc_9404E478, 237);
          goto LABEL_22;
        }
      }
      else
      {
        v29 = v18;
        v25 = sub_9404B8D0(v36, v40);
        v31 = v25;
        if ( v25 == 0 )
          goto LABEL_29;
        v26 = sub_94022C68(v25, &v44, nullptr);
        v27 = v29;
        if ( v26 != 0 )
        {
          v24 = a6;
          sub_9404BBD0(v31);
          goto LABEL_31;
        }
      }
      v30 = v27;
      v32 = sub_9404A1F0(v44);
      sub_9404CDC4(v32, 0, v36);
      __dmb(0xAu);
      v23 = v32;
      *(_QWORD *)(a8 + 8 * v30) = v44 | 3;
      goto LABEL_19;
    }
    v44 = v22 & 0xFFFFFFFFF000LL;
    v23 = sub_9404A1F0(v22 & 0xFFFFFFFFF000LL);
LABEL_19:
    if ( v23 == 0 || (unsigned int)sub_94022E10(v12, v13 & v15, v14, v17, a5, v41, a7) != 0 )
    {
LABEL_21:
      v24 = a6;
      goto LABEL_22;
    }
LABEL_13:
    v11 -= v17;
    v12 += v17;
    v13 += v17;
    v14 += v17;
    if ( v11 == 0 )
      return 0;
  }
  v19 = *(_QWORD *)(a8 + 8 * v18);
  if ( v19 == 0 )
  {
    v20 = v14 | a5 | 3;
    if ( a7 < a6 )
      v20 = v14 | a5 | 1;
    *(_QWORD *)(a8 + 8 * v18) = v20;
    goto LABEL_13;
  }
  v24 = a6;
  sub_9404CB4C("%s:%d: page table entry already in use, index 0x%lx, 0x%llx\n", "arm64_mmu_map_pt", 391, v13 >> a6, v19);
LABEL_22:
  sub_94022A70(a1, a2, a4 - v11, v24, a7, a8, a9);
  __dsb(0xFu);
  return 0xFFFFFFFFLL;
}

/* ===== sub_94023114 @ 0x94023114 size 204 ===== */
__int64 __fastcall sub_94023114(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        __int64 a5,
        char a6,
        unsigned int a7,
        unsigned int a8,
        __int64 a9,
        unsigned int a10)
{
  unsigned __int64 v10; // x8
  __int64 result; // x0

  v10 = 1LL << a6;
  if ( a1 - a5 > (1LL << a6) - a3 || v10 < a3 )
  {
    sub_9404CB4C(
      "%s:%d: vaddr 0x%lx, size 0x%lx out of range vaddr 0x%lx, size 0x%lx\n",
      "arm64_mmu_map",
      433,
      a1,
      a3,
      a5,
      v10);
    return 4294967288LL;
  }
  else if ( a9 != 0 )
  {
    result = sub_94022E10(a1, a1 - a5, a2, a3, a4, a7, a8, a9, a10);
    __dsb(0xFu);
  }
  else
  {
    sub_9404CB4C("%s:%d: page table is NULL\n", "arm64_mmu_map", 438);
    return 4294967288LL;
  }
  return result;
}

/* ===== sub_940231E0 @ 0x940231E0 size 176 ===== */
__int64 __fastcall sub_940231E0(
        __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        char a4,
        unsigned int a5,
        unsigned int a6,
        __int64 a7,
        unsigned int a8)
{
  unsigned __int64 v8; // x8

  v8 = 1LL << a4;
  if ( a1 - a3 > (1LL << a4) - a2 || v8 < a2 )
  {
    sub_9404CB4C(
      "%s:%d: vaddr 0x%lx, size 0x%lx out of range vaddr 0x%lx, size 0x%lx\n",
      (const char *)&loc_9404E4B8,
      460,
      a1,
      a2,
      a3,
      v8);
    return 4294967288LL;
  }
  else if ( a7 != 0 )
  {
    sub_94022A70(a1, a1 - a3, a2, a5, a6, a7, a8);
    __dsb(0xFu);
    return 0;
  }
  else
  {
    sub_9404CB4C("%s:%d: page table is NULL\n", (const char *)&loc_9404E4B8, 465);
    return 4294967288LL;
  }
}

/* ===== sub_94023290 @ 0x94023290 size 212 ===== */
__int64 __fastcall sub_94023290(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  unsigned __int64 v4; // x2
  __int64 v5; // x4
  int v6; // w5
  bool v7; // zf
  int v8; // w3
  __int64 v9; // x3

  v4 = (unsigned __int64)a3 << 12;
  if ( (a4 & 3) == 1 )
  {
    v5 = 1024;
    goto LABEL_5;
  }
  if ( (a4 & 3) != 0 )
  {
    if ( (a4 & 3) != 2 )
    {
      v9 = -8;
      return sub_94023114(a1, a2, v4, v9, -536870912, 29, 0x15u, 0xCu, -536621056, 0xFFFFFFFF);
    }
    v5 = 1028;
LABEL_5:
    v6 = a4 & 0xC;
    if ( v6 != 8 )
      goto LABEL_6;
    goto LABEL_17;
  }
  v6 = a4 & 0xC;
  v5 = 1800;
  if ( v6 != 8 )
  {
LABEL_6:
    if ( v6 == 12 )
    {
      v5 |= 0xC0uLL;
    }
    else if ( v6 == 4 )
    {
      v5 |= 0x40uLL;
    }
    goto LABEL_9;
  }
LABEL_17:
  v5 |= 0x80uLL;
LABEL_9:
  v7 = (a4 & 0x12) == 0;
  v8 = a4 & 0x20;
  if ( !v7 )
    v5 |= 0x60000000000000uLL;
  v7 = v8 == 0;
  v9 = v5 | 0x20;
  if ( v7 )
    v9 = v5;
  return sub_94023114(a1, a2, v4, v9, -536870912, 29, 0x15u, 0xCu, -536621056, 0xFFFFFFFF);
}

/* ===== sub_94023364 @ 0x94023364 size 36 ===== */
__int64 __fastcall sub_94023364(__int64 a1, unsigned int a2)
{
  return sub_940231E0(a1, (unsigned __int64)a2 << 12, -536870912, 29, 0x15u, 0xCu, -536621056, 0xFFFFFFFF);
}

/* ===== sub_94023388 @ 0x94023388 size 532 ===== */
__int64 __fastcall sub_94023388(int a1, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x30
  __int64 result; // x0
  unsigned int *v8; // x19
  __int64 v9; // x1
  int v10; // w3
  unsigned int *v11; // x2
  unsigned int v12; // w4
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0

  if ( a2 != 0 )
  {
    result = a2 - 1;
    v8 = nullptr;
    v9 = -536636368;
    while ( 2 )
    {
      v10 = 0;
      v11 = nullptr;
      do
      {
        if ( (unsigned int *)v9 == v8 )
          v10 = 1;
        if ( (a1 & *(_DWORD *)(v9 + 4)) != 0 )
        {
          v12 = *(_DWORD *)v9;
          if ( *(_DWORD *)v9 <= a3 && (unsigned int)result <= v12 && (v11 == nullptr || v12 < *v11) )
          {
            if ( a2 > v12 || (unsigned int)result >= v12 )
            {
              if ( (_DWORD)result == v12 && (unsigned int *)v9 != v8 && v10 != 0 )
              {
                v8 = (unsigned int *)v9;
                goto LABEL_17;
              }
            }
            else
            {
              v11 = (unsigned int *)v9;
            }
          }
        }
        v9 += 24;
      }
      while ( v9 != -536635432 );
      if ( v11 != nullptr )
      {
        result = *v11;
        v8 = v11;
LABEL_17:
        (*((void (__fastcall **)(__int64))v8 + 1))(result);
        v9 = -536636368;
        result = *v8;
        continue;
      }
      break;
    }
  }
  else
  {
    sub_9404B508(v3, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/top/init.c", 51, "start_level > 0");
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      sub_9404B2FC("top of bootstrap2()\n");
    sub_94023388(1, 458752, 0x7FFFF);
    sub_940224B0();
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      sub_9404B2FC("initializing platform\n");
    v13 = sub_94023388(1, 0x80000, 589823);
    nullsub_6(v13);
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      sub_9404B2FC("initializing target\n");
    v14 = sub_94023388(1, 589824, 655359);
    nullsub_8(v14);
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      sub_9404B2FC("calling apps_init()\n");
    v15 = sub_94023388(1, 655360, 720895);
    sub_9402396C(v15);
    sub_94023388(1, 720896, 0xFFFFFFFFLL);
    return 0;
  }
  return result;
}

/* ===== sub_9402359C @ 0x9402359C size 36 ===== */
__int64 sub_9402359C()
{
  sub_94023388(2, 0x70000u, 0xFFFFFFFF);
  return 0;
}

/* ===== sub_940235C0 @ 0x940235C0 size 444 ===== */
void __fastcall __noreturn sub_940235C0(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 *v4; // x21
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x5
  __int64 v11; // x6
  __int64 v12; // x7
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x19
  __int64 v19; // x0

  v4 = &qword_9405BFF0[2];
  MEMORY[0xFFFFFFFFE005A038] = a4;
  MEMORY[0xFFFFFFFFE005A020] = a1;
  MEMORY[0xFFFFFFFFE005A028] = a2;
  MEMORY[0xFFFFFFFFE005A030] = a3;
  sub_940268E8();
  v5 = sub_94023388(1, 1u, 0xFFFFu);
  sub_94022478(v5, v6, v7, v8, v9, v10, v11, v12);
  v13 = sub_94023388(1, 0x10000u, 0x1FFFFu);
  nullsub_5(v13);
  v14 = sub_94023388(1, 0x20000u, 0x2FFFFu);
  nullsub_7(v14);
  if ( MEMORY[0xFFFFFFFFE003CB98] > 0 )
  {
    sub_9404B2FC("\nwelcome to lk/MP\n\n");
    if ( MEMORY[0xFFFFFFFFE003CB98] > 0 )
    {
      sub_9404B2FC(
        "boot args 0x%lx 0x%lx 0x%lx 0x%lx\n",
        MEMORY[0xFFFFFFFFE005A020],
        MEMORY[0xFFFFFFFFE005A028],
        MEMORY[0xFFFFFFFFE005A030],
        MEMORY[0xFFFFFFFFE005A038]);
      if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      {
        sub_9404B2FC("calling constructors\n");
        if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
          sub_9404B2FC("initializing heap\n");
      }
    }
  }
  while ( 1 )
  {
    v15 = sub_94023388(1, 0x30000u, 0x3FFFFu);
    sub_9404BD38(v15);
    v16 = sub_94023388(1, 0x40000u, 0x5FFFFu);
    sub_9402514C(v16);
    sub_94023388(1, 0x60000u, 0x6FFFFu);
    v4 = (__int64 *)v4[464];
    if ( *v4 > 1 )
      sub_9404B2FC("creating bootstrap completion thread\n");
    v17 = sub_940268B8("bootstrap2", &loc_940234AC, 0, 16, 4096);
    *(_DWORD *)(v17 + 60) = 0;
    v18 = v17;
    sub_940273FC();
    v19 = sub_940260B0(v18);
    sub_94026568(v19);
  }
}

/* ===== sub_9402377C @ 0x9402377C size 172 ===== */
__int64 sub_9402377C()
{
  unsigned __int64 StatusReg; // x0
  __int64 v1; // x1
  __int64 result; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  v1 = (unsigned __int8)StatusReg | (4 * ((unsigned int)(StatusReg >> 8) & 0xF));
  if ( (_DWORD)v1 == 0 )
  {
    sub_94026A14((unsigned __int8)StatusReg, v1, &dword_94062000);
    sub_940260B0(MEMORY[0x894062020]);
    v3 = MEMORY[0xFFFFFFFFE003CB98];
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      v3 = sub_9404B2FC("entering scheduler on cpu %d\n", 0);
    sub_94026670(v3);
  }
  result = MEMORY[0xFFFFFFFFE003CB98];
  if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
    return sub_9404B2FC(
             "Invalid secondary cpu num %d, SMP_MAX_CPUS %d, secondary_bootstrap_thread_count %d\n",
             v1,
             4,
             0);
  return result;
}

/* ===== sub_94023828 @ 0x94023828 size 292 ===== */
// write access to const memory has been detected, the output may be wrong!
int *__fastcall sub_94023828(unsigned int a1)
{
  unsigned int v1; // w23
  __int64 v2; // x21
  unsigned int v3; // w19
  __int64 v4; // x20
  __int64 v5; // x1
  unsigned int v6; // w22
  __int64 v7; // x0
  __int64 v8; // x21

  v1 = a1;
  if ( a1 <= 3 )
  {
    if ( a1 == 0 )
      goto LABEL_11;
    v2 = MEMORY[0xFFFFFFFFE003CB98];
  }
  else
  {
    v2 = MEMORY[0xFFFFFFFFE003CB98];
    if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
    {
      sub_9404B2FC("Invalid secondary_cpu_count %d, SMP_MAX_CPUS %d\n", a1, 4);
      v2 = MEMORY[0xFFFFFFFFE003CB98];
    }
    v1 = 3;
  }
  v3 = 1;
  v4 = 0;
  v5 = 1;
  v6 = 1;
  if ( v2 > 1 )
LABEL_6:
    sub_9404B2FC("creating bootstrap completion thread for cpu %d\n", v5);
  while ( 1 )
  {
    v7 = sub_940268B8(&loc_9404E700, sub_9402359C, 0, 16, 4096);
    *(_DWORD *)(v7 + 60) = v3;
    v8 = v7;
    ++v3;
    sub_940273FC();
    qword_94062028[v4++] = v8;
    if ( v1 <= v6 )
      break;
    v5 = v3;
    v6 = v3;
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      goto LABEL_6;
  }
LABEL_11:
  dword_94062040 = v1;
  return &dword_94062000;
}

/* ===== sub_9402394C @ 0x9402394C size 32 ===== */
__int64 __fastcall sub_9402394C(__int64 a1)
{
  (*(void (__fastcall **)(__int64, _QWORD))(a1 + 16))(a1, 0);
  return 0;
}

/* ===== sub_9402396C @ 0x9402396C size 236 ===== */
__int64 sub_9402396C()
{
  return -536621840;
}

/* ===== sub_94023A58 @ 0x94023A58 size 40 ===== */
__int64 sub_94023A58()
{
  MEMORY[0xFFFFFFFFFFFF0000] = 11;
  MEMORY[0xFFFFFFFFFFFF1080] = -1;
  MEMORY[0xFFFFFFFFFFFF0004] = 255;
  return -65532;
}

/* ===== sub_94023A80 @ 0x94023A80 size 332 ===== */
__int64 __fastcall sub_94023A80(char a1, unsigned __int8 a2, int a3, unsigned __int8 a4)
{
  int v4; // w22
  int v6; // w23
  unsigned __int8 v7; // w20
  unsigned int v8; // w19
  int v9; // w20
  __int64 v10; // x1
  int v11; // w11
  unsigned __int64 v12; // x7
  int v13; // w10
  int v14; // w0
  unsigned int v15; // w5
  unsigned int v16; // w14
  char v17; // w4
  int v18; // w8
  int v19; // w4
  char v20; // w4
  unsigned int v21; // w5
  __int64 v22; // x4
  int v24; // w4

  v4 = a2;
  v6 = a4;
  v7 = MEMORY[0xFFFFFFFFFFFF1004];
  sub_940223B4((unsigned __int64 *)&qword_94065E08);
  v8 = 0;
  v9 = v7 >> 5;
  v10 = 0;
  v11 = (unsigned __int8)(1 << a1);
  do
  {
    v12 = qword_94065E18[v10];
    if ( v12 != 0 )
    {
      v13 = 1 * v10;
      do
      {
        while ( 1 )
        {
          while ( 1 )
          {
            v14 = __clz(__rbit64(v12));
            v15 = v14 + v13;
            v16 = (unsigned int)(v14 + v13) >> 2;
            v17 = 8 * ((v14 + v13) & 3);
            v18 = v11 << v17;
            v19 = (-v4 << v17) & (v11 << v17);
            v12 &= ~(1LL << v14);
            if ( v14 + v13 == a3 )
              v8 = 1;
            if ( v9 == 0 )
              break;
            v24 = *((_DWORD *)qword_9405A178 + v16) & ~v18 | v19;
            *((_DWORD *)qword_9405A178 + v16) = v24;
            *(_DWORD *)(4LL * ((v16 + 1536) & 0x3FFFFFFF) - 0x10000) = v24;
            if ( v6 != 0 )
              break;
            if ( v12 == 0 )
              goto LABEL_9;
          }
          v20 = v15 & 0x1F;
          v21 = v15 >> 5;
          v22 = 1LL << v20;
          if ( v4 == 0 )
            break;
          *(_DWORD *)(4LL * ((v21 + 1088) & 0xFFFFFFF) - 0x10000) = v22;
          if ( v12 == 0 )
            goto LABEL_9;
        }
        *(_DWORD *)(4LL * ((v21 + 1120) & 0xFFFFFFF) - 0x10000) = v22;
      }
      while ( v12 != 0 );
    }
LABEL_9:
    ++v10;
  }
  while ( v10 != 16 );
  sub_940223D4((unsigned __int64 *)&qword_94065E08);
  return v8;
}

/* ===== sub_94023BCC @ 0x94023BCC size 104 ===== */
__int64 sub_94023BCC()
{
  __int64 v0; // x30
  unsigned __int64 StatusReg; // x1
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  if ( ((unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF))) <= 7 )
    return sub_94023A80((unsigned __int8)StatusReg | (unsigned __int8)(4 * (BYTE1(StatusReg) & 0xF)), 0, -1, 0);
  v3 = sub_9404B508(v0, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/dev/interrupt/arm_gic/arm_gic.c", 573, "cpu < 8");
  return sub_94023C34(v3);
}

/* ===== sub_94023C34 @ 0x94023C34 size 360 ===== */
unsigned __int64 *__fastcall sub_94023C34(unsigned int a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x30
  unsigned __int64 StatusReg; // x20
  char v6; // w21
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 *v14; // x19
  unsigned __int64 *result; // x0
  __int64 *v18; // x19
  __int64 v20; // x0
  __int64 v21; // [xsp+40h] [xbp+40h]
  __int64 v22; // [xsp+48h] [xbp+48h]

  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  if ( a1 > 0x3FB )
  {
    v20 = sub_9404B508(v3, "register_int_handler: vector out of range %d\n", a1);
    return (unsigned __int64 *)sub_94023D9C(v20);
  }
  v6 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    v21 = a3;
    v22 = a2;
    if ( (_ReadStatusReg(DAIF) & 0x40) == 0 )
    {
LABEL_6:
      v6 |= 2u;
      __asm { MSR             DAIFSet, #1 }
      sub_940223B4((unsigned __int64 *)&qword_94065E08);
      v12 = v22;
      v13 = v21;
      goto LABEL_7;
    }
  }
  else
  {
    __asm { MSR             DAIFSet, #2 }
    v6 = 1;
    v21 = a3;
    v22 = a2;
    if ( (_ReadStatusReg(DAIF) & 0x40) == 0 )
      goto LABEL_6;
  }
  sub_940223B4((unsigned __int64 *)&qword_94065E08);
  v12 = v22;
  v13 = v21;
LABEL_7:
  if ( a1 > 0x1F )
  {
    v18 = &qword_94062048[2 * a1 - 64];
    *v18 = v12;
    v18[1] = v13;
    result = sub_940223D4((unsigned __int64 *)&qword_94065E08);
    if ( (v6 & 2) == 0 )
      goto LABEL_9;
  }
  else
  {
    v14 = &qword_94065E98[8 * a1 + 2 * ((unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF)))];
    *v14 = v12;
    v14[1] = v13;
    result = sub_940223D4((unsigned __int64 *)&qword_94065E08);
    if ( (v6 & 2) == 0 )
      goto LABEL_9;
  }
  __asm { MSR             DAIFClr, #1 }
LABEL_9:
  if ( (v6 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  return result;
}

/* ===== sub_94023D9C @ 0x94023D9C size 236 ===== */
__int64 sub_94023D9C()
{
  int v0; // w2
  int v1; // w0
  int v2; // w0
  int i; // w1
  int v4; // w2
  int v5; // w0
  int v6; // w1
  unsigned int v7; // w2
  int v8; // w0

  v0 = 0;
  do
  {
    v1 = v0 >> 5;
    v0 += 32;
    v2 = 4 * (v1 + 1120);
    *(_DWORD *)(v2 - 0x10000LL) = -1;
    *(_DWORD *)(v2 + 256 - 0x10000LL) = -1;
  }
  while ( v0 != 1024 );
  if ( MEMORY[0xFFFFFFFFFFFF1004] >> 5 != 0 )
  {
    for ( i = 32; i != 1020; i += 4 )
    {
      v4 = i >> 2;
      v5 = (i >> 2) + 1536;
      *(_DWORD *)(4 * v5 - 0x10000LL) = *((_DWORD *)qword_9405A178 + v4);
    }
  }
  v6 = 32;
  MEMORY[0xFFFFFFFFFFFF1000] = 3;
  do
  {
    v7 = v6 >> 5;
    v8 = (v6 >> 5) + 1056;
    v6 += 32;
    *(_DWORD *)(4LL * (v8 & 0x3FFFFFFF) - 0x10000) = *((_DWORD *)qword_9405A0D8 + v7);
  }
  while ( v6 != 1024 );
  MEMORY[0xFFFFFFFFFFFF0000] = 11;
  MEMORY[0xFFFFFFFFFFFF1080] = -1;
  MEMORY[0xFFFFFFFFFFFF0004] = 255;
  return -65532;
}

/* ===== sub_94023E88 @ 0x94023E88 size 300 ===== */
__int64 sub_94023E88()
{
  __int64 v0; // x30
  __int64 v1; // x21
  char v2; // w19
  unsigned __int8 v9; // w22
  unsigned __int64 StatusReg; // x1
  __int64 v14; // x0

  v1 = v0;
  v2 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v2 = 1;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) == 0 )
  {
    v2 |= 2u;
    __asm { MSR             DAIFSet, #1 }
  }
  sub_940223B4((unsigned __int64 *)&qword_94065E08);
  if ( (MEMORY[0xFFFFFFFFFFFF1000] & 1) != 0 )
  {
    v9 = 0;
    MEMORY[0xFFFFFFFFFFFF0000] = 11;
    MEMORY[0xFFFFFFFFFFFF1080] = -1;
    MEMORY[0xFFFFFFFFFFFF0004] = 255;
  }
  else
  {
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      sub_9404B2FC("%s: distibutor is off, calling arm_gic_init instead\n", "arm_gic_resume_cpu");
    v9 = 1;
    sub_94023D9C();
  }
  sub_940223D4((unsigned __int64 *)&qword_94065E08);
  if ( (v2 & 2) != 0 )
    __asm { MSR             DAIFClr, #1 }
  if ( (v2 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  if ( ((unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF))) <= 7 )
    return sub_94023A80((unsigned __int8)StatusReg | (unsigned __int8)(4 * (BYTE1(StatusReg) & 0xF)), 1u, -1, v9);
  v14 = sub_9404B508(
          v1,
          "ASSERT FAILED at (%s:%d): %s\n",
          "external/lk/dev/interrupt/arm_gic/arm_gic.c",
          573,
          "cpu < 8");
  return sub_94023FB4(v14);
}

/* ===== sub_94023FB4 @ 0x94023FB4 size 76 ===== */
__int64 __fastcall sub_94023FB4(unsigned int a1)
{
  __int64 v1; // x2
  _DWORD *v2; // x1

  if ( a1 > 0x3FB )
    return 4294967288LL;
  v1 = 1LL << (a1 & 0x1F);
  v2 = (_DWORD *)(4LL * ((a1 >> 5) + 1088) - 0x10000);
  *v2 = v1;
  return 0;
}

/* ===== sub_94024000 @ 0x94024000 size 484 ===== */
__int64 sub_94024000()
{
  char v0; // w21
  unsigned int v1; // w19
  unsigned __int64 StatusReg; // x0
  int v3; // w20
  __int64 *v4; // x0
  char v5; // w23
  char v7; // w21
  int v8; // w2
  int *v9; // x1
  unsigned int v10; // w3
  unsigned int v11; // w22
  __int64 *v14; // x20
  __int64 result; // x0

  v0 = MEMORY[0xFFFFFFFFFFFF0028];
  v1 = MEMORY[0xFFFFFFFFFFFF0028] & 0x3FF;
  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  if ( v1 > 0x3FB )
    return sub_94029348();
  v3 = (unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF));
  v4 = v1 <= 0x1F
     ? &qword_94065E98[8 * (v1 & 0x3FF) + 2 * (unsigned __int8)(StatusReg | (4 * (BYTE1(StatusReg) & 0xF)))]
     : &qword_94062048[2 * v1 - 64];
  if ( *v4 == 0 )
    return sub_94029348();
  v5 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v5 = 1;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) == 0 )
  {
    v5 |= 2u;
    __asm { MSR             DAIFSet, #1 }
  }
  v7 = 8 * (v0 & 3);
  sub_940223B4((unsigned __int64 *)&qword_94065E08);
  v8 = ~(255 << v7);
  v9 = (int *)(4LL * (((unsigned __int16)(v1 >> 2) + 1280) & 0xFFF) - 0x10000);
  v10 = *v9;
  *v9 &= v8;
  __dsb(0xFu);
  v11 = MEMORY[0xFFFFFFFFFFFF0020] & 0x3FF;
  *v9 = ((unsigned __int8)(v10 >> v7) << v7) | *v9 & v8;
  sub_940223D4((unsigned __int64 *)&qword_94065E08);
  if ( (v5 & 2) != 0 )
    __asm { MSR             DAIFClr, #1 }
  if ( (v5 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  if ( v11 <= 0x3FB
    && (v1 <= 0x1F
      ? (v14 = &qword_94065E98[8 * (v1 & 0x3FF) + 2 * (unsigned __int8)v3])
      : (v14 = &qword_94062048[2 * v1 - 64]),
        *v14 != 0) )
  {
    result = ((__int64 (__fastcall *)(__int64))*v14)(v14[1]);
    MEMORY[0xFFFFFFFFFFFF0024] = v11;
  }
  else
  {
    sub_9404CB4C("%s:%d: unexpected irq %d != %d may get lost\n", "platform_irq", 450, v11, v1);
    MEMORY[0xFFFFFFFFFFFF0024] = v11;
    return 0;
  }
  return result;
}

/* ===== sub_940241E4 @ 0x940241E4 size 4 ===== */
// attributes: thunk
__int64 sub_940241E4()
{
  return sub_9402944C();
}

/* ===== sub_940241E8 @ 0x940241E8 size 308 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_940241E8(__int64 a1)
{
  char v2; // w20
  unsigned int v9; // w5
  unsigned int v10; // w4
  unsigned int v11; // w0
  unsigned __int64 StatusReg; // x2
  __int64 *v13; // x1
  __int64 *v14; // x2
  __int64 v15; // x19

  v2 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v2 = 1;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) == 0 )
  {
    v2 |= 2u;
    __asm { MSR             DAIFSet, #1 }
  }
  sub_940223B4((unsigned __int64 *)&qword_94065E08);
  v9 = *(_DWORD *)(a1 + 8) != 0;
  byte_94065E10 = 1;
  if ( v9 != 0 )
    v10 = 32;
  else
    v10 = 1020;
  v11 = *(_DWORD *)(a1 + 4);
  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  if ( (v11 <= 0x1F) > v9 )
    v11 = 32;
  if ( v10 <= v11 )
  {
LABEL_22:
    v15 = -10;
    sub_940223D4((unsigned __int64 *)&qword_94065E08);
    if ( (v2 & 2) == 0 )
      goto LABEL_19;
    goto LABEL_23;
  }
  v13 = &qword_94065E98[8 * v11 + 2 * ((unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF)))];
  while ( 1 )
  {
    v14 = v13;
    if ( v11 > 0x1F )
      v14 = &qword_94062048[2 * v11 - 64];
    v13 += 8;
    if ( *v14 != 0 )
      break;
    if ( ++v11 == v10 )
      goto LABEL_22;
  }
  v15 = (int)v11;
  sub_940223D4((unsigned __int64 *)&qword_94065E08);
  if ( (v2 & 2) != 0 )
LABEL_23:
    __asm { MSR             DAIFClr, #1 }
LABEL_19:
  if ( (v2 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  return v15;
}

/* ===== sub_9402431C @ 0x9402431C size 484 ===== */
__int64 __fastcall sub_9402431C(__int64 a1)
{
  unsigned int v1; // w22
  BOOL v2; // w23
  char v3; // w20
  signed int v10; // w0
  __int64 v11; // x6
  int v12; // w2
  __int64 v13; // x2
  int v14; // w1
  int v15; // w4
  int v16; // w1
  __int64 v17; // x0
  __int64 v21; // x4

  v1 = *(_DWORD *)(a1 + 4);
  v2 = *(_DWORD *)(a1 + 8) != 0;
  if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
    sub_9404B2FC("%s: fiq %d, enable %d\n", "smc_intc_request_fiq", v1, v2);
  v3 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v3 = 1;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) == 0 )
  {
    v3 |= 2u;
    __asm { MSR             DAIFSet, #1 }
  }
  sub_940223B4((unsigned __int64 *)&qword_94065E08);
  v10 = v1 >> 5;
  v11 = 1LL << (v1 & 0x1F);
  if ( v1 <= 0x3FB )
  {
    v12 = *((_DWORD *)qword_9405A0D8 + v10) & ~(_DWORD)v11;
    *((_DWORD *)qword_9405A0D8 + v10) = v12;
    *(_DWORD *)(4LL * ((v1 >> 5) + 1056) - 0x10000) = v12;
  }
  v13 = 4 * ((v1 >> 2) + 1536);
  v14 = 255 << (8 * (v1 & 3));
  v15 = ~v14;
  v16 = ~v14 & *((_DWORD *)qword_9405A178 + (v1 >> 2)) | (-1 << (8 * (v1 & 3))) & v14;
  *(_DWORD *)(v13 - 0x10000) = v16;
  *((_DWORD *)qword_9405A178 + (v1 >> 2)) = v16;
  *(_DWORD *)((unsigned int)(v13 - 1024) - 0x10000LL) &= v15;
  if ( v2 )
  {
    v17 = qword_94065E18[v1 >> 6];
    *(_DWORD *)(4LL * ((v1 >> 5) + 1088) - 0x10000) = v11;
    qword_94065E18[v1 >> 6] = v17 | (1LL << v1);
  }
  else
  {
    v21 = qword_94065E18[v1 >> 6];
    *(_DWORD *)(4LL * ((v1 >> 5) + 1120) - 0x10000) = v11;
    qword_94065E18[v1 >> 6] = v21 & ~(1LL << v1);
  }
  if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
    sub_9404B2FC("%s: fiq %d, enable %d done\n", "smc_intc_request_fiq", v1, v2);
  sub_940223D4((unsigned __int64 *)&qword_94065E08);
  if ( (v3 & 2) != 0 )
    __asm { MSR             DAIFClr, #1 }
  if ( (v3 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  return 0;
}

/* ===== sub_94024500 @ 0x94024500 size 316 ===== */
__int64 sub_94024500()
{
  __int64 v0; // x30
  unsigned __int64 StatusReg; // x1
  unsigned int v2; // w19
  unsigned int v3; // w20
  char v4; // w0
  int v5; // w2
  unsigned int v6; // w21

  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  v2 = (unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF));
  v3 = MEMORY[0xFFFFFFFFFFFF000C] & 0x3FF;
  if ( v2 > 7 )
  {
    sub_9404B508(v0, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/dev/interrupt/arm_gic/arm_gic.c", 584, "cpu < 8");
  }
  else if ( v3 <= 0x3FB )
  {
    v4 = sub_94023A80((unsigned __int8)StatusReg | (unsigned __int8)(4 * (BYTE1(StatusReg) & 0xF)), 0, v3, 0);
    MEMORY[0xFFFFFFFFFFFF0010] = v3;
    v5 = *((_DWORD *)qword_9405A158 + v2);
    if ( v5 != 1023 )
    {
      v6 = -6;
      if ( MEMORY[0xFFFFFFFFE003CB98] > 0 )
        sub_9404B2FC("more than one fiq active: cpu %d, old %d, new %d\n", v2, v5, v3);
      return v6;
    }
    if ( v4 == 0 )
    {
      v6 = -3;
      if ( MEMORY[0xFFFFFFFFE003CB98] > 0 )
        sub_9404B2FC("got disabled fiq: cpu %d, new %d\n", v2, v3);
      return v6;
    }
    *((_DWORD *)qword_9405A158 + v2) = v3;
    return 0;
  }
  return (unsigned int)-4;
}

/* ===== sub_9402463C @ 0x9402463C size 212 ===== */
__int64 sub_9402463C()
{
  __int64 v0; // x30
  unsigned __int64 StatusReg; // x1
  unsigned int v2; // w19
  int v3; // w2
  __int64 result; // x0

  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  v2 = (unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF));
  if ( v2 > 7 )
  {
    sub_9404B508(v0, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/dev/interrupt/arm_gic/arm_gic.c", 615, "cpu < 8");
    _WriteStatusReg(CNTPS_TVAL_EL1, 0);
    __isb(0xFu);
    return 0;
  }
  else
  {
    v3 = *((_DWORD *)qword_9405A158 + v2);
    if ( v3 == 1023 )
    {
      result = MEMORY[0xFFFFFFFFE003CB98];
      if ( MEMORY[0xFFFFFFFFE003CB98] > 0 )
        return sub_9404B2FC("%s: no fiq active, cpu %d\n", "sm_intc_fiq_exit", v2);
    }
    else
    {
      sub_94023A80(StatusReg | (4 * (BYTE1(StatusReg) & 0xF)), 1u, v3, 0);
      result = 1023;
      *((_DWORD *)qword_9405A158 + v2) = 1023;
    }
  }
  return result;
}

/* ===== sub_94024710 @ 0x94024710 size 268 ===== */
unsigned __int64 __fastcall sub_94024710(unsigned int a1, unsigned int a2, unsigned int a3)
{
  unsigned __int64 v3; // x3
  unsigned __int64 v4; // x3
  unsigned __int64 result; // x0
  unsigned __int64 v6; // x4
  unsigned int v7; // w4
  __int64 v8; // x3

  v3 = a1 * (unsigned __int64)a2 / 0x3E8;
  if ( a1 * (unsigned __int64)a3 > 0xFFFFFFFF )
    v4 = v3
       + ((unsigned __int64)((((unsigned __int64)a1 << 29) * (unsigned __int128)0x20C49BA5E353F7CFuLL) >> 64) >> 4) * a3;
  else
    v4 = v3
       + ((unsigned __int64)((((unsigned __int64)(a1 * a3) << 29) * (unsigned __int128)0x20C49BA5E353F7CFuLL) >> 64) >> 4);
  result = (a1 + 999) / a1;
  v6 = (unsigned int)v4 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A054]
     + HIDWORD(v4) * MEMORY[0xFFFFFFFFE005A058]
     + (((unsigned int)v4 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A050]) << 32)
     + ((HIDWORD(v4) * MEMORY[0xFFFFFFFFE005A054]) << 32)
     + (((unsigned int)v4 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A058]) >> 32);
  v7 = HIDWORD(v6) + ((unsigned int)v6 >> 31);
  if ( a2 != (unsigned __int64)v7 )
  {
    v8 = (int)abs32(v7 - a2);
    if ( result < (int)v8 )
      return sub_9404CB4C("%s:%d: FAIL, off by %llu\n", "test_time_conversion_check_result", 288, v8);
  }
  return result;
}

/* ===== sub_9402481C @ 0x9402481C size 52 ===== */
__int64 sub_9402481C()
{
  sub_94023C34(0, (__int64)sub_94024B48, 0);
  return sub_94023FB4(0);
}

/* ===== sub_94024850 @ 0x94024850 size 184 ===== */
__int64 __fastcall sub_94024850(__int64 result, __int64 a2)
{
  unsigned __int64 v2; // x2
  __int64 v3; // x3
  unsigned __int64 v4; // x5
  unsigned __int64 v5; // x7
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x1
  __int64 v8; // x3
  unsigned __int64 v9; // x2
  unsigned __int64 v10; // x2
  unsigned __int64 v11; // x6
  __int64 v12; // x3
  unsigned __int64 v13; // x3

  v2 = (unsigned int)result * a2;
  v3 = 15625 * a2;
  v4 = HIDWORD(v2) * MEMORY[0xFFFFFFFFE005A040];
  v5 = (unsigned int)v2 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A044];
  v6 = (unsigned int)v2 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A040] + HIDWORD(v2) * MEMORY[0xFFFFFFFFE005A044];
  v7 = HIDWORD(v2) * MEMORY[0xFFFFFFFFE005A048];
  v8 = v3 << 6;
  v9 = (unsigned int)v7
     + (unsigned __int64)(unsigned int)v5
     + (((unsigned int)v2 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A048]) >> 32);
  v10 = ((v9 & 0x80000000) != 0LL) + v6 + (v4 << 32) + HIDWORD(v5) + HIDWORD(v7) + HIDWORD(v9);
  v11 = ((int)result + 999999) / (unsigned int)result;
  if ( v8 != v10 )
  {
    v12 = v10 - v8;
    result = v12 ^ (v12 >> 63);
    v13 = abs64(v12);
    if ( v11 < v13 )
      return sub_9404CB4C("%s:%d: FAIL, off by %llu\n", "test_time_conversion_check_result", 288, v13);
  }
  return result;
}

/* ===== sub_94024908 @ 0x94024908 size 148 ===== */
__int64 __fastcall sub_94024908(unsigned int a1, unsigned int a2)
{
  unsigned __int64 v2; // x3
  unsigned __int64 v3; // x2
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x1
  __int64 result; // x0
  unsigned __int64 v7; // x1
  unsigned __int64 v8; // x3
  __int64 v9; // x3
  __int64 v10; // x3

  v2 = (a2 * (unsigned __int64)a1 + 500) >> 3;
  v3 = a2 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A064];
  v4 = ((a2 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A068]) >> 32) + (unsigned int)v3;
  v5 = HIDWORD(v3) + a2 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A060] + HIDWORD(v4);
  result = (v4 & 0x80000000) != 0LL;
  v7 = result + v5;
  v8 = (unsigned __int64)((v2 * (unsigned __int128)0x20C49BA5E353F7CFuLL) >> 64) >> 4;
  if ( v8 != v7 )
  {
    v9 = v7 - v8;
    result = v9 ^ (v9 >> 63);
    v10 = abs64(v9);
    if ( v10 > 1 )
      return sub_9404CB4C("%s:%d: FAIL, off by %llu\n", "test_time_conversion_check_result", 288, v10);
  }
  return result;
}

/* ===== sub_9402499C @ 0x9402499C size 8 ===== */
unsigned __int64 sub_9402499C()
{
  return _ReadStatusReg(CNTPCT_EL0);
}

/* ===== sub_940249A4 @ 0x940249A4 size 208 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_940249A4(void *a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x30
  unsigned __int64 v4; // x3
  unsigned __int64 v5; // x19
  unsigned __int64 v6; // x19
  __int64 v8; // x0

  v4 = a3 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A064];
  v5 = ((a3 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A068]) >> 32) + (unsigned int)v4;
  v6 = ((v5 & 0x80000000) != 0LL) + HIDWORD(v4) + a3 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A060] + HIDWORD(v5);
  if ( a2 != 0 )
  {
    v8 = sub_9404B508(
           v3,
           "ASSERT FAILED at (%s:%d): %s\n",
           "external/lk/dev/timer/arm_generic/arm_generic_timer.c",
           244,
           "arg == NULL");
    return sub_94024A74(v8);
  }
  else
  {
    off_94066698 = a1;
    if ( v6 > 0x7FFFFFFF )
      _WriteStatusReg(CNTPS_CVAL_EL1, sub_9402499C() + v6);
    else
      _WriteStatusReg(CNTPS_TVAL_EL1, v6);
    __isb(0xFu);
    _WriteStatusReg(CNTPS_CTL_EL1, 1u);
    __isb(0xFu);
    return 0;
  }
}

/* ===== sub_94024A74 @ 0x94024A74 size 16 ===== */
__int64 sub_94024A74()
{
  _WriteStatusReg(CNTPS_CTL_EL1, 0);
  __isb(0xFu);
  return 0;
}

/* ===== sub_94024A84 @ 0x94024A84 size 108 ===== */
unsigned __int64 sub_94024A84()
{
  unsigned __int64 v0; // x0
  unsigned __int64 v1; // x4
  unsigned __int64 v2; // x2
  unsigned __int64 v3; // x1

  v0 = sub_9402499C();
  v1 = (unsigned int)v0 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A044];
  v2 = HIDWORD(v0) * MEMORY[0xFFFFFFFFE005A048];
  v3 = (unsigned int)v2
     + (unsigned __int64)(unsigned int)v1
     + (((unsigned int)v0 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A048]) >> 32);
  return ((v3 & 0x80000000) != 0LL)
       + (unsigned int)v0 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A040]
       + HIDWORD(v0) * MEMORY[0xFFFFFFFFE005A044]
       + ((HIDWORD(v0) * MEMORY[0xFFFFFFFFE005A040]) << 32)
       + HIDWORD(v1)
       + HIDWORD(v2)
       + HIDWORD(v3);
}

/* ===== sub_94024AF0 @ 0x94024AF0 size 88 ===== */
__int64 sub_94024AF0()
{
  unsigned __int64 v0; // x0
  unsigned __int64 v1; // x0

  v0 = sub_9402499C();
  v1 = (unsigned int)v0 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A054]
     + HIDWORD(v0) * MEMORY[0xFFFFFFFFE005A058]
     + (((unsigned int)v0 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A050]) << 32)
     + ((HIDWORD(v0) * MEMORY[0xFFFFFFFFE005A054]) << 32)
     + (((unsigned int)v0 * (unsigned __int64)MEMORY[0xFFFFFFFFE005A058]) >> 32);
  return HIDWORD(v1) + ((unsigned int)v1 >> 31);
}

/* ===== sub_94024B48 @ 0x94024B48 size 84 ===== */
__int64 sub_94024B48()
{
  _WriteStatusReg(CNTPS_CTL_EL1, 0);
  __isb(0xFu);
  return 0;
}

/* ===== sub_94024B9C @ 0x94024B9C size 608 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 *__fastcall sub_94024B9C(unsigned int a1, unsigned int a2)
{
  unsigned int StatusReg; // w19
  unsigned __int64 v4; // x6

  StatusReg = a2;
  if ( a2 == 0 )
  {
    StatusReg = _ReadStatusReg(CNTFRQ_EL0);
    if ( StatusReg == 0 )
      return (__int64 *)sub_9404CB4C(
                          "%s:%d: Failed to initialize timer, frequency is 0\n",
                          "arm_generic_timer_init",
                          368);
  }
  v4 = ((((unsigned __int64)StatusReg << 29) & 0x1FFFFFFFFFFFFFFFLL) * (unsigned __int128)0x20C49BA5E353F7CFuLL) >> 64;
  MEMORY[0xFFFFFFFFE005A060] = v4 >> 36;
  MEMORY[0xFFFFFFFFE005A068] = (unsigned __int64)(((((((unsigned __int64)StatusReg << 32) - 1000 * (v4 >> 4)) << 29)
                                                  & 0x1FFFFFFFFFFFFFFFLL)
                                                 * (unsigned __int128)0x20C49BA5E353F7CFuLL) >> 64) >> 4;
  MEMORY[0xFFFFFFFFE005A064] = v4 >> 4;
  MEMORY[0xFFFFFFFFE005A050] = (0x3E800000000uLL / StatusReg) >> 32;
  MEMORY[0xFFFFFFFFE005A054] = 0x3E800000000uLL / StatusReg;
  MEMORY[0xFFFFFFFFE005A040] = (0xF424000000000uLL / StatusReg) >> 32;
  MEMORY[0xFFFFFFFFE005A044] = 0xF424000000000uLL / StatusReg;
  MEMORY[0xFFFFFFFFE005A058] = ((0x3E800000000uLL % StatusReg) << 32) / StatusReg;
  MEMORY[0xFFFFFFFFE005A048] = ((0xF424000000000uLL % StatusReg) << 32) / StatusReg;
  sub_94024908(StatusReg, 0);
  sub_94024908(StatusReg, 1u);
  sub_94024908(StatusReg, 0x7FFFFFFFu);
  sub_94024908(StatusReg, 0x80000000);
  sub_94024908(StatusReg, 0xFFFFFFFF);
  sub_94024710(StatusReg, 0, 0);
  sub_94024710(StatusReg, 0x7FFFFFFFu, 0);
  sub_94024710(StatusReg, 0x80000000, 0);
  sub_94024710(StatusReg, 0xFFFFFFFF, 0);
  sub_94024710(StatusReg, 0, 1u);
  sub_94024710(StatusReg, 0, 7u);
  sub_94024710(StatusReg, 0, 0x46u);
  sub_94024710(StatusReg, 0, 0x2BCu);
  sub_94024850(StatusReg, 0);
  sub_94024850(StatusReg, 1);
  sub_94024850(StatusReg, 86400);
  sub_94024850(StatusReg, 31536000);
  sub_94024850(StatusReg, 315532800);
  sub_94024850(StatusReg, 3153772800LL);
  sub_94023C34(a1, (__int64)sub_94024B48, 0);
  sub_94023FB4(a1);
  dword_940666A0 = a1;
  return &qword_94065E98[45];
}

/* ===== sub_94024DFC @ 0x94024DFC size 52 ===== */
__int64 __fastcall sub_94024DFC(__int64 result, char a2, int a3)
{
  *(_DWORD *)result = 1702260340;
  *(_BYTE *)(result + 4) = a2;
  *(_DWORD *)(result + 8) = a3;
  *(_DWORD *)(result + 16) = 2002872692;
  *(_QWORD *)(result + 24) = result + 24;
  *(_QWORD *)(result + 32) = result + 24;
  *(_DWORD *)(result + 40) = 0;
  return result;
}

/* ===== sub_94024E30 @ 0x94024E30 size 204 ===== */
unsigned __int64 *__fastcall sub_94024E30(__int64 a1)
{
  __int64 v1; // x30
  unsigned __int64 *result; // x0
  __int64 v10; // x0

  if ( *(_DWORD *)a1 == 1702260340 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    {
      sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      *(_DWORD *)a1 = 0;
      *(_BYTE *)(a1 + 4) = 0;
      *(_DWORD *)(a1 + 8) = 0;
      sub_94027688(a1 + 16, 1);
      return sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    }
    else
    {
      __asm { MSR             DAIFSet, #2 }
      sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      *(_DWORD *)a1 = 0;
      *(_BYTE *)(a1 + 4) = 0;
      *(_DWORD *)(a1 + 8) = 0;
      sub_94027688(a1 + 16, 1);
      result = sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      __asm { MSR             DAIFClr, #2 }
    }
  }
  else
  {
    v10 = sub_9404B508(
            v1,
            "DEBUG ASSERT FAILED at (%s:%d): %s\n",
            "external/lk/kernel/event.c",
            72,
            "e->magic == EVENT_MAGIC");
    return (unsigned __int64 *)sub_94024EFC(v10);
  }
  return result;
}

/* ===== sub_94024EFC @ 0x94024EFC size 224 ===== */
__int64 __fastcall sub_94024EFC(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  int v4; // w22
  __int64 v5; // x1
  unsigned int v6; // w21
  __int64 v14; // x0

  if ( *(_DWORD *)a1 != 1702260340 )
  {
    v14 = sub_9404B508(
            v2,
            "DEBUG ASSERT FAILED at (%s:%d): %s\n",
            "external/lk/kernel/event.c",
            103,
            "e->magic == EVENT_MAGIC");
    return sub_94024FDC(v14);
  }
  v4 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    v5 = a2;
    if ( *(_BYTE *)(a1 + 4) != 0 )
      goto LABEL_4;
  }
  else
  {
    __asm { MSR             DAIFSet, #2 }
    v4 = 1;
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    v5 = a2;
    if ( *(_BYTE *)(a1 + 4) != 0 )
    {
LABEL_4:
      v6 = 0;
      if ( (*(_DWORD *)(a1 + 8) & 1) != 0 )
        *(_BYTE *)(a1 + 4) = 0;
      goto LABEL_6;
    }
  }
  v6 = sub_94026BA8(a1 + 16, v5);
LABEL_6:
  sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
  if ( v4 != 0 )
    __asm { MSR             DAIFClr, #2 }
  return v6;
}

/* ===== sub_94024FDC @ 0x94024FDC size 288 ===== */
__int64 __fastcall sub_94024FDC(__int64 a1, unsigned __int8 a2)
{
  __int64 *v2; // x20
  int v3; // w22
  __int64 v4; // x30
  unsigned int v6; // w21

  v6 = a2;
  if ( *(_DWORD *)a1 == 1702260340 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    {
      v2 = &qword_9405BFF0[2];
      sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      if ( *(_BYTE *)(a1 + 4) != 0 )
      {
        sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
        return 0;
      }
      v3 = 0;
      if ( (*(_DWORD *)(a1 + 8) & 1) != 0 )
        goto LABEL_5;
    }
    else
    {
      __asm { MSR             DAIFSet, #2 }
      v2 = &qword_9405BFF0[2];
      sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      if ( *(_BYTE *)(a1 + 4) != 0 )
      {
        sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
        goto LABEL_7;
      }
      v3 = 1;
      if ( (*(_DWORD *)(a1 + 8) & 1) != 0 )
      {
LABEL_5:
        if ( (int)sub_94026F80(a1 + 16, v6, 0) > 0 )
          goto LABEL_6;
        goto LABEL_13;
      }
    }
    *(_BYTE *)(a1 + 4) = 1;
    sub_94027128(a1 + 16, v6, 0);
    goto LABEL_6;
  }
  sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/event.c", 142, "e->magic == EVENT_MAGIC");
LABEL_13:
  *(_BYTE *)(a1 + 4) = 1;
LABEL_6:
  sub_940223D4((unsigned __int64 *)v2[465]);
  if ( v3 != 0 )
LABEL_7:
    __asm { MSR             DAIFClr, #2 }
  return 0;
}

/* ===== sub_940250FC @ 0x940250FC size 80 ===== */
__int64 __fastcall sub_940250FC(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x0

  if ( *(_DWORD *)a1 == 1702260340 )
  {
    *(_BYTE *)(a1 + 4) = 0;
    return 0;
  }
  else
  {
    v3 = sub_9404B508(
           v1,
           "DEBUG ASSERT FAILED at (%s:%d): %s\n",
           "external/lk/kernel/event.c",
           183,
           "e->magic == EVENT_MAGIC");
    return sub_9402514C(v3);
  }
}

/* ===== sub_9402514C @ 0x9402514C size 120 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 *sub_9402514C()
{
  __int64 v0; // x0
  __int64 v1; // x0

  v0 = MEMORY[0xFFFFFFFFE003CB98];
  if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
    v0 = sub_9404B2FC("initializing mp\n");
  nullsub_3(v0);
  v1 = MEMORY[0xFFFFFFFFE003CB98];
  if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
    v1 = sub_9404B2FC("initializing threads\n");
  sub_94026518(v1);
  if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
    sub_9404B2FC("initializing timers\n");
  qword_94067508 = (__int64)&qword_94067500;
  qword_94067500 = (__int64)&qword_94067500;
  MEMORY[0xFFFFFFFFE005A210] = 0;
  qword_94067528 = (__int64)&qword_94067520;
  qword_94067520 = (__int64)&qword_94067520;
  qword_94067548 = (__int64)&qword_94067540;
  qword_94067540 = (__int64)&qword_94067540;
  qword_94067568 = (__int64)&qword_94067560;
  qword_94067560 = (__int64)&qword_94067560;
  return &qword_94067500;
}

/* ===== sub_940251C4 @ 0x940251C4 size 52 ===== */
__int64 __fastcall sub_940251C4(__int64 result)
{
  *(_DWORD *)result = 1836414072;
  *(_QWORD *)(result + 8) = 0;
  *(_DWORD *)(result + 16) = 0;
  *(_DWORD *)(result + 24) = 2002872692;
  *(_QWORD *)(result + 32) = result + 32;
  *(_QWORD *)(result + 40) = result + 32;
  *(_DWORD *)(result + 48) = 0;
  return result;
}

/* ===== sub_940251F8 @ 0x940251F8 size 276 ===== */
__int64 __fastcall sub_940251F8(__int64 a1, __int64 a2)
{
  __int64 *v2; // x20
  int v3; // w22
  __int64 v4; // x30
  unsigned int v6; // w21
  __int64 v7; // x1
  int v8; // w0

  if ( *(_DWORD *)a1 != 1836414072 )
  {
    sub_9404B508(
      v4,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/mutex.c",
      82,
      "m->magic == MUTEX_MAGIC");
  }
  else if ( *(_QWORD *)(a1 + 8) != _ReadStatusReg(TPIDR_EL1) )
  {
    v3 = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      __asm { MSR             DAIFSet, #2 }
      v3 = 1;
    }
    v2 = &qword_9405BFF0[2];
    v6 = 0;
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    v7 = a2;
    v8 = *(_DWORD *)(a1 + 16) + 1;
    *(_DWORD *)(a1 + 16) = v8;
    if ( v8 <= 1 )
      goto LABEL_6;
LABEL_12:
    v6 = sub_94026BA8(a1 + 24, v7);
    if ( (v6 & 0x80000000) == 0 )
    {
LABEL_6:
      *(_QWORD *)(a1 + 8) = _ReadStatusReg(TPIDR_EL1);
      goto LABEL_7;
    }
    if ( v6 == -13 )
      --*(_DWORD *)(a1 + 16);
LABEL_7:
    sub_940223D4((unsigned __int64 *)v2[465]);
    if ( v3 != 0 )
      __asm { MSR             DAIFClr, #2 }
    return v6;
  }
  sub_9404B508(
    v4,
    "mutex_acquire_timeout: thread %p (%s) tried to acquire mutex %p it already owns.\n",
    _ReadStatusReg(TPIDR_EL1),
    _ReadStatusReg(TPIDR_EL1) + 696,
    a1);
  goto LABEL_12;
}

/* ===== sub_9402530C @ 0x9402530C size 312 ===== */
__int64 __fastcall sub_9402530C(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x30
  unsigned __int64 StatusReg; // x1
  char *v5; // x5
  int v11; // w0
  int v14; // w0
  const void *v15; // x2
  const char *v16; // x3
  const char *v17; // x6

  if ( *(_DWORD *)a1 != 1836414072 )
  {
    sub_9404B508(
      v2,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/mutex.c",
      124,
      "m->magic == MUTEX_MAGIC");
    goto LABEL_11;
  }
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v5 = *(char **)(a1 + 8);
  if ( v5 != (char *)StatusReg )
  {
LABEL_11:
    v15 = (const void *)_ReadStatusReg(TPIDR_EL1);
    v16 = (const char *)(_ReadStatusReg(TPIDR_EL1) + 696);
    if ( v5 != nullptr )
      v17 = v5 + 696;
    else
      v17 = "none";
    sub_9404B508(
      v2,
      "mutex_release: thread %p (%s) tried to release mutex %p it doesn't own. owned by %p (%s)\n",
      v15,
      v16,
      (const void *)a1,
      v5,
      v17);
    goto LABEL_14;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v1 = -536578848;
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    *(_QWORD *)(a1 + 8) = 0;
    v11 = *(_DWORD *)(a1 + 16) - 1;
    *(_DWORD *)(a1 + 16) = v11;
    if ( v11 <= 0 )
    {
LABEL_5:
      sub_940223D4((unsigned __int64 *)v1);
      __asm { MSR             DAIFClr, #2 }
      return 0;
    }
LABEL_14:
    sub_94026F80(a1 + 24, 1, 0);
    goto LABEL_5;
  }
  sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
  *(_QWORD *)(a1 + 8) = 0;
  v14 = *(_DWORD *)(a1 + 16) - 1;
  *(_DWORD *)(a1 + 16) = v14;
  if ( v14 > 0 )
    sub_94026F80(a1 + 24, 1, 0);
  sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
  return 0;
}

/* ===== sub_94025444 @ 0x94025444 size 212 ===== */
int *__fastcall sub_94025444(int a1)
{
  return &dword_940666C0[182 * a1];
}

/* ===== sub_94025518 @ 0x94025518 size 336 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_94025518(__int64 a1)
{
  __int64 v1; // x30
  __int64 v2; // x3
  int v3; // w1
  __int64 v4; // x4
  int v5; // w5
  __int64 *v6; // x2
  __int64 v8; // x0

  v2 = v1;
  if ( *(_DWORD *)a1 != 1953002084 )
  {
    sub_9404B508(v1, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 101, "t->magic == THREAD_MAGIC");
    goto LABEL_10;
  }
  v3 = *(_DWORD *)(a1 + 44);
  if ( v3 != 1 )
  {
LABEL_10:
    sub_9404B508(v1, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 102, "t->state == THREAD_READY");
LABEL_11:
    sub_9404B508(v2, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 104, "arch_ints_disabled()");
    goto LABEL_12;
  }
  v4 = a1 + 24;
  if ( *(_QWORD *)(a1 + 24) == 0 )
    goto LABEL_5;
  do
  {
    a1 = sub_9404B508(
           v2,
           "ASSERT FAILED at (%s:%d): %s\n",
           "external/lk/kernel/thread.c",
           103,
           "!list_in_list(&t->queue_node)");
LABEL_5:
    ;
  }
  while ( *(_QWORD *)(v4 + 8) != 0 );
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    goto LABEL_11;
  if ( MEMORY[0xFFFFFFFFE00474E0] != 0 )
  {
    v5 = *(_DWORD *)(a1 + 40);
    v6 = &qword_940672E0[2 * v5];
    *(_QWORD *)(v4 + 8) = v6[1];
    *(_QWORD *)(a1 + 24) = v6;
    *(_QWORD *)v6[1] = v4;
    v6[1] = v4;
    dword_940666B8 = v3 << v5;
    return 0;
  }
LABEL_12:
  v8 = sub_9404B508(
         v2,
         "ASSERT FAILED at (%s:%d): %s\n",
         "external/lk/kernel/thread.c",
         105,
         "spin_lock_held(&thread_lock)");
  return sub_94025668(v8);
}

/* ===== sub_94025668 @ 0x94025668 size 340 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_94025668(__int64 a1)
{
  __int64 v1; // x30
  __int64 v2; // x3
  int v3; // w1
  __int64 v4; // x4
  int v5; // w5
  __int64 *v6; // x7
  __int64 result; // x0
  __int64 v8; // x0

  v2 = v1;
  if ( *(_DWORD *)a1 != 1953002084 )
  {
    sub_9404B508(v1, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 115, "t->magic == THREAD_MAGIC");
    goto LABEL_10;
  }
  v3 = *(_DWORD *)(a1 + 44);
  if ( v3 != 1 )
  {
LABEL_10:
    sub_9404B508(v1, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 116, "t->state == THREAD_READY");
LABEL_11:
    sub_9404B508(v2, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 118, "arch_ints_disabled()");
    goto LABEL_12;
  }
  v4 = a1 + 24;
  if ( *(_QWORD *)(a1 + 24) == 0 )
    goto LABEL_5;
  do
  {
    a1 = sub_9404B508(
           v2,
           "ASSERT FAILED at (%s:%d): %s\n",
           "external/lk/kernel/thread.c",
           117,
           "!list_in_list(&t->queue_node)");
LABEL_5:
    ;
  }
  while ( *(_QWORD *)(v4 + 8) != 0 );
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    goto LABEL_11;
  if ( MEMORY[0xFFFFFFFFE00474E0] != 0 )
  {
    v5 = *(_DWORD *)(a1 + 40);
    v6 = &qword_940672E0[2 * v5];
    *(_QWORD *)(a1 + 24) = *v6;
    *(_QWORD *)(v4 + 8) = v6;
    result = *v6;
    dword_940666B8 = v3 << v5;
    *(_QWORD *)(result + 8) = v4;
    *v6 = v4;
    return result;
  }
LABEL_12:
  v8 = sub_9404B508(
         v2,
         "ASSERT FAILED at (%s:%d): %s\n",
         "external/lk/kernel/thread.c",
         119,
         "spin_lock_held(&thread_lock)");
  return sub_940257BC(v8);
}

/* ===== sub_940257BC @ 0x940257BC size 340 ===== */
int *sub_940257BC()
{
  __int64 v0; // x30
  __int64 v1; // x19
  int *result; // x0
  int v3; // w2
  int v4; // w3
  int v5; // w4
  __int64 v6; // x0

  v1 = v0;
  result = sub_94025444(-1);
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    sub_9404B508(v1, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 516, "arch_ints_disabled()");
  }
  else if ( MEMORY[0xFFFFFFFFE00474E0] != 0 )
  {
    if ( (MEMORY[0xFFFFFFFFE005A220] & 1) != 0 )
    {
      v3 = 0;
      v4 = 0;
    }
    else
    {
      v3 = 0x7FFFFFFF;
      v4 = -1;
    }
    if ( (MEMORY[0xFFFFFFFFE005A220] & 2) != 0 && v3 > 0 )
    {
      v3 = 0;
      v4 = 1;
    }
    if ( (MEMORY[0xFFFFFFFFE005A220] & 4) != 0 && v3 > 0 )
    {
      v3 = 0;
      v4 = 2;
    }
    if ( (MEMORY[0xFFFFFFFFE005A220] & 8) != 0 && v3 > 0 )
    {
      v3 = 0;
      v4 = 3;
    }
    v5 = result[10];
    if ( v5 > v3 )
    {
      dword_940666A8[v4] = v5;
      return (int *)nullsub_4(1LL << v4, 0);
    }
    return result;
  }
  v6 = sub_9404B508(
         v1,
         "DEBUG ASSERT FAILED at (%s:%d): %s\n",
         "external/lk/kernel/thread.c",
         517,
         "spin_lock_held(&thread_lock)");
  return (int *)sub_94025910(v6);
}

/* ===== sub_94025910 @ 0x94025910 size 864 ===== */
__int64 sub_94025910()
{
  __int64 v0; // x30
  __int64 v1; // x20
  int *StatusReg; // x21
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x19
  unsigned int v5; // w22
  __int64 v6; // x19
  int *v7; // x0
  int *v8; // x19
  bool v9; // zf
  __int64 result; // x0
  int v11; // w2
  __int64 v12; // x1
  int v13; // w0
  int v14; // w0
  unsigned __int64 v15; // x1
  int v16; // w3
  __int64 v17; // x1
  long double v18; // q0
  long double v19; // q1
  long double v20; // q2
  long double v21; // q3
  long double v22; // q4
  long double v23; // q5
  long double v24; // q6
  long double v25; // q7
  unsigned __int64 v26; // x0
  unsigned __int64 v27; // x0
  int v28; // w2

  v1 = v0;
  StatusReg = (int *)_ReadStatusReg(TPIDR_EL1);
  v3 = _ReadStatusReg(MPIDR_EL1);
  if ( (v3 & 0x1000000) != 0 )
    v3 >>= 8;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    sub_9404B508(v0, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 561, "arch_ints_disabled()");
  }
  else if ( MEMORY[0xFFFFFFFFE00474E0] != 0 )
  {
    if ( StatusReg[11] == 2 )
    {
LABEL_32:
      sub_9404B508(
        v0,
        "ASSERT FAILED at (%s:%d): %s\n",
        "external/lk/kernel/thread.c",
        563,
        "current_thread->state != THREAD_RUNNING");
      return sub_9404B508(v1, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 571, "newthread");
    }
    v4 = _ReadStatusReg(MPIDR_EL1);
    if ( (v4 & 0x1000000) != 0 )
      v4 >>= 8;
    v5 = (unsigned __int8)v3 | (4 * ((v3 >> 8) & 0xF));
    v6 = 80 * ((unsigned __int8)v4 | (4 * ((v4 >> 8) & 0xF))) - 536502064;
    ++*(_QWORD *)(v6 + 16);
    v7 = sub_94025444(v5);
    v8 = v7;
    if ( v7 != nullptr )
    {
      v9 = v7 == StatusReg;
      result = 2;
      v8[11] = 2;
      if ( v9 )
        return result;
      if ( v8[12] <= 0 )
        v8[12] = 5;
      StatusReg[14] = -1;
      v8[14] = v5;
      v11 = v8[13];
      v12 = 1LL << v5;
      if ( (v11 & 0x10) != 0 )
      {
        v13 = 1LL << v5;
        MEMORY[0xFFFFFFFFE005A224] |= v12;
        if ( (v11 & 8) == 0 )
          goto LABEL_25;
      }
      else
      {
        v13 = 1LL << v5;
        MEMORY[0xFFFFFFFFE005A224] &= ~(_DWORD)v12;
        if ( (v11 & 8) == 0 )
          goto LABEL_25;
      }
      if ( v8[10] > 16 )
      {
        v14 = v13 | MEMORY[0xFFFFFFFFE005A228];
        goto LABEL_16;
      }
LABEL_25:
      v14 = MEMORY[0xFFFFFFFFE005A228] & ~v13;
LABEL_16:
      MEMORY[0xFFFFFFFFE005A228] = v14;
      v15 = _ReadStatusReg(MPIDR_EL1);
      if ( (v15 & 0x1000000) != 0 )
        v15 >>= 8;
      v16 = StatusReg[13];
      v17 = 80 * ((unsigned __int8)v15 | (4 * ((v15 >> 8) & 0xF))) - 536502064;
      ++*(_QWORD *)(v17 + 24);
      if ( (v16 & 0x10) != 0 )
      {
        v26 = sub_94024A84();
        v11 = v8[13];
        *(_QWORD *)(80LL * v5 - 536502064) = *(_QWORD *)(80LL * v5 - 536502064)
                                           - *(_QWORD *)(80LL * v5 - 536502056)
                                           + v26;
        if ( (v11 & 0x10) == 0 )
        {
LABEL_20:
          if ( (v11 & 0x18) == 0 )
            goto LABEL_21;
          goto LABEL_28;
        }
      }
      else if ( (v11 & 0x10) == 0 )
      {
        goto LABEL_20;
      }
      v27 = sub_94024A84();
      v28 = v8[13];
      *(_QWORD *)(80LL * v5 - 536502056) = v27;
      if ( (v28 & 0x18) == 0 )
      {
LABEL_21:
        if ( (StatusReg[13] & 0x18) != 0 )
          sub_94027F10(&qword_94067220[6 * v5], 10, -536846872, 0);
LABEL_23:
        dword_940666A8[v5] = v8[10];
        _WriteStatusReg(TPIDR_EL1, (unsigned __int64)v8);
        __isb(0xFu);
        v18 = sub_9404D42C(StatusReg, v8);
        return (__int64)sub_94022A20((__int64)StatusReg, v18, v19, v20, v21, v22, v23, v24, v25);
      }
LABEL_28:
      sub_940257BC();
      if ( (StatusReg[13] & 0x18) == 0 )
        sub_94027F9C(&qword_94067220[6 * v5]);
      goto LABEL_23;
    }
    return sub_9404B508(v1, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 571, "newthread");
  }
  sub_9404B508(v0, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 562, "spin_lock_held(&thread_lock)");
  goto LABEL_32;
}

/* ===== sub_94025C70 @ 0x94025C70 size 120 ===== */
__int64 __fastcall sub_94025C70(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x2
  int v3; // w3
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(MPIDR_EL1);
  v3 = *(_DWORD *)(a2 + 60);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  if ( v3 == -1 || v3 == *(_DWORD *)(a1 + 60) || ((unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF))) == v3 )
  {
    v4 = 0;
  }
  else
  {
    v4 = 0;
    if ( *(_DWORD *)(a2 + 40) >= dword_940666A8[v3] )
      v4 = 1LL << v3;
  }
  return nullsub_4(v4, 0);
}

/* ===== sub_94025CE8 @ 0x94025CE8 size 416 ===== */
bool __fastcall sub_94025CE8(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x30
  unsigned __int64 StatusReg; // x19
  int v12; // w0

  if ( *a3 == 1953002084 )
  {
    if ( a3[11] == 4 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      {
        sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
        a3[11] = 1;
        sub_94025518((__int64)a3);
        sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      }
      else
      {
        __asm { MSR             DAIFSet, #2 }
        sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
        a3[11] = 1;
        sub_94025518((__int64)a3);
        sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
        __asm { MSR             DAIFClr, #2 }
      }
      return true;
    }
  }
  else
  {
    sub_9404B508(v3, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 807, "t->magic == THREAD_MAGIC");
  }
  sub_9404B508(v3, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 808, "t->state == THREAD_SLEEPING");
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( (*(_DWORD *)(StatusReg + 52) & 0x10) != 0 )
    return false;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    sub_940257BC();
    sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
  }
  else
  {
    __asm { MSR             DAIFSet, #2 }
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    sub_940257BC();
    sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    __asm { MSR             DAIFClr, #2 }
  }
  if ( (*(_DWORD *)(StatusReg + 52) & 0x18) != 0 )
    return false;
  v12 = *(_DWORD *)(StatusReg + 48) - 1;
  *(_DWORD *)(StatusReg + 48) = v12;
  return v12 <= 0;
}

/* ===== sub_94025E88 @ 0x94025E88 size 264 ===== */
__int64 __fastcall sub_94025E88(_DWORD *a1)
{
  __int64 v1; // x30
  int v3; // w21
  __int64 result; // x0
  unsigned __int64 StatusReg; // x1

  if ( a1 == nullptr )
    return 4294967288LL;
  if ( *a1 != 1953002084 )
  {
    sub_9404B508(v1, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 236, "t->magic == THREAD_MAGIC");
    return 4294967288LL;
  }
  v3 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    if ( a1 != (_DWORD *)_ReadStatusReg(TPIDR_EL1) )
      goto LABEL_5;
LABEL_9:
    StatusReg = _ReadStatusReg(MPIDR_EL1);
    if ( (StatusReg & 0x1000000) != 0 )
      StatusReg >>= 8;
    sub_94027F9C(&qword_94067220[6 * ((unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF)))]);
    goto LABEL_5;
  }
  __asm { MSR             DAIFSet, #2 }
  v3 = 1;
  sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
  if ( a1 == (_DWORD *)_ReadStatusReg(TPIDR_EL1) )
    goto LABEL_9;
LABEL_5:
  a1[13] |= 8u;
  sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
  result = 0;
  if ( v3 != 0 )
    __asm { MSR             DAIFClr, #2 }
  return result;
}

/* ===== sub_94025F90 @ 0x94025F90 size 288 ===== */
unsigned __int64 *sub_94025F90()
{
  __int64 v0; // x30
  _DWORD *StatusReg; // x19
  int v2; // w21
  unsigned __int64 v3; // x0
  int v4; // w3
  __int64 v5; // x1
  unsigned __int64 *result; // x0
  __int64 v13; // x0

  StatusReg = (_DWORD *)_ReadStatusReg(TPIDR_EL1);
  if ( *StatusReg != 1953002084 )
  {
    sub_9404B508(
      v0,
      "ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/thread.c",
      673,
      "current_thread->magic == THREAD_MAGIC");
  }
  else if ( StatusReg[11] == 2 )
  {
    v2 = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      __asm { MSR             DAIFSet, #2 }
      v2 = 1;
    }
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    v3 = _ReadStatusReg(MPIDR_EL1);
    v4 = StatusReg[13];
    if ( (v3 & 0x1000000) != 0 )
      v3 >>= 8;
    v5 = (unsigned __int8)v3 | (4 * ((v3 >> 8) & 0xF));
    ++*(_QWORD *)(80 * v5 - 536502024);
    StatusReg[12] = 0;
    StatusReg[11] = 1;
    if ( (v4 & 0x10) == 0 )
      sub_94025668((__int64)StatusReg);
    sub_94025910();
    result = sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    if ( v2 != 0 )
      __asm { MSR             DAIFClr, #2 }
    return result;
  }
  v13 = sub_9404B508(
          v0,
          "ASSERT FAILED at (%s:%d): %s\n",
          "external/lk/kernel/thread.c",
          674,
          "current_thread->state == THREAD_RUNNING");
  return (unsigned __int64 *)sub_940260B0(v13);
}

/* ===== sub_940260B0 @ 0x940260B0 size 776 ===== */
unsigned __int64 *__fastcall sub_940260B0(_DWORD *a1)
{
  __int64 v1; // x22
  __int64 v2; // x30
  unsigned __int64 v4; // x23
  int v5; // w21
  BOOL v6; // w22
  unsigned __int64 v7; // x3
  unsigned __int64 v8; // x0
  int v9; // w1
  __int64 v10; // x0
  unsigned __int64 *result; // x0
  __int64 v18; // x30
  _DWORD *StatusReg; // x19
  unsigned __int64 v20; // x0
  __int64 v21; // x1
  int v22; // w21
  int v23; // w0

  if ( *a1 != 1953002084 )
  {
    sub_9404B508(v2, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 314, "t->magic == THREAD_MAGIC");
LABEL_21:
    sub_9404B508(v2, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 315, "t->state != THREAD_DEATH");
    StatusReg = (_DWORD *)_ReadStatusReg(TPIDR_EL1);
    if ( *StatusReg == 1953002084 )
    {
      if ( StatusReg[11] == 2 )
      {
        if ( (StatusReg[13] & 0x10) == 0 )
        {
          v20 = _ReadStatusReg(MPIDR_EL1);
          if ( (v20 & 0x1000000) != 0 )
            v20 >>= 8;
          v21 = (unsigned __int8)v20 | (4 * ((v20 >> 8) & 0xF));
          ++*(_QWORD *)(80 * v21 - 536502032);
        }
        if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
        {
          __asm { MSR             DAIFSet, #2 }
          v22 = 1;
          sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
          StatusReg[11] = 1;
          if ( (StatusReg[13] & 0x10) != 0 )
          {
            sub_94025910();
            result = sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
            goto LABEL_32;
          }
LABEL_29:
          if ( (int)StatusReg[12] <= 0 )
            sub_94025668((__int64)StatusReg);
          else
            sub_94025518((__int64)StatusReg);
          sub_94025910();
          result = sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
          if ( v22 == 0 )
            return result;
LABEL_32:
          __asm { MSR             DAIFClr, #2 }
          return result;
        }
        v22 = 0;
        v1 = -536578848;
        sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
        v23 = StatusReg[13];
        StatusReg[11] = 1;
        if ( (v23 & 0x10) == 0 )
          goto LABEL_29;
LABEL_39:
        sub_94025910();
        return sub_940223D4((unsigned __int64 *)v1);
      }
    }
    else
    {
      sub_9404B508(
        v18,
        "ASSERT FAILED at (%s:%d): %s\n",
        "external/lk/kernel/thread.c",
        712,
        "current_thread->magic == THREAD_MAGIC");
    }
    sub_9404B508(
      v18,
      "ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/thread.c",
      713,
      "current_thread->state == THREAD_RUNNING");
    goto LABEL_39;
  }
  if ( a1[11] == 5 )
    goto LABEL_21;
  v4 = _ReadStatusReg(DAIF);
  v5 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v5 = 1;
    v6 = false;
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    if ( a1[11] != 0 )
      goto LABEL_5;
LABEL_18:
    a1[11] = 1;
    v6 = ((v4 ^ 0x80) & 0x80) != 0;
    sub_94025518((__int64)a1);
    goto LABEL_5;
  }
  v6 = false;
  sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
  if ( a1[11] == 0 )
    goto LABEL_18;
LABEL_5:
  v7 = _ReadStatusReg(TPIDR_EL1);
  v8 = _ReadStatusReg(MPIDR_EL1);
  v9 = a1[15];
  if ( (v8 & 0x1000000) != 0 )
    v8 >>= 8;
  if ( v9 == -1 || v9 == *(_DWORD *)(v7 + 60) || ((unsigned __int8)v8 | (4 * ((v8 >> 8) & 0xF))) == v9 )
  {
    v10 = 0;
  }
  else
  {
    v10 = 0;
    if ( a1[10] >= dword_940666A8[v9] )
      v10 = 1LL << v9;
  }
  nullsub_4(v10, 0);
  sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
  if ( v5 != 0 )
    __asm { MSR             DAIFClr, #2 }
  if ( v6 )
    sub_94025F90();
  return nullptr;
}

/* ===== sub_940263B8 @ 0x940263B8 size 352 ===== */
unsigned __int64 *__fastcall sub_940263B8(unsigned int a1)
{
  __int64 v1; // x30
  _DWORD *StatusReg; // x19
  unsigned __int64 *result; // x0
  __int64 v11; // x0
  _BYTE v12[48]; // [xsp+30h] [xbp+30h] BYREF

  StatusReg = (_DWORD *)_ReadStatusReg(TPIDR_EL1);
  if ( *StatusReg != 1953002084 )
  {
    sub_9404B508(
      v1,
      "ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/thread.c",
      838,
      "current_thread->magic == THREAD_MAGIC");
  }
  else if ( StatusReg[11] == 2 )
  {
    if ( (StatusReg[13] & 0x10) != 0 )
    {
LABEL_9:
      v11 = sub_9404B508(
              v1,
              "ASSERT FAILED at (%s:%d): %s\n",
              "external/lk/kernel/thread.c",
              840,
              "!thread_is_idle(current_thread)");
      return (unsigned __int64 *)sub_94026518(v11);
    }
    sub_94027E28(v12);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    {
      sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      sub_94027E84(v12, a1, sub_94025CE8, StatusReg);
      StatusReg[11] = 4;
      sub_94025910();
      return sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    }
    else
    {
      __asm { MSR             DAIFSet, #2 }
      sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      sub_94027E84(v12, a1, sub_94025CE8, StatusReg);
      StatusReg[11] = 4;
      sub_94025910();
      result = sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      __asm { MSR             DAIFClr, #2 }
    }
    return result;
  }
  sub_9404B508(
    v1,
    "ASSERT FAILED at (%s:%d): %s\n",
    "external/lk/kernel/thread.c",
    839,
    "current_thread->state == THREAD_RUNNING");
  goto LABEL_9;
}

/* ===== sub_94026518 @ 0x94026518 size 60 ===== */
__int64 sub_94026518()
{
  sub_94027E28(qword_94067220);
  sub_94027E28(qword_94067250);
  sub_94027E28(qword_94067280);
  return sub_94027E28(qword_940672B0);
}

/* ===== sub_94026554 @ 0x94026554 size 20 ===== */
__int64 __fastcall sub_94026554(__int64 a1)
{
  return sub_9404CF6C(_ReadStatusReg(TPIDR_EL1) + 696, a1, 32);
}

/* ===== sub_94026568 @ 0x94026568 size 264 ===== */
void __noreturn sub_94026568()
{
  __int64 v0; // x30
  _DWORD *StatusReg; // x19
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x1
  unsigned __int64 v4; // x0
  __int64 v10; // x0
  _BYTE v11[16]; // [xsp+20h] [xbp+20h] BYREF

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    StatusReg = (_DWORD *)_ReadStatusReg(TPIDR_EL1);
    v2 = _ReadStatusReg(MPIDR_EL1);
    if ( (v2 & 0x1000000) != 0 )
      v2 >>= 8;
    sub_9404CAC0(v11, 16, "idle %d", (unsigned __int8)v2 | (4 * ((v2 >> 8) & 0xF)));
    sub_94026554((__int64)v11);
    StatusReg[10] = 0;
    StatusReg[13] |= 0x10u;
    v3 = _ReadStatusReg(MPIDR_EL1);
    if ( (v3 & 0x1000000) != 0 )
      v3 >>= 8;
    StatusReg[15] = (unsigned __int8)v3 | (4 * ((v3 >> 8) & 0xF));
    sub_94028428(1);
    v4 = _ReadStatusReg(MPIDR_EL1);
    if ( (v4 & 0x1000000) != 0 )
      v4 >>= 8;
    MEMORY[0xFFFFFFFFE005A224] |= 1LL << ((unsigned __int8)v4 | (unsigned __int8)(4 * (BYTE1(v4) & 0xF)));
    __asm { MSR             DAIFClr, #2 }
    sub_94025F90();
    while ( 1 )
    {
      sub_940224F8();
      sub_940224F8();
    }
  }
  v10 = sub_9404B508(
          v0,
          "DEBUG ASSERT FAILED at (%s:%d): %s\n",
          "external/lk/kernel/thread.c",
          942,
          "arch_ints_disabled()");
  sub_94026670(v10);
}

/* ===== sub_94026670 @ 0x94026670 size 108 ===== */
void __noreturn sub_94026670()
{
  unsigned __int64 StatusReg; // x0
  int v1; // w19

  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  v1 = (unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF));
  *(_DWORD *)(_ReadStatusReg(TPIDR_EL1) + 40) = 0;
  sub_94028428(1);
  MEMORY[0xFFFFFFFFE005A224] |= 1LL << v1;
  __asm { MSR             DAIFClr, #2 }
  sub_94025F90();
  while ( 1 )
  {
    sub_940224F8();
    sub_940224F8();
  }
}

/* ===== sub_940266DC @ 0x940266DC size 32 ===== */
__int64 __fastcall sub_940266DC(__int64 result)
{
  *(_QWORD *)(result + 8) = result + 8;
  *(_DWORD *)result = 2002872692;
  *(_QWORD *)(result + 16) = result + 8;
  *(_DWORD *)(result + 24) = 0;
  return result;
}

/* ===== sub_940266FC @ 0x940266FC size 444 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_940266FC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v8; // x19
  int v11; // w21
  __int64 v12; // x0
  __int64 v20; // x0
  __int64 v21; // [xsp+48h] [xbp+48h]
  __int64 v22; // [xsp+48h] [xbp+48h]
  unsigned int v23; // [xsp+50h] [xbp+50h]
  unsigned int v24; // [xsp+50h] [xbp+50h]
  __int64 v25; // [xsp+58h] [xbp+58h]
  __int64 v26; // [xsp+58h] [xbp+58h]

  v8 = a1;
  v11 = 0;
  if ( a1 == 0 )
  {
    v22 = a6;
    v24 = a5;
    v11 = 4;
    v26 = a4;
    v20 = sub_9404CBC4(728);
    a4 = v26;
    v8 = v20;
    a5 = v24;
    a6 = v22;
    if ( v20 == 0 )
      return 0;
  }
  v21 = a6;
  v23 = a5;
  v25 = a4;
  sub_9404CDC4(v8, 0, 728);
  *(_DWORD *)v8 = 1953002084;
  *(_DWORD *)(v8 + 60) = -1;
  sub_9404CF6C(v8 + 696, a2, 32);
  *(_QWORD *)(v8 + 632) = a3;
  *(_QWORD *)(v8 + 640) = v25;
  *(_QWORD *)(v8 + 40) = v23;
  *(_QWORD *)(v8 + 64) = 0;
  *(_DWORD *)(v8 + 72) = 0;
  *(_DWORD *)(v8 + 56) = -1;
  *(_DWORD *)(v8 + 648) = 0;
  sub_940266DC(v8 + 656);
  if ( v21 == 0 )
  {
    v12 = sub_9404CBC4(a7);
    *(_QWORD *)(v8 + 616) = v12;
    if ( v12 == 0 )
    {
      if ( (v11 & 4) != 0 )
        sub_9404CC20(v8);
      return 0;
    }
    v11 |= 2u;
  }
  *(_QWORD *)(v8 + 624) = a7;
  *(_DWORD *)(v8 + 52) = v11;
  *(_QWORD *)(v8 + 688) = *(_QWORD *)(_ReadStatusReg(TPIDR_EL1) + 688);
  sub_940229C8((_QWORD *)v8);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    *(_QWORD *)(v8 + 16) = 0;
    *(_QWORD *)(v8 + 8) = &qword_940674E8;
    MEMORY[0] = v8 + 8;
    off_940674F0 = (_UNKNOWN *)(v8 + 8);
    sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
  }
  else
  {
    __asm { MSR             DAIFSet, #2 }
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    *(_QWORD *)(v8 + 16) = 0;
    *(_QWORD *)(v8 + 8) = &qword_940674E8;
    MEMORY[0] = v8 + 8;
    off_940674F0 = (_UNKNOWN *)(v8 + 8);
    sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    __asm { MSR             DAIFClr, #2 }
  }
  return v8;
}

/* ===== sub_940268B8 @ 0x940268B8 size 48 ===== */
__int64 __fastcall sub_940268B8(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, __int64 a5)
{
  return sub_940266FC(0, a1, a2, a3, a4, 0, a5);
}

/* ===== sub_940268E8 @ 0x940268E8 size 300 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 *sub_940268E8()
{
  __int64 v0; // x30
  unsigned __int64 StatusReg; // x1
  __int64 *v2; // x0
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2

  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  if ( ((unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF))) != 0 )
  {
    v4 = sub_9404B508(
           v0,
           "DEBUG ASSERT FAILED at (%s:%d): %s\n",
           "external/lk/kernel/thread.c",
           861,
           "arch_curr_cpu_num() == 0");
    return (__int64 *)sub_94026A14(v4, v5, v6);
  }
  else
  {
    v2 = qword_940672E0;
    do
    {
      v2[1] = (__int64)v2;
      *v2 = (__int64)v2;
      v2 += 2;
    }
    while ( v2 != &qword_940674E0 );
    qword_940674E8 = (__int64)&qword_940674E8;
    off_940674F0 = &qword_940674E8;
    sub_9404CDC4(dword_940666C0, 0, 728);
    dword_940666C0[0] = 1953002084;
    dword_940666FC = -1;
    sub_9404CF6C(&qword_94066700[79], "bootstrap", 32);
    dword_940666F8 = 0;
    dword_940666E8 = 31;
    dword_940666EC = 2;
    dword_940666FC = 0;
    dword_940666F4 = 1;
    sub_940266DC((__int64)&qword_94066700[74]);
    qword_940666D0 = 0;
    qword_940666C8 = (__int64)&qword_940674E8;
    MEMORY[0] = &qword_940666C8;
    off_940674F0 = &qword_940666C8;
    dword_940666A8[0] = 0;
    _WriteStatusReg(TPIDR_EL1, (unsigned __int64)dword_940666C0);
    __isb(0xFu);
    return &qword_94065E98[45];
  }
}

/* ===== sub_94026A14 @ 0x94026A14 size 404 ===== */
// write access to const memory has been detected, the output may be wrong!
unsigned __int64 *sub_94026A14()
{
  __int64 v0; // x30
  unsigned __int64 StatusReg; // x0
  __int64 v2; // x20
  int *v3; // x23
  int v4; // w24
  int *v5; // x1
  unsigned __int64 *result; // x0
  __int64 v13; // x0
  __int64 v14; // x1
  _BYTE v15[16]; // [xsp+60h] [xbp+60h] BYREF

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    StatusReg = _ReadStatusReg(MPIDR_EL1);
    if ( (StatusReg & 0x1000000) != 0 )
      StatusReg >>= 8;
    v2 = (unsigned __int8)StatusReg | (4 * ((unsigned int)(StatusReg >> 8) & 0xF));
    v3 = &dword_940666C0[182 * v2];
    sub_9404CAC0(v15, 16, "idle %d", (unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF)));
    sub_9404CDC4(v3, 0, 728);
    *v3 = 1953002084;
    v3[15] = -1;
    sub_9404CF6C(v3 + 174, v15, 32);
    v3[15] = v2;
    v3[10] = 31;
    v3[13] = 17;
    v3[11] = 2;
    v3[14] = v2;
    sub_940266DC((__int64)&dword_940666C0[182 * v2 + 164]);
    v4 = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      __asm { MSR             DAIFSet, #2 }
      v4 = 1;
    }
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    v5 = &dword_940666C0[182 * v2];
    *((_QWORD *)v5 + 1) = &qword_940674E8;
    *((_QWORD *)v5 + 2) = 0;
    MEMORY[0] = v5 + 2;
    off_940674F0 = v5 + 2;
    dword_940666A8[(unsigned int)v2] = v5[10];
    _WriteStatusReg(TPIDR_EL1, (unsigned __int64)v3);
    __isb(0xFu);
    result = sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    if ( v4 != 0 )
      __asm { MSR             DAIFClr, #2 }
  }
  else
  {
    v13 = sub_9404B508(
            v0,
            "DEBUG ASSERT FAILED at (%s:%d): %s\n",
            "external/lk/kernel/thread.c",
            969,
            "arch_ints_disabled()");
    return (unsigned __int64 *)sub_94026BA8(v13, v14);
  }
  return result;
}

/* ===== sub_94026BA8 @ 0x94026BA8 size 372 ===== */
__int64 __fastcall sub_94026BA8(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  unsigned __int64 StatusReg; // x19
  int v4; // w2
  __int64 v5; // x4
  _BYTE v8[48]; // [xsp+30h] [xbp+30h] BYREF

  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_DWORD *)a1 != 2002872692 )
  {
    sub_9404B508(
      v2,
      "ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/thread.c",
      1166,
      "wait->magic == WAIT_QUEUE_MAGIC");
  }
  else if ( *(_DWORD *)(StatusReg + 44) == 2 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
LABEL_13:
      sub_9404B508(v2, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 1168, "arch_ints_disabled()");
    }
    else if ( MEMORY[0xFFFFFFFFE00474E0] != 0 )
    {
      if ( (_DWORD)a2 == 0 )
        return 4294967283LL;
      *(_QWORD *)(StatusReg + 24) = *(_QWORD *)(a1 + 8);
      v4 = *(_DWORD *)(a1 + 24);
      v5 = *(_QWORD *)(a1 + 8);
      *(_QWORD *)(StatusReg + 32) = a1 + 8;
      *(_QWORD *)(v5 + 8) = StatusReg + 24;
      *(_DWORD *)(a1 + 24) = v4 + 1;
      *(_QWORD *)(a1 + 8) = StatusReg + 24;
      *(_DWORD *)(StatusReg + 44) = 3;
      *(_QWORD *)(StatusReg + 64) = a1;
      *(_DWORD *)(StatusReg + 72) = 0;
      if ( (_DWORD)a2 == -1 )
      {
        sub_94025910();
      }
      else
      {
        sub_94027E28(v8);
        sub_94027E84(v8, a2, &loc_94027950, StatusReg);
        sub_94025910();
        sub_94027F9C(v8);
      }
      return *(unsigned int *)(StatusReg + 72);
    }
    sub_9404B508(
      v2,
      "ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/thread.c",
      1169,
      "spin_lock_held(&thread_lock)");
    return 4294967283LL;
  }
  sub_9404B508(
    v2,
    "ASSERT FAILED at (%s:%d): %s\n",
    "external/lk/kernel/thread.c",
    1167,
    "current_thread->state == THREAD_RUNNING");
  goto LABEL_13;
}

/* ===== sub_94026D1C @ 0x94026D1C size 612 ===== */
__int64 __fastcall sub_94026D1C(__int64 a1, _DWORD *a2, unsigned int a3)
{
  int v3; // w23
  __int64 *v4; // x24
  __int64 v5; // x30
  __int64 v7; // x21
  unsigned int v9; // w20
  unsigned int v10; // w2
  _QWORD *v16; // x1
  int v18; // w1
  __int64 v19; // x0
  unsigned int v23; // [xsp+48h] [xbp+48h]

  v7 = v5;
  if ( *(_DWORD *)a1 != 1953002084 )
    goto LABEL_15;
  v23 = a3;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    goto LABEL_11;
  v4 = &qword_9405BFF0[2];
  v9 = -536578848;
  sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
  if ( (*(_DWORD *)(a1 + 52) & 1) != 0 )
  {
    v9 = -34;
    sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    return v9;
  }
  v3 = 0;
  v10 = v23;
  if ( *(_DWORD *)(a1 + 44) == 5 )
    goto LABEL_13;
  while ( 1 )
  {
    v9 = sub_94026BA8(a1 + 656, v10);
    if ( (v9 & 0x80000000) != 0 )
      goto LABEL_29;
    if ( *(_DWORD *)a1 == 1953002084 )
      break;
LABEL_14:
    sub_9404B508(v7, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 371, "t->magic == THREAD_MAGIC");
LABEL_15:
    sub_9404B508(v5, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 350, "t->magic == THREAD_MAGIC");
LABEL_16:
    if ( *(_QWORD *)(a1 + 32) == 0 )
    {
      if ( a2 != nullptr )
        *a2 = *(_DWORD *)(a1 + 648);
      v16 = *(_QWORD **)(a1 + 16);
      *v16 = *(_QWORD *)(a1 + 8);
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL) = v16;
      *(_QWORD *)(a1 + 16) = 0;
      *(_QWORD *)(a1 + 8) = 0;
      *(_DWORD *)a1 = 0;
      sub_940223D4((unsigned __int64 *)v4[465]);
      if ( v3 != 0 )
        __asm { MSR             DAIFClr, #2 }
      v18 = *(_DWORD *)(a1 + 52);
      if ( (v18 & 2) != 0 )
      {
        v19 = *(_QWORD *)(a1 + 616);
        if ( v19 != 0 )
        {
          sub_9404CC20(v19);
          v18 = *(_DWORD *)(a1 + 52);
        }
      }
      v9 = 0;
      if ( (v18 & 4) != 0 )
        sub_9404CC20(a1);
      return v9;
    }
    while ( 1 )
    {
      sub_9404B508(
        v7,
        "ASSERT FAILED at (%s:%d): %s\n",
        "external/lk/kernel/thread.c",
        374,
        "!list_in_list(&t->queue_node)");
LABEL_11:
      __asm { MSR             DAIFSet, #2 }
      v4 = &qword_9405BFF0[2];
      v9 = -536578848;
      sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      if ( (*(_DWORD *)(a1 + 52) & 1) != 0 )
      {
        sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
        __asm { MSR             DAIFClr, #2 }
        return (unsigned int)-34;
      }
      v3 = 1;
      v10 = v23;
      if ( *(_DWORD *)(a1 + 44) != 5 )
        break;
LABEL_13:
      if ( *(_DWORD *)a1 != 1953002084 )
        goto LABEL_14;
LABEL_8:
      if ( *(_QWORD *)(a1 + 64) != 0 )
        goto LABEL_28;
      if ( *(_QWORD *)(a1 + 24) == 0 )
        goto LABEL_16;
    }
  }
  if ( *(_DWORD *)(a1 + 44) == 5 )
    goto LABEL_8;
  sub_9404B508(v7, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 372, "t->state == THREAD_DEATH");
LABEL_28:
  sub_9404B508(
    v7,
    "ASSERT FAILED at (%s:%d): %s\n",
    "external/lk/kernel/thread.c",
    373,
    "t->blocking_wait_queue == NULL");
LABEL_29:
  sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
  if ( v3 != 0 )
    __asm { MSR             DAIFClr, #2 }
  return v9;
}

/* ===== sub_94026F80 @ 0x94026F80 size 424 ===== */
__int64 __fastcall sub_94026F80(__int64 a1, char a2, int a3)
{
  __int64 v3; // x30
  __int64 StatusReg; // x21
  __int64 v5; // x3
  _QWORD *v6; // x4
  __int64 v7; // x19
  int v8; // w4
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2

  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_DWORD *)a1 != 2002872692 )
  {
    sub_9404B508(
      v3,
      "ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/thread.c",
      1219,
      "wait->magic == WAIT_QUEUE_MAGIC");
  }
  else if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    if ( MEMORY[0xFFFFFFFFE00474E0] == 0 )
    {
LABEL_14:
      sub_9404B508(
        v3,
        "ASSERT FAILED at (%s:%d): %s\n",
        "external/lk/kernel/thread.c",
        1221,
        "spin_lock_held(&thread_lock)");
LABEL_15:
      v10 = sub_9404B508(
              v3,
              "ASSERT FAILED at (%s:%d): %s\n",
              "external/lk/kernel/thread.c",
              1228,
              "t->state == THREAD_BLOCKED");
      return sub_94027128(v10, v11, v12);
    }
    v5 = *(_QWORD *)(a1 + 16);
    if ( v5 == a1 + 8 )
      return 0;
    v6 = *(_QWORD **)(v5 + 8);
    *v6 = *(_QWORD *)v5;
    *(_QWORD *)(*(_QWORD *)v5 + 8LL) = v6;
    *(_QWORD *)(v5 + 8) = 0;
    *(_QWORD *)v5 = 0;
    v7 = v5 - 24;
    if ( v5 == 24 )
      return 0;
    v8 = *(_DWORD *)(v5 + 20);
    --*(_DWORD *)(a1 + 24);
    if ( v8 != 3 )
      goto LABEL_15;
    *(_DWORD *)(v5 + 48) = a3;
    *(_DWORD *)(v5 + 20) = 1;
    *(_QWORD *)(v5 + 40) = 0;
    if ( a2 != 0 )
    {
      *(_DWORD *)(StatusReg + 44) = 1;
      sub_94025518(StatusReg);
      sub_94025518(v7);
      sub_94025C70(StatusReg, v7);
      sub_94025910();
    }
    else
    {
      sub_94025518(v7);
      sub_94025C70(StatusReg, v7);
    }
    return 1;
  }
  sub_9404B508(v3, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 1220, "arch_ints_disabled()");
  goto LABEL_14;
}

/* ===== sub_94027128 @ 0x94027128 size 724 ===== */
__int64 __fastcall sub_94027128(__int64 a1, unsigned __int8 a2, int a3)
{
  __int64 v3; // x30
  __int64 StatusReg; // x22
  int v7; // w1
  __int64 v8; // x28
  __int64 v9; // x0
  _QWORD *v10; // x2
  __int64 v11; // x19
  int v12; // w0
  unsigned int v13; // w25
  unsigned int v14; // w26
  __int64 v15; // x2
  __int64 v16; // x0
  _QWORD *v17; // x1
  int v18; // w1
  unsigned __int64 v19; // x0
  int v20; // w1
  __int64 v22; // x0
  __int64 v23; // [xsp+60h] [xbp+60h]
  int v24; // [xsp+6Ch] [xbp+6Ch]

  v24 = a2;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_DWORD *)a1 != 2002872692 )
  {
    sub_9404B508(
      v3,
      "ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/thread.c",
      1278,
      "wait->magic == WAIT_QUEUE_MAGIC");
  }
  else if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    if ( MEMORY[0xFFFFFFFFE00474E0] == 0 )
    {
LABEL_31:
      sub_9404B508(
        v23,
        "ASSERT FAILED at (%s:%d): %s\n",
        "external/lk/kernel/thread.c",
        1280,
        "spin_lock_held(&thread_lock)");
      goto LABEL_32;
    }
    v7 = *(_DWORD *)(a1 + 24);
    if ( v24 != 0 && v7 > 0 )
    {
      *(_DWORD *)(StatusReg + 44) = 1;
      v8 = a1 + 8;
      sub_94025518(StatusReg);
      v9 = *(_QWORD *)(a1 + 16);
      v7 = *(_DWORD *)(a1 + 24);
      if ( a1 + 8 == v9 )
      {
LABEL_25:
        if ( v7 == 0 )
          return 0;
        goto LABEL_32;
      }
    }
    else
    {
      v8 = a1 + 8;
      v9 = *(_QWORD *)(a1 + 16);
      if ( a1 + 8 == v9 )
        goto LABEL_25;
    }
    v10 = *(_QWORD **)(v9 + 8);
    *v10 = *(_QWORD *)v9;
    *(_QWORD *)(*(_QWORD *)v9 + 8LL) = v10;
    *(_QWORD *)(v9 + 8) = 0;
    *(_QWORD *)v9 = 0;
    v11 = v9 - 24;
    if ( v9 == 24 )
      goto LABEL_25;
    v12 = *(_DWORD *)(v9 + 20);
    *(_DWORD *)(a1 + 24) = v7 - 1;
    v13 = 0;
    v14 = 0;
    if ( v12 != 3 )
    {
LABEL_27:
      sub_9404B508(
        v23,
        "ASSERT FAILED at (%s:%d): %s\n",
        "external/lk/kernel/thread.c",
        1296,
        "t->state == THREAD_BLOCKED");
      goto LABEL_28;
    }
    while ( 1 )
    {
      *(_DWORD *)(v11 + 44) = 1;
      *(_DWORD *)(v11 + 72) = a3;
      *(_QWORD *)(v11 + 64) = 0;
      sub_94025518(v11);
      v19 = _ReadStatusReg(MPIDR_EL1);
      v20 = *(_DWORD *)(v11 + 60);
      if ( (v19 & 0x1000000) != 0 )
        v19 >>= 8;
      if ( v20 != -1 && v20 != *(_DWORD *)(StatusReg + 60) && ((unsigned __int8)v19 | (4 * ((v19 >> 8) & 0xF))) != v20 )
        break;
      v16 = *(_QWORD *)(v8 + 8);
      ++v14;
      if ( v8 == v16 )
        goto LABEL_20;
LABEL_14:
      v17 = *(_QWORD **)(v16 + 8);
      *v17 = *(_QWORD *)v16;
      *(_QWORD *)(*(_QWORD *)v16 + 8LL) = v17;
      *(_QWORD *)(v16 + 8) = 0;
      *(_QWORD *)v16 = 0;
      v11 = v16 - 24;
      if ( v16 == 24 )
        goto LABEL_20;
      v18 = *(_DWORD *)(v16 + 20);
      --*(_DWORD *)(a1 + 24);
      if ( v18 != 3 )
        goto LABEL_27;
    }
    LODWORD(v15) = 0;
    ++v14;
    v16 = *(_QWORD *)(v8 + 8);
    if ( *(_DWORD *)(v11 + 40) >= dword_940666A8[v20] )
      v15 = 1LL << v20;
    v13 |= v15;
    if ( v8 != v16 )
      goto LABEL_14;
LABEL_20:
    if ( *(_DWORD *)(a1 + 24) != 0 )
    {
LABEL_32:
      v22 = sub_9404B508(v23, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 1308, "wait->count == 0");
      return sub_940273FC(v22);
    }
    nullsub_4(v13, 0);
    if ( v24 == 0 )
      return v14;
LABEL_28:
    sub_94025910();
    return v14;
  }
  sub_9404B508(v23, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 1279, "arch_ints_disabled()");
  goto LABEL_31;
}

/* ===== sub_940273FC @ 0x940273FC size 320 ===== */
__int64 __fastcall sub_940273FC(_DWORD *a1)
{
  __int64 v1; // x20
  __int64 v2; // x30

  if ( *a1 == 1953002084 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      __asm { MSR             DAIFSet, #2 }
      sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      sub_94027128((__int64)(a1 + 164), 0, -34);
      if ( a1[11] != 5 )
      {
        a1[13] |= 1u;
        sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
        __asm { MSR             DAIFClr, #2 }
        return 0;
      }
      a1[13] &= ~1u;
      sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      __asm { MSR             DAIFClr, #2 }
      return sub_94026D1C((__int64)a1, nullptr, 0);
    }
    v1 = -536578848;
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    sub_94027128((__int64)(a1 + 164), 0, -34);
    if ( a1[11] != 5 )
    {
      a1[13] |= 1u;
      sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      return 0;
    }
  }
  else
  {
    sub_9404B508(v2, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 402, "t->magic == THREAD_MAGIC");
  }
  a1[13] &= ~1u;
  sub_940223D4((unsigned __int64 *)v1);
  return sub_94026D1C((__int64)a1, nullptr, 0);
}

/* ===== sub_9402753C @ 0x9402753C size 332 ===== */
__int64 __fastcall sub_9402753C(int a1)
{
  __int64 v1; // x30
  unsigned __int64 StatusReg; // x19
  int v4; // w1
  _QWORD *v5; // x2
  __int64 v6; // x30
  __int64 v12; // x0
  __int64 v13; // x1

  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_DWORD *)StatusReg != 1953002084 )
  {
    sub_9404B508(
      v1,
      "ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/thread.c",
      435,
      "current_thread->magic == THREAD_MAGIC");
  }
  else if ( *(_DWORD *)(StatusReg + 44) == 2 )
  {
    if ( (*(_DWORD *)(StatusReg + 52) & 0x10) == 0 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
        __asm { MSR             DAIFSet, #2 }
      sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      *(_DWORD *)(StatusReg + 648) = a1;
      v4 = *(_DWORD *)(StatusReg + 52);
      *(_DWORD *)(StatusReg + 44) = 5;
      if ( (v4 & 1) == 0 )
        goto LABEL_13;
      v5 = *(_QWORD **)(StatusReg + 16);
      *v5 = *(_QWORD *)(StatusReg + 8);
      *(_QWORD *)(*(_QWORD *)(StatusReg + 8) + 8LL) = v5;
      *(_QWORD *)(StatusReg + 16) = 0;
      *(_QWORD *)(StatusReg + 8) = 0;
      *(_DWORD *)StatusReg = 0;
      if ( (v4 & 2) != 0 && *(_QWORD *)(StatusReg + 616) != 0 )
      {
        ((void (*)(void))sub_9404BC3C)();
        v4 = *(_DWORD *)(StatusReg + 52);
      }
      if ( (v4 & 4) != 0 )
        sub_9404BC3C(StatusReg);
      while ( 1 )
      {
        sub_94025910();
        sub_9404B508(v6, "somehow fell through thread_exit()\n");
LABEL_13:
        sub_94027128(StatusReg + 656, 0, 0);
      }
    }
LABEL_16:
    v12 = sub_9404B508(
            v1,
            "ASSERT FAILED at (%s:%d): %s\n",
            "external/lk/kernel/thread.c",
            437,
            "!thread_is_idle(current_thread)");
    return sub_94027688(v12, v13);
  }
  sub_9404B508(
    v1,
    "ASSERT FAILED at (%s:%d): %s\n",
    "external/lk/kernel/thread.c",
    436,
    "current_thread->state == THREAD_RUNNING");
  goto LABEL_16;
}

/* ===== sub_94027688 @ 0x94027688 size 196 ===== */
__int64 __fastcall sub_94027688(_DWORD *a1, unsigned __int8 a2)
{
  __int64 v2; // x30
  __int64 result; // x0
  __int64 v5; // x0

  if ( *a1 != 2002872692 )
  {
    sub_9404B508(
      v2,
      "ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/thread.c",
      1329,
      "wait->magic == WAIT_QUEUE_MAGIC");
  }
  else if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    if ( MEMORY[0xFFFFFFFFE00474E0] != 0 )
    {
      result = sub_94027128((__int64)a1, a2, -11);
      *a1 = 0;
      return result;
    }
LABEL_7:
    v5 = sub_9404B508(
           v2,
           "ASSERT FAILED at (%s:%d): %s\n",
           "external/lk/kernel/thread.c",
           1331,
           "spin_lock_held(&thread_lock)");
    return sub_9402774C(v5);
  }
  sub_9404B508(v2, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 1330, "arch_ints_disabled()");
  goto LABEL_7;
}

/* ===== sub_9402774C @ 0x9402774C size 652 ===== */
__int64 __fastcall sub_9402774C(__int64 a1, int a2)
{
  __int64 v2; // x30
  __int64 v4; // x0
  _DWORD *v5; // x2
  __int64 v6; // x3
  _QWORD *v7; // x4
  int v8; // w3
  unsigned __int64 StatusReg; // x3
  unsigned __int64 v10; // x0
  int v11; // w1
  __int64 v12; // x0
  _DWORD *v14; // x2
  __int64 v15; // x30
  int v16; // w20
  __int64 v17; // x0
  _DWORD *v18; // [xsp+28h] [xbp-8h]

  v4 = v2;
  if ( *(_DWORD *)a1 != 1953002084 )
    goto LABEL_20;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
LABEL_21:
    v4 = sub_9404B508(v4, "ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/thread.c", 1353, "arch_ints_disabled()");
  }
  else if ( MEMORY[0xFFFFFFFFE00474E0] != 0 )
  {
    if ( *(_DWORD *)(a1 + 44) != 3 )
      return 4294967284LL;
    v5 = *(_DWORD **)(a1 + 64);
    if ( v5 == nullptr )
    {
      v4 = sub_9404B508(
             v2,
             "ASSERT FAILED at (%s:%d): %s\n",
             "external/lk/kernel/thread.c",
             1361,
             "t->blocking_wait_queue != NULL");
LABEL_25:
      sub_9404B508(
        v4,
        "ASSERT FAILED at (%s:%d): %s\n",
        "external/lk/kernel/thread.c",
        1362,
        "t->blocking_wait_queue->magic == WAIT_QUEUE_MAGIC");
      if ( *v14 == 1953002084 )
      {
        v18 = v14;
        sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
        v16 = sub_9402774C(v18);
        sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
        return v16 >= 0;
      }
      else
      {
        v17 = sub_9404B508(
                v15,
                "ASSERT FAILED at (%s:%d): %s\n",
                "external/lk/kernel/thread.c",
                1126,
                "thread->magic == THREAD_MAGIC");
        return sub_940279D8(v17);
      }
    }
    if ( *v5 != 2002872692 )
      goto LABEL_25;
    v6 = *(_QWORD *)(a1 + 24);
    v7 = *(_QWORD **)(a1 + 32);
    if ( v6 == 0 && v7 == nullptr )
    {
      v4 = sub_9404B508(
             v2,
             "ASSERT FAILED at (%s:%d): %s\n",
             "external/lk/kernel/thread.c",
             1363,
             "list_in_list(&t->queue_node)");
LABEL_20:
      v4 = sub_9404B508(
             v4,
             "ASSERT FAILED at (%s:%d): %s\n",
             "external/lk/kernel/thread.c",
             1352,
             "t->magic == THREAD_MAGIC");
      goto LABEL_21;
    }
    *v7 = v6;
    v8 = v5[6] - 1;
    *(_QWORD *)(*(_QWORD *)(a1 + 24) + 8LL) = v7;
    *(_QWORD *)(a1 + 32) = 0;
    *(_QWORD *)(a1 + 24) = 0;
    v5[6] = v8;
    *(_QWORD *)(a1 + 64) = 0;
    *(_DWORD *)(a1 + 44) = 1;
    *(_DWORD *)(a1 + 72) = a2;
    sub_94025518(a1);
    StatusReg = _ReadStatusReg(TPIDR_EL1);
    v10 = _ReadStatusReg(MPIDR_EL1);
    v11 = *(_DWORD *)(a1 + 60);
    if ( (v10 & 0x1000000) != 0 )
      v10 >>= 8;
    if ( v11 == -1 || v11 == *(_DWORD *)(StatusReg + 60) || ((unsigned __int8)v10 | (4 * ((v10 >> 8) & 0xF))) == v11 )
    {
      v12 = 0;
    }
    else
    {
      v12 = 0;
      if ( *(_DWORD *)(a1 + 40) >= dword_940666A8[v11] )
        v12 = 1LL << v11;
    }
    nullsub_4(v12, 0);
    return 0;
  }
  sub_9404B508(
    v4,
    "ASSERT FAILED at (%s:%d): %s\n",
    "external/lk/kernel/thread.c",
    1354,
    "spin_lock_held(&thread_lock)");
  return 4294967284LL;
}

/* ===== sub_940279D8 @ 0x940279D8 size 228 ===== */
__int64 __fastcall sub_940279D8(unsigned int a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 *v3; // x5
  __int64 v4; // x4
  __int64 v5; // x2
  int v6; // w6
  __int64 result; // x0
  __int64 v8; // x1
  __int64 v9; // x0

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    v3 = &qword_94067500[4 * a1];
    v4 = v3[1];
    v5 = v4 - 8;
    if ( (__int64 *)v4 != v3 )
    {
      v6 = *(_DWORD *)(a2 + 24);
      if ( *(_DWORD *)(v4 + 16) - v6 > 0 )
      {
LABEL_8:
        result = a2 + 8;
        *(_QWORD *)(a2 + 8) = *(_QWORD *)(v5 + 8);
        v8 = *(_QWORD *)(v5 + 8);
        *(_QWORD *)(result + 8) = v4;
        *(_QWORD *)(v8 + 8) = result;
        *(_QWORD *)(v5 + 8) = result;
        return result;
      }
      while ( 1 )
      {
        v4 = *(_QWORD *)(v5 + 16);
        v5 = v4 - 8;
        if ( (__int64 *)v4 == v3 )
          break;
        if ( *(_DWORD *)(v4 + 16) - v6 > 0 )
          goto LABEL_8;
      }
    }
    result = 32LL * a1;
    *(_QWORD *)(a2 + 8) = *(__int64 *)((char *)qword_94067500 + result);
    *(_QWORD *)(a2 + 16) = v3;
    *(_QWORD *)(*(__int64 *)((char *)qword_94067500 + result) + 8) = a2 + 8;
    *(__int64 *)((char *)qword_94067500 + result) = a2 + 8;
    return result;
  }
  v9 = sub_9404B508(
         v2,
         "DEBUG ASSERT FAILED at (%s:%d): %s\n",
         "external/lk/kernel/timer.c",
         82,
         "arch_ints_disabled()");
  return sub_94027ABC(v9);
}

/* ===== sub_94027ABC @ 0x94027ABC size 876 ===== */
unsigned __int64 *__fastcall sub_94027ABC(__int64 a1, unsigned int a2)
{
  __int64 *v2; // x19
  __int64 *v3; // x21
  unsigned int v4; // w22
  __int64 *v5; // x23
  unsigned int v6; // w24
  __int64 *v7; // x25
  __int64 *v8; // x26
  __int64 v9; // x28
  __int64 v10; // x30
  __int64 v11; // x20
  unsigned __int64 StatusReg; // x1
  __int64 v14; // x0
  unsigned __int64 v15; // x1
  unsigned __int64 *result; // x0
  int v17; // w2
  signed int v18; // w2
  __int64 *v19; // x0
  unsigned __int64 v20; // x4
  unsigned int (__fastcall *v21)(__int64, _QWORD, __int64); // x7
  __int64 v22; // x2
  __int64 v23; // x3
  int v24; // w0
  __int64 v25; // x20
  int v26; // w2
  unsigned int v27; // w1
  unsigned int v28; // w22
  __int64 v29; // x3
  __int64 v30; // x4
  int v31; // w0
  int v32; // w21
  unsigned __int64 v38; // x19
  unsigned int v39; // w19
  __int64 *v40; // x19
  __int64 *v41; // x0
  int v43; // [xsp+48h] [xbp-18h]
  __int64 v44; // [xsp+50h] [xbp-10h]
  __int64 v45; // [xsp+58h] [xbp-8h]
  unsigned __int64 *v46; // [xsp+C0h] [xbp+60h]
  int v47; // [xsp+C8h] [xbp+68h]

  v11 = v10;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    sub_9404B508(v10, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/timer.c", 231, "arch_ints_disabled()");
    goto LABEL_12;
  }
  StatusReg = _ReadStatusReg(MPIDR_EL1);
  v2 = &qword_9405BFF0[2];
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  v14 = 80 * ((unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF))) - 536502064;
  ++*(_QWORD *)(v14 + 56);
  v15 = _ReadStatusReg(MPIDR_EL1);
  v5 = &qword_9405BFF0[2];
  if ( (v15 & 0x1000000) != 0 )
    v15 >>= 8;
  v4 = (unsigned __int8)v15 | (4 * ((v15 >> 8) & 0xF));
  v6 = 0;
  sub_940223B4((unsigned __int64 *)0xFFFFFFFFE005A210LL);
  v3 = &qword_94067500[4 * (unsigned __int8)v4];
  v7 = v3;
  while ( 1 )
  {
    v8 = (__int64 *)v7[1];
    if ( v8 == v3 )
      goto LABEL_10;
    if ( v8 == nullptr )
      goto LABEL_10;
    v9 = (__int64)(v8 - 1);
    if ( v8 == (__int64 *)8 )
      goto LABEL_10;
LABEL_12:
    v17 = *(_DWORD *)(v9 + 24);
    if ( ((a2 - v17) & 0x80000000) != 0 )
    {
      v18 = v17 - a2;
      if ( v18 > 0 )
      {
        sub_940249A4(sub_94027ABC, 0, v18);
LABEL_10:
        sub_940223D4((unsigned __int64 *)v5[490]);
        return (unsigned __int64 *)v6;
      }
      sub_9404B508(
        v11,
        "DEBUG ASSERT FAILED at (%s:%d): %s\n",
        "external/lk/kernel/timer.c",
        288,
        (const char *)&loc_9404F130);
    }
    if ( *((_DWORD *)v8 - 2) != 1953066354 )
      break;
    v19 = (__int64 *)v8[1];
    *v19 = *v8;
    *(_QWORD *)(*v8 + 8) = v19;
    v8[1] = 0;
    *v8 = 0;
    v46 = (unsigned __int64 *)v5[490];
    sub_940223D4(v46);
    v20 = _ReadStatusReg(MPIDR_EL1);
    if ( (v20 & 0x1000000) != 0 )
      v20 >>= 8;
    v21 = *(unsigned int (__fastcall **)(__int64, _QWORD, __int64))(v9 + 32);
    v22 = *(_QWORD *)(v9 + 40);
    v47 = *(_DWORD *)(v9 + 28);
    v23 = v2[469] + 80 * ((unsigned __int8)v20 | (4 * ((v20 >> 8) & 0xF)));
    ++*(_QWORD *)(v23 + 64);
    if ( v21(v9, a2, v22) == 1 )
      v6 = 1;
    sub_940223B4(v46);
    if ( v47 != 0 && *v8 == 0 && v8[1] == 0 )
    {
      v24 = *(_DWORD *)(v9 + 28);
      if ( v24 != 0 )
      {
        *(_DWORD *)(v9 + 24) = a2 + v24;
        sub_940279D8(v4, v9);
      }
    }
  }
  v25 = sub_9404B508(
          v11,
          "DEBUG ASSERT FAILED at (%s:%d): %s\n",
          "external/lk/kernel/timer.c",
          253,
          "timer && timer->magic == TIMER_MAGIC");
  v43 = v26;
  v28 = v27;
  v44 = v29;
  v45 = v30;
  v31 = sub_94024AF0();
  *(_DWORD *)(v25 + 28) = v43;
  *(_QWORD *)(v25 + 32) = v44;
  *(_DWORD *)(v25 + 24) = v31 + v28;
  *(_QWORD *)(v25 + 40) = v45;
  v32 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v32 = 1;
  }
  sub_940223B4((unsigned __int64 *)0xFFFFFFFFE005A210LL);
  v38 = _ReadStatusReg(MPIDR_EL1);
  if ( (v38 & 0x1000000) != 0 )
    v38 >>= 8;
  v39 = (unsigned __int8)v38 | (4 * ((v38 >> 8) & 0xF));
  sub_940279D8(v39, v25);
  v40 = &qword_94067500[4 * (unsigned __int8)v39];
  v41 = (__int64 *)v40[1];
  if ( v41 != nullptr && v41 != v40 && (__int64 *)v25 == v41 - 1 )
    sub_940249A4(sub_94027ABC, 0, v28);
  result = sub_940223D4((unsigned __int64 *)0xFFFFFFFFE005A210LL);
  if ( v32 != 0 )
    __asm { MSR             DAIFClr, #2 }
  return result;
}

/* ===== sub_94027E28 @ 0x94027E28 size 40 ===== */
__int64 __fastcall sub_94027E28(__int64 result)
{
  *(_QWORD *)(result + 8) = 0;
  *(_QWORD *)(result + 16) = 0;
  *(_DWORD *)result = 1953066354;
  *(_DWORD *)(result + 24) = 0;
  *(_DWORD *)(result + 28) = 0;
  *(_QWORD *)(result + 32) = 0;
  *(_QWORD *)(result + 40) = 0;
  return result;
}

/* ===== sub_94027E50 @ 0x94027E50 size 52 ===== */
bool __fastcall sub_94027E50(unsigned int a1)
{
  __int64 *v1; // x0
  __int64 *v2; // x1

  v1 = &qword_94067500[4 * a1];
  v2 = (__int64 *)v1[1];
  return v2 == nullptr || v2 == v1 || v2 == (__int64 *)8;
}

/* ===== sub_94027E84 @ 0x94027E84 size 140 ===== */
__int64 __fastcall sub_94027E84(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x5
  __int64 v6; // x8
  __int64 v7; // x4
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3

  v5 = a1;
  v6 = v4;
  v7 = a4;
  if ( *(_DWORD *)a1 == 1953066354 )
  {
    if ( *(_QWORD *)(a1 + 8) == 0 )
      goto LABEL_4;
    while ( 1 )
    {
      a1 = sub_9404B508(v6, (const char *)&loc_9404F178, v5, a4, v7);
LABEL_4:
      if ( *(_QWORD *)(a1 + 16) == 0 )
        JUMPOUT(0x94027D28LL);
    }
  }
  v8 = sub_9404B508(
         v4,
         "DEBUG ASSERT FAILED at (%s:%d): %s\n",
         "external/lk/kernel/timer.c",
         103,
         "timer->magic == TIMER_MAGIC");
  return sub_94027F10(v8, v9, v10, v11);
}

/* ===== sub_94027F10 @ 0x94027F10 size 140 ===== */
__int64 __fastcall sub_94027F10(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x5
  __int64 v6; // x8
  __int64 v7; // x4
  __int64 v8; // x0

  v5 = a1;
  v6 = v4;
  v7 = a4;
  if ( *(_DWORD *)a1 == 1953066354 )
  {
    if ( *(_QWORD *)(a1 + 8) == 0 )
      goto LABEL_4;
    while ( 1 )
    {
      a1 = sub_9404B508(v6, (const char *)&loc_9404F178, v5, a4, v7);
LABEL_4:
      if ( *(_QWORD *)(a1 + 16) == 0 )
        JUMPOUT(0x94027D28LL);
    }
  }
  v8 = sub_9404B508(
         v4,
         "DEBUG ASSERT FAILED at (%s:%d): %s\n",
         "external/lk/kernel/timer.c",
         103,
         "timer->magic == TIMER_MAGIC");
  return sub_94027F9C(v8);
}

/* ===== sub_94027F9C @ 0x94027F9C size 368 ===== */
unsigned __int64 *__fastcall sub_94027F9C(__int64 a1)
{
  __int64 *v1; // x20
  int v2; // w21
  __int64 v3; // x30
  unsigned __int64 StatusReg; // x0
  __int64 v6; // x8
  __int64 v7; // x2
  __int64 *v8; // x3
  __int64 v9; // x0
  __int64 v10; // x5
  BOOL v11; // w1
  _QWORD *v12; // x6
  signed int v13; // w2
  unsigned __int64 *result; // x0

  if ( *(_DWORD *)a1 != 1953066354 )
  {
    sub_9404B508(
      v3,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/timer.c",
      181,
      "timer->magic == TIMER_MAGIC");
LABEL_22:
    sub_94024A74();
    goto LABEL_16;
  }
  v2 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v2 = 1;
  }
  v1 = &qword_9405BFF0[2];
  sub_940223B4((unsigned __int64 *)0xFFFFFFFFE005A210LL);
  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  v6 = *(_QWORD *)(a1 + 8);
  v7 = (unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF));
  v8 = &qword_94067500[4 * v7];
  v9 = v8[1];
  v10 = v9 - 8;
  v11 = v9 != (_QWORD)v8 && v9 != 0;
  v12 = *(_QWORD **)(a1 + 16);
  if ( v9 == (_QWORD)v8 || v9 == 0 )
    v10 = 0;
  if ( v6 != 0 || v12 != nullptr )
  {
    *v12 = v6;
    *(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL) = v12;
    *(_QWORD *)(a1 + 16) = 0;
    *(_QWORD *)(a1 + 8) = 0;
    v9 = qword_94067500[4 * v7 + 1];
    v11 = v8 != (__int64 *)v9 && v9 != 0;
  }
  *(_DWORD *)(a1 + 28) = 0;
  *(_QWORD *)(a1 + 32) = 0;
  *(_QWORD *)(a1 + 40) = 0;
  if ( !v11 || v9 == 8 )
    goto LABEL_22;
  if ( v10 != v9 - 8 )
  {
    v13 = *(_DWORD *)(v9 + 16) - sub_94024AF0();
    if ( v13 < 0 )
      v13 = 0;
    sub_940249A4(sub_94027ABC, 0, v13);
  }
LABEL_16:
  result = sub_940223D4((unsigned __int64 *)v1[490]);
  if ( v2 != 0 )
    __asm { MSR             DAIFClr, #2 }
  return result;
}

/* ===== sub_94028150 @ 0x94028150 size 48 ===== */
__int64 __fastcall sub_94028150(__int64 result, int a2)
{
  *(_DWORD *)result = 1936026977;
  *(_DWORD *)(result + 4) = a2;
  *(_DWORD *)(result + 8) = 2002872692;
  *(_QWORD *)(result + 16) = result + 16;
  *(_QWORD *)(result + 24) = result + 16;
  *(_DWORD *)(result + 32) = 0;
  return result;
}

/* ===== sub_94028180 @ 0x94028180 size 132 ===== */
unsigned __int64 *__fastcall sub_94028180(__int64 a1)
{
  unsigned __int64 *result; // x0

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    *(_DWORD *)(a1 + 4) = 0;
    sub_94027688((_DWORD *)(a1 + 8), 1u);
    return sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
  }
  else
  {
    __asm { MSR             DAIFSet, #2 }
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    *(_DWORD *)(a1 + 4) = 0;
    sub_94027688((_DWORD *)(a1 + 8), 1u);
    result = sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    __asm { MSR             DAIFClr, #2 }
  }
  return result;
}

/* ===== sub_94028204 @ 0x94028204 size 244 ===== */
__int64 __fastcall sub_94028204(__int64 a1, char a2)
{
  int v9; // w0
  unsigned int v10; // w19
  int v13; // w0
  unsigned int v14; // w19

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    v13 = *(_DWORD *)(a1 + 4) + 1;
    *(_DWORD *)(a1 + 4) = v13;
    if ( v13 <= 0 )
      v14 = sub_94026F80(a1 + 8, a2, 0);
    else
      v14 = 0;
    sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    return v14;
  }
  else
  {
    __asm { MSR             DAIFSet, #2 }
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    v9 = *(_DWORD *)(a1 + 4) + 1;
    *(_DWORD *)(a1 + 4) = v9;
    if ( v9 <= 0 )
    {
      v10 = sub_94026F80(a1 + 8, a2, 0);
      sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      __asm { MSR             DAIFClr, #2 }
    }
    else
    {
      v10 = 0;
      sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      __asm { MSR             DAIFClr, #2 }
    }
    return v10;
  }
}

/* ===== sub_940282F8 @ 0x940282F8 size 296 ===== */
__int64 __fastcall sub_940282F8(__int64 a1, __int64 a2)
{
  int v8; // w0
  unsigned int v9; // w21
  int v12; // w0
  unsigned int v13; // w21

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    v12 = *(_DWORD *)(a1 + 4) - 1;
    *(_DWORD *)(a1 + 4) = v12;
    if ( v12 < 0 )
    {
      v13 = sub_94026BA8(a1 + 8, a2);
      if ( v13 == -13 )
        ++*(_DWORD *)(a1 + 4);
      sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    }
    else
    {
      v13 = 0;
      sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    }
    return v13;
  }
  else
  {
    __asm { MSR             DAIFSet, #2 }
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
    v8 = *(_DWORD *)(a1 + 4) - 1;
    *(_DWORD *)(a1 + 4) = v8;
    if ( v8 < 0 )
    {
      v9 = sub_94026BA8(a1 + 8, a2);
      if ( v9 == -13 )
      {
        ++*(_DWORD *)(a1 + 4);
        sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
        __asm { MSR             DAIFClr, #2 }
      }
      else
      {
        sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
        __asm { MSR             DAIFClr, #2 }
      }
    }
    else
    {
      v9 = 0;
      sub_940223D4((unsigned __int64 *)0xFFFFFFFFE00474E0LL);
      __asm { MSR             DAIFClr, #2 }
    }
    return v9;
  }
}

/* ===== nullsub_3 @ 0x94028420 size 4 ===== */
void nullsub_3()
{
  ;
}

/* ===== nullsub_4 @ 0x94028424 size 4 ===== */
void nullsub_4()
{
  ;
}

/* ===== sub_94028428 @ 0x94028428 size 68 ===== */
__int64 sub_94028428()
{
  unsigned __int64 StatusReg; // x0
  __int64 result; // x0
  unsigned int v2; // w2

  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  result = (unsigned int)(1 << (StatusReg | (4 * (BYTE1(StatusReg) & 0xF))));
  do
    v2 = __ldxr((unsigned int *)0xFFFFFFFFE005A220LL);
  while ( __stxr(v2 | result, (unsigned int *)0xFFFFFFFFE005A220LL) != 0 );
  return result;
}

/* ===== sub_9402846C @ 0x9402846C size 56 ===== */
__int64 sub_9402846C()
{
  __int64 result; // x0

  result = sub_9402985C(51, &qword_9405A588);
  if ( (_DWORD)result != 0 )
    return sub_9404CB4C("trusty error register entity: %d\n", result);
  return result;
}

/* ===== sub_940284A4 @ 0x940284A4 size 344 ===== */
unsigned __int64 *__fastcall sub_940284A4(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  int **v3; // x19
  char v5; // w20
  unsigned __int64 v12; // x10
  __int64 v13; // x7
  __int64 v14; // x9
  int *v15; // x6
  int v16; // w8
  __int64 i; // x4
  int v18; // w3
  char v19; // w5
  unsigned __int64 v20; // x2
  _DWORD *v21; // x6
  int v22; // w7
  __int64 v23; // x4
  int v24; // w3
  char v25; // w1
  unsigned __int64 *result; // x0

  v3 = (int **)(a1 - 32);
  v5 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v5 = 1;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) == 0 )
  {
    v5 |= 2u;
    __asm { MSR             DAIFSet, #1 }
  }
  sub_940223B4((unsigned __int64 *)&qword_94067580);
  v12 = a3 >> 7;
  if ( a3 >> 7 != 0 )
  {
    v13 = a2;
    v14 = 0;
    do
    {
      v15 = *v3;
      v16 = **v3;
      **v3 = v16 + 128;
      __dsb(0xEu);
      for ( i = 0; i != 128; ++i )
      {
        v18 = v16 + i;
        v19 = *(_BYTE *)(v13 + i);
        *((_BYTE *)v15 + (((unsigned int)v3[1] - 1) & v18) + 12) = v19;
      }
      __dsb(0xEu);
      ++v14;
      v13 += 128;
      v15[1] += 128;
    }
    while ( v14 != v12 );
    v12 <<= 7;
  }
  v20 = a3 - v12;
  if ( a3 != v12 )
  {
    v21 = *(_DWORD **)(a1 - 32);
    v22 = *v21;
    *v21 += v20;
    __dsb(0xEu);
    v23 = 0;
    do
    {
      v24 = v22 + v23;
      v25 = *(_BYTE *)(a2 + v12 + v23++);
      *((_BYTE *)v21 + (((unsigned int)v3[1] - 1) & v24) + 12) = v25;
    }
    while ( v23 != v20 );
    __dsb(0xEu);
    v21[1] += v23;
  }
  result = sub_940223D4((unsigned __int64 *)&qword_94067580);
  if ( (v5 & 2) != 0 )
    __asm { MSR             DAIFClr, #1 }
  if ( (v5 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  return result;
}

/* ===== sub_940285FC @ 0x940285FC size 372 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_940285FC(unsigned __int64 a1, __int64 a2)
{
  __int64 v2; // x2
  unsigned __int64 v3; // x3
  __int64 *v5; // x2
  bool v6; // zf
  __int64 v9; // x22
  __int64 v10; // x23
  _DWORD *v11; // x3
  char v12; // w2
  __int64 v13; // x0
  _DWORD *v14; // [xsp+48h] [xbp+48h] BYREF

  v2 = -536632000;
  if ( &qword_9405A578 == (__int64 *)-536631944LL )
  {
LABEL_7:
    v9 = sub_9404CBC4(72);
    if ( v9 != 0 )
    {
      v10 = a1 & 0xFFFFF;
      *(_QWORD *)(v9 + 16) = a1;
      *(_QWORD *)(v9 + 24) = a2;
      if ( (unsigned int)sub_9404A878(
                           -536460256,
                           "logmem",
                           (a2 + 0xFFFFF + (a1 & 0xFFFFF)) & 0xFFFFFFFFFFF00000LL,
                           &v14,
                           12,
                           a1 & 0xFFFFFFFFFFF00000LL,
                           0,
                           48) == 0 )
      {
        v11 = (_DWORD *)((char *)v14 + v10);
        v12 = __clz(*(_QWORD *)(v9 + 24) - 12);
        *(_QWORD *)v9 = (char *)v14 + v10;
        v13 = (unsigned int)(1 << (31 - v12));
        *(_QWORD *)(v9 + 8) = v13;
        v11[2] = v13;
        v14 = v11;
        *v11 = 0;
        v11[1] = 0;
        *(_QWORD *)(v9 + 64) = -536631944;
        *(_QWORD *)(v9 + 56) = &qword_9405A578;
        MEMORY[0xFFFFFFFFE003A578] = v9 + 56;
        off_9405A580 = (_UNKNOWN *)(v9 + 56);
        *(_QWORD *)(v9 + 48) = -536836956;
        sub_9404AF4C(v9 + 32);
        MEMORY[0xFFFFFFFFE0057F30] = 1;
        return 0;
      }
      sub_9404CC20(v9);
    }
    return -7;
  }
  else
  {
    while ( 1 )
    {
      v3 = *(_QWORD *)(v2 + 16);
      if ( v3 < a1 + a2 && a1 < v3 + *(_QWORD *)(v2 + 24) )
        return -2;
      v5 = *(__int64 **)(v2 + 64);
      v6 = &qword_9405A578 == v5;
      v2 = (__int64)(v5 - 7);
      if ( v6 )
        goto LABEL_7;
    }
  }
}

/* ===== sub_94028770 @ 0x94028770 size 172 ===== */
__int64 __fastcall sub_94028770(__int64 a1)
{
  __int64 v1; // x1
  __int64 v2; // x19
  _QWORD *v3; // x2
  __int64 v4; // x1
  int v5; // w20
  __int64 result; // x0

  v1 = -536631944;
  v2 = -536632000;
  if ( &qword_9405A578 == (__int64 *)-536631944LL )
    return -2;
  while ( a1 != *(_QWORD *)(v1 - 40) )
  {
    v1 = *(_QWORD *)(v2 + 64);
    v2 = v1 - 56;
    if ( &qword_9405A578 == (__int64 *)v1 )
      return -2;
  }
  sub_9404B014(v2 + 32);
  v3 = *(_QWORD **)(v2 + 64);
  v4 = *(_QWORD *)v2;
  *v3 = *(_QWORD *)(v2 + 56);
  *(_QWORD *)(*(_QWORD *)(v2 + 56) + 8LL) = v3;
  *(_QWORD *)(v2 + 64) = 0;
  *(_QWORD *)(v2 + 56) = 0;
  v5 = sub_9404ABDC(-536460256, v4);
  sub_9404CC20(v2);
  result = -7;
  if ( v5 == 0 )
    return 0;
  return result;
}

/* ===== sub_9402881C @ 0x9402881C size 92 ===== */
__int64 __fastcall sub_9402881C(int *a1)
{
  int v1; // w1
  __int64 result; // x0

  v1 = *a1;
  if ( *a1 == 855638017 )
    return sub_940285FC((unsigned int)a1[1] | ((unsigned __int64)(unsigned int)a1[2] << 32), (unsigned int)a1[3]);
  if ( v1 == 855638018 )
    return sub_94028770((unsigned int)a1[1] | ((unsigned __int64)(unsigned int)a1[2] << 32));
  result = 0xFFFFFFFFLL;
  if ( v1 == 855638016 )
    return 1;
  return result;
}

/* ===== sub_94028878 @ 0x94028878 size 56 ===== */
__int64 sub_94028878()
{
  __int64 result; // x0

  result = sub_9402985C(53, &qword_9405A598);
  if ( (_DWORD)result != 0 )
    return sub_9404CB4C("trusty error register entity: %d\n", result);
  return result;
}

/* ===== sub_940288B0 @ 0x940288B0 size 152 ===== */
__int64 __fastcall sub_940288B0(_DWORD *a1)
{
  unsigned int v2; // w1
  __int64 result; // x0

  switch ( *a1 )
  {
    case 0x35000000:
      MEMORY[0xFFFFFFFFE0059F48] = (unsigned int)a1[1];
      result = 0;
      break;
    case 0x35000001:
      result = MEMORY[0xFFFFFFFFE0059F48];
      break;
    case 0x35000002:
      v2 = a1[1];
      if ( v2 > 2 )
      {
        result = -2;
      }
      else
      {
        result = 0;
        MEMORY[0xFFFFFFFFE003CB98] = v2;
      }
      break;
    case 0x35000003:
      result = MEMORY[0xFFFFFFFFE003CB98];
      break;
    default:
      result = 0xFFFFFFFFLL;
      break;
  }
  return result;
}

/* ===== sub_94028948 @ 0x94028948 size 96 ===== */
__int64 __fastcall sub_94028948(int a1, _DWORD *a2)
{
  _DWORD *v8; // x9
  _DWORD *v9; // [xsp+10h] [xbp-10h]

  v9 = a2;
  __asm { SMC             #0 }
  v8 = v9;
  *v9 = 1006632960;
  v8[1] = a1;
  v8 += 2;
  *v8 = 0;
  v8[1] = 0;
  return 1006632960;
}

/* ===== sub_940289A8 @ 0x940289A8 size 8 ===== */
void sub_940289A8()
{
  JUMPOUT(0x94028950LL);
}

/* ===== sub_940289B0 @ 0x940289B0 size 36 ===== */
__int64 __fastcall sub_940289B0(unsigned __int16 *a1)
{
  __int64 v1; // x1
  __int64 (*v3)(void); // x2

  v1 = *a1;
  if ( (unsigned int)v1 < MEMORY[0xFFFFFFFFE003AB08] && (v3 = *(__int64 (**)(void))(8 * v1 - 536631192)) != nullptr )
    return v3();
  else
    return sub_940289D4();
}

/* ===== sub_940289D4 @ 0x940289D4 size 8 ===== */
// attributes: thunk
void sub_940289D4(void)
{
  JUMPOUT(0xFFFFFFFFE0009608LL);
}

/* ===== sub_94028A08 @ 0x94028A08 size 588 ===== */
// write access to const memory has been detected, the output may be wrong!
unsigned __int64 *__fastcall sub_94028A08(int a1, int a2)
{
  __int64 v9; // x0
  __int64 v10; // x30
  __int64 v11; // x22
  unsigned __int64 StatusReg; // x0
  int v13; // w19
  _DWORD *v14; // x0
  _DWORD *v15; // x0
  unsigned __int64 *result; // x0
  __int64 i; // x19
  _DWORD *v18; // x0
  unsigned __int64 *v19; // x1
  _BYTE v20[32]; // [xsp+60h] [xbp-20h] BYREF
  _QWORD v21[2]; // [xsp+B0h] [xbp+30h] BYREF

  v21[0] = 0;
  v21[1] = 0;
  if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
    sub_9404B2FC("HALT: (reason = %d)\n", a2);
  __asm
  {
    MSR             DAIFSet, #2
    MSR             DAIFSet, #1
  }
  while ( a1 != 3 || *(_QWORD *)(_ReadStatusReg(TPIDR_EL1) + 688) == 0 )
    sub_94028948(-11, v21);
  if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
    sub_9404B2FC("HALT: terminate user thread %s\n", (const char *)(_ReadStatusReg(TPIDR_EL1) + 696));
  v9 = sub_9402E190();
  sub_9402E300(v9);
  sub_9404D33C(0);
  v11 = v10;
  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  v13 = (unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF));
  sub_94024DFC((__int64)&qword_94067600[6 * v13], 0, 1);
  sub_9404CAC0(v20, 32, "irq-ns-switch-%d", v13);
  v14 = (_DWORD *)sub_940268B8((__int64)v20, (__int64)sub_940291F4, (unsigned __int8)v13, 0x1Fu, 4096);
  qword_940675B0[v13] = (__int64)v14;
  if ( v14 != nullptr )
  {
    v14[15] = v13;
    sub_94025E88(v14);
    sub_9404CAC0(v20, 32, "idle-ns-switch-%d", v13);
    v15 = (_DWORD *)sub_940268B8((__int64)v20, (__int64)sub_940290C8, 0, 1u, 4096);
    qword_940675D8[v13] = (__int64)v15;
    if ( v15 != nullptr )
    {
      v15[15] = v13;
      sub_94025E88(v15);
      return nullptr;
    }
    sub_9404B508(v11, "failed to create idle NS switcher thread for cpu %d!\n", v13);
  }
  sub_9404B508(v11, "failed to create irq NS switcher thread for cpu %d!\n", v13);
  byte_940675A0 = 1;
  __dmb(0xAu);
  for ( i = 0; i != 4; ++i )
  {
    v18 = (_DWORD *)qword_940675B0[i];
    if ( v18 != nullptr )
      sub_940260B0(v18);
    v19 = (unsigned __int64 *)qword_940675D8[i];
    result = v19;
    if ( v19 != nullptr )
      result = sub_940260B0(v19);
  }
  return result;
}

/* ===== sub_94028C54 @ 0x94028C54 size 292 ===== */
// write access to const memory has been detected, the output may be wrong!
unsigned __int64 *sub_94028C54()
{
  __int64 v0; // x30
  __int64 v1; // x20
  _DWORD *v2; // x0
  __int64 v4; // x21
  int v5; // w3
  __int64 v6; // x0
  __int64 v7; // [xsp+38h] [xbp+38h] BYREF

  v1 = v0;
  sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
  if ( MEMORY[0xFFFFFFFFE005A028] != 0 && MEMORY[0xFFFFFFFFE005A030] != 0 )
  {
    v4 = MEMORY[0xFFFFFFFFE005A028] & 0xFFF;
    v5 = sub_9404A878(
           -536460256,
           "sm",
           (MEMORY[0xFFFFFFFFE005A030] + 4095LL + v4) & 0xFFFFFFFFFFFFF000LL,
           &v7,
           12,
           MEMORY[0xFFFFFFFFE005A028] & 0xFFFFFFFFFFFFF000LL,
           0,
           48);
    if ( v5 != 0 )
    {
      qword_940675D0 = 0;
      sub_9404CB4C("%s:%d: Error mapping boot parameter block: %d\n", "sm_init", 398, v5);
    }
    else
    {
      qword_940675D0 = v7 + v4;
      dword_940675A4 = 1;
    }
  }
  sub_9402530C((__int64)"xtum");
  v2 = (_DWORD *)sub_940268B8((__int64)"sm-stdcall", (__int64)sub_94028F28, 0, 2u, 4096);
  qword_940675A8 = (__int64)v2;
  if ( v2 != nullptr )
  {
    sub_94025E88(v2);
    return sub_940260B0(nullptr);
  }
  else
  {
    v6 = sub_9404B508(v1, "failed to create sm-stdcall thread!\n");
    return (unsigned __int64 *)sub_94028D78(v6);
  }
}

/* ===== sub_94028D78 @ 0x94028D78 size 432 ===== */
__int64 __fastcall sub_94028D78(int a1)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x0
  int v10; // w25
  unsigned __int64 v11; // x3
  __int64 v12; // [xsp+50h] [xbp+50h] BYREF
  __int64 v13; // [xsp+58h] [xbp+58h]

  v12 = 0;
  v13 = 0;
  while ( 1 )
  {
    __asm { MSR             DAIFSet, #1 }
    sub_94028948(a1, &v12);
    __asm { MSR             DAIFClr, #1 }
    result = 1006632963;
    if ( (_DWORD)v12 == 1006632963 )
      return result;
    StatusReg = _ReadStatusReg(MPIDR_EL1);
    if ( (StatusReg & 0x1000000) != 0 )
      StatusReg >>= 8;
    v10 = (unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF));
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE003A5A8LL);
    if ( MEMORY[0xFFFFFFFFE003A5B4] != 0 || MEMORY[0xFFFFFFFFE003A5F8] != 0 )
    {
      if ( (_DWORD)v12 == 1006632960 && MEMORY[0xFFFFFFFFE003A5FC] == -1 )
      {
        ++MEMORY[0xFFFFFFFFE003A608];
LABEL_18:
        MEMORY[0xFFFFFFFFE003A5FC] = v10;
        return (__int64)sub_940223D4((unsigned __int64 *)0xFFFFFFFFE003A5A8LL);
      }
      a1 = -5;
      if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
        sub_9404B2FC("%s: cpu %d, std call busy\n", "sm_queue_stdcall", v10);
    }
    else
    {
      if ( (_DWORD)v12 != 1006632960 )
      {
        MEMORY[0xFFFFFFFFE003A600] = v10;
        MEMORY[0xFFFFFFFFE003A5F0] = -7;
        MEMORY[0xFFFFFFFFE003A5E0] = v12;
        MEMORY[0xFFFFFFFFE003A5E8] = v13;
        MEMORY[0xFFFFFFFFE003A608] = 0;
        sub_94024FDC(-536631888, 0);
        goto LABEL_18;
      }
      if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) != 0 )
      {
        a1 = -4;
      }
      else
      {
        v11 = _ReadStatusReg(MPIDR_EL1);
        if ( (v11 & 0x1000000) != 0 )
          v11 >>= 8;
        a1 = -4;
        sub_9404B2FC(
          "%s: cpu %d, unexpected restart, no std call active\n",
          "sm_queue_stdcall",
          (unsigned __int8)v11 | (4 * ((v11 >> 8) & 0xF)));
      }
    }
    sub_940223D4((unsigned __int64 *)0xFFFFFFFFE003A5A8LL);
  }
}

/* ===== sub_94028F28 @ 0x94028F28 size 164 ===== */
void __noreturn sub_94028F28()
{
  __int64 v0; // x24

  while ( 1 )
  {
    sub_94024EFC(-536631888, 0xFFFFFFFFLL);
    v0 = (*(__int64 (__fastcall **)(__int64))(8LL * (HIBYTE(MEMORY[0xFFFFFFFFE003A5E0]) & 0x3F) - 536631032))(-536631840);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    {
      sub_940223B4((unsigned __int64 *)0xFFFFFFFFE003A5A8LL);
      MEMORY[0xFFFFFFFFE003A5F0] = v0;
      MEMORY[0xFFFFFFFFE003A5F8] = 1;
      sub_940250FC(-536631888);
      sub_940223D4((unsigned __int64 *)0xFFFFFFFFE003A5A8LL);
    }
    else
    {
      __asm { MSR             DAIFSet, #2 }
      sub_940223B4((unsigned __int64 *)0xFFFFFFFFE003A5A8LL);
      MEMORY[0xFFFFFFFFE003A5F0] = v0;
      MEMORY[0xFFFFFFFFE003A5F8] = 1;
      sub_940250FC(-536631888);
      sub_940223D4((unsigned __int64 *)0xFFFFFFFFE003A5A8LL);
      __asm { MSR             DAIFClr, #2 }
    }
  }
}

/* ===== sub_94028FCC @ 0x94028FCC size 252 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_94028FCC()
{
  char v0; // w21

  v0 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v0 = 1;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) != 0 )
  {
    sub_940223B4((unsigned __int64 *)&qword_94067590);
    byte_94067588 = 1;
    sub_9404CB4C("%s:%d: lock api version %d\n", "sm_get_api_version", 109, 0);
    sub_940223D4((unsigned __int64 *)&qword_94067590);
  }
  else
  {
    v0 |= 2u;
    __asm { MSR             DAIFSet, #1 }
    sub_940223B4((unsigned __int64 *)&qword_94067590);
    byte_94067588 = 1;
    sub_9404CB4C("%s:%d: lock api version %d\n", "sm_get_api_version", 109, 0);
    sub_940223D4((unsigned __int64 *)&qword_94067590);
    __asm { MSR             DAIFClr, #1 }
  }
  if ( (v0 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  return 0;
}

/* ===== sub_940290C8 @ 0x940290C8 size 300 ===== */
void sub_940290C8()
{
  unsigned __int64 StatusReg; // x0
  int v7; // w27
  unsigned __int64 v8; // x27
  int v9; // w28

  while ( 1 )
  {
    __asm { MSR             DAIFSet, #2 }
    sub_94025F90();
    StatusReg = _ReadStatusReg(MPIDR_EL1);
    if ( (StatusReg & 0x1000000) != 0 )
      StatusReg >>= 8;
    v7 = -15;
    if ( MEMORY[0xFFFFFFFFE003A5FC] == ((unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF))) )
    {
      v8 = _ReadStatusReg(MPIDR_EL1);
      if ( (v8 & 0x1000000) != 0 )
        v8 >>= 8;
      v9 = (unsigned __int8)v8 | (4 * ((v8 >> 8) & 0xF));
      sub_940223B4((unsigned __int64 *)0xFFFFFFFFE003A5A8LL);
      if ( MEMORY[0xFFFFFFFFE003A5FC] == v9 )
      {
        MEMORY[0xFFFFFFFFE003A604] = MEMORY[0xFFFFFFFFE003A5FC];
        MEMORY[0xFFFFFFFFE003A5FC] = -1;
        if ( MEMORY[0xFFFFFFFFE003A5F8] != 0 )
        {
          MEMORY[0xFFFFFFFFE003A5F8] = 0;
          v7 = MEMORY[0xFFFFFFFFE003A5F0];
        }
        else if ( (unsigned int)sub_94028FCC() > 1 )
        {
          v7 = -13;
        }
        else if ( MEMORY[0xFFFFFFFFE003A608] != 0 )
        {
          v7 = -5;
        }
        else
        {
          v7 = -3;
        }
      }
      else
      {
        v7 = -7;
        if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
          sub_9404B2FC(
            "%s: stdcallcpu, a%d != curr-cpu %d, l%d, i%d\n",
            "sm_get_stdcall_ret",
            MEMORY[0xFFFFFFFFE003A5FC],
            v9,
            MEMORY[0xFFFFFFFFE003A604],
            MEMORY[0xFFFFFFFFE003A600]);
      }
      sub_940223D4((unsigned __int64 *)0xFFFFFFFFE003A5A8LL);
    }
    sub_94028D78(v7);
    __asm { MSR             DAIFClr, #2 }
  }
}

/* ===== sub_940291F4 @ 0x940291F4 size 180 ===== */
void __fastcall __noreturn sub_940291F4(int a1)
{
  __int64 *v6; // x23
  unsigned __int64 StatusReg; // x1
  int v8; // w21
  int v9; // w19

  __asm { MSR             DAIFSet, #2 }
  *((_BYTE *)&qword_94067598 + a1) = 1;
  _ReadStatusReg(MPIDR_EL1);
  v6 = &qword_94067600[6 * a1];
  while ( 1 )
  {
    sub_94024EFC((__int64)v6, 0xFFFFFFFFLL);
    StatusReg = _ReadStatusReg(MPIDR_EL1);
    if ( (StatusReg & 0x1000000) != 0 )
      StatusReg >>= 8;
    v8 = -14;
    v9 = (unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF));
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE003A5A8LL);
    if ( v9 == MEMORY[0xFFFFFFFFE003A5FC] )
    {
      MEMORY[0xFFFFFFFFE003A604] = v9;
      v8 = -3;
      MEMORY[0xFFFFFFFFE003A5FC] = -1;
    }
    sub_940223D4((unsigned __int64 *)0xFFFFFFFFE003A5A8LL);
    sub_94028D78(v8);
  }
}

/* ===== sub_940292A8 @ 0x940292A8 size 160 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_940292A8(__int64 a1)
{
  unsigned int v1; // w19

  v1 = *(_DWORD *)(a1 + 4);
  sub_940223B4((unsigned __int64 *)&qword_94067590);
  if ( v1 > 2 )
    v1 = 2;
  dword_940675F8 = v1;
  sub_940223D4((unsigned __int64 *)&qword_94067590);
  return v1;
}

/* ===== sub_94029348 @ 0x94029348 size 260 ===== */
__int64 sub_94029348()
{
  unsigned __int64 StatusReg; // x1
  __int64 v1; // x1
  unsigned __int64 v2; // x0
  int v3; // w22
  int v4; // w19

  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  v1 = (int)((unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF)));
  if ( *((_BYTE *)&qword_94067598 + v1) != 0 )
  {
    sub_94024FDC((__int64)&qword_94067600[6 * v1], 0);
    return 1;
  }
  else
  {
    sub_9404CB4C("%s:%d: warning: got ns irq before irq thread is ready\n", "sm_handle_irq", 421);
    v2 = _ReadStatusReg(MPIDR_EL1);
    if ( (v2 & 0x1000000) != 0 )
      v2 >>= 8;
    v3 = -14;
    v4 = (unsigned __int8)v2 | (4 * ((v2 >> 8) & 0xF));
    sub_940223B4((unsigned __int64 *)0xFFFFFFFFE003A5A8LL);
    if ( v4 == MEMORY[0xFFFFFFFFE003A5FC] )
    {
      MEMORY[0xFFFFFFFFE003A604] = v4;
      MEMORY[0xFFFFFFFFE003A5FC] = -1;
      v3 = -3;
    }
    sub_940223D4((unsigned __int64 *)0xFFFFFFFFE003A5A8LL);
    sub_94028D78(v3);
    return 1;
  }
}

/* ===== sub_9402944C @ 0x9402944C size 156 ===== */
__int64 sub_9402944C()
{
  int v0; // w20
  __int64 result; // x0
  _QWORD v2[2]; // [xsp+20h] [xbp+20h] BYREF

  v2[0] = 0;
  v2[1] = 0;
  if ( (unsigned int)sub_94028FCC() != 0 )
  {
    v0 = 1006632962;
    result = sub_94028948(-12, v2);
  }
  else
  {
    v0 = 1006632960;
    result = sub_94028948(-3, v2);
  }
  if ( LODWORD(v2[0]) != v0 )
  {
    sub_9404CB4C("%s:%d: got bad restart smc %x, expected %x\n", "sm_handle_fiq", 441, LODWORD(v2[0]), v0);
    for ( result = LODWORD(v2[0]); LODWORD(v2[0]) != v0; result = LODWORD(v2[0]) )
      sub_94028948(-6, v2);
  }
  return result;
}

/* ===== sub_940294E8 @ 0x940294E8 size 124 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_940294E8()
{
  sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
  sub_9404CB4C("%s:%d: WARNING: caller does not own a reference to boot parameters\n", "sm_put_boot_args", 489);
  return sub_9402530C((__int64)"xtum");
}

/* ===== sub_94029564 @ 0x94029564 size 88 ===== */
__int64 sub_94029564()
{
  ((void (*)(void))loc_94028BE4)();
  return 0;
}

/* ===== sub_940295BC @ 0x940295BC size 8 ===== */
__int64 sub_940295BC()
{
  return 0;
}

/* ===== sub_940295C4 @ 0x940295C4 size 68 ===== */
__int64 __fastcall sub_940295C4(unsigned __int16 *a1)
{
  __int64 (*v1)(void); // x1

  if ( *a1 <= 3u && (v1 = (__int64 (*)(void))qword_9405A848[*a1]) != nullptr )
    return v1();
  else
    return MEMORY[0xFFFFFFFFE0009608]();
}

/* ===== sub_94029608 @ 0x94029608 size 184 ===== */
__int64 __fastcall sub_94029608(unsigned int *a1)
{
  unsigned __int64 v2; // x3
  const char *v3; // x4
  int *v4; // x20
  int v5; // w19
  int v6; // t1
  int v7; // w3

  sub_9404CB4C("%s:%d: %s\n", "smc_undefined", 78, (const char *)&loc_9404F578);
  v2 = *a1;
  if ( (v2 & 0x80000000) != 0 )
    v3 = "Fastcall";
  else
    v3 = "Stdcall";
  v4 = (int *)(a1 + 1);
  v5 = 0;
  sub_9404CB4C(
    "%s:%d: SMC: 0x%x (%s entity %d function 0x%x)\n",
    "smc_undefined",
    78,
    v2,
    v3,
    (v2 >> 24) & 0x3F,
    (unsigned __int16)v2);
  do
  {
    v6 = *v4++;
    v7 = v5++;
    sub_9404CB4C("%s:%d: param%d: 0x%x\n", "smc_undefined", 78, v7, v6);
  }
  while ( v5 != 3 );
  return 0xFFFFFFFFLL;
}

/* ===== sub_940296C0 @ 0x940296C0 size 184 ===== */
__int64 __fastcall sub_940296C0(unsigned int *a1)
{
  unsigned __int64 v2; // x3
  const char *v3; // x4
  int *v4; // x20
  int v5; // w19
  int v6; // t1
  int v7; // w3

  sub_9404CB4C("%s:%d: %s\n", "smc_restart_stdcall", 85, "Unexpected stdcall restart!");
  v2 = *a1;
  if ( (v2 & 0x80000000) != 0 )
    v3 = "Fastcall";
  else
    v3 = "Stdcall";
  v4 = (int *)(a1 + 1);
  v5 = 0;
  sub_9404CB4C(
    "%s:%d: SMC: 0x%x (%s entity %d function 0x%x)\n",
    "smc_restart_stdcall",
    85,
    v2,
    v3,
    (v2 >> 24) & 0x3F,
    (unsigned __int16)v2);
  do
  {
    v6 = *v4++;
    v7 = v5++;
    sub_9404CB4C("%s:%d: param%d: 0x%x\n", "smc_restart_stdcall", 85, v7, v6);
  }
  while ( v5 != 3 );
  return -4;
}

/* ===== sub_94029778 @ 0x94029778 size 24 ===== */
__int64 sub_94029778()
{
  sub_9402463C();
  return 1;
}

/* ===== sub_94029790 @ 0x94029790 size 32 ===== */
__int64 __fastcall sub_94029790(__int64 a1)
{
  if ( sub_94027E50(*(_DWORD *)(a1 + 4)) )
    return 0;
  else
    return -1;
}

/* ===== sub_940297B0 @ 0x940297B0 size 76 ===== */
unsigned __int64 __fastcall sub_940297B0(__int64 a1)
{
  int v1; // w19
  unsigned __int64 result; // x0

  v1 = *(_DWORD *)(a1 + 4);
  result = sub_9404CFF4(-536621880);
  if ( v1 != -1 )
  {
    if ( result <= v1 )
      return -2;
    else
      return *(unsigned __int8 *)(v1 - 536621880LL);
  }
  return result;
}

/* ===== sub_940297FC @ 0x940297FC size 36 ===== */
__int64 sub_940297FC()
{
  sub_94023388(8, 1u, 0xFFFFFFFF);
  return 0;
}

/* ===== sub_94029820 @ 0x94029820 size 36 ===== */
__int64 sub_94029820()
{
  sub_94023388(4, 1u, 0xFFFFFFFF);
  return 0;
}

/* ===== sub_94029844 @ 0x94029844 size 24 ===== */
__int64 sub_94029844()
{
  return (int)sub_94024500();
}

/* ===== sub_9402985C @ 0x9402985C size 228 ===== */
__int64 __fastcall sub_9402985C(unsigned int a1, _QWORD *a2)
{
  unsigned int v4; // w21
  __int64 v6; // x0

  if ( a1 <= 0x3F )
  {
    if ( a1 - 5 <= 0x2A )
      return 4294967279LL;
    if ( a2 != nullptr )
    {
      if ( *a2 == 0 && a2[1] == 0 )
        return 4294967289LL;
      v4 = -14;
      sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
      if ( *(_QWORD *)(8LL * a1 - 536631736) == -536832504 && *(_QWORD *)(8LL * a1 - 536631032) == -536832504 )
      {
        if ( *a2 != 0 )
          *(_QWORD *)(8LL * a1 - 536631736) = *a2;
        v6 = a2[1];
        v4 = 0;
        if ( v6 != 0 )
          *(_QWORD *)(8LL * a1 - 536631032) = v6;
      }
      sub_9402530C((__int64)"xtum");
      return v4;
    }
  }
  return 4294967288LL;
}

/* ===== sub_94029940 @ 0x94029940 size 284 ===== */
__int64 __fastcall sub_94029940(_QWORD *a1, __int64 *a2, int *a3)
{
  int v6; // w3
  __int64 v7; // x3
  int v8; // w1
  __int64 result; // x0

  if ( a1 == nullptr )
    return 4294967288LL;
  sub_9404CB4C(
    "%s:%d: raw=0x%llx: pa=0x%llx: mair=0x%x, sharable=0x%x\n",
    "sm_decode_ns_memory_attr",
    89,
    *a1,
    *a1 & 0xFFFFFFFFF000LL,
    (unsigned __int8)BYTE6(*a1),
    (*a1 >> 8) & 3);
  if ( a2 != nullptr )
    *a2 = *a1 & 0xFFFFFFFFF000LL;
  if ( a3 == nullptr )
    return 0;
  v6 = (unsigned __int8)BYTE6(*a1);
  if ( v6 == 68 )
  {
    v8 = 1;
  }
  else
  {
    if ( v6 != 255 )
    {
      sub_9404CB4C("%s:%d: Unsupported memory attr 0x%x\n", "sm_decode_ns_memory_attr", 112, v6);
      return 4294967272LL;
    }
    v7 = (*a1 >> 8) & 3LL;
    if ( v7 != 3 )
    {
      sub_9404CB4C("%s:%d: Unsupported sharable attr 0x%x\n", "sm_decode_ns_memory_attr", 119, v7);
      return 4294967272LL;
    }
    v8 = 0;
  }
  if ( (*a1 & 0x40LL) != 0 )
    v8 |= 4u;
  result = 0;
  if ( (*a1 & 0x80LL) != 0 )
    v8 |= 8u;
  *a3 = v8 | 0x30;
  return result;
}

/* ===== sub_94029A5C @ 0x94029A5C size 268 ===== */
__int64 __fastcall sub_94029A5C(unsigned int *a1, __int64 *a2, _DWORD *a3, int *a4)
{
  __int64 v4; // x30
  __int64 result; // x0
  unsigned __int64 v8; // [xsp+48h] [xbp+28h] BYREF

  if ( a1 != nullptr )
  {
    v8 = a1[1] | ((unsigned __int64)a1[2] << 32);
    result = sub_94029940(&v8, a2, a4);
    if ( (_DWORD)result == 0 && a3 != nullptr )
      *a3 = a1[3];
  }
  else
  {
    sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/sm/ns_mem.c", 144, "args");
    sub_9404CC78(-536485312, "VerifiedBoot-LOCK", 18);
    MEMORY[0xFFFFFFFFE005F240] = 64;
    if ( (unsigned int)sub_9402985C(0x34u, &qword_9405AB20) != 0 )
      sub_9404CB4C("trusty error register entity: %d\n", 52);
    result = sub_9402985C(2u, qword_9405AB10);
    if ( (_DWORD)result != 0 )
      return sub_9404CB4C("trusty error register entity: %d\n", 2);
  }
  return result;
}

/* ===== sub_94029B68 @ 0x94029B68 size 564 ===== */
__int64 __fastcall sub_94029B68(__int64 a1, unsigned int a2)
{
  __int64 v4; // x0
  __int64 v5; // x20
  int v6; // w0
  unsigned int v7; // w19
  int v9; // w0
  unsigned int v10; // w1
  _QWORD v11[4]; // [xsp+40h] [xbp+40h] BYREF
  _BYTE v12[352]; // [xsp+60h] [xbp+60h] BYREF

  strcpy((char *)v11, " !\"#$%&'()*+,-./");
  BYTE1(v11[2]) = 0;
  WORD1(v11[2]) = 0;
  HIDWORD(v11[2]) = 0;
  v11[3] = 0;
  v4 = sub_9404CBC4(a2);
  v5 = v4;
  if ( v4 != 0 )
  {
    sub_94040888(v4, 0, a2);
    v6 = sub_94037D54(0, 0, v12, v11, 0, 16, 0, 0);
    if ( v6 != 0 )
    {
      if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
      {
        v7 = -65521;
        sub_9404B2FC("lihj : aes_cbc encrypt test init FAILED [%d]\n", v6);
LABEL_5:
        sub_9404CC20(v5);
        return v7;
      }
    }
    else
    {
      v9 = sub_94038198(v12, a1, v5, a2);
      if ( v9 != 0 )
      {
        if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
        {
          v7 = -65521;
          sub_9404B2FC("lihj : aes_cbc encrypt test process FAILED [%d]\n", v9);
          goto LABEL_5;
        }
      }
      else
      {
        v7 = sub_940381DC(v12, 0, 0, 0, 0, 0);
        if ( v7 == 0 )
        {
          sub_94040880(a1, v5, a2);
          goto LABEL_5;
        }
        if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
        {
          v10 = v7;
          v7 = -65521;
          sub_9404B2FC("lihj : aes_cbc encrypt test final FAILED [%d]\n", v10);
          goto LABEL_5;
        }
      }
    }
    sub_9404CC20(v5);
    return 4294901775LL;
  }
  else
  {
    v7 = -65526;
    if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) != 0 )
      goto LABEL_5;
    sub_9404B2FC("Cann't malloc memory for pt !\n");
    sub_9404CC20(0);
    return 4294901770LL;
  }
}

/* ===== sub_94029D9C @ 0x94029D9C size 620 ===== */
__int64 __fastcall sub_94029D9C(unsigned int a1, unsigned __int8 *a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v7; // x1
  unsigned __int8 *v8; // x19
  __int64 v9; // x19
  __int64 v10; // x19
  __int64 v11; // x19

  switch ( a1 )
  {
    case 2u:
      v7 = MEMORY[0xFFFFFFFFE003CB98];
      if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      {
        sub_9404B2FC("hwkey hash from uboot is:\n");
        v7 = MEMORY[0xFFFFFFFFE003CB98];
      }
      v8 = a2;
      do
      {
        if ( v7 > 1 )
        {
          sub_9404B2FC("%02x", *v8);
          v7 = MEMORY[0xFFFFFFFFE003CB98];
        }
        ++v8;
      }
      while ( v8 != a2 + 32 );
      goto LABEL_14;
    case 1u:
      v7 = MEMORY[0xFFFFFFFFE003CB98];
      if ( MEMORY[0xFFFFFFFFE003CB98] <= 1 )
      {
        if ( a3 == 0 )
          goto LABEL_5;
      }
      else
      {
        sub_9404B2FC("public key from uboot is:\n");
        v7 = MEMORY[0xFFFFFFFFE003CB98];
        if ( a3 == 0 )
          goto LABEL_14;
      }
      v9 = 0;
      do
      {
        if ( v7 > 1 )
        {
          sub_9404B2FC("%02x", a2[v9]);
          v7 = MEMORY[0xFFFFFFFFE003CB98];
        }
        ++v9;
      }
      while ( a3 > (unsigned int)v9 );
      goto LABEL_14;
    case 4u:
      v7 = MEMORY[0xFFFFFFFFE003CB98];
      if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      {
        sub_9404B2FC("device state from uboot is:\n");
        v7 = MEMORY[0xFFFFFFFFE003CB98];
        if ( a3 == 0 )
          goto LABEL_14;
      }
      else if ( a3 == 0 )
      {
        goto LABEL_5;
      }
      v10 = 0;
      do
      {
        if ( v7 > 1 )
        {
          sub_9404B2FC("%02x", a2[v10]);
          v7 = MEMORY[0xFFFFFFFFE003CB98];
        }
        ++v10;
      }
      while ( a3 > (unsigned int)v10 );
      goto LABEL_14;
    default:
      break;
  }
  if ( a1 != 5 )
    goto LABEL_5;
  v7 = MEMORY[0xFFFFFFFFE003CB98];
  if ( MEMORY[0xFFFFFFFFE003CB98] <= 1 )
  {
    if ( a3 == 0 )
      goto LABEL_5;
    goto LABEL_36;
  }
  sub_9404B2FC("chip uid from uboot(id=%d) len=%d:\n", 5, a3);
  v7 = MEMORY[0xFFFFFFFFE003CB98];
  if ( a3 != 0 )
  {
LABEL_36:
    v11 = 0;
    do
    {
      if ( v7 > 1 )
      {
        sub_9404B2FC("%02x ", a2[v11]);
        v7 = MEMORY[0xFFFFFFFFE003CB98];
      }
      ++v11;
    }
    while ( a3 > (unsigned int)v11 );
  }
LABEL_14:
  if ( v7 > 1 )
    sub_9404B2FC("\n");
LABEL_5:
  sub_9404CC78(4100LL * a1 - 536501712, a2, a3);
  *(_DWORD *)(4100LL * a1 - 536497616) = a3;
  result = MEMORY[0xFFFFFFFFE003CB98];
  if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
    return sub_9404B2FC("key[%d] data has been saved!\n", a1);
  return result;
}

/* ===== sub_9402A008 @ 0x9402A008 size 1756 ===== */
__int64 __fastcall sub_9402A008(_DWORD *a1)
{
  __int64 v2; // x19
  unsigned int v4; // w22
  unsigned int v5; // w21
  int v6; // w0
  int v7; // w21
  unsigned int v8; // w23
  unsigned int v9; // w22
  int v10; // w0
  unsigned int v11; // w23
  unsigned int v12; // w22
  int v13; // w0
  unsigned int v14; // w23
  unsigned int v15; // w22
  int v16; // w0
  __int64 v17; // x21
  unsigned int v18; // w0
  char v19; // w21
  __int64 v20; // x0
  __int64 v21; // x21
  unsigned int v22; // w0
  char v23; // w21
  __int64 v24; // x0
  __int64 v25; // [xsp+58h] [xbp+58h] BYREF
  unsigned __int8 *v26[8]; // [xsp+60h] [xbp+60h] BYREF

  if ( a1 != nullptr )
  {
    if ( *a1 == -2113863934 )
    {
      if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      {
        sub_9404B2FC("have got sip smc all from uboot###\n");
        if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
          sub_9404B2FC(" args->params[0] is 0x%x. ###\n", a1[1]);
      }
      switch ( a1[1] )
      {
        case 1:
          return sub_94041258(a1);
        case 3:
          return sub_940418C8(a1);
        case 8:
          return sub_940410E8(a1);
        case 9:
          return (int)sub_9403E3A0(a1);
        case 0xA:
          return sub_9404182C(a1);
        case 0xB:
          return sub_9404195C(a1);
        case 0x20:
          return sub_94047C30(a1);
        case 0x21:
          return sub_94047B0C(a1);
        case 0x22:
          return sub_94040BDC(a1);
        case 0x23:
          return sub_94040CE4(a1);
        case 0x30:
          v2 = 0xFFFFFFFFLL;
          if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
            sub_9404B2FC("enter process_sip_call FUNCTYPE_SET_BINDING_DATA !\n");
          return v2;
        case 0x31:
          if ( MEMORY[0xFFFFFFFFE003CB98] <= 1 )
          {
            v26[0] = nullptr;
            v8 = a1[2];
            v9 = a1[3];
          }
          else
          {
            sub_9404B2FC("enter process_sip_call FUNCTYPE_CRYPTO_DATA !\n");
            v26[0] = nullptr;
            v8 = a1[2];
            v9 = a1[3];
            if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
            {
              sub_9404B2FC("from uboot smc...addr:0x%x len:0x%x\n", v8, v9);
              if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
              {
                sub_9404B2FC("from uboot smc...p[0]:0x%x p1:0x%x p2:0x%x\n", a1[1], a1[2], a1[3]);
                if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
                  sub_9404B2FC("from uboot smc...addr:0x%x len:0x%x\n", v8, v9);
              }
            }
          }
          v10 = sub_940408CC("sprdsec", v8, (v9 & 0xFFFFF000) + 4096, 48, v26);
          v2 = v10;
          if ( v10 != 0 )
            goto LABEL_31;
          v2 = 0;
          sub_94029B68((__int64)v26[0], v9);
          v7 = sub_940408F4(v26[0], v9);
          if ( v7 == 0 )
            return v2;
          goto LABEL_17;
        case 0x32:
          if ( MEMORY[0xFFFFFFFFE003CB98] <= 1 )
          {
            v25 = 0;
            v11 = a1[2];
            v12 = a1[3];
          }
          else
          {
            sub_9404B2FC("enter process_sip_call FUNCTYPE_CHECK_PWD !\n");
            v25 = 0;
            v11 = a1[2];
            v12 = a1[3];
            if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
            {
              sub_9404B2FC("from uboot smc...addr:0x%x len:0x%x\n", v11, v12);
              if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
              {
                sub_9404B2FC("from uboot smc...p[0]:0x%x p1:0x%x p2:0x%x\n", a1[1], a1[2], a1[3]);
                if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
                  sub_9404B2FC("from uboot smc...addr:0x%x len:0x%x\n", v11, v12);
              }
            }
          }
          v13 = sub_940408CC("sprdsec", v11, (v12 & 0xFFFFF000) + 4096, 48, &v25);
          v2 = v13;
          if ( v13 != 0 )
          {
            if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
              sub_9404B2FC("can not map phy addr, ret:%d\n", v13);
            return v2;
          }
          v21 = v25;
          sub_94040888(v26, 0, 64);
          v22 = sub_94040AC4("ab#AB");
          sub_94040880(v26, "ab#AB", v22);
          sub_94029B68(v21, 0x40u);
          sub_94029B68((__int64)v26, 0x40u);
          if ( (unsigned int)sub_94040870(v21, v26, 64) != 0 )
          {
            v23 = 1;
            if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
              sub_9404B2FC("password is incorrect.\n");
          }
          else
          {
            v23 = 0;
            if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
              sub_9404B2FC("check password passed.\n");
          }
          v2 = 0;
          v24 = v25;
          *(_BYTE *)(v25 + 128) = v23;
          v7 = sub_940408F4(v24, v12);
          if ( v7 != 0 )
            goto LABEL_17;
          return v2;
        case 0x33:
          if ( MEMORY[0xFFFFFFFFE003CB98] <= 1 )
          {
            v25 = 0;
            v14 = a1[2];
            v15 = a1[3];
          }
          else
          {
            sub_9404B2FC("enter process_sip_call FUNCTYPE_CHECK_LOCK_STATUS !\n");
            v25 = 0;
            v14 = a1[2];
            v15 = a1[3];
            if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
            {
              sub_9404B2FC("from uboot smc...addr:0x%x len:0x%x\n", v14, v15);
              if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
              {
                sub_9404B2FC("from uboot smc...p[0]:0x%x p1:0x%x p2:0x%x\n", a1[1], a1[2], a1[3]);
                if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
                  sub_9404B2FC("from uboot smc...addr:0x%x len:0x%x\n", v14, v15);
              }
            }
          }
          v16 = sub_940408CC("sprdsec", v14, (v15 & 0xFFFFF000) + 4096, 48, &v25);
          v2 = v16;
          if ( v16 != 0 )
            goto LABEL_31;
          v17 = v25;
          sub_94040888(v26, 0, 64);
          v18 = sub_94040AC4("VerifiedBoot-UNLOCK");
          sub_94040880(v26, "VerifiedBoot-UNLOCK", v18);
          sub_94029B68((__int64)v26, 0x40u);
          if ( (unsigned int)sub_94040870(v17, v26, 64) != 0 )
          {
            v19 = 0;
            if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
              sub_9404B2FC("unlock status isn't matched, return lock.\n");
          }
          else
          {
            v19 = 1;
            if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
              sub_9404B2FC("unlock status is matched, return unlock.\n");
          }
          v2 = 0;
          v20 = v25;
          *(_BYTE *)(v25 + 64) = v19;
          v7 = sub_940408F4(v20, v15);
          if ( v7 != 0 )
            goto LABEL_17;
          return v2;
        case 0x34:
          return sub_940483B8(a1);
        case 0x35:
          return sub_940489D4(a1);
        case 0x40:
          v26[0] = nullptr;
          v4 = a1[2];
          v5 = a1[3];
          if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
            sub_9404B2FC("from uboot smc(set chip uid)...addr:0x%x len:0x%x\n", v4, v5);
          v6 = sub_940408CC("sprdsec", v4, (v5 & 0xFFFFF000) + 4096, 48, v26);
          v2 = v6;
          if ( v6 != 0 )
          {
LABEL_31:
            if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
              sub_9404B2FC("can not map phy addr 1 , ret:%d\n", v2);
          }
          else
          {
            if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
              sub_9404B2FC("get cpu id: 0x%x 0x%x\n", *(_DWORD *)v26[0], *((_DWORD *)v26[0] + 1));
            v2 = 0;
            sub_94029D9C(5u, v26[0], v5);
            v7 = sub_940408F4(v26[0], v5);
            if ( v7 != 0 )
            {
LABEL_17:
              if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
                sub_9404B2FC("can not unmap virt addr, ret:%d\n", v7);
              v2 = v7;
            }
          }
          break;
        default:
          return 0xFFFFFFFFLL;
      }
    }
    else
    {
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    v2 = -1;
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      sub_9404B2FC("args is null###\n");
  }
  return v2;
}

/* ===== sub_9402A6E4 @ 0x9402A6E4 size 264 ===== */
__int64 __fastcall sub_9402A6E4(unsigned int a1, unsigned int a2, unsigned int a3)
{
  int v6; // w19
  __int64 result; // x0
  unsigned __int8 *v8; // [xsp+48h] [xbp+48h] BYREF

  v8 = nullptr;
  if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
    sub_9404B2FC("from uboot smc...addr:0x%x len:0x%x\n", a1, a2);
  v6 = sub_9404A878(-536460256, "sprdsec", 4096, &v8, 12, a1, 0, 48);
  if ( v6 != 0 )
  {
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      sub_9404B2FC("can not map phy addr, ret:%d\n", v6);
    return v6;
  }
  sub_94029D9C(a3, v8, a2);
  v6 = sub_9404ABDC(-536460256, v8);
  result = 0;
  if ( v6 != 0 )
  {
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      sub_9404B2FC("can not unmap virt addr, ret:%d\n", v6);
    return v6;
  }
  return result;
}

/* ===== sub_9402A7EC @ 0x9402A7EC size 164 ===== */
__int64 __fastcall sub_9402A7EC(_DWORD *a1)
{
  __int64 v1; // x19

  if ( a1 == nullptr )
  {
    v1 = -1;
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      sub_9404B2FC("args is null###\n", 0);
    return v1;
  }
  if ( *a1 == 872415262 )
    return sub_9402A6E4(a1[2], a1[3], 1u);
  if ( *a1 != 872415263 )
    return 0xFFFFFFFFLL;
  return sub_9402A6E4(a1[2], a1[3], 2u);
}

/* ===== sub_9402A890 @ 0x9402A890 size 76 ===== */
__int64 sub_9402A890()
{
  __int64 result; // x0

  result = sub_9402D420(0, qword_9405AB30);
  if ( (_DWORD)result != 0 && MEMORY[0xFFFFFFFFE003CB98] > 1 )
    return sub_9404B2FC("can not install std in handler: %d\n", result);
  return result;
}

/* ===== sub_9402A8DC @ 0x9402A8DC size 920 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_9402A8DC(__int64 a1, int a2, unsigned int a3)
{
  unsigned int v3; // w19
  __int64 result; // x0
  __int64 v6; // x0
  __int64 i; // x19
  int v8; // w0
  int v9; // w0
  _QWORD v10[33]; // [xsp+48h] [xbp+48h] BYREF

  if ( a3 != 0 )
  {
    switch ( a2 )
    {
      case 1:
        if ( MEMORY[0xFFFFFFFFE005C234] != 0 )
        {
          sub_9404D224(a3, -536497612, MEMORY[0xFFFFFFFFE005C234]);
          return (unsigned int)MEMORY[0xFFFFFFFFE005C234];
        }
        if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
          sub_9404B2FC("there is no public key yet, give you fake data\n");
        sub_9404CDC4(v10, 255, 264);
        sub_9404D224(a3, v10, 264);
        return 264;
      case 2:
        if ( MEMORY[0xFFFFFFFFE005D238] == 0 )
          return 0xFFFFFFFFLL;
        sub_9404D224(a3, -536493512, MEMORY[0xFFFFFFFFE005D238]);
        return (unsigned int)MEMORY[0xFFFFFFFFE005D238];
      case 3:
        if ( MEMORY[0xFFFFFFFFE005E23C] != 0 )
          goto LABEL_14;
        v10[0] = 0;
        v8 = sub_9404A878(-536460256, "sprdrng", 4096, v10, 12, 2516578304LL, 0, 16);
        if ( v8 != 0 )
        {
          if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
            sub_9404B2FC("can not map sec addr, ret:%d\n", v8);
          return 0xFFFFFFFFLL;
        }
        sub_9404CC78(-536489412, v10[0], 4096);
        MEMORY[0xFFFFFFFFE005E23C] = 4096;
        v9 = sub_9404ABDC(-536460256, v10[0]);
        if ( v9 != 0 )
        {
          if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
            sub_9404B2FC("can not unmap virt addr, ret:%d\n", v9);
          return 0xFFFFFFFFLL;
        }
LABEL_14:
        dword_940676C0 = 1;
        v6 = MEMORY[0xFFFFFFFFE003CB98];
        if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
        {
          sub_9404B2FC("RNG  from kernel is:\n");
          v6 = MEMORY[0xFFFFFFFFE003CB98];
        }
        for ( i = -536489412; i != -536489380; ++i )
        {
          if ( v6 > 1 )
          {
            sub_9404B2FC("%02x", *(unsigned __int8 *)i);
            v6 = MEMORY[0xFFFFFFFFE003CB98];
          }
        }
        if ( v6 > 1 )
          sub_9404B2FC("\n");
        sub_9404D224(a3, -536489412, 32);
        result = 32;
        break;
      case 5:
        if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
          sub_9404B2FC("SEC_CHIP_UID(%d) len: %d\n", 5, MEMORY[0xFFFFFFFFE0060244]);
        if ( MEMORY[0xFFFFFFFFE0060244] == 0 )
          return 0xFFFFFFFFLL;
        sub_9404D224(a3, -536481212, MEMORY[0xFFFFFFFFE0060244]);
        v3 = MEMORY[0xFFFFFFFFE0060244];
        if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
          sub_9404B2FC("got chip id(len=%d)\n", MEMORY[0xFFFFFFFFE0060244]);
        return v3;
      case 6:
        if ( MEMORY[0xFFFFFFFFE0061248] == 0 )
          return 0xFFFFFFFFLL;
        sub_9404D224(a3, -536477112, MEMORY[0xFFFFFFFFE0061248]);
        return (unsigned int)MEMORY[0xFFFFFFFFE0061248];
      default:
        return (unsigned int)-24;
    }
  }
  else
  {
    return (unsigned int)-8;
  }
  return result;
}

/* ===== sub_9402AC74 @ 0x9402AC74 size 340 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_9402AC74()
{
  sub_9404CB4C("initializing ta_manager enter\n");
  qword_94067758 = (__int64)&qword_94067758;
  dword_940677A0 = 0;
  qword_94067760 = (__int64)&qword_94067758;
  sub_94024DFC((__int64)qword_94067728, 0, 1);
  sub_94024DFC((__int64)qword_940676F8, 0, 1);
  sub_94024DFC((__int64)qword_940676C8, 0, 1);
  sub_94024DFC((__int64)qword_940678B8, 0, 1);
  qword_940677D0 = (__int64)&qword_940677D0;
  qword_94067868 = (__int64)&qword_94067868;
  qword_940677D8 = (__int64)&qword_940677D0;
  qword_94067870 = (__int64)&qword_94067868;
  sub_940251C4((__int64)qword_94067768);
  sub_940251C4((__int64)qword_940677E0);
  sub_940251C4((__int64)qword_94067878);
  qword_940677B8 = sub_940268B8((__int64)"ta_manager", (__int64)sub_9402B14C, 0, 0x10u, 4096);
  qword_940677C8 = sub_940268B8((__int64)"ta_manager_unload", (__int64)sub_9402ADC8, 0, 0x10u, 4096);
  sub_9404CB4C("initializing ta_manager thread_resume\n");
  return 0;
}

/* ===== sub_9402ADC8 @ 0x9402ADC8 size 752 ===== */
// write access to const memory has been detected, the output may be wrong!
void __noreturn sub_9402ADC8()
{
  __int64 v0; // x1
  __int64 v1; // x27
  __int64 v2; // x19
  int v3; // w21
  unsigned int v4; // w21
  __int64 v5; // x0
  __int64 v6; // x1
  _QWORD *v7; // x2
  __int64 v8; // [xsp+70h] [xbp+70h]
  __int64 v9; // [xsp+88h] [xbp+88h] BYREF

  v8 = 0;
  sub_9404CB4C("%s:%d: ta_manager_unload_thread_fun enter\n", "ta_manager_unload_thread_fun", 600);
LABEL_2:
  sub_94024EFC((__int64)qword_940676F8, 0xFFFFFFFFLL);
  sub_940250FC((__int64)qword_940676F8);
  while ( 1 )
  {
LABEL_3:
    sub_940251F8((__int64)qword_94067878, 0xFFFFFFFFLL);
    if ( &qword_94067868 == nullptr )
    {
LABEL_15:
      sub_9402530C((__int64)qword_94067878);
      goto LABEL_2;
    }
    while ( 1 )
    {
      v0 = MEMORY[8];
      *MEMORY[8] = MEMORY[0];
      *(_QWORD *)(MEMORY[0] + 8LL) = v0;
      MEMORY[8] = 0;
      MEMORY[0] = 0;
      sub_9402530C((__int64)qword_94067878);
      sub_9404CB4C("%s:%d: look up %s\n", "ta_manager_unload_thread_fun", 614, 16);
      sub_940251F8((__int64)qword_94067768, 0xFFFFFFFFLL);
      v1 = 0;
      if ( &qword_94067758 != nullptr )
      {
        while ( 1 )
        {
          if ( (unsigned int)sub_9404D040(v1 + 40, 16, 64) == 0 )
            goto LABEL_9;
          if ( *(__int64 **)(v1 + 8) == &qword_94067758 )
            break;
          v1 = *(_QWORD *)(v1 + 8);
        }
        sub_9402530C((__int64)qword_94067768);
        sub_9404CC20(0);
      }
      else
      {
        v1 = v8;
LABEL_9:
        sub_9402530C((__int64)qword_94067768);
        sub_9404CC20(0);
        if ( v1 == 0 )
        {
          v8 = 0;
          sub_9404CB4C("%s:%d: static TA\n", "ta_manager_unload_thread_fun", 626);
          goto LABEL_3;
        }
      }
      v2 = ((__int64 (__fastcall *)(_QWORD))loc_9402EB7C)(*(_QWORD *)(v1 + 16));
      v3 = ((__int64 (*)(void))loc_9402EBD8)();
      if ( v3 > (int)sub_9402EC00(v2) )
        break;
      v4 = 0;
      v5 = *(_QWORD *)(*(_QWORD *)(v1 + 16) + 80LL);
      byte_940677C0 = 1;
      dword_94067860 = *(_DWORD *)(v5 + 104);
      while ( 1 )
      {
        v6 = v4++;
        if ( (unsigned int)sub_9402E5B8(v2, v6, &v9) == 0 )
          break;
        if ( v4 == 10 )
          goto LABEL_14;
      }
      sub_9402DADC(v9);
LABEL_14:
      v8 = 0;
      sub_9404CB4C("%s:%d: unload_thread wait for %d\n", "ta_manager_unload_thread_fun", 649, 0);
      sub_94024EFC((__int64)qword_940676C8, 0xFFFFFFFFLL);
      byte_940677C0 = 0;
      sub_940250FC((__int64)qword_940676C8);
      sub_9402E300(v2);
      sub_940251F8((__int64)qword_94067768, 0xFFFFFFFFLL);
      v7 = *(_QWORD **)(v1 + 8);
      *v7 = *(_QWORD *)v1;
      *(_QWORD *)(*(_QWORD *)v1 + 8LL) = v7;
      *(_QWORD *)(v1 + 8) = 0;
      *(_QWORD *)v1 = 0;
      dword_940677A0 = -1;
      sub_9402530C((__int64)qword_94067768);
      sub_9404CC20(*(_QWORD *)(v1 + 24));
      sub_9404CC20(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 88LL));
      sub_9404CC20(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 96LL));
      sub_9404CB4C(
        "%s:%d: will free trusty_app path %s\n",
        "ta_manager_unload_thread_fun",
        663,
        (const char *)(v1 + 40));
      sub_9404CC20(v1);
      sub_940251F8((__int64)qword_94067878, 0xFFFFFFFFLL);
      if ( &qword_94067868 == nullptr )
        goto LABEL_15;
    }
    v8 = v1;
    sub_9404CB4C("%s:%d: list_length %d\n", "ta_manager_unload_thread_fun", 635, v3);
  }
}

/* ===== sub_9402B0B8 @ 0x9402B0B8 size 148 ===== */
__int64 __fastcall sub_9402B0B8(__int64 a1, int a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x19
  __int64 result; // x0
  int v6; // [xsp+28h] [xbp+28h] BYREF
  _QWORD v7[4]; // [xsp+30h] [xbp+30h] BYREF
  int v8; // [xsp+50h] [xbp+50h] BYREF
  _QWORD *v9; // [xsp+58h] [xbp+58h]
  int v10; // [xsp+60h] [xbp+60h]
  __int64 v11; // [xsp+68h] [xbp+68h]

  v6 = a2 | 1;
  v7[2] = a3;
  v7[0] = &v6;
  v8 = 2;
  v7[1] = 4;
  v7[3] = a4;
  v9 = v7;
  v10 = 0;
  v11 = 0;
  v4 = (int)sub_94030F50(a1, &v8);
  result = 0;
  if ( v4 < 0 )
  {
    sub_9404CB4C("%s:%d: failed (%ld) to send_msg\n", "ta_manager_send_response", 150, v4);
    return v4;
  }
  return result;
}

/* ===== sub_9402B14C @ 0x9402B14C size 2892 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_9402B14C()
{
  unsigned int v0; // w24
  _QWORD *v1; // x25
  __int64 *v2; // x26
  unsigned int v3; // w27
  __int64 v4; // x28
  __int64 v5; // x30
  int *v6; // x21
  __int64 v7; // x19
  _QWORD *v8; // x21
  __int64 v9; // x0
  int v11; // w3
  int v12; // w4
  const char *v13; // x0
  const char *v14; // x1
  __int64 v15; // x2
  int v16; // w3
  int v17; // w1
  int v18; // w3
  __int64 v19; // x3
  char v20; // w3
  unsigned int v21; // w5
  int v22; // w4
  int v23; // w3
  int *v24; // x6
  unsigned int v25; // w3
  __int64 v26; // x0
  __int64 v27; // x2
  int v28; // w0
  int v29; // w3
  int v30; // w1
  int v31; // w1
  unsigned int v32; // w3
  __int64 v33; // x0
  unsigned int v34; // w0
  __int64 *i; // x3
  _QWORD *v36; // x1
  _QWORD *v37; // x2
  __int64 v38; // x0
  int v39; // w2
  __int64 v40; // x3
  _QWORD *v41; // x3
  _QWORD *v42; // x2
  __int64 v43; // x0
  unsigned int v44; // w3
  __int64 v45; // [xsp+70h] [xbp+70h]
  __int64 v46; // [xsp+80h] [xbp+80h]
  __int64 v47; // [xsp+80h] [xbp+80h]
  __int64 *v48; // [xsp+88h] [xbp+88h]
  __int64 v49; // [xsp+88h] [xbp+88h]
  _DWORD *v50; // [xsp+90h] [xbp+90h]
  int *v51; // [xsp+98h] [xbp+98h]
  __int64 v52; // [xsp+98h] [xbp+98h]
  _QWORD *v53; // [xsp+98h] [xbp+98h]
  __int64 v54; // [xsp+A0h] [xbp+A0h]
  int v55; // [xsp+A0h] [xbp+A0h]
  int v56; // [xsp+A0h] [xbp+A0h]
  __int64 v57; // [xsp+A0h] [xbp+A0h]
  __int64 v58; // [xsp+A0h] [xbp+A0h]
  int v59; // [xsp+A0h] [xbp+A0h]
  int v60; // [xsp+A0h] [xbp+A0h]
  __int64 v61; // [xsp+A8h] [xbp+A8h]
  unsigned int v62; // [xsp+B8h] [xbp+B8h] BYREF
  unsigned int v63; // [xsp+BCh] [xbp+BCh]
  __int64 v64; // [xsp+C0h] [xbp+C0h] BYREF
  __int64 v65; // [xsp+C8h] [xbp+C8h] BYREF
  unsigned int v66; // [xsp+D0h] [xbp+D0h]
  int v67; // [xsp+D4h] [xbp+D4h]
  _QWORD v68[2]; // [xsp+E0h] [xbp+E0h] BYREF
  int v69; // [xsp+F0h] [xbp+F0h] BYREF
  _QWORD *v70; // [xsp+F8h] [xbp+F8h]
  int v71; // [xsp+100h] [xbp+100h]
  __int64 v72; // [xsp+108h] [xbp+108h]

  v6 = (int *)"ta_manager_thread_fun";
  v7 = v5;
  sub_9404CB4C("%s:%d: ta_manager_thread_fun enter\n", "ta_manager_thread_fun", 541);
  qword_9405ABA0 = sub_9404CBDC(1, 8LL * MEMORY[0xFFFFFFFFE006124C]);
  sub_9404B508(v7, "allocate app local storage failed\n");
LABEL_79:
  v54 = -5;
  sub_9404CB4C("%s:%d: ta_manager_wait_load calloc(%d) failed!\n", "ta_manager_wait_load", 222, 68);
  v16 = -5;
LABEL_22:
  sub_9404CB4C("%s:%d: ta_manager_handle_request failed %d!\n", "ta_manager_handle_msg", 458, v16);
  v17 = *v6;
  v65 = v54;
  v18 = sub_9402B0B8(v64, v17, (__int64)&v65, 8u);
  v12 = v18;
  if ( v18 < 0 )
  {
    v55 = v18;
    sub_9404CB4C("%s:%d: ta_manager_send_error_response failed %d!\n", "ta_manager_handle_msg", 461, v18);
    v12 = v55;
  }
LABEL_24:
  v56 = v12;
  sub_9404CC20(v6);
  sub_940312C8(v64, v63);
  v19 = v56;
  if ( v56 == 0 )
  {
LABEL_25:
    v20 = v67;
    goto LABEL_26;
  }
LABEL_31:
  sub_9404CB4C("%s:%d: failed (%ld) to handle event on %d\n", "ta_manager_handle_channel", 523, v19, v66);
  sub_9402EA68(*(_QWORD *)(v7 + 1960), v3);
  v20 = v67;
LABEL_26:
  if ( (v20 & 4) != 0 )
  {
LABEL_9:
    sub_9404CB4C("%s:%d: closed by peer\n", "ta_manager_handle_channel", 530);
    sub_9402EA68(*(_QWORD *)(v7 + 1960), v3);
  }
  while ( 1 )
  {
    v8 = (_QWORD *)(v7 + 1960);
    v9 = sub_9402EA9C(*(_QWORD *)(v7 + 1960), qword_9405AB48, 0xFFFFFFFFLL);
    if ( v9 < 0 )
      break;
    if ( v9 == 0 )
    {
      v3 = v66;
      if ( v66 == v0 )
      {
        if ( (v67 & 0x1E) != 0 )
        {
          sub_9404CB4C("%s:%d: error event (0x%x) for port (%d)\n", "ta_manager_handle_port", 490, v67, v0);
        }
        else if ( (v67 & 1) != 0 )
        {
          v11 = sub_94030A18(*v8, v0, &v69);
          if ( v11 < 0 )
            sub_9404CB4C("%s:%d: failed (%d) to accept on port %d\n", "ta_manager_handle_port", 499, v11, v66);
        }
      }
      else if ( (v67 & 3) != 0 )
      {
        sub_9404CB4C("%s:%d: error event (0x%x) for chan (%d)\n", "ta_manager_handle_channel", 513, v67, v66);
      }
      else
      {
        if ( (v67 & 8) != 0 )
        {
          if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, __int64 *))loc_9402E4E4)(*v8, v66, &v64) != 0 )
          {
            sub_9404CB4C("%s:%d: uctx_handle_get failed %d!\n", "ta_manager_handle_msg", 424, v3);
            v19 = -2;
            goto LABEL_31;
          }
          if ( (unsigned int)sub_940311BC(v64, &v62) == -4 )
            goto LABEL_25;
          v6 = (int *)sub_9404CBDC(v62, 1);
          if ( v6 == nullptr )
          {
            sub_9404CB4C("%s:%d: ta_manager_handle_msg: no message!\n", "ta_manager_handle_msg", 436);
            sub_940312C8(v64, v63);
            v19 = -5;
            goto LABEL_31;
          }
          v68[1] = v62;
          v69 = 1;
          v68[0] = v6;
          v70 = v68;
          v71 = 0;
          v72 = 0;
          v12 = sub_94031564(v64, v63, 0, &v69);
          if ( (v12 & 0x80000000) == 0 )
          {
            switch ( *v6 )
            {
              case 2:
                v50 = (_DWORD *)sub_9404CBDC(8, 1);
                if ( v50 != nullptr )
                  goto LABEL_52;
                v13 = "%s:%d: ta_manager_initilze calloc(%d) failed!\n";
                v14 = "ta_manager_initilze";
                v15 = 168;
                goto LABEL_21;
              case 4:
                v50 = (_DWORD *)sub_9404CBDC(8, 1);
                if ( v50 != nullptr )
                {
LABEL_52:
                  v31 = *v6;
                  v32 = 8;
                  goto LABEL_53;
                }
                v13 = "%s:%d: ta_manager_terminate calloc(%d) failed!\n";
                v14 = "ta_manager_terminate";
                v15 = 182;
LABEL_21:
                v54 = -5;
                sub_9404CB4C(v13, v14, v15, 8);
                v16 = -5;
                goto LABEL_22;
              case 6:
                v33 = sub_9404CBDC(1, 68);
                v50 = (_DWORD *)v33;
                if ( v33 == 0 )
                  goto LABEL_79;
                v45 = v33 + 4;
                do
                {
LABEL_43:
                  while ( 1 )
                  {
                    sub_94024EFC((__int64)qword_94067728, 0xFFFFFFFFLL);
                    sub_940251F8(v4, 0xFFFFFFFFLL);
                    v57 = v1[1];
                    if ( (_QWORD *)v57 != v1 )
                      break;
                    sub_9402530C(v4);
                    sub_940250FC((__int64)qword_94067728);
                  }
                  sub_9402530C(v4);
                  sub_940250FC((__int64)qword_94067728);
                }
                while ( v57 == 0 );
                v52 = v57 + 16;
                sub_9404CB4C("%s:%d: ta_manager_wait_load %s\n", "ta_manager_wait_load", 235, (const char *)(v57 + 16));
                v34 = sub_9404CFF4(v57 + 16);
                *v50 = v34;
                sub_9404CC78(v45, v57 + 16, v34);
                v46 = (unsigned int)*v50;
                sub_940251F8(v61, 0xFFFFFFFFLL);
                for ( i = (__int64 *)v2[1]; i != v2; i = (__int64 *)v48[1] )
                {
                  v48 = i;
                  if ( (unsigned int)sub_9404D040(i + 5, v52, v46) == 0 )
                  {
                    sub_9402530C(v61);
                    sub_9404CB4C("%s:%d: %s is existing\n", "ta_manager_wait_load", 242, v52);
                    sub_94033ED8(v52, *(_QWORD *)(v57 + 80), *(unsigned int *)(v57 + 88));
                    sub_940251F8(v4, 0xFFFFFFFFLL);
                    v36 = (_QWORD *)v1[1];
                    if ( v36 == v1 )
                    {
                      sub_9402530C(v4);
                    }
                    else
                    {
                      v37 = (_QWORD *)v36[1];
                      v58 = v1[1];
                      *v37 = *v36;
                      *(_QWORD *)(*v36 + 8LL) = v37;
                      v36[1] = 0;
                      *v36 = 0;
                      sub_9402530C(v4);
                      sub_9404CC20(v58);
                    }
                    goto LABEL_43;
                  }
                }
                sub_9402530C(v61);
                v12 = sub_9402B0B8(v64, *v6, (__int64)v50, 0x44u);
                if ( v12 < 0 )
                  goto LABEL_57;
                goto LABEL_54;
              case 14:
                if ( v62 == 4 )
                {
                  v54 = -8;
                  sub_9404CB4C("%s:%d: ta_manager_write_ta: invalid parameters!\n", "ta_manager_write_ta", 272);
                  v16 = -8;
                  goto LABEL_22;
                }
                v21 = v6[1];
                v22 = v6[3];
                if ( v21 == 0 || v22 == 0 )
                {
                  v54 = -8;
                  sub_9404CB4C(
                    "%s:%d: write_ta: total_size %d, payload_len = %d\n",
                    "ta_manager_write_ta",
                    281,
                    v21,
                    v22);
                  v16 = -8;
                  goto LABEL_22;
                }
                v23 = v6[2];
                if ( v21 < v23 + v22 )
                {
                  v54 = -8;
                  sub_9404CB4C(
                    "%s:%d: write_ta: pos %d, payload_len = %d, total_size = %d\n",
                    "ta_manager_write_ta",
                    288,
                    v23,
                    v22,
                    v21);
                  v16 = -8;
                  goto LABEL_22;
                }
                v50 = (_DWORD *)sub_9404CBDC(1, 4);
                v24 = v6 + 1;
                if ( v50 == nullptr )
                {
                  v54 = -5;
                  sub_9404CB4C("%s:%d: write_ta:wresq calloc(%d) failed!\n", "ta_manager_write_ta", 294, 4);
                  v16 = -5;
                  goto LABEL_22;
                }
                v25 = v6[2];
                if ( v25 != 0 )
                {
                  v26 = MEMORY[0x18];
                }
                else
                {
                  sub_9404CB4C("%s:%d: ta_manager_write_ta: new ta!\n", "ta_manager_write_ta", 299);
                  v43 = sub_9404CBDC(1, 112);
                  off_940677B0 = (_UNKNOWN *)v43;
                  if ( v43 == 0 )
                  {
                    v54 = -5;
                    sub_9404CB4C("%s:%d: write_ta: ta calloc(%d) failed!\n", "ta_manager_write_ta", 303, 112);
                    sub_9404CC20(v50);
                    v16 = -5;
                    goto LABEL_22;
                  }
                  v44 = v6[1];
                  *(_QWORD *)(v43 + 8) = v43;
                  *(_QWORD *)v43 = v43;
                  *(_BYTE *)(v43 + 104) = 0;
                  *(_DWORD *)(v43 + 32) = v44;
                  *(_QWORD *)(v43 + 24) = sub_9404CBCC(4096, v44);
                  v26 = MEMORY[0x18];
                  if ( MEMORY[0x18] == 0 )
                  {
                    v54 = -5;
                    sub_9404CB4C(
                      "%s:%d: write_ta: image malloc(%d) failed!\n",
                      "ta_manager_write_ta",
                      313,
                      MEMORY[0x20]);
                    sub_9404CC20(0);
                    sub_9404CC20(v50);
                    v16 = -5;
                    off_940677B0 = nullptr;
                    goto LABEL_22;
                  }
                  v24 = v6 + 1;
                  v25 = v6[2];
                }
                v51 = v24;
                sub_9404CC78(v26 + v25, v6 + 4, (unsigned int)v24[2]);
                v27 = 0;
                v28 = v51[2];
                v29 = MEMORY[0x20];
                MEMORY[0x24] += v28;
                v30 = MEMORY[0x24];
                *v50 = v28;
                if ( v30 == v29 )
                {
                  *(_QWORD *)(v27 + 16) = sub_9402CF10(MEMORY[0x18]);
                  if ( MEMORY[0x10] != 0 )
                    sub_9402D228();
                  sub_94024EFC((__int64)qword_940678B8, 0xFFFFFFFFLL);
                  sub_940251F8(v4, 0xFFFFFFFFLL);
                  v47 = v1[1];
                  if ( (_QWORD *)v47 == v1 )
                  {
                    sub_9402530C(v4);
                    sub_9404CB4C(
                      "%s:%d: ta_manager_write_ta, load %s accomplished!\n",
                      "ta_manager_write_ta",
                      352,
                      (const char *)qword_94067820);
                    sub_940250FC((__int64)qword_940678B8);
                  }
                  else
                  {
                    sub_9402530C(v4);
                    sub_9404CB4C(
                      "%s:%d: ta_manager_write_ta, load %s accomplished!\n",
                      "ta_manager_write_ta",
                      352,
                      (const char *)qword_94067820);
                    sub_940250FC((__int64)qword_940678B8);
                    if ( v47 != 0 )
                    {
                      v38 = sub_9404CFF4(v47 + 16);
                      if ( (unsigned int)sub_9404D040(qword_94067820, v47 + 16, v38) == 0 )
                      {
                        sub_94033ED8(v47 + 16, *(_QWORD *)(v47 + 80), *(unsigned int *)(v47 + 88));
                        sub_940251F8(v4, 0xFFFFFFFFLL);
                        v41 = (_QWORD *)v1[1];
                        if ( v41 == v1 )
                        {
                          sub_9402530C(v4);
                        }
                        else
                        {
                          v42 = (_QWORD *)v41[1];
                          v49 = v1[1];
                          *v42 = *v41;
                          *(_QWORD *)(*v41 + 8LL) = v42;
                          v41[1] = 0;
                          *v41 = 0;
                          v53 = v41 + 2;
                          sub_9402530C(v4);
                          sub_9404CC78(40, v53, 64);
                          sub_9404CC20(v49);
                        }
                      }
                    }
                  }
                  MEMORY[0x68] = 1;
                  sub_940251F8(v61, 0xFFFFFFFFLL);
                  v39 = *((_DWORD *)v2 + 18) + 1;
                  MEMORY[0] = *v2;
                  MEMORY[8] = v2;
                  v40 = *v2;
                  *v2 = 0;
                  *(_QWORD *)(v40 + 8) = 0;
                  *((_DWORD *)v2 + 18) = v39;
                  sub_9402530C(v61);
                  off_940677B0 = nullptr;
                }
                v31 = *v6;
                v32 = 4;
LABEL_53:
                v12 = sub_9402B0B8(v64, v31, (__int64)v50, v32);
                if ( (v12 & 0x80000000) == 0 )
                {
LABEL_54:
                  v59 = v12;
                  sub_9404CC20(v50);
                  v12 = v59;
                  goto LABEL_24;
                }
LABEL_57:
                v60 = v12;
                sub_9404CB4C("%s:%d: ta_manager_send_response failed %d!\n", "ta_manager_handle_msg", 467, v12);
                v12 = v60;
                if ( v50 != nullptr )
                  goto LABEL_54;
                break;
              default:
                v12 = sub_9402B0B8(v64, *v6, 0, 0);
                if ( (v12 & 0x80000000) == 0 )
                  goto LABEL_24;
                v50 = nullptr;
                goto LABEL_57;
            }
          }
          goto LABEL_24;
        }
        if ( (v67 & 4) != 0 )
          goto LABEL_9;
      }
    }
  }
  sub_9404CB4C("%s:%d: uctx_wait_any failed %ld\n", "ta_manager_thread_fun", 571, v9);
  sub_9404CB4C("%s:%d: ta_manager_thread_fun exit\n", "ta_manager_thread_fun", 584);
  sub_9404CC20(0);
  sub_9402E300(*(_QWORD *)(v7 + 1960));
  return 0;
}

/* ===== sub_9402BC98 @ 0x9402BC98 size 108 ===== */
void __spoils<> sub_9402BC98()
{
  ;
}

/* ===== sub_9402BD04 @ 0x9402BD04 size 164 ===== */
const char *__fastcall sub_9402BD04(const char *result, unsigned int a2)
{
  const char *v2; // x20

  if ( a2 <= 0x3F && &qword_940677D0 != nullptr )
  {
    v2 = result;
    sub_9404CB4C("%s:%d:  %s\n", "tam_port_publish", 695, result);
    sub_9404CDC4(qword_94067820, 0, 64);
    sub_9404CC78(qword_94067820, v2, a2);
    return (const char *)sub_94024FDC((__int64)qword_940678B8, 0);
  }
  return result;
}

/* ===== sub_9402BDA8 @ 0x9402BDA8 size 244 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_9402BDA8(const char *a1, __int64 a2, int a3)
{
  __int64 v6; // x19
  __int64 v7; // x0

  sub_9404CB4C("%s:%d:  %s\n", "tam_load_request", 707, a1);
  v6 = sub_9404CBDC(1, 96);
  if ( v6 == 0 )
    return sub_9404CB4C("%s:%d:  calloc failed!\n", "tam_load_request", 711);
  v7 = sub_9404CFF4(a1);
  sub_9404CC78(v6 + 16, a1, v7);
  *(_QWORD *)(v6 + 80) = a2;
  *(_DWORD *)(v6 + 88) = a3;
  *(_QWORD *)(v6 + 8) = v6;
  *(_QWORD *)v6 = v6;
  sub_940251F8((__int64)qword_940677E0, 0xFFFFFFFFLL);
  *(_QWORD *)v6 = 0;
  *(_QWORD *)(v6 + 8) = &qword_940677D0;
  MEMORY[8] = v6;
  qword_940677D0 = v6;
  sub_9402530C((__int64)qword_940677E0);
  return sub_94024FDC((__int64)qword_94067728, 0);
}

/* ===== sub_9402BE9C @ 0x9402BE9C size 236 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_9402BE9C(const char *a1, __int64 a2)
{
  _QWORD *v4; // x19
  __int64 v5; // x0

  sub_9404CB4C("%s:%d:  %s\n", "tam_unload_request", 728, a1);
  v4 = (_QWORD *)sub_9404CBDC(1, 96);
  if ( v4 == nullptr )
    return sub_9404CB4C("%s:%d:  calloc failed!\n", "tam_unload_request", 732);
  v5 = sub_9404CFF4(a1);
  sub_9404CC78(v4 + 2, a1, v5);
  v4[10] = a2;
  v4[1] = v4;
  *v4 = v4;
  sub_940251F8((__int64)qword_94067878, 0xFFFFFFFFLL);
  *v4 = 0;
  v4[1] = &qword_94067868;
  MEMORY[8] = v4;
  qword_94067868 = (__int64)v4;
  sub_9402530C((__int64)qword_94067878);
  return sub_94024FDC((__int64)qword_940676F8, 1u);
}

/* ===== sub_9402BF88 @ 0x9402BF88 size 36 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_9402BF88()
{
  sub_9404CB4C("initializing trusty (%s)\n", (const char *)0xFFFFFFFFE003CCC8LL);
  qword_940678F8 = MEMORY[0xFFFFFFFFE03DF028];
  qword_94067910 = -536457216;
  dword_94067908 = MEMORY[0xFFFFFFFFE03DF028] + 536457216;
  sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
  byte_94067904 = 1;
  sub_9402530C((__int64)"xtum");
  if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
    sub_9404B2FC("trusty_app: start %p size 0x%08x end %p\n", nullptr, 0, nullptr);
  return 0;
}

/* ===== sub_9402BFAC @ 0x9402BFAC size 1136 ===== */
__int64 __fastcall sub_9402BFAC(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v3; // w1
  unsigned __int64 v4; // x22
  unsigned __int64 v5; // x21
  unsigned __int64 v6; // x24
  unsigned __int64 v7; // x23
  unsigned int v8; // w19
  __int64 v9; // x7
  _DWORD *v10; // x26
  unsigned int v11; // w0
  unsigned int v12; // w0
  __int64 v13; // x28
  __int64 v14; // x0
  int v15; // w3
  __int64 v16; // x28
  int v17; // w5
  int v18; // w3
  int v19; // w4
  unsigned __int64 v20; // x28
  __int64 v21; // x0
  unsigned int v22; // w0
  unsigned __int64 v23; // x1
  unsigned int v24; // w1
  __int64 v25; // x3
  unsigned __int64 v26; // x0
  unsigned int v27; // w2
  unsigned __int64 v28; // x1
  __int64 v29; // x2
  unsigned __int64 v30; // x1
  unsigned __int64 v31; // x0
  __int64 v32; // x19
  unsigned int v33; // w19
  __int64 v35; // x0
  __int64 v36; // x19
  __int64 v37; // x0
  __int64 v38; // x1
  __int64 v39; // x0
  __int64 v40; // [xsp+68h] [xbp+68h]
  __int64 v41; // [xsp+88h] [xbp+88h]
  __int64 v42; // [xsp+98h] [xbp+98h] BYREF
  __int64 v43; // [xsp+A0h] [xbp+A0h] BYREF
  __int64 v44; // [xsp+A8h] [xbp+A8h] BYREF

  v1 = *(_QWORD *)(a1 + 72);
  v3 = *(unsigned __int16 *)(v1 + 44);
  v4 = 0;
  v5 = -1;
  v6 = 0;
  v7 = 0;
  if ( *(_WORD *)(v1 + 44) != 0 )
  {
    v8 = 0;
    v9 = 0x7FFF;
    while ( 1 )
    {
      v10 = (_DWORD *)(v1 + *(unsigned int *)(v1 + 28) + 32LL * v8);
      if ( *v10 != 1 )
        goto LABEL_3;
      v11 = v10[2];
      if ( v11 <= (unsigned int)v9 || *(_QWORD *)a1 <= (unsigned __int64)v11 )
        goto LABEL_3;
      if ( (v11 & 0xFFF) != 0 || ((v12 = v10[1]) & 0xFFF) != 0 )
      {
        sub_9404B508(
          v40,
          "ASSERT FAILED at (%s:%d): %s\n",
          "lk/trusty/lib/trusty/trusty_app.c",
          331,
          "!(prg_hdr->p_vaddr & PAGE_MASK) && !(prg_hdr->p_offset & PAGE_MASK)");
        goto LABEL_39;
      }
      v41 = v9;
      v13 = (unsigned int)v10[5];
      v14 = sub_9404A248(v1 + v12);
      v15 = v10[6];
      v16 = v13 + 4095;
      v42 = v14;
      v17 = v15 & 1;
      v18 = v15 & 2 | 0x100 | ((v15 & 4) != 0);
      if ( v17 != 0 )
        v19 = 4;
      else
        v19 = 0;
      v20 = v16 & 0xFFFFFFFFFFFFF000LL;
      v21 = *(_QWORD *)(a1 + 80);
      v44 = (unsigned int)v10[2];
      v22 = sub_9404D438(v21, &v44, &v42, v20, v18 | v19 | 0x20u, 4096);
      v9 = v41;
      if ( v22 != 0 )
      {
        v33 = v22;
        if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
          sub_9404B2FC("cannot map the segment\n");
        return v33;
      }
      v23 = (unsigned int)(0x1000000 - *(_DWORD *)(a1 + 48));
      if ( v23 < v20 + v44 )
      {
        v33 = -25;
        if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
          sub_9404B2FC("failed to load trusty_app: (overlaps user stack 0x%lx)\n", v23);
        return v33;
      }
      v24 = v10[2];
      v25 = v24;
      v26 = v24 + v10[4];
      if ( v5 > v24 )
        v5 = v24;
      if ( v4 < v24 )
        v4 = v24;
      if ( v7 < v26 && (v10[6] & 1) != 0 )
        v7 = v24 + v10[4];
      v27 = v10[5];
      if ( v6 < v26 )
        v6 = v24 + v10[4];
      v28 = v27 + v24;
      if ( v28 > *(_QWORD *)(a1 + 8) )
      {
        v39 = (unsigned int)v10[1];
        *(_QWORD *)(a1 + 8) = v28;
        *(_QWORD *)(a1 + 24) = v20 + v25;
        sub_9404CDC4(v1 + v27 + v39, 0, v20 - v27);
        v3 = *(unsigned __int16 *)(v1 + 44);
        v9 = v41;
LABEL_3:
        if ( v3 <= ++v8 )
          break;
      }
      else
      {
        v3 = *(unsigned __int16 *)(v1 + 44);
        if ( v3 <= ++v8 )
          break;
      }
    }
  }
  v29 = *(_QWORD *)(a1 + 8);
  v30 = *(unsigned int *)(a1 + 52);
  v31 = *(_QWORD *)(a1 + 24) - v29;
  *(_QWORD *)(a1 + 16) = v29;
  if ( v31 >= v30 )
  {
LABEL_26:
    v32 = 0x4EC4EC4EC4EC4EC5LL * (a1 >> 3);
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
    {
      sub_9404B2FC("trusty_app %d: code: start 0x%08lx end 0x%08lx\n", v32, v5, v7);
      if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      {
        sub_9404B2FC("trusty_app %d: data: start 0x%08lx end 0x%08lx\n", v32, v4, v6);
        if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
        {
          sub_9404B2FC("trusty_app %d: bss:                end 0x%08lx\n", v32, *(_QWORD *)a1);
          if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
          {
            sub_9404B2FC(
              "trusty_app %d: brk:  start 0x%08lx end 0x%08lx\n",
              v32,
              *(_QWORD *)(a1 + 8),
              *(_QWORD *)(a1 + 24));
            if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
            {
              v33 = 0;
              sub_9404B2FC(
                "trusty_app %d: entry 0x%08lx\n",
                -991146299 * (a1 >> 3),
                *(_QWORD *)(*(_QWORD *)(a1 + 80) + 8LL));
              return v33;
            }
          }
        }
      }
    }
    return 0;
  }
  v35 = sub_9404CBCC(4096, v30);
  v1 = v35;
  if ( v35 != 0 )
  {
    sub_9404CDC4(v35, 0, *(unsigned int *)(a1 + 52));
    v36 = *(_QWORD *)(a1 + 80);
    v43 = *(_QWORD *)(a1 + 24);
    v44 = sub_9404A248(v1);
    if ( (unsigned int)sub_9404D438(v36, &v43, &v44, *(unsigned int *)(a1 + 52), 291, 4096) == 0 )
    {
      v37 = *(_QWORD *)(a1 + 24);
      if ( v37 == v43 )
      {
        v38 = *(unsigned int *)(a1 + 52);
        *(_QWORD *)(a1 + 96) = v1;
        *(_QWORD *)(a1 + 24) = v38 + v37;
        goto LABEL_26;
      }
    }
LABEL_39:
    if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
      sub_9404B2FC("cannot map brk\n");
    sub_9404CC20(v1);
  }
  v33 = -5;
  if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) != 0 )
    return v33;
  sub_9404B2FC("failed to load trusty_app: trusty_app heap creation error\n");
  return 4294967291LL;
}

/* ===== sub_9402C41C @ 0x9402C41C size 916 ===== */
__int64 __fastcall sub_9402C41C(__int64 a1, __int64 a2, unsigned int a3, _DWORD *a4)
{
  __int64 v4; // x30
  __int64 v7; // x22
  __int64 v8; // x20
  __int64 *v9; // x21
  __int64 result; // x0
  unsigned int v11; // w4
  __int64 v12; // x0
  unsigned int v13; // w3
  int v14; // w2
  unsigned int v15; // w3
  unsigned int v16; // w2
  __int64 *v17; // x21
  unsigned int v18; // w2

  v7 = v4;
  if ( *a4 <= 0xFu )
  {
    sub_9404B508(
      v4,
      "ASSERT FAILED at (%s:%d): %s\n",
      "lk/trusty/lib/trusty/trusty_app.c",
      171,
      "shdr->sh_size >= sizeof(uuid_t)");
LABEL_25:
    sub_9404B508(
      v7,
      "ASSERT FAILED at (%s:%d): %s\n",
      "lk/trusty/lib/trusty/trusty_app.c",
      219,
      "(trusty_app->props.config_entry_cnt - i) > 1");
LABEL_26:
    sub_9404B508(
      v7,
      "ASSERT FAILED at (%s:%d): %s\n",
      "lk/trusty/lib/trusty/trusty_app.c",
      212,
      "(trusty_app->props.config_entry_cnt - i) > 1");
LABEL_27:
    sub_9404B508(
      v7,
      "ASSERT FAILED at (%s:%d): %s\n",
      "lk/trusty/lib/trusty/trusty_app.c",
      226,
      "(trusty_app->props.config_entry_cnt - i) > 3");
LABEL_28:
    sub_9404B508(
      v7,
      "ASSERT FAILED at (%s:%d): %s\n",
      "lk/trusty/lib/trusty/trusty_app.c",
      215,
      "trusty_app->props.min_stack_size > 0");
    return 0;
  }
  else
  {
    v8 = a1 + a3;
    *(_DWORD *)(a2 + 52) = 0x4000;
    v9 = &qword_9405BFF0[2];
    *(_DWORD *)(a2 + 48) = 4096;
    sub_9404CC78(a2 + 32, v8, 16);
    result = MEMORY[0xFFFFFFFFE003CB98];
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      result = sub_9404B2FC(
                 "trusty_app %d uuid: 0x%x 0x%x 0x%x 0x%x%x 0x%x%x%x%x%x%x\n",
                 -991146299 * (unsigned int)(a2 >> 3),
                 *(_DWORD *)(a2 + 32),
                 *(unsigned __int16 *)(a2 + 36),
                 *(unsigned __int16 *)(a2 + 38),
                 *(unsigned __int8 *)(a2 + 40),
                 *(unsigned __int8 *)(a2 + 41),
                 *(unsigned __int8 *)(a2 + 42),
                 *(unsigned __int8 *)(a2 + 43),
                 *(unsigned __int8 *)(a2 + 44),
                 *(unsigned __int8 *)(a2 + 45),
                 *(unsigned __int8 *)(a2 + 46),
                 *(unsigned __int8 *)(a2 + 47));
    v11 = (unsigned int)(*a4 - 16) >> 2;
    *(_DWORD *)(a2 + 60) = v11;
    if ( v11 != 0 )
    {
      v12 = v8 + 16;
      v13 = 0;
      *(_QWORD *)(a2 + 64) = v8 + 16;
      while ( 1 )
      {
        v14 = *(_DWORD *)(v12 + 4LL * v13);
        if ( v14 != 2 )
          break;
        if ( v11 - v13 <= 1 )
          goto LABEL_25;
        v15 = v13 + 1;
        v18 = (*(_DWORD *)(v12 + 4LL * v15) + 4095) & 0xFFFFF000;
        *(_DWORD *)(a2 + 52) = v18;
        if ( v18 == 0 )
        {
          v12 = sub_9404B508(
                  v7,
                  "ASSERT FAILED at (%s:%d): %s\n",
                  "lk/trusty/lib/trusty/trusty_app.c",
                  222,
                  "trusty_app->props.min_heap_size > 0");
LABEL_22:
          if ( v11 - v13 <= 3 )
            goto LABEL_27;
          v15 = v13 + 3;
          ++*(_DWORD *)(a2 + 56);
        }
LABEL_14:
        v13 = v15 + 1;
        if ( v11 <= v13 )
        {
          v17 = (__int64 *)v9[464];
          result = *v17;
          if ( *v17 > 1 )
          {
            sub_9404B2FC("trusty_app %p: stack_sz=0x%x\n", (const void *)a2, *(_DWORD *)(a2 + 48));
            result = *v17;
            if ( *v17 > 1 )
              return sub_9404B2FC("trusty_app %p: heap_sz=0x%x\n", (const void *)a2, *(_DWORD *)(a2 + 52));
          }
          return result;
        }
      }
      if ( v14 != 3 )
      {
        if ( v14 != 1 )
        {
          v9 = (__int64 *)v9[464];
          if ( (*v9 & 0x8000000000000000LL) == 0 )
            sub_9404B2FC("%s: unknown config key: %d\n", "load_app_config_options", v14);
          v12 = sub_9404B508(v7, "ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/trusty_app.c", 234, "0");
        }
        if ( v11 - v13 <= 1 )
          goto LABEL_26;
        v15 = v13 + 1;
        v16 = (*(_DWORD *)(v12 + 4LL * v15) + 4095) & 0xFFFFF000;
        *(_DWORD *)(a2 + 48) = v16;
        if ( v16 == 0 )
          goto LABEL_28;
        goto LABEL_14;
      }
      goto LABEL_22;
    }
  }
  return result;
}

/* ===== sub_9402C7B0 @ 0x9402C7B0 size 120 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_9402C7B0(_QWORD *a1)
{
  sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
  a1[1] = &qword_9405ABE8;
  *a1 = -536630296;
  qword_9405ABE8 = (__int64)a1;
  MEMORY[0xFFFFFFFFE003ABF0] = a1;
  sub_9402530C((__int64)"xtum");
  return 0;
}

/* ===== sub_9402C828 @ 0x9402C828 size 96 ===== */
__int64 sub_9402C828()
{
  unsigned int v0; // w19

  sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
  v0 = ++MEMORY[0xFFFFFFFFE006124C];
  sub_9402530C((__int64)"xtum");
  return v0;
}

/* ===== sub_9402C888 @ 0x9402C888 size 176 ===== */
__int64 __fastcall sub_9402C888(__int64 a1, int a2, __int64 a3, int a4)
{
  unsigned int v4; // w8
  __int64 v5; // x7
  unsigned int v6; // w4
  unsigned int v7; // w5
  unsigned int v8; // w9
  unsigned int v9; // w6
  int v10; // w4
  unsigned int v11; // w3
  __int64 v12; // x0
  __int64 v14; // [xsp+18h] [xbp+18h] BYREF

  v4 = *(_DWORD *)(a1 + 60);
  if ( v4 == 0 )
    return 4294967294LL;
  v5 = *(_QWORD *)(a1 + 64);
  v6 = 0;
  while ( 1 )
  {
    v7 = v6 + 1;
    if ( *(_DWORD *)(v5 + 4LL * v6) == 3 )
    {
      v8 = v6 + 1;
      v7 = v6 + 3;
      v9 = *(_DWORD *)(v5 + 4LL * (v6 + 2));
      v10 = *(_DWORD *)(v5 + 4LL * (v6 + 3));
      if ( *(_DWORD *)(v5 + 4LL * v8) == a2 )
        break;
    }
    v6 = v7 + 1;
    if ( v7 + 1 >= v4 )
      return 4294967294LL;
  }
  v11 = (a4 + 4095) & 0xFFFFF000;
  if ( ((v10 + 4095) & 0xFFFFF000) < v11 )
    return 4294967288LL;
  v12 = *(_QWORD *)(a1 + 80);
  v14 = v9;
  return sub_9404D438(v12, a3, &v14, v11 & 0xFFFFF000, 163, 4096);
}

/* ===== sub_9402CF10 @ 0x9402CF10 size 792 ===== */
__int64 __fastcall sub_9402CF10(__int64 a1, unsigned int a2)
{
  __int64 v5; // x0
  _QWORD *v6; // x21
  __int64 v7; // x2
  __int64 v8; // x24
  unsigned int *v9; // x28
  unsigned int v10; // w23
  unsigned int *v11; // x22
  unsigned int *v12; // x26
  unsigned int v13; // w27
  __int64 v14; // x20
  bool v15; // zf
  unsigned int *v16; // x0
  unsigned int v17; // w0
  unsigned int v18; // w2
  __int64 v19; // x0
  unsigned int *v20; // [xsp+70h] [xbp+70h]
  unsigned int *v21; // [xsp+80h] [xbp+80h]
  __int64 vars0; // [xsp+88h] [xbp+88h]

  if ( MEMORY[0xFFFFFFFFE003CB98] <= 1 )
  {
    if ( a2 == 0 || a1 == 0 )
      return 0;
  }
  else
  {
    sub_9404B2FC("trusty_tapp_bootloader: start %p size 0x%08x end %p\n", (const void *)a1, a2, (const void *)(a1 + a2));
    if ( a2 == 0 || a1 == 0 )
    {
      if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      {
        sub_9404B2FC("trusty_tapp_bootloader:start %p size 0x%08x invalid parameters\n", (const void *)a1, a2);
        return 0;
      }
      return 0;
    }
  }
  v5 = sub_9404CBDC(1, 104);
  v6 = (_QWORD *)v5;
  if ( v5 == 0 )
  {
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
    {
      sub_9404B2FC("trusty_tapp_bootloader: calloc failed!\n");
      return 0;
    }
    return 0;
  }
  sub_9404CDC4(v5, 0, 104);
  if ( (unsigned int)sub_9404D040(a1, &qword_94050A58, 4) != 0 )
  {
    if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
      sub_9404B2FC("trusty_tapp_bootloader: ELF header not found\n");
    sub_9404CC20(v6);
    return 0;
  }
  v7 = *(unsigned int *)(a1 + 32) + a1;
  v8 = a1 + *(unsigned int *)(v7 + 40LL * *(unsigned __int16 *)(a1 + 50) + 16);
  if ( *(_WORD *)(a1 + 48) == 0 )
    goto LABEL_35;
  v9 = (unsigned int *)(*(unsigned int *)(a1 + 32) + a1);
  v10 = 0;
  v21 = nullptr;
  v11 = (unsigned int *)(v7 + 40LL * ((unsigned int)*(unsigned __int16 *)(a1 + 48) - 1) + 40);
  v20 = nullptr;
  v12 = nullptr;
  do
  {
    v13 = v9[1];
    if ( v13 != 0 )
    {
      v14 = v8 + *v9;
      if ( (unsigned int)sub_9404CED8(v14, ".bss") != 0 )
      {
        if ( (unsigned int)sub_9404CED8(v14, ".bss-pad") != 0 )
        {
          v15 = (unsigned int)sub_9404CED8(v14, ".trusty_app.manifest") == 0;
          v16 = v21;
          if ( v15 )
            v16 = v9;
          v21 = v16;
        }
        else
        {
          v20 = v9;
        }
      }
      else
      {
        v12 = v9;
        *v6 = v9[5] + v9[3];
      }
      if ( v13 != 8 && v10 < v9[5] + v9[4] )
        v10 = v9[5] + v9[4];
    }
    v9 += 10;
  }
  while ( v9 != v11 );
  if ( v20 != nullptr && v12 != nullptr && v21 != nullptr )
  {
    v17 = v12[4];
    v18 = v12[5];
    if ( v18 + v17 <= v10 )
    {
      sub_9404CDC4(a1 + v17, 0, v18);
      sub_9402C41C(a1, (__int64)v6, v21[4], v21 + 5);
      v6[9] = a1;
      return (__int64)v6;
    }
  }
  else
  {
LABEL_35:
    sub_9404B508(
      vars0,
      "ASSERT FAILED at (%s:%d): %s\n",
      "lk/trusty/lib/trusty/trusty_app.c",
      748,
      "bss_shdr && bss_pad_shdr && manifest_shdr");
  }
  v19 = sub_9404B508(
          vars0,
          "ASSERT FAILED at (%s:%d): %s\n",
          "lk/trusty/lib/trusty/trusty_app.c",
          751,
          "(bss_shdr->sh_offset + bss_shdr->sh_size) <= trusty_app_max_extent");
  return sub_9402D228(v19);
}

/* ===== sub_9402D228 @ 0x9402D228 size 504 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_9402D228(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x23
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x19
  __int64 (__fastcall *v7)(__int64); // x1
  int v8; // w2
  int v10; // w0
  unsigned int v11; // w2
  __int64 v12; // x20
  unsigned int v13; // w19
  int v14; // w22
  unsigned int v15; // w1
  __int64 v16; // x21
  __int64 v17; // x0
  _BYTE v18[32]; // [xsp+70h] [xbp+40h] BYREF

  v3 = v1;
  if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
    sub_9404B2FC("trusty_tapp_init:\n");
  sub_9404CAC0(
    v18,
    32,
    "trusty_tapp_%d_%08x-%04x-%04x",
    0,
    *(_DWORD *)(a1 + 32),
    *(unsigned __int16 *)(a1 + 36),
    *(unsigned __int16 *)(a1 + 38));
  v4 = sub_9404D7E8(v18, *(unsigned int *)(*(_QWORD *)(a1 + 72) + 24LL), 16, 0x1000000, *(unsigned int *)(a1 + 48), a1);
  if ( v4 == 0 )
    goto LABEL_15;
  *(_QWORD *)(a1 + 80) = v4;
  if ( (unsigned int)sub_9402BFAC(a1) != 0 )
  {
LABEL_14:
    sub_9404B508(v3, "failed to load address map\n");
LABEL_15:
    sub_9404B508(v3, "allocate user thread failed\n");
    goto LABEL_16;
  }
  v5 = sub_9404CBDC(1, 8LL * MEMORY[0xFFFFFFFFE006124C]);
  *(_QWORD *)(a1 + 88) = v5;
  if ( v5 == 0 )
  {
LABEL_13:
    sub_9404B508(v3, "allocate app local storage failed\n");
    goto LABEL_14;
  }
  v6 = -536630296;
  if ( &qword_9405ABE8 != (__int64 *)-536630296LL )
  {
    while ( 1 )
    {
      v7 = *(__int64 (__fastcall **)(__int64))(v6 + 16);
      if ( v7 != nullptr )
      {
        v8 = v7(a1);
        if ( v8 != 0 )
          break;
      }
      v6 = *(_QWORD *)(v6 + 8);
      if ( (__int64 *)v6 == &qword_9405ABE8 )
        goto LABEL_10;
    }
    sub_9404B508(v3, "failed (%d) to invoke startup notifier\n", v8);
    goto LABEL_13;
  }
LABEL_10:
  if ( (unsigned int)sub_9404D324(*(_QWORD *)(a1 + 80)) == 0 )
  {
    dword_940678E8 = 1;
    return 1;
  }
LABEL_16:
  v10 = sub_9404B508(v3, "Cannot start Trusty app!\n");
  v12 = v11;
  v13 = v11;
  v14 = v10;
  v16 = v15;
  if ( (unsigned __int8)sub_9404DC04(*(_QWORD *)(_ReadStatusReg(TPIDR_EL1) + 688), v15, v11) == 0 )
    return 4294967288LL;
  v17 = 2;
  if ( v14 == 2 )
    v17 = 1;
  if ( v17 <= MEMORY[0xFFFFFFFFE003CB98] )
    sub_9404B254(v16, v12);
  return v13;
}

/* ===== sub_9402D420 @ 0x9402D420 size 116 ===== */
__int64 __fastcall sub_9402D420(unsigned int a1, __int64 a2)
{
  unsigned int v4; // w20

  if ( a1 > 9 )
    return 4294967288LL;
  v4 = -14;
  sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
  if ( qword_9405AC48[a1] == 0 )
  {
    qword_9405AC48[a1] = a2;
    v4 = 0;
  }
  sub_9402530C((__int64)"xtum");
  return v4;
}

/* ===== sub_9402D494 @ 0x9402D494 size 64 ===== */
__int64 __fastcall sub_9402D494(unsigned int a1)
{
  __int64 v1; // x3
  __int64 v2; // x4
  int (*v3)(void); // x4

  v1 = -24;
  if ( a1 <= 9 )
  {
    v2 = qword_9405AC48[a1];
    if ( v2 != 0 )
    {
      v3 = *(int (**)(void))(v2 + 8);
      if ( v3 != nullptr )
        return v3();
    }
  }
  return v1;
}

/* ===== sub_9402D4D4 @ 0x9402D4D4 size 56 ===== */
__int64 __fastcall sub_9402D4D4(__int64 result)
{
  _QWORD *v1; // x1

  result = (unsigned int)result;
  v1 = *(_QWORD **)(*(_QWORD *)(_ReadStatusReg(TPIDR_EL1) + 688) + 144LL);
  if ( (unsigned __int64)(unsigned int)result < v1[1] || (unsigned __int64)(unsigned int)result > v1[3] )
    return v1[2];
  v1[2] = (unsigned int)result;
  return result;
}

/* ===== sub_9402D50C @ 0x9402D50C size 116 ===== */
__int64 sub_9402D50C()
{
  const char *StatusReg; // x1
  __int64 v1; // x0
  __int64 v2; // x1
  __int64 v3; // x3
  int (__fastcall **v4)(__int64, __int64); // x4
  int (__fastcall *v5)(__int64, __int64); // x4

  StatusReg = (const char *)_ReadStatusReg(TPIDR_EL1);
  if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
    sub_9404B2FC("exit called, thread %p, name %s\n", StatusReg, StatusReg + 696);
  v1 = sub_9404D33C(0);
  v3 = -24;
  if ( (unsigned int)v1 <= 9 )
  {
    v4 = (int (__fastcall **)(__int64, __int64))qword_9405AC48[(unsigned int)v1];
    if ( v4 != nullptr )
    {
      v5 = *v4;
      if ( v5 != nullptr )
        return v5(v1, v2);
    }
  }
  return v3;
}

/* ===== sub_9402D580 @ 0x9402D580 size 64 ===== */
__int64 __fastcall sub_9402D580(unsigned int a1)
{
  __int64 v1; // x3
  __int64 v2; // x4
  int (*v3)(void); // x4

  v1 = -24;
  if ( a1 <= 9 )
  {
    v2 = qword_9405AC48[a1];
    if ( v2 != 0 )
    {
      v3 = *(int (**)(void))(v2 + 16);
      if ( v3 != nullptr )
        return v3();
    }
  }
  return v1;
}

/* ===== sub_9402D5C0 @ 0x9402D5C0 size 64 ===== */
__int64 __fastcall sub_9402D5C0(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  sub_940263B8(((a4 << 32) + (unsigned __int64)a3 + 999999) / 0xF4240);
  return 0;
}

/* ===== sub_9402D600 @ 0x9402D600 size 92 ===== */
__int64 __fastcall sub_9402D600(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int64 v3; // x0
  __int64 v6; // [xsp+28h] [xbp+28h] BYREF

  if ( MEMORY[0xFFFFFFFFE0047918] != nullptr )
    v3 = MEMORY[0xFFFFFFFFE0047918]();
  else
    v3 = sub_94024A84();
  v6 = 1000 * v3;
  return (int)sub_9404D224(a3, &v6, 8);
}

/* ===== sub_9402D65C @ 0x9402D65C size 84 ===== */
__int64 __fastcall sub_9402D65C(int a1, int a2, int a3, int a4)
{
  bool v4; // zf
  __int64 v5; // x2
  __int64 result; // x0
  __int64 v7; // [xsp+18h] [xbp+18h] BYREF

  v4 = a3 == 1;
  v5 = *(_QWORD *)(*(_QWORD *)(_ReadStatusReg(TPIDR_EL1) + 688) + 144LL);
  if ( !v4 || a1 != 0 )
    return -8;
  result = (int)sub_9402C888(v5, a4, (__int64)&v7, a2);
  if ( (_DWORD)result == 0 )
    return v7;
  return result;
}

/* ===== sub_9402D6B0 @ 0x9402D6B0 size 48 ===== */
__int64 __fastcall sub_9402D6B0(unsigned int a1, unsigned int a2)
{
  return (int)sub_9404DA38(
                *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(_ReadStatusReg(TPIDR_EL1) + 688) + 144LL) + 80LL),
                a1,
                a2);
}

/* ===== sub_9402D6E0 @ 0x9402D6E0 size 8 ===== */
__int64 sub_9402D6E0()
{
  return -24;
}

/* ===== sub_9402D6E8 @ 0x9402D6E8 size 8 ===== */
__int64 sub_9402D6E8()
{
  return -24;
}

/* ===== sub_9402D6F0 @ 0x9402D6F0 size 364 ===== */
__int64 __fastcall sub_9402D6F0(__int64 a1, _QWORD *a2, _DWORD *a3, unsigned __int8 a4)
{
  __int64 v4; // x30
  int v8; // w21
  __int64 v9; // x19
  __int64 v10; // x19
  __int64 v11; // x22
  __int64 v12; // x26
  int v13; // w0
  __int64 v14; // x19
  bool v15; // zf
  unsigned int v17; // w24
  __int64 v18; // x19
  __int64 i; // x19
  __int64 v20; // x19

  v8 = a4;
  if ( *(_QWORD *)(a1 + 72) == 0 )
  {
    sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 272, "hlist->wait_event");
    return 4294967294LL;
  }
  v9 = *(_QWORD *)(a1 + 8);
  if ( a1 == v9 )
    return 4294967294LL;
  v10 = v9 - 80;
  v11 = 0;
  while ( 1 )
  {
    if ( v8 != 0 )
    {
      v12 = *(_QWORD *)(a1 + 72);
      sub_940251F8(v10 + 24, 0xFFFFFFFFLL);
      if ( *(_QWORD *)(v10 + 16) != 0 )
      {
        v17 = -6;
        sub_9402530C(v10 + 24);
        goto LABEL_13;
      }
      *(_QWORD *)(v10 + 16) = v12;
      v11 = v10;
      sub_9402530C(v10 + 24);
    }
    v13 = (**(__int64 (__fastcall ***)(__int64))(v10 + 8))(v10);
    if ( v13 != 0 )
      break;
    v14 = *(_QWORD *)(v10 + 88);
    v15 = a1 == v14;
    v10 = v14 - 80;
    if ( v15 )
      return 0;
  }
  *a3 = v13;
  v17 = 1;
  *a2 = v10;
  if ( v8 == 0 )
    return 1;
LABEL_13:
  if ( v11 != 0 )
  {
    v18 = *(_QWORD *)(a1 + 8);
    v15 = a1 == v18;
    for ( i = v18 - 80; !v15; i = v20 - 80 )
    {
      sub_940251F8(i + 24, 0xFFFFFFFFLL);
      *(_QWORD *)(i + 16) = 0;
      sub_9402530C(i + 24);
      if ( v11 == i )
        break;
      v20 = *(_QWORD *)(i + 88);
      v15 = a1 == v20;
    }
  }
  return v17;
}

/* ===== sub_9402D85C @ 0x9402D85C size 212 ===== */
__int64 __fastcall sub_9402D85C(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  unsigned int v4; // w0
  __int64 result; // x0
  __int64 v6; // x0

  if ( a1 == 0 )
  {
    sub_9404B508(v2, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 45, "handle");
  }
  else if ( a2 != 0 )
  {
    if ( *(_QWORD *)(a2 + 24) == 0 )
    {
LABEL_9:
      v6 = sub_9404B508(v2, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 47, "ops->destroy");
      return sub_9402D930(v6);
    }
    do
      __ldxr((unsigned int *)a1);
    while ( __stxr(0, (unsigned int *)a1) != 0 );
    do
      v4 = __ldxr((unsigned int *)a1);
    while ( __stxr(v4 + 1, (unsigned int *)a1) != 0 );
    *(_QWORD *)(a1 + 8) = a2;
    *(_QWORD *)(a1 + 16) = 0;
    result = sub_940251C4(a1 + 24);
    *(_QWORD *)(a1 + 96) = 0;
    *(_QWORD *)(a1 + 88) = 0;
    *(_QWORD *)(a1 + 80) = 0;
    return result;
  }
  sub_9404B508(v2, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 46, "ops");
  goto LABEL_9;
}

/* ===== sub_9402D930 @ 0x9402D930 size 176 ===== */
__int64 __fastcall sub_9402D930(__int64 result)
{
  __int64 v1; // x30
  unsigned int v2; // w1
  __int64 v3; // x30
  unsigned int v4; // w2
  __int64 v5; // x0

  if ( result != 0 )
  {
    do
      v2 = __ldxr((unsigned int *)result);
    while ( __stxr(v2 + 1, (unsigned int *)result) != 0 );
  }
  else
  {
    result = sub_9404B508(v1, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 67, "handle");
    if ( result != 0 )
    {
      do
        v4 = __ldxr((unsigned int *)result);
      while ( __stxr(v4 - 1, (unsigned int *)result) != 0 );
      if ( v4 == 1 )
        return (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)(result + 8) + 24LL))(
                 result,
                 *(_QWORD *)(*(_QWORD *)(result + 8) + 24LL));
    }
    else
    {
      v5 = sub_9404B508(v3, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 73, "handle");
      return sub_9402D9E0(v5);
    }
  }
  return result;
}

/* ===== sub_9402D9E0 @ 0x9402D9E0 size 252 ===== */
void __fastcall sub_9402D9E0(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x30
  __int64 v5; // x0
  __int64 v6; // x2
  _QWORD *v7; // x1
  __int64 v8; // x0

  v5 = v2;
  if ( a1 != 0 )
  {
    if ( a2 == nullptr )
    {
LABEL_10:
      sub_9404B508(v5, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 204, "handle");
      goto LABEL_11;
    }
    v6 = a2[10];
    v7 = (_QWORD *)a2[11];
    if ( v6 != 0 || v7 != nullptr )
    {
      *v7 = v6;
      v8 = *(_QWORD *)(a1 + 72);
      *(_QWORD *)(a2[10] + 8LL) = v7;
      a2[11] = 0;
      a2[10] = 0;
      if ( v8 == 0
        || (sub_940251F8((__int64)(a2 + 3), 0xFFFFFFFFLL),
            a2[2] = 0,
            sub_9402530C((__int64)(a2 + 3)),
            *(_QWORD *)(a1 + 8) != a1) )
      {
LABEL_12:
        JUMPOUT(0x9402D978LL);
      }
LABEL_11:
      sub_94024FDC(*(_QWORD *)(a1 + 72), 1u);
      goto LABEL_12;
    }
    v5 = sub_9404B508(
           v2,
           "DEBUG ASSERT FAILED at (%s:%d): %s\n",
           "lk/trusty/lib/trusty/handle.c",
           205,
           "list_in_list(&handle->hlist_node)");
  }
  v5 = sub_9404B508(v5, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 203, "hlist");
  goto LABEL_10;
}

/* ===== sub_9402DADC @ 0x9402DADC size 344 ===== */
__int64 __fastcall sub_9402DADC(__int64 a1)
{
  __int64 v1; // x30
  void (*v2)(void); // x1
  __int64 v3; // x0
  unsigned int *v4; // x1
  unsigned int v5; // w2
  __int64 v6; // x19
  unsigned int v7; // w23
  unsigned int *v8; // x24
  unsigned int v9; // w20
  unsigned int v10; // w20
  void (__fastcall *v11)(__int64, _QWORD); // x2
  _BYTE v13[48]; // [xsp+40h] [xbp-30h] BYREF

  if ( a1 != 0 )
  {
    v2 = *(void (**)(void))(*(_QWORD *)(a1 + 8) + 16LL);
    if ( v2 != nullptr )
      v2();
    JUMPOUT(0x9402D978LL);
  }
  v3 = sub_9404B508(v1, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 79, "handle");
  if ( v3 == 0 || v4 == nullptr )
    return 4294967288LL;
  v6 = v3;
  v7 = v5;
  v8 = v4;
  sub_94024DFC((__int64)v13, 0, 1);
  sub_940251F8(v6 + 24, 0xFFFFFFFFLL);
  if ( *(_QWORD *)(v6 + 16) != 0 )
  {
    v9 = -6;
    sub_9402530C(v6 + 24);
  }
  else
  {
    *(_QWORD *)(v6 + 16) = v13;
    sub_9402530C(v6 + 24);
    while ( 1 )
    {
      v10 = (**(__int64 (__fastcall ***)(__int64))(v6 + 8))(v6);
      if ( v10 != 0 )
        break;
      v9 = sub_94024EFC((__int64)v13, v7);
      if ( (v9 & 0x80000000) != 0 )
        goto LABEL_14;
    }
    v11 = *(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)(v6 + 8) + 8LL);
    if ( v11 != nullptr )
      v11(v6, v10);
    *v8 = v10;
    v9 = 0;
LABEL_14:
    sub_940251F8(v6 + 24, 0xFFFFFFFFLL);
    *(_QWORD *)(v6 + 16) = 0;
    sub_9402530C(v6 + 24);
  }
  sub_94024E30((__int64)v13);
  return v9;
}

/* ===== sub_9402DC34 @ 0x9402DC34 size 104 ===== */
__int64 __fastcall sub_9402DC34(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v6; // x0

  if ( a1 != 0 )
  {
    v3 = a1 + 24;
    sub_940251F8(a1 + 24, 0xFFFFFFFFLL);
    v4 = *(_QWORD *)(a1 + 16);
    if ( v4 != 0 )
      sub_94024FDC(v4, 1u);
    return sub_9402530C(v3);
  }
  else
  {
    v6 = sub_9404B508(v1, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 159, "handle");
    return sub_9402DC9C(v6);
  }
}

/* ===== sub_9402DC9C @ 0x9402DC9C size 112 ===== */
_QWORD *__fastcall sub_9402DC9C(_QWORD *result)
{
  __int64 v1; // x30
  __int64 v2; // x0

  if ( result != nullptr )
  {
    result[2] = 0;
    result[3] = 0;
    result[4] = 0;
    result[5] = 0;
    *result = result;
    result[8] = 0;
    result[9] = 0;
    result[1] = result;
    *((_DWORD *)result + 4) = 1836414072;
    *((_DWORD *)result + 10) = 2002872692;
    result[6] = result + 6;
    result[7] = result + 6;
  }
  else
  {
    v2 = sub_9404B508(v1, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 174, "hlist");
    return (_QWORD *)sub_9402DD0C(v2);
  }
  return result;
}

/* ===== sub_9402DD0C @ 0x9402DD0C size 300 ===== */
__int64 __fastcall sub_9402DD0C(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v5; // x22
  __int64 v7; // x0

  if ( a1 == nullptr )
  {
    sub_9404B508(v2, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 181, "hlist");
  }
  else if ( a2 != 0 )
  {
    if ( *(_QWORD *)(a2 + 80) == 0 )
      goto LABEL_5;
    do
    {
      sub_9404B508(
        v2,
        "DEBUG ASSERT FAILED at (%s:%d): %s\n",
        "lk/trusty/lib/trusty/handle.c",
        183,
        "!list_in_list(&handle->hlist_node)");
LABEL_5:
      ;
    }
    while ( *(_QWORD *)(a2 + 88) != 0 );
    sub_9402D930(a2);
    sub_940251F8((__int64)(a1 + 2), 0xFFFFFFFFLL);
    v5 = a1[9];
    *(_QWORD *)(a2 + 80) = *a1;
    *(_QWORD *)(a2 + 88) = a1;
    *(_QWORD *)(*a1 + 8LL) = a2 + 80;
    *a1 = a2 + 80;
    if ( v5 != 0 )
    {
      sub_940251F8(a2 + 24, 0xFFFFFFFFLL);
      if ( *(_QWORD *)(a2 + 16) == 0 )
        *(_QWORD *)(a2 + 16) = v5;
      sub_9402530C(a2 + 24);
      if ( (**(unsigned int (__fastcall ***)(__int64))(a2 + 8))(a2) != 0 )
        sub_9402DC34(a2);
    }
    return sub_9402530C((__int64)(a1 + 2));
  }
  v7 = sub_9404B508(v2, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 182, "handle");
  return sub_9402DE38(v7);
}

/* ===== sub_9402DE38 @ 0x9402DE38 size 856 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_9402DE38(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x30
  __int64 v5; // x21
  __int64 result; // x0
  __int64 *v7; // x1
  unsigned int *v8; // x2
  _QWORD *v9; // x21
  __int64 v10; // x30
  __int64 v11; // x20
  __int64 *v12; // x23
  unsigned int *v13; // x24
  unsigned int v14; // w3
  unsigned int v15; // w19
  int v16; // w0
  unsigned int v17; // w20
  _QWORD *v18; // x19
  bool v19; // zf
  _QWORD *v20; // x19
  __int64 v21; // x19
  void (__fastcall *v22)(__int64, _QWORD); // x2
  _QWORD *v23; // x0
  _QWORD *v24; // x19
  _QWORD *v25; // x19
  __int64 v26; // x30
  __int64 v27; // x19
  int v28; // w2
  int v29; // w2
  __int64 v30; // x0
  _BYTE v31[48]; // [xsp+70h] [xbp-30h] BYREF

  if ( a1 != 0 )
  {
    if ( a2 != nullptr )
    {
      v5 = a1 + 16;
      sub_940251F8(a1 + 16, 0xFFFFFFFFLL);
      sub_9402D9E0(a1, a2);
      return sub_9402530C(v5);
    }
  }
  else
  {
    sub_9404B508(v2, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 224, "hlist");
  }
  v9 = (_QWORD *)sub_9404B508(
                   v2,
                   "DEBUG ASSERT FAILED at (%s:%d): %s\n",
                   "lk/trusty/lib/trusty/handle.c",
                   225,
                   "handle");
  v11 = v10;
  v12 = v7;
  v13 = v8;
  v15 = v14;
  if ( v9 == nullptr )
  {
    sub_9404B508(v10, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 312, "hlist");
  }
  else if ( v7 != nullptr )
  {
    if ( v8 == nullptr )
    {
LABEL_28:
      sub_9404B508(v10, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 314, "event_ptr");
      goto LABEL_29;
    }
    sub_94024DFC((__int64)v31, 0, 1);
    *v13 = 0;
    *v12 = 0;
    sub_940251F8((__int64)(v9 + 2), 0xFFFFFFFFLL);
    if ( v9[9] == 0 )
    {
      v9[9] = v31;
      v16 = sub_9402D6F0((__int64)v9, v12, v13, 1u);
      v17 = v16;
      if ( v16 >= 0 )
      {
        if ( v16 != 0 )
        {
LABEL_11:
          if ( v17 != 1 )
            goto LABEL_12;
        }
        else
        {
          do
          {
            sub_9402530C((__int64)(v9 + 2));
            v17 = sub_94024EFC((__int64)v31, v15);
            sub_940251F8((__int64)(v9 + 2), 0xFFFFFFFFLL);
            if ( (v17 & 0x80000000) != 0 )
            {
              v18 = (_QWORD *)v9[1];
              v19 = v9 == v18;
              v20 = v18 - 10;
              if ( v19 )
                goto LABEL_12;
              goto LABEL_22;
            }
            v17 = sub_9402D6F0((__int64)v9, v12, v13, 0);
          }
          while ( v17 == 0 );
          v24 = (_QWORD *)v9[1];
          v19 = v9 == v24;
          v20 = v24 - 10;
          if ( v19 )
            goto LABEL_11;
          do
          {
LABEL_22:
            sub_940251F8((__int64)(v20 + 3), 0xFFFFFFFFLL);
            v20[2] = 0;
            sub_9402530C((__int64)(v20 + 3));
            v25 = (_QWORD *)v20[11];
            v19 = v9 == v25;
            v20 = v25 - 10;
          }
          while ( !v19 );
          if ( v17 != 1 )
            goto LABEL_12;
        }
        v21 = *v12;
        v22 = *(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)(*v12 + 8) + 8LL);
        if ( v22 != nullptr )
          v22(*v12, *v13);
        v17 = 0;
        sub_9402D930(v21);
        v23 = (_QWORD *)v9[1];
        *v23 = *v9;
        *(_QWORD *)(*v9 + 8LL) = v23;
        v9[1] = 0;
        v9[1] = *(_QWORD *)(v21 + 88);
        *v9 = v21 + 80;
        **(_QWORD **)(v21 + 88) = v9;
        *(_QWORD *)(v21 + 88) = v9;
      }
LABEL_12:
      v9[9] = 0;
      sub_9402530C((__int64)(v9 + 2));
      sub_94024E30((__int64)v31);
      return v17;
    }
LABEL_29:
    sub_9404B508(
      v11,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      "lk/trusty/lib/trusty/handle.c",
      323,
      "hlist->wait_event == NULL");
    v27 = v26;
    v28 = sub_9402C828();
    if ( v28 < 0 )
    {
      sub_9404B508(v27, "failed (%d) to alloc als slot\n", v28);
      goto LABEL_33;
    }
    dword_94067920 = v28;
    result = sub_9402C7B0(qword_9405AC98);
    v29 = result;
    if ( (result & 0x80000000) != 0 )
    {
LABEL_33:
      v30 = sub_9404B508(v27, "failed (%d) to register uctx notifier\n", v29);
      return sub_9402E190(v30);
    }
    return result;
  }
  sub_9404B508(v10, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/handle.c", 313, "handle_ptr");
  goto LABEL_28;
}

/* ===== sub_9402E190 @ 0x9402E190 size 232 ===== */
__int64 sub_9402E190()
{
  __int64 v0; // x30
  __int64 v1; // x0
  __int64 v2; // x30
  __int64 *v3; // x1
  __int64 *v4; // x20
  __int64 v5; // x21
  __int64 v6; // x0
  __int64 v7; // x19

  _ReadStatusReg(TPIDR_EL1);
  v1 = sub_9404B508(
         v0,
         "ASSERT FAILED at (%s:%d): %s\n",
         "lk/trusty/lib/tam/../trusty/include/lib/trusty/trusty_app.h",
         102,
         "slot < als_slot_cnt");
  v4 = v3;
  v5 = v1;
  if ( v3 == nullptr )
  {
    sub_9404B508(v2, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 164, "ctx");
    return 4294967291LL;
  }
  v6 = sub_9404CBDC(1, 616);
  v7 = v6;
  if ( v6 == 0 )
    return 4294967291LL;
  *(_QWORD *)(v6 + 520) = v5;
  sub_9402DC9C((_QWORD *)(v6 + 528));
  *v4 = v7;
  return 0;
}

/* ===== sub_9402E278 @ 0x9402E278 size 136 ===== */
__int64 sub_9402E278()
{
  __int64 v0; // x30
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v3; // x0

  v1 = v0;
  result = ((__int64 (*)(void))loc_9402E1F8)();
  if ( (_DWORD)result == 0 )
  {
    v3 = sub_9404B508(
           v1,
           "ASSERT FAILED at (%s:%d): %s\n",
           "lk/trusty/lib/tam/../trusty/include/lib/trusty/trusty_app.h",
           109,
           "slot < als_slot_cnt");
    return sub_9402E300(v3);
  }
  return result;
}

/* ===== sub_9402E300 @ 0x9402E300 size 696 ===== */
__int64 __fastcall sub_9402E300(__int64 a1)
{
  __int64 v1; // x30
  __int64 *v3; // x19
  __int64 *v4; // x20
  _QWORD *v6; // x0
  __int64 v7; // x1
  _DWORD *v8; // x2
  __int64 v9; // x30
  int v10; // w3
  int v11; // w19
  unsigned int *v12; // x4
  unsigned int v13; // w2
  _QWORD *v14; // x0
  unsigned int v15; // w1
  _QWORD *v16; // x2
  __int64 v17; // x30
  _QWORD *v18; // x1
  __int64 v19; // x19
  _QWORD *v20; // [xsp+28h] [xbp-38h]
  _DWORD *v21; // [xsp+58h] [xbp-8h]

  v3 = (__int64 *)(a1 + 8);
  v4 = (__int64 *)(a1 + 520);
  if ( a1 != 0 )
  {
    do
    {
      if ( *v3 != 0 )
      {
        sub_9404CB4C("%s:%d: destroying a non-empty uctx!!!\n", "uctx_destroy", 191);
        sub_9402DE38(a1 + 528, (_QWORD *)*v3);
        sub_9402DADC(*v3);
        *v3 = 0;
      }
      ++v3;
    }
    while ( v3 != v4 );
    return sub_9404CC20(a1);
  }
  v6 = (_QWORD *)sub_9404B508(v1, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 187, "ctx");
  if ( v6 == nullptr )
  {
    sub_9404B508(v9, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 218, "ctx");
  }
  else if ( v7 != 0 )
  {
    if ( v8 == nullptr )
    {
LABEL_17:
      sub_9404B508(v9, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 220, "id");
      goto LABEL_18;
    }
    if ( *v6 == -1 )
      return 4294967255LL;
    v10 = __clz(__rbit64(~*v6)) + 1;
    v11 = v10 - 1;
    if ( v6[v10] == 0 )
    {
      v21 = v8;
      v12 = (unsigned int *)((char *)v6 + (((__int64)v11 >> 3) & 0x1FFFFFFFFFFFFFFCLL));
      do
        v13 = __ldxr(v12);
      while ( __stxr(v13 | (1 << v11), v12) != 0 );
      v6[v10] = v7;
      sub_9402DD0C(v6 + 66, v7);
      *v21 = v11;
      return 0;
    }
LABEL_18:
    v14 = (_QWORD *)sub_9404B508(
                      v9,
                      "ASSERT FAILED at (%s:%d): %s\n",
                      "lk/trusty/lib/trusty/uctx.c",
                      226,
                      "ctx->handles[new_id] == NULL");
    if ( v14 == nullptr )
    {
      sub_9404B508(v17, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 242, "ctx");
    }
    else if ( v16 != nullptr )
    {
      if ( v15 > 0x3F )
        return 4294967254LL;
      if ( ((*v14 >> v15) & 1) != 0 )
      {
        v18 = &v14[v15];
        v19 = v18[1];
        if ( v19 != 0 )
        {
          v20 = v16;
          sub_9402D930(v18[1]);
          *v20 = v19;
          return 0;
        }
        sub_9404B508(
          v17,
          "ASSERT FAILED at (%s:%d): %s\n",
          "lk/trusty/lib/trusty/uctx.c",
          134,
          "ctx->handles[handle_id]");
      }
      return 4294967294LL;
    }
    sub_9404B508(v17, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 243, "handle_ptr");
    return 4294967254LL;
  }
  sub_9404B508(v9, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 219, "handle");
  goto LABEL_17;
}

/* ===== sub_9402E5B8 @ 0x9402E5B8 size 260 ===== */
__int64 __fastcall sub_9402E5B8(_QWORD *a1, unsigned int a2, _QWORD *a3)
{
  __int64 v3; // x30
  unsigned __int64 v4; // x3
  _QWORD *v5; // x5
  _QWORD *v6; // x19
  int v7; // w1
  unsigned int *v8; // x3
  unsigned int v9; // w2
  __int64 result; // x0

  if ( a1 == nullptr )
  {
    sub_9404B508(v3, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 262, "ctx");
  }
  else if ( a3 != nullptr )
  {
    if ( a2 > 0x3F )
      return 4294967254LL;
    if ( ((*a1 >> a2) & 1) == 0 )
      return 4294967294LL;
    v4 = a2;
    v5 = &a1[a2];
    v6 = (_QWORD *)v5[1];
    if ( v6 == nullptr )
    {
      sub_9404B508(v3, "ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 134, "ctx->handles[handle_id]");
      return 4294967294LL;
    }
    v7 = ~(1 << a2);
    v8 = (unsigned int *)a1 + (v4 >> 5);
    do
      v9 = __ldxr(v8);
    while ( __stxr(v9 & v7, v8) != 0 );
    v5[1] = 0;
    sub_9402DE38((__int64)(a1 + 66), v6);
    result = 0;
    *a3 = v6;
    return result;
  }
  sub_9404B508(v3, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 263, "handle_ptr");
  return 4294967254LL;
}

/* ===== sub_9402E6BC @ 0x9402E6BC size 600 ===== */
__int64 __fastcall sub_9402E6BC(unsigned int a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x23
  __int64 v4; // x30
  __int64 v5; // x20
  __int64 v7; // x22
  __int64 v8; // x21
  __int64 v9; // x0
  __int64 result; // x0
  int v11; // w19
  int v12; // w0
  unsigned int v13; // w0
  __int64 v14; // x30
  unsigned int v15; // w1
  unsigned int v16; // w19
  unsigned int v17; // w22
  __int64 v18; // x23
  __int64 v19; // x20
  int v20; // w19
  _QWORD *v21; // x1
  int v22; // w0
  int v23; // w1
  __int64 v24; // x2
  int v25; // w0
  _QWORD *v26; // x0
  unsigned int v27; // [xsp+18h] [xbp-78h]
  __int64 v28[10]; // [xsp+28h] [xbp-68h] BYREF
  __int64 v29; // [xsp+78h] [xbp-18h] BYREF
  unsigned int v30; // [xsp+80h] [xbp-10h] BYREF
  _DWORD v31[3]; // [xsp+84h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+90h] [xbp+0h] BYREF
  __int64 v33; // [xsp+C8h] [xbp+38h] BYREF
  int v34; // [xsp+D0h] [xbp+40h] BYREF
  _BYTE v35[4]; // [xsp+D4h] [xbp+44h] BYREF
  int v36; // [xsp+D8h] [xbp+48h]

  v5 = a1;
  v7 = a2;
  v8 = v4;
  v9 = sub_9402E190();
  LODWORD(result) = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *))loc_9402E4E4)(v9, (unsigned int)v5, &v33);
  if ( (_DWORD)result != 0 )
    return (int)result;
  if ( v33 == 0 )
  {
    v13 = sub_9404B508(v8, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 305, "handle");
    v28[1] = (__int64)&v32;
    v28[2] = v14;
    v28[3] = a3;
    v28[4] = v5;
    v28[5] = v8;
    v28[6] = v7;
    v16 = v15;
    v28[7] = v3;
    v17 = v13;
    v18 = v14;
    v19 = sub_9402E190();
    v20 = ((__int64 (__fastcall *)(__int64, __int64 *, _DWORD *, _QWORD))loc_9402DED0)(v19 + 528, &v29, v31, v16);
    if ( (v20 & 0x80000000) == 0 )
    {
      if ( v29 == 0 )
      {
        sub_9404B508(v18, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 357, "handle");
LABEL_21:
        sub_9404B508(v18, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 144, "ctx");
LABEL_22:
        v27 = sub_9404B508(
                v18,
                "DEBUG ASSERT FAILED at (%s:%d): %s\n",
                "lk/trusty/lib/trusty/uctx.c",
                366,
                "tmp_event.handle < IPC_MAX_HANDLES");
        v26 = (_QWORD *)sub_9402E190();
        LODWORD(result) = sub_9402E5B8(v26, v27, v28);
        if ( (_DWORD)result != 0 )
          return (int)result;
        sub_9402DADC(v28[0]);
        return 0;
      }
      v21 = (_QWORD *)(v19 + 8);
      v22 = 0;
      if ( v19 == 0 )
        goto LABEL_21;
      do
      {
        if ( v29 == *v21 )
        {
          v23 = v22;
          goto LABEL_15;
        }
        ++v22;
        ++v21;
      }
      while ( v22 != 64 );
      v23 = -1;
LABEL_15:
      v24 = *(_QWORD *)(v29 + 96);
      v30 = v23;
      v31[1] = v24;
      ((void (__fastcall *)(__int64))loc_9402D978)(v29);
      if ( v30 > 0x3F )
        goto LABEL_22;
      v25 = sub_9404D224(v17, &v30, 12);
      if ( v25 != 0 )
        return v25;
    }
    return v20;
  }
  v11 = ((__int64 (__fastcall *)(__int64, _BYTE *, _QWORD))loc_9402DB34)(v33, v35, (unsigned int)a3);
  if ( (v11 & 0x80000000) == 0 )
  {
    v34 = v5;
    v36 = *(_QWORD *)(v33 + 96);
    v12 = sub_9404D224((unsigned int)v7, &v34, 12);
    if ( v12 != 0 )
      v11 = v12;
  }
  ((void (__fastcall *)(__int64))loc_9402D978)(v33);
  return v11;
}

/* ===== sub_9402E914 @ 0x9402E914 size 88 ===== */
__int64 __fastcall sub_9402E914(unsigned int a1, unsigned int a2)
{
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // [xsp+28h] [xbp+28h] BYREF

  v3 = a2;
  v4 = sub_9402E190();
  LODWORD(result) = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *))loc_9402E4E4)(v4, a1, &v7);
  if ( (_DWORD)result != 0 )
    return (int)result;
  v6 = v7;
  *(_QWORD *)(v7 + 96) = v3;
  ((void (__fastcall *)(__int64))loc_9402D978)(v6);
  return 0;
}

/* ===== sub_9402E96C @ 0x9402E96C size 252 ===== */
__int64 sub_9402E96C()
{
  __int64 v0; // x30
  __int64 v1; // x21
  __int64 v2; // x0
  __int64 v3; // x1

  v1 = v0;
  if ( (unsigned int)((__int64 (*)(void))loc_9402E1F8)() != 0 )
    sub_9404B508(
      v1,
      "ASSERT FAILED at (%s:%d): %s\n",
      "lk/trusty/lib/tam/../trusty/include/lib/trusty/trusty_app.h",
      102,
      "slot < als_slot_cnt");
  v2 = sub_9404B508(
         v1,
         "ASSERT FAILED at (%s:%d): %s\n",
         "lk/trusty/lib/tam/../trusty/include/lib/trusty/trusty_app.h",
         109,
         "slot < als_slot_cnt");
  return sub_9402EA68(v2, v3);
}

/* ===== sub_9402EA68 @ 0x9402EA68 size 52 ===== */
__int64 __fastcall sub_9402EA68(_QWORD *a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v3; // [xsp+18h] [xbp+18h] BYREF

  LODWORD(result) = sub_9402E5B8(a1, a2, &v3);
  if ( (_DWORD)result != 0 )
    return (int)result;
  sub_9402DADC(v3);
  return 0;
}

/* ===== sub_9402EA9C @ 0x9402EA9C size 356 ===== */
__int64 __fastcall sub_9402EA9C(__int64 a1, int *a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v6; // x22
  int v7; // w21
  _QWORD *v8; // x2
  int v9; // w1
  __int64 v11; // x30
  __int64 v12; // x0
  __int64 *v13; // x1
  unsigned int v14; // w2
  __int64 *v15; // x0
  __int64 v16; // t1
  __int64 v17; // [xsp+48h] [xbp+38h] BYREF

  v6 = v3;
  v7 = ((__int64 (__fastcall *)(__int64, __int64 *, int *, __int64))loc_9402DED0)(a1 + 528, &v17, a2 + 1, a3);
  if ( v7 < 0 )
    return v7;
  if ( v17 == 0 )
  {
    sub_9404B508(v6, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 453, "handle");
    goto LABEL_11;
  }
  v8 = (_QWORD *)(a1 + 8);
  v9 = 0;
  if ( a1 != 0 )
  {
    while ( v17 != *v8 )
    {
      ++v9;
      ++v8;
      if ( v9 == 64 )
      {
        v9 = -1;
        break;
      }
    }
    a2[2] = *(_QWORD *)(v17 + 96);
    *a2 = v9;
    ((void (*)(void))loc_9402D978)();
    return v7;
  }
LABEL_11:
  sub_9404B508(v6, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/uctx.c", 144, "ctx");
  v12 = sub_9404B508(
          v11,
          "ASSERT FAILED at (%s:%d): %s\n",
          "lk/trusty/lib/tam/../trusty/include/lib/trusty/trusty_app.h",
          102,
          "slot < als_slot_cnt");
  v13 = (__int64 *)(v12 + 8);
  v14 = 0;
  v15 = (__int64 *)(v12 + 520);
  do
  {
    v16 = *v13++;
    if ( v16 != 0 )
      ++v14;
  }
  while ( v13 != v15 );
  return v14;
}

/* ===== sub_9402EC00 @ 0x9402EC00 size 8 ===== */
__int64 __fastcall sub_9402EC00(__int64 a1)
{
  return *(unsigned int *)(a1 + 608);
}

/* ===== sub_9402EC08 @ 0x9402EC08 size 16 ===== */
__int64 __fastcall sub_9402EC08(__int64 result, int a2)
{
  *(_DWORD *)(result + 608) += a2;
  return result;
}

/* ===== sub_9402EC18 @ 0x9402EC18 size 112 ===== */
__int64 __fastcall sub_9402EC18(int a1, __int64 a2, __int64 *a3)
{
  __int64 result; // x0

  result = sub_9404CBDC(1, 232);
  if ( result != 0 )
  {
    *(_QWORD *)(result + 8) = a3;
    *(_QWORD *)result = a3;
    *(_QWORD *)(result + 184) = 0;
    *(_QWORD *)(result + 192) = 0;
    *a3 = result;
    a3[1] = result;
    *(_QWORD *)(result + 16) = 0;
    *(_QWORD *)(result + 24) = 0;
    *(_QWORD *)(result + 64) = 0;
    *(_QWORD *)(result + 72) = 0;
    *(_QWORD *)(result + 40) = a2;
    *(_DWORD *)(result + 48) = 0;
    *(_DWORD *)(result + 52) = a1;
  }
  return result;
}

/* ===== sub_9402EC88 @ 0x9402EC88 size 812 ===== */
__int64 __fastcall sub_9402EC88(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  int v3; // w21
  __int64 v5; // x20
  __int64 v6; // x22
  __int64 v7; // x21
  __int64 v8; // x1
  __int64 v9; // x0
  __int64 v11; // x2
  __int64 v12; // x1
  __int64 v13; // x1
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 *v16; // x0
  __int64 v17; // x1
  __int64 v18; // x1
  __int64 *v19; // x0
  __int64 v20; // x1
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // [xsp+40h] [xbp+40h] BYREF
  __int64 *v26; // [xsp+48h] [xbp+48h]

  v3 = *(_DWORD *)(a1 + 72);
  v25 = 0;
  v26 = nullptr;
  if ( v3 != 1 )
    return 4294967293LL;
  if ( *(_QWORD *)(a2 + 40) == 0 )
    return 4294967253LL;
  v5 = a2;
  v6 = v2;
  if ( (unsigned __int8)sub_94034218() != 0 )
    goto LABEL_10;
  if ( (*(_DWORD *)(a1 + 76) & 1) == 0 )
    return 4294967253LL;
  while ( 1 )
  {
    v7 = sub_9402EC18(1, *(_QWORD *)(a1 + 64), &v25);
    if ( v7 == 0 )
      return 4294967291LL;
    if ( (unsigned int)sub_94030CA4(*(unsigned int *)(a1 + 80), *(_QWORD *)(a1 + 88), v5 + 216) != 0 )
      goto LABEL_28;
    if ( (unsigned int)sub_94030CA4(*(unsigned int *)(a1 + 80), *(_QWORD *)(a1 + 88), v7 + 216) != 0 )
    {
      sub_94030DEC(*(_QWORD *)(v5 + 216));
      *(_QWORD *)(v5 + 216) = 0;
LABEL_28:
      v18 = v25;
      v19 = v26;
      if ( v25 == 0 )
        goto LABEL_45;
      goto LABEL_29;
    }
    v8 = *(_QWORD *)(v5 + 16);
    *(_DWORD *)(v7 + 48) = 1;
    *(_DWORD *)(v5 + 48) = 2;
    v9 = v5 + 16;
    if ( v8 == 0 && *(_QWORD *)(v5 + 24) == 0 )
    {
      v11 = v7 + 16;
      *(_QWORD *)(v5 + 16) = *(_QWORD *)v7;
      *(_QWORD *)(v5 + 24) = v7;
      v12 = *(_QWORD *)(v7 + 16);
      *(_QWORD *)(*(_QWORD *)v7 + 8LL) = v9;
      *(_QWORD *)v7 = v9;
      *(_QWORD *)(v5 + 32) = v7;
      if ( v12 == 0 && *(_QWORD *)(v7 + 24) == 0 )
      {
        v13 = v7 + 184;
        *(_QWORD *)(v7 + 16) = *(_QWORD *)v5;
        *(_QWORD *)(v7 + 24) = v5;
        *(_QWORD *)(*(_QWORD *)v5 + 8LL) = v11;
        *(_QWORD *)v5 = v11;
        *(_QWORD *)(v7 + 32) = v5;
        if ( *(_QWORD *)(v7 + 184) == 0 && *(_QWORD *)(v7 + 192) == 0 )
          break;
      }
    }
    sub_9404B508(
      v6,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      "lk/trusty/include/reflist.h",
      62,
      "!list_in_list(&ref->ref_node)");
LABEL_10:
    if ( (*(_DWORD *)(a1 + 76) & 2) == 0 )
      return 4294967253LL;
  }
  v14 = *(_QWORD *)v7;
  *(_QWORD *)(v7 + 184) = *(_QWORD *)v7;
  *(_QWORD *)(v7 + 192) = v7;
  *(_QWORD *)(v14 + 8) = v13;
  *(_QWORD *)v7 = v13;
  v5 = v7 + 200;
  *(_QWORD *)(v7 + 200) = *(_QWORD *)(a1 + 200);
  *(_QWORD *)(v7 + 208) = a1 + 200;
  *(_QWORD *)(*(_QWORD *)(a1 + 200) + 8LL) = v7 + 200;
  *(_QWORD *)(a1 + 200) = v7 + 200;
  sub_9402D930(a1 + 96);
  sub_9402DC34(a1 + 96);
  v15 = v25;
  v16 = v26;
  if ( v25 == 0 )
    goto LABEL_24;
  while ( 1 )
  {
    *v16 = v15;
    v17 = v25;
    v25 = 0;
    *(_QWORD *)(v17 + 8) = v16;
    v26 = nullptr;
    if ( v7 != *(_QWORD *)(v7 + 8) )
      return 0;
    if ( *(_QWORD *)(v7 + 32) != 0 )
    {
      while ( 1 )
      {
        v19 = (__int64 *)sub_9404B508(
                           v6,
                           "ASSERT FAILED at (%s:%d): %s\n",
                           "lk/trusty/lib/trusty/ipc.c",
                           390,
                           (const char *)&loc_94051058);
LABEL_45:
        if ( v19 == nullptr )
          break;
LABEL_29:
        *v19 = v18;
        v20 = v25;
        v25 = 0;
        *(_QWORD *)(v20 + 8) = v19;
        v26 = nullptr;
        if ( v7 != *(_QWORD *)(v7 + 8) )
          return 4294967291LL;
        if ( *(_QWORD *)(v7 + 32) == 0 )
        {
          if ( *(_QWORD *)(v7 + 200) != 0 || *(_QWORD *)(v7 + 208) != 0 )
            goto LABEL_23;
          v21 = *(_QWORD *)(v7 + 224);
          if ( v21 != 0 )
            sub_9404CC20(v21);
          v22 = *(_QWORD *)(v7 + 216);
          if ( v22 != 0 )
          {
            sub_94030DEC(v22);
            *(_QWORD *)(v7 + 216) = 0;
          }
          sub_9404CC20(v7);
          return 4294967291LL;
        }
      }
LABEL_25:
      sub_9404B508(
        v6,
        "DEBUG ASSERT FAILED at (%s:%d): %s\n",
        "lk/trusty/include/reflist.h",
        71,
        "list_in_list(&ref->ref_node)");
      return 4294967291LL;
    }
    if ( *(_QWORD *)(v7 + 200) == 0 && *(_QWORD *)(v5 + 8) == 0 )
      break;
LABEL_23:
    v16 = (__int64 *)sub_9404B508(
                       v6,
                       "ASSERT FAILED at (%s:%d): %s\n",
                       "lk/trusty/lib/trusty/ipc.c",
                       393,
                       "!list_in_list(&chan->node)");
LABEL_24:
    if ( v16 == nullptr )
      goto LABEL_25;
  }
  v23 = *(_QWORD *)(v7 + 224);
  if ( v23 != 0 )
    sub_9404CC20(v23);
  v24 = *(_QWORD *)(v7 + 216);
  if ( v24 != 0 )
  {
    sub_94030DEC(v24);
    *(_QWORD *)(v7 + 216) = 0;
  }
  sub_9404CC20(v7);
  return 0;
}

/* ===== sub_9402EFB4 @ 0x9402EFB4 size 800 ===== */
__int64 __fastcall sub_9402EFB4(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x21
  __int64 v3; // x30
  __int64 v5; // x22
  __int64 v6; // kr18_8
  __int64 result; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  _QWORD *v10; // x0
  __int64 v11; // x3
  __int64 v12; // x2
  _QWORD *v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x1
  _QWORD *v17; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  _QWORD *v20; // x0
  __int64 v21; // x3
  _QWORD *v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0

  v5 = v3;
  v6 = (unsigned int)(*(_DWORD *)(a1 + 48) - 1);
  result = (__int64)&loc_9402EFF4 + 4 * jpt_9402EFF0[(unsigned int)v6];
  switch ( (int)v6 )
  {
    case 0:
      goto LABEL_14;
    case 1:
    case 2:
      goto LABEL_25;
    case 3:
      goto LABEL_15;
    case 4:
      v8 = a1 + 200;
      v9 = *(_QWORD *)(a1 + 200);
      v10 = *(_QWORD **)(a1 + 208);
      if ( v9 != 0 )
        goto LABEL_4;
      break;
    default:
      result = v6;
      goto LABEL_15;
  }
  while ( 1 )
  {
    if ( v10 != nullptr )
    {
LABEL_4:
      *v10 = v9;
      v11 = a1 + 184;
      v12 = *(_QWORD *)(a1 + 184);
      *(_QWORD *)(*(_QWORD *)(a1 + 200) + 8LL) = v10;
      *(_QWORD *)(v8 + 8) = 0;
      *(_QWORD *)(a1 + 200) = 0;
      v13 = *(_QWORD **)(a1 + 192);
      if ( v12 != 0 )
        goto LABEL_5;
    }
    else
    {
LABEL_44:
      v13 = (_QWORD *)sub_9404B508(
                        v5,
                        "ASSERT FAILED at (%s:%d): %s\n",
                        "lk/trusty/lib/trusty/ipc.c",
                        461,
                        "list_in_list(&chan->node)");
    }
    if ( v13 == nullptr )
    {
LABEL_33:
      while ( 1 )
      {
        sub_9404B508(
          v5,
          "DEBUG ASSERT FAILED at (%s:%d): %s\n",
          "lk/trusty/include/reflist.h",
          71,
          "list_in_list(&ref->ref_node)");
LABEL_34:
        if ( *(_QWORD *)(v1 + 32) != 0 )
          goto LABEL_42;
        if ( *(_QWORD *)(v1 + 200) != 0 || *(_QWORD *)(v18 + 8) != 0 )
          goto LABEL_24;
        v23 = *(_QWORD *)(v1 + 224);
        if ( v23 != 0 )
          sub_9404CC20(v23);
        v24 = *(_QWORD *)(v1 + 216);
        if ( v24 != 0 )
        {
          sub_94030DEC(v24);
          *(_QWORD *)(v1 + 216) = 0;
        }
        sub_9404CC20(v1);
        v1 = *(_QWORD *)(a1 + 32);
LABEL_29:
        *(_DWORD *)(v2 + 48) = 4;
        v2 = v1;
LABEL_17:
        v16 = *(_QWORD *)(a1 + 16);
        v17 = *(_QWORD **)(a1 + 24);
        if ( v16 != 0 || v17 != nullptr )
        {
          *v17 = v16;
          *(_QWORD *)(*(_QWORD *)(a1 + 16) + 8LL) = v17;
          *(_QWORD *)(a1 + 24) = 0;
          *(_QWORD *)(a1 + 16) = 0;
          result = *(_QWORD *)(v2 + 8);
          if ( v2 != result )
          {
            *(_QWORD *)(a1 + 32) = 0;
            return result;
          }
          if ( *(_QWORD *)(v2 + 32) != 0 )
            goto LABEL_42;
          if ( *(_QWORD *)(v2 + 200) != 0 || *(_QWORD *)(v2 + 208) != 0 )
            goto LABEL_24;
          v25 = *(_QWORD *)(v2 + 224);
          if ( v25 != 0 )
            sub_9404CC20(v25);
          v26 = *(_QWORD *)(v2 + 216);
          if ( v26 != 0 )
          {
            sub_94030DEC(v26);
            *(_QWORD *)(v2 + 216) = 0;
          }
          result = sub_9404CC20(v2);
          *(_QWORD *)(a1 + 32) = 0;
          return result;
        }
      }
    }
LABEL_5:
    *v13 = v12;
    *(_QWORD *)(*(_QWORD *)(a1 + 184) + 8LL) = v13;
    *(_QWORD *)(v11 + 8) = 0;
    *(_QWORD *)(a1 + 184) = 0;
    if ( a1 != *(_QWORD *)(a1 + 8) )
      goto LABEL_14;
    if ( *(_QWORD *)(a1 + 32) == 0 )
      break;
LABEL_42:
    v10 = (_QWORD *)sub_9404B508(
                      v5,
                      "ASSERT FAILED at (%s:%d): %s\n",
                      "lk/trusty/lib/trusty/ipc.c",
                      390,
                      (const char *)&loc_94051058);
  }
  if ( *(_QWORD *)(a1 + 200) == 0 && *(_QWORD *)(v8 + 8) == 0 )
  {
    v14 = *(_QWORD *)(a1 + 224);
    if ( v14 != 0 )
      sub_9404CC20(v14);
    v15 = *(_QWORD *)(a1 + 216);
    if ( v15 != 0 )
    {
      sub_94030DEC(v15);
      *(_QWORD *)(a1 + 216) = 0;
    }
    sub_9404CC20(a1);
LABEL_14:
    result = 4;
    *(_DWORD *)(a1 + 48) = 4;
    goto LABEL_15;
  }
LABEL_24:
  sub_9404B508(v5, "ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 393, "!list_in_list(&chan->node)");
LABEL_25:
  *(_DWORD *)(a1 + 48) = 4;
  result = sub_9402DC34(a1 + 80);
LABEL_15:
  v1 = *(_QWORD *)(a1 + 32);
  v2 = v1;
  if ( v1 != 0 )
  {
    switch ( *(_DWORD *)(v1 + 48) )
    {
      case 1:
        *(_DWORD *)(v1 + 48) = 4;
        goto LABEL_17;
      case 2:
      case 3:
        *(_DWORD *)(v1 + 48) = 4;
        sub_9402DC34(v1 + 80);
        v2 = *(_QWORD *)(a1 + 32);
        goto LABEL_17;
      case 5:
        v18 = v1 + 200;
        v19 = *(_QWORD *)(v1 + 200);
        v20 = *(_QWORD **)(v1 + 208);
        if ( v19 == 0 && v20 == nullptr )
          goto LABEL_44;
        *v20 = v19;
        v21 = *(_QWORD *)(v1 + 184);
        *(_QWORD *)(*(_QWORD *)(v1 + 200) + 8LL) = v20;
        *(_QWORD *)(v1 + 208) = 0;
        *(_QWORD *)(v1 + 200) = 0;
        v22 = *(_QWORD **)(v1 + 192);
        if ( v21 == 0 && v22 == nullptr )
          goto LABEL_33;
        *v22 = v21;
        *(_QWORD *)(*(_QWORD *)(v1 + 184) + 8LL) = v22;
        *(_QWORD *)(v1 + 192) = 0;
        *(_QWORD *)(v1 + 184) = 0;
        if ( v1 != *(_QWORD *)(v1 + 8) )
          goto LABEL_29;
        goto LABEL_34;
      default:
        goto LABEL_17;
    }
  }
  return result;
}

/* ===== sub_9402F2D4 @ 0x9402F2D4 size 24 ===== */
bool __fastcall sub_9402F2D4(__int64 a1)
{
  return *(_QWORD *)(a1 + 8) == (_QWORD)qword_9405ACC8;
}

/* ===== sub_9402F2EC @ 0x9402F2EC size 1008 ===== */
__int64 __fastcall sub_9402F2EC(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 *v2; // x21
  __int64 v3; // x30
  __int64 v5; // x22
  __int64 v6; // x1
  _QWORD *v7; // x0
  _QWORD *v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x30
  __int64 v13; // x20
  __int64 v14; // x19
  __int64 result; // x0
  __int64 v16; // x0
  __int64 v17; // x30
  __int64 v18; // x19
  __int64 v19; // x21
  unsigned int v20; // w1
  __int64 v21; // x20
  __int64 v22; // x0
  __int64 v23; // x30
  __int64 v24; // x20
  __int64 v25; // x19
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  int v30; // w0
  __int64 v31; // x1
  bool v32; // zf
  __int64 v33; // x0
  unsigned int v34; // w19
  __int64 v35; // x2
  char v36; // w0
  __int64 v37; // x0
  __int64 v38; // [xsp+8h] [xbp-78h]
  __int64 v39; // [xsp+10h] [xbp-70h]
  __int64 v40; // [xsp+18h] [xbp-68h]
  _QWORD v41[6]; // [xsp+30h] [xbp-50h] BYREF
  _QWORD v42[4]; // [xsp+60h] [xbp-20h] BYREF
  __int64 vars0; // [xsp+80h] [xbp+0h] BYREF

  v5 = v3;
  if ( a1 == 0 )
    goto LABEL_11;
  if ( !sub_9402F2D4(a1) )
    goto LABEL_12;
  v2 = &qword_9405BFF0[2];
  v1 = (_QWORD *)(a1 - 80);
  sub_940251F8(-536630024, 0xFFFFFFFFLL);
  v6 = *(_QWORD *)(a1 - 16);
  v7 = *(_QWORD **)(a1 - 8);
  if ( v6 == 0 )
    goto LABEL_9;
  while ( 1 )
  {
    *v7 = v6;
    *(_QWORD *)(*(_QWORD *)(a1 - 16) + 8LL) = v7;
    *(_QWORD *)(a1 - 8) = 0;
    v8 = *(_QWORD **)(a1 - 72);
    *(_QWORD *)(a1 - 16) = 0;
    if ( v1 != v8 )
      return sub_9402530C(v2[495]);
    if ( *(_QWORD *)(a1 - 48) != 0 )
    {
      v11 = sub_9404B508(
              v5,
              "ASSERT FAILED at (%s:%d): %s\n",
              "lk/trusty/lib/trusty/ipc.c",
              390,
              (const char *)&loc_94051058);
      v42[0] = &vars0;
      v42[1] = v12;
      v42[2] = a1;
      v42[3] = v1;
      v13 = v11;
      v14 = v12;
      if ( v11 != 0 )
      {
        if ( sub_9402F2D4(v11) )
        {
          sub_940251F8(-536630024, 0xFFFFFFFFLL);
          sub_9402EFB4(v13 - 80);
          return sub_9402530C(-536630024);
        }
      }
      else
      {
        sub_9404B508(v12, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 492, "chandle");
      }
      v16 = sub_9404B508(
              v14,
              "DEBUG ASSERT FAILED at (%s:%d): %s\n",
              "lk/trusty/lib/trusty/ipc.c",
              493,
              "ipc_is_channel(chandle)");
      v41[0] = v42;
      v41[1] = v17;
      v41[2] = v14;
      v41[3] = v13;
      v41[4] = v2;
      v18 = v16;
      v19 = v17;
      v21 = v20;
      if ( v16 != 0 )
      {
        if ( sub_9402F2D4(v16) )
        {
          result = 17;
          if ( (v21 & 0x11) != 0 )
          {
            sub_940251F8(-536630024, 0xFFFFFFFFLL);
            if ( (v21 & 0x10) != 0 )
              *(_DWORD *)(v18 - 24) &= ~2u;
            if ( (v21 & 1) != 0 )
              *(_DWORD *)(v18 - 24) &= ~4u;
            return sub_9402530C(-536630024);
          }
          return result;
        }
      }
      else
      {
        sub_9404B508(v17, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 563, "chandle");
      }
      v22 = sub_9404B508(
              v19,
              "DEBUG ASSERT FAILED at (%s:%d): %s\n",
              "lk/trusty/lib/trusty/ipc.c",
              564,
              "ipc_is_channel(chandle)");
      v38 = v23;
      v39 = v18;
      v40 = v21;
      v24 = v22;
      v25 = v23;
      if ( v22 != 0 )
      {
        if ( sub_9402F2D4(v22) )
        {
          sub_940251F8(-536630024, 0xFFFFFFFFLL);
          v30 = *(_DWORD *)(v24 - 32);
          if ( v30 != 0 )
          {
            v31 = *(unsigned int *)(v24 - 24);
            v32 = v30 == 4;
            v33 = *(_QWORD *)(v24 + 136);
            if ( v32 )
              v34 = 4;
            else
              v34 = 0;
            v35 = v34 | 1;
            if ( (v31 & 4) != 0 )
              v34 |= 1u;
            if ( v33 != 0 )
            {
              v36 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, _QWORD *, __int64, __int64, __int64, __int64))sub_94030E14)(
                      v33,
                      v31,
                      v35,
                      v31 & 4,
                      v26,
                      v27,
                      v28,
                      v29,
                      v41,
                      v38,
                      v39,
                      v40,
                      v19);
              LODWORD(v31) = *(_DWORD *)(v24 - 24);
              if ( v36 == 0 )
                v34 |= 8u;
            }
            if ( (v31 & 2) != 0 )
              v34 |= 0x10u;
            sub_9402530C(-536630024);
            return v34;
          }
          else
          {
            sub_9402530C(-536630024);
            return 2;
          }
        }
      }
      else
      {
        sub_9404B508(v23, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 520, "chandle");
      }
      v37 = sub_9404B508(
              v25,
              "DEBUG ASSERT FAILED at (%s:%d): %s\n",
              "lk/trusty/lib/trusty/ipc.c",
              521,
              "ipc_is_channel(chandle)");
      return sub_9402F6DC(v37);
    }
    if ( v1[25] == 0 )
    {
LABEL_13:
      if ( v1[26] == 0 )
        break;
    }
    v7 = (_QWORD *)sub_9404B508(
                     v5,
                     "ASSERT FAILED at (%s:%d): %s\n",
                     "lk/trusty/lib/trusty/ipc.c",
                     393,
                     "!list_in_list(&chan->node)");
LABEL_9:
    if ( v7 == nullptr )
    {
      sub_9404B508(
        v5,
        "DEBUG ASSERT FAILED at (%s:%d): %s\n",
        "lk/trusty/include/reflist.h",
        71,
        "list_in_list(&ref->ref_node)");
LABEL_11:
      sub_9404B508(v3, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 506, "chandle");
LABEL_12:
      sub_9404B508(
        v5,
        "DEBUG ASSERT FAILED at (%s:%d): %s\n",
        "lk/trusty/lib/trusty/ipc.c",
        507,
        "ipc_is_channel(chandle)");
      goto LABEL_13;
    }
  }
  v9 = v1[28];
  if ( v9 != 0 )
    sub_9404CC20(v9);
  v10 = v1[27];
  if ( v10 != 0 )
  {
    sub_94030DEC(v10);
    v1[27] = 0;
  }
  sub_9404CC20(v1);
  return sub_9402530C(v2[495]);
}

/* ===== sub_9402F6DC @ 0x9402F6DC size 24 ===== */
bool __fastcall sub_9402F6DC(__int64 a1)
{
  return *(_QWORD *)(a1 + 8) == (_QWORD)qword_9405AD30;
}

/* ===== sub_9402F6F4 @ 0x9402F6F4 size 768 ===== */
__int64 __fastcall sub_9402F6F4(__int64 a1)
{
  _QWORD *v1; // x22
  __int64 *v2; // x23
  __int64 v3; // x30
  _QWORD *v4; // x19
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x1
  _QWORD *v8; // x19
  __int64 v10; // x0
  __int64 v11; // x30
  __int64 v12; // x21
  __int64 v13; // x24
  __int64 v14; // x0
  __int64 *v15; // x1
  _QWORD *v16; // x2
  _QWORD *v17; // x1
  _QWORD *v18; // x0
  __int64 v19; // x3
  _QWORD *v20; // x2
  __int64 v21; // x0
  __int64 v22; // x0

  v4 = (_QWORD *)a1;
  v5 = v3;
  if ( a1 == 0 )
  {
    sub_9404B508(v3, "ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 217, "phandle");
  }
  else if ( sub_9402F6DC(a1) )
  {
    v6 = (__int64)(v4 - 12);
    if ( (_QWORD *)v4[14] != v4 + 13 )
      goto LABEL_10;
    v7 = v4[15];
    v8 = v4 + 15;
    if ( v7 == 0 )
      goto LABEL_6;
    do
    {
      v6 = sub_9404B508(
             v5,
             "DEBUG ASSERT FAILED at (%s:%d): %s\n",
             "lk/trusty/lib/trusty/ipc.c",
             226,
             "!list_in_list(&port->node)");
LABEL_6:
      ;
    }
    while ( v8[1] != 0 );
    return sub_9404CC20(v6);
  }
  sub_9404B508(v5, "ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 218, (const char *)sub_94051138);
LABEL_10:
  v10 = sub_9404B508(
          v5,
          "DEBUG ASSERT FAILED at (%s:%d): %s\n",
          "lk/trusty/lib/trusty/ipc.c",
          225,
          "list_is_empty(&port->pending_list)");
  v12 = v10;
  v13 = v11;
  if ( v10 != 0 )
  {
    if ( sub_9402F6DC(v10) )
    {
      v2 = &qword_9405BFF0[2];
      v1 = (_QWORD *)(v12 - 96);
      sub_940251F8(-536630024, 0xFFFFFFFFLL);
      v14 = *(_QWORD *)(v12 + 120);
      *(_DWORD *)(v12 - 24) = 2;
      v15 = *(__int64 **)(v12 + 128);
      if ( v14 == 0 )
        goto LABEL_25;
LABEL_13:
      *v15 = v14;
      *(_QWORD *)(v1[27] + 8LL) = v15;
      v1[28] = 0;
      v1[27] = 0;
      ((void (__fastcall *)(__int64))loc_9402D978)(v12);
LABEL_14:
      v4 = (_QWORD *)(v1[26] - 200LL);
      v5 = *(_QWORD *)(v1[26] + 8LL) - 200LL;
      if ( v1 == v4 )
        return sub_9402530C(v2[495]);
      while ( 1 )
      {
        sub_9402EFB4((__int64)v4);
        v16 = (_QWORD *)v4[26];
        v17 = v4 + 25;
        v18 = v4 + 23;
        *v16 = v4[25];
        v19 = v4[23];
        *(_QWORD *)(v4[25] + 8LL) = v16;
        v4[26] = 0;
        v4[25] = 0;
        v20 = (_QWORD *)v4[24];
        if ( v19 == 0 )
          goto LABEL_22;
        while ( 1 )
        {
          *v20 = v19;
          *(_QWORD *)(*v18 + 8LL) = v20;
          v18[1] = 0;
          *v18 = 0;
          if ( v4 != (_QWORD *)v4[1] )
            break;
          if ( v4[4] != 0 )
            goto LABEL_24;
          if ( *v17 == 0 )
          {
LABEL_29:
            if ( v17[1] == 0 )
            {
              v21 = v4[28];
              if ( v21 != 0 )
                sub_9404CC20(v21);
              v22 = v4[27];
              if ( v22 != 0 )
              {
                sub_94030DEC(v22);
                v4[27] = 0;
              }
              sub_9404CC20(v4);
              break;
            }
          }
          v18 = (_QWORD *)sub_9404B508(
                            v13,
                            "ASSERT FAILED at (%s:%d): %s\n",
                            "lk/trusty/lib/trusty/ipc.c",
                            393,
                            "!list_in_list(&chan->node)");
LABEL_22:
          if ( v20 == nullptr )
          {
            sub_9404B508(
              v13,
              "DEBUG ASSERT FAILED at (%s:%d): %s\n",
              "lk/trusty/include/reflist.h",
              71,
              "list_in_list(&ref->ref_node)");
LABEL_24:
            v14 = sub_9404B508(
                    v13,
                    "ASSERT FAILED at (%s:%d): %s\n",
                    "lk/trusty/lib/trusty/ipc.c",
                    390,
                    (const char *)&loc_94051058);
LABEL_25:
            if ( v15 != nullptr )
              goto LABEL_13;
            goto LABEL_14;
          }
        }
        v4 = (_QWORD *)v5;
        ((void (__fastcall *)(__int64))loc_9402D978)(v12);
        v5 = *(_QWORD *)(v5 + 208) - 200LL;
        if ( v1 == v4 )
          return sub_9402530C(v2[495]);
      }
    }
  }
  else
  {
    sub_9404B508(v11, "ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 170, "phandle");
  }
  sub_9404B508(v13, "ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 171, (const char *)sub_94051138);
  goto LABEL_29;
}

/* ===== sub_9402F9F4 @ 0x9402F9F4 size 216 ===== */
__int64 __fastcall sub_9402F9F4(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  BOOL v5; // w21
  __int64 v6; // x0

  v3 = v1;
  if ( a1 == 0 )
  {
    sub_9404B508(v1, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 365, "phandle");
  }
  else if ( sub_9402F6DC(a1) )
  {
    sub_940251F8(-536630024, 0xFFFFFFFFLL);
    if ( *(_DWORD *)(a1 - 24) == 1 )
    {
      v5 = *(_QWORD *)(a1 + 112) != a1 + 104;
      sub_9402530C(-536630024);
      return v5;
    }
    else
    {
      sub_9402530C(-536630024);
      return 2;
    }
  }
  v6 = sub_9404B508(
         v3,
         "DEBUG ASSERT FAILED at (%s:%d): %s\n",
         "lk/trusty/lib/trusty/ipc.c",
         366,
         (const char *)sub_94051138);
  return sub_9402FACC(v6);
}

/* ===== sub_9402FACC @ 0x9402FACC size 288 ===== */
__int64 __fastcall sub_9402FACC(__int64 a1, __int64 a2, int a3, __int64 a4, int a5, _QWORD *a6)
{
  __int64 v12; // x0
  __int64 v13; // x20
  unsigned int v14; // w0
  unsigned int v15; // w19

  if ( a1 == 0 || (unsigned int)(a3 - 1) > 0x1F || (unsigned __int64)(a4 - 1) > 0xFFF )
    return 4294967288LL;
  v12 = sub_9404CBDC(1, 232);
  v13 = v12;
  if ( v12 == 0 )
    return 4294967291LL;
  v14 = sub_9404CF6C(v12, a2, 64);
  if ( v14 != 0 )
  {
    v15 = -25;
    if ( v14 <= 0x3F )
    {
      *(_QWORD *)(v13 + 64) = a1;
      *(_DWORD *)(v13 + 80) = a3;
      *(_QWORD *)(v13 + 88) = a4;
      *(_DWORD *)(v13 + 76) = a5;
      *(_DWORD *)(v13 + 72) = 0;
      *(_QWORD *)(v13 + 208) = v13 + 200;
      *(_QWORD *)(v13 + 200) = v13 + 200;
      sub_9402D85C(v13 + 96, (__int64)qword_9405AD30);
      *a6 = v13 + 96;
      return 0;
    }
  }
  else
  {
    v15 = -8;
  }
  sub_9404CC20(v13);
  return v15;
}

/* ===== sub_9402FBEC @ 0x9402FBEC size 916 ===== */
__int64 __fastcall sub_9402FBEC(__int64 a1)
{
  __int64 *v1; // x21
  __int64 v2; // x23
  __int64 (__fastcall **v3)(); // x25
  __int64 v4; // x30
  __int64 v6; // x20
  __int64 v7; // x22
  __int64 *v8; // x22
  bool v9; // zf
  unsigned int v10; // w24
  __int64 (__fastcall *v12)(); // x2
  __int64 v13; // x19
  __int64 v14; // x22
  __int64 v15; // x24
  __int64 v16; // x1
  __int64 v17; // x0
  _QWORD *v18; // x24
  _QWORD *v19; // x1
  __int64 v20; // x2
  _QWORD *v21; // x1
  __int64 v22; // x1
  _QWORD *v23; // x0
  __int64 v24; // x1
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // [xsp+50h] [xbp+50h] BYREF
  _QWORD *v29; // [xsp+58h] [xbp+58h]

  v6 = v4;
  if ( a1 == 0 )
  {
    sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 240, "phandle");
  }
  else if ( sub_9402F6DC(a1) )
  {
    v1 = &qword_9405BFF0[2];
    v2 = a1 - 96;
    sub_940251F8(-536630024, 0xFFFFFFFFLL);
    if ( *(_QWORD *)(a1 + 120) == 0 )
      goto LABEL_5;
    do
    {
      sub_9404B508(
        v6,
        "DEBUG ASSERT FAILED at (%s:%d): %s\n",
        "lk/trusty/lib/trusty/ipc.c",
        246,
        "!list_in_list(&port->node)");
LABEL_5:
      ;
    }
    while ( *(_QWORD *)(a1 + 128) != 0 );
    v3 = &off_9405A000;
    v7 = -536630304;
    if ( &qword_9405ACB8 == (__int64 *)-536630088LL )
      goto LABEL_14;
    while ( (unsigned int)sub_9404CED8(a1 - 96, v7) != 0 )
    {
      v8 = *(__int64 **)(v7 + 224);
      v9 = &qword_9405ACB8 == v8;
      v7 = (__int64)(v8 - 27);
      if ( v9 )
        goto LABEL_14;
    }
    v10 = -14;
    if ( v7 == 0 )
    {
LABEL_14:
      v12 = v3[407];
      *(_DWORD *)(a1 - 24) = 1;
      *(_QWORD *)(v2 + 216) = v12;
      *(_QWORD *)(v2 + 224) = v3 + 407;
      *((_QWORD *)v12 + 1) = v2 + 216;
      v3[407] = (__int64 (__fastcall *)())(v2 + 216);
      sub_9402D930(v2 + 96);
      v28 = 0;
      v29 = nullptr;
      v13 = -536630240;
      v14 = MEMORY[0xFFFFFFFFE003ACF0] - 200LL;
      if ( &off_9405ACE8 == (_UNKNOWN **)-536630040LL )
      {
LABEL_18:
        v10 = 0;
        goto LABEL_11;
      }
      while ( 1 )
      {
        v15 = *(_QWORD *)(v13 + 224);
        if ( (unsigned int)sub_9404CED8(v15, v2) != 0 )
          goto LABEL_16;
        sub_9404CC20(v15);
        *(_QWORD *)(v13 + 224) = 0;
        if ( v28 != 0 )
          break;
LABEL_21:
        if ( v29 != nullptr )
          break;
        v16 = *(_QWORD *)v13;
        v29 = (_QWORD *)v13;
        v17 = v13 + 184;
        v28 = v16;
        *(_QWORD *)(*(_QWORD *)v13 + 8LL) = &v28;
        *(_QWORD *)v13 = &v28;
        v18 = (_QWORD *)(v13 + 200);
        v19 = *(_QWORD **)(v13 + 208);
        *v19 = *(_QWORD *)(v13 + 200);
        v20 = *(_QWORD *)(v13 + 184);
        *(_QWORD *)(*(_QWORD *)(v13 + 200) + 8LL) = v19;
        *(_QWORD *)(v13 + 208) = 0;
        *(_QWORD *)(v13 + 200) = 0;
        v21 = *(_QWORD **)(v13 + 192);
        if ( v20 == 0 && v21 == nullptr )
        {
          while ( 1 )
          {
            v23 = (_QWORD *)sub_9404B508(
                              v6,
                              "DEBUG ASSERT FAILED at (%s:%d): %s\n",
                              "lk/trusty/include/reflist.h",
                              71,
                              "list_in_list(&ref->ref_node)");
LABEL_39:
            if ( v23 != nullptr )
              goto LABEL_27;
          }
        }
        *v21 = v20;
        *(_QWORD *)(*(_QWORD *)v17 + 8LL) = v21;
        *(_QWORD *)(v13 + 192) = 0;
        *(_QWORD *)v17 = 0;
        if ( v13 == *(_QWORD *)(v13 + 8) )
        {
          while ( 1 )
          {
            if ( *(_QWORD *)(v13 + 32) != 0 )
              goto LABEL_41;
            if ( *v18 == 0 && *(_QWORD *)(v13 + 208) == 0 )
              break;
LABEL_30:
            sub_9404B508(
              v6,
              "ASSERT FAILED at (%s:%d): %s\n",
              "lk/trusty/lib/trusty/ipc.c",
              393,
              "!list_in_list(&chan->node)");
          }
          v25 = *(_QWORD *)(v13 + 216);
          if ( v25 != 0 )
          {
            sub_94030DEC(v25);
            *(_QWORD *)(v13 + 216) = 0;
          }
          sub_9404CC20(v13);
        }
        if ( (unsigned int)sub_9402EC88(v2, v13) != 0 )
          sub_9402EFB4(v13);
        v22 = v28;
        v23 = v29;
        if ( v28 == 0 )
          goto LABEL_39;
LABEL_27:
        *v23 = v22;
        v24 = v28;
        v28 = 0;
        *(_QWORD *)(v24 + 8) = v23;
        v29 = nullptr;
        if ( v13 == *(_QWORD *)(v13 + 8) )
        {
          if ( *(_QWORD *)(v13 + 32) == 0 )
          {
            if ( *v18 == 0 )
            {
LABEL_42:
              if ( *(_QWORD *)(v13 + 208) == 0 )
              {
                v26 = *(_QWORD *)(v13 + 224);
                if ( v26 != 0 )
                  sub_9404CC20(v26);
                v27 = *(_QWORD *)(v13 + 216);
                if ( v27 != 0 )
                {
                  sub_94030DEC(v27);
                  *(_QWORD *)(v13 + 216) = 0;
                }
                sub_9404CC20(v13);
                goto LABEL_16;
              }
            }
            goto LABEL_30;
          }
LABEL_41:
          sub_9404B508(
            v6,
            "ASSERT FAILED at (%s:%d): %s\n",
            "lk/trusty/lib/trusty/ipc.c",
            390,
            (const char *)&loc_94051058);
          goto LABEL_42;
        }
LABEL_16:
        v9 = &off_9405ACE8 == (_UNKNOWN **)(v14 + 200);
        v13 = v14;
        v14 = *(_QWORD *)(v14 + 208) - 200LL;
        if ( v9 )
          goto LABEL_18;
      }
      sub_9404B508(
        v6,
        "DEBUG ASSERT FAILED at (%s:%d): %s\n",
        "lk/trusty/include/reflist.h",
        62,
        "!list_in_list(&ref->ref_node)");
      goto LABEL_21;
    }
LABEL_11:
    sub_9402530C(v1[495]);
    return v10;
  }
  sub_9404B508(
    v6,
    "DEBUG ASSERT FAILED at (%s:%d): %s\n",
    "lk/trusty/lib/trusty/ipc.c",
    241,
    (const char *)sub_94051138);
  goto LABEL_14;
}

/* ===== sub_9402FF80 @ 0x9402FF80 size 308 ===== */
__int64 __fastcall sub_9402FF80(unsigned int a1, int a2, __int64 a3, int a4)
{
  __int64 v8; // x24
  _QWORD *v9; // x26
  __int64 result; // x0
  int v11; // w19
  unsigned int v12; // w0
  unsigned int v13; // [xsp+54h] [xbp+54h] BYREF
  __int64 v14; // [xsp+58h] [xbp+58h] BYREF
  char v15[64]; // [xsp+60h] [xbp+60h] BYREF

  v8 = *(_QWORD *)(*(_QWORD *)(_ReadStatusReg(TPIDR_EL1) + 688) + 144LL);
  v9 = (_QWORD *)sub_9402E190();
  v14 = 0;
  LODWORD(result) = sub_9404D264(v15, a1, 64);
  if ( (result & 0x80000000) != 0 )
    return (int)result;
  if ( (unsigned int)result > 0x3F )
    return -8;
  v11 = sub_9402FACC(v8 + 32, (__int64)v15, a2, a3, a4, &v14);
  if ( v11 == 0 )
  {
    v11 = ((__int64 (__fastcall *)(_QWORD *, __int64, unsigned int *))loc_9402E3B0)(v9, v14, &v13);
    if ( v11 == 0 )
    {
      sub_9402EC08((__int64)v9, 1);
      v11 = sub_9402FBEC(v14);
      if ( v11 == 0 )
      {
        v12 = sub_9404CFF4(v15);
        sub_9402BD04(v15, v12);
        return v13;
      }
      sub_9402E5B8(v9, v13, &v14);
    }
    ((void (__fastcall *)(__int64))loc_9402D978)(v14);
  }
  return v11;
}

/* ===== sub_940300B4 @ 0x940300B4 size 704 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_940300B4(__int64 a1, __int64 a2, unsigned __int64 a3, char a4, _QWORD *a5)
{
  __int64 v5; // x30
  __int64 v7; // x24
  unsigned __int64 v11; // x0
  __int64 v12; // x22
  __int64 v13; // x19
  __int64 *v14; // x19
  bool v15; // zf
  unsigned int v16; // w19
  __int64 v17; // x0
  _QWORD *v18; // x0
  __int64 v19; // x1
  __int64 v21; // x0
  __int64 v22; // x4
  __int64 v23; // x2
  __int64 v24; // x0
  __int64 v25; // x1
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v29; // [xsp+60h] [xbp+60h] BYREF
  _QWORD *v30; // [xsp+68h] [xbp+68h]

  v29 = 0;
  v30 = nullptr;
  v7 = v5;
  if ( a1 == 0 )
    return 4294967288LL;
  v11 = sub_9404D0A0(a2, a3);
  if ( v11 >= a3 || v11 == 0 )
    return 4294967288LL;
  v12 = sub_9402EC18(0, a1, &v29);
  if ( v12 != 0 )
  {
    sub_940251F8(-536630024, 0xFFFFFFFFLL);
    v13 = -536630304;
    if ( &qword_9405ACB8 == (__int64 *)-536630088LL )
      goto LABEL_13;
    while ( (unsigned int)sub_9404CED8(a2, v13) != 0 )
    {
      v14 = *(__int64 **)(v13 + 224);
      v15 = &qword_9405ACB8 == v14;
      v13 = (__int64)(v14 - 27);
      if ( v15 )
        goto LABEL_13;
    }
    if ( v13 == 0 )
      goto LABEL_13;
    v16 = sub_9402EC88(v13, v12);
    if ( v16 == 0 )
      goto LABEL_11;
    while ( 1 )
    {
LABEL_15:
      v18 = v30;
      if ( v29 == 0 && v30 == nullptr )
      {
        sub_9404B508(
          v7,
          "DEBUG ASSERT FAILED at (%s:%d): %s\n",
          "lk/trusty/include/reflist.h",
          71,
          "list_in_list(&ref->ref_node)");
        return 4294967288LL;
      }
      *v30 = v29;
      v19 = v29;
      v29 = 0;
      *(_QWORD *)(v19 + 8) = v18;
      v30 = nullptr;
      if ( v12 != *(_QWORD *)(v12 + 8) )
        goto LABEL_17;
      if ( *(_QWORD *)(v12 + 32) != 0 )
        break;
      if ( *(_QWORD *)(v12 + 200) == 0 && *(_QWORD *)(v12 + 208) == 0 )
      {
        v26 = *(_QWORD *)(v12 + 224);
        if ( v26 != 0 )
          sub_9404CC20(v26);
        v27 = *(_QWORD *)(v12 + 216);
        if ( v27 != 0 )
        {
          sub_94030DEC(v27);
          *(_QWORD *)(v12 + 216) = 0;
        }
        sub_9404CC20(v12);
LABEL_17:
        sub_9402530C(-536630024);
        return v16;
      }
      sub_9404B508(
        v7,
        "ASSERT FAILED at (%s:%d): %s\n",
        "lk/trusty/lib/trusty/ipc.c",
        393,
        "!list_in_list(&chan->node)");
      while ( 1 )
      {
        v16 = -5;
        v21 = sub_9404CF24(a2);
        *(_QWORD *)(v12 + 224) = v21;
        if ( v21 == 0 )
          break;
        *(_DWORD *)(v12 + 48) = 5;
        v22 = *(_QWORD *)(v12 + 184);
        v23 = v12 + 184;
        *(_QWORD *)(v12 + 200) = -536630040;
        *(_QWORD *)(v12 + 208) = &off_9405ACE8;
        MEMORY[0xFFFFFFFFE003ACF0] = v12 + 200;
        off_9405ACE8 = (_UNKNOWN *)(v12 + 200);
        if ( v22 == 0 && *(_QWORD *)(v12 + 192) == 0 )
        {
          v24 = *(_QWORD *)v12;
          *(_QWORD *)(v12 + 184) = *(_QWORD *)v12;
          *(_QWORD *)(v12 + 192) = v12;
          *(_QWORD *)(v24 + 8) = v23;
          *(_QWORD *)v12 = v23;
LABEL_11:
          sub_9402D85C(v12 + 80, (__int64)qword_9405ACC8);
          v17 = v12 + 64;
          if ( *(_QWORD *)(v12 + 64) == 0 && *(_QWORD *)(v12 + 72) == 0 )
          {
            v25 = *(_QWORD *)v12;
            v16 = 0;
            *(_QWORD *)(v12 + 64) = *(_QWORD *)v12;
            *(_QWORD *)(v12 + 72) = v12;
            *(_QWORD *)(v25 + 8) = v17;
            *(_QWORD *)v12 = v17;
            *a5 = v12 + 80;
            goto LABEL_15;
          }
        }
        sub_9404B508(
          v7,
          "DEBUG ASSERT FAILED at (%s:%d): %s\n",
          "lk/trusty/include/reflist.h",
          62,
          "!list_in_list(&ref->ref_node)");
LABEL_13:
        if ( (a4 & 1) == 0 )
        {
          v16 = -2;
          goto LABEL_15;
        }
      }
    }
    sub_9404B508(v7, "ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 390, (const char *)&loc_94051058);
  }
  return 4294967291LL;
}

/* ===== sub_94030374 @ 0x94030374 size 400 ===== */
__int64 __fastcall sub_94030374(unsigned int a1, int a2)
{
  __int64 v4; // x22
  __int64 v5; // x23
  __int64 result; // x0
  int v7; // w19
  unsigned int v8; // [xsp+44h] [xbp+44h] BYREF
  __int64 v9; // [xsp+48h] [xbp+48h] BYREF
  char v10[64]; // [xsp+50h] [xbp+50h] BYREF

  v4 = *(_QWORD *)(*(_QWORD *)(_ReadStatusReg(TPIDR_EL1) + 688) + 144LL);
  v5 = sub_9402E190();
  if ( (a2 & 0xFFFFFFFC) == 0 )
  {
    LODWORD(result) = sub_9404D264(v10, a1, 64);
    if ( (result & 0x80000000) != 0 )
      return (int)result;
    if ( (unsigned int)result <= 0x3F )
    {
      LODWORD(result) = sub_940300B4(v4 + 32, (__int64)v10, 0x40u, a2, &v9);
      if ( (_DWORD)result != 0 )
        return (int)result;
      if ( (a2 & 2) != 0 )
        goto LABEL_10;
      v7 = ((__int64 (__fastcall *)(__int64, unsigned int *, __int64))loc_9402DB34)(v9, &v8, 0xFFFFFFFFLL);
      if ( v7 != -13 )
      {
        if ( (v7 & 0x80000000) == 0 )
          goto LABEL_8;
LABEL_14:
        sub_9402DADC(v9);
        return v7;
      }
      sub_9404CB4C("%s:%d: Timedout connecting to %s\n", "sys_connect", 792, v10);
      v7 = ((__int64 (__fastcall *)(__int64, unsigned int *, __int64))loc_9402DB34)(v9, &v8, 0xFFFFFFFFLL);
      if ( v7 < 0 )
        goto LABEL_14;
LABEL_8:
      if ( (v8 & 0xC) == 4 )
      {
        sub_9402DADC(v9);
        return -15;
      }
      else
      {
        if ( (v8 & 1) != 0 )
        {
LABEL_10:
          v7 = ((__int64 (__fastcall *)(__int64, __int64, unsigned int *))loc_9402E3B0)(v5, v9, &v8);
          if ( v7 == 0 )
            return v8;
          goto LABEL_14;
        }
        sub_9404CB4C("%s:%d: Unexpected channel state: event = 0x%x\n", "sys_connect", 811, v8);
        sub_9402DADC(v9);
        return -3;
      }
    }
  }
  return -8;
}

/* ===== sub_94030504 @ 0x94030504 size 920 ===== */
__int64 __fastcall sub_94030504(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 v3; // x30
  __int64 v5; // x25
  __int64 v8; // x26
  unsigned int v9; // w21
  _QWORD *v11; // x19
  _QWORD *v12; // x0
  _QWORD *v13; // x20
  __int64 v14; // x2
  __int64 v15; // x2
  _QWORD *v16; // x0
  __int64 v17; // x1
  _QWORD *v18; // x0
  __int64 v19; // x1
  __int64 v20; // x0
  __int64 v21; // x0
  int v22; // w1
  _QWORD *v23; // x1
  __int64 v24; // x2
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // [xsp+60h] [xbp+60h] BYREF
  _QWORD *v28; // [xsp+68h] [xbp+68h]

  v27 = 0;
  v5 = v3;
  v28 = nullptr;
  if ( a2 == nullptr )
    goto LABEL_12;
  if ( a3 == nullptr )
  {
LABEL_13:
    sub_9404B508(v3, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 840, "uuid_ptr");
    return 4294967288LL;
  }
  if ( a1 == 0 || !sub_9402F6DC(a1) )
    return 4294967288LL;
  v8 = a1 - 96;
  v9 = -15;
  sub_940251F8(-536630024, 0xFFFFFFFFLL);
  if ( *(_DWORD *)(a1 - 24) != 1 )
    goto LABEL_6;
  v11 = *(_QWORD **)(a1 + 112);
  if ( v11 == (_QWORD *)(a1 + 104)
    || (v12 = (_QWORD *)v11[1],
        *v12 = *v11,
        *(_QWORD *)(*v11 + 8LL) = v12,
        v11[1] = 0,
        *v11 = 0,
        v13 = v11 - 25,
        v11 == (_QWORD *)200) )
  {
    v9 = -4;
    goto LABEL_6;
  }
  if ( (*((_DWORD *)v11 - 37) & 1) == 0 )
  {
    v18 = (_QWORD *)sub_9404B508(
                      v5,
                      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
                      "lk/trusty/lib/trusty/ipc.c",
                      870,
                      "server->flags & IPC_CHAN_FLAG_SERVER");
    goto LABEL_42;
  }
  if ( v27 != 0 || v28 != nullptr )
  {
LABEL_11:
    sub_9404B508(
      v5,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      "lk/trusty/include/reflist.h",
      62,
      "!list_in_list(&ref->ref_node)");
LABEL_12:
    sub_9404B508(v3, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 839, "chandle_ptr");
    goto LABEL_13;
  }
  v14 = *(v11 - 25);
  v28 = v11 - 25;
  v27 = v14;
  v15 = *(v11 - 2);
  *(_QWORD *)(*(v11 - 25) + 8LL) = &v27;
  *(v11 - 25) = &v27;
  v16 = (_QWORD *)*(v11 - 1);
  if ( v15 == 0 && v16 == nullptr )
    goto LABEL_36;
  *v16 = v15;
  *(_QWORD *)(*(v11 - 2) + 8LL) = v16;
  *(v11 - 1) = 0;
  *(v11 - 2) = 0;
  if ( v13 != (_QWORD *)*(v11 - 24) )
    goto LABEL_19;
  while ( 1 )
  {
    if ( *(v11 - 21) != 0 )
      goto LABEL_44;
    if ( *v11 == 0 && v11[1] == 0 )
      break;
LABEL_26:
    sub_9404B508(v5, "ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 393, "!list_in_list(&chan->node)");
  }
  v20 = v11[3];
  if ( v20 != 0 )
    sub_9404CC20(v20);
  v21 = v11[2];
  if ( v21 != 0 )
  {
    sub_94030DEC(v21);
    v11[2] = 0;
  }
  sub_9404CC20(v11 - 25);
LABEL_19:
  ((void (__fastcall *)(__int64))loc_9402D978)(v8 + 96);
  v8 = *(v11 - 21);
  if ( v8 == 0 || *((_DWORD *)v11 - 38) != 1 )
  {
LABEL_21:
    v9 = -15;
    sub_9402EFB4((__int64)(v11 - 25));
    goto LABEL_22;
  }
  while ( 1 )
  {
    if ( *(_DWORD *)(v8 + 48) != 2 )
      goto LABEL_21;
    v22 = *(_DWORD *)(v8 + 56);
    *((_DWORD *)v11 - 38) = 3;
    *(_DWORD *)(v8 + 56) = v22 | 4;
    *(_DWORD *)(v8 + 48) = 3;
    sub_9402D85C((__int64)(v11 - 15), (__int64)qword_9405ACC8);
    v23 = v11 - 17;
    if ( *(v11 - 17) != 0 || *(v11 - 16) != 0 )
      goto LABEL_11;
    v24 = *(v11 - 25);
    *(v11 - 17) = v24;
    v9 = 0;
    *(v11 - 16) = v13;
    *(_QWORD *)(v24 + 8) = v23;
    *(v11 - 25) = v23;
    *a2 = v11 - 15;
    *a3 = *(_QWORD *)(v8 + 40);
    sub_9402DC34(v8 + 80);
LABEL_22:
    v17 = v27;
    v18 = v28;
    if ( v27 != 0 )
      break;
LABEL_42:
    if ( v18 != nullptr )
      break;
LABEL_36:
    sub_9404B508(
      v5,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      "lk/trusty/include/reflist.h",
      71,
      "list_in_list(&ref->ref_node)");
  }
  *v18 = v17;
  v19 = v27;
  v27 = 0;
  *(_QWORD *)(v19 + 8) = v18;
  v28 = nullptr;
  if ( v13 != (_QWORD *)*(v11 - 24) )
    goto LABEL_6;
  if ( *(v11 - 21) != 0 )
  {
LABEL_44:
    sub_9404B508(v5, "ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc.c", 390, (const char *)&loc_94051058);
    goto LABEL_45;
  }
  if ( *v11 != 0 )
    goto LABEL_26;
LABEL_45:
  if ( v11[1] != 0 )
    goto LABEL_26;
  v25 = v11[3];
  if ( v25 != 0 )
    sub_9404CC20(v25);
  v26 = v11[2];
  if ( v26 != 0 )
  {
    sub_94030DEC(v26);
    v11[2] = 0;
  }
  sub_9404CC20(v11 - 25);
LABEL_6:
  sub_9402530C(-536630024);
  return v9;
}

/* ===== sub_9403089C @ 0x9403089C size 220 ===== */
__int64 __fastcall sub_9403089C(unsigned int a1, unsigned int a2)
{
  _QWORD *v4; // x20
  __int64 result; // x0
  int v6; // w19
  unsigned int v7; // [xsp+34h] [xbp+34h] BYREF
  __int64 v8; // [xsp+38h] [xbp+38h] BYREF
  __int64 v9; // [xsp+40h] [xbp+40h] BYREF
  __int64 v10; // [xsp+48h] [xbp+48h] BYREF

  v8 = 0;
  v4 = (_QWORD *)sub_9402E190();
  v9 = 0;
  LODWORD(result) = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64 *))loc_9402E4E4)(v4, a1, &v8);
  if ( (_DWORD)result == 0 )
  {
    v6 = sub_94030504(v8, &v9, &v10);
    if ( v6 == 0 )
    {
      v6 = ((__int64 (__fastcall *)(_QWORD *, __int64, unsigned int *))loc_9402E3B0)(v4, v9, &v7);
      if ( v6 == 0 )
      {
        v6 = sub_9404D224(a2, v10, 16);
        if ( v6 == 0 )
        {
          ((void (__fastcall *)(__int64))loc_9402D978)(v8);
          return v7;
        }
        sub_9402E5B8(v4, v7, &v9);
      }
      sub_9402DADC(v9);
    }
    ((void (__fastcall *)(__int64))loc_9402D978)(v8);
    return v6;
  }
  return (int)result;
}

/* ===== sub_94030978 @ 0x94030978 size 160 ===== */
__int64 __fastcall sub_94030978(__int64 a1, _QWORD *a2, __int64 a3, int a4, __int64 a5, int a6)
{
  int v7; // w19
  unsigned int v9; // [xsp+34h] [xbp+34h] BYREF
  __int64 v10; // [xsp+38h] [xbp+38h] BYREF

  v10 = 0;
  v7 = sub_9402FACC(a1 + 32, a3, a4, a5, a6, &v10);
  if ( v7 == 0 )
  {
    v7 = ((__int64 (__fastcall *)(_QWORD *, __int64, unsigned int *))loc_9402E3B0)(a2, v10, &v9);
    if ( v7 == 0 )
    {
      v7 = sub_9402FBEC(v10);
      if ( v7 == 0 )
        return v9;
      sub_9402E5B8(a2, v9, &v10);
    }
    ((void (__fastcall *)(__int64))loc_9402D978)(v10);
  }
  return v7;
}

/* ===== sub_94030A18 @ 0x94030A18 size 152 ===== */
__int64 __fastcall sub_94030A18(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  int v5; // w19
  __int64 v6; // [xsp+28h] [xbp+28h] BYREF
  unsigned int v7; // [xsp+3Ch] [xbp+3Ch] BYREF
  __int64 v8; // [xsp+40h] [xbp+40h] BYREF
  __int64 v9; // [xsp+48h] [xbp+48h] BYREF

  v6 = a3;
  v8 = 0;
  v9 = 0;
  LODWORD(result) = ((__int64 (__fastcall *)(__int64, __int64, __int64 *))loc_9402E4E4)(a1, a2, &v8);
  if ( (_DWORD)result == 0 )
  {
    v5 = sub_94030504(v8, &v9, &v6);
    if ( v5 == 0 )
    {
      v5 = ((__int64 (__fastcall *)(__int64, __int64, unsigned int *))loc_9402E3B0)(a1, v9, &v7);
      if ( v5 == 0 )
      {
        ((void (__fastcall *)(__int64))loc_9402D978)(v8);
        return v7;
      }
      sub_9402DADC(v9);
    }
    ((void (__fastcall *)(__int64))loc_9402D978)(v8);
    return v5;
  }
  return (int)result;
}

/* ===== sub_94030AB0 @ 0x94030AB0 size 312 ===== */
__int64 __fastcall sub_94030AB0(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x30
  _QWORD *v3; // x20
  _QWORD *v4; // x19
  int v6; // w2
  __int64 v7; // x1
  __int64 v8; // x4
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 result; // x0
  _QWORD *v12; // x3
  __int64 v13; // x4

  v3 = *(_QWORD **)(*(_QWORD *)(a1 + 32) + 216LL);
  v4 = (_QWORD *)v3[1];
  if ( v3 == v4 || v4 == nullptr || v4 == (_QWORD *)48 )
  {
    *(_DWORD *)(a1 + 56) |= 1u;
    return 4294967287LL;
  }
  if ( *((_BYTE *)v4 - 47) != 0 )
  {
    sub_9404B508(
      v2,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      "lk/trusty/lib/trusty/ipc_msg.c",
      228,
      "item->state == MSG_ITEM_STATE_FREE");
    return 4294967272LL;
  }
  *(v4 - 1) = 0;
  v6 = *a2;
  v7 = v3[7];
  v8 = v3[8];
  v9 = *((unsigned __int8 *)v4 - 48);
  *((_DWORD *)v4 - 11) = 0;
  v10 = v8 + v9 * v7;
  if ( v6 != 1 )
  {
    if ( v6 != 0 )
      return 4294967288LL;
    if ( a2[4] == 0 )
    {
      result = sub_940318E4(v10, v7, (unsigned int)a2[3], (unsigned int)a2[2]);
      goto LABEL_9;
    }
    return 4294967272LL;
  }
  if ( a2[6] != 0 )
    return 4294967272LL;
  result = sub_94031708(v10, v7, *((_QWORD *)a2 + 2), (unsigned int)a2[2]);
LABEL_9:
  if ( (result & 0x8000000000000000LL) == 0 )
  {
    v12 = (_QWORD *)v4[1];
    v13 = *v4;
    *(v4 - 1) = result;
    *v12 = v13;
    *(_QWORD *)(*v4 + 8LL) = v12;
    *v4 = 0;
    *v4 = v3[2];
    v4[1] = v3 + 2;
    *(_QWORD *)(v3[2] + 8LL) = v4;
    v3[2] = v4;
    *((_BYTE *)v4 - 47) = 1;
  }
  return result;
}

/* ===== sub_94030BE8 @ 0x94030BE8 size 188 ===== */
__int64 __fastcall sub_94030BE8(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  __int64 v4; // x7
  __int64 v5; // x1
  __int64 v6; // x7
  unsigned __int64 v7; // x6
  unsigned __int64 v9; // x3
  __int64 v10; // x2

  v4 = a2 + 1LL;
  v5 = a1 + ((unsigned __int64)a2 << 6);
  v6 = a1 + (v4 << 6);
  if ( *(_BYTE *)(v5 + 73) != 2 )
    return 4294967288LL;
  if ( *(_DWORD *)(v5 + 76) == 0 )
  {
    v7 = *(_QWORD *)(v5 + 112);
    if ( a3 <= v7 )
    {
      v9 = v7 - a3;
      v10 = *(_QWORD *)(a1 + 64) + a3 + *(unsigned __int8 *)(v6 + 8) * *(_QWORD *)(a1 + 56);
      if ( *(_DWORD *)a4 == 1 )
      {
        if ( *(_DWORD *)(a4 + 24) == 0 )
          return sub_9403161C(*(_QWORD *)(a4 + 16), *(unsigned int *)(a4 + 8), v10, v9);
        return 4294967272LL;
      }
      if ( *(_DWORD *)a4 == 0 )
      {
        if ( *(_DWORD *)(a4 + 16) == 0 )
          return sub_940317F4(*(unsigned int *)(a4 + 12), *(unsigned int *)(a4 + 8), v10, v9);
        return 4294967272LL;
      }
    }
    return 4294967288LL;
  }
  return 4294967272LL;
}

/* ===== sub_94030CA4 @ 0x94030CA4 size 328 ===== */
__int64 __fastcall sub_94030CA4(unsigned int a1, __int64 a2, __int64 *a3)
{
  __int64 v4; // x23
  __int64 v6; // x19
  __int64 v7; // x0
  _QWORD *v8; // x0
  _QWORD *v9; // x4
  int v10; // w1
  unsigned int v11; // w19
  __int64 v13; // x0

  v4 = a1;
  v6 = sub_9404CBDC(1, ((unsigned __int64)a1 << 6) + 72);
  if ( v6 != 0 )
  {
    v7 = sub_9404CBC4(v4 * a2);
    *(_QWORD *)(v6 + 64) = v7;
    if ( v7 != 0 )
    {
      *(_DWORD *)(v6 + 48) = v4;
      *(_QWORD *)(v6 + 56) = a2;
      *(_QWORD *)(v6 + 8) = v6;
      *(_QWORD *)v6 = v6;
      *(_QWORD *)(v6 + 24) = v6 + 16;
      *(_QWORD *)(v6 + 16) = v6 + 16;
      *(_QWORD *)(v6 + 40) = v6 + 32;
      *(_QWORD *)(v6 + 32) = v6 + 32;
      if ( (_DWORD)v4 != 0 )
      {
        v8 = (_QWORD *)(v6 + 120);
        v9 = (_QWORD *)v6;
        v10 = 0;
        do
        {
          *((_BYTE *)v8 - 48) = v10++;
          *v8 = v9;
          v8[1] = v6;
          v9[1] = v8;
          v9 = v8;
          v8 += 8;
        }
        while ( v10 != (_DWORD)v4 );
        *(_QWORD *)v6 = v6 + ((unsigned __int64)(unsigned int)(v10 - 1) << 6) + 120;
      }
      *a3 = v6;
      return 0;
    }
    else
    {
      if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
        sub_9404B2FC("cannot allocate memory for message queue buf\n");
      v13 = v6;
      v11 = -5;
      sub_9404CC20(v13);
    }
    return v11;
  }
  v11 = -5;
  if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) != 0 )
    return v11;
  sub_9404B2FC("cannot allocate memory for message queue\n");
  return 4294967291LL;
}

/* ===== sub_94030DEC @ 0x94030DEC size 40 ===== */
__int64 __fastcall sub_94030DEC(__int64 a1)
{
  sub_9404CC20(*(_QWORD *)(a1 + 64));
  return sub_9404CC20(a1);
}

/* ===== sub_94030E14 @ 0x94030E14 size 20 ===== */
bool __fastcall sub_94030E14(__int64 a1)
{
  return *(_QWORD *)(a1 + 24) == a1 + 16;
}

/* ===== sub_94030E28 @ 0x94030E28 size 296 ===== */
__int64 __fastcall sub_94030E28(unsigned int a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v4; // x22
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x19
  int v8; // w0
  __int64 v9; // x19
  int v10; // w0
  __int64 v11; // x1
  __int64 v12; // x19
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // [xsp+30h] [xbp+30h] BYREF
  int v16; // [xsp+38h] [xbp+38h] BYREF
  __int64 v17; // [xsp+40h] [xbp+40h] BYREF

  v16 = 0;
  v4 = v2;
  LODWORD(result) = sub_9404D244(&v17, a2, 16);
  if ( (_DWORD)result != 0 )
    return (int)result;
  v6 = sub_9402E190();
  LODWORD(result) = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *))loc_9402E4E4)(v6, a1, &v15);
  if ( (_DWORD)result != 0 )
    return (int)result;
  sub_940251F8(-536630024, 0xFFFFFFFFLL);
  v7 = v15;
  if ( v15 == 0 || !sub_9402F2D4(v15) )
  {
    v12 = -8;
LABEL_9:
    sub_9402530C(-536630024);
    ((void (__fastcall *)(__int64))loc_9402D978)(v15);
    return v12;
  }
  v8 = *(_DWORD *)(v7 - 32);
  if ( v8 != 3 )
  {
    v12 = -3;
    if ( v8 == 4 )
      v12 = -15;
    goto LABEL_9;
  }
  if ( *(_QWORD *)(v7 - 48) != 0 )
  {
    v9 = v15;
    v10 = sub_94030AB0(v15 - 80, &v16);
    if ( v10 < 0 )
    {
      v12 = v10;
    }
    else
    {
      v11 = *(_QWORD *)(v9 - 48);
      v12 = v10;
      sub_9402DC34(v11 + 80);
    }
    goto LABEL_9;
  }
  v13 = sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc_msg.c", 206, "chan->peer");
  return sub_94030F50(v13, v14);
}

/* ===== sub_94030F50 @ 0x94030F50 size 240 ===== */
__int64 __fastcall sub_94030F50(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v4; // x20
  int v5; // w1
  unsigned int v6; // w20
  int v8; // [xsp+38h] [xbp+38h] BYREF
  __int64 v9; // [xsp+40h] [xbp+40h] BYREF

  if ( a2 == 0 )
    return 4294967288LL;
  v4 = v2;
  v8 = 1;
  sub_9404CC78(&v9, a2, 32);
  sub_940251F8(-536630024, 0xFFFFFFFFLL);
  if ( a1 != 0 && sub_9402F2D4(a1) )
  {
    v5 = *(_DWORD *)(a1 - 32);
    if ( v5 != 3 )
    {
      if ( v5 == 4 )
        v6 = -15;
      else
        v6 = -3;
      goto LABEL_8;
    }
    if ( *(_QWORD *)(a1 - 48) != 0 )
    {
      v6 = sub_94030AB0(a1 - 80, &v8);
      if ( (v6 & 0x80000000) == 0 )
        sub_9402DC34(*(_QWORD *)(a1 - 48) + 80LL);
      goto LABEL_8;
    }
    sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc_msg.c", 206, "chan->peer");
    return 4294967288LL;
  }
  v6 = -8;
LABEL_8:
  sub_9402530C(-536630024);
  return v6;
}

/* ===== sub_94031040 @ 0x94031040 size 380 ===== */
__int64 __fastcall sub_94031040(unsigned int a1, unsigned int a2)
{
  __int64 v2; // x30
  __int64 v4; // x20
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x19
  __int64 v9; // x0
  __int64 v10; // x3
  int v11; // w0
  _QWORD *v12; // x1
  _QWORD *v13; // x2
  _QWORD *v14; // x5
  __int64 v15; // x19
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // [xsp+30h] [xbp+30h] BYREF
  _DWORD v19[2]; // [xsp+38h] [xbp+38h] BYREF

  v4 = v2;
  v6 = sub_9402E190();
  LODWORD(result) = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *))loc_9402E4E4)(v6, a1, &v18);
  if ( (_DWORD)result != 0 )
    return (int)result;
  sub_940251F8(-536630024, 0xFFFFFFFFLL);
  if ( v18 == 0 || !sub_9402F2D4(v18) )
  {
    v15 = -8;
    goto LABEL_13;
  }
  v8 = v18 - 80;
  v9 = *(_QWORD *)(v18 + 136);
  v10 = *(_QWORD *)(v9 + 24);
  if ( v10 == v9 + 16 || v10 == 0 || v10 == 48 )
  {
    v15 = -4;
    goto LABEL_13;
  }
  v19[0] = *(_QWORD *)(v10 - 8);
  v19[1] = *(unsigned __int8 *)(v10 - 48);
  v11 = sub_9404D224(a2, v19, 8);
  if ( v11 != 0 )
  {
    v15 = v11;
    goto LABEL_13;
  }
  v12 = *(_QWORD **)(v8 + 216);
  v13 = (_QWORD *)v12[3];
  if ( v13 != v12 + 2 && v13 != nullptr && v13 != (_QWORD *)48 )
  {
    v14 = (_QWORD *)v13[1];
    v15 = 0;
    *v14 = *v13;
    *(_QWORD *)(*v13 + 8LL) = v14;
    *v13 = 0;
    *v13 = v12[4];
    v13[1] = v12 + 4;
    *(_QWORD *)(v12[4] + 8LL) = v13;
    v12[4] = v13;
    *((_BYTE *)v13 - 47) = 2;
LABEL_13:
    sub_9402530C(-536630024);
    ((void (__fastcall *)(__int64))loc_9402D978)(v18);
    return v15;
  }
  v16 = sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc_msg.c", 349, "item");
  return sub_940311BC(v16, v17);
}

/* ===== sub_940311BC @ 0x940311BC size 268 ===== */
__int64 __fastcall sub_940311BC(__int64 a1, _DWORD *a2)
{
  _QWORD *v4; // x2
  _QWORD *v5; // x0
  unsigned int v6; // w19
  _QWORD *v7; // x4

  sub_940251F8(-536630024, 0xFFFFFFFFLL);
  if ( a1 != 0 && sub_9402F2D4(a1) )
  {
    v4 = *(_QWORD **)(a1 + 136);
    v5 = (_QWORD *)v4[3];
    if ( v5 == v4 + 2 || v5 == nullptr )
    {
      sub_9402530C(-536630024);
      return 4294967292LL;
    }
    else
    {
      v6 = -4;
      if ( v5 != (_QWORD *)48 )
      {
        *a2 = *(v5 - 1);
        v6 = 0;
        v7 = (_QWORD *)v5[1];
        a2[1] = *((unsigned __int8 *)v5 - 48);
        *v7 = *v5;
        *(_QWORD *)(*v5 + 8LL) = v7;
        *v5 = 0;
        *v5 = v4[4];
        v5[1] = v4 + 4;
        *(_QWORD *)(v4[4] + 8LL) = v5;
        v4[4] = v5;
        *((_BYTE *)v5 - 47) = 2;
      }
      sub_9402530C(-536630024);
      return v6;
    }
  }
  else
  {
    sub_9402530C(-536630024);
    return 4294967288LL;
  }
}

/* ===== sub_940312C8 @ 0x940312C8 size 352 ===== */
__int64 __fastcall sub_940312C8(__int64 a1, unsigned int a2)
{
  __int64 v2; // x30
  __int64 v3; // x22
  __int64 v5; // x19
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x19
  __int64 v9; // x3
  _QWORD *v10; // x4
  __int64 v11; // x1
  int v12; // w0
  unsigned int v13; // w19

  v3 = v2;
  v5 = a2;
  sub_940251F8(-536630024, 0xFFFFFFFFLL);
  if ( a1 == 0 || !sub_9402F2D4(a1) )
    goto LABEL_10;
  if ( a1 == 80 )
  {
    sub_9404B508(v3, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc_msg.c", 358, "chan");
    goto LABEL_13;
  }
  v6 = *(_QWORD *)(a1 + 136);
  if ( v6 == 0 )
  {
LABEL_13:
    sub_9404B508(v3, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/ipc_msg.c", 359, "chan->msg_queue");
    goto LABEL_14;
  }
  if ( (unsigned int)v5 >= *(_DWORD *)(v6 + 48)
    || (v7 = v5 << 6, v8 = v6 + (v5 << 6), v9 = v6 + v7, *(_BYTE *)(v6 + v7 + 73) != 2) )
  {
LABEL_10:
    v13 = -8;
    goto LABEL_11;
  }
  v10 = *(_QWORD **)(v8 + 128);
  *v10 = *(_QWORD *)(v8 + 120);
  *(_QWORD *)(*(_QWORD *)(v8 + 120) + 8LL) = v10;
  *(_QWORD *)(v8 + 128) = 0;
  *(_QWORD *)(v8 + 128) = *(_QWORD *)(v6 + 8);
  *(_QWORD *)(v8 + 120) = v6;
  **(_QWORD **)(v6 + 8) = v9 + 120;
  *(_QWORD *)(v6 + 8) = v9 + 120;
  *(_BYTE *)(v9 + 73) = 0;
  v11 = *(_QWORD *)(a1 - 48);
  if ( v11 == 0 )
  {
LABEL_14:
    v13 = 0;
    goto LABEL_11;
  }
  v12 = *(_DWORD *)(v11 + 56);
  v13 = 0;
  if ( (v12 & 1) != 0 )
  {
    *(_DWORD *)(v11 + 56) = v12 & 0xFFFFFFFC | 2;
    sub_9402DC34(v11 + 80);
    sub_9402530C(-536630024);
    return 0;
  }
LABEL_11:
  sub_9402530C(-536630024);
  return v13;
}

/* ===== sub_94031428 @ 0x94031428 size 96 ===== */
__int64 __fastcall sub_94031428(unsigned int a1, unsigned int a2)
{
  __int64 v4; // x0
  __int64 result; // x0
  int v6; // w19
  __int64 v7; // [xsp+28h] [xbp+28h] BYREF

  v4 = sub_9402E190();
  LODWORD(result) = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *))loc_9402E4E4)(v4, a1, &v7);
  if ( (_DWORD)result != 0 )
    return (int)result;
  v6 = sub_940312C8(v7, a2);
  ((void (__fastcall *)(__int64))loc_9402D978)(v7);
  return v6;
}

/* ===== sub_94031488 @ 0x94031488 size 220 ===== */
__int64 __fastcall sub_94031488(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x19
  __int64 v11; // [xsp+30h] [xbp+30h] BYREF
  int v12; // [xsp+38h] [xbp+38h] BYREF
  __int64 v13; // [xsp+40h] [xbp+40h] BYREF

  v12 = 0;
  LODWORD(result) = sub_9404D244(&v13, a4, 16);
  if ( (_DWORD)result != 0 )
    return (int)result;
  v8 = sub_9402E190();
  LODWORD(result) = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *))loc_9402E4E4)(v8, a1, &v11);
  if ( (_DWORD)result != 0 )
    return (int)result;
  sub_940251F8(-536630024, 0xFFFFFFFFLL);
  if ( v11 != 0 && sub_9402F2D4(v11) && *(_DWORD *)((v9 = *(_QWORD *)(v11 + 136)) + 48) > a2 )
    v10 = (int)sub_94030BE8(v9, a2, a3, (__int64)&v12);
  else
    v10 = -8;
  sub_9402530C(-536630024);
  ((void (__fastcall *)(__int64))loc_9402D978)(v11);
  return v10;
}

/* ===== sub_94031564 @ 0x94031564 size 184 ===== */
__int64 __fastcall sub_94031564(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  __int64 v7; // x0
  unsigned int v8; // w19
  int v10; // [xsp+48h] [xbp+48h] BYREF
  __int64 v11; // [xsp+50h] [xbp+50h] BYREF

  if ( a4 == 0 )
    return 4294967288LL;
  v10 = 1;
  sub_9404CC78(&v11, a4, 32);
  sub_940251F8(-536630024, 0xFFFFFFFFLL);
  if ( a1 != 0 && sub_9402F2D4(a1) && *(_DWORD *)((v7 = *(_QWORD *)(a1 + 136)) + 48) > a2 )
    v8 = sub_94030BE8(v7, a2, a3, (__int64)&v10);
  else
    v8 = -8;
  sub_9402530C(-536630024);
  return v8;
}

/* ===== sub_9403161C @ 0x9403161C size 236 ===== */
__int64 __fastcall sub_9403161C(_QWORD *a1, int a2, __int64 a3, unsigned __int64 a4)
{
  _QWORD *v4; // x20
  __int64 v5; // x22
  unsigned __int64 v6; // x21
  __int64 v7; // x23
  _QWORD *v8; // x24
  __int64 v9; // x1
  unsigned __int64 v10; // x19

  v4 = a1;
  v5 = a3;
  v6 = a4;
  if ( a2 == 0 || a4 == 0 )
    return 0;
  if ( a1 == nullptr || a3 == 0 )
    return -8;
  v7 = 0;
  v8 = &a1[2 * (unsigned int)(a2 - 1) + 2];
  while ( 1 )
  {
    v10 = v4[1];
    if ( v10 >= v6 )
      break;
    v9 = v5;
    if ( v10 == 0 )
      goto LABEL_19;
    v7 += v10;
    v5 += v10;
    if ( *v4 == 0 )
      return -8;
    sub_9404CC78(*v4, v9, v4[1]);
    v6 -= v10;
    if ( v6 != 0 )
    {
LABEL_19:
      v4 += 2;
      if ( v4 != v8 )
        continue;
    }
    return v7;
  }
  if ( *v4 == 0 )
    return -8;
  sub_9404CC78(*v4, v5, v6);
  return v7 + v6;
}

/* ===== sub_94031708 @ 0x94031708 size 236 ===== */
__int64 __fastcall sub_94031708(__int64 a1, unsigned __int64 a2, _QWORD *a3, int a4)
{
  __int64 v4; // x22
  unsigned __int64 v5; // x21
  _QWORD *v6; // x20
  __int64 v7; // x23
  _QWORD *v8; // x24
  __int64 v9; // x0
  unsigned __int64 v10; // x19

  v4 = a1;
  v5 = a2;
  v6 = a3;
  if ( a4 == 0 || a2 == 0 )
    return 0;
  if ( a1 == 0 || a3 == nullptr )
    return -8;
  v7 = 0;
  v8 = &a3[2 * (unsigned int)(a4 - 1) + 2];
  while ( 1 )
  {
    v10 = v6[1];
    if ( v5 <= v10 )
      break;
    v9 = v4;
    if ( v10 == 0 )
      goto LABEL_19;
    v7 += v10;
    v4 += v10;
    if ( *v6 == 0 )
      return -8;
    sub_9404CC78(v9, *v6, v6[1]);
    v5 -= v10;
    if ( v5 != 0 )
    {
LABEL_19:
      v6 += 2;
      if ( v6 != v8 )
        continue;
    }
    return v7;
  }
  if ( *v6 == 0 )
    return -8;
  sub_9404CC78(v4, *v6, v5);
  return v7 + v5;
}

/* ===== sub_940317F4 @ 0x940317F4 size 240 ===== */
__int64 __fastcall sub_940317F4(unsigned int a1, int a2, __int64 a3, unsigned __int64 a4)
{
  __int64 v5; // x22
  unsigned __int64 v6; // x20
  int v8; // w23
  __int64 v9; // x24
  __int64 v10; // x1
  __int64 result; // x0
  __int64 v12; // x1
  unsigned __int64 v13; // x19
  unsigned int v14; // [xsp+58h] [xbp+58h] BYREF
  unsigned int v15; // [xsp+5Ch] [xbp+5Ch]

  v5 = a3;
  v6 = a4;
  if ( a2 == 0 || a4 == 0 )
    return 0;
  if ( a3 == 0 )
    return -8;
  v8 = 0;
  v9 = 0;
  while ( 1 )
  {
    v10 = a1;
    ++v8;
    a1 += 8;
    LODWORD(result) = sub_9404D244(&v14, v10, 8);
    v12 = v5;
    if ( (_DWORD)result != 0 )
      break;
    v13 = v15;
    if ( v6 <= v15 )
      v13 = v6;
    v9 += v13;
    v5 += v13;
    LODWORD(result) = sub_9404D224(v14, v12, v13);
    v6 -= v13;
    if ( (_DWORD)result != 0 )
      break;
    if ( v6 == 0 || v8 == a2 )
      return v9;
  }
  return (int)result;
}

/* ===== sub_940318E4 @ 0x940318E4 size 272 ===== */
__int64 __fastcall sub_940318E4(__int64 a1, unsigned __int64 a2, unsigned int a3, int a4)
{
  __int64 v5; // x22
  unsigned __int64 v6; // x20
  int v8; // w23
  __int64 v9; // x24
  __int64 v10; // x1
  int v11; // w1
  __int64 v12; // x0
  unsigned __int64 v13; // x19
  __int64 result; // x0
  unsigned int v15; // [xsp+58h] [xbp+58h] BYREF
  unsigned int v16; // [xsp+5Ch] [xbp+5Ch]

  v5 = a1;
  v6 = a2;
  if ( a4 == 0 || a2 == 0 )
    return 0;
  if ( a1 == 0 )
    return -8;
  v8 = 0;
  v9 = 0;
  while ( 1 )
  {
    v10 = a3;
    ++v8;
    a3 += 8;
    v11 = sub_9404D244(&v15, v10, 8);
    v12 = v5;
    if ( v11 != 0 )
      return v11;
    v13 = v16;
    if ( v6 <= v16 )
      v13 = v6;
    v9 += v13;
    v5 += v13;
    LODWORD(result) = sub_9404D244(v12, v15, v13);
    v6 -= v13;
    if ( (_DWORD)result != 0 )
      break;
    if ( v6 == 0 || v8 == a4 )
      return v9;
  }
  return (int)result;
}

/* ===== sub_940319F4 @ 0x940319F4 size 716 ===== */
__int64 __fastcall sub_940319F4(
        __int64 a1,
        int a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x30
  __int64 v17; // x2
  unsigned int v18; // w26
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v22; // x0
  __int64 v23; // x30
  __int64 v24; // x19
  unsigned __int64 *v25; // x20
  __int64 v26; // x1
  __int64 v32; // x1
  __int64 v34; // x19
  unsigned __int64 *v35; // x20
  __int64 v39; // [xsp+48h] [xbp-8h]
  __int64 v40; // [xsp+A8h] [xbp+58h] BYREF

  v40 = 0;
  if ( a1 != 0 )
  {
    v17 = 8 * a4 + 6 + (((_DWORD)a5 - 1 + 2 * (a4 + 3 + 8 * a4)) & -(int)a5);
    *(_QWORD *)(a1 + 48) = v17;
    v18 = sub_9404A878(-536460256, "vqueue", (v17 + 4095) & 0x1FFFFF000LL, &v40, 12, a3, 0, 48);
    if ( v18 != 0 )
    {
      sub_9404CC20(a1);
      return v18;
    }
    else
    {
      v19 = v40;
      *(_DWORD *)(a1 + 8) = a4;
      v20 = v19 + 16LL * a4;
      *(_QWORD *)(a1 + 16) = v19;
      *(_QWORD *)(a1 + 24) = v20;
      *(_DWORD *)a1 = a2;
      *(_QWORD *)(a1 + 136) = a6;
      *(_QWORD *)(a1 + 32) = -a5 & (v20 + 2LL * a4 + 5 + a5);
      *(_QWORD *)(a1 + 120) = a7;
      *(_QWORD *)(a1 + 40) = v19;
      *(_QWORD *)(a1 + 128) = a8;
      sub_94024DFC(a1 + 72, 0, 0);
      return 0;
    }
  }
  else
  {
    v22 = sub_9404B508(v8, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/vqueue.c", 51, "vq");
    v24 = v22;
    if ( v22 != 0 )
    {
      v25 = (unsigned __int64 *)(v22 + 56);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      {
        sub_940223B4(v25);
        *(_QWORD *)(v24 + 48) = 0;
        v26 = *(_QWORD *)(v24 + 40);
        *(_QWORD *)(v24 + 40) = 0;
        v39 = v26;
        sub_940223D4(v25);
      }
      else
      {
        __asm { MSR             DAIFSet, #2 }
        sub_940223B4(v25);
        *(_QWORD *)(v24 + 48) = 0;
        v32 = *(_QWORD *)(v24 + 40);
        *(_QWORD *)(v24 + 40) = 0;
        v39 = v32;
        sub_940223D4(v25);
        __asm { MSR             DAIFClr, #2 }
      }
      return sub_9404ABDC(-536460256, v39);
    }
    else
    {
      v34 = sub_9404B508(v23, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/vqueue.c", 84, "vq");
      v35 = (unsigned __int64 *)(v34 + 56);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      {
        sub_940223B4(v35);
        if ( *(_QWORD *)(v34 + 40) != 0 )
          **(_WORD **)(v34 + 32) |= 1u;
        sub_940223D4(v35);
      }
      else
      {
        __asm { MSR             DAIFSet, #2 }
        sub_940223B4(v35);
        if ( *(_QWORD *)(v34 + 40) != 0 )
        {
          **(_WORD **)(v34 + 32) |= 1u;
          sub_940223D4(v35);
          __asm { MSR             DAIFClr, #2 }
        }
        else
        {
          sub_940223D4(v35);
          __asm { MSR             DAIFClr, #2 }
        }
      }
      return sub_94024FDC(v34 + 72, 1u);
    }
  }
}

/* ===== sub_94031CC0 @ 0x94031CC0 size 576 ===== */
__int64 __fastcall sub_94031CC0(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v4; // x23
  unsigned __int64 *v6; // x22
  int v7; // w19
  int v13; // w3
  int v14; // w4
  unsigned int v15; // w1
  unsigned int v16; // w4
  unsigned int v17; // w3
  __int64 v18; // x8
  __int64 v19; // x3
  __int64 v20; // x5
  __int16 v21; // w7
  __int64 v22; // x0
  unsigned int v23; // w1
  __int64 v24; // x10
  __int64 v25; // x2
  __int64 v26; // x11
  unsigned int v27; // w20

  v4 = v2;
  v6 = (unsigned __int64 *)(a1 + 56);
  v7 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v7 = 1;
  }
  sub_940223B4(v6);
  if ( a1 != 0 )
  {
    if ( a2 != 0 )
    {
      if ( *(_QWORD *)(a1 + 40) == 0 )
      {
LABEL_28:
        v27 = -15;
        goto LABEL_17;
      }
      v13 = *(unsigned __int16 *)(a1 + 64);
      v14 = *(unsigned __int16 *)(*(_QWORD *)(a1 + 24) + 2LL);
      if ( *(unsigned __int16 *)(a1 + 8) >= (unsigned int)(unsigned __int16)(v14 - v13) )
      {
        if ( v14 != v13 )
          goto LABEL_8;
        goto LABEL_23;
      }
    }
    else
    {
      sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/vqueue.c", 118, "iovbuf");
    }
    sub_9404B508(v4, "vq %p: new avail idx out of range (old %u new %u)\n", (const void *)a1, v13, v14);
    goto LABEL_27;
  }
  sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/vqueue.c", 117, "vq");
LABEL_23:
  sub_940250FC(a1 + 72);
  **(_WORD **)(a1 + 32) &= ~1u;
  __dmb(0xBu);
  if ( *(unsigned __int16 *)(a1 + 64) == *(unsigned __int16 *)(*(_QWORD *)(a1 + 24) + 2LL) )
  {
    v27 = -9;
    goto LABEL_17;
  }
  **(_WORD **)(a1 + 32) |= 1u;
  sub_94024FDC(a1 + 72, 0);
LABEL_8:
  __dmb(9u);
  v15 = *(unsigned __int16 *)(a1 + 64);
  v16 = *(_DWORD *)(a1 + 8);
  v17 = *(unsigned __int16 *)(*(_QWORD *)(a1 + 24) + 2LL * (v15 % v16) + 4);
  *(_WORD *)(a1 + 64) = v15 + 1;
  if ( v16 <= v17 )
  {
LABEL_27:
    sub_9404B508(v4, "vq %p: head out of range %u (max %u)\n", (const void *)a1, v17, v16);
    goto LABEL_28;
  }
  v18 = *(_QWORD *)(a1 + 16);
  *(_WORD *)a2 = v17;
  *(_DWORD *)(a2 + 12) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  *(_QWORD *)(a2 + 48) = 0;
  while ( 1 )
  {
    v19 = 16LL * (unsigned __int16)v17;
    v20 = v18 + v19;
    v21 = *(_WORD *)(v18 + v19 + 12);
    if ( (v21 & 2) != 0 )
      v22 = a2 + 40;
    else
      v22 = a2 + 8;
    v23 = *(_DWORD *)(v22 + 4);
    if ( v23 >= *(_DWORD *)v22 )
    {
      v27 = -25;
      goto LABEL_17;
    }
    v24 = *(_QWORD *)(v22 + 16);
    v25 = *(unsigned int *)(v20 + 8);
    v26 = *(_QWORD *)(v18 + v19);
    v17 = *(unsigned __int16 *)(v20 + 14);
    *(_QWORD *)(*(_QWORD *)(v22 + 24) + 16LL * *(unsigned int *)(v22 + 4) + 8) = v25;
    *(_QWORD *)(v24 + 8LL * v23) = v26;
    *(_DWORD *)(v22 + 4) = v23 + 1;
    *(_QWORD *)(v22 + 8) += v25;
    if ( (v21 & 1) == 0 )
      break;
    if ( v16 <= v17 )
    {
      v27 = -7;
      goto LABEL_17;
    }
  }
  v27 = 0;
LABEL_17:
  sub_940223D4(v6);
  if ( v7 != 0 )
    __asm { MSR             DAIFClr, #2 }
  return v27;
}

/* ===== sub_94031F00 @ 0x94031F00 size 404 ===== */
__int64 __fastcall sub_94031F00(__int64 a1, unsigned int a2)
{
  __int64 v2; // x30
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  unsigned int v8; // w3
  unsigned int v9; // w19
  __int64 v10; // x5
  _QWORD *v11; // x3
  unsigned int v12; // w24
  unsigned int v13; // w22
  __int64 v14; // x1
  __int64 v15; // x19
  int v16; // w0
  __int64 v18; // x0

  v5 = v2;
  if ( a1 == 0 )
  {
    v5 = sub_9404B508(v2, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/vqueue.c", 216, "vqiovs");
    goto LABEL_16;
  }
  v6 = *(_QWORD *)(a1 + 16);
  if ( v6 == 0 )
  {
LABEL_16:
    v5 = sub_9404B508(v5, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/vqueue.c", 217, "vqiovs->phys");
    goto LABEL_17;
  }
  v7 = *(_QWORD *)(a1 + 24);
  if ( v7 == 0 )
  {
LABEL_17:
    v5 = sub_9404B508(v5, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/vqueue.c", 218, "vqiovs->iovs");
    goto LABEL_18;
  }
  v8 = *(_DWORD *)(a1 + 4);
  if ( v8 > *(_DWORD *)a1 )
  {
LABEL_18:
    v18 = sub_9404B508(
            v5,
            "DEBUG ASSERT FAILED at (%s:%d): %s\n",
            "lk/trusty/lib/trusty/vqueue.c",
            219,
            "vqiovs->used <= vqiovs->cnt");
    return sub_94032094(v18);
  }
  if ( v8 == 0 )
    return 0;
  v9 = 0;
  while ( 1 )
  {
    v10 = *(_QWORD *)(v6 + 8LL * v9);
    v11 = (_QWORD *)(v7 + 16LL * v9);
    *v11 = 0;
    v12 = sub_9404A878(-536460256, "vqueue", (v11[1] + 4095LL) & 0xFFFFFFFFFFFFF000LL, v11, 12, v10, 0, a2);
    if ( v12 != 0 )
      break;
    if ( *(_DWORD *)(a1 + 4) <= ++v9 )
      return 0;
    v7 = *(_QWORD *)(a1 + 24);
    v6 = *(_QWORD *)(a1 + 16);
  }
  v13 = v9 - 1;
  if ( v9 != 0 )
  {
    v14 = *(_QWORD *)(a1 + 24);
    do
    {
      v15 = 16LL * v13;
      sub_9404ABDC(-536460256, *(_QWORD *)(v14 + v15));
      v14 = *(_QWORD *)(a1 + 24);
      v16 = v13--;
      *(_QWORD *)(v14 + v15) = 0;
    }
    while ( v16 != 0 );
  }
  return v12;
}

/* ===== sub_94032094 @ 0x94032094 size 332 ===== */
__int64 *__fastcall sub_94032094(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x23
  __int64 *result; // x0
  unsigned int v5; // w1
  __int64 v6; // x1
  __int64 v7; // x21
  unsigned int v8; // w19
  unsigned int v9; // w1
  __int64 v10; // x0

  v3 = v1;
  if ( a1 == 0 )
  {
    sub_9404B508(v1, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/vqueue.c", 244, "vqiovs");
  }
  else if ( *(_QWORD *)(a1 + 16) != 0 )
  {
    result = *(__int64 **)(a1 + 24);
    if ( result == nullptr )
    {
LABEL_14:
      sub_9404B508(v1, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/vqueue.c", 246, "vqiovs->iovs");
      goto LABEL_15;
    }
    v5 = *(_DWORD *)(a1 + 4);
    if ( v5 > *(_DWORD *)a1 )
    {
LABEL_15:
      v10 = sub_9404B508(
              v1,
              "DEBUG ASSERT FAILED at (%s:%d): %s\n",
              "lk/trusty/lib/trusty/vqueue.c",
              247,
              "vqiovs->used <= vqiovs->cnt");
      return (__int64 *)sub_940321E0(v10);
    }
    if ( v5 != 0 )
    {
      v6 = *result;
      if ( *result != 0 )
      {
        v7 = 0;
        v8 = 0;
        while ( 1 )
        {
          ++v8;
          sub_9404ABDC(-536460256, v6);
          result = *(__int64 **)(a1 + 24);
          v9 = *(_DWORD *)(a1 + 4);
          result[v7] = 0;
          if ( v9 <= v8 )
            break;
          v7 = 2LL * v8;
          v6 = result[v7];
          if ( v6 == 0 )
            return (__int64 *)sub_9404B508(
                                v3,
                                "DEBUG ASSERT FAILED at (%s:%d): %s\n",
                                "lk/trusty/lib/trusty/vqueue.c",
                                251,
                                "vqiovs->iovs[i].base");
        }
      }
      else
      {
        return (__int64 *)sub_9404B508(
                            v3,
                            "DEBUG ASSERT FAILED at (%s:%d): %s\n",
                            "lk/trusty/lib/trusty/vqueue.c",
                            251,
                            "vqiovs->iovs[i].base");
      }
    }
    return result;
  }
  sub_9404B508(v1, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/vqueue.c", 245, "vqiovs->phys");
  goto LABEL_14;
}

/* ===== sub_940321E0 @ 0x940321E0 size 280 ===== */
__int64 __fastcall sub_940321E0(__int64 a1, unsigned __int16 *a2, int a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  unsigned __int64 *v6; // x21
  int v7; // w20
  unsigned int v13; // w3
  unsigned int v14; // w0
  __int64 v15; // x0
  __int64 v16; // x1
  unsigned int v17; // w19

  v4 = v3;
  v6 = (unsigned __int64 *)(a1 + 56);
  v7 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v7 = 1;
  }
  sub_940223B4(v6);
  if ( a1 == 0 )
  {
    sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/vqueue.c", 262, "vq");
  }
  else if ( a2 != nullptr )
  {
    if ( *(_QWORD *)(a1 + 40) == 0 )
    {
LABEL_13:
      v17 = -15;
      goto LABEL_8;
    }
    v13 = *a2;
    v14 = *(_DWORD *)(a1 + 8);
    if ( v13 >= v14 )
    {
      v17 = -7;
    }
    else
    {
      v15 = *(_QWORD *)(a1 + 32) + 8LL * (*(unsigned __int16 *)(*(_QWORD *)(a1 + 32) + 2LL) % v14);
      *(_DWORD *)(v15 + 4) = v13;
      *(_DWORD *)(v15 + 8) = a3;
      __dmb(0xAu);
      v16 = *(_QWORD *)(a1 + 32);
      v17 = 0;
      ++*(_WORD *)(v16 + 2);
    }
LABEL_8:
    sub_940223D4(v6);
    if ( v7 != 0 )
      __asm { MSR             DAIFClr, #2 }
    return v17;
  }
  sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/vqueue.c", 263, "buf");
  goto LABEL_13;
}

/* ===== sub_940322F8 @ 0x940322F8 size 100 ===== */
__int64 sub_940322F8()
{
  __int64 result; // x0

  if ( MEMORY[0xFFFFFFFFE003CB98] > 0 )
    sub_9404B2FC("Initializing Trusted OS SMC handler\n");
  result = sub_9402985C(0x32u, &qword_9405AD50);
  if ( (_DWORD)result != 0 )
    return sub_9404CB4C("%s:%d: WARNING: Cannot register SMC entity! (%d)\n", "trusty_sm_init", 138, result);
  return result;
}

/* ===== sub_9403235C @ 0x9403235C size 192 ===== */
__int64 __fastcall sub_9403235C(unsigned int *a1, __int64 *a2, _DWORD *a3, int *a4)
{
  __int64 v4; // x30
  __int64 result; // x0

  if ( a2 == nullptr )
  {
    sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/smcall.c", 45, "ppa");
  }
  else if ( a3 != nullptr )
  {
    if ( a4 == nullptr )
    {
LABEL_12:
      sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/smcall.c", 47, "pflags");
      return 4294967288LL;
    }
    result = sub_94029A5C(a1, a2, a3, a4);
    if ( (_DWORD)result != 0 )
      return result;
    if ( (*a4 & 3u) > 1 )
      return 4294967288LL;
    if ( (*a4 & 0xC) != 0 )
      return 4294967288LL;
    else
      return 0;
  }
  sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/smcall.c", 46, "psz");
  goto LABEL_12;
}

/* ===== sub_9403241C @ 0x9403241C size 260 ===== */
__int64 __fastcall sub_9403241C(unsigned int *a1)
{
  __int64 result; // x0
  unsigned int v2; // [xsp+10h] [xbp+10h] BYREF
  unsigned int v3; // [xsp+14h] [xbp+14h] BYREF
  __int64 v4; // [xsp+18h] [xbp+18h] BYREF

  switch ( *a1 )
  {
    case 0x32000014u:
      result = (int)sub_9403235C(a1, &v4, &v2, (int *)&v3);
      if ( (_DWORD)result == 0 )
        result = sub_940325BC(v4, v2, v3);
      break;
    case 0x32000015u:
      result = (int)sub_9403235C(a1, &v4, &v2, (int *)&v3);
      if ( (_DWORD)result == 0 )
        result = (int)sub_94032838(v4, v2, v3);
      break;
    case 0x32000016u:
      result = (int)sub_9403235C(a1, &v4, &v2, (int *)&v3);
      if ( (_DWORD)result == 0 )
        result = (int)sub_940329CC(v4, v2, v3);
      break;
    case 0x32000017u:
      result = (int)sub_94032A80(a1[1]);
      break;
    case 0x32000018u:
      result = (int)sub_94032AFC(a1[1], a1[2]);
      break;
    default:
      result = -24;
      break;
  }
  return result;
}

/* ===== sub_94032520 @ 0x94032520 size 156 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_94032520(__int64 a1)
{
  _QWORD *v1; // x1
  unsigned int v2; // w7

  if ( a1 != 0
    && (v1 = *(_QWORD **)(a1 + 32)) != nullptr
    && *v1 != 0
    && v1[1] != 0
    && v1[2] != 0
    && v1[3] != 0
    && v1[4] != 0 )
  {
    dword_9405AD64 = 1;
    *(_QWORD *)(a1 + 16) = -536629896;
    v2 = 0;
    *(_QWORD *)(a1 + 24) = &off_9405AD78;
    *(_DWORD *)(a1 + 4) = 0;
    dword_9405AD60 = 1;
    MEMORY[0xFFFFFFFFE003AD80] = a1 + 16;
    off_9405AD78 = (_UNKNOWN *)(a1 + 16);
  }
  else
  {
    return (unsigned int)-8;
  }
  return v2;
}

/* ===== sub_940325BC @ 0x940325BC size 636 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_940325BC(__int64 a1, int a2, int a3)
{
  __int64 v3; // x30
  __int64 v5; // x24
  __int64 *v6; // x25
  _DWORD *v7; // x23
  __int64 v8; // x19
  unsigned __int64 v9; // x20
  __int64 (__fastcall **v10)(__int64); // x1
  int v11; // w0
  _UNKNOWN **v12; // x19
  bool v13; // zf
  __int64 result; // x0
  __int64 v15; // x20
  _DWORD *v16; // [xsp+68h] [xbp+68h] BYREF

  v5 = v3;
  LODWORD(v6) = a2;
  LODWORD(v7) = a3;
  v8 = -536629912;
  v9 = 16;
  if ( &off_9405AD78 != (_UNKNOWN **)-536629896LL )
  {
    do
    {
      v10 = *(__int64 (__fastcall ***)(__int64))(v8 + 32);
      *(_DWORD *)(v8 + 8) = v9;
      v11 = (*v10)(v8);
      v12 = *(_UNKNOWN ***)(v8 + 24);
      v9 = (unsigned int)(v9 + v11);
      v13 = v12 == &off_9405AD78;
      v8 = (__int64)(v12 - 2);
    }
    while ( !v13 );
  }
  qword_9405AD68 = v9;
  dword_9405AD70 = 1;
  while ( 1 )
  {
    if ( v9 > (unsigned int)v6 )
      return -9;
    v16 = nullptr;
    if ( a1 == 0 || (a1 & 0xFFF) != 0 )
      return -8;
    v6 = &qword_9405BFF0[2];
    LODWORD(result) = sub_9404A878(
                        -536460256,
                        "virtio",
                        (v9 + 4095) & 0xFFFFFFFFFFFFF000LL,
                        &v16,
                        12,
                        a1,
                        0,
                        (unsigned int)v7);
    if ( (_DWORD)result != 0 )
      return (int)result;
    sub_9404CDC4(v16, 0, 0);
    v7 = v16;
    v16[1] = 0;
    *v7 = 1;
    if ( &off_9405AD78 == (_UNKNOWN **)-536629896LL )
      break;
    v15 = MEMORY[0xFFFFFFFFE003AD70];
    a1 = 0;
    if ( MEMORY[0xFFFFFFFFE003AD70] == 0 )
    {
      if ( v15 + ((__int64 (__fastcall *)(__int64))*MEMORY[0xFFFFFFFFE003AD88])(-536629912) != 0 )
        sub_9404B508(
          v5,
          "DEBUG ASSERT FAILED at (%s:%d): %s\n",
          "lk/trusty/lib/trusty/trusty_virtio.c",
          215,
          "vd->descr_offset + vd->ops->descr_sz(vd) <= vb->descr_size");
      sub_9404B508(
        v5,
        "DEBUG ASSERT FAILED at (%s:%d): %s\n",
        "lk/trusty/lib/trusty/trusty_virtio.c",
        216,
        "vdev_idx < vb->vdev_cnt");
      return -9;
    }
    sub_9404B508(
      v5,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      "lk/trusty/lib/trusty/trusty_virtio.c",
      214,
      "vd->descr_offset <= vb->descr_size");
    v9 = -536629896;
  }
  sub_9404ABDC(-536460256, v7);
  return 0;
}

/* ===== sub_94032838 @ 0x94032838 size 404 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_94032838(__int64 a1, int a2, unsigned int a3)
{
  unsigned int v3; // w4
  unsigned int v4; // w20
  __int64 result; // x0
  __int64 v8; // x23
  __int64 v9; // x20
  _UNKNOWN **v10; // x20
  bool v11; // zf
  int v12; // [xsp+54h] [xbp+54h]
  __int64 v13; // [xsp+58h] [xbp+58h] BYREF

  v13 = 0;
  v12 = 1;
  do
    v3 = __ldxr((unsigned int *)&dword_9405AD70);
  while ( v3 == 1 && __stxr(2u, (unsigned int *)&dword_9405AD70) != 0 );
  if ( v3 != 1 )
    v12 = v3;
  if ( v12 != 1 )
    return 4294967265LL;
  v4 = -8;
  if ( a2 != 0 )
    goto LABEL_8;
  v8 = sub_9404CBC4(0);
  if ( v8 == 0 )
  {
    v4 = -5;
    goto LABEL_8;
  }
  if ( a1 == 0 || (a1 & 0xFFF) != 0 || (v4 = sub_9404A878(-536460256, "virtio", 0, &v13, 12, a1, 0, a3)) != 0 )
  {
    sub_9404CC20(v8);
LABEL_8:
    result = v4;
    dword_9405AD70 = 1;
    return result;
  }
  sub_9404CC78(v8, v13, 0);
  v9 = -536629912;
  if ( &off_9405AD78 != (_UNKNOWN **)-536629896LL )
  {
    do
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v9 + 32) + 16LL))(v9, v8 + *(unsigned int *)(v9 + 8));
      v10 = *(_UNKNOWN ***)(v9 + 24);
      v11 = v10 == &off_9405AD78;
      v9 = (__int64)(v10 - 2);
    }
    while ( !v11 );
  }
  sub_9404ABDC(-536460256, v13);
  sub_9404CC20(v8);
  dword_9405AD70 = 3;
  return 0;
}

/* ===== sub_940329CC @ 0x940329CC size 180 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_940329CC()
{
  unsigned int v0; // w2
  __int64 v1; // x19
  _UNKNOWN **v2; // x19
  bool v3; // zf
  __int64 result; // x0
  int v5; // [xsp+3Ch] [xbp+3Ch]

  v5 = 3;
  do
    v0 = __ldxr((unsigned int *)&dword_9405AD70);
  while ( v0 == 3 && __stxr(4u, (unsigned int *)&dword_9405AD70) != 0 );
  if ( v0 != 3 )
    v5 = v0;
  if ( v5 != 3 )
    return 4294967265LL;
  v1 = -536629912;
  if ( &off_9405AD78 != (_UNKNOWN **)-536629896LL )
  {
    do
    {
      (*(void (__fastcall **)(__int64))(*(_QWORD *)(v1 + 32) + 24LL))(v1);
      v2 = *(_UNKNOWN ***)(v1 + 24);
      v3 = v2 == &off_9405AD78;
      v1 = (__int64)(v2 - 2);
    }
    while ( !v3 );
  }
  result = 0;
  dword_9405AD70 = 1;
  return result;
}

/* ===== sub_94032A80 @ 0x94032A80 size 124 ===== */
__int64 sub_94032A80()
{
  return 4294967265LL;
}

/* ===== sub_94032AFC @ 0x94032AFC size 124 ===== */
__int64 sub_94032AFC()
{
  return 4294967265LL;
}

/* ===== sub_94032B78 @ 0x94032B78 size 8 ===== */
__int64 __fastcall sub_94032B78(__int64 a1)
{
  return *(_QWORD *)(a1 + 56);
}

/* ===== sub_94032B80 @ 0x94032B80 size 60 ===== */
__int64 __fastcall sub_94032B80(__int64 a1, __int64 a2)
{
  sub_9404CC78(a2, *(_QWORD *)(a1 + 48), *(_QWORD *)(a1 + 56));
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(a1 + 4);
  return *(_QWORD *)(a1 + 56);
}

/* ===== sub_94032BBC @ 0x94032BBC size 24 ===== */
__int64 sub_94032BBC()
{
  ((void (*)(void))loc_94031C08)();
  return 0;
}

/* ===== sub_94032BD4 @ 0x94032BD4 size 24 ===== */
__int64 sub_94032BD4()
{
  ((void (*)(void))loc_94031C08)();
  return 0;
}

/* ===== sub_94032BEC @ 0x94032BEC size 132 ===== */
__int64 __fastcall sub_94032BEC(__int64 a1, int a2)
{
  __int64 v2; // x30
  __int64 v3; // x0
  __int64 (__fastcall *v4)(__int64, _QWORD); // x2

  if ( a1 == 0 )
  {
    sub_9404B508(v2, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 1071, "vd");
    return 4294967294LL;
  }
  if ( *(_DWORD *)(a1 + 64) == a2 )
  {
    v3 = a1 + 64;
    v4 = *(__int64 (__fastcall **)(__int64, _QWORD))(v3 + 120);
    if ( v4 != nullptr )
      return v4(v3, *(_QWORD *)(v3 + 136));
    return 0;
  }
  if ( a2 != *(_DWORD *)(a1 + 208) )
    return 4294967294LL;
  v3 = a1 + 208;
  v4 = *(__int64 (__fastcall **)(__int64, _QWORD))(v3 + 120);
  if ( v4 == nullptr )
    return 0;
  return v4(v3, *(_QWORD *)(v3 + 136));
}

/* ===== sub_94032C70 @ 0x94032C70 size 372 ===== */
__int64 __fastcall sub_94032C70(__int64 a1, unsigned __int64 a2, _QWORD *a3)
{
  __int64 v3; // x30
  unsigned int v4; // w19
  __int64 v6; // x0
  __int64 v7; // x2
  __int64 v8; // x30
  __int64 v9; // x1
  __int64 v10; // x5
  __int64 v11; // x0
  unsigned int v12; // w1
  __int64 v13; // x0
  _QWORD v14[2]; // [xsp+10h] [xbp-30h] BYREF
  int v15; // [xsp+20h] [xbp-20h] BYREF
  _QWORD *v16; // [xsp+28h] [xbp-18h]
  int v17; // [xsp+30h] [xbp-10h]
  __int64 v18; // [xsp+38h] [xbp-8h]

  v4 = a2;
  if ( a1 == 0 )
  {
    sub_9404B508(v3, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 1204, "dst");
  }
  else if ( a3 != nullptr )
  {
    if ( *a3 == 0 )
    {
LABEL_8:
      sub_9404B508(v3, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 1206, "buf->data");
      goto LABEL_9;
    }
    if ( a3[1] >= a2 )
    {
      sub_9404CC78(a1, *a3, a2);
      return v4;
    }
LABEL_9:
    v6 = sub_9404B508(
           v3,
           "DEBUG ASSERT FAILED at (%s:%d): %s\n",
           "lk/trusty/lib/trusty/tipc_dev.c",
           1207,
           "sz <= buf->len");
    v10 = v9;
    if ( v6 != 0 )
    {
      if ( v7 != 0 )
      {
        v14[0] = v6;
        v11 = *(_QWORD *)v7;
        v12 = *(_DWORD *)(v7 + 12);
        v15 = 1;
        v14[1] = v10;
        v16 = v14;
        v17 = 0;
        v18 = 0;
        return sub_94031564(v11, v12, 0, (__int64)&v15);
      }
    }
    else
    {
      sub_9404B508(v8, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 668, "buf");
    }
    v13 = sub_9404B508(v8, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 669, "cb_ctx");
    return sub_94032DE4(v13);
  }
  sub_9404B508(v3, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 1205, "buf");
  goto LABEL_8;
}

/* ===== sub_94032DE4 @ 0x94032DE4 size 428 ===== */
__int64 __fastcall sub_94032DE4(
        __int64 a1,
        int a2,
        int a3,
        __int64 (__fastcall *a4)(__int64, __int64, __int64),
        __int64 a5,
        unsigned __int16 a6)
{
  __int64 v6; // x30
  __int64 v12; // x21
  __int64 v13; // x22
  __int64 v14; // x19
  __int64 result; // x0
  int v16; // w2
  __int64 v17; // x1
  __int64 v18; // x0
  unsigned __int64 v19; // x2
  int v20; // w0
  int v21; // w19
  char v22; // [xsp+60h] [xbp+60h] BYREF
  char v23; // [xsp+68h] [xbp+68h] BYREF
  unsigned __int16 v24[20]; // [xsp+78h] [xbp+78h] BYREF
  _DWORD v25[4]; // [xsp+A0h] [xbp+A0h] BYREF
  char *v26; // [xsp+B0h] [xbp+B0h]
  __int64 *v27; // [xsp+B8h] [xbp+B8h]

  v12 = a1 + 64;
  if ( a1 == 0 )
  {
    sub_9404B508(v6, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 1100, "dev");
  }
  else if ( a4 != nullptr )
  {
    v13 = a1 + 136;
    v14 = a1 + 69632;
    sub_9404CDC4(v24, 0, 72);
    v25[0] = 1;
    v26 = &v22;
    v27 = (__int64 *)&v23;
    while ( 1 )
    {
      result = sub_94031CC0(v12, (__int64)v24);
      if ( (_DWORD)result == 0 )
        break;
      if ( (_DWORD)result != -9 )
        return result;
      sub_94024EFC(v13, 0xFFFFFFFFLL);
      if ( *(_BYTE *)(v14 + 584) != 0 )
        return 4294967281LL;
    }
    v16 = -9;
    if ( v25[1] != 0 && (unsigned __int64)v27[1] > 0xF )
    {
      v16 = sub_94031F00((__int64)v25, 0x30u);
      if ( v16 == 0 )
      {
        v17 = a6;
        v18 = *v27;
        v19 = v27[1];
        *(_DWORD *)v18 = a2;
        *(_DWORD *)(v18 + 4) = a3;
        *(_DWORD *)(v18 + 8) = 0;
        *(_WORD *)(v18 + 12) = a6;
        *(_WORD *)(v18 + 14) = 0;
        if ( (unsigned __int64)a6 + 16 > v19 )
          v17 = (unsigned __int16)(v19 - 16);
        v20 = a4(v18 + 16, v17, a5);
        v21 = v20;
        if ( v20 >= 0 )
          v21 = v20 + 16;
        sub_94032094((__int64)v25);
        v16 = v21;
      }
    }
    return sub_940321E0(v12, v24, v16);
  }
  return 4294967288LL;
}

/* ===== sub_94032F90 @ 0x94032F90 size 548 ===== */
__int64 __fastcall sub_94032F90(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v4; // x0
  __int64 result; // x0
  unsigned int *v7; // x22
  __int64 v8; // x25
  __int64 v9; // x24
  unsigned int v10; // w23
  unsigned int v11; // w21
  _DWORD *v12; // x0
  _DWORD *v13; // x0
  __int64 v14; // [xsp+68h] [xbp+68h] BYREF
  _QWORD v15[2]; // [xsp+70h] [xbp+70h] BYREF
  _BYTE v16[32]; // [xsp+80h] [xbp+80h] BYREF

  v4 = v2;
  if ( a1 == 0 )
  {
    v4 = sub_9404B508(v2, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 1062, "vd");
  }
  else if ( a2 != 0 )
  {
    if ( *(_DWORD *)a1 != 0 )
      return 4294967265LL;
    result = 4294967288LL;
    if ( *(_DWORD *)a2 == 3 && *(_DWORD *)(a2 + 4) == 13 && *(_BYTE *)(a2 + 25) == 2 && *(_BYTE *)(a2 + 24) == 7 )
    {
      v7 = (unsigned int *)(a2 + 28);
      v8 = a1 + 64;
      v9 = 0;
      v10 = 0;
      do
      {
        v11 = sub_940319F4(v8, v7[3], *v7 | ((unsigned __int64)v7[4] << 32), v7[2], v7[1], a1, qword_9405ADB0[v9], 0);
        if ( v11 != 0 )
        {
          if ( v10 != 0 )
            ((void (__fastcall *)(__int64))loc_94031B4C)(a1 + 64);
          return v11;
        }
        ++v10;
        v7 += 5;
        ++v9;
        v8 += 144;
      }
      while ( v10 < *(unsigned __int8 *)(a2 + 25) );
      sub_9404CAC0(v16, 32, "tipc-dev%d-rx", *(_DWORD *)(a1 + 4));
      v12 = (_DWORD *)sub_940268B8((__int64)v16, (__int64)sub_94033318, a1, 0x10u, 4096);
      *(_QWORD *)(a1 + 70200) = v12;
      if ( v12 != nullptr )
        sub_940260B0(v12);
      sub_9404CAC0(v16, 32, "tipc-dev%d-tx", *(_DWORD *)(a1 + 4));
      v13 = (_DWORD *)sub_940268B8((__int64)v16, (__int64)sub_94033B30, a1, 0x10u, 4096);
      *(_QWORD *)(a1 + 70208) = v13;
      if ( v13 != nullptr )
        sub_940260B0(v13);
      v15[1] = 8;
      v14 = 1;
      v15[0] = &v14;
      result = sub_94032DE4(
                 a1,
                 53,
                 53,
                 (__int64 (__fastcall *)(__int64, __int64, __int64))sub_94032C70,
                 (__int64)v15,
                 8u);
      if ( (_DWORD)result == 0 )
        *(_DWORD *)a1 = 1;
    }
    return result;
  }
  sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 1063, "descr");
  return 4294967265LL;
}

/* ===== sub_940331B4 @ 0x940331B4 size 96 ===== */
__int64 __fastcall sub_940331B4(__int64 a1, int a2, int a3, int a4, int a5, int a6)
{
  _QWORD v7[2]; // [xsp+10h] [xbp+10h] BYREF
  _DWORD v8[8]; // [xsp+20h] [xbp+20h] BYREF

  v8[4] = a2;
  v8[3] = a4;
  v8[0] = 4;
  v8[2] = a3;
  v8[5] = a5;
  v8[6] = a6;
  v8[1] = 20;
  v7[1] = 28;
  v7[0] = v8;
  return sub_94032DE4(a1, 53, 53, (__int64 (__fastcall *)(__int64, __int64, __int64))sub_94032C70, (__int64)v7, 0x1Cu);
}

/* ===== sub_94033214 @ 0x94033214 size 260 ===== */
__int64 __fastcall sub_94033214(_QWORD *a1, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x4
  unsigned __int64 v5; // x4
  unsigned int v6; // w19
  unsigned int *v7; // x4
  unsigned int v8; // w6
  __int64 v9; // x4
  _QWORD *v10; // x5
  __int64 v13; // x6
  int v14; // w4
  unsigned __int64 v15; // x6
  int v16; // w19

  v4 = a1[8748];
  if ( v4 != -1 )
  {
    v5 = ~v4;
    v6 = __clz(__rbit64(v5));
    if ( v5 == 0 )
      v6 = -1;
    goto LABEL_4;
  }
  v13 = a1[8749];
  v14 = 1;
  if ( v13 == -1 )
  {
    v13 = a1[8750];
    v14 = 2;
    if ( v13 == -1 )
    {
      v13 = a1[8751];
      if ( v13 == -1 )
        return 0;
      v14 = 3;
    }
  }
  v15 = ~v13;
  v16 = __clz(__rbit64(v15));
  if ( v15 == 0 )
    v16 = -1;
  v6 = v16 + (v14 << 6);
  if ( v6 <= 0xFF )
  {
LABEL_4:
    v7 = (unsigned int *)a1 + (v6 >> 5) + 17496;
    do
      v8 = __ldxr(v7);
    while ( __stxr(v8 | (1 << v6), v7) != 0 );
    v9 = 34LL * (int)v6;
    v10 = &a1[v9];
    v10[45] = a3;
    *((_DWORD *)v10 + 88) = a2;
    if ( a4 != 0 )
      sub_9404CF0C(&a1[v9 + 46], a4);
    return v6 + 1000;
  }
  return 0;
}

/* ===== sub_94033318 @ 0x94033318 size 1532 ===== */
__int64 __fastcall sub_94033318(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x28
  int v4; // w0
  __int64 v5; // x21
  int v6; // w3
  unsigned __int64 v7; // x0
  int *v8; // x1
  int v9; // w5
  int v10; // w3
  unsigned __int64 v11; // x2
  int v12; // w0
  __int64 v14; // x4
  __int64 v15; // x2
  __int64 v16; // x0
  int v17; // w0
  __int64 v18; // x21
  __int64 v19; // x0
  __int64 v20; // x6
  _DWORD *v21; // x2
  unsigned __int64 v22; // x0
  __int64 v23; // x2
  unsigned __int64 v24; // x0
  __int64 v25; // x0
  int v26; // w0
  int v27; // w5
  __int64 v28; // x2
  __int64 v29; // x4
  int v30; // w21
  unsigned int *v31; // x1
  unsigned int v32; // w3
  __int64 v33; // x0
  unsigned int v34; // w21
  int v35; // w3
  int v36; // w1
  int v37; // [xsp+60h] [xbp+60h]
  __int64 v38; // [xsp+60h] [xbp+60h]
  int v39; // [xsp+68h] [xbp+68h]
  int v40; // [xsp+68h] [xbp+68h]
  __int64 v41; // [xsp+68h] [xbp+68h]
  __int64 v42; // [xsp+68h] [xbp+68h]
  int v43; // [xsp+70h] [xbp+70h]
  _QWORD *v44; // [xsp+70h] [xbp+70h]
  int v45; // [xsp+70h] [xbp+70h]
  char v46; // [xsp+88h] [xbp+88h] BYREF
  __int64 v47; // [xsp+90h] [xbp+90h] BYREF
  __int64 v48; // [xsp+98h] [xbp+98h] BYREF
  _QWORD v49[2]; // [xsp+A8h] [xbp+A8h] BYREF
  __int64 v50; // [xsp+B8h] [xbp+B8h] BYREF
  _DWORD v51[4]; // [xsp+C0h] [xbp+C0h] BYREF
  char *v52; // [xsp+D0h] [xbp+D0h]
  int **v53; // [xsp+D8h] [xbp+D8h]
  _QWORD v54[32]; // [xsp+100h] [xbp+100h] BYREF

  v3 = v1;
  sub_9404CDC4(&v50, 0, 72);
  v51[0] = 1;
  v52 = &v46;
  v53 = (int **)&v48;
  do
  {
LABEL_2:
    if ( *(_BYTE *)(a1 + 70217) == 0 )
    {
      sub_94024EFC(a1 + 280, 0xFFFFFFFFLL);
      v4 = sub_94031CC0(a1 + 208, (__int64)&v50);
      if ( v4 != -15 )
        continue;
    }
    return 0;
  }
  while ( v4 == -9 );
  LODWORD(v5) = v4;
  if ( v4 != 0 )
    goto LABEL_11;
  if ( v51[1] != 0 )
  {
    v6 = sub_94031F00((__int64)v51, 0x38u);
    if ( v6 != 0 )
    {
      LODWORD(v5) = v6;
      sub_9404CB4C("%s:%d: failed to map iovs %d\n", "handle_rx_msg", 574, v6);
      goto LABEL_11;
    }
    v7 = (unsigned __int64)v53[1];
    if ( v7 <= 0xF )
      goto LABEL_14;
    v8 = *v53;
    v5 = 4294967288LL;
    v9 = **v53;
    v10 = (*v53)[1];
    v11 = *((unsigned __int16 *)*v53 + 6);
    if ( v7 != v11 + 16 )
      goto LABEL_10;
    if ( v10 != 53 )
    {
      v49[0] = v8 + 4;
      v37 = v10;
      v54[0] = 1;
      v39 = v9;
      LODWORD(v5) = -2;
      v54[2] = 0;
      v54[3] = 0;
      v49[1] = v11;
      v54[1] = v49;
      sub_940251F8(a1 + 70144, 0xFFFFFFFFLL);
      v14 = a1 + 70144;
      if ( (unsigned int)(v37 - 1000) <= 0xFF
        && ((*(_QWORD *)(a1 + 8 * ((unsigned __int64)(unsigned int)(v37 - 1000) >> 6) + 69984) >> ((unsigned __int8)v37
                                                                                                 + 24))
          & 1) != 0 )
      {
        v15 = a1 + 272LL * (unsigned int)(v37 - 1000);
        if ( v39 == *(_DWORD *)(v15 + 352) )
        {
          v16 = *(_QWORD *)(v15 + 360);
          if ( v16 != 0 )
          {
            LODWORD(v5) = sub_94030F50(v16, (__int64)v54);
            v14 = a1 + 70144;
          }
        }
      }
      sub_9402530C(v14);
      goto LABEL_10;
    }
    if ( v8 == (int *)-16LL )
    {
      LODWORD(v24) = sub_9404B508(
                       v3,
                       "DEBUG ASSERT FAILED at (%s:%d): %s\n",
                       "lk/trusty/lib/trusty/tipc_dev.c",
                       474,
                       "ns_data");
      goto LABEL_51;
    }
    if ( v11 <= 7 || (v17 = v8[4], v18 = (unsigned int)v8[5], v11 != v18 + 8) )
    {
LABEL_49:
      LODWORD(v5) = -7;
      goto LABEL_10;
    }
    if ( v17 != 3 )
    {
      if ( v17 == 5 )
      {
        v43 = *v8;
        if ( v18 == 4 )
        {
          v5 = a1 + 70144;
          v40 = v8[6];
          sub_940251F8(a1 + 70144, 0xFFFFFFFFLL);
          if ( (unsigned int)(v40 - 1000) <= 0xFF
            && ((*(_QWORD *)(a1 + 8 * ((unsigned __int64)(unsigned int)(v40 - 1000) >> 6) + 69984) >> ((unsigned __int8)v40 + 24))
              & 1) != 0
            && (v19 = 272LL * (unsigned int)(v40 - 1000), v43 == *(_DWORD *)(a1 + v19 + 352)) )
          {
            v20 = a1 + 352;
            v23 = a1 + v19 + 352;
          }
          else
          {
            v20 = a1 + 352;
            v21 = (_DWORD *)(a1 + 352);
            v22 = 0;
            while ( ((*(_QWORD *)(a1 + 69984 + 8 * (v22 >> 6)) >> v22) & 1) == 0 || v43 != *v21 )
            {
              ++v22;
              v21 += 68;
              if ( v22 == 256 )
                goto LABEL_43;
            }
            v23 = a1 + 272LL * (unsigned int)v22 + 352;
          }
          if ( *(_QWORD *)(v23 + 8) != 0 )
          {
            v38 = v20;
            v41 = v23;
            v44 = *(_QWORD **)(v23 + 8);
            sub_9402DE38(a1 + 70064, v44);
            v44[12] = 0;
            sub_9402DADC((__int64)v44);
            v23 = v41;
            v20 = v38;
            if ( *(_BYTE *)(v41 + 16) != 0 )
            {
              sub_9402BE9C((const char *)(v41 + 16), a1);
              v20 = v38;
              v23 = v41;
            }
          }
          v24 = 0xF0F0F0F0F0F0F0F1LL * ((v23 - v20) >> 4);
          if ( (unsigned int)v24 > 0xFF )
          {
LABEL_43:
            v25 = v5;
            LODWORD(v5) = 0;
            sub_9402530C(v25);
            goto LABEL_10;
          }
LABEL_51:
          v31 = (unsigned int *)(a1 + (((__int64)(int)v24 >> 3) & 0x1FFFFFFFFFFFFFFCLL) + 69984);
          do
            v32 = __ldxr(v31);
          while ( __stxr(v32 & ~(1 << v24), v31) != 0 );
          v33 = a1 + 272LL * (unsigned int)v24;
          *(_QWORD *)(v33 + 360) = 0;
          *(_DWORD *)(v33 + 352) = 0;
          *(_BYTE *)(v33 + 368) = 0;
          goto LABEL_43;
        }
      }
      goto LABEL_49;
    }
    v45 = *v8;
    if ( v18 != 256 )
      goto LABEL_49;
    v47 = 0;
    sub_9404D01C(v54, v8 + 6, 256);
    v26 = sub_940300B4(*(_QWORD *)(a1 + 40), (__int64)v54, 0x100u, 0, &v47);
    v27 = v45;
    if ( v26 == -2 )
    {
      sub_9402BDA8((const char *)v54, a1, v45);
      v28 = v47;
      v29 = 0;
      v35 = -2;
      if ( v47 != 0 )
        goto LABEL_48;
    }
    else
    {
      if ( v26 != 0 )
      {
        v28 = v47;
        v29 = 0;
        v30 = 0;
        if ( v47 != 0 )
        {
LABEL_48:
          *(_QWORD *)(v28 + 96) = v29;
          LODWORD(v5) = 0;
          sub_9402DD0C((_QWORD *)(a1 + 70064), v28);
          sub_94024FDC(a1 + 70016, 0);
          goto LABEL_10;
        }
      }
      else
      {
        v42 = a1 + 70144;
        sub_940251F8(a1 + 70144, 0xFFFFFFFFLL);
        v30 = sub_94033214((_QWORD *)a1, v45, v47, 0);
        if ( v30 != 0 )
        {
          sub_9402530C(v42);
          v28 = v47;
          v27 = v45;
          if ( v47 != 0 )
          {
            v34 = v30 - 1000;
            v29 = 0;
            if ( v34 <= 0xFF && ((*(_QWORD *)(a1 + 8 * ((unsigned __int64)v34 >> 6) + 69984) >> v34) & 1) != 0 )
              v29 = a1 + 272LL * v34 + 352;
            goto LABEL_48;
          }
        }
        else
        {
          sub_9402DADC(v47);
          v47 = 0;
          sub_9402530C(v42);
          v28 = v47;
          v29 = 0;
          v27 = v45;
          if ( v47 != 0 )
            goto LABEL_48;
        }
      }
      v36 = v30;
      LODWORD(v5) = 0;
      v35 = sub_940331B4(a1, v36, v27, -41, 0, 0);
      if ( v35 == 0 )
        goto LABEL_10;
    }
    LODWORD(v5) = v35;
    sub_9404CB4C("%s:%d: failed (%d) to send response\n", "handle_conn_req", 406);
    goto LABEL_10;
  }
  LODWORD(v5) = -8;
LABEL_11:
  while ( 1 )
  {
    v12 = sub_940321E0(a1 + 208, (unsigned __int16 *)&v50, v5);
    if ( v12 == -15 )
      return 0;
    if ( v12 == 0 )
      goto LABEL_2;
    sub_9404B508(v3, "Unable (%d) to return buffer to vqueue\n", v12);
LABEL_14:
    LODWORD(v5) = -8;
LABEL_10:
    sub_94032094((__int64)v51);
  }
}

/* ===== sub_94033914 @ 0x94033914 size 540 ===== */
__int64 __fastcall sub_94033914(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x26
  int v5; // w2
  __int64 v6; // x28
  __int64 v7; // x19
  unsigned __int64 v8; // x27
  _QWORD *v9; // x1
  __int64 v10; // x0
  unsigned __int64 v11; // x0
  unsigned int *v12; // x1
  unsigned int v13; // w2
  __int64 v14; // x0
  int v15; // w2
  __int64 v16; // x0
  __int64 v17; // [xsp+68h] [xbp+68h]

  v3 = v1;
  if ( a1 != 0 )
  {
    if ( *(_DWORD *)a1 == 0 )
      return 0;
    v17 = a1 + 208;
    *(_BYTE *)(a1 + 70217) = 1;
    ((void (*)(void))loc_94031C08)();
    v5 = sub_94026D1C(*(_QWORD *)(a1 + 70200), nullptr, 0x3E8u);
    if ( v5 != 0 )
      goto LABEL_17;
    *(_BYTE *)(a1 + 70216) = 1;
    *(_QWORD *)(a1 + 70200) = 0;
    *(_BYTE *)(a1 + 70217) = 0;
    v6 = a1 + 69984;
    sub_940251F8(a1 + 70144, 0xFFFFFFFFLL);
    v7 = a1 + 352;
    v8 = 0;
    do
    {
      while ( 1 )
      {
        if ( ((*(_QWORD *)(v6 + 8 * (v8 >> 6)) >> v8) & 1) != 0 )
        {
          v9 = *(_QWORD **)(v7 + 8);
          if ( v9 != nullptr )
          {
            sub_9402DE38(a1 + 70064, v9);
            v10 = *(_QWORD *)(v7 + 8);
            *(_QWORD *)(v10 + 96) = 0;
            sub_9402DADC(v10);
            v11 = 0xF0F0F0F0F0F0F0F1LL * ((v7 - (a1 + 352)) >> 4);
            if ( (unsigned int)v11 <= 0xFF )
              break;
          }
        }
        v7 += 272;
        ++v8;
        if ( v7 == v6 )
          goto LABEL_13;
      }
      v12 = (unsigned int *)(v6 + (((__int64)(int)v11 >> 3) & 0x1FFFFFFFFFFFFFFCLL));
      do
        v13 = __ldxr(v12);
      while ( __stxr(v13 & ~(1 << v11), v12) != 0 );
      v7 += 272;
      ++v8;
      v14 = a1 + 272LL * (unsigned int)v11;
      *(_QWORD *)(v14 + 360) = 0;
      *(_DWORD *)(v14 + 352) = 0;
      *(_BYTE *)(v14 + 368) = 0;
    }
    while ( v7 != v6 );
LABEL_13:
    sub_9402530C(a1 + 70144);
    sub_94024FDC(a1 + 70016, 0);
    ((void (__fastcall *)(__int64))loc_94031C08)(a1 + 64);
    v15 = sub_94026D1C(*(_QWORD *)(a1 + 70208), nullptr, 0x3E8u);
    if ( v15 == 0 )
    {
      *(_QWORD *)(a1 + 70208) = 0;
      *(_BYTE *)(a1 + 70216) = 0;
      ((void (__fastcall *)(__int64))loc_94031B4C)(v17);
      ((void (__fastcall *)(__int64))loc_94031B4C)(a1 + 64);
      *(_DWORD *)a1 = 0;
      return 0;
    }
  }
  else
  {
    sub_9404B508(v1, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 922, "vd");
  }
  sub_9404B508(v3, "unable to shutdown tx thread: %d\n", v15);
LABEL_17:
  v16 = sub_9404B508(v3, "unable to shutdown rx thread: %d\n", v5);
  return sub_94033B30(v16);
}

/* ===== sub_94033B30 @ 0x94033B30 size 936 ===== */
__int64 __fastcall sub_94033B30(__int64 a1)
{
  __int64 v1; // x25
  __int64 v2; // x19
  int v4; // w3
  __int64 v6; // x19
  __int64 v7; // x0
  int *v8; // x1
  int v9; // w24
  int v10; // w0
  unsigned int v11; // w0
  _QWORD *v12; // x24
  int *v13; // x3
  unsigned __int64 v14; // x22
  unsigned int *v15; // x0
  unsigned int v16; // w3
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // [xsp+68h] [xbp+68h]
  __int64 v22; // [xsp+70h] [xbp+70h]
  int v23; // [xsp+88h] [xbp+88h]
  int v24; // [xsp+88h] [xbp+88h]
  int v25; // [xsp+94h] [xbp+94h] BYREF
  _DWORD *v26; // [xsp+98h] [xbp+98h] BYREF
  _DWORD v27[4]; // [xsp+A0h] [xbp+A0h] BYREF
  _DWORD *v28; // [xsp+B0h] [xbp+B0h] BYREF
  __int64 v29; // [xsp+B8h] [xbp+B8h] BYREF

  v1 = a1 + 69632;
  v2 = *(unsigned __int8 *)(a1 + 70216);
  if ( *(_BYTE *)(a1 + 70216) != 0 )
    return 0;
  v22 = a1 + 70016;
  while ( 1 )
  {
    sub_94024EFC(v22, 0xFFFFFFFFLL);
    v4 = ((__int64 (__fastcall *)(__int64, _DWORD **, int *, __int64))loc_9402DED0)(v1 + 432, &v26, &v25, 0xFFFFFFFFLL);
    if ( v4 != -2 )
      break;
LABEL_11:
    if ( *(_BYTE *)(v1 + 584) != 0 )
      return 0;
  }
  while ( (v4 & 0x80000000) == 0 )
  {
    if ( v26 == nullptr )
    {
      sub_9404B508(v21, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 817, "chan");
LABEL_26:
      sub_9404B508(
        v21,
        "DEBUG ASSERT FAILED at (%s:%d): %s\n",
        "lk/trusty/lib/trusty/tipc_dev.c",
        818,
        "ipc_is_channel(chan)");
LABEL_27:
      v7 = v2;
LABEL_28:
      sub_9402530C(v7);
      goto LABEL_10;
    }
    if ( !sub_9402F2D4((__int64)v26) )
      goto LABEL_26;
    if ( (v25 & 1) != 0 )
    {
      v6 = (__int64)v26;
      sub_940251F8(v1 + 512, 0xFFFFFFFFLL);
      v2 = *(_QWORD *)(v6 + 96);
      v7 = v1 + 512;
      if ( v2 == 0 )
        goto LABEL_28;
      v23 = *(_DWORD *)v2;
      sub_9402530C(v7);
      sub_940331B4(a1, -252645135 * ((v2 - (a1 + 352)) >> 4) + 1000, v23, 0, 4096, 1);
    }
    else
    {
      if ( (v25 & 8) != 0 )
      {
        v2 = (__int64)v26;
        v29 = 0;
        v28 = v26;
        sub_940251F8(v1 + 512, 0xFFFFFFFFLL);
        v8 = *(int **)(v2 + 96);
        v7 = v1 + 512;
        if ( v8 != nullptr )
        {
          v9 = *v8;
          sub_9402530C(v7);
          while ( 1 )
          {
            v10 = sub_940311BC(v2, &v29);
            if ( v10 == -4 )
              goto LABEL_10;
            if ( v10 != 0 )
            {
              sub_9404B508(v21, "%s: failed (%d) to get message\n", "handle_tx_msg", v10);
              goto LABEL_33;
            }
            v11 = sub_94032DE4(
                    a1,
                    0,
                    v9,
                    (__int64 (__fastcall *)(__int64, __int64, __int64))&loc_94032D44,
                    (__int64)&v28,
                    v29);
            if ( v11 != 0 )
              sub_9404CB4C("%s:%d: tipc_send_data failed (%d)\n", "handle_tx_msg", 724, v11);
            sub_940312C8(v2, HIDWORD(v29));
          }
        }
        goto LABEL_28;
      }
      if ( (v25 & 4) != 0 )
      {
        v2 = v1 + 512;
        v12 = v26;
        sub_940251F8(v1 + 512, 0xFFFFFFFFLL);
        v13 = (int *)v12[12];
        if ( v13 != nullptr )
        {
          v24 = *v13;
          v14 = 0xF0F0F0F0F0F0F0F1LL * (((__int64)v13 - a1 - 352) >> 4);
          sub_9402DE38(v1 + 432, v12);
          v12[12] = 0;
          sub_9402DADC((__int64)v12);
          if ( (unsigned int)v14 <= 0xFF )
          {
            v15 = (unsigned int *)(a1 + (((__int64)(int)v14 >> 3) & 0x1FFFFFFFFFFFFFFCLL) + 69984);
            do
              v16 = __ldxr(v15);
            while ( __stxr(v16 & ~(1 << v14), v15) != 0 );
            v17 = a1 + 272LL * (unsigned int)v14;
            *(_QWORD *)(v17 + 360) = 0;
            *(_DWORD *)(v17 + 352) = 0;
            *(_BYTE *)(v17 + 368) = 0;
          }
          sub_9402530C(v1 + 512);
          v27[0] = 5;
          v27[1] = 4;
          v27[2] = v24;
          v28 = v27;
          v29 = 12;
          sub_94032DE4(
            a1,
            v14 + 1000,
            53,
            (__int64 (__fastcall *)(__int64, __int64, __int64))sub_94032C70,
            (__int64)&v28,
            0xCu);
          goto LABEL_10;
        }
        goto LABEL_27;
      }
    }
LABEL_10:
    ((void (__fastcall *)(_DWORD *))loc_9402D978)(v26);
    v4 = ((__int64 (__fastcall *)(__int64, _DWORD **, int *, __int64))loc_9402DED0)(v1 + 432, &v26, &v25, 0xFFFFFFFFLL);
    if ( v4 == -2 )
      goto LABEL_11;
  }
LABEL_33:
  v18 = sub_9404B508(v21, "%s: couldn't wait for handle events (%d)\n", "handle_tx", v4);
  return sub_94033ED8(v18, v19, v20);
}

/* ===== sub_94033ED8 @ 0x94033ED8 size 416 ===== */
__int64 __fastcall sub_94033ED8(__int64 a1, _QWORD *a2, int a3)
{
  __int64 v6; // x2
  _QWORD *v7; // x3
  _QWORD *v8; // x22
  int v9; // w19
  __int64 result; // x0
  unsigned int v11; // w19
  __int64 v12; // [xsp+58h] [xbp+58h] BYREF
  _BYTE v13[256]; // [xsp+60h] [xbp+60h] BYREF

  v12 = 0;
  sub_9404CDC4(v13, 0, 256);
  sub_9404CF0C(v13, a1);
  if ( (unsigned int)sub_940300B4(a2[5], (__int64)v13, 0x100u, 0, &v12) != 0 )
  {
    v6 = v12;
    v7 = nullptr;
    v8 = a2 + 8704;
    v9 = 0;
    if ( v12 != 0 )
    {
LABEL_3:
      *(_QWORD *)(v6 + 96) = v7;
      sub_9402DD0C(v8 + 54, v6);
      sub_94024FDC((__int64)(v8 + 48), 0);
      return 0;
    }
  }
  else
  {
    v8 = a2 + 8704;
    sub_940251F8((__int64)(a2 + 8768), 0xFFFFFFFFLL);
    v9 = sub_94033214(a2, a3, v12, a1);
    if ( v9 != 0 )
    {
      sub_9402530C((__int64)(a2 + 8768));
      v6 = v12;
      if ( v12 != 0 )
      {
        v7 = nullptr;
        if ( (unsigned int)(v9 - 1000) <= 0xFF
          && ((a2[((unsigned __int64)(unsigned int)(v9 - 1000) >> 6) + 8748] >> ((unsigned __int8)v9 + 24)) & 1) != 0 )
        {
          v7 = &a2[34 * (unsigned int)(v9 - 1000) + 44];
        }
        goto LABEL_3;
      }
    }
    else
    {
      sub_9402DADC(v12);
      v12 = 0;
      sub_9402530C((__int64)(a2 + 8768));
      v6 = v12;
      v7 = nullptr;
      if ( v12 != 0 )
        goto LABEL_3;
    }
  }
  v11 = sub_940331B4((__int64)a2, v9, a3, -41, 0, 0);
  result = 0;
  if ( v11 != 0 )
  {
    sub_9404CB4C("%s:%d: failed (%d) to send response\n", "tipc_handle_save_ctx", 350, v11);
    return v11;
  }
  return result;
}

/* ===== sub_94034078 @ 0x94034078 size 336 ===== */
__int64 __fastcall sub_94034078(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // x30
  __int64 v9; // x0
  _QWORD *v10; // x19
  __int64 v11; // x20
  unsigned int v12; // w20

  if ( a3 == 0 )
  {
    sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 1238, "uuid");
  }
  else if ( a1 != 0 )
  {
    if ( a2 == 0 )
    {
LABEL_13:
      sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 1240, "size");
      return 4294967291LL;
    }
    v9 = sub_9404CBDC(1, 70224);
    v10 = (_QWORD *)v9;
    if ( v9 == 0 )
      return 4294967291LL;
    v11 = v9 + 69632;
    sub_940251C4(v9 + 70144);
    v10[5] = a3;
    v10[6] = a1;
    v10[4] = qword_9405AD88;
    v10[7] = a2;
    sub_9402DC9C((_QWORD *)(v11 + 432));
    sub_94024DFC(v11 + 384, 0, 1);
    v12 = sub_94032520((__int64)v10);
    if ( v12 != 0 )
    {
      sub_9404CC20(v10);
      return v12;
    }
    else
    {
      if ( a4 != nullptr )
        *a4 = v10;
      return 0;
    }
  }
  sub_9404B508(v4, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "lk/trusty/lib/trusty/tipc_dev.c", 1239, "descr");
  goto LABEL_13;
}

/* ===== sub_940341C8 @ 0x940341C8 size 80 ===== */
__int64 sub_940341C8()
{
  __int64 result; // x0

  result = sub_94034078((__int64)qword_94051880, 108, -536668192, nullptr);
  if ( (_DWORD)result != 0 )
    return sub_9404CB4C("%s:%d: WARNING: failed (%d) to register tipc device\n", "tipc_init", 51, result);
  return result;
}

/* ===== sub_94034218 @ 0x94034218 size 20 ===== */
bool __fastcall sub_94034218(__int64 a1)
{
  return a1 == -536668192;
}

/* ===== nullsub_5 @ 0x9403422C size 4 ===== */
void nullsub_5()
{
  ;
}

/* ===== nullsub_6 @ 0x94034230 size 4 ===== */
void nullsub_6()
{
  ;
}

/* ===== sub_94034234 @ 0x94034234 size 212 ===== */
__int64 __fastcall sub_94034234(int a1)
{
  __int64 v1; // x1
  int v2; // t1
  __int64 v3; // x3
  __int64 result; // x0
  int v5; // w1

  if ( MEMORY[0xFFFFFFFFE003ADE0] == 0 )
    return 0;
  if ( MEMORY[0xFFFFFFFFE003ADC0] != a1 )
  {
    v1 = -536629784;
    while ( 1 )
    {
      v3 = v1;
      if ( *(_QWORD *)(v1 + 32) == 0 )
        return 0;
      v2 = *(_DWORD *)v1;
      v1 += 40;
      if ( v2 == a1 )
        goto LABEL_8;
    }
  }
  v3 = -536629824;
LABEL_8:
  v5 = *(_DWORD *)(v3 + 4);
  if ( v5 > 3 )
    return 0;
  result = v3;
  switch ( v5 )
  {
    case 0:
      *(_QWORD *)(v3 + 8) = MEMORY[0xFFFFFFFFE0061260];
      result = v3;
      break;
    case 1:
      *(_QWORD *)(v3 + 8) = MEMORY[0xFFFFFFFFE0061258];
      result = v3;
      break;
    case 2:
      *(_QWORD *)(v3 + 8) = MEMORY[0xFFFFFFFFE0061250];
      result = v3;
      break;
    case 3:
      *(_QWORD *)(v3 + 8) = MEMORY[0xFFFFFFFFE0061268];
      result = v3;
      break;
    default:
      return result;
  }
  return result;
}

/* ===== sub_94034308 @ 0x94034308 size 160 ===== */
__int64 __fastcall sub_94034308(int a1)
{
  __int64 v2; // x19
  int v3; // w0
  __int64 v4; // x1
  unsigned int v6; // [xsp+2Ch] [xbp+2Ch] BYREF

  v2 = sub_94034234(a1);
  if ( v2 != 0 )
  {
    sub_94040978(&qword_94067928, &v6, 3221225472LL);
    v3 = *(_DWORD *)(v2 + 24);
    if ( v3 == 0 )
    {
      *(_DWORD *)(*(_QWORD *)(v2 + 8) + *(int *)(v2 + 16) + 4096LL) = *(_DWORD *)(v2 + 20);
      v3 = *(_DWORD *)(v2 + 24);
    }
    v4 = v6;
    *(_DWORD *)(v2 + 24) = v3 + 1;
    sub_940409B8(&qword_94067928, v4, 3221225472LL);
    return 0;
  }
  else
  {
    sub_940407DC(2, "clk_get_info type:%d failed\n", a1);
    return 1;
  }
}

/* ===== sub_940343A8 @ 0x940343A8 size 212 ===== */
__int64 __fastcall sub_940343A8(int a1)
{
  __int64 v2; // x19
  int v3; // w0
  unsigned int v4; // w20
  unsigned int v6; // [xsp+3Ch] [xbp+3Ch] BYREF

  v2 = sub_94034234(a1);
  if ( v2 != 0 )
  {
    sub_94040978(&qword_94067928, &v6, 3221225472LL);
    v3 = *(_DWORD *)(v2 + 24);
    if ( v3 != 0 )
    {
      *(_DWORD *)(v2 + 24) = v3 - 1;
      v4 = 0;
      if ( v3 == 1 )
        *(_DWORD *)(*(_QWORD *)(v2 + 8) + *(int *)(v2 + 16) + 0x2000LL) = *(_DWORD *)(v2 + 20);
    }
    else
    {
      v4 = 1;
      sub_940407DC(4, "%s clk:%s enable_count=0!\n", "clk_enable_restore", *(const char **)(v2 + 32));
    }
    sub_940409B8(&qword_94067928, v6, 3221225472LL);
    return v4;
  }
  else
  {
    sub_940407DC(2, "clk_get_info type:%d failed\n", a1);
    return 1;
  }
}

/* ===== sub_9403447C @ 0x9403447C size 216 ===== */
__int64 sub_9403447C()
{
  if ( (unsigned int)sub_940408CC("ap_apb", 1898971136, 0x10000, 2, -536472992) != 0
    || (unsigned int)sub_940408CC("ap_ahb", 551550976, 0x10000, 2, -536473000) != 0
    || (unsigned int)sub_940408CC("aon_apb", 1076756480, 0x10000, 2, -536473008) != 0
    || (unsigned int)sub_940408CC("sec_aon_apb", 839188480, 0x10000, 2, -536472984) != 0 )
  {
    return sub_940407DC(2, "%s: failed %d\n");
  }
  else
  {
    return sub_940407DC(2, "sprd glb clk is ok!\n");
  }
}

/* ===== sub_94034554 @ 0x94034554 size 20 ===== */
__int64 sub_94034554()
{
  __int64 v0; // x0

  v0 = sub_94037604();
  return sub_9403535C(v0);
}

/* ===== sub_94034568 @ 0x94034568 size 3504 ===== */
__int64 __fastcall sub_94034568(int a1, unsigned int a2)
{
  unsigned int v3; // w19
  __int64 v5; // x22
  __int64 v6; // x0
  __int64 v7; // x23
  __int64 v8; // x0
  __int64 v9; // x22
  __int64 v10; // x23
  __int64 v11; // x24
  __int64 v12; // x22
  __int64 v13; // x24
  __int64 v14; // x23
  int v15; // w19
  int v16; // w19
  __int64 v17; // x25
  __int64 v18; // x24
  __int64 v19; // x22
  __int64 v20; // x21
  __int64 v21; // x23
  __int64 v22; // x25
  __int64 v23; // x24
  __int64 v24; // x21
  __int64 v25; // x0
  __int64 v26; // x21
  int v27; // w19
  int v28; // w19
  __int64 v29; // x2
  __int64 v30; // x1
  __int64 v31; // x0
  _QWORD v32[2]; // [xsp+50h] [xbp+50h] BYREF
  __int64 v33; // [xsp+60h] [xbp+60h]
  __int64 v34; // [xsp+68h] [xbp+68h]
  _QWORD v35[3]; // [xsp+78h] [xbp+78h] BYREF
  __int64 v36; // [xsp+90h] [xbp+90h] BYREF
  __int64 v37; // [xsp+98h] [xbp+98h]
  __int64 v38; // [xsp+A0h] [xbp+A0h]
  __int64 v39; // [xsp+A8h] [xbp+A8h] BYREF
  __int64 v40; // [xsp+B0h] [xbp+B0h] BYREF
  __int64 v41; // [xsp+B8h] [xbp+B8h]
  __int64 v42; // [xsp+C0h] [xbp+C0h]
  __int64 v43; // [xsp+C8h] [xbp+C8h]
  unsigned int v44; // [xsp+D0h] [xbp+D0h]
  unsigned int v45; // [xsp+100h] [xbp+100h]
  unsigned int v46; // [xsp+150h] [xbp+150h]
  unsigned int v47; // [xsp+158h] [xbp+158h] BYREF
  unsigned int v48; // [xsp+15Ch] [xbp+15Ch]
  unsigned int v49; // [xsp+160h] [xbp+160h]
  unsigned int v50; // [xsp+164h] [xbp+164h] BYREF
  unsigned int v51; // [xsp+16Ch] [xbp+16Ch]
  unsigned int v52; // [xsp+170h] [xbp+170h] BYREF
  _DWORD v53[2]; // [xsp+174h] [xbp+174h] BYREF
  unsigned int v54; // [xsp+17Ch] [xbp+17Ch]
  unsigned int v55; // [xsp+180h] [xbp+180h]
  unsigned int v56; // [xsp+184h] [xbp+184h]
  unsigned int v57; // [xsp+188h] [xbp+188h]
  int v58; // [xsp+18Ch] [xbp+18Ch]
  __int64 v59; // [xsp+190h] [xbp+190h]
  unsigned int v60; // [xsp+198h] [xbp+198h]

  switch ( a1 )
  {
    case 2:
      sub_9404D244(&v36, a2, 32);
      v9 = sub_9404CBC4(HIDWORD(v38));
      v10 = sub_9404CBC4(164);
      v11 = sub_9404CBC4(1024);
      if ( v9 != 0 && v10 != 0 )
      {
        sub_9404D244(v9, (unsigned int)v38, HIDWORD(v38));
        sub_9404D244(&v40, HIDWORD(v36), 84);
        v27 = sub_94038FE8(v45, &v40, HIDWORD(v37), &v47);
        v28 = sub_94038DF0(v45, &v47, v9, BYTE4(v38), v10) | v27;
        v3 = v28 | sub_94039298(v10, v11, &v39);
        if ( v3 != 0 )
        {
          if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
            sub_9404B2FC("SPRD_ENGINE_ECC_SIGN failed !errno (%X)\n", v3);
        }
        else
        {
          sub_9404D224(HIDWORD(v39), v11, (unsigned int)v39);
          sub_9404D224(a2, &v36, 32);
        }
      }
      else
      {
        if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
          sub_9404B2FC("Cann't malloc when operate SPRD_ENGINE_ECC_SIGN !\n");
        v3 = -5;
        if ( v9 == 0 )
          goto LABEL_18;
      }
      sub_9404CC20(v9);
LABEL_18:
      if ( v10 != 0 )
        sub_9404CC20(v10);
      if ( v11 != 0 )
        sub_9404CC20(v11);
      return v3;
    case 3:
      sub_9404D244(&v36, a2, 32);
      v12 = sub_9404CBC4((unsigned int)v39);
      v13 = sub_9404CBC4(164);
      v14 = sub_9404CBC4(164);
      if ( v12 != 0 && v13 != 0 && v14 != 0 )
      {
        sub_9404D244(v12, (unsigned int)v38, HIDWORD(v38));
        sub_9404D244(v14, HIDWORD(v39), (unsigned int)v39);
        sub_9404D244(&v40, (unsigned int)v36, 164);
        v15 = sub_940390B8(v46, &v40, (unsigned int)(2 * v37), &v47);
        v16 = sub_940391A8(v46, v14, HIDWORD(v38), v13) | v15;
        v3 = v16 | sub_94038ED8(v46, &v47, v12, (unsigned __int8)v39, v13);
        if ( v3 != 0 )
        {
          if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
            sub_9404B2FC("SPRD_ENGINE_ECC_VERIFY failed !errno (%X)\n", v3);
        }
        else
        {
          sub_9404D224(a2, &v36, 32);
        }
LABEL_27:
        sub_9404CC20(v13);
        goto LABEL_28;
      }
      if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
        sub_9404B2FC("Cann't malloc when operate SPRD_ENGINE_ECC_SIGN !\n");
      v3 = -5;
      if ( v13 != 0 )
        goto LABEL_27;
LABEL_28:
      if ( v14 != 0 )
        sub_9404CC20(v14);
      if ( v12 != 0 )
        sub_9404CC20(v12);
      return v3;
    case 32:
      sub_9404D244(&v47, a2, 8);
      v24 = sub_9404CBC4(v47);
      if ( v24 != 0 )
      {
        v3 = 0;
        sub_9403B7D4(v47, v24);
        sub_9404D224(v48, v24, v47);
        sub_9404D224(a2, &v47, 8);
        sub_9404CC20(v24);
      }
      else
      {
        v3 = -5;
        if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
          sub_9404B2FC("Cann't malloc when operate SPRD_ENGINE_RSA_GEN_PRIME !\n");
      }
      return v3;
    case 33:
      sub_9404D244(&v47, a2, 68);
      v19 = sub_9404CBC4(v54);
      v20 = sub_9404CBC4((int)v55);
      v21 = sub_9404CBC4((int)v55);
      if ( v20 != 0 && v19 != 0 && v21 != 0 )
      {
        sub_9404D244(v19, v53[1], v54);
        v3 = sub_9403B4E0(v19, v54, v55, v21, v20);
        if ( v3 != 0 )
        {
          if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
            sub_9404B2FC("sprd_rsa_key_gen failed !errno (%X)\n", v3);
        }
        else
        {
          sub_9404D224(v56, v21, (int)v55);
          sub_9404D224(v57, v20, (int)v55);
          sub_9404D224(a2, &v47, 68);
        }
LABEL_49:
        sub_9404CC20(v19);
        goto LABEL_50;
      }
      if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
        sub_9404B2FC("Cann't malloc when operate SPRD_ENGINE_RSA_GEN !\n");
      v3 = -5;
      if ( v19 != 0 )
        goto LABEL_49;
LABEL_50:
      if ( v20 != 0 )
        sub_9404CC20(v20);
      if ( v21 == 0 )
        return v3;
      v8 = v21;
      goto LABEL_11;
    case 34:
      sub_9404D244(&v47, a2, 68);
      sub_9404D244(v35, v48, 16);
      v38 = v35[1];
      v37 = sub_9404CBC4(HIDWORD(v35[1]));
      v36 = sub_9404CBC4((unsigned int)v38);
      v22 = sub_9404CBC4(v50);
      v23 = sub_9404CBC4(v50);
      if ( v23 != 0 && v22 != 0 && v37 != 0 && v36 != 0 )
      {
        sub_9404D244(v37, HIDWORD(v35[0]), HIDWORD(v38));
        sub_9404D244(v36, LODWORD(v35[0]), (unsigned int)v38);
        sub_9404D244(v22, v49, v50);
        LODWORD(v40) = v58;
        switch ( v58 )
        {
          case 20:
            LODWORD(v41) = v59;
            break;
          case 21:
            v41 = v59;
            break;
          case 11:
            LODWORD(v41) = v59;
            LODWORD(v43) = v60;
            sub_9404D244(v42, HIDWORD(v59), v60);
            break;
          default:
            break;
        }
        v32[0] = v40;
        v32[1] = v41;
        v33 = v42;
        v34 = v43;
        v3 = sub_9403B158(&v36, v22, v50, v23, &v52, v32);
        if ( v3 != 0 )
        {
          if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
            sub_9404B2FC("sprd_rsa_public_encrypt failed !errno (%X)\n", v3);
        }
        else
        {
          sub_9404D224(v51, v23, v52);
          sub_9404D224(a2, &v47, 68);
        }
        goto LABEL_110;
      }
      if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
        sub_9404B2FC("Cann't malloc when operate SPRD_ENGINE_RSA_ENCRYPT !\n");
      goto LABEL_109;
    case 35:
      sub_9404D244(&v47, a2, 68);
      sub_9404D244(v35, v47, 24);
      v43 = *(_QWORD *)((char *)&v35[1] + 4);
      v44 = HIDWORD(v35[2]);
      v41 = sub_9404CBC4(LODWORD(v35[2]));
      v40 = sub_9404CBC4((unsigned int)v43);
      v42 = sub_9404CBC4(v44);
      v17 = sub_9404CBC4(v52);
      v18 = sub_9404CBC4(v52);
      if ( v18 == 0 || v17 == 0 || v41 == 0 || v42 == 0 || v40 == 0 )
      {
        if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
          sub_9404B2FC("Cann't malloc when operate SPRD_ENGINE_RSA_DECRYPT !\n");
        goto LABEL_95;
      }
      sub_9404D244(v41, HIDWORD(v35[0]), HIDWORD(v43));
      sub_9404D244(v40, LODWORD(v35[0]), (unsigned int)v43);
      sub_9404D244(v42, LODWORD(v35[1]), v44);
      sub_9404D244(v17, v51, v52);
      LODWORD(v36) = v58;
      switch ( v58 )
      {
        case 20:
          LODWORD(v37) = v59;
          break;
        case 21:
          v37 = v59;
          break;
        case 11:
          LODWORD(v37) = v59;
          LODWORD(v39) = v60;
          sub_9404D244(v38, HIDWORD(v59), v60);
          break;
        default:
          break;
      }
      v32[0] = v36;
      v32[1] = v37;
      v33 = v38;
      v34 = v39;
      v3 = sub_9403B31C(&v40, v17, v52, v18, &v50, v32);
      if ( v3 == 0 )
      {
        v29 = v50;
        v30 = v18;
        v31 = v49;
        goto LABEL_145;
      }
      if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
        sub_9404B2FC("sprd_rsa_private_decrypt failed !errno (%X)\n", v3);
      goto LABEL_96;
    case 36:
      sub_9404D244(&v47, a2, 68);
      sub_9404D244(v35, v47, 24);
      v43 = *(_QWORD *)((char *)&v35[1] + 4);
      v44 = HIDWORD(v35[2]);
      v41 = sub_9404CBC4(LODWORD(v35[2]));
      v40 = sub_9404CBC4((unsigned int)v43);
      v42 = sub_9404CBC4(v44);
      v17 = sub_9404CBC4(v50);
      v18 = sub_9404CBC4(4096);
      if ( v18 != 0 && v17 != 0 && v41 != 0 && v42 != 0 && v40 != 0 )
      {
        sub_9404D244(v41, HIDWORD(v35[0]), HIDWORD(v43));
        sub_9404D244(v40, LODWORD(v35[0]), (unsigned int)v43);
        sub_9404D244(v42, LODWORD(v35[1]), v44);
        sub_9404D244(v17, v49, v50);
        LODWORD(v36) = v58;
        switch ( v58 )
        {
          case 20:
            LODWORD(v37) = v59;
            break;
          case 21:
            v37 = v59;
            break;
          case 11:
            LODWORD(v37) = v59;
            LODWORD(v39) = v60;
            sub_9404D244(v38, HIDWORD(v59), v60);
            break;
          default:
            break;
        }
        v32[0] = v36;
        v32[1] = v37;
        v33 = v38;
        v34 = v39;
        v3 = sub_9403B9E4(&v40, v17, v50, v18, &v52, v32);
        if ( v3 != 0 )
        {
          if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
            sub_9404B2FC("sprd_rsa_sign failed !errno (%X)\n", v3);
        }
        else
        {
          v29 = v52;
          v30 = v18;
          v31 = v51;
LABEL_145:
          sub_9404D224(v31, v30, v29);
          sub_9404D224(a2, &v47, 68);
        }
LABEL_96:
        sub_9404CC20(v17);
        goto LABEL_97;
      }
      if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
        sub_9404B2FC("Cann't malloc when operate SPRD_ENGINE_RSA_SIGN !\n");
LABEL_95:
      v3 = -5;
      if ( v17 != 0 )
        goto LABEL_96;
LABEL_97:
      if ( v18 != 0 )
        sub_9404CC20(v18);
      if ( v41 != 0 )
        sub_9404CC20(v41);
      if ( v40 != 0 )
        sub_9404CC20(v40);
      v8 = v42;
      if ( v42 != 0 )
        goto LABEL_11;
      return v3;
    case 37:
      sub_9404D244(&v47, a2, 68);
      sub_9404D244(v35, v48, 16);
      v38 = v35[1];
      v37 = sub_9404CBC4(HIDWORD(v35[1]));
      v36 = sub_9404CBC4((unsigned int)v38);
      v22 = sub_9404CBC4(v50);
      v23 = sub_9404CBC4(v52);
      if ( v23 != 0 && v22 != 0 && v37 != 0 && v36 != 0 )
      {
        sub_9404D244(v37, HIDWORD(v35[0]), HIDWORD(v38));
        sub_9404D244(v36, LODWORD(v35[0]), (unsigned int)v38);
        sub_9404D244(v23, v51, v52);
        sub_9404D244(v22, v49, v50);
        LODWORD(v40) = v58;
        switch ( v58 )
        {
          case 20:
            LODWORD(v41) = v59;
            break;
          case 21:
            v41 = v59;
            break;
          case 11:
            LODWORD(v41) = v59;
            LODWORD(v43) = v60;
            sub_9404D244(v42, HIDWORD(v59), v60);
            break;
          default:
            break;
        }
        v32[0] = v40;
        v32[1] = v41;
        v33 = v42;
        v34 = v43;
        v3 = sub_9403BC1C(&v36, v22, v50, v23, v52, v32, v53);
        if ( v3 != 0 )
        {
          if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
            sub_9404B2FC("sprd_rsa_verify failed !errno (%X)\n", v3);
        }
        else
        {
          sub_9404D224(a2, &v47, 68);
        }
LABEL_110:
        sub_9404CC20(v22);
        goto LABEL_111;
      }
      if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
        sub_9404B2FC("Cann't malloc when operate SPRD_ENGINE_RSA_VERIFY !\n");
LABEL_109:
      v3 = -5;
      if ( v22 != 0 )
        goto LABEL_110;
LABEL_111:
      if ( v23 != 0 )
        sub_9404CC20(v23);
      if ( v37 != 0 )
        sub_9404CC20(v37);
      v8 = v36;
      if ( v36 != 0 )
        goto LABEL_11;
      return v3;
    case 49:
      sub_9404D244(&v47, a2, 8);
      v25 = sub_9404CBC4(v47);
      v26 = v25;
      if ( v25 != 0 )
      {
        v3 = sub_9403BFB0(v25, v47);
        sub_9404D224(v48, v26, v47);
        sub_9404D224(a2, &v47, 8);
LABEL_81:
        v8 = v26;
        goto LABEL_11;
      }
      v3 = -5;
      if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) != 0 )
        goto LABEL_81;
      sub_9404B2FC("Cann't malloc when operate SPRD_ENGINE_RNG_GEN !\n");
      v8 = 0;
LABEL_11:
      sub_9404CC20(v8);
      return v3;
    case 65:
      sub_9404D244(&v47, a2, 16);
      v5 = sub_9404CBC4(v48);
      v6 = sub_9404CBC4(v47);
      v7 = v6;
      if ( v5 != 0 && v6 != 0 )
      {
        sub_9404D244(v6, v49, v47);
        v3 = sub_94037BF4(v7, v47, v5, v48);
        sub_9404D224(v50, v5, v48);
        sub_9404D224(a2, &v47, 16);
      }
      else
      {
        v3 = -5;
        if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
          sub_9404B2FC("Cann't malloc when operate SPRD_ENGINE_HUK_DERIVE !\n");
      }
      sub_9404CC20(v5);
      v8 = v7;
      goto LABEL_11;
    default:
      v3 = -24;
      if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
        sub_9404B2FC("Don't support this cmd %d  \n", a1);
      return v3;
  }
}

/* ===== sub_94035318 @ 0x94035318 size 68 ===== */
__int64 __fastcall sub_94035318(__int64 a1, int a2, unsigned int a3)
{
  if ( a3 != 0 )
    return sub_94034568(a2, a3);
  if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
    sub_9404B2FC("IOCTL params is wrong !\n");
  return 4294967288LL;
}

/* ===== sub_9403535C @ 0x9403535C size 76 ===== */
__int64 sub_9403535C()
{
  __int64 result; // x0

  result = sub_9402D420(3u, (__int64)qword_9405B108);
  if ( (_DWORD)result != 0 && MEMORY[0xFFFFFFFFE003CB98] > 1 )
    return sub_9404B2FC("can not install std in handler: %d\n", result);
  return result;
}

/* ===== sub_940353A8 @ 0x940353A8 size 20 ===== */
__int64 __fastcall sub_940353A8(__int64 *a1)
{
  __int64 result; // x0

  for ( result = *a1; result != 0; result = *(_QWORD *)(result + 8) )
    ;
  return result;
}

/* ===== sub_940353BC @ 0x940353BC size 192 ===== */
__int64 __fastcall sub_940353BC(__int64 *a1, _QWORD *a2)
{
  int v3; // w0
  _QWORD *v4; // x0
  __int64 v5; // x0
  const void *v7; // x0
  int v9; // [xsp+28h] [xbp+28h]

  v3 = sub_9404096C(a1[3]);
  if ( v3 != 0 )
  {
    v9 = v3;
    v7 = (const void *)sub_94040A98();
    sub_940407DC(3, "%p: %s: %s: failed to get mutex err = %d\n", v7, "SPRD_CE", "sprd_queue_add_item_top", v9);
    return 0xFFFFFFFFLL;
  }
  else
  {
    v4 = (_QWORD *)*a1;
    a2[1] = *a1;
    *a2 = 0;
    if ( v4 != nullptr )
      *v4 = a2;
    v5 = a1[1];
    *a1 = (__int64)a2;
    if ( v5 == 0 )
      a1[1] = (__int64)a2;
    if ( a1[2] == 0 )
      a1[2] = (__int64)a2;
    sub_940353A8(a1);
    sub_94040974(a1[3]);
    return 0;
  }
}

/* ===== sub_9403547C @ 0x9403547C size 8 ===== */
__int64 __fastcall sub_9403547C(__int64 a1)
{
  return *(_QWORD *)(a1 + 16);
}

/* ===== sub_94035484 @ 0x94035484 size 92 ===== */
__int64 __fastcall sub_94035484(__int64 a1)
{
  _QWORD *v3; // x0

  if ( (unsigned int)sub_9404096C(*(_QWORD *)(a1 + 24)) != 0 )
    return 0xFFFFFFFFLL;
  v3 = *(_QWORD **)(a1 + 16);
  if ( v3 != nullptr )
    *(_QWORD *)(a1 + 16) = *v3;
  sub_94040974(*(_QWORD *)(a1 + 24));
  return 0;
}

/* ===== sub_940354E0 @ 0x940354E0 size 180 ===== */
__int64 *__fastcall sub_940354E0(_QWORD *a1)
{
  __int64 *v2; // x20
  __int64 v3; // x0
  const void *v5; // x0

  if ( (unsigned int)sub_9404096C(a1[3]) != 0 )
    return nullptr;
  v2 = (__int64 *)a1[1];
  if ( v2 == nullptr || v2 == (__int64 *)a1[2] )
  {
    v5 = (const void *)sub_94040A98();
    v2 = nullptr;
    sub_940407DC(
      3,
      "%p: %s: %s: queue is empty or tail is equal to current\n",
      v5,
      "SPRD_CE",
      "sprd_queue_delete_item_bottom");
    sub_94040974(a1[3]);
  }
  else
  {
    v3 = *v2;
    if ( *v2 != 0 )
    {
      *(_QWORD *)(v3 + 8) = 0;
      a1[1] = v3;
    }
    else
    {
      *a1 = 0;
      a1[1] = 0;
      a1[2] = 0;
    }
    sub_94040974(a1[3]);
  }
  return v2;
}

/* ===== sub_94035594 @ 0x94035594 size 56 ===== */
__int64 __fastcall sub_94035594(_QWORD *a1)
{
  __int64 v2; // x0

  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  v2 = sub_9404093C();
  a1[3] = v2;
  if ( v2 != 0 )
    return 0;
  else
    return 0xFFFFFFFFLL;
}

/* ===== sub_940355CC @ 0x940355CC size 64 ===== */
void __noreturn sub_940355CC()
{
  while ( 1 )
    sub_94040A74(0);
}

/* ===== sub_9403560C @ 0x9403560C size 64 ===== */
void __noreturn sub_9403560C()
{
  int v0; // [xsp+3Ch] [xbp+3Ch]

  v0 = 1;
  while ( 1 )
    sub_94040A74(0);
}

/* ===== sub_9403564C @ 0x9403564C size 44 ===== */
_BYTE *__fastcall sub_9403564C(_BYTE *result)
{
  result[3] = 119;
  result[2] = 48;
  result[1] = 16;
  *result = 8;
  return result;
}

/* ===== sub_94035678 @ 0x94035678 size 60 ===== */
__int64 __fastcall sub_94035678(unsigned __int16 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v4; // x3

  result = a1 | 0x10000000 | ((unsigned __int8)(a2 & 0x1F) << 16);
  v4 = 0;
  for ( MEMORY[0x500] = result; a2 > (unsigned int)v4; MEMORY[0x500] = result )
    result = *(unsigned int *)(a3 + 4 * v4++);
  return result;
}

/* ===== sub_940356B4 @ 0x940356B4 size 60 ===== */
__int64 __fastcall sub_940356B4(unsigned __int16 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v4; // x3

  result = a1 | 0x10000000 | ((unsigned __int8)(a2 & 0x1F) << 16);
  v4 = 0;
  for ( MEMORY[0x600] = result; a2 > (unsigned int)v4; MEMORY[0x600] = result )
    result = *(unsigned int *)(a3 + 4 * v4++);
  return result;
}

/* ===== sub_940356F0 @ 0x940356F0 size 76 ===== */
__int64 __fastcall sub_940356F0(_DWORD *a1)
{
  __int64 result; // x0

  MEMORY[0x500] = ((*a1 & 0x7000000u) >> 4) | 0x20000000 | ((unsigned __int8)a1[5] << 8);
  MEMORY[0x500] = a1[1];
  MEMORY[0x500] = a1[2];
  MEMORY[0x500] = a1[3];
  result = (unsigned int)a1[4];
  MEMORY[0x500] = result;
  return result;
}

/* ===== sub_9403573C @ 0x9403573C size 44 ===== */
__int64 __fastcall sub_9403573C(_DWORD *a1, int a2)
{
  __int64 result; // x0

  MEMORY[0x600] = ((*a1 & 0x7000000u) >> 4) | 0x20000000;
  result = (unsigned int)a1[1];
  MEMORY[0x600] = a2;
  return result;
}

/* ===== sub_94035768 @ 0x94035768 size 132 ===== */
__int64 __fastcall sub_94035768(_DWORD *a1)
{
  unsigned int v1; // w1
  __int64 result; // x0

  v1 = *a1 & 0xFFFF0000;
  if ( v1 == 84017152 )
    return 14;
  if ( v1 <= 0x5020000 )
  {
    if ( v1 != 0x2000000 )
    {
      if ( v1 != 83951616 )
      {
        result = 36;
        if ( v1 == 0 )
          return result;
        return 0;
      }
      return 14;
    }
    return 10;
  }
  if ( v1 == 84148224 )
    return 12;
  if ( v1 == 84213760 )
    return 10;
  result = 18;
  if ( v1 != 84082688 )
    return 0;
  return result;
}

/* ===== sub_940357EC @ 0x940357EC size 360 ===== */
__int64 __fastcall sub_940357EC(int *a1)
{
  unsigned __int64 v2; // x2
  __int64 v3; // x0
  __int64 v4; // x0
  unsigned __int64 v5; // x2
  __int64 v6; // x0
  int v7; // w0
  bool v8; // w3
  char v9; // w1
  __int64 v10; // x0
  __int16 v11; // w2
  unsigned __int64 v12; // x2
  __int64 v13; // x0
  unsigned __int64 v14; // x2
  __int64 v15; // x0
  unsigned int v17; // [xsp+38h] [xbp+38h] BYREF
  unsigned int v18; // [xsp+3Ch] [xbp+3Ch]
  int v19; // [xsp+40h] [xbp+40h]
  int v20; // [xsp+44h] [xbp+44h]
  int v21; // [xsp+48h] [xbp+48h] BYREF
  __int16 v22; // [xsp+4Ch] [xbp+4Ch]
  _BYTE v23[4]; // [xsp+50h] [xbp+50h] BYREF
  int v24; // [xsp+54h] [xbp+54h]
  int v25; // [xsp+58h] [xbp+58h]
  char v26; // [xsp+5Ch] [xbp+5Ch]

  sub_94040888(&v17, 0, 16);
  v2 = ((unsigned __int64)sub_940408C8(*((_QWORD *)a1 + 37)) >> 32) & 0xF;
  v3 = *((_QWORD *)a1 + 37);
  HIBYTE(v17) = HIBYTE(v17) & 0xF0 | v2 & 0xF;
  v19 = sub_940408C8(v3);
  v4 = *((_QWORD *)a1 + 39);
  v17 = v17 & 0xFF000000 | a1[76] & 0xFFFFFF;
  v5 = ((unsigned __int64)sub_940408C8(v4) >> 32) & 0xF;
  v6 = *((_QWORD *)a1 + 39);
  HIBYTE(v18) = HIBYTE(v18) & 0xF0 | v5 & 0xF;
  v20 = sub_940408C8(v6);
  v18 = v18 & 0xFF000000 | a1[80] & 0xFFFFFF;
  sub_94035678(0x48u, 4u, (__int64)&v17);
  sub_94040888(&v21, 0, 24);
  v21 = *a1;
  sub_9403564C(v23);
  v7 = a1[2];
  v8 = v7 != 0;
  v9 = v23[0] & 0xEF | (16 * (v7 & 1));
  v10 = *((_QWORD *)a1 + 19);
  v11 = v22 & 0xFE0F | (16 * (*a1 & 0x1F));
  v23[0] = v9 & 0xF9 | (4 * v8) | (2 * (a1[1] == 0));
  v22 = v11 | 1;
  v12 = ((unsigned __int64)sub_940408C8(v10) >> 32) & 0xF;
  v13 = *((_QWORD *)a1 + 19);
  v26 = v26 & 0xF0 | v12 & 0xF;
  v14 = ((unsigned __int64)sub_940408C8(v13) >> 32) & 0xF;
  v15 = *((_QWORD *)a1 + 19);
  v26 = v26 & 0xF | (16 * (v14 & 0xF));
  v24 = sub_940408C8(v15);
  v25 = sub_940408C8(*((_QWORD *)a1 + 19));
  return sub_940356F0(&v21);
}

/* ===== sub_94035954 @ 0x94035954 size 200 ===== */
__int64 __fastcall sub_94035954(int *a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  int v4; // w0
  int v6; // [xsp+38h] [xbp+38h] BYREF
  char v7; // [xsp+3Ch] [xbp+3Ch]
  char v8; // [xsp+3Fh] [xbp+3Fh]
  char v9; // [xsp+40h] [xbp+40h] BYREF
  char v10; // [xsp+41h] [xbp+41h]
  char v11; // [xsp+42h] [xbp+42h]

  v2 = *((_QWORD *)a1 + 2) + 516LL;
  sub_94039378();
  sub_94040888(&v6, 0, 24);
  v6 = *a1;
  sub_9403564C(&v9);
  v11 = v11 & 0xF | 0x80;
  v10 |= 1u;
  v7 |= 1u;
  v9 |= 0x16u;
  v8 = v8 & 0xF0 | 8;
  v3 = sub_940408C8(v2);
  v8 = v8 & 0xF | (16 * (BYTE4(v3) & 0xF));
  v4 = sub_940408C8(v2);
  return sub_9403573C(&v6, v4);
}

/* ===== sub_94035A1C @ 0x94035A1C size 556 ===== */
__int64 __fastcall sub_94035A1C(int *a1)
{
  _DWORD *v2; // x22
  __int64 v3; // x0
  __int64 v4; // x22
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x0
  __int64 v8; // x22
  __int64 v9; // x22
  __int64 v10; // x0
  __int64 v11; // x22
  unsigned __int64 v12; // x1
  __int64 v13; // x0
  unsigned __int64 v14; // x1
  __int64 v15; // x0
  unsigned __int64 v16; // x2
  __int64 v17; // x0
  __int64 v18; // x0
  unsigned __int64 v19; // x2
  __int64 v20; // x0
  int v21; // w0
  int v23; // [xsp+3Ch] [xbp+3Ch] BYREF
  _DWORD v24[3]; // [xsp+40h] [xbp+40h] BYREF
  int v25; // [xsp+4Ch] [xbp+4Ch] BYREF
  int v26; // [xsp+50h] [xbp+50h] BYREF
  int v27; // [xsp+58h] [xbp+58h] BYREF
  char v28; // [xsp+5Ch] [xbp+5Ch]
  char v29; // [xsp+5Eh] [xbp+5Eh]
  char v30; // [xsp+5Fh] [xbp+5Fh]
  char v31; // [xsp+60h] [xbp+60h] BYREF
  char v32; // [xsp+61h] [xbp+61h]
  char v33; // [xsp+62h] [xbp+62h]

  v2 = *((_DWORD **)a1 + 5);
  v3 = sub_940408C8(*((_QWORD *)a1 + 2));
  *v2 = sub_94037708(0, 0, 1, v3 & 0x1FFFF);
  v4 = *((_QWORD *)a1 + 5);
  v5 = sub_940408C8(*((_QWORD *)a1 + 37));
  *(_DWORD *)(v4 + 4) = sub_94037708(0, 1, 1, v5 & 0x1FFFF);
  v6 = *((_QWORD *)a1 + 5);
  v7 = sub_940408C8(*((_QWORD *)a1 + 3));
  *(_DWORD *)(v6 + 8) = sub_94037708(0, 2, 1, v7 & 0x1FFFF);
  v8 = *((_QWORD *)a1 + 5);
  *(_DWORD *)(v8 + 12) = sub_940377F0(0, 3, 1, 2);
  v9 = *((_QWORD *)a1 + 5);
  v10 = sub_940408C8(*((_QWORD *)a1 + 39));
  *(_DWORD *)(v9 + 16) = sub_94037730(0, 3, 1, v10 & 0x1FFFF);
  v11 = *((_QWORD *)a1 + 5);
  *(_DWORD *)(v11 + 20) = sub_94037700();
  v23 = a1[8];
  sub_940356B4(0xD0u, 1u, (__int64)&v23);
  sub_94040888(v24, 0, 20);
  v12 = ((unsigned __int64)sub_940408C8(*((_QWORD *)a1 + 37)) >> 17) & 0x7FFFF;
  v13 = *((_QWORD *)a1 + 39);
  v26 = v12;
  v14 = ((unsigned __int64)sub_940408C8(v13) >> 17) & 0x7FFFF;
  v15 = *((_QWORD *)a1 + 5);
  v25 = v14;
  v16 = ((unsigned __int64)sub_940408C8(v15) >> 32) & 0xF;
  v17 = *((_QWORD *)a1 + 5);
  HIBYTE(v24[0]) = HIBYTE(v24[0]) & 0xF0 | v16 & 0xF;
  v24[2] = sub_940408C8(v17);
  v24[0] = v24[0] & 0xFF000000 | 0x80;
  sub_940356B4(0x610u, 1u, (__int64)&v26);
  sub_940356B4(0x60Cu, 1u, (__int64)&v25);
  sub_940408B8(*((_QWORD *)a1 + 5), v24[0] & 0xFFFFFF);
  sub_94040888(&v27, 0, 24);
  v27 = *a1;
  sub_9403564C(&v31);
  v18 = *((_QWORD *)a1 + 5);
  v31 |= 0x16u;
  v33 = v33 & 0x3F | 0x80;
  v32 |= 1u;
  v28 |= 3u;
  v29 = -1;
  v30 = v30 & 0xF0 | 3;
  v19 = ((unsigned __int64)sub_940408C8(v18) >> 32) & 0xF;
  v20 = *((_QWORD *)a1 + 5);
  v30 = v30 & 0xF | (16 * (v19 & 0xF));
  v21 = sub_940408C8(v20);
  return sub_9403573C(&v27, v21);
}

/* ===== sub_94035C48 @ 0x94035C48 size 436 ===== */
__int64 __fastcall sub_94035C48(int *a1)
{
  _DWORD *v2; // x22
  __int64 v3; // x22
  __int64 v4; // x22
  __int64 v5; // x0
  __int64 v6; // x22
  unsigned __int64 v7; // x1
  __int64 v8; // x0
  unsigned __int64 v9; // x2
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned __int64 v12; // x2
  __int64 v13; // x0
  int v14; // w0
  int v16; // [xsp+3Ch] [xbp+3Ch] BYREF
  _DWORD v17[3]; // [xsp+40h] [xbp+40h] BYREF
  int v18; // [xsp+4Ch] [xbp+4Ch] BYREF
  int v19; // [xsp+50h] [xbp+50h] BYREF
  int v20; // [xsp+58h] [xbp+58h] BYREF
  char v21; // [xsp+5Ch] [xbp+5Ch]
  char v22; // [xsp+5Eh] [xbp+5Eh]
  char v23; // [xsp+5Fh] [xbp+5Fh]
  _BYTE v24[2]; // [xsp+60h] [xbp+60h] BYREF
  char v25; // [xsp+62h] [xbp+62h]

  v2 = *((_DWORD **)a1 + 4);
  *v2 = sub_94037770(0, 1);
  v3 = *((_QWORD *)a1 + 4);
  *(_DWORD *)(v3 + 4) = sub_94037758(18, 0);
  v4 = *((_QWORD *)a1 + 4);
  v5 = sub_940408C8(*((_QWORD *)a1 + 39));
  *(_DWORD *)(v4 + 8) = sub_94037730(0, 1, 1, v5 & 0x1FFFF);
  v6 = *((_QWORD *)a1 + 4);
  *(_DWORD *)(v6 + 12) = sub_94037700();
  v16 = a1[6];
  sub_940356B4(0xD0u, 1u, (__int64)&v16);
  sub_94040888(v17, 0, 20);
  v19 = 0;
  v7 = ((unsigned __int64)sub_940408C8(*((_QWORD *)a1 + 39)) >> 17) & 0x7FFFF;
  v8 = *((_QWORD *)a1 + 4);
  v18 = v7;
  v9 = ((unsigned __int64)sub_940408C8(v8) >> 32) & 0xF;
  v10 = *((_QWORD *)a1 + 4);
  HIBYTE(v17[0]) = HIBYTE(v17[0]) & 0xF0 | v9 & 0xF;
  v17[2] = sub_940408C8(v10);
  v17[0] = v17[0] & 0xFF000000 | 0x30;
  sub_940356B4(0x610u, 1u, (__int64)&v19);
  sub_940356B4(0x60Cu, 1u, (__int64)&v18);
  sub_940408B8(*((_QWORD *)a1 + 4), v17[0] & 0xFFFFFF);
  sub_94040888(&v20, 0, 24);
  v20 = *a1;
  sub_9403564C(v24);
  v11 = *((_QWORD *)a1 + 4);
  v24[0] |= 0x16u;
  v25 = v25 & 0x3F | 0x80;
  v21 |= 3u;
  v22 = -1;
  v23 = v23 & 0xF0 | 3;
  v12 = ((unsigned __int64)sub_940408C8(v11) >> 32) & 0xF;
  v13 = *((_QWORD *)a1 + 4);
  v23 = v23 & 0xF | (16 * (v12 & 0xF));
  v14 = sub_940408C8(v13);
  return sub_9403573C(&v20, v14);
}

/* ===== sub_94035DFC @ 0x94035DFC size 700 ===== */
__int64 __fastcall sub_94035DFC(int *a1)
{
  _DWORD *v2; // x22
  __int64 v3; // x22
  __int64 v4; // x22
  __int64 v5; // x22
  int v6; // w0
  _DWORD *v7; // x1
  __int64 v8; // x22
  __int64 v9; // x22
  __int64 v10; // x22
  __int64 v11; // x22
  __int64 v12; // x0
  __int64 v13; // x22
  __int64 v14; // x0
  __int64 v15; // x22
  __int64 v16; // x0
  __int64 v17; // x22
  __int64 v18; // x0
  __int64 v19; // x22
  unsigned __int64 v20; // x1
  __int64 v21; // x0
  unsigned __int64 v22; // x2
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned __int64 v25; // x2
  __int64 v26; // x0
  int v27; // w0
  unsigned int v29; // [xsp+3Ch] [xbp+3Ch] BYREF
  _DWORD v30[3]; // [xsp+40h] [xbp+40h] BYREF
  int v31; // [xsp+4Ch] [xbp+4Ch] BYREF
  int v32; // [xsp+50h] [xbp+50h] BYREF
  int v33; // [xsp+58h] [xbp+58h] BYREF
  char v34; // [xsp+5Ch] [xbp+5Ch]
  char v35; // [xsp+5Eh] [xbp+5Eh]
  char v36; // [xsp+5Fh] [xbp+5Fh]
  _BYTE v37[2]; // [xsp+60h] [xbp+60h] BYREF
  char v38; // [xsp+62h] [xbp+62h]

  v2 = *((_DWORD **)a1 + 5);
  *v2 = sub_94037770(0, 1);
  v3 = *((_QWORD *)a1 + 5);
  *(_DWORD *)(v3 + 4) = sub_94037758(18, 0);
  v4 = *((_QWORD *)a1 + 5);
  *(_DWORD *)(v4 + 8) = sub_94037770(0, 9);
  v5 = *((_QWORD *)a1 + 5);
  v6 = sub_94037758(18, 8);
  v7 = *((_DWORD **)a1 + 37);
  *(_DWORD *)(v5 + 12) = v6;
  v8 = *((_QWORD *)a1 + 5);
  *(_DWORD *)(v8 + 16) = sub_9403778C(0, *v7 & 0x1FFFF);
  v9 = *((_QWORD *)a1 + 5);
  *(_DWORD *)(v9 + 20) = sub_940377A0(0, 3, 5, 6);
  v10 = *((_QWORD *)a1 + 5);
  *(_DWORD *)(v10 + 24) = sub_940377C4(0, 4, 1, 9);
  v11 = *((_QWORD *)a1 + 5);
  v12 = sub_940408C8(*((_QWORD *)a1 + 39));
  *(_DWORD *)(v11 + 28) = sub_94037730(0, 3, 1, v12 & 0x1FFFF);
  v13 = *((_QWORD *)a1 + 5);
  v14 = sub_940408C8(*((_QWORD *)a1 + 39));
  *(_DWORD *)(v13 + 32) = sub_94037730(0, 4, 1, (v14 & 0x1FFFF) + ((unsigned int)a1[80] >> 2));
  v15 = *((_QWORD *)a1 + 5);
  v16 = sub_940408C8(*((_QWORD *)a1 + 39));
  *(_DWORD *)(v15 + 36) = sub_94037730(0, 5, 1, (v16 & 0x1FFFF) + ((unsigned int)a1[80] >> 1));
  v17 = *((_QWORD *)a1 + 5);
  v18 = sub_940408C8(*((_QWORD *)a1 + 39));
  *(_DWORD *)(v17 + 40) = sub_94037730(0, 6, 1, (v18 & 0x1FFFF) + ((unsigned int)(3 * a1[80]) >> 2));
  v19 = *((_QWORD *)a1 + 5);
  *(_DWORD *)(v19 + 44) = sub_94037700();
  v29 = (unsigned int)a1[8] >> 1;
  sub_940356B4(0xD0u, 1u, (__int64)&v29);
  sub_94040888(v30, 0, 20);
  v32 = 0;
  v20 = ((unsigned __int64)sub_940408C8(*((_QWORD *)a1 + 39)) >> 17) & 0x7FFFF;
  v21 = *((_QWORD *)a1 + 5);
  v31 = v20;
  v22 = ((unsigned __int64)sub_940408C8(v21) >> 32) & 0xF;
  v23 = *((_QWORD *)a1 + 5);
  HIBYTE(v30[0]) = HIBYTE(v30[0]) & 0xF0 | v22 & 0xF;
  v30[2] = sub_940408C8(v23);
  v30[0] = v30[0] & 0xFF000000 | 0x30;
  sub_940356B4(0x610u, 1u, (__int64)&v32);
  sub_940356B4(0x60Cu, 1u, (__int64)&v31);
  sub_940408B8(*((_QWORD *)a1 + 5), v30[0] & 0xFFFFFF);
  sub_94040888(&v33, 0, 24);
  v33 = *a1;
  sub_9403564C(v37);
  v24 = *((_QWORD *)a1 + 5);
  v37[0] |= 0x16u;
  v38 = v38 & 0x3F | 0x80;
  v34 |= 3u;
  v35 = -1;
  v36 = v36 & 0xF0 | 3;
  v25 = ((unsigned __int64)sub_940408C8(v24) >> 32) & 0xF;
  v26 = *((_QWORD *)a1 + 5);
  v36 = v36 & 0xF | (16 * (v25 & 0xF));
  v27 = sub_940408C8(v26);
  return sub_9403573C(&v33, v27);
}

/* ===== sub_940360B8 @ 0x940360B8 size 1208 ===== */
__int64 __fastcall sub_940360B8(int *a1)
{
  unsigned int v2; // w1
  int *v3; // x3
  unsigned int i; // w0
  __int64 v5; // x8
  __int64 v6; // x6
  __int64 v7; // x5
  int v8; // w4
  unsigned int v9; // w7
  unsigned int v10; // w1
  unsigned __int64 v11; // x2
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned __int64 v14; // x2
  __int64 v15; // x0
  unsigned __int64 v16; // x2
  __int64 v17; // x0
  int v18; // w1
  __int64 v19; // x0
  unsigned __int64 v20; // x2
  __int64 v21; // x0
  unsigned __int64 v22; // x2
  __int64 v23; // x0
  int *v25; // x3
  unsigned int j; // w0
  __int64 v27; // x8
  __int64 v28; // x6
  __int64 v29; // x5
  int v30; // w4
  unsigned int v31; // w7
  __int16 v32; // w3
  unsigned int v33; // w4
  int v34; // w0
  int v35; // w3
  unsigned int v36; // w1
  __int16 v37; // [xsp+38h] [xbp+38h] BYREF
  __int16 v38; // [xsp+3Ah] [xbp+3Ah]
  char v39; // [xsp+40h] [xbp+40h] BYREF
  char v40; // [xsp+41h] [xbp+41h]
  int v41; // [xsp+44h] [xbp+44h]
  _DWORD v42[4]; // [xsp+48h] [xbp+48h] BYREF
  unsigned int v43; // [xsp+58h] [xbp+58h] BYREF
  unsigned int v44; // [xsp+5Ch] [xbp+5Ch]
  int v45; // [xsp+60h] [xbp+60h]
  int v46; // [xsp+64h] [xbp+64h]
  int v47; // [xsp+68h] [xbp+68h] BYREF
  char v48; // [xsp+6Ch] [xbp+6Ch]
  char v49; // [xsp+6Dh] [xbp+6Dh]
  char v50; // [xsp+70h] [xbp+70h] BYREF
  char v51; // [xsp+71h] [xbp+71h]
  int v52; // [xsp+74h] [xbp+74h]
  int v53; // [xsp+78h] [xbp+78h]
  char v54; // [xsp+7Ch] [xbp+7Ch]
  _DWORD v55[8]; // [xsp+80h] [xbp+80h] BYREF

  switch ( *a1 )
  {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
      goto LABEL_6;
    case 3:
      v2 = a1[24];
      if ( v2 != 0 )
      {
        v3 = a1 + 16;
        for ( i = 0; i < v2; i += 4 )
        {
          v5 = i + 3;
          v6 = i + 1;
          v7 = i + 2;
          v8 = LOBYTE(v3[i / 4]);
          v9 = i >> 2;
          v55[v9] = *((unsigned __int8 *)v3 + v5)
                  | (v8 << 24)
                  | (*((unsigned __int8 *)v3 + v6) << 16)
                  | (*((unsigned __int8 *)v3 + v7) << 8);
        }
        sub_94035678(0xA0u, v2 >> 2, (__int64)v55);
      }
LABEL_6:
      v10 = a1[15];
      if ( v10 == 0 )
        goto LABEL_7;
      v25 = a1 + 7;
      for ( j = 0; j < v10; j += 4 )
      {
        v27 = j + 3;
        v28 = j + 1;
        v29 = j + 2;
        v30 = LOBYTE(v25[j / 4]);
        v31 = j >> 2;
        v55[v31] = *((unsigned __int8 *)v25 + v27)
                 | (v30 << 24)
                 | (*((unsigned __int8 *)v25 + v28) << 16)
                 | (*((unsigned __int8 *)v25 + v29) << 8);
      }
      sub_94035678(0x80u, v10 >> 2, (__int64)v55);
      if ( a1[1] == 0 )
        goto LABEL_20;
      goto LABEL_8;
    case 7:
    case 8:
      sub_94040888(&v37, 0, 4);
      v32 = v38 & 0xC01F | (32 * (a1[15] & 0x1FF));
      v37 = v37 & 0xF801 | 0xC0;
      v38 = v32;
      sub_94035678(0x340u, 1u, (__int64)&v37);
      goto LABEL_7;
    default:
LABEL_7:
      if ( a1[1] == 0 )
      {
LABEL_20:
        sub_94040888(v42, 0, 16);
        switch ( *a1 )
        {
          case 1:
          case 2:
          case 3:
          case 5:
          case 7:
            v33 = _byteswap_ulong(a1[25]);
            v34 = *((unsigned __int8 *)a1 + 114);
            v35 = (*((unsigned __int8 *)a1 + 113) << 16)
                | (*((unsigned __int8 *)a1 + 112) << 24)
                | *((unsigned __int8 *)a1 + 115);
            v36 = _byteswap_ulong(a1[27]);
            v42[1] = _byteswap_ulong(a1[26]);
            v42[2] = v36;
            v42[3] = v35 | (v34 << 8);
            v42[0] = v33;
            sub_94035678(0x70u, 4u, (__int64)v42);
            break;
          default:
            sub_94035678(0x70u, 4u, (__int64)v42);
            break;
        }
      }
LABEL_8:
      sub_94040888(&v43, 0, 16);
      v11 = ((unsigned __int64)sub_940408C8(*((_QWORD *)a1 + 37)) >> 32) & 0xF;
      v12 = *((_QWORD *)a1 + 37);
      HIBYTE(v43) = HIBYTE(v43) & 0xF0 | v11 & 0xF;
      v45 = sub_940408C8(v12);
      v13 = *((_QWORD *)a1 + 39);
      v43 = v43 & 0xFF000000 | a1[76] & 0xFFFFFF;
      v14 = ((unsigned __int64)sub_940408C8(v13) >> 32) & 0xF;
      v15 = *((_QWORD *)a1 + 39);
      HIBYTE(v44) = HIBYTE(v44) & 0xF0 | v14 & 0xF;
      v46 = sub_940408C8(v15);
      v44 = v44 & 0xFF000000 | a1[80] & 0xFFFFFF;
      sub_94035678(0x48u, 4u, (__int64)&v43);
      sub_94040888(&v39, 0, 8);
      v16 = ((unsigned __int64)sub_940408C8(*((_QWORD *)a1 + 41)) >> 32) & 0xF;
      v17 = *((_QWORD *)a1 + 41);
      v40 = v40 & 0xF0 | v16 & 0xF;
      v41 = sub_940408C8(v17);
      v39 = a1[84];
      sub_94035678(0x68u, 2u, (__int64)&v39);
      sub_94040888(&v47, 0, 24);
      v47 = *a1;
      sub_9403564C(&v50);
      if ( (unsigned int)(v47 - 7) > 1 )
        v51 &= ~1u;
      else
        v51 |= 2u;
      v18 = a1[15];
      v50 = v50 & 0x89
          | ((a1[5] & 1) << 6)
          | (32 * (a1[6] & 1))
          | (16 * (a1[2] & 1))
          | (4 * (a1[2] != 0))
          | (2 * (a1[1] == 0));
      if ( v18 == 24 )
      {
        v49 = v49 & 0x8F | 0x10;
      }
      else if ( v18 == 16 )
      {
        v49 &= 0x8Fu;
      }
      else
      {
        v49 = v49 & 0x8F | 0x20;
      }
      switch ( *a1 )
      {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
          v49 = v49 & 0xF8 | *a1 & 7;
          break;
        case 7:
          v49 = v49 & 0xF8 | 1;
          break;
        case 8:
          v49 = v49 & 0xF8 | 4;
          break;
        default:
          break;
      }
      v19 = *((_QWORD *)a1 + 18);
      v48 = v48 & 0xEF | (16 * (a1[4] & 1)) | 1;
      v20 = ((unsigned __int64)sub_940408C8(v19) >> 32) & 0xF;
      v21 = *((_QWORD *)a1 + 18);
      v54 = v54 & 0xF0 | v20 & 0xF;
      v22 = ((unsigned __int64)sub_940408C8(v21) >> 32) & 0xF;
      v23 = *((_QWORD *)a1 + 18);
      v54 = v54 & 0xF | (16 * (v22 & 0xF));
      v52 = sub_940408C8(v23);
      v53 = sub_940408C8(*((_QWORD *)a1 + 18));
      return sub_940356F0(&v47);
  }
}

/* ===== sub_94036570 @ 0x94036570 size 416 ===== */
__int64 __fastcall sub_94036570(int *a1)
{
  _DWORD *v2; // x22
  __int64 v3; // x22
  __int64 v4; // x0
  __int64 v5; // x22
  unsigned __int64 v6; // x1
  __int64 v7; // x0
  unsigned __int64 v8; // x2
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned __int64 v11; // x2
  __int64 v12; // x0
  int v13; // w0
  int v15; // [xsp+3Ch] [xbp+3Ch] BYREF
  _DWORD v16[3]; // [xsp+40h] [xbp+40h] BYREF
  int v17; // [xsp+4Ch] [xbp+4Ch] BYREF
  int v18; // [xsp+50h] [xbp+50h] BYREF
  int v19; // [xsp+58h] [xbp+58h] BYREF
  char v20; // [xsp+5Ch] [xbp+5Ch]
  char v21; // [xsp+5Eh] [xbp+5Eh]
  char v22; // [xsp+5Fh] [xbp+5Fh]
  _BYTE v23[2]; // [xsp+60h] [xbp+60h] BYREF
  char v24; // [xsp+62h] [xbp+62h]

  v2 = *((_DWORD **)a1 + 2);
  *v2 = sub_94037818(0, 0);
  v3 = *((_QWORD *)a1 + 2);
  v4 = sub_940408C8(*((_QWORD *)a1 + 39));
  *(_DWORD *)(v3 + 4) = sub_94037730(0, 0, 1, v4 & 0x1FFFF);
  v5 = *((_QWORD *)a1 + 2);
  *(_DWORD *)(v5 + 8) = sub_94037700();
  v15 = a1[80];
  sub_940356B4(0xD0u, 1u, (__int64)&v15);
  sub_94040888(v16, 0, 20);
  v18 = 0;
  v6 = ((unsigned __int64)sub_940408C8(*((_QWORD *)a1 + 39)) >> 17) & 0x7FFFF;
  v7 = *((_QWORD *)a1 + 2);
  v17 = v6;
  v8 = ((unsigned __int64)sub_940408C8(v7) >> 32) & 0xF;
  v9 = *((_QWORD *)a1 + 2);
  HIBYTE(v16[0]) = HIBYTE(v16[0]) & 0xF0 | v8 & 0xF;
  v16[2] = sub_940408C8(v9);
  v16[0] = v16[0] & 0xFF000000 | 0xC;
  sub_940356B4(0x610u, 1u, (__int64)&v18);
  sub_940356B4(0x60Cu, 1u, (__int64)&v17);
  sub_940408B8(*((_QWORD *)a1 + 2), v16[0] & 0xFFFFFF);
  sub_94040888(&v19, 0, 24);
  v19 = *a1;
  sub_9403564C(v23);
  v10 = *((_QWORD *)a1 + 2);
  v23[0] |= 0x16u;
  v24 = v24 & 0x3F | 0x80;
  v20 |= 3u;
  v21 = -1;
  v22 = v22 & 0xF0 | 3;
  v11 = ((unsigned __int64)sub_940408C8(v10) >> 32) & 0xF;
  v12 = *((_QWORD *)a1 + 2);
  v22 = v22 & 0xF | (16 * (v11 & 0xF));
  v13 = sub_940408C8(v12);
  return sub_9403573C(&v19, v13);
}

/* ===== sub_94036710 @ 0x94036710 size 272 ===== */
__int64 __fastcall sub_94036710(int *a1)
{
  unsigned int v2; // w1

  v2 = *a1 & 0xFFFF0000;
  if ( v2 == 84017152 )
  {
    sub_94035DFC(a1);
    a1[1] = 1;
    return 1;
  }
  else if ( v2 <= 0x5020000 )
  {
    switch ( v2 )
    {
      case 0x2000000u:
        sub_940357EC(a1);
        a1[1] = 1;
        return 1;
      case 0x5010000u:
        sub_94035A1C(a1);
        a1[1] = 1;
        return 1;
      case 0u:
        sub_940360B8(a1);
        a1[1] = 1;
        return 1;
      default:
LABEL_7:
        a1[1] = 1;
        return 1;
    }
  }
  else if ( v2 == 84148224 )
  {
    sub_94036570(a1);
    a1[1] = 1;
    return 1;
  }
  else
  {
    if ( v2 != 84213760 )
    {
      if ( v2 == 84082688 )
        sub_94035954(a1);
      goto LABEL_7;
    }
    sub_94035C48(a1);
    a1[1] = 1;
    return 1;
  }
}

/* ===== sub_94036820 @ 0x94036820 size 24 ===== */
__int64 sub_94036820()
{
  return (unsigned int)(109 - MEMORY[0x504]);
}

/* ===== sub_94036838 @ 0x94036838 size 16 ===== */
__int64 sub_94036838()
{
  return MEMORY[0x514];
}

/* ===== sub_94036848 @ 0x94036848 size 24 ===== */
__int64 sub_94036848()
{
  return (unsigned int)(109 - MEMORY[0x604]);
}

/* ===== sub_94036860 @ 0x94036860 size 16 ===== */
__int64 sub_94036860()
{
  return MEMORY[0x614];
}

/* ===== sub_94036870 @ 0x94036870 size 232 ===== */
__int64 sub_94036870()
{
  int v0; // w19
  int v1; // w21
  int v2; // w20
  const void *v3; // x0

  MEMORY[0x15C] = 1;
  while ( (MEMORY[0x15C] & 2) == 0 )
    ;
  v0 = MEMORY[0x20];
  MEMORY[0x24] = MEMORY[0x20];
  v1 = sub_94036838();
  v2 = sub_94036860();
  MEMORY[0x15C] = 16;
  if ( (v0 & 1) != 0 && v1 != 0 )
  {
    do
    {
      sub_94040A7C(0, 0);
      --v1;
    }
    while ( v1 != 0 );
  }
  if ( (v0 & 0x2000) != 0 && v2 != 0 )
  {
    do
    {
      sub_94040A7C(0, 0);
      --v2;
    }
    while ( v2 != 0 );
  }
  if ( (v0 & 0x5C10) != 0 )
  {
    while ( 1 )
    {
      v3 = (const void *)sub_94040A98();
      sub_940407DC(3, "%p: %s: %s: int status = 0x%x\n", v3, "SPRD_CE", "sprd_ce_int_notify", v0);
    }
  }
  return 1;
}

/* ===== sub_94036958 @ 0x94036958 size 12 ===== */
// write access to const memory has been detected, the output may be wrong!
void *__fastcall sub_94036958(void *result)
{
  off_94067960 = result;
  return result;
}

/* ===== sub_94036964 @ 0x94036964 size 12 ===== */
// write access to const memory has been detected, the output may be wrong!
void *__fastcall sub_94036964(void *result)
{
  off_94067938 = result;
  return result;
}

/* ===== sub_94036970 @ 0x94036970 size 84 ===== */
__int64 sub_94036970()
{
  if ( MEMORY[0x58] != 3 )
    MEMORY[0x58] = 3;
  sub_94034308(22);
  sub_94036838();
  sub_94036860();
  MEMORY[0x24] = -1;
  MEMORY[0x1C] = 31761;
  return 0;
}

/* ===== sub_940369C4 @ 0x940369C4 size 20 ===== */
__int64 sub_940369C4()
{
  MEMORY[0x1C] = 0;
  return sub_940343A8(22);
}

/* ===== sub_940369D8 @ 0x940369D8 size 456 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_940369D8()
{
  int v0; // w0
  int v1; // w0
  const void *v2; // x0
  const void *v4; // x0
  const void *v5; // x0
  const void *v6; // x0
  int v7; // [xsp+28h] [xbp+28h]
  int v8; // [xsp+28h] [xbp+28h]

  v0 = sub_940408CC("sprd_ce", 568328192, 0x100000, 2, &off_94067958);
  if ( v0 != 0 )
  {
    v8 = v0;
    v4 = (const void *)sub_94040A98();
    sub_940407DC(3, "%p: %s: %s: sprd_pal_mem_map failed[0x%x]\n", v4, "SPRD_CE", "sprd_ce_init", v8);
  }
  v1 = sub_940408CC("sprd_clk", 558891008, 0x10000, 2, &off_94067970);
  if ( v1 != 0 )
  {
    v7 = v1;
    v2 = (const void *)sub_94040A98();
    sub_940407DC(3, "%p: %s: %s: sprd_pal_mem_map ap clk phys failed[0x%x]\n", v2, "SPRD_CE", "sprd_ce_init", v7);
  }
  dword_94067968 = 85;
  qword_94067940 = sub_940409F8(0);
  v6 = (const void *)sub_94040A98();
  sub_940407DC(3, "%p: %s: %s: sem init FAILED!\n", v6, "SPRD_CE", "sprd_ce_irq_init");
  qword_94067950 = sub_940409F8(0);
  v5 = (const void *)sub_94040A98();
  sub_940407DC(3, "%p: %s: %s: sem pka init FAILED!\n", v5, "SPRD_CE", "sprd_ce_irq_init");
  qword_94067930 = sub_94040A8C("sprd_ce_int_thread", sub_9403560C, 0, 28, 4096);
  sub_94040A94(nullptr);
  qword_94067948 = sub_94040A8C("sprd_ce_int_thread_pka", sub_940355CC, 0, 28, 4096);
  sub_94040A94(nullptr);
  sub_9404078C(0, sub_94036870, 0);
  return sub_94040788(0);
}

/* ===== sub_94036BA0 @ 0x94036BA0 size 136 ===== */
__int64 sub_94036BA0()
{
  unsigned int v0; // w21
  __int64 v1; // x0
  __int64 v2; // x19

  if ( (unsigned int)sub_9404096C(0) == 0 )
  {
    while ( 1 )
    {
      v1 = sub_9403547C(-536472936);
      v2 = v1;
      if ( v1 == 0 )
        break;
      v0 = sub_94035768(*(_DWORD **)(v1 + 16));
      if ( v0 > (unsigned int)sub_94036848() )
        break;
      sub_94035484(-536472936);
      sub_94036710(*(int **)(v2 + 16));
    }
    sub_94040974(0);
  }
  return 0;
}

/* ===== sub_94036C28 @ 0x94036C28 size 112 ===== */
__int64 __fastcall sub_94036C28(int *a1)
{
  int i; // w20
  __int64 *v2; // x0
  __int64 *v3; // x19
  __int64 v4; // x1
  __int64 v5; // x0
  __int64 v6; // x0

  for ( i = *a1; i != 0; --i )
  {
    v2 = sub_940354E0((_QWORD *)0xFFFFFFFFE0061298LL);
    v3 = v2;
    v4 = 0;
    if ( v2 != nullptr )
    {
      v5 = v2[2];
      if ( v5 != 0 )
      {
        v6 = *(_QWORD *)(v5 + 344);
        if ( v6 != 0 )
          sub_94040A7C(v6, 0);
      }
      sub_940408AC(v3, v4);
    }
  }
  sub_94036BA0();
  return 0;
}

/* ===== sub_94036C98 @ 0x94036C98 size 136 ===== */
__int64 sub_94036C98()
{
  unsigned int v0; // w21
  __int64 v1; // x0
  __int64 v2; // x19

  if ( (unsigned int)sub_9404096C(0) == 0 )
  {
    while ( 1 )
    {
      v1 = sub_9403547C(-536472976);
      v2 = v1;
      if ( v1 == 0 )
        break;
      v0 = sub_94035768(*(_DWORD **)(v1 + 16));
      if ( v0 > (unsigned int)sub_94036820() )
        break;
      sub_94035484(-536472976);
      sub_94036710(*(int **)(v2 + 16));
    }
    sub_94040974(0);
  }
  return 0;
}

/* ===== sub_94036D20 @ 0x94036D20 size 112 ===== */
__int64 __fastcall sub_94036D20(int *a1)
{
  int i; // w20
  __int64 *v2; // x0
  __int64 *v3; // x19
  __int64 v4; // x1
  __int64 v5; // x0
  __int64 v6; // x0

  for ( i = *a1; i != 0; --i )
  {
    v2 = sub_940354E0((_QWORD *)0xFFFFFFFFE0061270LL);
    v3 = v2;
    v4 = 0;
    if ( v2 != nullptr )
    {
      v5 = v2[2];
      if ( v5 != 0 )
      {
        v6 = *(_QWORD *)(v5 + 344);
        if ( v6 != 0 )
          sub_94040A7C(v6, 0);
      }
      sub_940408AC(v3, v4);
    }
  }
  sub_94036C98();
  return 0;
}

/* ===== sub_94036D90 @ 0x94036D90 size 552 ===== */
__int64 __fastcall sub_94036D90(int *a1)
{
  unsigned int v2; // w0
  __int64 v3; // x2
  const char *v4; // x1
  unsigned int v5; // w20
  __int64 v6; // x0
  const void *v8; // x0
  __int64 v9; // x0
  _QWORD *v10; // x20
  int v11; // w0
  int v12; // w0
  const void *v13; // x0

  v2 = *a1 & 0xFFFF0000;
  if ( v2 != 84017152 )
  {
    if ( v2 > 0x5020000 )
    {
      if ( v2 != 84148224 )
      {
        if ( v2 == 84213760 || v2 == 84082688 )
          goto LABEL_18;
LABEL_14:
        v8 = (const void *)sub_94040A98();
        v5 = -65535;
        sub_940407DC(3, "%p: %s: %s: bad algo!\n", v8, "SPRD_CE", "sprd_crypto_process");
        goto LABEL_15;
      }
      v5 = -65529;
      if ( a1[80] == 512 )
        goto LABEL_18;
    }
    else
    {
      if ( v2 != 0x2000000 )
      {
        if ( v2 == 83951616 )
        {
          if ( *((_QWORD *)a1 + 2) == 0 || *((_QWORD *)a1 + 3) == 0 || a1[8] == 0 )
          {
            v3 = sub_94040A98();
            v4 = "%p: %s: %s: Bad RSA key!\n";
            goto LABEL_9;
          }
          goto LABEL_18;
        }
        if ( v2 == 0 )
          goto LABEL_18;
        goto LABEL_14;
      }
      if ( a1[76] != 0 || a1[2] != 0 )
        goto LABEL_18;
      v5 = 0;
    }
LABEL_15:
    v6 = *((_QWORD *)a1 + 43);
    if ( v6 == 0 )
      return v5;
LABEL_16:
    sub_94040A7C(v6, 0);
    return v5;
  }
  v12 = a1[8];
  if ( (v12 & 0xFFFFFEFF) != 128 && v12 != 32 && ((v12 - 256) & 0xFFFFFEFF) != 0 )
  {
    v3 = sub_94040A98();
    v4 = "%p: %s: %s: Bad RSA key len!\n";
LABEL_9:
    v5 = -65529;
    sub_940407DC(3, v4, v3, "SPRD_CE", "sprd_crypto_process");
    v6 = *((_QWORD *)a1 + 43);
    if ( v6 == 0 )
      return v5;
    goto LABEL_16;
  }
LABEL_18:
  v9 = sub_94040894(24);
  v10 = (_QWORD *)v9;
  if ( v9 != 0 )
  {
    sub_94040888(v9, 0, 24);
    v11 = *a1;
    v10[2] = a1;
    if ( (v11 & 0xFF000000) == 0x5000000 )
    {
      sub_940353BC((__int64 *)0xFFFFFFFFE0061298LL, v10);
      sub_94036BA0();
    }
    else
    {
      sub_940353BC((__int64 *)0xFFFFFFFFE0061270LL, v10);
      sub_94036C98();
    }
    return 0;
  }
  else
  {
    v13 = (const void *)sub_94040A98();
    sub_940407DC(3, "%p: %s: %s: out of memory !!\n", v13, "SPRD_CE", "sprd_crypto_process");
    return 4294901770LL;
  }
}

/* ===== sub_94036FB8 @ 0x94036FB8 size 20 ===== */
unsigned __int64 __fastcall sub_94036FB8(__int64 a1, __int64 a2, unsigned int a3)
{
  return (a1 - 1 + a3) & ~(unsigned __int64)(a3 - 1);
}

/* ===== sub_94036FCC @ 0x94036FCC size 32 ===== */
__int64 __fastcall sub_94036FCC(int a1, int a2, int a3)
{
  return ((a2 + a1) & -a3) - ((a3 - 1 + a1) & (unsigned int)-a3);
}

/* ===== sub_94036FEC @ 0x94036FEC size 432 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_94036FEC(__int64 a1, unsigned int a2, _QWORD *a3, int *a4)
{
  __int64 result; // x0
  const void *v9; // x0
  int v10; // w0

  if ( a3 != nullptr && a4 != nullptr )
  {
    result = a2 & 0x3F;
    if ( (a2 & 0x3F) != 0 )
    {
      *a3 = 0;
    }
    else
    {
      while ( (unsigned int)sub_9404096C(0) != 0 )
        ;
      qword_94067998 = sub_94036FB8(0, 0, a2);
      v10 = sub_94036FCC(0, 0, a2);
      *a3 = 0;
      *(_QWORD *)&algn_940679A4[4] = a1;
      *a4 = v10;
      dword_940679A0 = v10;
      return sub_94040974(0);
    }
  }
  else
  {
    v9 = (const void *)sub_94040A98();
    return sub_940407DC(3, "%p: %s: %s: buf = NULL or len = NULL\n", v9, "SPRD_CE", "sprd_crypto_malloc_buf");
  }
  return result;
}

/* ===== sub_9403719C @ 0x9403719C size 420 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_9403719C(__int64 result)
{
  __int64 v1; // x0
  const void *v2; // x0

  if ( result != 0 )
  {
    while ( (unsigned int)sub_9404096C(0) != 0 )
      ;
    v1 = sub_94040974(0);
    v2 = (const void *)sub_94040A98(v1);
    return sub_940407DC(3, "%p: %s: %s: an addr is not in buf list !\n", v2, "SPRD_CE", "sprd_crypto_free_buf");
  }
  return result;
}

/* ===== sub_94037340 @ 0x94037340 size 56 ===== */
__int64 sub_94037340()
{
  __int64 result; // x0

  result = sub_9404096C(0);
  if ( (_DWORD)result == 0 )
    return sub_94040974(0);
  return result;
}

/* ===== sub_94037378 @ 0x94037378 size 160 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_94037378(_DWORD *a1)
{
  int v2; // w1
  bool v3; // cf

  sub_9404096C(0);
  sub_94036970();
  v2 = *a1 - 7;
  v3 = *a1 != 7;
  dword_94067AC8 = 1;
  if ( v2 == 1 || !v3 )
    sub_9403CC8C();
  sub_94040974(0);
  return 0;
}

/* ===== sub_94037418 @ 0x94037418 size 152 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_94037418(int *a1)
{
  int v2; // w1

  sub_9404096C(0);
  v2 = *a1;
  dword_94067AC8 = -1;
  if ( (unsigned int)(v2 - 7) <= 1 )
    sub_9403CC90();
  sub_94037340();
  sub_94040974(0);
  return 0;
}

/* ===== sub_940374B0 @ 0x940374B0 size 68 ===== */
__int64 __fastcall sub_940374B0(unsigned __int64 a1)
{
  unsigned int v1; // w2
  unsigned __int64 v2; // x0
  int i; // w1

  v1 = 0;
  if ( a1 != 1 )
  {
    v1 = 1;
    v2 = a1 >> 1;
    for ( i = 2; v2 != 1; i = (unsigned __int8)(i + 1) )
    {
      v1 = i;
      v2 >>= 1;
    }
  }
  return v1;
}

/* ===== sub_940374F4 @ 0x940374F4 size 272 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_940374F4()
{
  unsigned int v0; // w0

  v0 = sub_940374B0(0x40u);
  if ( (unsigned int)sub_94040904("crypto buffer", 0x80000, &qword_94067AE0, v0, 0, 0) == 0 )
    qword_94067980 = sub_9404093C();
  return 4294901760LL;
}

/* ===== sub_94037604 @ 0x94037604 size 252 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_94037604()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 result; // x0
  const void *v4; // x0
  const void *v5; // x0
  const void *v6; // x0

  sub_940374F4();
  sub_940369D8();
  sub_94036958((void *)0xFFFFFFFFE0016D20LL);
  v0 = sub_94035594((_QWORD *)0xFFFFFFFFE0061270LL);
  qword_94067AD0 = sub_9404093C(v0);
  v5 = (const void *)sub_94040A98(0);
  sub_940407DC(3, "%p: %s: %s: mutex init s_crypto_mutex FAILED!\n", v5, "SPRD_CE", "sprd_crypto_init");
  sub_94036964((void *)0xFFFFFFFFE0016C28LL);
  v1 = sub_94035594((_QWORD *)0xFFFFFFFFE0061298LL);
  v2 = sub_9404093C(v1);
  qword_94067AD8 = v2;
  if ( v2 == 0 )
  {
    v6 = (const void *)sub_94040A98(0);
    v2 = sub_940407DC(3, "%p: %s: %s: mutex init s_crypto_mutex_pka FAILED!\n", v6, "SPRD_CE", "sprd_crypto_init");
  }
  result = sub_9404093C(v2);
  qword_94067978 = result;
  if ( result == 0 )
  {
    v4 = (const void *)sub_94040A98(0);
    return sub_940407DC(3, "%p: %s: %s: mutex init s_crypto_count_mutex FAILED!\n", v4, "SPRD_CE", "sprd_crypto_init");
  }
  return result;
}

/* ===== sub_94037700 @ 0x94037700 size 8 ===== */
__int64 sub_94037700()
{
  return 0xFFFFFFFFLL;
}

/* ===== sub_94037708 @ 0x94037708 size 40 ===== */
__int64 __fastcall sub_94037708(char a1, char a2, char a3, int a4)
{
  return a4 & 0x1FFFF | 0xB0000000 | ((a2 & 0x1F) << 18) | ((a1 & 0xF) << 23) | ((a3 & 1) << 17);
}

/* ===== sub_94037730 @ 0x94037730 size 40 ===== */
__int64 __fastcall sub_94037730(char a1, char a2, char a3, int a4)
{
  return a4 & 0x1FFFF | 0xB8000000 | ((a2 & 0x1F) << 18) | ((a1 & 0xF) << 23) | ((a3 & 1) << 17);
}

/* ===== sub_94037758 @ 0x94037758 size 24 ===== */
__int64 __fastcall sub_94037758(char a1, int a2)
{
  return a2 & 0x3FFFF | 0x28000000 | ((unsigned __int8)(a1 & 0x1F) << 18);
}

/* ===== sub_94037770 @ 0x94037770 size 28 ===== */
__int64 __fastcall sub_94037770(char a1, char a2)
{
  return ((a2 & 0x1F) << 18) | 0xF0020805 | ((a1 & 0xF) << 23);
}

/* ===== sub_9403778C @ 0x9403778C size 20 ===== */
__int64 __fastcall sub_9403778C(char a1, int a2)
{
  return ((a2 & 0x1FFFF) << 6) | 0xF8000000 | ((a1 & 0xF) << 23);
}

/* ===== sub_940377A0 @ 0x940377A0 size 36 ===== */
__int64 __fastcall sub_940377A0(char a1, char a2, char a3, char a4)
{
  return ((a4 & 0x1F) << 6) | 0xF8000001 | ((a3 & 0x1F) << 12) | ((a2 & 0x1F) << 18) | ((a1 & 0xF) << 23);
}

/* ===== sub_940377C4 @ 0x940377C4 size 44 ===== */
__int64 __fastcall sub_940377C4(char a1, char a2, char a3, char a4)
{
  return ((a4 & 0x1F) << 6) | 0xF8000002 | ((a3 & 0x1F) << 12) | ((a2 & 0x1F) << 18) | ((a1 & 0xF) << 23);
}

/* ===== sub_940377F0 @ 0x940377F0 size 40 ===== */
__int64 __fastcall sub_940377F0(char a1, char a2, char a3, char a4)
{
  return ((a4 & 0x1F) << 6)
       | 0x58000000
       | ((a3 & 0x1F) << 12)
       | ((a2 & 0x1F) << 18)
       | ((unsigned __int8)(a1 & 0xF) << 23);
}

/* ===== sub_94037818 @ 0x94037818 size 20 ===== */
__int64 __fastcall sub_94037818(char a1, char a2)
{
  return ((a2 & 0x1F) << 18) | 0x8000000 | ((unsigned __int8)(a1 & 0xF) << 23);
}

/* ===== sub_9403782C @ 0x9403782C size 36 ===== */
__int64 __fastcall sub_9403782C(__int64 result, unsigned int a2)
{
  __int64 i; // x2

  for ( i = 0; a2 > (unsigned int)i; ++i )
    *(_DWORD *)(result + 4 * i) &= ~0x80000000;
  return result;
}

/* ===== sub_94037850 @ 0x94037850 size 240 ===== */
__int64 __fastcall sub_94037850(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x2
  __int64 v10; // x2
  __int64 v11; // x2
  __int64 v12; // [xsp+38h] [xbp+38h]
  __int64 v13; // [xsp+38h] [xbp+38h]
  __int64 v14; // [xsp+38h] [xbp+38h]
  _BYTE v15[352]; // [xsp+40h] [xbp+40h] BYREF

  v6 = sub_940382C4(33554436, v15);
  if ( (_DWORD)v6 != 0 )
  {
    v13 = (unsigned int)v6;
    v10 = sub_94040A98(v6);
    return sub_940407DC(3, "%p: %s: %s: sprd_hash_init return [0x%x]\n", v10, "SPRD_CE", "sha256_csum_wd", v13);
  }
  else
  {
    v7 = sub_9403870C(v15, a1, a2);
    if ( (_DWORD)v7 != 0 )
    {
      v12 = (unsigned int)v7;
      v9 = sub_94040A98(v7);
      return sub_940407DC(3, "%p: %s: %s: sprd_hash_process return [0x%x]\n", v9, "SPRD_CE", "sha256_csum_wd", v12);
    }
    else
    {
      result = sub_9403871C(v15, a3);
      if ( (_DWORD)result != 0 )
      {
        v14 = (unsigned int)result;
        v11 = sub_94040A98(result);
        return sub_940407DC(3, "%p: %s: %s: sprd_hash_final return [0x%x]\n", v11, "SPRD_CE", "sha256_csum_wd", v14);
      }
    }
  }
  return result;
}

/* ===== sub_94037940 @ 0x94037940 size 220 ===== */
__int64 __fastcall sub_94037940(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x0
  __int64 result; // x0
  const void *v7; // x0
  const void *v8; // x0
  int v9; // [xsp+18h] [xbp+18h]
  _QWORD v10[4]; // [xsp+20h] [xbp+20h] BYREF
  int v11; // [xsp+44h] [xbp+44h] BYREF
  _QWORD v12[2]; // [xsp+48h] [xbp+48h] BYREF
  int v13; // [xsp+58h] [xbp+58h]
  int v14; // [xsp+5Ch] [xbp+5Ch]
  _QWORD v15[4]; // [xsp+60h] [xbp+60h]

  LODWORD(v15[0]) = 20;
  v12[0] = a2;
  qmemcpy(v10, v15, sizeof(v10));
  v12[1] = a1;
  v13 = a3 >> 3;
  v14 = 4;
  v5 = sub_9403BC1C(v12, a5, 0, a4, (unsigned int)(a3 >> 3), v10, &v11);
  if ( (_DWORD)v5 != 0 )
  {
    v9 = v5;
    v7 = (const void *)sub_94040A98(v5);
    sub_940407DC(3, "%p: %s: %s: sprd_rsa_verify fail(%08x)\n", v7, "SPRD_CE", "RSA_PubDec", v9);
    return 0xFFFFFFFFLL;
  }
  else
  {
    result = (unsigned int)v11;
    if ( v11 <= 0 )
    {
      v8 = (const void *)sub_94040A98((unsigned int)v11);
      sub_940407DC(3, "%p: %s: %s: sprd_rsa_verify result(%08x)\n", v8, "SPRD_CE", "RSA_PubDec", v11);
      return 0xFFFFFFFFLL;
    }
  }
  return result;
}

/* ===== sub_94037A1C @ 0x94037A1C size 472 ===== */
__int64 __fastcall sub_94037A1C(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x2
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x2
  __int64 v10; // x2
  __int64 v11; // x5
  __int64 v12; // x2
  __int64 v13; // [xsp+48h] [xbp+48h]
  __int64 v14; // [xsp+48h] [xbp+48h]
  __int64 v15; // [xsp+48h] [xbp+48h]
  __int64 v16; // [xsp+48h] [xbp+48h]
  __int64 v17; // [xsp+48h] [xbp+48h]
  _BYTE v18[32]; // [xsp+58h] [xbp+58h] BYREF
  char v19[40]; // [xsp+78h] [xbp+78h] BYREF
  _BYTE v20[32]; // [xsp+A0h] [xbp+A0h] BYREF
  _QWORD v21[2]; // [xsp+C0h] [xbp+C0h] BYREF
  _BYTE v22[352]; // [xsp+D0h] [xbp+D0h] BYREF
  _BYTE v23[352]; // [xsp+230h] [xbp+230h] BYREF

  memset(v19, 0, 36);
  memset(v20, 0, sizeof(v20));
  v21[0] = 0;
  v21[1] = 0;
  sub_9403CC40(v18);
  sub_9403782C((__int64)v18, 8u);
  sub_94040880(v20, v18, 32);
  v19[0] = 1;
  strcpy(&v19[1], "I");
  v19[35] = 0x80;
  v2 = sub_9403886C(8, 0, 32, v22);
  if ( (_DWORD)v2 != 0 )
  {
    v13 = (unsigned int)v2;
    v3 = sub_94040A98(v2);
    sub_940407DC(3, "%p: %s: %s: aes cmac init FAILED [%d]\n", v3, "SPRD_CE", "sprd_socid_get", v13);
    return 0xFFFFFFFFLL;
  }
  v5 = sub_94038B24(v22, v19, 36);
  if ( (_DWORD)v5 != 0 )
  {
    v14 = (unsigned int)v5;
    v6 = sub_94040A98(v5);
    sub_940407DC(3, "%p: %s: %s: aes cmac update FAILED [%d]\n", v6, "SPRD_CE", "sprd_socid_get", v14);
    return 0xFFFFFFFFLL;
  }
  v7 = sub_94038CB4(v22, v21);
  if ( (_DWORD)v7 != 0 )
  {
    v16 = (unsigned int)v7;
    v10 = sub_94040A98(v7);
    sub_940407DC(3, "%p: %s: %s: aes cmac final FAILED [%d]\n", v10, "SPRD_CE", "sprd_socid_get", v16);
    return 0xFFFFFFFFLL;
  }
  v8 = sub_940382C4(33554436, v23);
  if ( (_DWORD)v8 != 0 )
  {
    v15 = (unsigned int)v8;
    v9 = sub_94040A98(v8);
    sub_940407DC(3, "%p: %s: %s: sha256 init FAILED [%d]\n", v9, "SPRD_CE", "sprd_socid_get", v15);
    return 0xFFFFFFFFLL;
  }
  result = sub_9403870C(v23, v20, 48);
  v11 = (unsigned int)result;
  if ( (_DWORD)result != 0 || (v11 = (unsigned int)sub_9403871C(v23, a1), result = 0, (_DWORD)v11 != 0) )
  {
    v17 = v11;
    v12 = sub_94040A98(result);
    sub_940407DC(3, "%p: %s: %s: sha256 update FAILED [%d]\n", v12, "SPRD_CE", "sprd_socid_get", v17);
    return 0xFFFFFFFFLL;
  }
  return result;
}

/* ===== sub_94037BF4 @ 0x94037BF4 size 352 ===== */
__int64 __fastcall sub_94037BF4(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4)
{
  char v9[48]; // [xsp+40h] [xbp+40h] BYREF
  _BYTE v10[352]; // [xsp+70h] [xbp+70h] BYREF

  strcpy(v9, "@ABCDEFGHIJKLMNO");
  memset(&v9[17], 0, 31);
  if ( (unsigned int)sub_94037D54(7, 0, v10, 0, 0, 16, v9, 16) != 0
    || (unsigned int)sub_94038198(v10, a1, &v9[16], a2) != 0
    || (unsigned int)sub_940381DC(v10, 0, 0, 0, 0, 0) != 0 )
  {
    return 4294901775LL;
  }
  sub_94040880(a3, &v9[16], a4);
  return 0;
}

/* ===== sub_94037D54 @ 0x94037D54 size 524 ===== */
__int64 __fastcall sub_94037D54(
        int a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        unsigned int a6,
        __int64 a7,
        unsigned int a8)
{
  __int64 v9; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  unsigned int v19; // w1
  const void *v21; // x0
  __int64 v22; // x1
  __int64 v23; // x0
  __int64 v24; // x2
  __int64 v25; // x2
  __int64 v26; // x2

  v9 = (unsigned int)(a1 - 7);
  if ( (unsigned int)v9 > 1 && (a4 == 0 || (_DWORD)(v9 = a6 & 0xFFFFFFF7) != 16 && a6 != 32) )
  {
    v24 = sub_94040A98(v9);
    sub_940407DC(3, "%p: %s: %s: Bad AES key1!\n", v24, "SPRD_CE", "sprd_aes_init");
    return (unsigned int)-65529;
  }
  if ( a1 == 3 && a5 == 0 )
  {
    v25 = sub_94040A98(v9);
    sub_940407DC(3, "%p: %s: %s: Bad AES key2!\n", v25, "SPRD_CE", "sprd_aes_init");
    return (unsigned int)-65529;
  }
  if ( (a1 & 0xFFFFFFFB) != 0 && a1 != 8 && (a7 == 0 || a8 != 16) )
  {
    v26 = sub_94040A98(v9);
    sub_940407DC(3, "%p: %s: %s: Bad AES iv!\n", v26, "SPRD_CE", "sprd_aes_init");
    return (unsigned int)-65529;
  }
  sub_94040888(a3, 0, 352);
  v17 = sub_9404089C(128, 64);
  *(_QWORD *)(a3 + 144) = v17;
  if ( v17 == 0 )
    return (unsigned int)-65526;
  sub_940408B0(v17, 128);
  *(_DWORD *)a3 = a1;
  *(_DWORD *)(a3 + 16) = a2;
  if ( a4 != 0 )
    sub_94040880(a3 + 28, a4, a6);
  *(_DWORD *)(a3 + 60) = a6;
  if ( a5 != 0 )
  {
    sub_94040880(a3 + 64, a5, a6);
    *(_DWORD *)(a3 + 96) = a6;
  }
  if ( a7 != 0 )
  {
    sub_94040880(a3 + 100, a7, a8);
    *(_DWORD *)(a3 + 116) = a8;
  }
  v18 = sub_94037378((_DWORD *)a3);
  v19 = 0;
  if ( (_DWORD)v18 == 0 )
    return v19;
  v21 = (const void *)sub_94040A98(v18);
  sub_940407DC(3, "%p: %s: %s: FAILED!\n", v21, "SPRD_CE", "sprd_aes_init");
  v23 = *(_QWORD *)(a3 + 144);
  if ( v23 != 0 )
  {
    sub_940408AC(v23, v22);
    *(_QWORD *)(a3 + 144) = 0;
  }
  return 4294901760LL;
}

/* ===== sub_94037F60 @ 0x94037F60 size 568 ===== */
__int64 __fastcall sub_94037F60(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  int v8; // w25
  __int64 v9; // x24
  __int64 v10; // x0
  const void *v11; // x19
  unsigned int v12; // w21
  __int64 v13; // x23
  __int64 v14; // x0
  const void *v15; // x0
  unsigned int v16; // w19
  int v17; // w0
  const void *v18; // x2
  __int64 v19; // x1
  unsigned int v20; // w28
  __int64 result; // x0
  const void *v22; // x0
  __int64 v23; // x1
  __int64 v24; // x0
  const void *v25; // x0
  unsigned int v26; // [xsp+64h] [xbp+64h] BYREF
  const void *v27; // [xsp+68h] [xbp+68h] BYREF

  v27 = nullptr;
  v8 = *(_DWORD *)(a1 + 8);
  v9 = sub_940409F8(0);
  if ( v9 == 0 )
    return 4294901770LL;
  v10 = sub_94036FEC(a1, 0x40u, &v27, (int *)&v26);
  v11 = v27;
  if ( v27 != nullptr && (v10 = v26, v26 > 0x3F) )
  {
    v12 = (v26 - 1 + a3) / v26;
    if ( v12 == 0 )
    {
LABEL_13:
      sub_94040A34(v9);
      result = (__int64)v27;
      if ( v27 != nullptr )
      {
        sub_9403719C((__int64)v27);
        return 0;
      }
      return result;
    }
    v13 = a2;
    while ( 1 )
    {
      v15 = v11;
      if ( v12 == 1 )
      {
        v16 = a3 + a2 - v13;
        sub_94040880(v15, v13, v16);
        v17 = (unsigned __int8)v8;
      }
      else
      {
        v16 = v26;
        sub_94040880(v15, v13, v26);
        v17 = 0;
      }
      v18 = v27;
      v19 = v26;
      *(_DWORD *)(a1 + 8) = v17;
      *(_QWORD *)(a1 + 296) = v18;
      *(_QWORD *)(a1 + 312) = v18;
      *(_DWORD *)(a1 + 304) = v16;
      *(_DWORD *)(a1 + 320) = v16;
      *(_QWORD *)(a1 + 344) = v9;
      sub_940408B0(v18, v19);
      v20 = sub_94036D90((int *)a1);
      if ( v20 != 0 )
        break;
      sub_94040A74(v9);
      if ( a4 != 0 )
      {
        sub_940408C0(v27, v26);
        v14 = a4;
        a4 += v16;
        v13 += v16;
        sub_94040880(v14, v27, v16);
        if ( --v12 == 0 )
          goto LABEL_13;
      }
      else
      {
        --v12;
        v13 += v16;
        if ( v12 == 0 )
          goto LABEL_13;
      }
      v11 = v27;
    }
    v25 = (const void *)sub_94040A98(v9);
    sub_940407DC(3, "%p: %s: %s: sprd_crypto_process return 0x%x\n", v25, "SPRD_CE", "sprd_aes_process_internal", v20);
  }
  else
  {
    v22 = (const void *)sub_94040A98(v10);
    v20 = -65526;
    sub_940407DC(3, "%p: %s: %s: buf = %p, buf_len is %d!\n", v22, "SPRD_CE", "sprd_aes_process_internal", v27, v26);
  }
  if ( v27 != nullptr )
    sub_9403719C((__int64)v27);
  sub_94040A34(v9);
  v24 = *(_QWORD *)(a1 + 144);
  if ( v24 != 0 )
  {
    sub_940408AC(v24, v23);
    *(_QWORD *)(a1 + 144) = 0;
  }
  sub_94037418((int *)a1);
  return v20;
}

/* ===== sub_94038198 @ 0x94038198 size 68 ===== */
__int64 __fastcall sub_94038198(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  if ( a2 == 0 || a3 == 0 || a4 == 0 || (a4 & 0xF) != 0 )
    return 4294901767LL;
  *(_DWORD *)(a1 + 8) = 0;
  return sub_94037F60(a1, a2, a4, a3);
}

/* ===== sub_940381DC @ 0x940381DC size 232 ===== */
__int64 __fastcall sub_940381DC(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, unsigned int *a5, unsigned int a6)
{
  unsigned int v9; // w22
  __int64 v10; // x0
  __int64 v12; // x0
  const void *v13; // x0

  if ( a2 != 0 && (a4 == 0 || a5 == nullptr || *a5 < a3) || (a3 & 0xF) != 0 || a6 > 2 )
    return 4294901767LL;
  if ( a2 == 0 || a3 == 0 )
    goto LABEL_9;
  *(_DWORD *)(a1 + 8) = 1;
  v12 = sub_94037F60(a1, a2, a3, a4);
  v9 = v12;
  if ( (_DWORD)v12 != 0 )
  {
    v13 = (const void *)sub_94040A98(v12);
    sub_940407DC(3, "%p: %s: %s: sprd_aes_process_internal FAILED[0x%x]\n", v13, "SPRD_CE", "sprd_aes_final", v9);
    goto LABEL_10;
  }
  if ( a5 != nullptr )
    *a5 = a3;
  else
LABEL_9:
    v9 = 0;
LABEL_10:
  v10 = *(_QWORD *)(a1 + 144);
  if ( v10 != 0 )
  {
    sub_940408AC(v10, a2);
    *(_QWORD *)(a1 + 144) = 0;
  }
  sub_94037418((int *)a1);
  return v9;
}

/* ===== sub_940382C4 @ 0x940382C4 size 156 ===== */
__int64 __fastcall sub_940382C4(int a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x0
  unsigned int v6; // w1
  const void *v8; // x0

  sub_94040888(a2, 0, 352);
  v4 = sub_9404089C(128, 64);
  *(_QWORD *)(a2 + 152) = v4;
  if ( v4 != 0 )
  {
    sub_940408B0(v4, 128);
    *(_DWORD *)a2 = a1;
    v5 = sub_94037378((_DWORD *)a2);
    v6 = 0;
    if ( (_DWORD)v5 != 0 )
    {
      v8 = (const void *)sub_94040A98(v5);
      sub_940407DC(3, "%p: %s: %s: FAILED!\n", v8, "SPRD_CE", "sprd_hash_init");
      return (unsigned int)-65536;
    }
  }
  else
  {
    return (unsigned int)-65526;
  }
  return v6;
}

/* ===== sub_94038360 @ 0x94038360 size 940 ===== */
__int64 __fastcall sub_94038360(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, unsigned int a5)
{
  __int64 v6; // x26
  int v10; // w23
  __int64 v11; // x21
  __int64 v12; // x0
  unsigned int v13; // w1
  const void *v14; // x0
  unsigned int v15; // w20
  __int64 v16; // x1
  __int64 v17; // x0
  __int64 v19; // x2
  int v20; // w22
  __int64 v21; // x24
  unsigned int v22; // w28
  unsigned int v23; // w22
  unsigned int v24; // w20
  __int64 v25; // x1
  char *v26; // x2
  __int64 v27; // x1
  __int64 v28; // x0
  __int64 v29; // x2
  int v30; // w3
  __int64 v31; // x1
  char *v32; // x0
  __int64 v33; // x1
  __int64 v34; // x24
  char *v35; // x0
  __int64 v36; // x0
  __int64 v37; // x2
  unsigned int v38; // [xsp+6Ch] [xbp+6Ch]
  unsigned int v39; // [xsp+74h] [xbp+74h] BYREF
  char *v40; // [xsp+78h] [xbp+78h] BYREF

  v6 = a3;
  v40 = nullptr;
  v10 = *(_DWORD *)(a1 + 8);
  v11 = sub_940409F8(0);
  if ( v11 == 0 )
    return 4294901770LL;
  sub_94036FEC(a1, 0x80u, &v40, (int *)&v39);
  v12 = (__int64)v40;
  if ( v40 != nullptr )
  {
    v13 = v39;
    if ( v39 > 0x7F )
    {
      *(_QWORD *)(a1 + 344) = v11;
      v19 = *(unsigned int *)(a1 + 16);
      if ( (_BYTE)v10 != 0 )
      {
        sub_94040880(v12, a1 + 20, v19);
        *(_DWORD *)(a1 + 320) = a5;
        v30 = *(_DWORD *)(a1 + 16);
        v31 = v39;
        v32 = v40;
        *(_QWORD *)(a1 + 296) = v40;
        *(_DWORD *)(a1 + 304) = v30;
        *(_QWORD *)(a1 + 312) = v32;
        sub_940408B0(v32, v31);
        v28 = sub_94036D90((int *)a1);
        v15 = v28;
        if ( (_DWORD)v28 != 0 )
        {
LABEL_27:
          v29 = sub_94040A98(v28);
          sub_940407DC(3, "%p: %s: %s: sprd_crypt_process return 0x%x\n", v29, "SPRD_CE", "sprd_hash_process", v15);
          goto LABEL_5;
        }
        sub_94040A74(v11);
        sub_94040A34(v11);
        if ( (unsigned __int8)v10 == 1 )
        {
          sub_940408C0(v40, v39);
          sub_94040880(a4, v40, a5);
        }
LABEL_31:
        if ( v40 != nullptr )
        {
          sub_9403719C((__int64)v40);
          return 0;
        }
        return 0;
      }
      v20 = v6 + v19;
      if ( (_DWORD)v6 + (_DWORD)v19 == 0 )
      {
LABEL_12:
        sub_9403719C(v12);
LABEL_13:
        sub_94040A34(v11);
        return 0;
      }
      if ( (unsigned int)(v20 - 1) <= 0x7E )
      {
        sub_94040880(a1 + (unsigned int)v19 + 20, a2, (unsigned int)v6);
        *(_DWORD *)(a1 + 16) = v20;
        v12 = (__int64)v40;
        if ( v40 == nullptr )
          goto LABEL_13;
        goto LABEL_12;
      }
      v21 = a2;
      if ( (_DWORD)v19 != 0 )
      {
        v20 -= 128;
        sub_94040880(v12, a1 + 20, v19);
        sub_94040880(&v40[*(unsigned int *)(a1 + 16)], a2, (unsigned int)(128 - *(_DWORD *)(a1 + 16)));
        v33 = v39;
        v34 = *(unsigned int *)(a1 + 16);
        v35 = v40;
        *(_QWORD *)(a1 + 296) = v40;
        *(_DWORD *)(a1 + 304) = 128;
        *(_QWORD *)(a1 + 312) = v35;
        v21 = a2 + 128 - v34;
        *(_DWORD *)(a1 + 16) = 0;
        *(_DWORD *)(a1 + 320) = a5;
        sub_940408B0(v35, v33);
        v36 = sub_94036D90((int *)a1);
        v15 = v36;
        if ( (_DWORD)v36 != 0 )
        {
          v37 = sub_94040A98(v36);
          sub_940407DC(3, "%p: %s: %s: sprd_crypto_process return 0x%x\n", v37, "SPRD_CE", "sprd_hash_process", v15);
          goto LABEL_5;
        }
        sub_94040A74(v11);
        if ( v20 == 0 )
        {
LABEL_36:
          sub_94040A34(v11);
          goto LABEL_31;
        }
        v13 = v39;
      }
      v38 = v20 & 0x7F;
      v22 = v20 - v38;
      v23 = (v20 - v38) / v13;
      if ( v22 % v13 != 0 )
        ++v23;
      if ( v23 != 0 )
      {
        while ( 1 )
        {
          v24 = v13 > v22 ? v22 : v13;
          v25 = v21;
          v21 += v24;
          v22 -= v24;
          sub_94040880(v40, v25, v24);
          *(_DWORD *)(a1 + 304) = v24;
          v26 = v40;
          v27 = v39;
          *(_QWORD *)(a1 + 296) = v40;
          *(_DWORD *)(a1 + 8) = 0;
          *(_QWORD *)(a1 + 312) = v26;
          *(_DWORD *)(a1 + 320) = a5;
          sub_940408B0(v26, v27);
          v15 = sub_94036D90((int *)a1);
          v28 = v11;
          if ( v15 != 0 )
            goto LABEL_27;
          sub_94040A74(v11);
          if ( --v23 == 0 )
            break;
          v13 = v39;
        }
      }
      if ( v38 != 0 )
      {
        sub_94040880(a1 + 20, a2 + v6 - v38, v38);
        *(_DWORD *)(a1 + 16) = v38;
      }
      goto LABEL_36;
    }
  }
  v14 = (const void *)sub_94040A98(v40);
  v15 = -65526;
  sub_940407DC(3, "%p: %s: %s: buf = %p, buf_len is %d!\n", v14, "SPRD_CE", "sprd_hash_process", v40, v39);
LABEL_5:
  if ( v40 != nullptr )
    sub_9403719C((__int64)v40);
  sub_94040A34(v11);
  v17 = *(_QWORD *)(a1 + 152);
  if ( v17 != 0 )
  {
    sub_940408AC(v17, v16);
    *(_QWORD *)(a1 + 152) = 0;
  }
  sub_94037418((int *)a1);
  return v15;
}

/* ===== sub_9403870C @ 0x9403870C size 16 ===== */
__int64 __fastcall sub_9403870C(__int64 a1, __int64 a2, unsigned int a3)
{
  *(_DWORD *)(a1 + 8) = 0;
  return sub_94038360(a1, a2, a3, 0, 0);
}

/* ===== sub_9403871C @ 0x9403871C size 336 ===== */
__int64 __fastcall sub_9403871C(__int64 a1, __int64 a2)
{
  int v3; // w0
  unsigned int v4; // w4
  __int64 v5; // x0
  __int64 v6; // x1
  unsigned int v7; // w20
  const void *v8; // x0
  unsigned int v9; // w4
  __int64 v10; // x0

  v3 = *(_DWORD *)a1;
  *(_DWORD *)(a1 + 8) = 1;
  if ( v3 == 33554433 )
  {
    v9 = 16;
    goto LABEL_14;
  }
  if ( v3 == 33554434 )
  {
    v9 = 20;
    goto LABEL_14;
  }
  if ( v3 == 33554435 )
    goto LABEL_19;
  if ( v3 == 33554436 )
  {
    v9 = 32;
  }
  else if ( v3 == 33554437 )
  {
    v9 = 48;
  }
  else
  {
    if ( v3 != 33554438 )
    {
      if ( v3 != 33554439 )
      {
        if ( v3 == 33554440 )
          v4 = 32;
        else
          v4 = 0;
        v5 = sub_94038360(a1, 0, 0, a2, v4);
        v7 = v5;
        if ( (_DWORD)v5 == 0 )
          goto LABEL_15;
        goto LABEL_12;
      }
LABEL_19:
      v9 = 28;
      goto LABEL_14;
    }
    v9 = 64;
  }
LABEL_14:
  v5 = sub_94038360(a1, 0, 0, a2, v9);
  v7 = v5;
  if ( (_DWORD)v5 != 0 )
  {
LABEL_12:
    v8 = (const void *)sub_94040A98(v5);
    sub_940407DC(3, "%p: %s: %s: sprd_crypto_hash_process FAILED!\n", v8, "SPRD_CE", "sprd_hash_final");
  }
LABEL_15:
  v10 = *(_QWORD *)(a1 + 152);
  if ( v10 != 0 )
  {
    sub_940408AC(v10, v6);
    *(_QWORD *)(a1 + 152) = 0;
  }
  sub_94037418((int *)a1);
  return v7;
}

/* ===== sub_9403886C @ 0x9403886C size 36 ===== */
__int64 __fastcall sub_9403886C(int a1, __int64 a2, unsigned int a3, __int64 a4)
{
  return sub_94037D54(a1, 0, a4, a2, 0, a3, 0, 0);
}

/* ===== sub_94038890 @ 0x94038890 size 660 ===== */
__int64 __fastcall sub_94038890(__int64 a1, __int64 a2, int a3, __int64 a4, unsigned int a5)
{
  int v10; // w24
  __int64 v11; // x21
  __int64 v12; // x0
  const void *v13; // x2
  __int64 v14; // x1
  int v15; // w28
  unsigned int v16; // w20
  __int64 v17; // x22
  unsigned int v18; // w24
  int v19; // w0
  const void *v20; // x2
  __int64 v21; // x1
  unsigned int v22; // w1
  __int64 v23; // x0
  const void *v25; // x0
  unsigned int v26; // w20
  const void *v27; // x0
  const void *v28; // x0
  int v29; // [xsp+6Ch] [xbp+6Ch]
  unsigned int v30; // [xsp+74h] [xbp+74h] BYREF
  const void *v31; // [xsp+78h] [xbp+78h] BYREF

  v31 = nullptr;
  v10 = *(_DWORD *)(a1 + 8);
  v11 = sub_940409F8(0);
  if ( v11 == 0 )
    return 4294901770LL;
  v12 = sub_94036FEC(a1, 0x40u, &v31, (int *)&v30);
  v13 = v31;
  if ( v31 != nullptr )
  {
    v14 = v30;
    if ( v30 > 0x3F )
    {
      v15 = (unsigned __int8)v10;
      v16 = (v30 - 1 + a3) / v30;
      if ( v16 != 0 )
      {
        v17 = a2;
        v29 = (unsigned __int8)v10;
        while ( 1 )
        {
          if ( v16 == 1 )
          {
            v18 = a3 + a2 - v17;
            sub_94040880(v13, v17, v18);
            v19 = v29;
          }
          else
          {
            v18 = v30;
            sub_94040880(v13, v17, v30);
            v19 = 0;
          }
          v20 = v31;
          v17 += v18;
          v21 = v30;
          *(_DWORD *)(a1 + 8) = v19;
          *(_QWORD *)(a1 + 296) = v20;
          *(_QWORD *)(a1 + 312) = v20;
          *(_QWORD *)(a1 + 328) = v20;
          *(_DWORD *)(a1 + 304) = v18;
          *(_DWORD *)(a1 + 320) = 0;
          *(_DWORD *)(a1 + 336) = a5;
          *(_QWORD *)(a1 + 344) = v11;
          sub_940408B0(v20, v21);
          v22 = sub_94036D90((int *)a1);
          v23 = v11;
          if ( v22 != 0 )
            break;
          sub_94040A74(v11);
          if ( --v16 == 0 )
            goto LABEL_11;
          v13 = v31;
        }
        v26 = v22;
        goto LABEL_25;
      }
      if ( (unsigned __int8)v10 == 1 )
      {
        v27 = v31;
        *(_QWORD *)(a1 + 296) = v31;
        *(_QWORD *)(a1 + 312) = v13;
        *(_QWORD *)(a1 + 328) = v13;
        *(_DWORD *)(a1 + 8) = 1;
        *(_DWORD *)(a1 + 304) = 0;
        *(_DWORD *)(a1 + 320) = 0;
        *(_DWORD *)(a1 + 336) = a5;
        *(_QWORD *)(a1 + 344) = v11;
        sub_940408B0(v27, v14);
        v23 = sub_94036D90((int *)a1);
        v26 = v23;
        if ( (_DWORD)v23 != 0 )
        {
LABEL_25:
          v28 = (const void *)sub_94040A98(v23);
          sub_940407DC(
            3,
            "%p: %s: %s: sprd_crypto_process return 0x%x\n",
            v28,
            "SPRD_CE",
            "sprd_cmac_process_internal",
            v26);
          goto LABEL_18;
        }
        sub_94040A74(v11);
LABEL_11:
        if ( a4 != 0 && v15 == 1 )
        {
          sub_940408C0(v31, v30);
          sub_94040880(a4, v31, a5);
        }
      }
      sub_94040A34(v11);
      if ( v31 != nullptr )
        sub_9403719C((__int64)v31);
      return 0;
    }
  }
  v25 = (const void *)sub_94040A98(v12);
  v26 = -65526;
  sub_940407DC(3, "%p: %s: %s: buf = %p, buf_len is %d!\n", v25, "SPRD_CE", "sprd_cmac_process_internal", v31, v30);
LABEL_18:
  if ( v31 != nullptr )
    sub_9403719C((__int64)v31);
  sub_94040A34(v11);
  sub_940381DC(a1, 0, 0, 0, nullptr, 0);
  return v26;
}

/* ===== sub_94038B24 @ 0x94038B24 size 400 ===== */
__int64 __fastcall sub_94038B24(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w4
  int v6; // w20
  int v7; // w22
  __int64 v8; // x0
  unsigned int v9; // w22
  int v10; // w0
  unsigned int v11; // w20
  unsigned int v12; // w22
  __int64 v13; // x21
  __int64 v14; // x2
  __int64 result; // x0
  unsigned int v16; // w19
  const void *v17; // x0
  const void *v18; // x0

  if ( (_DWORD)a3 == 0 )
    return 0;
  v3 = *(_DWORD *)(a1 + 120);
  *(_DWORD *)(a1 + 8) = 0;
  v6 = a3 + v3;
  v7 = a3;
  if ( (unsigned int)a3 + v3 <= 0x10 )
  {
    sub_94040880(a1 + v3 + 124, a2, a3);
    *(_DWORD *)(a1 + 120) += v7;
    return 0;
  }
  sub_94040880(a1 + v3 + 124, a2, 16 - v3);
  v8 = sub_94038890(a1, a1 + 124, 16, 0, 0);
  v9 = v8;
  if ( (_DWORD)v8 != 0 )
  {
    v18 = (const void *)sub_94040A98(v8);
    sub_940407DC(3, "%p: %s: %s: sprd_cmac_process_internal FAILED[0x%x]\n", v18, "SPRD_CE", "sprd_cmac_update", v9);
    return v9;
  }
  v10 = *(_DWORD *)(a1 + 120);
  v11 = v6 - 16;
  *(_DWORD *)(a1 + 120) = 0;
  v12 = v11 & 0xF;
  v13 = a2 + (unsigned int)(16 - v10);
  if ( (v11 & 0xF) != 0 )
  {
    v14 = v11 & 0xF;
  }
  else
  {
    v14 = 16;
    v12 = 16;
  }
  sub_94040880(a1 + 124, v13 + v11 - v14, v12);
  *(_DWORD *)(a1 + 120) = v12;
  if ( v11 == v12 )
    return 0;
  v16 = sub_94038890(a1, v13, v11 - v12, 0, 0);
  result = 0;
  if ( v16 != 0 )
  {
    v17 = (const void *)sub_94040A98(0);
    sub_940407DC(3, "%p: %s: %s: sprd_cmac_process_internal FAILED[0x%x]\n", v17, "SPRD_CE", "sprd_cmac_update", v16);
    return v16;
  }
  return result;
}

/* ===== sub_94038CB4 @ 0x94038CB4 size 156 ===== */
__int64 __fastcall sub_94038CB4(__int64 a1, __int64 a2)
{
  int v3; // w2
  __int64 v4; // x0
  unsigned int v5; // w20
  const void *v7; // x0

  if ( a2 == 0 )
    return 4294901767LL;
  v3 = *(_DWORD *)(a1 + 120);
  *(_DWORD *)(a1 + 8) = 1;
  v4 = sub_94038890(a1, a1 + 124, v3, a2, 0x10u);
  v5 = v4;
  if ( (_DWORD)v4 != 0 )
  {
    v7 = (const void *)sub_94040A98(v4);
    sub_940407DC(3, "%p: %s: %s: sprd_cmac_process_internal FAILED[0x%x]\n", v7, "SPRD_CE", "sprd_cmac_final", v5);
  }
  sub_940381DC(a1, 0, 0, 0, nullptr, 0);
  return v5;
}

/* ===== sub_94038D50 @ 0x94038D50 size 160 ===== */
__int64 __fastcall sub_94038D50(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x21
  unsigned int v4; // w20
  _QWORD v6[44]; // [xsp+30h] [xbp+30h] BYREF

  sub_94040888(v6, 0, 352);
  v2 = sub_94037378(v6);
  if ( (_DWORD)v2 != 0 )
    return 4294901760LL;
  v3 = sub_940409F8(v2);
  if ( v3 == 0 )
    return 4294901770LL;
  v6[2] = a1;
  v6[43] = v3;
  LODWORD(v6[0]) = 84082688;
  v4 = sub_94036D90((int *)v6);
  if ( v4 == 0 )
    sub_94040A74(v3);
  sub_94040A34(v3);
  sub_94037418((int *)v6);
  return v4;
}

/* ===== sub_94038DF0 @ 0x94038DF0 size 232 ===== */
__int64 __fastcall sub_94038DF0(unsigned int a1, __int64 a2, __int64 a3, unsigned __int8 a4, __int64 a5)
{
  unsigned int v6; // w22
  _DWORD *v10; // x19
  _DWORD *v11; // x0
  unsigned int v12; // w22
  unsigned int v14; // [xsp+44h] [xbp+44h] BYREF
  _DWORD *v15; // [xsp+48h] [xbp+48h] BYREF

  v6 = a4;
  v15 = nullptr;
  v14 = 0;
  sub_94036FEC(0, 0x1000u, &v15, (int *)&v14);
  sub_94040888(v15, 0, v14);
  v10 = v15;
  v11 = v15;
  *v15 = 1;
  sub_94040880(v11 + 2, (char *)qword_9405B120 + 508 * a1, 508);
  sub_94040880(v10 + 641, a2, 84);
  sub_94040880(v10 + 662, a3, v6);
  *((_BYTE *)v10 + 2728) = v6;
  sub_94038D50((__int64)v10);
  v12 = v10[1];
  sub_94040880(a5, v10 + 683, 164);
  *(_DWORD *)(a5 + 160) = a1;
  sub_9403719C((__int64)v15);
  return v12;
}

/* ===== sub_94038ED8 @ 0x94038ED8 size 272 ===== */
__int64 __fastcall sub_94038ED8(unsigned int a1, __int64 a2, __int64 a3, unsigned __int8 a4, __int64 a5)
{
  unsigned int v5; // w21
  _DWORD *v9; // x19
  unsigned int v10; // w20
  unsigned int v13; // [xsp+54h] [xbp+54h] BYREF
  _DWORD *v14; // [xsp+58h] [xbp+58h] BYREF

  v5 = a4;
  v14 = nullptr;
  v13 = 0;
  sub_94036FEC(0, 0x1000u, &v14, (int *)&v13);
  sub_94040888(v14, 0, v13);
  v9 = v14;
  *v14 = 2;
  sub_94040880(v9 + 2, (char *)qword_9405B120 + 508 * a1, 508);
  sub_94040880(v9 + 641, a2, 164);
  sub_94040880(v9 + 682, a3, v5);
  *((_BYTE *)v9 + 2808) = v5;
  sub_94040880(v9 + 703, a5, 164);
  sub_94038D50((__int64)v9);
  v10 = v9[1];
  if ( v10 == 0 )
  {
    if ( (unsigned int)sub_94040870(v9 + 744, v9 + 703, (unsigned int)(4 * v9[126])) != 0 )
      v10 = 261;
    else
      v10 = 0;
  }
  sub_9403719C((__int64)v14);
  return v10;
}

/* ===== sub_94038FE8 @ 0x94038FE8 size 208 ===== */
__int64 __fastcall sub_94038FE8(unsigned int a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 result; // x0
  bool v6; // cc
  __int64 v7; // x0
  int v10; // w21
  _BYTE v12[488]; // [xsp+40h] [xbp+40h] BYREF
  int v13; // [xsp+228h] [xbp+228h]
  int v14; // [xsp+230h] [xbp+230h]

  if ( a2 == 0 || a4 == 0 )
    return 263;
  v6 = a1 > 0xA;
  result = 264;
  if ( !v6 )
  {
    v7 = a1;
    v10 = v7;
    sub_94040880(v12, (char *)qword_9405B120 + 508 * v7, 508);
    if ( a3 <= (unsigned int)(v13 + 7) >> 3 && a3 != 0 )
    {
      sub_94040888(a4, 0, (unsigned int)(4 * v14));
      sub_9403A604(a4, a2, a3);
      *(_DWORD *)(a4 + 80) = v10;
      return 0;
    }
    else
    {
      return 259;
    }
  }
  return result;
}

/* ===== sub_940390B8 @ 0x940390B8 size 240 ===== */
__int64 __fastcall sub_940390B8(unsigned int a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 result; // x0
  unsigned int v9; // w21
  _BYTE v10[484]; // [xsp+40h] [xbp+40h] BYREF
  int v11; // [xsp+224h] [xbp+224h]
  int v12; // [xsp+22Ch] [xbp+22Ch]

  if ( a2 == 0 || a4 == 0 )
    return 263;
  sub_94040880(v10, (char *)qword_9405B120 + 508 * a1, 508);
  result = 259;
  if ( a3 != 0 && a3 <= 2 * ((unsigned int)(v11 + 7) >> 3) )
  {
    v9 = a3 >> 1;
    sub_94040888(a4, 0, (unsigned int)(4 * v12));
    sub_94040888(a4 + 80, 0, (unsigned int)(4 * v12));
    sub_9403A604(a4, a2, v9);
    sub_9403A604(a4 + 80, a2 + v9, v9);
    *(_DWORD *)(a4 + 160) = a1;
    return 0;
  }
  return result;
}

/* ===== sub_940391A8 @ 0x940391A8 size 240 ===== */
__int64 __fastcall sub_940391A8(unsigned int a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 result; // x0
  unsigned int v9; // w21
  _BYTE v10[488]; // [xsp+40h] [xbp+40h] BYREF
  int v11; // [xsp+228h] [xbp+228h]
  int v12; // [xsp+230h] [xbp+230h]

  if ( a2 == 0 || a4 == 0 )
    return 263;
  sub_94040880(v10, (char *)qword_9405B120 + 508 * a1, 508);
  result = 259;
  if ( a3 != 0 && a3 <= 2 * ((unsigned int)(v11 + 7) >> 3) )
  {
    v9 = a3 >> 1;
    sub_94040888(a4, 0, (unsigned int)(4 * v12));
    sub_94040888(a4 + 80, 0, (unsigned int)(4 * v12));
    sub_9403A604(a4, a2, v9);
    sub_9403A604(a4 + 80, a2 + v9, v9);
    *(_DWORD *)(a4 + 160) = a1;
    return 0;
  }
  return result;
}

/* ===== sub_94039298 @ 0x94039298 size 224 ===== */
__int64 __fastcall sub_94039298(__int64 a1, __int64 a2, int *a3)
{
  unsigned int v6; // w22
  int v7; // w0
  _BYTE v9[488]; // [xsp+30h] [xbp+30h] BYREF
  int v10; // [xsp+218h] [xbp+218h]

  if ( a1 == 0 || a3 == nullptr || a2 == 0 )
    return 263;
  sub_94040880(v9, (char *)qword_9405B120 + 508 * *(unsigned int *)(a1 + 160), 508);
  v6 = (unsigned int)(v10 + 7) >> 3;
  v7 = 2 * v6;
  if ( *a3 >= 2 * v6 )
  {
    *a3 = v7;
    sub_9403A604(a2, a1, v6);
    sub_9403A604(a2 + v6, a1 + 80, v6);
    return 0;
  }
  else
  {
    *a3 = v7;
    return 262;
  }
}

/* ===== sub_94039378 @ 0x94039378 size 4748 ===== */
__int64 __fastcall sub_94039378(__int64 a1)
{
  unsigned int v2; // w20
  int v3; // w22
  unsigned int v4; // w28
  unsigned int v5; // w22
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 result; // x0
  unsigned int v17; // w20
  int v18; // w22
  unsigned int v19; // w28
  unsigned int v20; // w22
  unsigned int v21; // w28
  int v22; // w3
  unsigned __int8 *v23; // x1
  unsigned int v24; // w0
  unsigned int v25; // w21
  unsigned int v26; // w20
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  unsigned int v36; // w20
  unsigned int v37; // w21
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  unsigned int v48; // w28
  int v49; // w3
  unsigned __int8 *v50; // x1
  unsigned int v51; // w0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  int v64; // [xsp+64h] [xbp+64h]
  int v65; // [xsp+68h] [xbp+68h]
  __int64 v66; // [xsp+68h] [xbp+68h]
  _BYTE v67[80]; // [xsp+70h] [xbp+70h] BYREF

  switch ( *(_DWORD *)a1 )
  {
    case 0:
      v25 = 4 * *(_DWORD *)(a1 + 504);
      v26 = 4 * *(_DWORD *)(a1 + 500);
      sub_9403A774(v25, 1);
      sub_9403A774(v26, 2);
      sub_9403A6C0(a1 + 516, a1 + 516);
      *(_DWORD *)(a1 + 516) = sub_9403A7CC(0, 17, v25, 1);
      *(_DWORD *)(a1 + 520) = sub_9403A7CC(0, 18, v25, 1);
      *(_DWORD *)(a1 + 524) = sub_9403A7CC(0, 19, v25, 1);
      *(_DWORD *)(a1 + 528) = sub_9403A7CC(0, 20, v25, 1);
      *(_DWORD *)(a1 + 532) = sub_9403A7CC(0, 21, v25, 1);
      v27 = sub_940408C8(a1 + 8);
      *(_DWORD *)(a1 + 536) = sub_9403A7F0(v27, 17, v26, 2);
      v28 = sub_940408C8(a1 + 88);
      *(_DWORD *)(a1 + 540) = sub_9403A7F0(v28, 18, v26, 2);
      v29 = sub_940408C8(a1 + 168);
      *(_DWORD *)(a1 + 544) = sub_9403A7F0(v29, 19, v26, 2);
      v30 = sub_940408C8(a1 + 248);
      *(_DWORD *)(a1 + 548) = sub_9403A7F0(v30, 20, v26, 2);
      v31 = sub_940408C8(a1 + 328);
      *(_DWORD *)(a1 + 552) = sub_9403A7F0(v31, 21, v26, 2);
      v32 = sub_940408C8(a1 + 408);
      *(_DWORD *)(a1 + 556) = sub_9403A7F0(v32, 22, v25, 1);
      *(_DWORD *)(a1 + 560) = sub_9403A638(1, 1, 2, 0, 0, 0, 0, 0);
      *(_DWORD *)(a1 + 564) = sub_9403A638(15, 1, 1, 0, 2, 0, 22, 0);
      *(_DWORD *)(a1 + 568) = sub_9403A638(13, 1, 2, 0, 1, 1, 1, 0);
      *(_DWORD *)(a1 + 572) = sub_9403A734(5, 0, 16, 0);
      *(_DWORD *)(a1 + 576) = sub_9403A638(28, 1, 0, 0, 17, 0, 0, 0);
      *(_DWORD *)(a1 + 580) = sub_9403A638(29, 1, 4, 0, 18, 0, 1, 2);
      *(_DWORD *)(a1 + 584) = sub_9403A638(2, 1, 5, 0, 20, 0, 21, 0);
      *(_DWORD *)(a1 + 588) = sub_9403A734(5, 0, 17, 0);
      v33 = sub_940408C8(a1 + 2564);
      *(_DWORD *)(a1 + 592) = sub_9403A808(1, v33, v25, 1);
      v34 = sub_940408C8(a1 + 2648);
      *(_DWORD *)(a1 + 596) = sub_9403A808(4, v34, v26, 2);
      v35 = sub_940408C8(a1 + 2728);
      *(_DWORD *)(a1 + 600) = sub_9403A808(5, v35, v26, 2);
      *(_DWORD *)(a1 + 604) = -1;
      sub_9403A820(a1 + 516, 92);
      sub_940408B8(a1 + 8, 508);
      sub_940408B8(a1 + 516, 2048);
      sub_940408C0(a1 + 2564, 84);
      sub_940408C0(a1 + 2648, 164);
      result = 0;
      break;
    case 1:
      v2 = 4 * *(_DWORD *)(a1 + 504);
      v3 = *(_DWORD *)(a1 + 500);
      v4 = *(unsigned __int8 *)(a1 + 2728);
      v65 = *(_DWORD *)(a1 + 496);
      sub_94040888(v67, 0, v2);
      v5 = 4 * v3;
      if ( *(_DWORD *)(a1 + 496) < 8 * v4 )
      {
        v48 = (unsigned int)(v65 + 7) >> 3;
        sub_9403A604(v67, a1 + 2648, v48);
        v49 = -*(_DWORD *)(a1 + 496) & 7;
        if ( v49 != 0 )
        {
          if ( (unsigned int)(v65 + 7) >> 3 <= 1 )
          {
            v51 = 0;
          }
          else
          {
            v50 = v67;
            do
            {
              *v50 = (v50[1] << (8 - v49)) | ((int)*v50 >> v49);
              ++v50;
            }
            while ( v50 != &v67[v48 - 1] );
            v51 = v48 - 1;
          }
          v67[v51] = (int)(unsigned __int8)v67[v51] >> v49;
        }
        v4 = (unsigned __int8)((unsigned int)(v65 + 7) >> 3);
      }
      else
      {
        sub_9403A604(v67, a1 + 2648, v4);
      }
      sub_94040888(a1 + 2648, 0, 80);
      sub_94040880(a1 + 2648, v67, v4);
      sub_9403A774(v2, 1);
      sub_9403A774(v5, 2);
      sub_9403A6C0(a1 + 516, a1 + 516);
      *(_DWORD *)(a1 + 516) = sub_9403A7CC(0, 17, v2, 1);
      *(_DWORD *)(a1 + 520) = sub_9403A7CC(0, 18, v2, 1);
      *(_DWORD *)(a1 + 524) = sub_9403A7CC(0, 19, v2, 1);
      *(_DWORD *)(a1 + 528) = sub_9403A7CC(0, 20, v2, 1);
      *(_DWORD *)(a1 + 532) = sub_9403A7CC(0, 21, v2, 1);
      v6 = sub_940408C8(a1 + 8);
      *(_DWORD *)(a1 + 536) = sub_9403A7F0(v6, 17, v5, 2);
      v7 = sub_940408C8(a1 + 88);
      *(_DWORD *)(a1 + 540) = sub_9403A7F0(v7, 18, v5, 2);
      v8 = sub_940408C8(a1 + 168);
      *(_DWORD *)(a1 + 544) = sub_9403A7F0(v8, 19, v5, 2);
      v9 = sub_940408C8(a1 + 248);
      *(_DWORD *)(a1 + 548) = sub_9403A7F0(v9, 20, v5, 2);
      v10 = sub_940408C8(a1 + 328);
      *(_DWORD *)(a1 + 552) = sub_9403A7F0(v10, 21, v5, 2);
      v11 = sub_940408C8(a1 + 408);
      *(_DWORD *)(a1 + 556) = sub_9403A7F0(v11, 22, v2, 1);
      *(_DWORD *)(a1 + 560) = sub_9403A7CC(0, 11, v2, 1);
      v12 = sub_940408C8(a1 + 2564);
      *(_DWORD *)(a1 + 564) = sub_9403A7F0(v12, 11, v2, 1);
      *(_DWORD *)(a1 + 568) = sub_9403A7CC(0, 9, v2, 1);
      v13 = sub_940408C8(a1 + 2648);
      *(_DWORD *)(a1 + 572) = sub_9403A7F0(v13, 9, v4, 1);
      *(_DWORD *)(a1 + 576) = sub_9403A638(15, 1, 2, 0, 9, 0, 22, 0);
      *(_DWORD *)(a1 + 580) = sub_9403A638(1, 1, 3, 0, 0, 0, 0, 0);
      *(_DWORD *)(a1 + 584) = sub_9403A638(15, 1, 1, 0, 3, 0, 22, 0);
      *(_DWORD *)(a1 + 588) = sub_9403A638(13, 1, 3, 0, 1, 1, 1, 0);
      *(_DWORD *)(a1 + 592) = sub_9403A734(5, 0, 16, 0);
      *(_DWORD *)(a1 + 596) = sub_9403A638(28, 1, 0, 0, 17, 0, 0, 0);
      *(_DWORD *)(a1 + 600) = sub_9403A638(29, 1, 4, 0, 18, 0, 1, 2);
      *(_DWORD *)(a1 + 604) = sub_9403A638(2, 1, 5, 0, 20, 0, 21, 0);
      *(_DWORD *)(a1 + 608) = sub_9403A734(5, 0, 17, 0);
      *(_DWORD *)(a1 + 612) = sub_9403A638(15, 1, 3, 0, 4, 0, 22, 0);
      *(_DWORD *)(a1 + 616) = sub_9403A638(13, 1, 6, 0, 3, 1, 1, 0);
      *(_DWORD *)(a1 + 620) = sub_9403A734(5, 0, 16, 0);
      *(_DWORD *)(a1 + 624) = sub_9403A638(28, 1, 0, 0, 22, 0, 0, 0);
      *(_DWORD *)(a1 + 628) = sub_9403A638(6, 1, 6, 0, 3, 0, 11, 0);
      *(_DWORD *)(a1 + 632) = sub_9403A638(8, 1, 4, 0, 6, 0, 2, 0);
      *(_DWORD *)(a1 + 636) = sub_9403A638(10, 1, 5, 0, 1, 0, 0, 0);
      *(_DWORD *)(a1 + 640) = sub_9403A638(6, 1, 2, 0, 5, 0, 4, 0);
      *(_DWORD *)(a1 + 644) = sub_9403A638(28, 1, 13, 0, 3, 0, 0, 0);
      *(_DWORD *)(a1 + 648) = sub_9403A638(28, 1, 12, 0, 2, 0, 0, 0);
      v14 = sub_940408C8(a1 + 2732);
      *(_DWORD *)(a1 + 652) = sub_9403A808(13, v14, v2, 1);
      v15 = sub_940408C8(a1 + 2812);
      *(_DWORD *)(a1 + 656) = sub_9403A808(12, v15, v2, 1);
      *(_DWORD *)(a1 + 660) = -1;
      sub_9403A820(a1 + 516, 148);
      sub_940408B8(a1 + 8, 508);
      sub_940408B8(a1 + 516, 2048);
      sub_940408B8(a1 + 2564, 84);
      sub_940408B8(a1 + 2648, v4);
      sub_940408C0(a1 + 2732, 164);
      goto LABEL_5;
    case 2:
      v17 = 4 * *(_DWORD *)(a1 + 504);
      v18 = *(_DWORD *)(a1 + 500);
      v19 = *(unsigned __int8 *)(a1 + 2808);
      v64 = *(_DWORD *)(a1 + 496);
      sub_94040888(v67, 0, v17);
      v20 = 4 * v18;
      v66 = a1 + 2976;
      if ( *(_DWORD *)(a1 + 496) >= 8 * v19 )
      {
        sub_9403A604(v67, a1 + 2728, v19);
      }
      else
      {
        v21 = (unsigned int)(v64 + 7) >> 3;
        sub_9403A604(v67, a1 + 2728, v21);
        v22 = -*(_DWORD *)(a1 + 496) & 7;
        if ( v22 != 0 )
        {
          if ( (unsigned int)(v64 + 7) >> 3 <= 1 )
          {
            v24 = 0;
          }
          else
          {
            v23 = v67;
            do
            {
              *v23 = (v23[1] << (8 - v22)) | ((int)*v23 >> v22);
              ++v23;
            }
            while ( v23 != &v67[v21 - 1] );
            v24 = v21 - 1;
          }
          v67[v24] = (int)(unsigned __int8)v67[v24] >> v22;
        }
        v19 = (unsigned __int8)((unsigned int)(v64 + 7) >> 3);
      }
      sub_94040888(a1 + 2728, 0, 80);
      sub_94040880(a1 + 2728, v67, v19);
      sub_9403A774(v17, 1);
      sub_9403A774(v20, 2);
      sub_9403A6C0(a1 + 516, a1 + 516);
      *(_DWORD *)(a1 + 516) = sub_9403A7CC(0, 17, v17, 1);
      *(_DWORD *)(a1 + 520) = sub_9403A7CC(0, 18, v17, 1);
      *(_DWORD *)(a1 + 524) = sub_9403A7CC(0, 19, v17, 1);
      *(_DWORD *)(a1 + 528) = sub_9403A7CC(0, 20, v17, 1);
      *(_DWORD *)(a1 + 532) = sub_9403A7CC(0, 21, v17, 1);
      v52 = sub_940408C8(a1 + 8);
      *(_DWORD *)(a1 + 536) = sub_9403A7F0(v52, 17, v20, 2);
      v53 = sub_940408C8(a1 + 88);
      *(_DWORD *)(a1 + 540) = sub_9403A7F0(v53, 18, v20, 2);
      v54 = sub_940408C8(a1 + 168);
      *(_DWORD *)(a1 + 544) = sub_9403A7F0(v54, 19, v20, 2);
      v55 = sub_940408C8(a1 + 248);
      *(_DWORD *)(a1 + 548) = sub_9403A7F0(v55, 20, v20, 2);
      v56 = sub_940408C8(a1 + 328);
      *(_DWORD *)(a1 + 552) = sub_9403A7F0(v56, 21, v20, 2);
      v57 = sub_940408C8(a1 + 408);
      *(_DWORD *)(a1 + 556) = sub_9403A7F0(v57, 22, v17, 1);
      *(_DWORD *)(a1 + 560) = sub_9403A7CC(0, 13, v17, 1);
      *(_DWORD *)(a1 + 564) = sub_9403A7CC(0, 14, v17, 1);
      v58 = sub_940408C8(a1 + 2564);
      *(_DWORD *)(a1 + 568) = sub_9403A7F0(v58, 13, v20, 2);
      v59 = sub_940408C8(a1 + 2644);
      *(_DWORD *)(a1 + 572) = sub_9403A7F0(v59, 14, v20, 2);
      v60 = sub_940408C8(a1 + 2812);
      *(_DWORD *)(a1 + 576) = sub_9403A7F0(v60, 11, v17, 1);
      v61 = sub_940408C8(a1 + 2892);
      *(_DWORD *)(a1 + 580) = sub_9403A7F0(v61, 12, v17, 1);
      *(_DWORD *)(a1 + 584) = sub_9403A7CC(0, 10, v17, 1);
      v62 = sub_940408C8(a1 + 2728);
      *(_DWORD *)(a1 + 588) = sub_9403A7F0(v62, 10, v17, 1);
      *(_DWORD *)(a1 + 592) = sub_9403A638(15, 1, 1, 0, 10, 0, 22, 0);
      *(_DWORD *)(a1 + 596) = sub_9403A638(28, 1, 0, 0, 22, 0, 0, 0);
      *(_DWORD *)(a1 + 600) = sub_9403A638(10, 1, 2, 0, 12, 0, 0, 0);
      *(_DWORD *)(a1 + 604) = sub_9403A638(6, 1, 3, 0, 1, 0, 2, 0);
      *(_DWORD *)(a1 + 608) = sub_9403A638(6, 1, 4, 0, 11, 0, 2, 0);
      *(_DWORD *)(a1 + 612) = sub_9403A638(28, 1, 0, 0, 17, 0, 0, 0);
      *(_DWORD *)(a1 + 616) = sub_9403A638(29, 1, 5, 0, 18, 0, 3, 2);
      *(_DWORD *)(a1 + 620) = sub_9403A638(2, 1, 6, 0, 20, 0, 21, 0);
      *(_DWORD *)(a1 + 624) = sub_9403A638(29, 1, 1, 0, 18, 0, 4, 2);
      *(_DWORD *)(a1 + 628) = sub_9403A638(2, 1, 2, 0, 13, 0, 14, 0);
      *(_DWORD *)(a1 + 632) = sub_9403A638(26, 0, 4, 0, 5, 0, 6, 0);
      *(_DWORD *)(a1 + 636) = sub_9403A638(3, 1, 3, 0, 1, 0, 2, 0);
      v63 = sub_940408C8(v66);
      *(_DWORD *)(a1 + 640) = sub_9403A808(4, v63, v17, 1);
      *(_DWORD *)(a1 + 644) = -1;
      sub_9403A820(a1 + 516, 132);
      sub_940408B8(a1 + 8, 508);
      sub_940408B8(a1 + 516, 2048);
      sub_940408B8(a1 + 2564, 164);
      sub_940408B8(a1 + 2728, v19);
      sub_940408B8(a1 + 2812, 164);
      sub_940408C0(v66, v17);
      result = 0;
      break;
    case 3:
      v36 = 4 * *(_DWORD *)(a1 + 504);
      v37 = 4 * *(_DWORD *)(a1 + 500);
      sub_9403A774(v36, 1);
      sub_9403A774(v37, 2);
      sub_9403A6C0(a1 + 516, a1 + 516);
      *(_DWORD *)(a1 + 516) = sub_9403A7CC(0, 17, v36, 1);
      *(_DWORD *)(a1 + 520) = sub_9403A7CC(0, 18, v36, 1);
      *(_DWORD *)(a1 + 524) = sub_9403A7CC(0, 19, v36, 1);
      *(_DWORD *)(a1 + 528) = sub_9403A7CC(0, 20, v36, 1);
      *(_DWORD *)(a1 + 532) = sub_9403A7CC(0, 21, v36, 1);
      v38 = sub_940408C8(a1 + 8);
      *(_DWORD *)(a1 + 536) = sub_9403A7F0(v38, 17, v37, 2);
      v39 = sub_940408C8(a1 + 88);
      *(_DWORD *)(a1 + 540) = sub_9403A7F0(v39, 18, v37, 2);
      v40 = sub_940408C8(a1 + 168);
      *(_DWORD *)(a1 + 544) = sub_9403A7F0(v40, 19, v37, 2);
      v41 = sub_940408C8(a1 + 248);
      *(_DWORD *)(a1 + 548) = sub_9403A7F0(v41, 20, v37, 2);
      v42 = sub_940408C8(a1 + 328);
      *(_DWORD *)(a1 + 552) = sub_9403A7F0(v42, 21, v37, 2);
      v43 = sub_940408C8(a1 + 408);
      *(_DWORD *)(a1 + 556) = sub_9403A7F0(v43, 22, v36, 1);
      *(_DWORD *)(a1 + 560) = sub_9403A7CC(0, 4, v36, 1);
      v44 = sub_940408C8(a1 + 2564);
      *(_DWORD *)(a1 + 564) = sub_9403A7F0(v44, 4, v36, 1);
      *(_DWORD *)(a1 + 568) = sub_9403A7CC(0, 13, v36, 1);
      v45 = sub_940408C8(a1 + 2648);
      *(_DWORD *)(a1 + 572) = sub_9403A7F0(v45, 13, v37, 2);
      *(_DWORD *)(a1 + 576) = sub_9403A7CC(0, 14, v36, 1);
      v46 = sub_940408C8(a1 + 2728);
      *(_DWORD *)(a1 + 580) = sub_9403A7F0(v46, 14, v37, 2);
      *(_DWORD *)(a1 + 584) = sub_9403A638(28, 1, 0, 0, 17, 0, 0, 0);
      *(_DWORD *)(a1 + 588) = sub_9403A638(29, 1, 1, 0, 18, 0, 4, 2);
      *(_DWORD *)(a1 + 592) = sub_9403A638(2, 1, 2, 0, 13, 0, 14, 0);
      v47 = sub_940408C8(a1 + 2812);
      *(_DWORD *)(a1 + 596) = sub_9403A808(1, v47, v37, 2);
      *(_DWORD *)(a1 + 600) = -1;
      sub_9403A820(a1 + 516, 88);
      sub_940408B8(a1 + 8, 508);
      sub_940408B8(a1 + 516, 2048);
      sub_940408B8(a1 + 2648, 164);
      sub_940408B8(a1 + 2564, 84);
      sub_940408C0(a1 + 2812, 128);
      result = 0;
      break;
    default:
LABEL_5:
      result = 0;
      break;
  }
  return result;
}

/* ===== sub_9403A604 @ 0x9403A604 size 52 ===== */
_BYTE *__fastcall sub_9403A604(_BYTE *result, __int64 a2, unsigned int a3)
{
  __int64 v3; // x4
  char *v4; // x1
  _BYTE *v5; // x2
  _BYTE *v6; // x4
  char v7; // t1

  v3 = a3 - 1;
  v4 = (char *)(a2 + a3 - 1LL);
  if ( a3 != 0 )
  {
    v5 = result;
    v6 = &result[v3 + 1];
    do
    {
      v7 = *v4--;
      *v5++ = v7;
    }
    while ( v5 != v6 );
  }
  return result;
}

/* ===== sub_9403A638 @ 0x9403A638 size 136 ===== */
__int64 __fastcall sub_9403A638(
        unsigned __int8 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        unsigned __int8 a6,
        unsigned __int8 a7,
        unsigned __int8 a8)
{
  int v8; // w8
  bool v9; // zf
  __int64 result; // x0

  v8 = a1;
  v9 = (a1 & 0xE0) == 0;
  result = 0xFFFFFFFFLL;
  if ( v9
    && (a2 & 0xF0) == 0
    && (a3 & 0xE0) == 0
    && (a4 & 0xFE) == 0
    && (a5 & 0xE0) == 0
    && (a6 & 0xFE) == 0
    && (a7 & 0xE0) == 0
    && (a8 & 0xC0) == 0 )
  {
    return a8 | (a7 << 6) | (a6 << 11) | (a5 << 12) | (a4 << 17) | (a3 << 18) | (a2 << 23) | (unsigned int)(v8 << 27);
  }
  return result;
}

/* ===== sub_9403A6C0 @ 0x9403A6C0 size 116 ===== */
__int64 __fastcall sub_9403A6C0(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x20
  int v5; // [xsp+4Ch] [xbp+4Ch] BYREF

  v5 = ((unsigned __int64)sub_940408C8(a1) >> 17) & 0x7FFFF;
  v2 = ((unsigned __int64)sub_940408C8(a2) >> 17) & 0x7FFFF;
  sub_940356B4(0x610u, 1u, (__int64)&v5);
  v5 = v2;
  sub_940356B4(0x60Cu, 1u, (__int64)&v5);
  return 0;
}

/* ===== sub_9403A734 @ 0x9403A734 size 64 ===== */
__int64 __fastcall sub_9403A734(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3, int a4)
{
  int v4; // w4
  bool v5; // zf
  __int64 result; // x0

  v4 = a1;
  v5 = (a1 & 0xE0) == 0;
  result = 0xFFFFFFFFLL;
  if ( v5 && (a2 & 0xF0) == 0 && (a3 & 0xE0) == 0 )
    return a4 & 0x1FFFF | (a3 << 18) | (a2 << 23) | (unsigned int)(v4 << 27);
  return result;
}

/* ===== sub_9403A774 @ 0x9403A774 size 88 ===== */
__int64 __fastcall sub_9403A774(int a1, unsigned int a2)
{
  __int64 result; // x0
  int v4; // [xsp+1Ch] [xbp+1Ch] BYREF

  result = 258;
  if ( a2 <= 3 && (a1 & 0xFFFFFC00) == 0 )
  {
    v4 = a1 << (16 * (a2 & 1));
    sub_940356B4(4 * ((a2 >> 1) + 52), 1u, (__int64)&v4);
    return 0;
  }
  return result;
}

/* ===== sub_9403A7CC @ 0x9403A7CC size 36 ===== */
__int64 __fastcall sub_9403A7CC(unsigned __int8 a1, unsigned __int8 a2, __int64 a3, unsigned __int8 a4)
{
  return sub_9403A638(0x1Cu, a4, a2, 0, a1, 0, 0, 3u);
}

/* ===== sub_9403A7F0 @ 0x9403A7F0 size 24 ===== */
__int64 __fastcall sub_9403A7F0(int a1, unsigned __int8 a2, __int64 a3, unsigned __int8 a4)
{
  return sub_9403A734(0x16u, a4, a2, a1);
}

/* ===== sub_9403A808 @ 0x9403A808 size 24 ===== */
__int64 __fastcall sub_9403A808(unsigned __int8 a1, int a2, __int64 a3, unsigned __int8 a4)
{
  return sub_9403A734(0x17u, a4, a1, a2);
}

/* ===== sub_9403A820 @ 0x9403A820 size 8 ===== */
__int64 sub_9403A820()
{
  return 0;
}

/* ===== sub_9403A828 @ 0x9403A828 size 584 ===== */
__int64 __fastcall sub_9403A828(__int64 a1, unsigned int a2, int a3, __int64 a4, _BYTE *a5, _DWORD *a6)
{
  __int64 v7; // x0
  const void *v12; // x0
  __int64 v14; // x0
  const void *v15; // x0
  const void *v16; // x0
  int v17; // w25
  unsigned int v18; // w20
  unsigned int v19; // w19
  __int64 v20; // x0
  unsigned int v21; // w23
  __int64 v22; // x0
  __int64 i; // x4
  int v24; // w1
  const void *v25; // x0
  __int64 v26; // [xsp+68h] [xbp+68h]
  int v27; // [xsp+68h] [xbp+68h]
  int v28; // [xsp+68h] [xbp+68h]
  _BYTE v29[512]; // [xsp+70h] [xbp+70h] BYREF

  v7 = (unsigned int)(a3 - 1);
  if ( (unsigned int)v7 <= 1 )
  {
    v14 = a2 + 11;
    if ( (unsigned int)v14 > (unsigned int)a4 )
    {
      v16 = (const void *)sub_94040A98(v14);
      sub_940407DC(3, "%p: %s: %s: msglen(%d) is too big\n", v16, "SPRD_CE", "sprd_pkcs1_v1_5_encode", a2);
      return 4294901767LL;
    }
    else if ( a5 != nullptr && a6 != nullptr && (v14 = (unsigned int)*a6, (unsigned int)a4 <= (unsigned int)v14) )
    {
      *a5 = 0;
      a5[1] = a3;
      v17 = a4 - a2;
      v18 = a4 - a2 - 3;
      if ( a3 == 2 )
      {
        v19 = 0;
        while ( 1 )
        {
          v26 = a4;
          v20 = sub_9403BFB0(v29, 512);
          v21 = v20;
          if ( (_DWORD)v20 != 0 )
            break;
          a4 = v26;
          v22 = 0;
LABEL_14:
          for ( i = v19 + 2; (unsigned int)v22 <= 0x1FF; i = ++v19 + 2 )
          {
            if ( v19 >= v18 )
              break;
            v24 = (unsigned __int8)v29[v22++];
            if ( v24 == 0 )
              goto LABEL_14;
            a5[i] = v24;
          }
          if ( v18 <= v19 )
            goto LABEL_19;
        }
        v25 = (const void *)sub_94040A98(v20);
        sub_940407DC(3, "%p: %s: %s: get rng failed\n", v25, "SPRD_CE", "sprd_pkcs1_v1_5_encode");
        return v21;
      }
      else
      {
        v28 = a4;
        sub_94040888(a5 + 2, 0xFFFFFFFFLL, v18);
        LODWORD(a4) = v28;
LABEL_19:
        v27 = a4;
        a5[v17 - 1] = 0;
        sub_94040880(&a5[v17], a1, a2);
        *a6 = v27;
        return 0;
      }
    }
    else
    {
      v15 = (const void *)sub_94040A98(v14);
      sub_940407DC(
        3,
        "%p: %s: %s: out(%p) or outlen(%p) is less than required\n",
        v15,
        "SPRD_CE",
        "sprd_pkcs1_v1_5_encode",
        a5,
        a6);
      return 4294901767LL;
    }
  }
  else
  {
    v12 = (const void *)sub_94040A98(v7);
    sub_940407DC(3, "%p: %s: %s: invalid block type in padding(0x%x)\n", v12, "SPRD_CE", "sprd_pkcs1_v1_5_encode", a3);
    return 4294901765LL;
  }
}

/* ===== sub_9403AA70 @ 0x9403AA70 size 796 ===== */
__int64 __fastcall sub_9403AA70(
        unsigned __int8 *a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        const void *a5,
        _DWORD *a6,
        _DWORD *a7)
{
  unsigned int v9; // w21
  __int64 v12; // x0
  __int64 v13; // x2
  const void *v15; // x0
  const void *v16; // x0
  const void *v17; // x0
  unsigned __int64 v18; // x0
  int v19; // w1
  unsigned int v20; // w5
  unsigned int v21; // w21
  __int64 v22; // x2
  const void *v23; // x0
  const void *v24; // x0
  int v25; // w1
  unsigned __int8 *v26; // x24
  const void *v27; // x0
  __int64 v28; // x0
  const void *v29; // x0

  v9 = a3;
  if ( a1 == nullptr || a2 == 0 )
  {
    v15 = (const void *)sub_94040A98(a1);
    sub_940407DC(3, "%p: %s: %s: msg is %p or msglen is %d\n", v15, "SPRD_CE", "sprd_pkcs1_v1_5_decode", a1, a2);
    return 4294901767LL;
  }
  if ( a7 == nullptr )
  {
    v17 = (const void *)sub_94040A98(a1);
    sub_940407DC(3, "%p: %s: %s: is_valid is NULL\n", v17, "SPRD_CE", "sprd_pkcs1_v1_5_decode");
    return 4294901767LL;
  }
  *a7 = 0;
  if ( a2 > a4 || a4 <= 0xA )
  {
    v16 = (const void *)sub_94040A98(a1);
    sub_940407DC(3, "%p: %s: %s: msglen(%d) is too big or too small\n", v16, "SPRD_CE", "sprd_pkcs1_v1_5_decode", a2);
    return 4294901768LL;
  }
  v12 = *a1;
  if ( (_DWORD)v12 != 0 || (_DWORD)(v12 = a1[1]) != (unsigned __int8)a3 )
  {
    v13 = sub_94040A98(v12);
    sub_940407DC(
      3,
      "%p: %s: %s: bad msg[0](0x%x) or msg[1](0x%x)\n",
      v13,
      "SPRD_CE",
      "sprd_pkcs1_v1_5_decode",
      *a1,
      a1[1]);
    return 4294901768LL;
  }
  if ( a3 == 1 )
  {
    v18 = (unsigned __int64)(a1 + 2);
    v9 = 2;
    while ( 1 )
    {
      v25 = *(unsigned __int8 *)v18;
      v26 = (unsigned __int8 *)v18++;
      if ( v25 != 255 )
        break;
      if ( a4 <= ++v9 )
      {
        v18 = v9;
        v26 = &a1[v9];
        v25 = *v26;
        break;
      }
    }
    if ( v25 != 0 )
    {
      v27 = (const void *)sub_94040A98(v18);
      sub_940407DC(
        3,
        "%p: %s: %s: There was no 0x00 to separate ps from msg. msg[%d] = 0x%x\n",
        v27,
        "SPRD_CE",
        "sprd_pkcs1_v1_5_decode",
        v9,
        *v26);
      return 4294901768LL;
    }
  }
  else
  {
    if ( a3 != 2 )
    {
      v24 = (const void *)sub_94040A98(v12);
      sub_940407DC(3, "%p: %s: %s: invalid block type in padding(0x%x)\n", v24, "SPRD_CE", "sprd_pkcs1_v1_5_decode", v9);
      return 4294901765LL;
    }
    v18 = (unsigned __int64)(a1 + 2);
    do
    {
      v19 = *(unsigned __int8 *)v18++;
      if ( v19 == 0 )
        break;
      ++v9;
    }
    while ( a4 > v9 );
  }
  v20 = v9 + 1;
  if ( a4 <= v9 + 1 )
  {
    v28 = sub_94040A98(v18);
    sub_940407DC(
      3,
      "%p: %s: %s: There was no 0x00 to separate ps from msg. msg[%d] = 0x%x\n",
      v28,
      "SPRD_CE",
      "sprd_pkcs1_v1_5_decode",
      v9 + 1,
      a1[v9 + 1]);
    return 4294901768LL;
  }
  v21 = v9 - 2;
  if ( v21 <= 7 )
  {
    v29 = (const void *)sub_94040A98(v18);
    sub_940407DC(3, "%p: %s: %s: the length of ps(%d) is less than 8\n", v29, "SPRD_CE", "sprd_pkcs1_v1_5_decode", v21);
    return 4294901768LL;
  }
  else if ( a5 != nullptr
         && a6 != nullptr
         && (v18 = (unsigned int)*a6, v22 = a2 - 3 - v21, (unsigned int)v18 >= (unsigned int)v22) )
  {
    *a6 = v22;
    sub_94040880(a5, &a1[v20], v22);
    *a7 = 1;
    return 0;
  }
  else
  {
    v23 = (const void *)sub_94040A98(v18);
    sub_940407DC(
      3,
      "%p: %s: %s: out(%p) or outlen(%p) is less than required\n",
      v23,
      "SPRD_CE",
      "sprd_pkcs1_v1_5_decode",
      a5,
      a6);
    return 4294901767LL;
  }
}

/* ===== sub_9403AD8C @ 0x9403AD8C size 88 ===== */
__int64 __fastcall sub_9403AD8C(unsigned __int8 *a1, int a2, unsigned __int8 *a3)
{
  unsigned int v3; // w4
  unsigned int v4; // w3
  unsigned __int8 *v5; // x2
  unsigned __int8 *v6; // x1
  unsigned int v7; // t1
  unsigned int v8; // t1

  if ( a2 <= 0 )
    return 0;
  v3 = *a1;
  v4 = *a3;
  if ( v3 == v4 )
  {
    v5 = a3 + 1;
    v6 = &a1[a2 - 1];
    while ( a1 != v6 )
    {
      v7 = *++a1;
      v3 = v7;
      v8 = *v5++;
      v4 = v8;
      if ( v3 != v8 )
        goto LABEL_7;
    }
    return 0;
  }
LABEL_7:
  if ( v3 <= v4 )
    return 0xFFFFFFFFLL;
  else
    return 1;
}

/* ===== sub_9403ADE4 @ 0x9403ADE4 size 884 ===== */
__int64 __fastcall sub_9403ADE4(
        int a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6,
        unsigned int a7,
        __int64 a8,
        unsigned int *a9)
{
  __int64 v16; // x0
  int v17; // w0
  __int64 v18; // x0
  __int64 v19; // x22
  const void *v20; // x0
  unsigned int v21; // w21
  const void *v23; // x0
  __int64 v24; // x0
  const void *v25; // x0
  const void *v26; // x0
  unsigned int v28; // [xsp+74h] [xbp+74h] BYREF
  __int64 v29; // [xsp+78h] [xbp+78h] BYREF
  _QWORD v30[44]; // [xsp+80h] [xbp+80h] BYREF

  v29 = 0;
  v16 = sub_94040888(v30, 0, 352);
  if ( a3 == 256 )
  {
    if ( a1 == 1 )
      v17 = 83951618;
    else
      v17 = 83951623;
    goto LABEL_11;
  }
  if ( a3 > 0x100 )
  {
    if ( a3 == 384 )
    {
      if ( a1 == 1 )
        v17 = 83951619;
      else
        v17 = 83951624;
    }
    else
    {
      if ( a3 != 512 )
        goto LABEL_21;
      if ( a1 == 1 )
        v17 = 83951620;
      else
        v17 = 83951625;
    }
LABEL_11:
    LODWORD(v30[0]) = v17;
    goto LABEL_12;
  }
  if ( a3 == 32 )
  {
    if ( a1 == 1 )
      v17 = 83951616;
    else
      v17 = 83951621;
    goto LABEL_11;
  }
  if ( a3 != 128 )
  {
LABEL_21:
    v23 = (const void *)sub_94040A98(v16);
    sub_940407DC(3, "%p: %s: %s: bad key len!\n", v23, "SPRD_CE", "sprd_rsa_nopad");
    return 4294901769LL;
  }
  if ( a1 == 1 )
    LODWORD(v30[0]) = 83951617;
  else
    LODWORD(v30[0]) = 83951622;
LABEL_12:
  v18 = sub_94037378(v30);
  if ( (_DWORD)v18 != 0 )
  {
    v26 = (const void *)sub_94040A98(v18);
    sub_940407DC(3, "%p: %s: %s: FAILED!\n", v26, "SPRD_CE", "sprd_rsa_nopad");
    return 4294901760LL;
  }
  else
  {
    v19 = sub_940409F8(v18);
    if ( v19 != 0 )
    {
      sub_94036FEC((__int64)v30, 0x1000u, &v29, (int *)&v28);
      if ( v29 != 0 && v28 > 0xFFF )
      {
        sub_94040880(v29, a2, a3);
        sub_94040888(v29 + 512, 0, a3);
        sub_94040880(v29 + 512LL - a5 + a3, a4, a5);
        sub_94040880(v29 + 1024, a6, a7);
        LODWORD(v30[4]) = a3;
        v30[2] = v29;
        v30[3] = v29 + 512;
        LODWORD(v30[1]) = 1;
        v30[37] = v29 + 1024;
        v30[39] = v29 + 1536;
        v30[5] = v29 + 4096;
        HIDWORD(v30[0]) = 0;
        LODWORD(v30[38]) = a7;
        LODWORD(v30[40]) = a7;
        v30[43] = v19;
        sub_940408B0(v29, 0x2000);
        v24 = sub_94036D90((int *)v30);
        v21 = v24;
        if ( (_DWORD)v24 != 0 )
        {
          v25 = (const void *)sub_94040A98(v24);
          sub_940407DC(3, "%p: %s: %s: sprd_crypto_process return 0x%x\n", v25, "SPRD_CE", "sprd_rsa_nopad", v21);
        }
        else
        {
          sub_94040A74(v19);
          if ( a9 != nullptr )
            *a9 = a7;
          sub_940408C0(v29 + 1536, 512);
          sub_94040880(a8, v29 + 1536, a7);
        }
      }
      else
      {
        v20 = (const void *)sub_94040A98(v29);
        v21 = -65526;
        sub_940407DC(3, "%p: %s: %s: buf_len is %d, too small!\n", v20, "SPRD_CE", "sprd_rsa_nopad", v28);
      }
      if ( v29 != 0 )
        sub_9403719C(v29);
      sub_94040A34(v19);
      sub_94037418((int *)v30);
      return v21;
    }
    else
    {
      return 4294901770LL;
    }
  }
}

/* ===== sub_9403B158 @ 0x9403B158 size 452 ===== */
__int64 __fastcall sub_9403B158(__int64 a1, unsigned __int8 *a2, int a3, __int64 a4, unsigned int *a5, int *a6)
{
  unsigned int v6; // w6
  __int64 v7; // x7
  int v8; // w5
  unsigned int v12; // w20
  unsigned __int8 *v13; // x22
  __int64 v14; // x0
  const void *v16; // x0
  const void *v17; // x0
  const void *v18; // x0
  const void *v19; // x0
  const void *v20; // x0
  int v24; // [xsp+58h] [xbp+48h]

  v6 = a3;
  v7 = a4;
  v8 = *a6;
  if ( a1 != 0 )
  {
    if ( a2 != nullptr && a3 != 0 )
    {
      if ( a4 != 0 )
      {
        if ( v8 != 0 )
        {
          v24 = v8;
          v18 = (const void *)sub_94040A98(a1);
          sub_940407DC(3, "%p: %s: %s: Bad padding type(%d)!\n", v18, "SPRD_CE", "sprd_rsa_public_encrypt", v24);
          return 4294901765LL;
        }
        else
        {
          v12 = *(_DWORD *)(a1 + 16);
          v13 = *(unsigned __int8 **)a1;
          v14 = a3 - v12;
          if ( a3 == v12 )
          {
            v14 = sub_9403AD8C(a2, a3, v13);
            v7 = a4;
            v6 = a3;
          }
          if ( (v14 & 0x80000000) != 0 )
          {
            return sub_9403ADE4(
                     1,
                     (__int64)v13,
                     v12,
                     *(_QWORD *)(a1 + 8),
                     *(_DWORD *)(a1 + 20),
                     (__int64)a2,
                     v6,
                     v7,
                     a5);
          }
          else
          {
            v16 = (const void *)sub_94040A98(v14);
            sub_940407DC(3, "%p: %s: %s: Bad data too lager for modulus!\n", v16, "SPRD_CE", "sprd_rsa_public_encrypt");
            return 4294901772LL;
          }
        }
      }
      else
      {
        v20 = (const void *)sub_94040A98(a1);
        sub_940407DC(3, "%p: %s: %s: Bad dst(%p)\n", v20, "SPRD_CE", "sprd_rsa_public_encrypt", nullptr);
        return 4294901767LL;
      }
    }
    else
    {
      v17 = (const void *)sub_94040A98(a1);
      sub_940407DC(3, "%p: %s: %s: Bad src(%p) or src_size(%d)\n", v17, "SPRD_CE", "sprd_rsa_public_encrypt", a2, a3);
      return 4294901767LL;
    }
  }
  else
  {
    v19 = (const void *)sub_94040A98(0);
    sub_940407DC(3, "%p: %s: %s: Bad pub key(%p)!\n", v19, "SPRD_CE", "sprd_rsa_public_encrypt", nullptr);
    return 4294901762LL;
  }
}

/* ===== sub_9403B31C @ 0x9403B31C size 452 ===== */
__int64 __fastcall sub_9403B31C(__int64 a1, unsigned __int8 *a2, int a3, __int64 a4, unsigned int *a5, int *a6)
{
  unsigned int v6; // w6
  __int64 v7; // x7
  int v8; // w5
  unsigned int v12; // w20
  unsigned __int8 *v13; // x22
  __int64 v14; // x0
  const void *v16; // x0
  const void *v17; // x0
  const void *v18; // x0
  const void *v19; // x0
  const void *v20; // x0
  int v24; // [xsp+58h] [xbp+48h]

  v6 = a3;
  v7 = a4;
  v8 = *a6;
  if ( a1 != 0 )
  {
    if ( a2 != nullptr && a3 != 0 )
    {
      if ( a4 != 0 )
      {
        if ( v8 != 0 )
        {
          v24 = v8;
          v18 = (const void *)sub_94040A98(a1);
          sub_940407DC(3, "%p: %s: %s: Bad padding type(%d)!\n", v18, "SPRD_CE", "sprd_rsa_private_decrypt", v24);
          return 4294901765LL;
        }
        else
        {
          v12 = *(_DWORD *)(a1 + 24);
          v13 = *(unsigned __int8 **)a1;
          v14 = a3 - v12;
          if ( a3 == v12 )
          {
            v14 = sub_9403AD8C(a2, a3, v13);
            v7 = a4;
            v6 = a3;
          }
          if ( (v14 & 0x80000000) != 0 )
          {
            return sub_9403ADE4(
                     0,
                     (__int64)v13,
                     v12,
                     *(_QWORD *)(a1 + 16),
                     *(_DWORD *)(a1 + 32),
                     (__int64)a2,
                     v6,
                     v7,
                     a5);
          }
          else
          {
            v16 = (const void *)sub_94040A98(v14);
            sub_940407DC(3, "%p: %s: %s: Bad data too lager for modulus!\n", v16, "SPRD_CE", "sprd_rsa_private_decrypt");
            return 4294901772LL;
          }
        }
      }
      else
      {
        v20 = (const void *)sub_94040A98(a1);
        sub_940407DC(3, "%p: %s: %s: Bad dst(%p)\n", v20, "SPRD_CE", "sprd_rsa_private_decrypt", nullptr);
        return 4294901767LL;
      }
    }
    else
    {
      v17 = (const void *)sub_94040A98(a1);
      sub_940407DC(3, "%p: %s: %s: Bad src(%p) or src_size(%d)\n", v17, "SPRD_CE", "sprd_rsa_private_decrypt", a2, a3);
      return 4294901767LL;
    }
  }
  else
  {
    v19 = (const void *)sub_94040A98(0);
    sub_940407DC(3, "%p: %s: %s: Bad priv key(%p)!\n", v19, "SPRD_CE", "sprd_rsa_private_decrypt", nullptr);
    return 4294901762LL;
  }
}

/* ===== sub_9403B4E0 @ 0x9403B4E0 size 756 ===== */
__int64 __fastcall sub_9403B4E0(__int64 a1, unsigned int a2, int a3, __int64 a4, __int64 a5)
{
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x23
  const void *v13; // x0
  unsigned int v14; // w21
  const void *v16; // x0
  __int64 v17; // x0
  const void *v18; // x0
  const void *v19; // x0
  unsigned int v20; // [xsp+64h] [xbp+64h] BYREF
  __int64 v21; // [xsp+68h] [xbp+68h] BYREF
  _QWORD v22[44]; // [xsp+70h] [xbp+70h] BYREF

  v10 = sub_94040888(v22, 0, 352);
  if ( a3 == 256 )
  {
    LODWORD(v22[4]) = 256;
    LODWORD(v22[0]) = 84017154;
  }
  else if ( a3 > 256 )
  {
    if ( a3 == 384 )
    {
      LODWORD(v22[4]) = 384;
      LODWORD(v22[0]) = 84017155;
    }
    else
    {
      if ( a3 != 512 )
        goto LABEL_17;
      LODWORD(v22[4]) = 512;
      LODWORD(v22[0]) = 84017156;
    }
  }
  else
  {
    if ( a3 != 32 )
    {
      if ( a3 == 128 )
      {
        LODWORD(v22[4]) = 128;
        LODWORD(v22[0]) = 84017153;
        goto LABEL_6;
      }
LABEL_17:
      v16 = (const void *)sub_94040A98(v10);
      sub_940407DC(3, "%p: %s: %s: bad key len!\n", v16, "SPRD_CE", "sprd_rsa_key_gen");
      return 4294901769LL;
    }
    LODWORD(v22[4]) = 32;
    LODWORD(v22[0]) = 84017152;
  }
LABEL_6:
  v11 = sub_94037378(v22);
  if ( (_DWORD)v11 != 0 )
  {
    v19 = (const void *)sub_94040A98(v11);
    sub_940407DC(3, "%p: %s: %s: FAILED!\n", v19, "SPRD_CE", "sprd_rsa_key_gen");
    return 4294901760LL;
  }
  else
  {
    v12 = sub_940409F8(v11);
    if ( v12 != 0 )
    {
      sub_94036FEC((__int64)v22, 0x1000u, &v21, (int *)&v20);
      if ( v21 != 0 && v20 > 0xFFF )
      {
        sub_94040888(v21 + 1024, 0, (unsigned int)a3);
        sub_94040880(v21 + 1024, a1, a2);
        HIDWORD(v22[0]) = 0;
        LODWORD(v22[38]) = a2;
        v22[37] = v21 + 1024;
        LODWORD(v22[1]) = 1;
        v22[39] = v21 + 1536;
        LODWORD(v22[40]) = 2 * a3;
        v22[5] = v21 + 4096;
        v22[43] = v12;
        sub_940408B0(v21, 0x2000);
        v17 = sub_94036D90((int *)v22);
        v14 = v17;
        if ( (_DWORD)v17 != 0 )
        {
          v18 = (const void *)sub_94040A98(v17);
          sub_940407DC(3, "%p: %s: %s: sprd_crypto_process return 0x%x\n", v18, "SPRD_CE", "sprd_rsa_key_gen", v14);
        }
        else
        {
          sub_94040A74(v12);
          sub_940408C0(v21 + 1536, 1024);
          sub_94040880(a4, v21 + 1536, (unsigned int)a3);
          sub_94040880(a5, v21 + a3 + 1536LL, (unsigned int)a3);
        }
      }
      else
      {
        v13 = (const void *)sub_94040A98(v21);
        v14 = -65526;
        sub_940407DC(3, "%p: %s: %s: buf_len is %d, too small!\n", v13, "SPRD_CE", "sprd_rsa_key_gen", v20);
      }
      if ( v21 != 0 )
        sub_9403719C(v21);
      sub_94040A34(v12);
      sub_94037418((int *)v22);
      return v14;
    }
    else
    {
      return 4294901770LL;
    }
  }
}

/* ===== sub_9403B7D4 @ 0x9403B7D4 size 528 ===== */
__int64 __fastcall sub_9403B7D4(unsigned int a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x23
  __int64 v7; // x0
  const void *v8; // x0
  unsigned int v9; // w21
  __int64 v11; // x0
  const void *v12; // x0
  const void *v13; // x0
  const void *v14; // x0
  unsigned int v15; // [xsp+44h] [xbp+44h] BYREF
  __int64 v16; // [xsp+48h] [xbp+48h] BYREF
  _QWORD v17[44]; // [xsp+50h] [xbp+50h] BYREF

  sub_94040888(v17, 0, 352);
  v4 = 84213760;
  LODWORD(v17[0]) = 84213760;
  if ( a1 - 32 > 0xE9 || (v4 = a1 & 3, (a1 & 3) != 0) )
  {
    v13 = (const void *)sub_94040A98(v4);
    sub_940407DC(
      3,
      "%p: %s: %s: prime_len: range [32byte-265byte] and must be integral multiple of 4!\n",
      v13,
      "SPRD_CE",
      "sprd_rsa_prime_gen");
    return 4294901769LL;
  }
  else
  {
    LODWORD(v17[3]) = a1;
    v5 = sub_94037378(v17);
    if ( (_DWORD)v5 != 0 )
    {
      v14 = (const void *)sub_94040A98(v5);
      sub_940407DC(3, "%p: %s: %s: FAILED!\n", v14, "SPRD_CE", "sprd_rsa_prime_gen");
      return 4294901760LL;
    }
    else
    {
      v6 = sub_940409F8(v5);
      if ( v6 != 0 )
      {
        v7 = sub_94036FEC((__int64)v17, 0x1000u, &v16, (int *)&v15);
        if ( v16 != 0 && (v7 = v15, v15 > 0xFFF) )
        {
          LODWORD(v17[1]) = 1;
          v17[39] = v16;
          v17[4] = v16 + 1024;
          HIDWORD(v17[0]) = 0;
          v17[37] = 0;
          LODWORD(v17[38]) = a1;
          LODWORD(v17[40]) = a1;
          v17[43] = v6;
          sub_940408B0(v16, 4096);
          v11 = sub_94036D90((int *)v17);
          v9 = v11;
          if ( (_DWORD)v11 != 0 )
          {
            v12 = (const void *)sub_94040A98(v11);
            sub_940407DC(3, "%p: %s: %s: sprd_crypto_process return 0x%x\n", v12, "SPRD_CE", "sprd_rsa_prime_gen", v9);
          }
          else
          {
            sub_94040A74(v6);
            sub_940408C0(v16, 1024);
            sub_94040880(a2, v16, a1);
          }
        }
        else
        {
          v8 = (const void *)sub_94040A98(v7);
          v9 = -65526;
          sub_940407DC(3, "%p: %s: %s: buf_len is %d, too small!\n", v8, "SPRD_CE", "sprd_rsa_prime_gen", v15);
        }
        if ( v16 != 0 )
          sub_9403719C(v16);
        sub_94040A34(v6);
        sub_94037418((int *)v17);
        return v9;
      }
      else
      {
        return 4294901770LL;
      }
    }
  }
}

/* ===== sub_9403B9E4 @ 0x9403B9E4 size 568 ===== */
__int64 __fastcall sub_9403B9E4(__int64 a1, __int64 a2, unsigned int a3, const void *a4, unsigned int *a5, int *a6)
{
  __int64 v6; // x20
  unsigned __int8 *v7; // x23
  int v10; // w5
  unsigned int v11; // w8
  __int64 v12; // x0
  unsigned int v13; // w19
  unsigned int v14; // w6
  unsigned int v15; // w19
  __int64 v16; // x0
  unsigned __int8 *v17; // x24
  const void *v19; // x0
  const void *v20; // x0
  const void *v21; // x0
  const void *v22; // x0
  const void *v23; // x0
  unsigned int v24; // [xsp+68h] [xbp+58h]
  int v25; // [xsp+68h] [xbp+58h]
  unsigned int v26; // [xsp+7Ch] [xbp+6Ch] BYREF
  _BYTE v27[512]; // [xsp+80h] [xbp+70h] BYREF

  v6 = a1;
  v7 = (unsigned __int8 *)a2;
  v10 = *a6;
  if ( a1 == 0 )
  {
    v23 = (const void *)sub_94040A98(0);
    sub_940407DC(3, "%p: %s: %s: Bad priv key(%p)!\n", v23, "SPRD_CE", "sprd_rsa_sign", nullptr);
    return 4294901762LL;
  }
  if ( a4 == nullptr || a5 == nullptr || (v11 = *(_DWORD *)(a1 + 24), (unsigned int)(a1 = *a5) < v11) )
  {
    v22 = (const void *)sub_94040A98(a1);
    sub_940407DC(3, "%p: %s: %s: Bad sig(%p) or sig_size(%p)!\n", v22, "SPRD_CE", "sprd_rsa_sign", a4, a5);
    return 4294901767LL;
  }
  if ( v10 != 0 )
  {
    if ( v10 != 20 )
    {
      v25 = v10;
      v19 = (const void *)sub_94040A98(a1);
      sub_940407DC(3, "%p: %s: %s: Bad padding type(%d)!\n", v19, "SPRD_CE", "sprd_rsa_sign", v25);
      return 4294901765LL;
    }
    v26 = v11;
    v12 = sub_9403A828(a2, a3, 1, v11, v27, &v26);
    v13 = v12;
    if ( (_DWORD)v12 != 0 )
    {
      v20 = (const void *)sub_94040A98(v12);
      sub_940407DC(3, "%p: %s: %s: rsa padding encode failed(0x%x)!\n", v20, "SPRD_CE", "sprd_rsa_sign", v13);
      return v13;
    }
    v14 = v26;
    v7 = v27;
    v15 = *(_DWORD *)(v6 + 24);
  }
  else
  {
    v15 = v11;
    v14 = a3;
    v26 = a3;
  }
  v16 = v14 - v15;
  v17 = *(unsigned __int8 **)v6;
  if ( v14 == v15 )
  {
    v24 = v14;
    v16 = sub_9403AD8C(v7, v14, *(unsigned __int8 **)v6);
    v14 = v24;
  }
  if ( (v16 & 0x80000000) != 0 )
    return sub_9403ADE4(
             0,
             (__int64)v17,
             v15,
             *(_QWORD *)(v6 + 16),
             *(_DWORD *)(v6 + 32),
             (__int64)v7,
             v14,
             (__int64)a4,
             a5);
  v21 = (const void *)sub_94040A98(v16);
  sub_940407DC(3, "%p: %s: %s: Bad data too lager for modulus!\n", v21, "SPRD_CE", "sprd_rsa_sign");
  return 4294901772LL;
}

/* ===== sub_9403BC1C @ 0x9403BC1C size 916 ===== */
__int64 __fastcall sub_9403BC1C(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int8 *a4,
        unsigned int a5,
        int *a6,
        unsigned int *a7)
{
  int v12; // w26
  unsigned __int8 *v13; // x27
  unsigned int v14; // w21
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v17; // w20
  unsigned int v18; // w3
  __int64 v19; // x0
  unsigned int v20; // w20
  __int64 v21; // x0
  const void *v22; // x0
  const void *v24; // x0
  const void *v25; // x0
  const void *v26; // x0
  const void *v27; // x0
  const void *v28; // x0
  const void *v29; // x0
  __int64 v30; // x2
  __int64 v31; // x2
  unsigned int v33; // [xsp+84h] [xbp+74h] BYREF
  unsigned int v34; // [xsp+88h] [xbp+78h] BYREF
  unsigned int v35; // [xsp+8Ch] [xbp+7Ch] BYREF
  unsigned __int8 v36[512]; // [xsp+90h] [xbp+80h] BYREF
  _BYTE v37[512]; // [xsp+290h] [xbp+280h] BYREF

  v12 = *a6;
  if ( a1 == 0 )
  {
    v29 = (const void *)sub_94040A98(0);
    sub_940407DC(3, "%p: %s: %s: Bad pub key(%p)!\n", v29, "SPRD_CE", "sprd_rsa_verify", nullptr);
    return 4294901762LL;
  }
  if ( a2 == 0 )
  {
    v30 = sub_94040A98(a1);
    sub_940407DC(3, "%p: %s: %s: Bad dig(%p)!\n", v30, "SPRD_CE", "sprd_rsa_verify", 0);
    return 4294901767LL;
  }
  if ( a4 == nullptr || a5 == 0 )
  {
    v28 = (const void *)sub_94040A98(a1);
    sub_940407DC(3, "%p: %s: %s: Bad sig(%p) or sig_size(%d)!\n", v28, "SPRD_CE", "sprd_rsa_verify", a4, a5);
    return 4294901767LL;
  }
  if ( a7 == nullptr )
  {
    v31 = sub_94040A98(a1);
    sub_940407DC(3, "%p: %s: %s: Bad result(%p)!\n", v31, "SPRD_CE", "sprd_rsa_verify", 0);
    return 4294901767LL;
  }
  *a7 = -1;
  v13 = *(unsigned __int8 **)a1;
  v14 = *(_DWORD *)(a1 + 16);
  v15 = a5 - v14;
  if ( a5 == v14 )
    v15 = sub_9403AD8C(a4, a5, *(unsigned __int8 **)a1);
  if ( (v15 & 0x80000000) != 0 )
  {
    v16 = sub_9403ADE4(
            1,
            (__int64)v13,
            v14,
            *(_QWORD *)(a1 + 8),
            *(_DWORD *)(a1 + 20),
            (__int64)a4,
            a5,
            (__int64)v36,
            &v33);
    v17 = v16;
    if ( (_DWORD)v16 != 0 )
    {
      v26 = (const void *)sub_94040A98(v16);
      sub_940407DC(3, "%p: %s: %s: sprd_rsa_nopad failed(0x%x)!\n", v26, "SPRD_CE", "sprd_rsa_verify", v17);
      return v17;
    }
    else if ( v12 != 0 )
    {
      if ( v12 == 20 )
      {
        v18 = *(_DWORD *)(a1 + 16);
        v34 = 512;
        v19 = sub_9403AA70(v36, v33, 1u, v18, v37, &v34, &v35);
        v20 = v19;
        if ( (_DWORD)v19 != 0 || (v19 = v35, v35 == 0) )
        {
          v25 = (const void *)sub_94040A98(v19);
          sub_940407DC(
            3,
            "%p: %s: %s: rsa padding decode failed(0x%x), is_valid(%d)!\n",
            v25,
            "SPRD_CE",
            "sprd_rsa_verify",
            v20,
            v35);
          *a7 = -1;
          return v20;
        }
        else
        {
          if ( a3 != 0 )
          {
            v21 = v34;
            if ( v34 == a3 )
            {
              v21 = sub_94040870(v37, a2, a3);
              if ( (_DWORD)v21 == 0 )
                goto LABEL_20;
            }
            v22 = (const void *)sub_94040A98(v21);
            sub_940407DC(
              3,
              "%p: %s: %s: temp_len(%d) is not equal dig_size(%d) or memcmp is failed\n",
              v22,
              "SPRD_CE",
              "sprd_rsa_verify",
              v34,
              a3);
            goto LABEL_17;
          }
          sub_94040880(a2, v37, v34);
          *a7 = v34;
          return 0;
        }
      }
      else
      {
        v24 = (const void *)sub_94040A98(v16);
        sub_940407DC(3, "%p: %s: %s: Bad padding type(%d)!\n", v24, "SPRD_CE", "sprd_rsa_verify", v12);
        return 4294901765LL;
      }
    }
    else
    {
      if ( a3 != 0 )
      {
        if ( (unsigned int)sub_94040870(v36, a2, a3) == 0 )
        {
LABEL_20:
          *a7 = 0;
          return 0;
        }
LABEL_17:
        *a7 = -1;
        return 0;
      }
      sub_94040880(a2, v36, v33);
      *a7 = v33;
      return 0;
    }
  }
  else
  {
    v27 = (const void *)sub_94040A98(v15);
    sub_940407DC(3, "%p: %s: %s: Bad data too lager for modulus!\n", v27, "SPRD_CE", "sprd_rsa_verify");
    return 4294901772LL;
  }
}

/* ===== sub_9403BFB0 @ 0x9403BFB0 size 540 ===== */
__int64 __fastcall sub_9403BFB0(__int64 a1, int a2)
{
  __int64 v4; // x0
  unsigned int v5; // w24
  __int64 v6; // x23
  __int64 v7; // x0
  const void *v8; // x0
  unsigned int v10; // w20
  __int64 v11; // x22
  __int64 v12; // x0
  unsigned int v13; // w25
  unsigned int v14; // w1
  const void *v15; // x0
  const void *v16; // x0
  unsigned int v17; // [xsp+64h] [xbp+64h] BYREF
  char *v18; // [xsp+68h] [xbp+68h] BYREF
  _QWORD v19[44]; // [xsp+70h] [xbp+70h] BYREF

  v18 = nullptr;
  sub_94040888(v19, 0, 352);
  LODWORD(v19[0]) = 84148224;
  v4 = sub_94037378(v19);
  v5 = v4;
  if ( (_DWORD)v4 != 0 )
  {
    v16 = (const void *)sub_94040A98(v4);
    sub_940407DC(3, "%p: %s: %s: FAILED!\n", v16, "SPRD_CE", "sprd_rng_gen");
    return 4294901760LL;
  }
  else
  {
    v6 = sub_940409F8(v4);
    if ( v6 != 0 )
    {
      v7 = sub_94036FEC((__int64)v19, 0x40u, &v18, (int *)&v17);
      if ( v18 != nullptr && (v7 = v17, v17 > 0x1FF) )
      {
        v19[39] = v18;
        v10 = (unsigned int)(a2 + 511) >> 9;
        HIDWORD(v19[0]) = 0;
        v11 = a1;
        v19[37] = 0;
        LODWORD(v19[1]) = 1;
        LODWORD(v19[38]) = 0;
        LODWORD(v19[40]) = 512;
        v19[2] = v18 + 4096;
        v19[43] = v6;
        sub_940408B0(v18, 0x2000);
        if ( v10 != 0 )
        {
          while ( 1 )
          {
            v13 = 512;
            if ( v10 == 1 )
              v13 = a2 + a1 - v11;
            sub_940408B0(v18, 512);
            v14 = sub_94036D90((int *)v19);
            if ( v14 != 0 )
              break;
            sub_94040A74(v6);
            sub_940408C0(v18, 512);
            v12 = v11;
            v11 += v13;
            sub_94040880(v12, v18, v13);
            if ( --v10 == 0 )
              goto LABEL_6;
          }
          v5 = v14;
          v15 = (const void *)sub_94040A98(v6);
          sub_940407DC(3, "%p: %s: %s: sprd_crypto_work return 0x%x\n", v15, "SPRD_CE", "sprd_rng_gen", v5);
        }
      }
      else
      {
        v8 = (const void *)sub_94040A98(v7);
        v5 = -65526;
        sub_940407DC(3, "%p: %s: %s: buf = %p, buf_len is %d!\n", v8, "SPRD_CE", "sprd_rng_gen", v18, v17);
      }
LABEL_6:
      if ( v18 != nullptr )
        sub_9403719C((__int64)v18);
      sub_94040A34(v6);
      sub_94037418((int *)v19);
      return v5;
    }
    else
    {
      return 4294901770LL;
    }
  }
}

/* ===== sub_9403C1CC @ 0x9403C1CC size 436 ===== */
__int64 sub_9403C1CC()
{
  int v0; // w23
  int v1; // w0
  int v2; // w2
  int v3; // w2
  __int64 v4; // x19
  unsigned int v5; // w2
  unsigned int v6; // w3
  __int64 v7; // x1
  int v8; // w4
  unsigned __int64 v9; // x4
  int v10; // w5

  v0 = *(_DWORD *)(MEMORY[0xFFFFFFFFE0061EC0] + 20LL);
  if ( v0 == 0 )
    return 0;
  while ( 1 )
  {
    v1 = v0;
    v2 = 32;
    if ( (v0 & 0xFFFF0000) == 0 )
    {
      v1 = v0 << 16;
      v2 = 16;
    }
    if ( (v1 & 0xFF000000) == 0 )
    {
      v1 <<= 8;
      v2 -= 8;
    }
    if ( (v1 & 0xF0000000) == 0 )
    {
      v1 *= 16;
      v2 -= 4;
    }
    if ( (v1 & 0xC0000000) == 0 )
    {
      v1 *= 4;
      v2 -= 2;
    }
    v3 = v2 - (v1 >= 0);
    if ( v3 <= 28 )
      break;
    v0 &= v0 - 1;
    v5 = v3 - 29;
    v4 = v5;
    v6 = 16;
    v7 = *(_QWORD *)(80LL * v5 - 536469792);
    v8 = *(_DWORD *)(v7 + 12);
    if ( (v8 & 0x100000) != 0 || (v6 = 8, (v8 & 0x80000) != 0) )
    {
      v9 = ((unsigned __int64)*(unsigned int *)(v7 + 24) >> 24) & 3;
    }
    else
    {
      v6 = 4;
      if ( (v8 & 0x40000) == 0 )
      {
        v6 = 2;
        if ( (v8 & 0x20000) == 0 )
        {
          if ( (v8 & 0x10000) == 0 )
          {
            v6 = 0;
            v10 = 0;
            v9 = ((unsigned __int64)*(unsigned int *)(v7 + 24) >> 24) & 3;
            goto LABEL_14;
          }
          v6 = 1;
        }
      }
      v9 = ((unsigned __int64)*(unsigned int *)(v7 + 24) >> 24) & 3;
      if ( 1 << (HIBYTE(*(_DWORD *)(v7 + 24)) & 3) > v6 )
      {
        v10 = 0;
        goto LABEL_14;
      }
    }
    v10 = 1;
LABEL_14:
    *(_DWORD *)(80LL * v5 - 536469752) = v10;
    *(_DWORD *)(v7 + 12) = 520093696;
    sub_940407DC(2, "DMA [%d] irq,int_type=%d,req_type=%d!\n", v5, v6, v9);
    if ( *(_DWORD *)(80 * v4 - 536469752) != 0 && *(_QWORD *)(80 * (v4 + 1) - 536469824) != 0 )
      (*(void (__fastcall **)(_QWORD))(80 * (v4 + 1) - 536469824))(*(_QWORD *)(80 * (v4 + 1) - 536469816));
    if ( v0 == 0 )
      return 0;
  }
  sub_940407DC(2, "DMA %d is not security channel!\n", v3);
  return 0;
}

/* ===== sub_9403C380 @ 0x9403C380 size 256 ===== */
__int64 sub_9403C380()
{
  sub_94040888(-536469824, 0, 336);
  sub_94040888(-536472904, 0, 3080);
  if ( (unsigned int)sub_940408CC("sprd-dma", 537919488, 12288, 2, -536469824) != 0 )
    return sub_940407DC(2, "%s: mem map failed %d\n");
  MEMORY[0xFFFFFFFFE0061F30] = MEMORY[0xFFFFFFFFE0061EC0] + 5952LL;
  MEMORY[0xFFFFFFFFE0061EE0] = MEMORY[0xFFFFFFFFE0061EC0] + 5888LL;
  MEMORY[0xFFFFFFFFE0061ED0] = 28;
  MEMORY[0xFFFFFFFFE0061F80] = MEMORY[0xFFFFFFFFE0061EC0] + 6016LL;
  MEMORY[0xFFFFFFFFE0061F20] = 29;
  MEMORY[0xFFFFFFFFE0061F70] = 30;
  MEMORY[0xFFFFFFFFE0061FD0] = MEMORY[0xFFFFFFFFE0061EC0] + 6080LL;
  MEMORY[0xFFFFFFFFE0061FC0] = 31;
  MEMORY[0xFFFFFFFFE0061EC8] = 4;
  sub_9404078C(84, sub_9403C1CC, 0);
  sub_94040788(0x54u);
  return sub_940407DC(2, "sprd dma init ok!\n");
}

/* ===== sub_9403C480 @ 0x9403C480 size 92 ===== */
__int64 __fastcall sub_9403C480(__int64 a1, int a2)
{
  unsigned int v3; // w20
  __int64 result; // x0
  int v5; // [xsp+2Ch] [xbp+2Ch] BYREF

  v3 = a1;
  result = ((__int64 (__fastcall *)(__int64, int *))loc_9403CFF8)(a1, &v5);
  if ( (_DWORD)result == 0 )
  {
    result = 0;
    if ( (a2 & ~v5) != 0 )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD))loc_9403D3C4)(v3, a2 & (unsigned int)~v5) != 0 )
        return 4294901762LL;
      else
        return 0;
    }
  }
  return result;
}

/* ===== sub_9403C4DC @ 0x9403C4DC size 116 ===== */
__int64 __fastcall sub_9403C4DC(unsigned int a1, unsigned int a2)
{
  unsigned int v2; // w2
  int v4; // w0

  v2 = -65535;
  if ( a1 <= a2 )
  {
    v4 = ((__int64 (*)(void))loc_9403CFA8)();
    v2 = -65531;
    if ( v4 == 0 )
      return 0;
  }
  return v2;
}

/* ===== sub_9403C550 @ 0x9403C550 size 128 ===== */
__int64 __fastcall sub_9403C550(__int64 a1, int a2)
{
  unsigned int v3; // w19
  unsigned int v4; // w1
  int v6; // w0
  int v7; // [xsp+28h] [xbp+28h] BYREF
  int v8; // [xsp+2Ch] [xbp+2Ch] BYREF

  v3 = a1;
  v8 = 0;
  v7 = 0;
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, int *))loc_9403CFF8)(a1, &v8) != 0 )
    return (unsigned int)-65533;
  v6 = sub_9403C480(v3, a2);
  v4 = -65534;
  if ( v6 != 0 )
    return v4;
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, int *))loc_9403CFF8)(v3, &v7) != 0 )
  {
    return (unsigned int)-65533;
  }
  else if ( (a2 | v8) == v7 )
  {
    return 0;
  }
  else
  {
    return (unsigned int)-65532;
  }
}

/* ===== sub_9403C5D0 @ 0x9403C5D0 size 232 ===== */
__int64 __fastcall sub_9403C5D0(unsigned int a1, unsigned int a2, int *a3)
{
  unsigned int v6; // w19
  int v7; // w22
  int v9; // [xsp+58h] [xbp+58h] BYREF
  int v10; // [xsp+5Ch] [xbp+5Ch] BYREF

  if ( a2 < a1 )
    return sub_9403C4DC(a1, a2);
  v6 = a1;
  while ( 1 )
  {
    v7 = *a3;
    v9 = 0;
    v10 = 0;
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, int *))loc_9403CFF8)(v6, &v10) != 0 )
      return 4294901763LL;
    if ( (unsigned int)sub_9403C480(v6, v7) != 0 )
      return 4294901762LL;
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, int *))loc_9403CFF8)(v6, &v9) != 0 )
      return 4294901763LL;
    if ( (v7 | v10) != v9 )
      break;
    ++v6;
    ++a3;
    if ( v6 > a2 )
      return sub_9403C4DC(a1, a2);
  }
  return 4294901764LL;
}

/* ===== sub_9403C6B8 @ 0x9403C6B8 size 96 ===== */
__int64 sub_9403C6B8()
{
  __int64 result; // x0
  int v1; // [xsp+18h] [xbp+18h] BYREF
  int v2; // [xsp+1Ch] [xbp+1Ch] BYREF

  ((void (*)(void))loc_9403CF84)();
  v1 = 0;
  v2 = 0;
  result = ((__int64 (__fastcall *)(_QWORD, __int64, int *, int *))loc_9403CFA8)(0, 7, &v1, &v2);
  if ( (_DWORD)result == 0 && (v1 == 0 || (_DWORD)(result = sub_9403C480(34, v1)) == 0) && v2 != 0 )
    return sub_9403C480(35, v2);
  return result;
}

/* ===== sub_9403C718 @ 0x9403C718 size 168 ===== */
__int64 __fastcall sub_9403C718(int *a1)
{
  int *v1; // x20
  unsigned int v2; // w19
  int v3; // w21
  __int64 result; // x0
  int v5; // [xsp+3Ch] [xbp+3Ch] BYREF

  v1 = a1;
  if ( a1 == nullptr )
    return 4294901761LL;
  v2 = 8;
  while ( 1 )
  {
    v3 = *v1++;
    result = ((__int64 (__fastcall *)(_QWORD, int *))loc_9403CFF8)(v2, &v5);
    if ( (_DWORD)result != 0 )
      break;
    if ( (v3 & ~v5) != 0
      && (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD))loc_9403D3C4)(v2, v3 & (unsigned int)~v5) != 0 )
    {
      return 4294901762LL;
    }
    if ( ++v2 == 16 )
      return sub_9403C4DC(8u, 0xFu);
  }
  return result;
}

/* ===== sub_9403C7C0 @ 0x9403C7C0 size 28 ===== */
__int64 __fastcall sub_9403C7C0(int *a1)
{
  if ( a1 != nullptr )
    return sub_9403C5D0(0x19u, 0x20u, a1);
  else
    return 4294901761LL;
}

/* ===== sub_9403C7DC @ 0x9403C7DC size 80 ===== */
__int64 sub_9403C7DC()
{
  __int64 result; // x0
  int v1; // [xsp+1Ch] [xbp+1Ch] BYREF

  result = ((__int64 (__fastcall *)(__int64, int *))loc_9403CFF8)(33, &v1);
  if ( (_DWORD)result == 0 )
  {
    result = 0;
    if ( (~(_BYTE)v1 & 2) != 0 )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))loc_9403D3C4)(33, ~(_BYTE)v1 & 2) != 0 )
        return 4294901762LL;
      else
        return 0;
    }
  }
  return result;
}

/* ===== sub_9403C82C @ 0x9403C82C size 176 ===== */
__int64 __fastcall sub_9403C82C(int a1, _DWORD *a2)
{
  unsigned int v3; // w19
  int v4; // w21
  __int64 result; // x0
  int v6; // w0
  int i; // w2
  int v8; // [xsp+3Ch] [xbp+3Ch] BYREF

  if ( a2 == nullptr )
    return 4294901761LL;
  if ( a1 == 0 )
    return ((__int64 (__fastcall *)(__int64))loc_9403CFF8)(24);
  if ( a1 != 1 )
    return 4294901761LL;
  v3 = 36;
  v4 = 0;
  while ( 1 )
  {
    result = ((__int64 (__fastcall *)(_QWORD, int *))loc_9403CFF8)(v3, &v8);
    if ( (_DWORD)result != 0 )
      break;
    v6 = v8;
    for ( i = 0; v6 != 0; v6 &= v6 - 1 )
      ++i;
    ++v3;
    v4 += i;
    if ( v3 == 43 )
    {
      *a2 = v4;
      return 0;
    }
  }
  return result;
}

/* ===== sub_9403C8DC @ 0x9403C8DC size 296 ===== */
__int64 __fastcall sub_9403C8DC(int a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int v4; // w19
  unsigned int v5; // w20
  int v6; // w21
  unsigned __int64 v7; // x21
  bool v8; // zf
  int v9; // [xsp+58h] [xbp+58h] BYREF
  int v10; // [xsp+5Ch] [xbp+5Ch] BYREF

  result = 4294901761LL;
  v4 = a2;
  if ( a2 != 0 )
  {
    if ( a1 != 0 )
    {
      if ( a1 == 1 && a2 <= 0xDF )
      {
        v5 = 36;
        while ( 1 )
        {
          if ( v4 > 0x20 )
            v6 = 32;
          else
            v6 = v4;
          v4 -= v6;
          v9 = 0;
          v10 = 0;
          if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, int *))loc_9403CFF8)(v5, &v10) != 0 )
            return 4294901763LL;
          v7 = 0xFFFFFFFFuLL >> (32 - (unsigned __int8)v6);
          if ( (unsigned int)sub_9403C480(v5, v7) != 0 )
            return 4294901762LL;
          result = ((__int64 (__fastcall *)(_QWORD, int *))loc_9403CFF8)(v5, &v9);
          if ( (_DWORD)result != 0 )
            return 4294901763LL;
          if ( (v10 | (unsigned int)v7) != v9 )
            break;
          v8 = v5++ == 42;
          if ( v8 || v4 == 0 )
            return result;
        }
        return 4294901764LL;
      }
    }
    else
    {
      return sub_9403C550(24, a2);
    }
  }
  return result;
}

/* ===== sub_9403CA04 @ 0x9403CA04 size 28 ===== */
__int64 sub_9403CA04()
{
  char v1; // [xsp+1Ch] [xbp+1Ch] BYREF

  return ((__int64 (__fastcall *)(__int64, char *))loc_9403CFF8)(33, &v1);
}

/* ===== sub_9403CA20 @ 0x9403CA20 size 392 ===== */
__int64 __fastcall sub_9403CA20(_DWORD *a1)
{
  __int64 result; // x0
  _DWORD *v3; // x19
  int v4; // w0
  int v5; // w1
  int v6; // [xsp+2Ch] [xbp+2Ch] BYREF
  int v7; // [xsp+30h] [xbp+30h] BYREF
  int v8; // [xsp+34h] [xbp+34h] BYREF
  int v9; // [xsp+38h] [xbp+38h] BYREF
  int v10; // [xsp+3Ch] [xbp+3Ch] BYREF
  int v11; // [xsp+40h] [xbp+40h] BYREF
  int v12; // [xsp+44h] [xbp+44h] BYREF
  int v13; // [xsp+48h] [xbp+48h] BYREF
  int v14; // [xsp+4Ch] [xbp+4Ch] BYREF

  result = 4294901761LL;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  if ( a1 != nullptr )
  {
    v3 = a1;
    result = ((__int64 (__fastcall *)(__int64, int *))loc_9403CFF8)(34, &v6);
    if ( (_DWORD)result == 0 )
    {
      if ( v6 == 0 )
        *v3 = 0;
      ((void (__fastcall *)(_QWORD, __int64, int *, int *))loc_9403CFA8)(0, 7, &v8, &v9);
      ((void (__fastcall *)(__int64, __int64, int *, int *))loc_9403CFA8)(16, 23, &v10, &v11);
      ((void (__fastcall *)(__int64, __int64, int *, int *))loc_9403CFA8)(25, 32, &v12, &v13);
      if ( v8 == (v8 & v6) )
        *v3 = 1;
      if ( v9 != 0 || v11 != 0 || v13 != 0 )
        ((void (__fastcall *)(__int64, int *))loc_9403CFF8)(35, &v7);
      v14 = 0;
      result = ((__int64 (__fastcall *)(__int64, int *))loc_9403CFF8)(33, &v14);
      if ( (_DWORD)result == 0 )
      {
        if ( (v14 & 2) != 0 )
        {
          if ( (v12 | v8) != ((v12 | v8) & v6) )
            goto LABEL_13;
          v4 = v9;
          v5 = v13;
        }
        else
        {
          if ( (v10 | v8) != ((v10 | v8) & v6) )
          {
LABEL_13:
            v14 = 0;
            return ((__int64 (__fastcall *)(__int64, int *))loc_9403CFF8)(33, &v14);
          }
          v4 = v9;
          v5 = v11;
        }
        if ( (v5 | v4) == ((v5 | v4) & v7) )
          *v3 = 5;
        goto LABEL_13;
      }
    }
  }
  return result;
}

/* ===== sub_9403CBA8 @ 0x9403CBA8 size 136 ===== */
__int64 __fastcall sub_9403CBA8(unsigned int a1, unsigned int a2, __int64 a3)
{
  unsigned int v3; // w19
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // [xsp+28h] [xbp+28h]

  v3 = a1;
  if ( a3 == 0 || a1 <= 0xF || a2 <= 0xF )
    return 4294901761LL;
  if ( a1 > a2 )
    return 0;
  while ( 1 )
  {
    v6 = v3++;
    v7 = a3 + 4;
    result = ((__int64 (__fastcall *)(__int64, __int64))loc_9403CFF8)(v6, a3);
    if ( (_DWORD)result != 0 )
      break;
    a3 = v7;
    if ( a2 < v3 )
      return 0;
    if ( v7 == 0 )
      return 4294901766LL;
  }
  return result;
}

/* ===== sub_9403CC30 @ 0x9403CC30 size 16 ===== */
__int64 __fastcall sub_9403CC30(__int64 a1)
{
  return sub_9403CBA8(0x10u, 0x17u, a1);
}

/* ===== sub_9403CC40 @ 0x9403CC40 size 16 ===== */
__int64 __fastcall sub_9403CC40(__int64 a1)
{
  return sub_9403CBA8(0x19u, 0x20u, a1);
}

/* ===== sub_9403CC50 @ 0x9403CC50 size 60 ===== */
__int64 __fastcall sub_9403CC50(_DWORD *a1)
{
  __int64 result; // x0
  int v3; // [xsp+2Ch] [xbp+2Ch] BYREF

  v3 = 0;
  result = ((__int64 (__fastcall *)(__int64, int *))loc_9403CFF8)(33, &v3);
  if ( (_DWORD)result == 0 )
    *a1 = (v3 & 2) != 0;
  return result;
}

/* ===== sub_9403CC8C @ 0x9403CC8C size 4 ===== */
// attributes: thunk
void sub_9403CC8C(void)
{
  JUMPOUT(0x9403D464LL);
}

/* ===== sub_9403CC90 @ 0x9403CC90 size 2308 ===== */
__int64 sub_9403CC90()
{
  unsigned int v1; // [xsp+7Ch] [xbp-4h] BYREF

  sub_94040978(&qword_94067AF0, &v1, 3221225472LL);
  return sub_940409B8(&qword_94067AF0, v1, 3221225472LL);
}

/* ===== sub_9403D594 @ 0x9403D594 size 420 ===== */
__int64 __fastcall sub_9403D594(unsigned int a1, unsigned int a2, __int64 a3, int a4)
{
  int v6; // w0
  __int64 v7; // x2
  unsigned int v9; // w0
  unsigned int i; // w0
  unsigned int v11; // w3
  __int64 v12; // x1
  unsigned int v13; // w19
  int v14; // w3
  int v16; // [xsp+30h] [xbp+30h]
  __int64 v18; // [xsp+38h] [xbp+38h]

  v6 = sub_9404096C(0);
  v7 = a3;
  if ( v6 != 0 )
    return 2;
  v16 = a4;
  v18 = v7;
  ((void (*)(void))loc_9403D46C)();
  MEMORY[0x4C] = 34832;
  MEMORY[0x40] |= 0x10u;
  MEMORY[0x54] |= 4u;
  MEMORY[0x54] &= ~2u;
  sub_94040A88(1u);
  MEMORY[0x54] |= 1u;
  sub_94040A88(1u);
  MEMORY[0x40] |= 2u;
  if ( v16 != 0 )
    v9 = MEMORY[0x40] | 4;
  else
    v9 = MEMORY[0x40] & 0xFFFFFFFB;
  MEMORY[0x40] = v9;
  for ( i = a1; a2 >= i; *(_DWORD *)(v12 + 4096) = *(_DWORD *)(v18 + 4LL * v11) )
  {
    v11 = i - a1;
    v12 = 4LL * (i++ & 0x3FFFFFFF);
  }
  if ( MEMORY[0x44] != 0 )
  {
    v14 = a1;
    v13 = 2;
    sub_940407DC(2, "efuse_write_drv(): err = %x start_id = %d end_id = %d\n", MEMORY[0x44], v14, a2);
  }
  else
  {
    v13 = 0;
  }
  MEMORY[0x54] &= ~1u;
  sub_94040A88(1u);
  MEMORY[0x54] |= 2u;
  sub_94040A88(1u);
  MEMORY[0x54] &= ~4u;
  MEMORY[0x40] &= ~0x10u;
  MEMORY[0x4C] = 0;
  ((void (*)(void))loc_9403D4F8)();
  if ( (unsigned int)sub_94040974(0) != 0 )
    return 2;
  else
    return v13;
}

/* ===== sub_9403D738 @ 0x9403D738 size 248 ===== */
__int64 __fastcall sub_9403D738(unsigned int a1, unsigned int a2, __int64 a3, int a4)
{
  unsigned int v9; // w0
  unsigned int i; // w0
  __int64 v11; // x3
  unsigned int v12; // w1
  unsigned int v13; // w19
  int v14; // w3

  if ( (unsigned int)sub_9404096C(0) != 0 )
    return 1;
  ((void (*)(void))loc_9403D46C)();
  if ( a4 != 0 )
    v9 = MEMORY[0x40] | 4;
  else
    v9 = MEMORY[0x40] & 0xFFFFFFFB;
  MEMORY[0x40] = v9;
  for ( i = a1; a2 >= i; *(_DWORD *)(a3 + 4LL * v12) = *(_DWORD *)(v11 + 4096) )
  {
    v11 = 4LL * (i & 0x3FFFFFFF);
    v12 = i - a1;
    ++i;
  }
  if ( MEMORY[0x44] != 0 )
  {
    v14 = a1;
    v13 = 1;
    sub_940407DC(2, "efuse_read_drv(): err = %x start_id = %d end_id = %d\n", MEMORY[0x44], v14, a2);
  }
  else
  {
    v13 = 0;
  }
  ((void (*)(void))loc_9403D4F8)();
  if ( (unsigned int)sub_94040974(0) != 0 )
    return 1;
  else
    return v13;
}

/* ===== sub_9403D830 @ 0x9403D830 size 324 ===== */
__int64 __fastcall sub_9403D830(int a1, int a2)
{
  unsigned int v4; // w19

  if ( (unsigned int)sub_9404096C(0) != 0 )
    return 2;
  ((void (*)(void))loc_9403D46C)();
  v4 = 0;
  MEMORY[0x4C] = 34832;
  MEMORY[0x54] |= 4u;
  MEMORY[0x54] &= ~2u;
  sub_94040A88(1u);
  MEMORY[0x54] |= 1u;
  sub_94040A88(1u);
  MEMORY[0x40] &= ~2u;
  MEMORY[0x40] |= 4u;
  *(_DWORD *)(4LL * (a1 & 0x3FFFFFFF) + 0x1000) = a2;
  if ( MEMORY[0x44] != 0 )
  {
    v4 = 2;
    sub_940407DC(2, "efuse_rewrite_double_bit(): err = %x block_id = %d\n", MEMORY[0x44], a1);
  }
  MEMORY[0x54] &= ~1u;
  sub_94040A88(1u);
  MEMORY[0x54] |= 2u;
  sub_94040A88(1u);
  MEMORY[0x54] &= ~4u;
  MEMORY[0x4C] = 0;
  ((void (*)(void))loc_9403D4F8)();
  if ( (unsigned int)sub_94040974(0) != 0 )
    return 2;
  else
    return v4;
}

/* ===== sub_9403D974 @ 0x9403D974 size 408 ===== */
__int64 sub_9403D974()
{
  unsigned int v1; // w19

  if ( (unsigned int)sub_9404096C(0) != 0 )
    return 2;
  ((void (*)(void))loc_9403D46C)();
  MEMORY[0x4C] = 34832;
  MEMORY[0x40] |= 0x10u;
  MEMORY[0x54] |= 4u;
  MEMORY[0x54] &= ~2u;
  sub_94040A88(1u);
  MEMORY[0x54] |= 1u;
  sub_94040A88(1u);
  MEMORY[0x40] |= 2u;
  MEMORY[0x40] |= 4u;
  MEMORY[0x3038] |= 1u;
  MEMORY[0x18] = 32;
  MEMORY[0x200] = 3;
  MEMORY[0x340] |= 0x80000000;
  while ( (MEMORY[0x340] & 0x80000000) != 0 )
    ;
  MEMORY[0x200] = 0;
  v1 = 0;
  MEMORY[0x18] = 0;
  MEMORY[0x3038] &= ~1u;
  if ( MEMORY[0x44] != 0 )
  {
    v1 = 2;
    sub_940407DC(2, "efuse_huk_program(): err = %x\n", MEMORY[0x44]);
  }
  MEMORY[0x54] &= ~1u;
  sub_94040A88(1u);
  MEMORY[0x54] |= 2u;
  sub_94040A88(1u);
  MEMORY[0x54] &= ~4u;
  MEMORY[0x40] &= ~0x10u;
  MEMORY[0x4C] = 0;
  ((void (*)(void))loc_9403D4F8)();
  if ( (unsigned int)sub_94040974(0) != 0 )
    return 2;
  else
    return v1;
}

/* ===== sub_9403DC08 @ 0x9403DC08 size 76 ===== */
__int64 sub_9403DC08()
{
  __int64 result; // x0

  result = sub_9402D420(7u, (__int64)qword_9405C718);
  if ( (_DWORD)result != 0 && MEMORY[0xFFFFFFFFE003CB98] > 1 )
    return sub_9404B2FC("fp_driver can not install std in handler: %d\n", result);
  return result;
}

/* ===== sub_9403DC54 @ 0x9403DC54 size 240 ===== */
__int64 __fastcall sub_9403DC54(int a1, char a2, char a3, char a4, unsigned __int8 a5)
{
  __int64 v9; // x0
  unsigned int v10; // w19

  v9 = sub_940490FC(a5);
  MEMORY[0xFFFFFFFFE0062010] = v9;
  if ( v9 != 0 )
  {
    *(_DWORD *)v9 = a1;
    *(_BYTE *)(v9 + 4) = a2;
    *(_BYTE *)(v9 + 5) = a3;
    *(_BYTE *)(v9 + 6) = a4;
    if ( MEMORY[0xFFFFFFFFE0047B28] != 0 && (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
      sub_9404B2FC((const char *)&loc_94053648);
    v10 = sub_940490E4(MEMORY[0xFFFFFFFFE0062010]);
    if ( MEMORY[0xFFFFFFFFE0047B28] != 0 && (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
      sub_9404B2FC("fp_driver after spi_setup ret:%d\n", v10);
  }
  else
  {
    v10 = -1;
    if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
      sub_9404B2FC((const char *)&loc_94053608);
  }
  return v10;
}

/* ===== sub_9403DD44 @ 0x9403DD44 size 1088 ===== */
__int64 __fastcall sub_9403DD44(__int64 a1, int a2, unsigned int a3)
{
  __int64 v4; // x21
  __int64 v5; // x0
  int v6; // w19
  __int64 v7; // x0
  __int64 v8; // x19
  __int64 v9; // x22
  int v10; // w21
  int v12; // [xsp+30h] [xbp+30h] BYREF
  unsigned __int8 v13; // [xsp+34h] [xbp+34h]
  unsigned __int8 v14; // [xsp+35h] [xbp+35h]
  unsigned __int8 v15; // [xsp+36h] [xbp+36h]
  unsigned __int8 v16; // [xsp+37h] [xbp+37h]
  unsigned int v17; // [xsp+38h] [xbp+38h]
  unsigned int v18; // [xsp+3Ch] [xbp+3Ch]
  unsigned int v19; // [xsp+40h] [xbp+40h]
  char v20; // [xsp+44h] [xbp+44h]
  _QWORD v21[3]; // [xsp+48h] [xbp+48h] BYREF

  if ( a3 == 0 )
    return 4294967288LL;
  switch ( a2 )
  {
    case 0:
      sub_9404D244(&v12, a3, 24);
      MEMORY[0xFFFFFFFFE0047B28] = v20;
      if ( v20 != 0 && (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
        sub_9404B2FC((const char *)&loc_94053690, v13, v14, v15, v16, v19);
      v6 = sub_9403DC54(v12, v13, v14, v15, v16);
      if ( MEMORY[0xFFFFFFFFE0047B28] != 0 )
      {
        if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) != 0 )
        {
          if ( v6 != 0 )
            return 0xFFFFFFFFLL;
          goto LABEL_34;
        }
        sub_9404B2FC("fp_driver after sprd_fp_default_init\n");
      }
      if ( v6 == 0 )
      {
LABEL_34:
        v7 = sub_9404CBC4(v19);
        v8 = v7;
        if ( v7 == 0 )
        {
          if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
            sub_9404B2FC("malloc txbuf error\n");
          return 4294967291LL;
        }
        sub_9404D244(v7, v18, v19);
        v9 = sub_9404CBC4(v19);
        if ( v9 == 0 )
        {
          if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
            sub_9404B2FC("malloc rxbuf error\n");
          sub_9404CC20(v8);
          return 4294967291LL;
        }
        v21[0] = v8;
        v21[1] = v9;
        v21[2] = v19;
        if ( MEMORY[0xFFFFFFFFE0047B28] != 0 && (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
          sub_9404B2FC((const char *)sub_94053770);
        v10 = sub_940490CC(MEMORY[0xFFFFFFFFE0062010], v21);
        if ( MEMORY[0xFFFFFFFFE0047B28] != 0 )
        {
          if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) != 0 )
          {
            if ( v10 != 0 )
            {
LABEL_45:
              sub_9404CC20(v8);
              sub_9404CC20(v9);
              return 0xFFFFFFFFLL;
            }
LABEL_52:
            sub_9404D224(v17, v9, v19);
            sub_9404CC20(v8);
            sub_9404CC20(v9);
            return 0;
          }
          sub_9404B2FC("fp_driver after spi_sync ret:%d\n", v10);
        }
        if ( v10 != 0 )
        {
          if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
            sub_9404B2FC((const char *)&loc_940537B8);
          goto LABEL_45;
        }
        goto LABEL_52;
      }
      if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) != 0 )
        return 0xFFFFFFFFLL;
      sub_9404B2FC((const char *)&loc_94053718);
      return 0xFFFFFFFFLL;
    case 1:
      sub_9404D244(-536577244, a3, 4);
      return 0;
    case 2:
      sub_9404D224(a3, -536577244, 4);
      return 0;
    case 3:
      if ( MEMORY[0xFFFFFFFFE0062020] != 0 )
      {
        sub_9404CC20(MEMORY[0xFFFFFFFFE0062020]);
        MEMORY[0xFFFFFFFFE0062020] = 0;
      }
      MEMORY[0xFFFFFFFFE0062018] = 0;
      sub_9404D244(-536469480, a3, 4);
      v4 = (unsigned int)(4 * MEMORY[0xFFFFFFFFE0062018]);
      if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
        sub_9404B2FC("IFAA_SET_FP_ENROLLED_ID_LIST--> list_num = %d, fps_len = %d\n", MEMORY[0xFFFFFFFFE0062018], v4);
      v5 = sub_9404CBC4(v4);
      MEMORY[0xFFFFFFFFE0062020] = v5;
      if ( v5 != 0 )
      {
        sub_9404CDC4(v5, 0, v4);
        sub_9404D244(MEMORY[0xFFFFFFFFE0062020], a3 + 4, v4);
        if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
          sub_9404B2FC("IFAA_SET_FP_ENROLLED_ID_LIST--> id[0] = 0x%x\n", *MEMORY[0xFFFFFFFFE0062020]);
        return 0;
      }
      else
      {
        if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) != 0 )
          return 0xFFFFFFFFLL;
        sub_9404B2FC("IFAA_SET_FP_ENROLLED_ID_LIST malloc failed.\n");
        return 0xFFFFFFFFLL;
      }
    case 4:
      if ( MEMORY[0xFFFFFFFFE0062020] == 0 )
        return 0xFFFFFFFFLL;
      sub_9404D224(a3, -536469480, 4);
      sub_9404D224(a3 + 4, MEMORY[0xFFFFFFFFE0062020], 4LL * MEMORY[0xFFFFFFFFE0062018]);
      return 0;
    case 5:
      sub_9404D244(-536469464, a3, 136);
      return 0;
    case 6:
      sub_9404D224(a3, -536469464, 136);
      return 0;
    case 7:
      sub_9404D244(-536577248, a3, 2);
      return 0;
    case 8:
      sub_9404D224(a3, -536577248, 2);
      return 0;
    default:
      return 4294967272LL;
  }
}

/* ===== sub_9403E184 @ 0x9403E184 size 292 ===== */
__int64 sub_9403E184()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 v2; // x0
  const void *v3; // x0
  __int64 v4; // x0
  const void *v6; // x0
  const void *v7; // x0
  int v8; // [xsp+18h] [xbp+18h]
  int v9; // [xsp+18h] [xbp+18h]
  int v10; // [xsp+18h] [xbp+18h]
  __int64 v11; // [xsp+20h] [xbp+20h] BYREF
  __int64 v12; // [xsp+28h] [xbp+28h] BYREF

  v0 = sub_9402D420(6u, (__int64)qword_9405C730);
  if ( (_DWORD)v0 != 0 )
  {
    v10 = v0;
    v7 = (const void *)sub_94040A98(v0);
    sub_940407DC(3, "%p: %s: %s: failed to install firewall handler: %d\n", v7, "SPRD_FW", "sprd_pal_fw_init", v10);
  }
  v1 = sub_940408CC("sprd_fw_iram", 57344, 0x2000, 2, &v11);
  if ( (_DWORD)v1 != 0 )
  {
    v9 = v1;
    v6 = (const void *)sub_94040A98(v1);
    sub_940407DC(3, "%p: %s: %s: map sprd_fw_iram failed[0x%x]\n", v6, "SPRD_FW", "sprd_pal_fw_init", v9);
  }
  v11 += 3072;
  v2 = sub_940408CC("sprd_fw", 838926336, 0x10000, 2, &v12);
  if ( (_DWORD)v2 != 0 )
  {
    v8 = v2;
    v3 = (const void *)sub_94040A98(v2);
    sub_940407DC(3, "%p: %s: %s: map fw_vaddr failed[0x%x]\n", v3, "SPRD_FW", "sprd_pal_fw_init", v8);
  }
  v4 = sub_9403F4C8(v12, v11);
  return sub_9403E3A8(v4);
}

/* ===== sub_9403E2A8 @ 0x9403E2A8 size 32 ===== */
__int64 sub_9403E2A8()
{
  __int64 result; // x0

  result = sub_94040AA0();
  if ( (_DWORD)result == 0 )
    return sub_9403E548();
  return result;
}

/* ===== sub_9403E2C8 @ 0x9403E2C8 size 32 ===== */
__int64 sub_9403E2C8()
{
  __int64 result; // x0

  result = sub_94040AA0();
  if ( (_DWORD)result == 0 )
    return sub_9403E620();
  return result;
}

/* ===== sub_9403E2E8 @ 0x9403E2E8 size 184 ===== */
__int64 __fastcall sub_9403E2E8(__int64 a1, int a2)
{
  unsigned int v2; // w19
  __int64 v4; // x0
  __int64 v5; // x2
  __int64 v6; // x0
  __int64 v7; // x2

  if ( a2 == 1 )
  {
    v6 = sub_9403E804();
    v2 = v6;
    if ( (_DWORD)v6 == 0 )
      return v2;
    v7 = sub_94040A98(v6);
    sub_940407DC(3, "%p: %s: %s: lock CP error. res = 0x%x\n", v7, "SPRD_FW", &loc_940540D8, v2);
    return v2;
  }
  if ( a2 == 0 )
  {
    v4 = sub_9403E710();
    v2 = v4;
    if ( (_DWORD)v4 == 0 )
      return v2;
    v5 = sub_94040A98(v4);
    sub_940407DC(3, "%p: %s: %s: unlock CP error. res = 0x%x\n", v5, "SPRD_FW", &loc_940540D8, v2);
    return v2;
  }
  if ( a2 != 2 )
    return (unsigned int)-24;
  sub_9403E6F8();
  return 0;
}

/* ===== sub_9403E3A0 @ 0x9403E3A0 size 8 ===== */
__int64 sub_9403E3A0()
{
  return 0;
}

/* ===== sub_9403E3A8 @ 0x9403E3A8 size 416 ===== */
__int64 sub_9403E3A8()
{
  __int64 v0; // x0
  unsigned int v1; // w19
  __int64 v2; // x0
  __int64 v3; // x0
  unsigned int v4; // w19
  __int64 v5; // x0
  const void *v7; // x0
  __int64 v8; // x0
  const void *v9; // x0
  __int64 v10; // x0
  __int64 v11; // x2
  __int64 v12; // x0
  const void *v13; // x0
  __int64 v14; // x0
  __int64 v15; // x2
  _QWORD v16[10]; // [xsp+20h] [xbp+20h] BYREF

  sub_9403F4B8();
  v0 = sub_9403ED58(3, 275, 1, 1);
  v1 = v0;
  if ( (_DWORD)v0 != 0 )
  {
    v7 = (const void *)sub_94040A98(v0);
    v8 = sub_940407DC(
           3,
           "%p: %s: %s: config SLV_FW_AP SLV_ID_SCE Error(0x%x)!\n",
           v7,
           "SPRD_FW",
           "sprd_config_default_slave_fw",
           v1);
    v9 = (const void *)sub_94040A98(v8);
    v10 = sub_940407DC(
            3,
            "%p: %s: %s: config default slave fw failed(0x%x)!\n",
            v9,
            "SPRD_FW",
            "sprd_fw_config_default",
            v1);
    sub_9403F4C0(v10);
    return v1;
  }
  else
  {
    v2 = sub_940408C8(-536465408);
    v3 = sub_9403F0D8(10, v2);
    v4 = v3;
    if ( (_DWORD)v3 != 0 )
    {
      v11 = sub_94040A98(v3);
      v12 = sub_940407DC(
              3,
              "%p: %s: %s: config default addr Error(0x%x)!\n",
              v11,
              "SPRD_FW",
              "sprd_config_default_memory_fw",
              v4);
    }
    else
    {
      v16[1] = 2516582399LL;
      v16[0] = 2483027968LL;
      v16[2] = -1;
      v16[4] = 0;
      v16[6] = -1;
      v16[8] = 0;
      v16[3] = -1;
      v16[5] = 0;
      v16[7] = -1;
      v16[9] = 0;
      v5 = sub_9403F078(10, 256, v16);
      v4 = v5;
      if ( (_DWORD)v5 == 0 )
      {
        sub_9403F4C0(v5);
        return 0;
      }
      v15 = sub_94040A98(v5);
      v12 = sub_940407DC(
              3,
              "%p: %s: %s: config region TOS_MEMORY Error(0x%x)!\n",
              v15,
              "SPRD_FW",
              "sprd_config_default_memory_fw",
              v4);
    }
    v13 = (const void *)sub_94040A98(v12);
    v14 = sub_940407DC(
            3,
            "%p: %s: %s: config default memory fw failed(0x%x)!\n",
            v13,
            "SPRD_FW",
            "sprd_fw_config_default",
            v4);
    sub_9403F4C0(v14);
    return v4;
  }
}

/* ===== sub_9403E548 @ 0x9403E548 size 216 ===== */
__int64 sub_9403E548()
{
  __int64 v0; // x0
  unsigned int v1; // w19
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x2
  __int64 v6; // x2
  __int64 v8; // x2
  __int64 v9; // x2

  sub_9403F4B8();
  v0 = sub_9403EAE4(1);
  v1 = v0;
  if ( (_DWORD)v0 != 0 )
  {
    v8 = sub_94040A98(v0);
    v4 = sub_940407DC(3, "%p: %s: %s: save MST_CTRL_AP failed(0x%x)!\n", v8, "SPRD_FW", "sprd_fw_save_config", v1);
  }
  else
  {
    v2 = sub_9403EAE4(3);
    v1 = v2;
    if ( (_DWORD)v2 != 0 )
    {
      v6 = sub_94040A98(v2);
      v4 = sub_940407DC(3, "%p: %s: %s: save SLV_FW_AP failed(0x%x)!\n", v6, "SPRD_FW", "sprd_fw_save_config", v1);
    }
    else
    {
      v3 = sub_9403EAE4(7);
      v1 = v3;
      if ( (_DWORD)v3 != 0 )
      {
        v9 = sub_94040A98(v3);
        v4 = sub_940407DC(3, "%p: %s: %s: save REG_FW_AP_APB failed(0x%x)!\n", v9, "SPRD_FW", "sprd_fw_save_config", v1);
      }
      else
      {
        v4 = sub_9403EAE4(8);
        v1 = v4;
        if ( (_DWORD)v4 != 0 )
        {
          v5 = sub_94040A98(v4);
          v4 = sub_940407DC(
                 3,
                 "%p: %s: %s: save REG_FW_AP_AHB failed(0x%x)!\n",
                 v5,
                 "SPRD_FW",
                 "sprd_fw_save_config",
                 v1);
        }
      }
    }
  }
  sub_9403F4C0(v4);
  return v1;
}

/* ===== sub_9403E620 @ 0x9403E620 size 216 ===== */
__int64 sub_9403E620()
{
  __int64 v0; // x0
  unsigned int v1; // w19
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x2
  __int64 v6; // x2
  __int64 v8; // x2
  __int64 v9; // x2

  sub_9403F4B8();
  v0 = sub_9403EBEC(1);
  v1 = v0;
  if ( (_DWORD)v0 != 0 )
  {
    v8 = sub_94040A98(v0);
    v4 = sub_940407DC(3, "%p: %s: %s: restore MST_CTRL_AP failed(0x%x)!\n", v8, "SPRD_FW", "sprd_fw_restore_config", v1);
  }
  else
  {
    v2 = sub_9403EBEC(3);
    v1 = v2;
    if ( (_DWORD)v2 != 0 )
    {
      v6 = sub_94040A98(v2);
      v4 = sub_940407DC(3, "%p: %s: %s: restore SLV_FW_AP failed(0x%x)!\n", v6, "SPRD_FW", "sprd_fw_restore_config", v1);
    }
    else
    {
      v3 = sub_9403EBEC(7);
      v1 = v3;
      if ( (_DWORD)v3 != 0 )
      {
        v9 = sub_94040A98(v3);
        v4 = sub_940407DC(
               3,
               "%p: %s: %s: restore REG_FW_AP_APB failed(0x%x)!\n",
               v9,
               "SPRD_FW",
               "sprd_fw_restore_config",
               v1);
      }
      else
      {
        v4 = sub_9403EBEC(8);
        v1 = v4;
        if ( (_DWORD)v4 != 0 )
        {
          v5 = sub_94040A98(v4);
          v4 = sub_940407DC(
                 3,
                 "%p: %s: %s: restore REG_FW_AP_AHB failed(0x%x)!\n",
                 v5,
                 "SPRD_FW",
                 "sprd_fw_restore_config",
                 v1);
        }
      }
    }
  }
  sub_9403F4C0(v4);
  return v1;
}

/* ===== sub_9403E6F8 @ 0x9403E6F8 size 24 ===== */
__int64 sub_9403E6F8()
{
  __int64 v0; // x0
  __int64 v1; // x0

  v0 = sub_9403F4B8();
  v1 = sub_9403F210(v0);
  return sub_9403F4C0(v1);
}

/* ===== sub_9403E710 @ 0x9403E710 size 244 ===== */
__int64 sub_9403E710()
{
  __int64 v0; // x0
  unsigned int v1; // w19
  __int64 v2; // x0
  __int64 v3; // x2
  __int64 v5; // x2
  _QWORD v6[10]; // [xsp+20h] [xbp+20h] BYREF

  sub_9403F4B8();
  sub_94040888(v6, 0, 80);
  v6[1] = 0;
  v6[0] = -1;
  v0 = sub_9403F078(10, 257, v6);
  v1 = v0;
  if ( (_DWORD)v0 != 0 )
  {
    v5 = sub_94040A98(v0);
    v2 = sub_940407DC(
           3,
           "%p: %s: %s: config region CP_MODEM Error(0x%x)!\n",
           v5,
           "SPRD_FW",
           "sprd_destroy_cp_modem",
           v1);
  }
  else
  {
    v2 = sub_9403ED58(2, 74, 3, 3);
    v1 = v2;
    if ( (_DWORD)v2 != 0
      || (v2 = sub_9403ED58(2, 73, 3, 3), v1 = v2, (_DWORD)v2 != 0)
      || (v2 = sub_9403ED58(2, 72, 3, 3), v1 = v2, (_DWORD)v2 != 0) )
    {
      v3 = sub_94040A98(v2);
      v2 = sub_940407DC(
             3,
             "%p: %s: %s: config SLV_FW_AON SLV_ID_SM4_IRAM1 Error(0x%x)!\n",
             v3,
             "SPRD_FW",
             "sprd_destroy_cp_modem",
             v1);
    }
  }
  sub_9403F4C0(v2);
  return v1;
}

/* ===== sub_9403E804 @ 0x9403E804 size 384 ===== */
__int64 sub_9403E804()
{
  unsigned int v0; // w3
  int v1; // w0
  int v2; // w1
  __int64 v3; // x0
  unsigned int v4; // w19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x2
  __int64 v9; // x2
  __int64 v11; // x2
  __int64 v12; // x2
  _QWORD v13[9]; // [xsp+20h] [xbp+20h] BYREF
  unsigned __int64 v14; // [xsp+68h] [xbp+68h]

  sub_9403F4B8();
  sub_94040888(v13, 0, 80);
  v13[8] = 0;
  v13[0] = 2304770048LL;
  v0 = 0;
  v13[1] = 2371616767LL;
  memset(&v13[2], 255, 48);
  v1 = 72;
  v14 = 0;
  do
  {
    v2 = 1 << v1++;
    v0 |= v2;
  }
  while ( v1 != 96 );
  v14 = __PAIR64__(HIDWORD(v14), v0) | 0x3F00000000000000LL;
  v3 = sub_9403F078(10, 257, v13);
  v4 = v3;
  if ( (_DWORD)v3 != 0 )
  {
    v11 = sub_94040A98(v3);
    v7 = sub_940407DC(
           3,
           "%p: %s: %s: config region CP_MODEM Error(0x%x)!\n",
           v11,
           "SPRD_FW",
           "sprd_recreate_cp_modem",
           v4);
  }
  else
  {
    v5 = sub_9403ED58(2, 74, 3, 1);
    v4 = v5;
    if ( (_DWORD)v5 != 0 )
    {
      v9 = sub_94040A98(v5);
      v7 = sub_940407DC(
             3,
             "%p: %s: %s: config SLV_FW_AON SLV_ID_SM4_IRAM1 Error(0x%x)!\n",
             v9,
             "SPRD_FW",
             "sprd_recreate_cp_modem",
             v4);
    }
    else
    {
      v6 = sub_9403ED58(2, 73, 3, 1);
      v4 = v6;
      if ( (_DWORD)v6 != 0 )
      {
        v12 = sub_94040A98(v6);
        v7 = sub_940407DC(
               3,
               "%p: %s: %s: config SLV_FW_AON SLV_ID_SM4_IRAM2 Error(0x%x)!\n",
               v12,
               "SPRD_FW",
               "sprd_recreate_cp_modem",
               v4);
      }
      else
      {
        v7 = sub_9403ED58(2, 72, 3, 1);
        v4 = v7;
        if ( (_DWORD)v7 != 0 )
        {
          v8 = sub_94040A98(v7);
          v7 = sub_940407DC(
                 3,
                 "%p: %s: %s: config SLV_FW_AON SLV_ID_SM4_IRAM3 Error(0x%x)!\n",
                 v8,
                 "SPRD_FW",
                 "sprd_recreate_cp_modem",
                 v4);
        }
      }
    }
  }
  sub_9403F4C0(v7);
  return v4;
}

/* ===== sub_9403E984 @ 0x9403E984 size 352 ===== */
__int64 __fastcall sub_9403E984(__int64 a1, _QWORD *a2, _QWORD *a3, _DWORD *a4, _QWORD *a5, _DWORD *a6)
{
  const void *v6; // x0
  __int64 result; // x0
  int v8; // [xsp+18h] [xbp+18h]

  switch ( (int)a1 )
  {
    case 1:
      *a2 = 0;
      *a3 = 0;
      *a4 = 0;
      *a5 = 0x8000;
      *a6 = 2;
      result = 0;
      break;
    case 3:
      *a2 = 16;
      *a3 = 28672;
      *a4 = 4;
      *a5 = 28704;
      *a6 = 198;
      result = 0;
      break;
    case 7:
      *a2 = 848;
      *a3 = 0;
      *a4 = 0;
      *a5 = 36864;
      *a6 = 34;
      result = 0;
      break;
    case 8:
      *a2 = 992;
      *a3 = 0;
      *a4 = 0;
      *a5 = 40960;
      *a6 = 36;
      result = 0;
      break;
    default:
      v8 = a1;
      v6 = (const void *)sub_94040A98(a1);
      sub_940407DC(3, "%p: %s: %s: bad fw_id:%d\n", v6, "SPRD_FW", "tzfw_get_ap_cfg_addr", v8);
      result = 4294901761LL;
      break;
  }
  return result;
}

/* ===== sub_9403EAE4 @ 0x9403EAE4 size 264 ===== */
__int64 __fastcall sub_9403EAE4(__int64 a1)
{
  __int64 v1; // x0
  unsigned int v2; // w19
  _DWORD *v3; // x0
  _DWORD *v4; // x1
  _DWORD *v5; // x2
  _DWORD *v6; // x0
  int i; // w3
  int *v8; // x2
  int j; // w0
  int v10; // t1
  const void *v12; // x0
  int v13; // [xsp+20h] [xbp+20h] BYREF
  int v14; // [xsp+24h] [xbp+24h] BYREF
  _DWORD *v15; // [xsp+28h] [xbp+28h] BYREF
  _DWORD *v16; // [xsp+30h] [xbp+30h] BYREF
  int *v17; // [xsp+38h] [xbp+38h] BYREF

  v1 = sub_9403E984(a1, &v15, &v16, &v13, &v17, &v14);
  v2 = v1;
  if ( (_DWORD)v1 != 0 )
  {
    v12 = (const void *)sub_94040A98(v1);
    sub_940407DC(3, "%p: %s: %s: tzfw_get_ap_cfg_addr Error(%d)\n", v12, "SPRD_FW", "tzfw_save_ap_cfg", v2);
    return v2;
  }
  else
  {
    v3 = v15;
    v4 = ++v15;
    *v3 = 1739273421;
    if ( v13 > 0 )
    {
      v5 = v16;
      v6 = v3 + 2;
      for ( i = 0; i < v13; ++i )
      {
        *(v6 - 1) = *v5++;
        v4 = v6++;
      }
      v15 = v4;
      v16 = v5;
    }
    if ( v14 > 0 )
    {
      v8 = v17;
      for ( j = 0; j < v14; ++j )
      {
        v10 = *v8++;
        *v4++ = v10;
      }
    }
    *v4 = -1145324613;
    return 0;
  }
}

/* ===== sub_9403EBEC @ 0x9403EBEC size 364 ===== */
__int64 __fastcall sub_9403EBEC(__int64 a1)
{
  int v1; // w20
  __int64 v2; // x0
  unsigned int v3; // w19
  _DWORD *v4; // x0
  int v5; // w2
  const void *v6; // x0
  const void *v8; // x0
  _DWORD *v9; // x1
  _DWORD *v10; // x0
  int v11; // w2
  _DWORD *v12; // x4
  _DWORD *v13; // x2
  int v14; // w0
  int *v15; // x1
  int v16; // t1
  int v17; // [xsp+20h] [xbp+20h] BYREF
  int v18; // [xsp+24h] [xbp+24h] BYREF
  _DWORD *v19; // [xsp+28h] [xbp+28h] BYREF
  _DWORD *v20; // [xsp+30h] [xbp+30h] BYREF
  _DWORD *v21; // [xsp+38h] [xbp+38h] BYREF

  v1 = a1;
  v2 = sub_9403E984(a1, &v19, &v20, &v17, &v21, &v18);
  v3 = v2;
  if ( (_DWORD)v2 != 0 )
  {
    v8 = (const void *)sub_94040A98(v2);
    sub_940407DC(3, "%p: %s: %s: tzfw_get_ap_cfg_addr Error(%d)\n", v8, "SPRD_FW", "tzfw_restore_ap_cfg", v3);
    return v3;
  }
  else
  {
    v4 = v19;
    if ( *v19 == 1739273421 && (v5 = v18, v19[v18 + 1 + (__int64)v17] == -1145324613) )
    {
      ++v19;
      if ( v17 > 0 )
      {
        v9 = v20;
        v10 = v4 + 2;
        v11 = 0;
        do
        {
          ++v11;
          *v9 = *(v10 - 1);
          v12 = v10;
          ++v9;
          ++v10;
        }
        while ( v17 > v11 );
        v5 = v18;
        v19 = v12;
        v20 = v9;
      }
      if ( v5 > 0 )
      {
        v13 = v21;
        v14 = 0;
        v15 = v19;
        do
        {
          v16 = *v15++;
          ++v14;
          *v13++ = v16;
        }
        while ( v18 > v14 );
      }
      return 0;
    }
    else
    {
      v6 = (const void *)sub_94040A98(v19);
      sub_940407DC(3, "%p: %s: %s: no data to restore for fw_id(%d)\n", v6, "SPRD_FW", "tzfw_restore_ap_cfg", v1);
      return 0;
    }
  }
}

/* ===== sub_9403ED58 @ 0x9403ED58 size 420 ===== */
__int64 __fastcall sub_9403ED58(__int64 a1, int a2, char a3, char a4)
{
  int v5; // w19
  int v6; // w1
  char v7; // w19
  int v8; // w5
  __int64 v9; // x1
  const void *v11; // x0
  char v12; // w19
  __int64 v13; // x1
  int v14; // w4
  __int64 v15; // x2
  __int64 v16; // x2
  int v17; // [xsp+28h] [xbp+28h]

  if ( (_DWORD)a1 == 2 )
  {
    if ( (unsigned int)a2 <= 0x4A )
    {
      v12 = 2 * (a2 & 0xF);
      v13 = 4 * (a2 >> 4);
      v14 = ~(3 << v12);
      *(_DWORD *)(v13 + 36) = *(_DWORD *)(v13 + 36) & v14 | ((a3 & 3) << v12);
      *(_DWORD *)(v13 + 56) = *(_DWORD *)(v13 + 56) & v14 | ((a4 & 3) << v12);
      return 0;
    }
    v16 = sub_94040A98(a1);
    sub_940407DC(3, "%p: %s: %s: bad SLV_FW_AON slv_id:%d\n", v16, "SPRD_FW", "tzfw_cfg_slv_fw", (unsigned int)a2);
    return 4294901764LL;
  }
  if ( (_DWORD)a1 == 3 )
  {
    v5 = a2 - 256;
    if ( (unsigned int)(a2 - 256) <= 0x120 )
    {
      v6 = v5 >> 4;
      v7 = 2 * (v5 & 0xF);
      v8 = ~(3 << v7);
      v9 = 4 * v6;
      *(_DWORD *)(v9 + 28704) = *(_DWORD *)(v9 + 28704) & v8 | ((a3 & 3) << v7);
      *(_DWORD *)(v9 + 28716) = *(_DWORD *)(v9 + 28716) & v8 | ((a4 & 3) << v7);
      return 0;
    }
    v15 = sub_94040A98(a1);
    sub_940407DC(3, "%p: %s: %s: bad SLV_FW_AP slv_id:%d\n", v15, "SPRD_FW", "tzfw_cfg_slv_fw", (unsigned int)v5);
    return 4294901764LL;
  }
  v17 = a1;
  v11 = (const void *)sub_94040A98(a1);
  sub_940407DC(3, "%p: %s: %s: bad fw_id:%d\n", v11, "SPRD_FW", "tzfw_cfg_slv_fw", v17);
  return 4294901761LL;
}

/* ===== sub_9403EEFC @ 0x9403EEFC size 380 ===== */
__int64 __fastcall sub_9403EEFC(__int64 a1, __int64 *a2)
{
  int v2; // w20
  __int64 result; // x0
  _DWORD *v5; // x20
  __int64 v6; // x5
  __int64 v7; // x4
  const void *v8; // x0

  v2 = a1 - 256;
  if ( (unsigned int)(a1 - 256) > 7 )
  {
    v8 = (const void *)sub_94040A98(a1);
    sub_940407DC(3, "%p: %s: %s: MEM_FW_PUB: seg_id: %d is invalid!\n", v8, "SPRD_FW", "tzfw_cfg_mem_fw_pub_seg", v2);
    return 4294901764LL;
  }
  else
  {
    sub_94040880(80LL * v2 - 536461264, a2, 80);
    result = 0;
    if ( v2 != 0 )
    {
      v5 = (_DWORD *)(72 * v2);
      v5[11273] = -1;
      v5[11275] = *((_DWORD *)a2 + 4);
      v5[11279] = *((_DWORD *)a2 + 8);
      v5[11283] = *((_DWORD *)a2 + 12);
      v5[11287] = *((_DWORD *)a2 + 16);
      v5[11276] = *((_DWORD *)a2 + 5);
      v5[11280] = *((_DWORD *)a2 + 9);
      v5[11284] = *((_DWORD *)a2 + 13);
      v5[11288] = *((_DWORD *)a2 + 17);
      v5[11277] = *((_DWORD *)a2 + 6);
      v5[11281] = *((_DWORD *)a2 + 10);
      v5[11285] = *((_DWORD *)a2 + 14);
      v5[11289] = *((_DWORD *)a2 + 18);
      v5[11278] = *((_DWORD *)a2 + 7);
      v5[11282] = *((_DWORD *)a2 + 11);
      v5[11286] = *((_DWORD *)a2 + 15);
      v5[11290] = *((_DWORD *)a2 + 19);
      v6 = *a2;
      v7 = a2[1];
      if ( *a2 != -1 || v7 != 0 )
      {
        v5[11274] = (unsigned __int64)(v7 - 0x80000000LL) >> 12;
        v5[11273] = (unsigned __int64)(v6 - 0x80000000LL) >> 12;
        return 0;
      }
      else
      {
        *(_QWORD *)(v5 + 11273) = (unsigned int)v6;
      }
    }
  }
  return result;
}

/* ===== sub_9403F078 @ 0x9403F078 size 96 ===== */
__int64 __fastcall sub_9403F078(__int64 a1, unsigned int a2, __int64 *a3)
{
  const void *v4; // x0
  int v5; // [xsp+18h] [xbp+18h]

  if ( (_DWORD)a1 == 10 )
    return sub_9403EEFC(a2, a3);
  v5 = a1;
  v4 = (const void *)sub_94040A98(a1);
  sub_940407DC(3, "%p: %s: %s: bad fw_id:%d\n", v4, "SPRD_FW", "tzfw_cfg_mem_fw_seg", v5);
  return 4294901761LL;
}

/* ===== sub_9403F0D8 @ 0x9403F0D8 size 312 ===== */
__int64 __fastcall sub_9403F0D8(int a1, unsigned __int64 a2)
{
  unsigned int v3; // w0
  const void *v4; // x0
  __int64 result; // x0
  unsigned __int64 v6; // x0
  __int64 v7; // kr00_8
  const void *v8; // x0
  int v9; // [xsp+18h] [xbp+18h]

  if ( (a2 & 0xFFF) != 0 )
  {
    v8 = (const void *)sub_94040A98(a2 & 0xFFF);
    sub_940407DC(3, "%p: %s: %s: dft_phy_addr is not aligned to 4K!\n", v8, "SPRD_FW", "tzfw_cfg_dft_addr");
    return 4294901767LL;
  }
  else
  {
    v3 = a1 - 2;
    v7 = v3;
    v6 = (unsigned __int64)&loc_9403F14C + 4 * jpt_9403F148[v3];
    switch ( v7 )
    {
      case 0LL:
        MEMORY[0] = a2;
        MEMORY[4] = a2;
        MEMORY[8] = a2;
        MEMORY[0xC] = a2;
        MEMORY[0x10] = a2;
        result = 0;
        break;
      case 1LL:
        MEMORY[0x7000] = a2;
        MEMORY[0x7004] = (a2 & 0x100000000LL) != 0;
        MEMORY[0x7008] = a2;
        MEMORY[0x700C] = (a2 & 0x100000000LL) != 0;
        result = 0;
        break;
      case 2LL:
      case 3LL:
      case 4LL:
      case 5LL:
      case 6LL:
        goto LABEL_3;
      case 7LL:
        MEMORY[0x1000] = (a2 >> 12) & 0x3F;
        result = 0;
        break;
      case 8LL:
        MEMORY[0xB000] = ((unsigned int)a2 >> 12) ^ 0x80000;
        result = 0;
        break;
      default:
        v6 = (unsigned int)(a1 - 2);
LABEL_3:
        v9 = a1;
        v4 = (const void *)sub_94040A98(v6);
        sub_940407DC(3, "%p: %s: %s: bad fw_id:%d\n", v4, "SPRD_FW", "tzfw_cfg_dft_addr", v9);
        result = 4294901761LL;
        break;
    }
  }
  return result;
}

/* ===== sub_9403F210 @ 0x9403F210 size 680 ===== */
__int64 sub_9403F210()
{
  _DWORD *v0; // x10
  int v1; // w9
  __int64 v2; // x0
  int v3; // w2
  _DWORD *v4; // x16
  int v5; // w7
  _DWORD *v6; // x15
  int v7; // w6
  _DWORD *v8; // x14
  int v9; // w5
  _DWORD *v10; // x8
  int v11; // w4
  _DWORD *v12; // x1

  v0 = nullptr;
  v1 = -1576947676;
  MEMORY[4] = 10;
  MEMORY[0xC] = -1576726528;
  MEMORY[0x10] = 1;
  v2 = 28;
  MEMORY[0x14] = -1576947712;
  v3 = 0;
  MEMORY[0x18] = MEMORY[0xB000];
  do
  {
    *(_DWORD *)v2 = v1;
    *(_DWORD *)(v2 + 4) = -1;
    *(_DWORD *)(v2 + 8) = v3 - 1576947668;
    *(_DWORD *)(v2 + 12) = v0[11275];
    *(_DWORD *)(v2 + 16) = v3 - 1576947664;
    *(_DWORD *)(v2 + 20) = v0[11276];
    *(_DWORD *)(v2 + 24) = v3 - 1576947660;
    *(_DWORD *)(v2 + 28) = v0[11277];
    *(_DWORD *)(v2 + 32) = v3 - 1576947656;
    *(_DWORD *)(v2 + 36) = v0[11278];
    *(_DWORD *)(v2 + 40) = v3 - 1576947652;
    *(_DWORD *)(v2 + 44) = v0[11279];
    *(_DWORD *)(v2 + 48) = v3 - 1576947648;
    *(_DWORD *)(v2 + 52) = v0[11280];
    *(_DWORD *)(v2 + 56) = v3 - 1576947644;
    *(_DWORD *)(v2 + 60) = v0[11281];
    *(_DWORD *)(v2 + 64) = v3 - 1576947640;
    *(_DWORD *)(v2 + 68) = v0[11282];
    *(_DWORD *)(v2 + 72) = v3 - 1576947636;
    *(_DWORD *)(v2 + 76) = v0[11283];
    *(_DWORD *)(v2 + 80) = v3 - 1576947632;
    v2 += 152;
    *(_DWORD *)(v2 - 68) = v0[11284];
    v4 = v0 + 11288;
    *(_DWORD *)(v2 - 64) = v3 - 1576947628;
    v5 = v3 - 1576947616;
    v6 = v0 + 11289;
    *(_DWORD *)(v2 - 60) = v0[11285];
    *(_DWORD *)(v2 - 56) = v3 - 1576947624;
    v7 = v3 - 1576947612;
    v8 = v0 + 11290;
    *(_DWORD *)(v2 - 52) = v0[11286];
    v9 = v3 - 1576947608;
    *(_DWORD *)(v2 - 48) = v3 - 1576947620;
    v10 = v0 + 11274;
    v11 = v3 - 1576947672;
    *(_DWORD *)(v2 - 44) = v0[11287];
    v12 = v0 + 11273;
    v3 += 72;
    v0 += 18;
    *(_DWORD *)(v2 - 40) = v5;
    *(_DWORD *)(v2 - 36) = *v4;
    *(_DWORD *)(v2 - 32) = v7;
    *(_DWORD *)(v2 - 28) = *v6;
    *(_DWORD *)(v2 - 24) = v9;
    *(_DWORD *)(v2 - 20) = *v8;
    *(_DWORD *)(v2 - 16) = v11;
    *(_DWORD *)(v2 - 12) = *v10;
    *(_DWORD *)(v2 - 8) = v1;
    v1 += 72;
    *(_DWORD *)(v2 - 4) = *v12;
  }
  while ( v3 != 576 );
  MEMORY[0x4DC] = -1576722432;
  MEMORY[0x4E0] = 1;
  MEMORY[8] = 1240;
  MEMORY[0x4E4] = -1145324613;
  MEMORY[0] = 1739273421;
  return 0;
}

/* ===== sub_9403F4B8 @ 0x9403F4B8 size 8 ===== */
__int64 sub_9403F4B8()
{
  return sub_94034308(24);
}

/* ===== sub_9403F4C0 @ 0x9403F4C0 size 8 ===== */
__int64 sub_9403F4C0()
{
  return sub_940343A8(24);
}

/* ===== sub_9403F4C8 @ 0x9403F4C8 size 168 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_9403F4C8(void *a1, __int64 a2)
{
  __int64 v2; // x0
  const void *v3; // x0

  off_94067B40 = a1;
  qword_94067B30 = a2;
  sub_94040888(-536461312, 0, 688);
  v2 = sub_94040894(1144);
  qword_94067B38 = v2;
  if ( v2 != 0 )
    return sub_94040888(v2, 0, 1144);
  v3 = (const void *)sub_94040A98(0);
  sub_940407DC(3, "%p: %s: %s: can NOT malloc memory for fw!\n", v3, "SPRD_FW", "tzfw_init");
  sub_940407A4(1);
  return sub_94040888(0, 0, 1144);
}

/* ===== sub_9403F570 @ 0x9403F570 size 456 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_9403F570()
{
  __int64 v0; // x0
  int v1; // w4
  unsigned int v2; // w19
  __int64 v3; // x3
  _DWORD v5[6]; // [xsp+48h] [xbp+48h] BYREF

  sub_940407DC(2, "%s:Init GPIO !\n", "GPIO_Init");
  v0 = sub_94034308(9);
  v1 = sub_9403FF34(v0);
  if ( v1 != 0 )
  {
    sub_940407DC(2, "%s:%s: mem map failed %d\n", "GPIO_Init", "GPIO_Init", v1);
    return 0xFFFFFFFFLL;
  }
  else
  {
    v2 = 0;
    sub_9403F9B4(MEMORY[0xFFFFFFFFE0047DC8]);
    dword_94067B64 = 255;
    dword_94067BA4 = 255;
    dword_94067BE4 = 255;
    dword_94067C24 = 255;
    dword_94067C64 = 255;
    dword_94067CA4 = 255;
    dword_94067CE4 = 255;
    dword_94067D24 = 255;
    dword_94067D64 = 255;
    dword_94067DA4 = 255;
    sub_9404078C(95, sub_9403F7D8, 0);
    sub_94040788(0x5Fu);
    do
    {
      while ( 1 )
      {
        sub_9403F8A8(v2, v5);
        if ( (v5[0] & 0xFFFFFFFD) == 0 && (unsigned int)sub_9403FA98(v5) != 0 && v2 != 0 )
          break;
        if ( ++v2 == 16 )
          return 0;
      }
      v3 = v2++;
      sub_940407DC(2, "%s:GPIO_Init GPIO_%lu interrupt has not been registed!\n", "GPIO_Init", v3);
      sub_9403FC28(v5);
    }
    while ( v2 != 16 );
    return 0;
  }
}

/* ===== sub_9403F738 @ 0x9403F738 size 72 ===== */
__int64 sub_9403F738()
{
  if ( (unsigned int)sub_9403F570() != 0 )
    return sub_940407DC(2, "%s:sprd_gpio_init failed[0x%x]\n", "sprd_pal_gpio_init");
  else
    return sub_940407DC(2, "%s:sprd_gpio_init successful\n", "sprd_pal_gpio_init");
}

/* ===== sub_9403F780 @ 0x9403F780 size 44 ===== */
__int64 __fastcall sub_9403F780(__int64 a1)
{
  _BYTE v2[24]; // [xsp+28h] [xbp+28h] BYREF

  sub_9403F8A8(a1, v2);
  return sub_9403FB60(v2);
}

/* ===== sub_9403F7AC @ 0x9403F7AC size 44 ===== */
__int64 __fastcall sub_9403F7AC(__int64 a1)
{
  _BYTE v2[24]; // [xsp+28h] [xbp+28h] BYREF

  sub_9403F8A8(a1, v2);
  return sub_9403FC28(v2);
}

/* ===== sub_9403F7D8 @ 0x9403F7D8 size 188 ===== */
__int64 sub_9403F7D8()
{
  unsigned int v0; // w20
  int *i; // x19
  __int64 *v2; // x22
  void (__fastcall *v3)(_QWORD, _QWORD); // x19
  unsigned int v4; // w0
  _BYTE v6[24]; // [xsp+38h] [xbp+38h] BYREF

  v0 = 0;
  for ( i = &dword_94067B64; ; i += 16 )
  {
    if ( *i != 255 )
    {
      sub_9403F8A8((unsigned int)*i, v6);
      if ( (unsigned int)sub_9403FCE8(v6) != 0 )
      {
        sub_9403FD9C(v6);
        sub_9403F7AC((unsigned int)*i);
        if ( i[8] != 0 )
          break;
      }
    }
    if ( ++v0 == 10 )
      return 1;
  }
  v2 = &qword_94067B48[8 * (unsigned __int64)v0];
  v3 = (void (__fastcall *)(_QWORD, _QWORD))v2[4];
  v4 = sub_9403FA0C(v6);
  v3(v0, v4);
  sub_9403FF04(v6);
  sub_9403F780(*((unsigned int *)v2 + 7));
  return 1;
}

/* ===== sub_9403F894 @ 0x9403F894 size 20 ===== */
__int64 *__fastcall sub_9403F894(_DWORD *a1)
{
  *a1 = 1;
  return &qword_9405C748;
}

/* ===== sub_9403F8A8 @ 0x9403F8A8 size 268 ===== */
__int64 __fastcall sub_9403F8A8(unsigned int a1, __int64 a2)
{
  __int64 *v4; // x20
  unsigned int v5; // w3
  unsigned __int64 v6; // x0
  unsigned int v7; // w1
  unsigned int v8; // w19
  __int64 *v9; // x2
  __int64 result; // x0
  unsigned int v11; // [xsp+4Ch] [xbp+4Ch] BYREF

  v11 = 0;
  v4 = sub_9403F894(&v11);
  v5 = a1 & 0xF;
  *(_WORD *)(a2 + 16) = a1 & 0xF;
  v6 = MEMORY[0xFFFFFFFFE0047DC8] + ((unsigned __int64)((a1 >> 4) & 0x1FFFFFF) << 7);
  v7 = v11;
  *(_QWORD *)(a2 + 8) = v6;
  if ( v7 == 0 )
  {
LABEL_6:
    *(_DWORD *)a2 = 3;
    return 3;
  }
  if ( v6 != *v4 )
  {
    v8 = 0;
    while ( 1 )
    {
      ++v8;
      sub_940407DC(2, "%s:GPIO_PHY_GetBaseInfo gpio_%lu can not be used\n", "GPIO_PHY_GetBaseInfo", a1);
      v9 = &v4[2 * v8];
      if ( v11 <= v8 )
        goto LABEL_6;
      if ( v4[2 * v8] == *(_QWORD *)(a2 + 8) )
      {
        v5 = *(unsigned __int16 *)(a2 + 16);
        goto LABEL_8;
      }
    }
  }
  v9 = v4;
LABEL_8:
  if ( *((_DWORD *)v9 + 2) <= v5 )
    goto LABEL_6;
  result = *((unsigned int *)v9 + 3);
  *(_DWORD *)a2 = result;
  return result;
}

/* ===== sub_9403F9B4 @ 0x9403F9B4 size 88 ===== */
__int64 *__fastcall sub_9403F9B4(__int64 a1)
{
  __int64 *result; // x0
  int v3; // [xsp+2Ch] [xbp+2Ch] BYREF

  v3 = 0;
  result = sub_9403F894(&v3);
  *result = a1;
  if ( a1 == 0 )
    return (__int64 *)sub_940407DC(2, "%s:can not get base addr!!!\n", "GPIO_PHY_SetBaseAddr");
  return result;
}

/* ===== sub_9403FA0C @ 0x9403FA0C size 140 ===== */
bool __fastcall sub_9403FA0C(__int64 a1)
{
  unsigned int v2; // w0
  _DWORD *v3; // x20

  v2 = *(_DWORD *)a1;
  v3 = *(_DWORD **)(a1 + 8);
  if ( v2 <= 2 )
    return ((1 << *(_WORD *)(a1 + 16)) & *v3) != 0;
  if ( v2 != 3 )
  {
    sub_940407DC(2, "%s:_GPIO_GetGpioDataRegAddr error\n", "_GPIO_GetGpioDataRegAddr");
    return ((1 << *(_WORD *)(a1 + 16)) & *v3) != 0;
  }
  sub_940407DC(2, "%s:_GPIO_GetGpioDataRegAddr GPIO_ID Invalid\n", "_GPIO_GetGpioDataRegAddr");
  return false;
}

/* ===== sub_9403FA98 @ 0x9403FA98 size 200 ===== */
bool __fastcall sub_9403FA98(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  _BOOL8 result; // x0

  v2 = *(_QWORD *)(a1 + 8);
  switch ( *(_DWORD *)a1 )
  {
    case 0:
    case 2:
      v3 = 24;
      goto LABEL_3;
    case 1:
      sub_940407DC(2, "%s:_GPIO_GetGpioIntMaskAddr gpo\n", "_GPIO_GetGpioIntMaskAddr");
      result = false;
      break;
    case 3:
      sub_940407DC(2, "%s:_GPIO_GetGpioIntMaskAddr GPIO_ID Invalid\n", "_GPIO_GetGpioIntMaskAddr");
      result = false;
      break;
    default:
      sub_940407DC(2, "%s:_GPIO_GetGpioIntMaskAddr error\n", "_GPIO_GetGpioIntMaskAddr");
      v3 = 0;
LABEL_3:
      result = (*(_DWORD *)(v2 + v3) & (1 << *(_WORD *)(a1 + 16))) != 0;
      break;
  }
  return result;
}

/* ===== sub_9403FB60 @ 0x9403FB60 size 200 ===== */
__int64 __fastcall sub_9403FB60(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x2
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 8);
  switch ( *(_DWORD *)a1 )
  {
    case 0:
    case 2:
      v3 = 24;
      goto LABEL_3;
    case 1:
      result = sub_940407DC(2, "%s:_GPIO_GetGpioIntMaskAddr gpo\n", "_GPIO_GetGpioIntMaskAddr");
      break;
    case 3:
      result = sub_940407DC(2, "%s:_GPIO_GetGpioIntMaskAddr GPIO_ID Invalid\n", "_GPIO_GetGpioIntMaskAddr");
      break;
    default:
      sub_940407DC(2, "%s:_GPIO_GetGpioIntMaskAddr error\n", "_GPIO_GetGpioIntMaskAddr");
      v3 = 0;
LABEL_3:
      result = *(_DWORD *)(v2 + v3) & ~(unsigned int)(1LL << *(_WORD *)(a1 + 16)) | (1 << *(_WORD *)(a1 + 16));
      *(_DWORD *)(v2 + v3) = result;
      break;
  }
  return result;
}

/* ===== sub_9403FC28 @ 0x9403FC28 size 192 ===== */
__int64 __fastcall sub_9403FC28(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x1
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 8);
  switch ( *(_DWORD *)a1 )
  {
    case 0:
    case 2:
      v3 = 24;
      goto LABEL_3;
    case 1:
      result = sub_940407DC(2, "%s:_GPIO_GetGpioIntMaskAddr gpo\n", "_GPIO_GetGpioIntMaskAddr");
      break;
    case 3:
      result = sub_940407DC(2, "%s:_GPIO_GetGpioIntMaskAddr GPIO_ID Invalid\n", "_GPIO_GetGpioIntMaskAddr");
      break;
    default:
      sub_940407DC(2, "%s:_GPIO_GetGpioIntMaskAddr error\n", "_GPIO_GetGpioIntMaskAddr");
      v3 = 0;
LABEL_3:
      result = *(_DWORD *)(v2 + v3) & ~(unsigned int)(1LL << *(_WORD *)(a1 + 16));
      *(_DWORD *)(v2 + v3) = result;
      break;
  }
  return result;
}

/* ===== sub_9403FCE8 @ 0x9403FCE8 size 180 ===== */
bool __fastcall sub_9403FCE8(__int64 a1)
{
  _DWORD *v2; // x20
  _BOOL8 result; // x0

  v2 = *(_DWORD **)(a1 + 8);
  switch ( *(_DWORD *)a1 )
  {
    case 0:
    case 2:
      v2 += 8;
      goto LABEL_3;
    case 1:
      result = false;
      break;
    case 3:
      sub_940407DC(2, "%s:GPIO_PHY_GetIntState GPIO_ID Invalid\n", "GPIO_PHY_GetIntState");
      result = false;
      break;
    default:
      sub_940407DC(2, "%s:GPIO_PHY_GetIntState error\n", "GPIO_PHY_GetIntState");
LABEL_3:
      result = (*v2 & (1 << *(_WORD *)(a1 + 16))) != 0;
      break;
  }
  return result;
}

/* ===== sub_9403FD9C @ 0x9403FD9C size 164 ===== */
__int64 __fastcall sub_9403FD9C(unsigned int *a1)
{
  unsigned int v2; // w0
  _DWORD *v3; // x20
  __int64 result; // x0
  __int64 v5; // kr00_8

  v2 = *a1;
  v3 = *((_DWORD **)a1 + 1);
  v5 = v2;
  result = (__int64)&loc_9403FE18 + 4 * jpt_9403FE14[v2];
  switch ( v5 )
  {
    case 0LL:
    case 2LL:
      v3 += 9;
      goto LABEL_3;
    case 1LL:
      return result;
    case 3LL:
      result = sub_940407DC(2, "%s:GPIO_PHY_ClearIntStatus GPIO_ID Invalid\n", "GPIO_PHY_ClearIntStatus");
      break;
    default:
      sub_940407DC(2, "%s:GPIO_PHY_ClearIntStatus error\n", "GPIO_PHY_ClearIntStatus");
LABEL_3:
      result = *v3 & ~(unsigned int)(1LL << *((_WORD *)a1 + 8)) | (1 << *((_WORD *)a1 + 8));
      *v3 = result;
      break;
  }
  return result;
}

/* ===== sub_9403FE40 @ 0x9403FE40 size 196 ===== */
__int64 __fastcall sub_9403FE40(__int64 a1)
{
  _DWORD *v2; // x20
  __int64 result; // x0

  v2 = *(_DWORD **)(a1 + 8);
  switch ( *(_DWORD *)a1 )
  {
    case 0:
      v2 += 18;
      goto LABEL_3;
    case 1:
    case 2:
      result = sub_940407DC(2, "%s:GPIO_PHY_TrigGPIDetect can not belong to GPO", "GPIO_PHY_TrigGPIDetect");
      break;
    case 3:
      result = sub_940407DC(2, "%s:GPIO_PHY_TrigGPIDetect GPIO_ID Invalid\n", "GPIO_PHY_TrigGPIDetect");
      break;
    default:
      sub_940407DC(2, "%s:GPIO_PHY_TrigGPIDetect error\n", "GPIO_PHY_TrigGPIDetect");
LABEL_3:
      result = *v2 & ~(unsigned int)(1LL << *(_WORD *)(a1 + 16)) | (1 << *(_WORD *)(a1 + 16));
      *v2 = result;
      break;
  }
  return result;
}

/* ===== sub_9403FF04 @ 0x9403FF04 size 48 ===== */
_DWORD *__fastcall sub_9403FF04(_DWORD *result)
{
  if ( *result == 0 )
    return (_DWORD *)sub_9403FE40((__int64)result);
  if ( *result > 2u )
    return (_DWORD *)sub_940407DC(2, "%s:GPIO_PHY_EnableGPIDetect error\n", "GPIO_PHY_EnableGPIDetect");
  return result;
}

/* ===== sub_9403FF34 @ 0x9403FF34 size 96 ===== */
__int64 sub_9403FF34()
{
  int v0; // w4
  __int64 result; // x0

  v0 = sub_940408CC("gpio", 839254016, 4096, 2, -536576568);
  result = 0;
  if ( v0 != 0 )
  {
    sub_940407DC(2, "%s:%s: mem map failed %d\n", "gpio_mem_map", "gpio_mem_map", v0);
    return 0xFFFFFFFFLL;
  }
  return result;
}

/* ===== sub_9403FF94 @ 0x9403FF94 size 116 ===== */
__int64 sub_9403FF94()
{
  if ( (unsigned int)sub_940408CC("hwspinlock", 855638016, 4096, 2, &qword_94067DD0) != 0 )
    return sub_940407DC(2, "%s: mem map failed %d\n");
  *MEMORY[0xFFFFFFFFE0061250] |= 0x400000u;
  return sub_940407DC(2, "sprd hwspinlock is ok!\n");
}

/* ===== sub_94040008 @ 0x94040008 size 44 ===== */
__int64 __fastcall sub_94040008(char a1)
{
  __int64 result; // x0
  __int64 v2; // [xsp+8h] [xbp-8h]

  v2 = 1000 << a1;
  do
    result = v2--;
  while ( result != 0 );
  return result;
}

/* ===== sub_94040034 @ 0x94040034 size 1420 ===== */
__int64 __fastcall sub_94040034(__int64 a1, unsigned __int8 *a2, unsigned int a3)
{
  unsigned __int8 *v4; // x1
  unsigned __int8 *v5; // x24
  __int64 v6; // x25
  unsigned int *v7; // x19
  unsigned int v8; // w0
  __int16 v9; // w0
  _DWORD *v10; // x27
  int v11; // w22
  unsigned __int8 *v12; // x21
  int v13; // w0
  int v14; // w22
  int v15; // w0
  int i; // w20
  __int16 v18; // w0
  _BYTE *v19; // x22
  int v20; // w23
  _DWORD *v21; // x20
  int v22; // w28
  int v23; // w0
  __int64 v25; // [xsp+78h] [xbp+78h]
  unsigned int v27; // [xsp+84h] [xbp+84h]

  sub_94034308(*(_DWORD *)(a1 + 56));
  if ( a3 != 0 )
  {
    v27 = a3 - 1;
    v4 = a2;
    v25 = a3 - 1 + 1LL;
    v5 = v4;
    v6 = 0;
    while ( 1 )
    {
      v7 = *(unsigned int **)(a1 + 48);
      v7[1] = 2 * *v5;
      v8 = *v7;
      if ( v27 == (_DWORD)v6 )
      {
        *v7 = v8 & 0xFFEFFFFF;
        v9 = *((_WORD *)v5 + 1);
        v10 = v7 + 2;
        v7[2] = *((_DWORD *)v5 + 1);
        if ( (v9 & 1) == 0 )
          goto LABEL_5;
      }
      else
      {
        *v7 = v8 | 0x100000;
        v18 = *((_WORD *)v5 + 1);
        v10 = v7 + 2;
        v7[2] = *((_DWORD *)v5 + 1);
        if ( (v18 & 1) == 0 )
        {
LABEL_5:
          v11 = *((_DWORD *)v5 + 1);
          v12 = *((unsigned __int8 **)v5 + 1);
          if ( v11 > 15 )
            v13 = 15;
          else
            v13 = *((_DWORD *)v5 + 1);
          *v7 &= ~8u;
          if ( v13 > 0 )
          {
            v7[4] = *v12;
            if ( v13 != 1 )
            {
              v7[4] = v12[1];
              if ( v13 != 2 )
              {
                v7[4] = v12[2];
                if ( v13 != 3 )
                {
                  v7[4] = v12[3];
                  if ( v13 != 4 )
                  {
                    v7[4] = v12[4];
                    if ( v13 != 5 )
                    {
                      v7[4] = v12[5];
                      if ( v13 != 6 )
                      {
                        v7[4] = v12[6];
                        if ( v13 != 7 )
                        {
                          v7[4] = v12[7];
                          if ( v13 != 8 )
                          {
                            v7[4] = v12[8];
                            if ( v13 != 9 )
                            {
                              v7[4] = v12[9];
                              if ( v13 != 10 )
                              {
                                v7[4] = v12[10];
                                if ( v13 != 11 )
                                {
                                  v7[4] = v12[11];
                                  if ( v13 != 12 )
                                  {
                                    v7[4] = v12[12];
                                    if ( v13 != 13 )
                                    {
                                      v7[4] = v12[13];
                                      if ( v13 == 15 )
                                        v7[4] = v12[14];
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          v14 = v11 - v13;
          *v7 |= 1u;
          while ( v14 != 0 )
          {
            if ( v14 > 15 )
              v15 = 15;
            else
              v15 = v14;
            if ( v15 > 0 )
            {
              v7[4] = *v12;
              if ( v15 != 1 )
              {
                v7[4] = v12[1];
                if ( v15 != 2 )
                {
                  v7[4] = v12[2];
                  if ( v15 != 3 )
                  {
                    v7[4] = v12[3];
                    if ( v15 != 4 )
                    {
                      v7[4] = v12[4];
                      if ( v15 != 5 )
                      {
                        v7[4] = v12[5];
                        if ( v15 != 6 )
                        {
                          v7[4] = v12[6];
                          if ( v15 != 7 )
                          {
                            v7[4] = v12[7];
                            if ( v15 != 8 )
                            {
                              v7[4] = v12[8];
                              if ( v15 != 9 )
                              {
                                v7[4] = v12[9];
                                if ( v15 != 10 )
                                {
                                  v7[4] = v12[10];
                                  if ( v15 != 11 )
                                  {
                                    v7[4] = v12[11];
                                    if ( v15 != 12 )
                                    {
                                      v7[4] = v12[12];
                                      if ( v15 != 13 )
                                      {
                                        v7[4] = v12[13];
                                        if ( v15 == 15 )
                                          v7[4] = v12[14];
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            v14 -= v15;
            v12 += v15;
            if ( (v7[5] & 8) == 0 )
            {
              for ( i = 1000; i != 0; --i )
                sub_94040008(1);
            }
          }
          goto LABEL_48;
        }
      }
      v19 = *((_BYTE **)v5 + 1);
      v20 = *((_DWORD *)v5 + 1);
      *v7 |= 8u;
      *v7 |= 1u;
      v21 = v7 + 5;
      if ( v20 != 0 )
      {
        do
        {
          v22 = 1000;
          while ( 1 )
          {
            sub_94040008(200);
            if ( (*v21 & 0x14) != 0 )
              break;
            if ( --v22 == -1 )
              goto LABEL_79;
          }
          if ( v22 != 0 )
          {
            *v21 &= ~4u;
            goto LABEL_57;
          }
LABEL_79:
          sub_940407DC(2, "Timed out in wait_for_data_ready: status=%04x\n");
          sub_940407DC(2, "I2C_CTL \t= 0x%x\n", *v7);
          sub_940407DC(2, "I2C_ADDR_CFG \t= 0x%x\n", v7[1]);
          sub_940407DC(2, "I2C_COUNT = 0x%x\n", *v10);
          sub_940407DC(2, "I2C_STATUS = 0x%x\n", *v21);
          sub_940407DC(2, "ADDR_DVD0 = 0x%x\n", v7[8]);
          sub_940407DC(2, "ADDR_DVD1 = 0x%x\n", v7[9]);
          sub_940407DC(2, "ADDR_STA0_DVD = 0x%x\n", v7[10]);
          *v7 &= ~1u;
LABEL_57:
          if ( v20 > 15 )
            v23 = 15;
          else
            v23 = v20;
          if ( v23 > 0 )
          {
            *v19 = v7[3];
            if ( v23 != 1 )
            {
              v19[1] = v7[3];
              if ( v23 != 2 )
              {
                v19[2] = v7[3];
                if ( v23 != 3 )
                {
                  v19[3] = v7[3];
                  if ( v23 != 4 )
                  {
                    v19[4] = v7[3];
                    if ( v23 != 5 )
                    {
                      v19[5] = v7[3];
                      if ( v23 != 6 )
                      {
                        v19[6] = v7[3];
                        if ( v23 != 7 )
                        {
                          v19[7] = v7[3];
                          if ( v23 != 8 )
                          {
                            v19[8] = v7[3];
                            if ( v23 != 9 )
                            {
                              v19[9] = v7[3];
                              if ( v23 != 10 )
                              {
                                v19[10] = v7[3];
                                if ( v23 != 11 )
                                {
                                  v19[11] = v7[3];
                                  if ( v23 != 12 )
                                  {
                                    v19[12] = v7[3];
                                    if ( v23 != 13 )
                                    {
                                      v19[13] = v7[3];
                                      if ( v23 == 15 )
                                        v19[14] = v7[3];
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          v20 -= v23;
          v19 += v23;
        }
        while ( v20 != 0 );
        ++v6;
        v5 += 16;
        if ( v6 == v25 )
          break;
      }
      else
      {
LABEL_48:
        ++v6;
        v5 += 16;
        if ( v6 == v25 )
          break;
      }
    }
  }
  sub_940343A8(*(_DWORD *)(a1 + 56));
  return a3;
}

/* ===== sub_940405C0 @ 0x940405C0 size 456 ===== */
__int64 sub_940405C0()
{
  int v0; // w19
  __int64 v1; // x24
  __int64 v2; // x1
  __int64 v3; // x0
  int v4; // w3
  _DWORD *v5; // x25
  int v6; // w3
  _DWORD *v7; // x4
  unsigned int v8; // w0
  unsigned int v9; // w1
  unsigned __int64 v10; // x0
  __int64 result; // x0

  v0 = 0;
  v1 = -536623216;
  do
  {
    v2 = *(_QWORD *)(v1 - 8);
    v3 = *(_QWORD *)(v1 - 16);
    *(_DWORD *)(v1 - 40) = v0;
    *(_DWORD *)(v1 - 32) = 0;
    *(_QWORD *)(v1 - 24) = qword_9405C758;
    v4 = sub_940408CC(v3, v2, 4096, 2, v1);
    if ( v4 != 0 )
    {
      result = sub_940407DC(2, "%s: mem map failed %d\n", "sprd_i2c_bus_init", v4);
    }
    else
    {
      sub_94034308(*(_DWORD *)(v1 + 8));
      v5 = *(_DWORD **)v1;
      **(_DWORD **)v1 = **(_DWORD **)v1 & 0xFFF00EBB | 0x82100;
      sub_940407DC(2, "i2c%d, freq=%d\n", *(_DWORD *)(v1 - 40), *(_DWORD *)(v1 + 12));
      v6 = *(_DWORD *)(v1 + 12);
      v7 = *(_DWORD **)v1;
      v8 = 0x18CBA80u / (4 * v6) - 1;
      v9 = 4 * v8 / 5;
      v10 = (3435973837u * (unsigned __int64)(6 * v8)) >> 32;
      v7[8] = (unsigned __int16)(v10 >> 2) | (v9 << 16);
      v7[9] = ((unsigned int)v10 >> 18) | v9 & 0x3FFF0000;
      if ( v6 == 400000 )
      {
        v7[10] = 15;
      }
      else if ( v6 == 100000 )
      {
        v7[10] = 104;
      }
      v5[11] = 1;
      v5[5] &= ~4u;
      *v5 |= 4u;
      sub_940343A8(*(_DWORD *)(v1 + 8));
      result = sub_940407DC(2, "%s is ok!\n", *(const char **)(v1 - 16));
    }
    ++v0;
    v1 += 72;
  }
  while ( v0 != 5 );
  return result;
}

/* ===== sub_94040788 @ 0x94040788 size 4 ===== */
// attributes: thunk
__int64 __fastcall sub_94040788(unsigned int a1)
{
  return sub_94023FB4(a1);
}

/* ===== sub_9404078C @ 0x9404078C size 24 ===== */
__int64 __fastcall sub_9404078C(unsigned int a1, __int64 a2, __int64 a3)
{
  sub_94023C34(a1, a2, a3);
  return 0;
}

/* ===== sub_940407A4 @ 0x940407A4 size 56 ===== */
__int64 __fastcall sub_940407A4(__int64 result)
{
  __int64 v1; // x30
  __int64 v2; // x0
  const char *v3; // x1

  if ( (_DWORD)result == 0 )
  {
    v2 = sub_9404B508(
           v1,
           "ASSERT FAILED at (%s:%d): %s\n",
           "external/lk/platform/sprd/pal/src/sprd_pal_debug.c",
           31,
           "x");
    return sub_940407DC(v2, v3);
  }
  return result;
}

/* ===== sub_940407DC @ 0x940407DC size 148 ===== */
__int64 sub_940407DC(
        unsigned int a1,
        const char *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        ...)
{
  __int64 v10; // x3
  __int64 result; // x0
  va_list va1; // [xsp+10h] [xbp+10h] BYREF
  va_list va; // [xsp+30h] [xbp+30h] BYREF

  va_start(va, a10);
  if ( a1 > 7 )
    v10 = 2;
  else
    v10 = *((unsigned int *)qword_94054AF8 + a1);
  result = MEMORY[0xFFFFFFFFE003CB98];
  if ( v10 <= MEMORY[0xFFFFFFFFE003CB98] )
  {
    va_copy(va1, va);
    return sub_9404B41C(a2, va1);
  }
  return result;
}

/* ===== sub_94040870 @ 0x94040870 size 8 ===== */
__int64 __fastcall sub_94040870(__int64 a1, __int64 a2, unsigned int a3)
{
  return sub_9404CC24(a1, a2, a3);
}

/* ===== sub_94040878 @ 0x94040878 size 4 ===== */
// attributes: thunk
__int64 __fastcall sub_94040878(__int64 a1, __int64 a2)
{
  return sub_9404CED8(a1, a2);
}

/* ===== sub_9404087C @ 0x9404087C size 4 ===== */
// attributes: thunk
__int64 sub_9404087C()
{
  return sub_9404D0E4();
}

/* ===== sub_94040880 @ 0x94040880 size 8 ===== */
__int64 __fastcall sub_94040880(__int64 a1, __int64 a2, unsigned int a3)
{
  return sub_9404CC78(a1, a2, a3);
}

/* ===== sub_94040888 @ 0x94040888 size 12 ===== */
__int64 __fastcall sub_94040888(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  return sub_9404CDC4(a1, a2, a3);
}

/* ===== sub_94040894 @ 0x94040894 size 8 ===== */
__int64 __fastcall sub_94040894(unsigned int a1)
{
  return sub_9404CBC4(a1);
}

/* ===== sub_9404089C @ 0x9404089C size 16 ===== */
__int64 __fastcall sub_9404089C(unsigned int a1, unsigned int a2)
{
  return sub_9404CBCC(a2, a1);
}

/* ===== sub_940408AC @ 0x940408AC size 4 ===== */
// attributes: thunk
__int64 __fastcall sub_940408AC(__int64 a1)
{
  return sub_9404CC20(a1);
}

/* ===== sub_940408B0 @ 0x940408B0 size 8 ===== */
__int64 __fastcall sub_940408B0(__int64 a1, unsigned int a2)
{
  return sub_940223FC(a1, a2);
}

/* ===== sub_940408B8 @ 0x940408B8 size 8 ===== */
__int64 __fastcall sub_940408B8(__int64 result, unsigned int a2)
{
  unsigned __int64 v2; // x3

  v2 = result & 0xFFFFFFFFFFFFFFE0LL;
  do
  {
    __asm { DC              CVAC, X3 }
    v2 += 32LL;
  }
  while ( v2 < result + (unsigned __int64)a2 );
  __dsb(0xFu);
  return result;
}

/* ===== sub_940408C0 @ 0x940408C0 size 8 ===== */
__int64 __fastcall sub_940408C0(__int64 a1, unsigned int a2)
{
  return sub_9402241C(a1, a2);
}

/* ===== sub_940408C8 @ 0x940408C8 size 4 ===== */
// attributes: thunk
__int64 __fastcall sub_940408C8(__int64 a1)
{
  return sub_9404A248(a1);
}

/* ===== sub_940408CC @ 0x940408CC size 40 ===== */
__int64 __fastcall sub_940408CC(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, __int64 a5)
{
  return sub_9404A878(-536460256, a1, a3, a5, 12, a2, 0, a4);
}

/* ===== sub_940408F4 @ 0x940408F4 size 16 ===== */
__int64 __fastcall sub_940408F4(__int64 a1)
{
  return sub_9404ABDC(-536460256, a1);
}

/* ===== sub_94040904 @ 0x94040904 size 56 ===== */
__int64 __fastcall sub_94040904(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int8 a4,
        unsigned int a5,
        unsigned int a6)
{
  return sub_9404AA04(-536460256, a1, a2, a3, a4, a5, a6);
}

/* ===== sub_9404093C @ 0x9404093C size 48 ===== */
__int64 sub_9404093C()
{
  __int64 v0; // x0
  __int64 v1; // x19

  v0 = sub_9404CBC4(56);
  v1 = v0;
  if ( v0 != 0 )
    sub_940251C4(v0);
  return v1;
}

/* ===== sub_9404096C @ 0x9404096C size 8 ===== */
__int64 __fastcall sub_9404096C(__int64 a1)
{
  return sub_940251F8(a1, 0xFFFFFFFFLL);
}

/* ===== sub_94040974 @ 0x94040974 size 4 ===== */
// attributes: thunk
__int64 __fastcall sub_94040974(__int64 a1)
{
  return sub_9402530C(a1);
}

/* ===== sub_94040978 @ 0x94040978 size 64 ===== */
unsigned __int64 *__fastcall sub_94040978(unsigned __int64 *result, int *a2, int a3)
{
  int v3; // w3

  v3 = 0;
  if ( (a3 & 0x40000000) != 0 && (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v3 = 1;
    if ( (a3 & 0x80000000) == 0 )
      goto LABEL_4;
  }
  else if ( (a3 & 0x80000000) == 0 )
  {
    goto LABEL_4;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) == 0 )
  {
    __asm { MSR             DAIFSet, #1 }
    *a2 = v3 | 2;
    return sub_940223B4(result);
  }
LABEL_4:
  *a2 = v3;
  return sub_940223B4(result);
}

/* ===== sub_940409B8 @ 0x940409B8 size 64 ===== */
unsigned __int64 *__fastcall sub_940409B8(unsigned __int64 *a1, char a2, int a3)
{
  unsigned __int64 *result; // x0

  result = sub_940223D4(a1);
  if ( a3 < 0 && (a2 & 2) != 0 )
    __asm { MSR             DAIFClr, #1 }
  if ( (a3 & 0x40000000) != 0 && (a2 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  return result;
}

/* ===== sub_940409F8 @ 0x940409F8 size 60 ===== */
__int64 __fastcall sub_940409F8(int a1)
{
  __int64 v1; // x0
  __int64 v2; // x19

  v1 = sub_9404CBC4(40);
  v2 = v1;
  if ( v1 != 0 )
    sub_94028150(v1, a1);
  return v2;
}

/* ===== sub_94040A34 @ 0x94040A34 size 64 ===== */
__int64 __fastcall sub_94040A34(__int64 a1)
{
  if ( a1 == 0 )
    return 1;
  sub_94028180(a1);
  sub_9404CC20(a1);
  return 0;
}

/* ===== sub_94040A74 @ 0x94040A74 size 8 ===== */
__int64 __fastcall sub_94040A74(__int64 a1)
{
  return sub_940282F8(a1, 0xFFFFFFFFLL);
}

/* ===== sub_94040A7C @ 0x94040A7C size 12 ===== */
__int64 __fastcall sub_94040A7C(__int64 a1, int a2)
{
  return sub_94028204(a1, a2 != 0);
}

/* ===== sub_94040A88 @ 0x94040A88 size 4 ===== */
// attributes: thunk
unsigned __int64 *__fastcall sub_94040A88(unsigned int a1)
{
  return sub_940263B8(a1);
}

/* ===== sub_94040A8C @ 0x94040A8C size 8 ===== */
__int64 __fastcall sub_94040A8C(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, unsigned int a5)
{
  return sub_940268B8(a1, a2, a3, a4, a5);
}

/* ===== sub_94040A94 @ 0x94040A94 size 4 ===== */
// attributes: thunk
unsigned __int64 *__fastcall sub_94040A94(_DWORD *a1)
{
  return sub_940260B0(a1);
}

/* ===== sub_94040A98 @ 0x94040A98 size 8 ===== */
unsigned __int64 sub_94040A98()
{
  return _ReadStatusReg(TPIDR_EL1);
}

/* ===== sub_94040AA0 @ 0x94040AA0 size 36 ===== */
unsigned __int64 sub_94040AA0()
{
  unsigned __int64 StatusReg; // x1

  StatusReg = _ReadStatusReg(MPIDR_EL1);
  if ( (StatusReg & 0x1000000) != 0 )
    StatusReg >>= 8;
  return (unsigned __int8)StatusReg | (4 * ((StatusReg >> 8) & 0xF));
}

/* ===== sub_94040AC4 @ 0x94040AC4 size 20 ===== */
__int64 __fastcall sub_94040AC4(__int64 a1)
{
  return sub_9404CFF4(a1);
}

/* ===== sub_94040AD8 @ 0x94040AD8 size 76 ===== */
__int64 sub_94040AD8()
{
  __int64 result; // x0

  result = sub_9402D420(9u, (__int64)qword_9405C8C8);
  if ( (_DWORD)result != 0 && MEMORY[0xFFFFFFFFE003CB98] > 1 )
    return sub_9404B2FC("can not install sprd_rpmb_op in handler: %d\n", result);
  return result;
}

/* ===== sub_94040B24 @ 0x94040B24 size 184 ===== */
__int64 __fastcall sub_94040B24(__int64 a1, int a2, unsigned int a3)
{
  unsigned int v3; // w19

  if ( a3 == 0 )
    return (unsigned int)-8;
  if ( a2 != 0 )
  {
    if ( a2 != 1 )
      return (unsigned int)-24;
    sub_9404D224(a3, &dword_9405C8E0, 4);
    return 4;
  }
  else
  {
    v3 = -1;
    if ( MEMORY[0xFFFFFFFFE003CB98] <= 1 )
      return v3;
    sub_9404B2FC("uboot don't set rpmb size, return error\n", &qword_94067DD8);
    return 0xFFFFFFFFLL;
  }
}

/* ===== sub_94040BDC @ 0x94040BDC size 264 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_94040BDC(__int64 a1)
{
  unsigned int v1; // w21
  int v2; // w19
  __int64 result; // x0
  __int64 *v4; // x1
  __int64 v5; // x0
  int v6; // w20
  __int64 *v7; // [xsp+38h] [xbp+38h] BYREF

  v1 = *(_DWORD *)(a1 + 8);
  v7 = nullptr;
  v2 = sub_9404A878(-536460256, "sprdrpmbsize", 4096, &v7, 12, v1, 0, 48);
  if ( v2 != 0 )
  {
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      sub_9404B2FC("can not map phy 0x%x , ret:%d\n", v1, v2);
    return v2;
  }
  else
  {
    v4 = v7;
    v5 = *v7;
    qword_94067DD8 = *v7;
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
    {
      sub_9404B2FC((const char *)&loc_94054BA8, v5);
      v4 = v7;
    }
    v6 = sub_9404ABDC(-536460256, v4);
    result = 0;
    if ( v6 != 0 )
    {
      if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
        sub_9404B2FC("can not unmap virt addr, ret:%d\n", v6);
      return v6;
    }
  }
  return result;
}

/* ===== sub_94040CE4 @ 0x94040CE4 size 264 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_94040CE4(__int64 a1)
{
  unsigned int v1; // w21
  int v2; // w19
  __int64 result; // x0
  int *v4; // x1
  int v5; // w0
  int v6; // w20
  int *v7; // [xsp+38h] [xbp+38h] BYREF

  v1 = *(_DWORD *)(a1 + 8);
  v7 = nullptr;
  v2 = sub_9404A878(-536460256, "sprdisrpmbkey", 4096, &v7, 12, v1, 0, 48);
  if ( v2 != 0 )
  {
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
      sub_9404B2FC("can not map phy 0x%x , ret:%d\n", v1, v2);
    return v2;
  }
  else
  {
    v4 = v7;
    v5 = *v7;
    dword_9405C8E0 = *v7;
    if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
    {
      sub_9404B2FC("is written rpmb key %d\n", v5);
      v4 = v7;
    }
    v6 = sub_9404ABDC(-536460256, v4);
    result = 0;
    if ( v6 != 0 )
    {
      if ( MEMORY[0xFFFFFFFFE003CB98] > 1 )
        sub_9404B2FC("can not unmap virt addr, ret:%d\n", v6);
      return v6;
    }
  }
  return result;
}

/* ===== sub_94040DEC @ 0x94040DEC size 68 ===== */
unsigned __int64 sub_94040DEC()
{
  return 1000 * (0xFFFF00000000LL - *(_QWORD *)(MEMORY[0xFFFFFFFFE0047DE0] + 24LL)) / 0x21uLL;
}

/* ===== sub_94040E30 @ 0x94040E30 size 204 ===== */
__int64 sub_94040E30()
{
  _DWORD *v0; // x0
  __int64 result; // x0

  if ( MEMORY[0xFFFFFFFFE0047DE8] != 0
    || (_DWORD)(result = sub_940408CC((__int64)"sprd_timer_secure", 839188480, 0x10000u, 2u, -536576536)) == 0 )
  {
    v0 = (_DWORD *)MEMORY[0xFFFFFFFFE0047DE0];
    if ( MEMORY[0xFFFFFFFFE0047DE0] == 0 )
    {
      result = sub_940408CC((__int64)"sprd_timer_secure", 838991872, 0x10000u, 2u, -536576544);
      if ( (_DWORD)result != 0 )
        return result;
      v0 = (_DWORD *)MEMORY[0xFFFFFFFFE0047DE0];
    }
    *MEMORY[0xFFFFFFFFE0047DE8] |= 6u;
    *v0 = 0;
    v0[1] = 0xFFFF;
    v0[4] |= 0x10001u;
    v0[4] |= 2u;
    result = -536577768;
    MEMORY[0xFFFFFFFFE0047918] = (__int64 (*)(void))-536736276LL;
  }
  return result;
}

/* ===== sub_94040EFC @ 0x94040EFC size 48 ===== */
__int64 __fastcall sub_94040EFC(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  __int64 result; // x0

  result = -536576248;
  if ( MEMORY[0xFFFFFFFFE0047F08] != 0 )
    return sub_940407DC(2u, "SECUREBOOTDataVal is not NULL.\n", a1, a2, a3, a4, a5, a6, a7, a8);
  MEMORY[0xFFFFFFFFE0047F08] = -536460568;
  return result;
}

/* ===== sub_94040F2C @ 0x94040F2C size 240 ===== */
__int64 __fastcall sub_94040F2C(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x2
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w0
  const char *v43; // x1

  sub_940407DC(2u, "sprd_kbc_init() enter.\n", a1, a2, a3, a4, a5, a6, a7, a8);
  sub_940407DC(2u, "map size = %d \n", v8, v9, v10, v11, v12, v13, v14, v15, 0x10000);
  sub_940407DC(2u, "CTL_BASE_AON_APB = %p \n", v16, v17, v18, v19, v20, v21, v22, v23, 1076756480);
  v24 = sub_940408CC((__int64)"sprdsec", 1076559872, 0x10000u, 2u, (__int64)&qword_94067DF0);
  v33 = v24;
  if ( v24 != 0
    || (sub_940407DC(2u, "pmu_vaddr = %p \n", v25, v26, v27, v28, v29, v30, v31, v32, 0),
        sub_940407DC(2u, "CTL_BASE_PMU_APB = %p \n", v34, v35, v36, v37, v38, v39, v40, v41, 1076559872),
        v42 = sub_940408CC((__int64)"sprdsec", 1076756480, 0x10000u, 2u, (__int64)&qword_94067DF8),
        v33 = v42,
        v42 != 0) )
  {
    v43 = "can not map, err = %d \n";
  }
  else
  {
    v33 = 0;
    v43 = "aon_vaddr = %p \n";
  }
  return sub_940407DC(2u, v43, v25, v26, v27, v28, v29, v30, v31, v32, v33);
}

/* ===== sub_9404101C @ 0x9404101C size 204 ===== */
__int64 __fastcall sub_9404101C(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  __int64 v22; // x19
  __int64 v23; // x2
  __int64 v24; // x2
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  sub_940407DC(2u, "%s", a4, a5, a6, a7, a8, a9, a10, a11, a1);
  if ( a3 > 0 )
  {
    v21 = (unsigned int)(a3 - 1) + 1LL;
    v22 = 0;
    do
    {
      while ( (v22 & 0xF) != 0 )
      {
        v23 = *(unsigned __int8 *)(a2 + v22++);
        sub_940407DC(2u, " %02x", v13, v14, v15, v16, v17, v18, v19, v20, v23);
        if ( v22 == v21 )
          return sub_940407DC(2u, "\n", v13, v14, v15, v16, v17, v18, v19, v20);
      }
      sub_940407DC(2u, "\n%04x", v13, v14, v15, v16, v17, v18, v19, v20, (unsigned int)v22);
      v24 = *(unsigned __int8 *)(a2 + v22++);
      sub_940407DC(2u, " %02x", v25, v26, v27, v28, v29, v30, v31, v32, v24);
    }
    while ( v22 != v21 );
  }
  return sub_940407DC(2u, "\n", v13, v14, v15, v16, v17, v18, v19, v20);
}

/* ===== sub_940410E8 @ 0x940410E8 size 368 ===== */
__int64 __fastcall sub_940410E8(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w19
  __int64 v10; // x3
  unsigned int v11; // w19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x21
  unsigned int v21; // w19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w19
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  __int64 v40; // [xsp+40h] [xbp+40h] BYREF
  __int64 *v41; // [xsp+48h] [xbp+48h] BYREF

  v9 = *(_DWORD *)(a1 + 8);
  v10 = *(unsigned int *)(a1 + 12);
  v41 = nullptr;
  v40 = 0;
  sub_940407DC(2u, "from uboot smc...addr:0x%x len:0x%x\n", a2, a3, a4, a5, a6, a7, a8, a9, v9, v10);
  v11 = sub_940408CC((__int64)"sprdsec", v9, 0x1000u, 0x30u, (__int64)&v41);
  if ( v11 != 0 )
  {
    sub_940407DC(2u, "can not map phy addr 1 , ret:%d\n", v12, v13, v14, v15, v16, v17, v18, v19, v11);
    return (int)v11;
  }
  else
  {
    v20 = v41[1];
    sub_940407DC(
      2u,
      "from uboot smc...addr:0x%x len:0x%x\n",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      *v41,
      (unsigned int)v20);
    v21 = sub_940408CC((__int64)"sprdsec", *v41, ((unsigned int)v20 & 0xFFFFF000) + 4096, 0x30u, (__int64)&v40);
    if ( v21 != 0 )
    {
      sub_940407DC(2u, "can not map phy addr 2 , ret:%d\n", v22, v23, v24, v25, v26, v27, v28, v29, v21);
      return (int)v21;
    }
    else
    {
      sub_940407DC(2u, "##before process_ns_save_hubkey##### \n", v22, v23, v24, v25, v26, v27, v28, v29);
      sub_940427A4(v40);
      v30 = sub_940408F4((__int64)v41);
      if ( v30 != 0 || (v30 = sub_940408F4(v40), result = 0, v30 != 0) )
      {
        sub_940407DC(2u, "can not unmap virt addr, ret:%d\n", v31, v32, v33, v34, v35, v36, v37, v38, v30);
        return (int)v30;
      }
    }
  }
  return result;
}

/* ===== sub_94041258 @ 0x94041258 size 532 ===== */
__int64 __fastcall sub_94041258(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x21
  unsigned int v28; // w19
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w19
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w19
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 result; // x0
  __int64 v66; // [xsp+58h] [xbp+58h] BYREF
  __int64 v67; // [xsp+60h] [xbp+60h] BYREF
  __int64 *v68; // [xsp+68h] [xbp+68h] BYREF

  v68 = nullptr;
  v66 = 0;
  v67 = 0;
  sub_94040EFC(a2, a3, a4, a5, a6, a7, a8, a9);
  v9 = *(_DWORD *)(a1 + 8);
  sub_940407DC(
    2u,
    "from uboot smc...addr:0x%x len:0x%x\n",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v9,
    *(unsigned int *)(a1 + 12));
  v18 = sub_940408CC((__int64)"sprdsec", v9, 0x1000u, 0x30u, (__int64)&v68);
  if ( v18 != 0 )
  {
    sub_940407DC(2u, "can not map phy addr 1 , ret:%d\n", v19, v20, v21, v22, v23, v24, v25, v26, v18);
    return (int)v18;
  }
  else
  {
    v27 = v68[1];
    sub_940407DC(
      2u,
      "from uboot smc...addr:0x%x len:0x%x\n",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      *v68,
      (unsigned int)v27);
    v28 = sub_940408CC((__int64)"sprdsec", *v68, ((unsigned int)v27 & 0xFFFFF000) + 4096, 0x30u, (__int64)&v66);
    if ( v28 != 0 )
    {
      sub_940407DC(2u, "can not map phy addr 2 , ret:%d\n", v29, v30, v31, v32, v33, v34, v35, v36, v28);
      return (int)v28;
    }
    else
    {
      sub_940407DC(
        2u,
        "from uboot smc...addr:0x%x len:0x%x flag:0x%x\n",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v68[2],
        *((unsigned int *)v68 + 6),
        v68[4]);
      v37 = sub_940408CC((__int64)"sprdsec", v68[2], 0x1000u, 0x30u, (__int64)&v67);
      if ( v37 != 0 )
      {
        sub_940407DC(2u, "can not map phy addr 3 , ret:%d\n", v38, v39, v40, v41, v42, v43, v44, v45, v37);
        return (int)v37;
      }
      else
      {
        sub_940407DC(2u, (const char *)&loc_94054DA8, v38, v39, v40, v41, v42, v43, v44, v45);
        v46 = sub_9404236C(v67, v66);
        sub_940407DC(2u, "sprd_verify_img , ret:%d\n", v47, v48, v49, v50, v51, v52, v53, v54, v46);
        v55 = sub_940408F4((__int64)v68);
        if ( v55 != 0 || (v55 = sub_940408F4(v66)) != 0 || (v55 = sub_940408F4(v67), result = 0, v55 != 0) )
        {
          sub_940407DC(2u, "can not unmap virt addr, ret:%d\n", v56, v57, v58, v59, v60, v61, v62, v63, v55);
          return (int)v55;
        }
      }
    }
  }
  return result;
}

/* ===== sub_9404146C @ 0x9404146C size 464 ===== */
__int64 __fastcall sub_9404146C(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x19
  unsigned int v11; // w20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x0
  unsigned int v38; // w21
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned int v63; // w21
  __int64 v64; // [xsp+58h] [xbp+58h] BYREF

  v64 = 0;
  sub_940407DC(2u, "kbc_image_verify() enter.\n", a2, a3, a4, a5, a6, a7, a8, a9);
  v10 = a1 + 112;
  v11 = 0;
  sub_9404101C((__int64)"pubkhash:", MEMORY[0xFFFFFFFFE0047F08] + 32LL, 32, v12, v13, v14, v15, v16, v17, v18, v19);
  while ( 1 )
  {
    if ( *(_QWORD *)(v10 - 112) == 0 )
    {
      sub_940407DC(2u, "invalid image [%d]\n", v20, v21, v22, v23, v24, v25, v26, v27, v11);
      if ( v11 == 3 )
        goto LABEL_5;
      goto LABEL_4;
    }
    sub_940407DC(
      2u,
      (const char *)&loc_94054E30,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      *(_QWORD *)(v10 - 112),
      *(unsigned int *)(v10 - 100));
    v38 = sub_940408CC(
            (__int64)"sprdsec",
            *(_QWORD *)(v10 - 112),
            (*(_DWORD *)(v10 - 100) & 0xFFFFF000) + 4096,
            0x19u,
            (__int64)&v64);
    if ( v38 != 0 )
    {
      sub_940407DC(2u, "can not map, ret = %d \n", v39, v40, v41, v42, v43, v44, v45, v46, v38);
      return (int)v38;
    }
    sub_940407DC(2u, "after map:pAddr = %p\n", v39, v40, v41, v42, v43, v44, v45, v46, v64);
    sub_940407DC(
      2u,
      "after map:pAddr = %p, img_len = 0x%x\n",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v64,
      *(unsigned int *)(v10 - 104));
    sub_9404263C(MEMORY[0xFFFFFFFFE0047F08] + 32LL, v64, *(unsigned int *)(v10 - 104));
    sub_940407DC(2u, (const char *)&loc_94054EA0, v55, v56, v57, v58, v59, v60, v61, v62, v64);
    v63 = sub_940408F4(v64);
    if ( v63 != 0 )
      break;
    if ( v11 == 3 )
    {
LABEL_5:
      sub_940407DC(2u, "secboot_verify return success\n", v20, v21, v22, v23, v24, v25, v26, v27);
      v36 = sub_940407DC(2u, "will update version\n", v28, v29, v30, v31, v32, v33, v34, v35);
      sub_94041A38(v36);
      return 0;
    }
LABEL_4:
    ++v11;
    v10 += 112;
    if ( v11 == 4 )
      goto LABEL_5;
  }
  sub_940407DC(2u, "can not unmap virt addr, ret = %d \n", v20, v21, v22, v23, v24, v25, v26, v27, v63);
  return (int)v63;
}

/* ===== sub_9404163C @ 0x9404163C size 108 ===== */
__int64 __fastcall sub_9404163C(
        unsigned int *a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  sub_940407DC(2u, "reg_addr = %p\n", a3, a4, a5, a6, a7, a8, a9, a10, a1);
  sub_940407DC(2u, (const char *)sub_94054F40, v12, v13, v14, v15, v16, v17, v18, v19, *a1);
  *a1 |= 1 << a2;
  return sub_940407DC(2u, (const char *)sub_94054F58, v20, v21, v22, v23, v24, v25, v26, v27, *a1);
}

/* ===== sub_940416A8 @ 0x940416A8 size 108 ===== */
__int64 __fastcall sub_940416A8(
        unsigned int *a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  sub_940407DC(2u, "reg_addr = %p\n", a3, a4, a5, a6, a7, a8, a9, a10, a1);
  sub_940407DC(2u, (const char *)sub_94054F40, v12, v13, v14, v15, v16, v17, v18, v19, *a1);
  *a1 &= ~(1 << a2);
  return sub_940407DC(2u, (const char *)sub_94054F58, v20, v21, v22, v23, v24, v25, v26, v27, *a1);
}

/* ===== sub_94041714 @ 0x94041714 size 140 ===== */
__int64 __fastcall sub_94041714(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  sub_940407DC(2u, "kbc_start_cp() enter \n", a1, a2, a3, a4, a5, a6, a7, a8);
  sub_940416A8((unsigned int *)0x48, 25, v8, v9, v10, v11, v12, v13, v14, v15);
  sub_940416A8((unsigned int *)0xCC, 18, v16, v17, v18, v19, v20, v21, v22, v23);
  sub_940416A8((unsigned int *)0x284, 10, v24, v25, v26, v27, v28, v29, v30, v31);
  sub_940416A8((unsigned int *)0xB0, 1, v32, v33, v34, v35, v36, v37, v38, v39);
  return sub_940407DC(2u, "kbc_start_cp() enter \n", v40, v41, v42, v43, v44, v45, v46, v47);
}

/* ===== sub_940417A0 @ 0x940417A0 size 140 ===== */
__int64 __fastcall sub_940417A0(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  sub_940407DC(2u, "kbc_stop_cp() enter \n", a1, a2, a3, a4, a5, a6, a7, a8);
  sub_9404163C((unsigned int *)0x284, 10, v8, v9, v10, v11, v12, v13, v14, v15);
  sub_9404163C((unsigned int *)0xB0, 1, v16, v17, v18, v19, v20, v21, v22, v23);
  sub_9404163C((unsigned int *)0xCC, 18, v24, v25, v26, v27, v28, v29, v30, v31);
  sub_9404163C((unsigned int *)0x48, 25, v32, v33, v34, v35, v36, v37, v38, v39);
  return sub_940407DC(2u, "kbc_stop_cp() leave \n", v40, v41, v42, v43, v44, v45, v46, v47);
}

/* ===== sub_9404182C @ 0x9404182C size 156 ===== */
__int64 __fastcall sub_9404182C(__int64 a1)
{
  __int64 v1; // x1
  int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  unsigned int *v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int *v22; // [xsp+28h] [xbp+28h] BYREF

  v1 = *(unsigned int *)(a1 + 8);
  v22 = nullptr;
  v2 = sub_940408CC((__int64)"fastboot", v1, 0x1000u, 0x30u, (__int64)&v22);
  v11 = v2;
  if ( v2 != 0 )
  {
    sub_940407DC(
      2u,
      "process_sip_call, case FUNCTYPE_GET_LCS can not map phy addr error:%ld\n",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v2);
  }
  else
  {
    v12 = v22;
    v11 = (unsigned int)sub_9403CA20(v22);
    sub_940407DC(
      2u,
      "process_sip_call, case FUNCTYPE_GET_LCS res:%ld, tmp is %d\n",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v11,
      *v12);
    sub_940408F4((__int64)v22);
  }
  return v11;
}

/* ===== sub_940418C8 @ 0x940418C8 size 148 ===== */
__int64 __fastcall sub_940418C8(__int64 a1)
{
  __int64 v1; // x1
  int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v21; // [xsp+28h] [xbp+28h] BYREF

  v1 = *(unsigned int *)(a1 + 8);
  v21 = 0;
  v2 = sub_940408CC((__int64)"fastboot", v1, 0x1000u, 0x30u, (__int64)&v21);
  v11 = v2;
  if ( v2 != 0 )
  {
    sub_940407DC(
      2u,
      "process_sip_call, case FUNCTYPE_GET_LCS can not map phy addr error:%ld\n",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v2);
  }
  else
  {
    v11 = (int)sub_94037A1C(v21);
    sub_940407DC(
      2u,
      "process_sip_call, case FUNCTYPE_GET_SOCID, res is:%ld\n",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v11);
    sub_940408F4(v21);
  }
  return v11;
}

/* ===== sub_9404195C @ 0x9404195C size 56 ===== */
__int64 sub_9404195C()
{
  __int64 v0; // x19
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7

  v0 = (unsigned int)sub_9403CA04();
  sub_940407DC(2u, "process_sip_call, case FUNCTYPE_SET_RMA, res is:%ld\n", v1, v2, v3, v4, v5, v6, v7, v8, v0);
  return v0;
}

/* ===== sub_94041994 @ 0x94041994 size 164 ===== */
__int64 __fastcall sub_94041994(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  sub_940407DC(1u, "%s(): ", a4, a5, a6, a7, a8, a9, a10, a11, "cal_sha256");
  sub_940407DC(1u, "enter cal_sha256 \r\n", v14, v15, v16, v17, v18, v19, v20, v21);
  if ( a1 != 0 && a3 != 0 )
    return sub_94037850(a1, a2, a3);
  sub_940407DC(1u, "%s(): ", v22, v23, v24, v25, v26, v27, v28, v29, "cal_sha256");
  return sub_940407DC(1u, "\r\tthe pointer is error,pls check it\n", v31, v32, v33, v34, v35, v36, v37, v38);
}

/* ===== sub_94041A38 @ 0x94041A38 size 604 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_94041A38(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w1
  unsigned int v57; // w19
  int v58; // w2
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  const char *v92; // x1

  sub_940407DC(1u, "%s(): ", a1, a2, a3, a4, a5, a6, a7, a8, "update_sec_version");
  sub_940407DC(1u, (const char *)&loc_94055108, v8, v9, v10, v11, v12, v13, v14, v15);
  sub_940407DC(1u, "%s(): ", v16, v17, v18, v19, v20, v21, v22, v23, "update_sec_version");
  sub_940407DC(1u, "reset index \r\n", v24, v25, v26, v27, v28, v29, v30, v31);
  dword_94067E00 = 0;
  sub_940407DC(1u, "%s(): ", v32, v33, v34, v35, v36, v37, v38, v39, "update_sec_version");
  sub_940407DC(
    1u,
    "num = %d \r\n",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    *(unsigned int *)(MEMORY[0xFFFFFFFFE0047F08] + 148LL));
  v56 = *(_DWORD *)(MEMORY[0xFFFFFFFFE0047F08] + 148LL);
  if ( v56 != 0 )
  {
    v57 = *(_DWORD *)(MEMORY[0xFFFFFFFFE0047F08] + 72LL);
    if ( v56 <= 1
      || *(_DWORD *)(MEMORY[0xFFFFFFFFE0047F08] + 80LL) == v57
      && (v56 == 2
       || (v58 = *(_DWORD *)(MEMORY[0xFFFFFFFFE0047F08] + 88LL)) == v57
       && (v56 == 3
        || v58 == *(_DWORD *)(MEMORY[0xFFFFFFFFE0047F08] + 96LL)
        && (v56 == 4
         || v58 == *(_DWORD *)(MEMORY[0xFFFFFFFFE0047F08] + 104LL)
         && (v56 == 5
          || v58 == *(_DWORD *)(MEMORY[0xFFFFFFFFE0047F08] + 112LL)
          && (v56 == 6
           || v58 == *(_DWORD *)(MEMORY[0xFFFFFFFFE0047F08] + 120LL)
           && (v56 == 7
            || v58 == *(_DWORD *)(MEMORY[0xFFFFFFFFE0047F08] + 128LL)
            && (v56 == 8
             || v58 == *(_DWORD *)(MEMORY[0xFFFFFFFFE0047F08] + 136LL)
             && (v56 == 9 || v58 == *(_DWORD *)(MEMORY[0xFFFFFFFFE0047F08] + 144LL))))))))) )
    {
      sub_940407DC(1u, "%s(): ", v48, v49, v50, v51, v52, v53, v54, v55, "update_sec_version");
      sub_940407DC(1u, "nosecure_update_version = %d \r\n", v59, v60, v61, v62, v63, v64, v65, v66, v57);
      if ( v57 > 0xFFFF )
      {
        sub_940407DC(1u, "%s(): ", v67, v68, v69, v70, v71, v72, v73, v74, "update_sec_version");
        sub_940407DC(1u, (const char *)&loc_94055188, v75, v76, v77, v78, v79, v80, v81, v82);
        return sub_9403C8DC(1, v57);
      }
      sub_940407DC(1u, "%s(): ", v67, v68, v69, v70, v71, v72, v73, v74, "update_sec_version");
      v92 = "no need to update \r\n";
    }
    else
    {
      sub_940407DC(1u, "%s(): ", v48, v49, v50, v51, v52, v53, v54, v55, "update_sec_version");
      v92 = "\r\rollback version not unified\n";
    }
  }
  else
  {
    sub_940407DC(1u, "%s(): ", v48, v49, v50, v51, v52, v53, v54, v55, "update_sec_version");
    v92 = "version num is 0 ! \r\n";
  }
  return sub_940407DC(1u, v92, v84, v85, v86, v87, v88, v89, v90, v91);
}

/* ===== sub_94041C94 @ 0x94041C94 size 604 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_94041C94(
        unsigned int a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w19
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7

  sub_940407DC(1u, "%s(): ", a3, a4, a5, a6, a7, a8, a9, a10, "sprd_anti_rollback");
  sub_940407DC(1u, "image type = %d\n", v12, v13, v14, v15, v16, v17, v18, v19, a1);
  if ( a1 == 1 )
  {
    sub_9403C82C(0, &dword_9405C8E8);
    sub_940407DC(1u, "%s(): ", v102, v103, v104, v105, v106, v107, v108, v109, "sprd_anti_rollback");
    sub_940407DC(1u, "read efuse version: 0X%x\n", v110, v111, v112, v113, v114, v115, v116, v117, 4660);
    v36 = 1;
    sub_940407DC(1u, "%s(): ", v46, v47, v48, v49, v50, v51, v52, v53, "sprd_anti_rollback");
    sub_940407DC(
      1u,
      "Trusted_rollback_version = 0X%x  certversion = 0X%x\n",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      4660,
      a2);
    if ( a2 < 0x1234 )
    {
      sub_940407DC(1u, "%s(): ", v62, v63, v64, v65, v66, v67, v68, v69, "sprd_anti_rollback");
      v36 = 0;
      sub_940407DC(1u, "SEC ANTI_ROLLBACK ERR version = 0X%x\n", v70, v71, v72, v73, v74, v75, v76, v77, a2);
    }
    return v36;
  }
  if ( a1 == 0 )
  {
    sub_9403C82C(1, &dword_9405C8E4);
    sub_940407DC(1u, "%s(): ", v86, v87, v88, v89, v90, v91, v92, v93, "sprd_anti_rollback");
    sub_940407DC(1u, "version efuse: %d\n", v94, v95, v96, v97, v98, v99, v100, v101, 0xFFFF);
    sub_940407DC(1u, "%s(): ", v28, v29, v30, v31, v32, v33, v34, v35, "sprd_anti_rollback");
    v36 = 0;
    sub_940407DC(1u, "NOSEC ANTI_ROLLBACK ERR version = %x\n", v37, v38, v39, v40, v41, v42, v43, v44, a2);
    return v36;
  }
  sub_940407DC(1u, "%s(): ", v20, v21, v22, v23, v24, v25, v26, v27, "sprd_anti_rollback");
  sub_940407DC(1u, "certtype mismatch!! \r\n", v78, v79, v80, v81, v82, v83, v84, v85);
  return 0;
}

/* ===== sub_94041EF0 @ 0x94041EF0 size 740 ===== */
__int64 __fastcall sub_94041EF0(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v14; // w19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w25
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int v73; // w0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  _BYTE v154[32]; // [xsp+60h] [xbp+60h] BYREF

  v14 = *a3;
  sub_940407DC(1u, "%s(): ", a4, a5, a6, a7, a8, a9, a10, a11, "sprd_verify_cert");
  sub_940407DC(1u, "#####cert type: %d #######\n", v15, v16, v17, v18, v19, v20, v21, v22, v14);
  if ( v14 <= 1 )
  {
    if ( v14 == 1 )
    {
      sub_94041994((__int64)(a3 + 4), 0x108u, (__int64)v154, v23, v24, v25, v26, v27, v28, v29, v30);
      if ( (unsigned int)sub_94042870(a2, a3 + 268, 32) != 0 || (unsigned int)sub_94042870(a1, v154, 32) != 0 )
      {
        v31 = 0;
        sub_940407DC(1u, "%s(): ", v98, v99, v100, v101, v102, v103, v104, v105, "sprd_verify_cert");
        sub_940407DC(1u, "cmp hash of pubk diffent\r\n", v106, v107, v108, v109, v110, v111, v112, v113);
        return v31;
      }
      sub_94037940((__int64)(a3 + 8), (__int64)(a3 + 12), *((_DWORD *)a3 + 1), (__int64)(a3 + 340), -536576504);
      if ( (unsigned int)sub_94042870(a3 + 268, -536576504, 72) == 0 )
      {
        sub_940407DC(1u, "%s(): ", v74, v75, v76, v77, v78, v79, v80, v81, "sprd_verify_cert");
        sub_940407DC(1u, "\nRSA verify Success\n", v138, v139, v140, v141, v142, v143, v144, v145);
        return (unsigned int)sub_94041C94(
                               *((_DWORD *)a3 + 83),
                               *((_DWORD *)a3 + 84),
                               v146,
                               v147,
                               v148,
                               v149,
                               v150,
                               v151,
                               v152,
                               v153);
      }
    }
    else
    {
      sub_94041994((__int64)(a3 + 4), 0x108u, (__int64)v154, v23, v24, v25, v26, v27, v28, v29, v30);
      v31 = sub_94042870(a2, a3 + 268, 32);
      if ( v31 != 0 )
      {
        v31 = 0;
        sub_940407DC(1u, "%s(): ", v41, v42, v43, v44, v45, v46, v47, v48, "sprd_verify_cert");
        sub_940407DC(1u, "cmp hash data diffent\r\n", v114, v115, v116, v117, v118, v119, v120, v121);
        return v31;
      }
      sub_940407DC(1u, "%s(): ", v41, v42, v43, v44, v45, v46, v47, v48, "sprd_verify_cert");
      sub_940407DC(1u, "cmp hash data SUCCESS\r\n", v49, v50, v51, v52, v53, v54, v55, v56);
      if ( (unsigned int)sub_94042870(a1, v154, 32) != 0 )
      {
        sub_940407DC(1u, "%s(): ", v57, v58, v59, v60, v61, v62, v63, v64, "sprd_verify_cert");
        sub_940407DC(1u, "cmp hash key diffent\r\n", v122, v123, v124, v125, v126, v127, v128, v129);
        return v31;
      }
      sub_940407DC(1u, "%s(): ", v57, v58, v59, v60, v61, v62, v63, v64, "sprd_verify_cert");
      sub_940407DC(1u, "cmp hash key SUCCESS\r\n", v65, v66, v67, v68, v69, v70, v71, v72);
      v73 = sub_94037940((__int64)(a3 + 8), (__int64)(a3 + 12), *((_DWORD *)a3 + 1), (__int64)(a3 + 308), -536576504);
      if ( (unsigned int)sub_94042870(a3 + 268, -536576504, v73) == 0 )
      {
        sub_940407DC(1u, "%s(): ", v74, v75, v76, v77, v78, v79, v80, v81, "sprd_verify_cert");
        sub_940407DC(1u, "\nRSA verify Success\n", v82, v83, v84, v85, v86, v87, v88, v89);
        return (unsigned int)sub_94041C94(
                               *((_DWORD *)a3 + 75),
                               *((_DWORD *)a3 + 76),
                               v90,
                               v91,
                               v92,
                               v93,
                               v94,
                               v95,
                               v96,
                               v97);
      }
    }
    v31 = 0;
    sub_940407DC(1u, "%s(): ", v74, v75, v76, v77, v78, v79, v80, v81, "sprd_verify_cert");
    sub_940407DC(1u, "\nRSA verify err\n", v130, v131, v132, v133, v134, v135, v136, v137);
    return v31;
  }
  v31 = 0;
  sub_940407DC(1u, "%s(): ", v23, v24, v25, v26, v27, v28, v29, v30, "sprd_verify_cert");
  sub_940407DC(1u, "invalid cert type %d!!", v32, v33, v34, v35, v36, v37, v38, v39, v14);
  return v31;
}

/* ===== sub_940421D4 @ 0x940421D4 size 108 ===== */
__int64 __fastcall sub_940421D4(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  if ( a1 != 0 )
    return a1 + *(unsigned int *)(a1 + 48) + 512LL;
  sub_940407DC(1u, "%s(): ", a2, a3, a4, a5, a6, a7, a8, a9, "sprd_get_sechdr_addr");
  sub_940407DC(1u, "\r\t input of get_sechdr_Addr err\n", v10, v11, v12, v13, v14, v15, v16, v17);
  return MEMORY[0x30] + 512LL;
}

/* ===== sub_94042240 @ 0x94042240 size 40 ===== */
__int64 __fastcall sub_94042240(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  return a1 + *(_QWORD *)(sub_940421D4(a1, a2, a3, a4, a5, a6, a7, a8, a9) + 24);
}

/* ===== sub_94042268 @ 0x94042268 size 40 ===== */
__int64 __fastcall sub_94042268(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  return a1 + *(_QWORD *)(sub_940421D4(a1, a2, a3, a4, a5, a6, a7, a8, a9) + 40);
}

/* ===== sub_94042290 @ 0x94042290 size 16 ===== */
__int64 __fastcall sub_94042290(__int64 a1, unsigned int a2)
{
  return a1 + a2 + 96LL;
}

/* ===== sub_940422A0 @ 0x940422A0 size 124 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_940422A0(__int64 a1)
{
  sub_94042848(MEMORY[0xFFFFFFFFE0047F08] + 32LL, a1, 32);
  dword_94067E04 = 1;
  return 1;
}

/* ===== sub_9404231C @ 0x9404231C size 80 ===== */
__int64 __fastcall sub_9404231C(__int64 a1)
{
  int v3; // [xsp+2Ch] [xbp+2Ch] BYREF

  v3 = 0;
  sub_9403CC50(&v3);
  if ( v3 != 0 )
    return sub_9403CC40(a1);
  else
    return sub_9403CC30(a1);
}

/* ===== sub_9404236C @ 0x9404236C size 720 ===== */
__int64 __fastcall sub_9404236C(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x25
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int16 v46; // w0
  char *v47; // x1
  __int64 v48; // x27
  unsigned int v49; // w28
  unsigned int v50; // w26
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned __int8 *v83; // x20
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  __int64 result; // x0
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  int v117; // [xsp+6Ch] [xbp+6Ch] BYREF
  _BYTE v118[32]; // [xsp+70h] [xbp+70h] BYREF
  __int64 v119; // [xsp+90h] [xbp+90h] BYREF
  _QWORD v120[2]; // [xsp+98h] [xbp+98h] BYREF
  __int64 v121; // [xsp+A8h] [xbp+A8h] BYREF
  _QWORD v122[2]; // [xsp+B0h] [xbp+B0h] BYREF
  __int64 v123; // [xsp+C0h] [xbp+C0h] BYREF
  _QWORD v124[2]; // [xsp+C8h] [xbp+C8h] BYREF
  __int64 v125; // [xsp+D8h] [xbp+D8h] BYREF
  _QWORD v126[2]; // [xsp+E0h] [xbp+E0h] BYREF

  v12 = sub_940421D4(a2, a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = sub_94042240(a2, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( (unsigned int)sub_94042870(v21, "SCI1", 5) == 0 )
  {
    sub_940407DC(1u, "%s(): ", v22, v23, v24, v25, v26, v27, v28, v29, "sprd_verify_img");
    sub_940407DC(1u, "the image is new packed modem image\n", v30, v31, v32, v33, v34, v35, v36, v37);
    v119 = 0;
    v120[0] = 0;
    v120[1] = 0;
    v121 = 0;
    v122[0] = 0;
    v122[1] = 0;
    v123 = 0;
    v124[0] = 0;
    v124[1] = 0;
    v125 = 0;
    v126[0] = 0;
    v126[1] = 0;
    sub_94042848(&v119, v21, 96);
    if ( (unsigned int)sub_94042870(&v119, "SCI1", 5) == 0 )
    {
      v46 = WORD2(v120[0]);
      if ( BYTE4(v120[0]) == 1 )
      {
        v47 = (char *)v120 + 4;
      }
      else
      {
        v46 = v121;
        v47 = (char *)&v121;
        if ( (unsigned __int8)v121 != 1 )
        {
          v46 = WORD2(v122[0]);
          v47 = (char *)v122 + 4;
          if ( BYTE4(v122[0]) != 1 )
          {
            v46 = v123;
            v47 = (char *)&v123;
            if ( (unsigned __int8)v123 != 1 )
            {
              v46 = WORD2(v124[0]);
              v47 = (char *)v124 + 4;
              if ( BYTE4(v124[0]) != 1 )
              {
                v46 = v125;
                v47 = (char *)&v125;
                if ( (unsigned __int8)v125 != 1 )
                {
                  v46 = WORD2(v126[0]);
                  v47 = (char *)v126 + 4;
                  if ( BYTE4(v126[0]) != 1 )
                  {
                    v48 = 0;
                    v49 = 0;
                    sub_940407DC(1u, "%s(): ", v38, v39, v40, v41, v42, v43, v44, v45, "get_modem_info");
                    v50 = 0;
                    sub_940407DC(1u, "no MODEM exe found in SCI header!", v51, v52, v53, v54, v55, v56, v57, v58);
LABEL_11:
                    v21 += v48;
                    sub_940407DC(1u, "%s(): ", v38, v39, v40, v41, v42, v43, v44, v45, "sprd_verify_img");
                    sub_940407DC(1u, "modem offset: %d, length: %d\n", v59, v60, v61, v62, v63, v64, v65, v66, v50, v49);
                    goto LABEL_12;
                  }
                }
              }
            }
          }
        }
      }
      v50 = *((_DWORD *)v47 + 1);
      v49 = *((_DWORD *)v47 + 2);
      if ( (v46 & 0x400) != 0 )
        v50 += 20;
      v48 = v50;
      goto LABEL_11;
    }
    v48 = 0;
    v49 = 0;
    sub_940407DC(1u, "%s(): ", v38, v39, v40, v41, v42, v43, v44, v45, "get_modem_info");
    v50 = 0;
    sub_940407DC(1u, "old image format!\n", v109, v110, v111, v112, v113, v114, v115, v116);
    goto LABEL_11;
  }
LABEL_12:
  v117 = 0;
  sub_94042820(&v119, 255, 32);
  sub_940422A0(a1);
  sub_94041994(v21, *(_DWORD *)(v12 + 16), (__int64)v118, v67, v68, v69, v70, v71, v72, v73, v74);
  v83 = (unsigned __int8 *)sub_94042268(a2, v75, v76, v77, v78, v79, v80, v81, v82);
  if ( (unsigned int)sub_94042870(a1, &v119, 32) == 0 )
  {
    sub_9403CA20(&v117);
    if ( v117 != 5 )
    {
      sub_940407DC(1u, "%s(): ", v92, v93, v94, v95, v96, v97, v98, v99, "sprd_verify_img");
      sub_940407DC(1u, "not secure lcs\n", v100, v101, v102, v103, v104, v105, v106, v107);
      return 1;
    }
    sub_9404231C(a1);
  }
  result = sub_94041EF0(a1, (__int64)v118, v83, v84, v85, v86, v87, v88, v89, v90, v91);
  if ( (_DWORD)result == 0 )
  {
    while ( 1 )
      ;
  }
  return result;
}

/* ===== sub_9404263C @ 0x9404263C size 316 ===== */
__int64 __fastcall sub_9404263C(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned __int8 *v62; // x22
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 result; // x0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  _BYTE v104[32]; // [xsp+40h] [xbp+40h] BYREF

  sub_940407DC(1u, "%s(): ", a4, a5, a6, a7, a8, a9, a10, a11, "sprd_verify_img_kbc");
  sub_940407DC(
    1u,
    "sprd_verify_img_kbc enter imgbuf = %p imgSize = 0x%x \r\n",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    a2,
    a3);
  sub_94042820(v104, 255, 32);
  sub_940407DC(1u, "%s(): ", v22, v23, v24, v25, v26, v27, v28, v29, "sprd_verify_img_kbc");
  sub_940407DC(1u, "call cal_sha256() imgSize = 0x%x\r\n", v30, v31, v32, v33, v34, v35, v36, v37, a3);
  sub_94041994(a2, a3, (__int64)v104, v38, v39, v40, v41, v42, v43, v44, v45);
  sub_940407DC(1u, "%s(): ", v46, v47, v48, v49, v50, v51, v52, v53, "sprd_verify_img_kbc");
  sub_940407DC(1u, (const char *)&loc_940554F8, v54, v55, v56, v57, v58, v59, v60, v61);
  v62 = (unsigned __int8 *)sub_94042290(a2, a3);
  sub_940407DC(1u, "%s(): ", v63, v64, v65, v66, v67, v68, v69, v70, "sprd_verify_img_kbc");
  sub_940407DC(1u, (const char *)&loc_94055520, v71, v72, v73, v74, v75, v76, v77, v78);
  result = sub_94041EF0(a1, (__int64)v104, v62, v79, v80, v81, v82, v83, v84, v85, v86);
  if ( (_DWORD)result == 0 )
  {
    sub_940407DC(1u, "%s(): ", v88, v89, v90, v91, v92, v93, v94, v95, "sprd_verify_img_kbc");
    sub_940407DC(1u, "sprd_verify_cert() failed , enter while(1) \r\n", v96, v97, v98, v99, v100, v101, v102, v103);
    while ( 1 )
      ;
  }
  return result;
}

/* ===== sub_94042778 @ 0x94042778 size 44 ===== */
__int64 __fastcall sub_94042778(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0

  v11 = sub_94042268(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  return sub_94042848(a2, v11 + 4, 264);
}

/* ===== sub_940427A4 @ 0x940427A4 size 124 ===== */
__int64 __fastcall sub_940427A4(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _BYTE v19[32]; // [xsp+38h] [xbp+38h] BYREF
  _BYTE v20[264]; // [xsp+58h] [xbp+58h] BYREF

  sub_9404CDC4(v20, 0, 264);
  memset(v19, 0, sizeof(v19));
  sub_94042778(a1, (__int64)v20, v2, v3, v4, v5, v6, v7, v8, v9);
  sub_94041994((__int64)v20, 0x108u, (__int64)v19, v10, v11, v12, v13, v14, v15, v16, v17);
  return sub_94042848(MEMORY[0xFFFFFFFFE0047F08], v19, 32);
}

/* ===== sub_94042820 @ 0x94042820 size 40 ===== */
_BYTE *__fastcall sub_94042820(_BYTE *result, char a2, int a3)
{
  __int64 v3; // x3
  _BYTE *v4; // x2
  _BYTE *v5; // x3

  v3 = (unsigned int)(a3 - 1);
  if ( a3 != 0 )
  {
    v4 = result;
    v5 = &result[v3 + 1];
    do
      *v4++ = a2;
    while ( v4 != v5 );
  }
  return result;
}

/* ===== sub_94042848 @ 0x94042848 size 40 ===== */
__int64 __fastcall sub_94042848(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x4
  __int64 v4; // x2
  __int64 v5; // x4

  v3 = (unsigned int)(a3 - 1);
  if ( a3 != 0 )
  {
    v4 = 0;
    v5 = v3 + 1;
    do
    {
      *(_BYTE *)(result + v4) = *(_BYTE *)(a2 + v4);
      ++v4;
    }
    while ( v4 != v5 );
  }
  return result;
}

/* ===== sub_94042870 @ 0x94042870 size 92 ===== */
__int64 __fastcall sub_94042870(unsigned __int8 *a1, unsigned __int8 *a2, int a3)
{
  unsigned __int8 *v3; // x3
  __int64 result; // x0
  unsigned __int8 *v5; // x5
  unsigned int v6; // w2

  v3 = a1;
  if ( a3 == 0 )
    return 0;
  result = *a1 - (unsigned int)*a2;
  if ( (_DWORD)result == 0 )
  {
    v5 = &v3[a3 - 1 + 1];
    while ( 1 )
    {
      ++v3;
      ++a2;
      if ( v3 == v5 )
        break;
      v6 = *v3 - *a2;
      if ( v6 != 0 )
        return v6;
    }
  }
  return result;
}

/* ===== sub_940428CC @ 0x940428CC size 64 ===== */
__int64 __fastcall sub_940428CC(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7

  sub_94040F2C(a1, a2, a3, a4, a5, a6, a7, a8);
  result = sub_9402D420(5u, (__int64)qword_9405C8F0);
  if ( (_DWORD)result != 0 )
    return sub_940407DC(
             2u,
             "failed to install kbc_verify_ops handler: %d\n",
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             (unsigned int)result);
  return result;
}

/* ===== sub_9404290C @ 0x9404290C size 120 ===== */
__int64 __fastcall sub_9404290C(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x19
  __int64 *v11; // x22
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // t1
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v9 = a1;
  v11 = a1 + 56;
  do
  {
    v12 = *((unsigned int *)v9 + 2);
    v13 = *((unsigned int *)v9 + 3);
    v14 = *v9;
    v9 += 14;
    sub_940407DC(2u, "dump_table() len = %x maplen = %x addr = %llx \n", a2, a3, a4, a5, a6, a7, a8, a9, v12, v13, v14);
  }
  while ( v9 != v11 );
  sub_940407DC(2u, "dump_table() flag = %d \n", a2, a3, a4, a5, a6, a7, a8, a9, *((unsigned __int16 *)a1 + 224));
  return sub_940407DC(
           2u,
           "dump_table() is_packed = %d \n",
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           *((unsigned __int16 *)a1 + 225));
}

/* ===== sub_94042984 @ 0x94042984 size 396 ===== */
__int64 __fastcall sub_94042984(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        int a10,
        unsigned int a11)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 result; // x0
  __int64 v69[57]; // [xsp+28h] [xbp+28h] BYREF

  switch ( a10 )
  {
    case 0:
      sub_940407DC(2u, "enter SEC_KBC_STOP_CP\n", a1, a2, a3, a4, a5, a6, a7, a8);
      sub_940417A0(v52, v53, v54, v55, v56, v57, v58, v59);
      result = 0;
      break;
    case 1:
      sub_940407DC(2u, "enter SEC_KBC_VERIFY_ALL\n", a1, a2, a3, a4, a5, a6, a7, a8);
      if ( (unsigned int)sub_9404D244(v69, a11, 456) != 0 )
        goto LABEL_11;
      sub_9404290C(v69, v12, v13, v14, v15, v16, v17, v18, v19);
      sub_940407DC(2u, (const char *)&loc_94055668, v20, v21, v22, v23, v24, v25, v26, v27);
      sub_9404146C((__int64)v69, v28, v29, v30, v31, v32, v33, v34, v35);
      sub_940407DC(2u, "verify succ,will update version\n", v36, v37, v38, v39, v40, v41, v42, v43);
      result = 0;
      break;
    case 2:
      sub_940407DC(2u, "enter SEC_KBC_START_CP\n", a1, a2, a3, a4, a5, a6, a7, a8);
      sub_94041714(v60, v61, v62, v63, v64, v65, v66, v67);
      result = 0;
      break;
    case 3:
      sub_940407DC(2u, "enter SEC_KBC_VERIFY_ALL_V2\n", a1, a2, a3, a4, a5, a6, a7, a8);
      if ( (unsigned int)sub_9404D244(v69, a11, 456) != 0 )
      {
LABEL_11:
        sub_940407DC(2u, "copy_from_user failed!! \n", v12, v13, v14, v15, v16, v17, v18, v19);
        result = 4294967288LL;
      }
      else
      {
        sub_9404290C(v69, v12, v13, v14, v15, v16, v17, v18, v19);
        result = sub_94048EEC(v69);
      }
      break;
    case 4:
      sub_940407DC(2u, "enter SEC_KBC_GET_VERSION\n", a1, a2, a3, a4, a5, a6, a7, a8);
      sub_9404D224(a11, -536460624, 56);
      sub_940407DC(2u, (const char *)&loc_94055710, v44, v45, v46, v47, v48, v49, v50, v51);
      MEMORY[0xFFFFFFFFE00642E4] = 0;
      result = 0;
      break;
    default:
      result = 4294967272LL;
      break;
  }
  return result;
}

/* ===== sub_94042B10 @ 0x94042B10 size 276 ===== */
__int64 __fastcall sub_94042B10(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x1
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int64 v30; // [xsp+28h] [xbp+28h] BYREF

  sub_940463E0(a2, a1, 92);
  result = sub_94042CC8(a1, a2);
  if ( (_DWORD)result != 0 )
  {
    if ( *(_QWORD *)a2 == 4 )
    {
      *(_DWORD *)(a2 + 16) = sub_94046434(*(unsigned int *)(a2 + 16));
      *(_DWORD *)(a2 + 20) = sub_94046434(*(unsigned int *)(a2 + 20));
      *(_DWORD *)(a2 + 24) = sub_94046434(*(unsigned int *)(a2 + 24));
      if ( *(_DWORD *)(a2 + 16) != 0 )
      {
        v21 = *(unsigned int *)(a2 + 20);
        v30 = 76;
        if ( (unsigned int)sub_940464DC(&v30, v21) != 0
          && (unsigned int)sub_940464DC(&v30, *(unsigned int *)(a2 + 24)) != 0 )
        {
          result = 1;
          if ( *(_QWORD *)(a2 + 8) < v30 )
          {
            sub_940407DC(0, "Descriptor payload size overflow.\n", v22, v23, v24, v25, v26, v27, v28, v29);
            return 0;
          }
        }
        else
        {
          sub_940407DC(0, "Overflow while adding up sizes.\n", v22, v23, v24, v25, v26, v27, v28, v29);
          return 0;
        }
      }
      else
      {
        sub_940407DC(0, "Invalid rollback index location value.\n", v13, v14, v15, v16, v17, v18, v19, v20);
        return 0;
      }
    }
    else
    {
      sub_940407DC(0, "Invalid tag for chain partition descriptor.\n", v5, v6, v7, v8, v9, v10, v11, v12);
      return 0;
    }
  }
  return result;
}

/* ===== sub_94042C24 @ 0x94042C24 size 44 ===== */
__int64 *__fastcall sub_94042C24(unsigned int a1)
{
  if ( a1 > 6 )
    return nullptr;
  else
    return &qword_9405C908[3 * a1];
}

/* ===== sub_94042C50 @ 0x94042C50 size 72 ===== */
__int64 __fastcall sub_94042C50(__int64 a1, unsigned int *a2)
{
  sub_940463E0(a2, a1, 8);
  *a2 = sub_94046434(*a2);
  a2[1] = sub_94046434(a2[1]);
  return 1;
}

/* ===== sub_94042C98 @ 0x94042C98 size 20 ===== */
__int64 __fastcall sub_94042C98(__int64 a1, _QWORD *a2)
{
  ++*a2;
  return 1;
}

/* ===== sub_94042CAC @ 0x94042CAC size 28 ===== */
__int64 __fastcall sub_94042CAC(__int64 a1, __int64 *a2)
{
  __int64 v2; // x2
  __int64 v3; // x3

  v2 = *a2;
  v3 = a2[1];
  ++*a2;
  *(_QWORD *)(v3 + 8 * v2) = a1;
  return 1;
}

/* ===== sub_94042CC8 @ 0x94042CC8 size 88 ===== */
__int64 __fastcall sub_94042CC8(_QWORD *a1, _QWORD *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x1
  __int64 result; // x0

  *a2 = sub_94046458(*a1);
  v4 = sub_94046458(a1[1]);
  v13 = v4 & 7;
  a2[1] = v4;
  result = 1;
  if ( v13 != 0 )
  {
    sub_940407DC(0, "Descriptor size is not divisible by 8.\n", v5, v6, v7, v8, v9, v10, v11, v12);
    return 0;
  }
  return result;
}

/* ===== sub_94042D20 @ 0x94042D20 size 552 ===== */
__int64 __fastcall sub_94042D20(
        unsigned __int64 a1,
        unsigned __int64 a2,
        unsigned int (__fastcall *a3)(unsigned __int64, __int64),
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int64 v24; // x20
  __int64 v25; // x21
  unsigned __int64 v26; // x21
  unsigned __int64 v27; // x22
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int64 v36; // x19
  __int64 v38; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x2
  unsigned __int64 v48; // x20
  bool v49; // cc
  unsigned __int64 v50; // x0

  if ( a1 != 0 )
  {
    if ( a3 != nullptr )
    {
      if ( a2 <= 0xFF )
      {
        sub_940407DC(0, "Length is smaller than header.\n", a5, a6, a7, a8, a9, a10, a11, a12);
        return 0;
      }
      else if ( (unsigned int)sub_940463DC(a1, (__int64)"AVB0", 4u) != 0 )
      {
        sub_940407DC(0, "Magic is incorrect.\n", v16, v17, v18, v19, v20, v21, v22, v23);
        return 0;
      }
      else
      {
        if ( (a1 & 7) != 0 )
          sub_940407DC(
            0,
            "assert fail: (((uintptr_t)image_data) & (AVB_ALIGNMENT_SIZE - 1)) == 0\n",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23);
        v24 = a1 + a2;
        v25 = sub_94046458(*(_QWORD *)(a1 + 12));
        v26 = a1 + v25 + sub_94046458(*(_QWORD *)(a1 + 96)) + 256;
        v27 = v26 + sub_94046458(*(_QWORD *)(a1 + 104));
        if ( a1 > v26 || v24 < v26 || a1 > v27 || v24 < v27 || v26 > v27 )
        {
          sub_940407DC(0, "Descriptors not inside passed-in data.\n", v28, v29, v30, v31, v32, v33, v34, v35);
          return 0;
        }
        else
        {
          v36 = v26;
          if ( v26 < v27 )
          {
            while ( 1 )
            {
              if ( (v36 & 7) != 0 )
                sub_940407DC(
                  0,
                  "assert fail: (((uintptr_t)dh) & (AVB_ALIGNMENT_SIZE - 1)) == 0\n",
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35);
              v38 = sub_94046458(*(_QWORD *)(v36 + 8)) + 16;
              v47 = v38 & 7;
              v48 = v36 + v38;
              v49 = v26 > v36 + v38;
              v50 = v36;
              v36 = v48;
              if ( v47 != 0 )
              {
                sub_940407DC(0, "Invalid descriptor length.\n", v39, v40, v41, v42, v43, v44, v45, v46);
                return 0;
              }
              if ( v49 || v27 < v48 )
              {
                sub_940407DC(0, "Invalid data in descriptors array.\n", v39, v40, v41, v42, v43, v44, v45, v46);
                return 0;
              }
              if ( a3(v50, a4) == 0 )
                break;
              if ( v27 <= v48 )
                return 1;
            }
            return 0;
          }
          else
          {
            return 1;
          }
        }
      }
    }
    else
    {
      sub_940407DC(0, "foreach_func is NULL\n.", a5, a6, a7, a8, a9, a10, a11, a12);
      return 0;
    }
  }
  else
  {
    sub_940407DC(0, "image_data is NULL\n.", a5, a6, a7, a8, a9, a10, a11, a12);
    return 0;
  }
}

/* ===== sub_94042F48 @ 0x94042F48 size 172 ===== */
__int64 __fastcall sub_94042F48(
        unsigned __int64 a1,
        unsigned __int64 a2,
        _QWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v31; // [xsp+38h] [xbp+38h] BYREF
  __int64 v32; // [xsp+40h] [xbp+40h] BYREF
  __int64 v33; // [xsp+48h] [xbp+48h]

  v31 = 0;
  sub_94042D20(
    a1,
    a2,
    (unsigned int (__fastcall *)(unsigned __int64, __int64))sub_94042C98,
    (__int64)&v31,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11);
  v32 = 0;
  v33 = sub_94046748(8 * (v31 + 1));
  if ( v33 == 0 )
    return 0;
  sub_94042D20(
    a1,
    a2,
    (unsigned int (__fastcall *)(unsigned __int64, __int64))sub_94042CAC,
    (__int64)&v32,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21);
  if ( v32 != v31 )
    sub_940407DC(0, "assert fail: data.descriptor_number == num_descriptors\n", v22, v23, v24, v25, v26, v27, v28, v29);
  if ( a3 != nullptr )
    *a3 = v31;
  return v33;
}

/* ===== sub_94042FF4 @ 0x94042FF4 size 216 ===== */
__int64 __fastcall sub_94042FF4(__int64 a1, __int64 a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  sub_940463E0(a2, a1, 64);
  *(_DWORD *)(a2 + 4) = sub_94046434(*(unsigned int *)(a2 + 4));
  *(_DWORD *)(a2 + 8) = sub_94046434(*(unsigned int *)(a2 + 8));
  *(_QWORD *)(a2 + 12) = sub_94046458(*(_QWORD *)(a2 + 12));
  *(_QWORD *)(a2 + 20) = sub_94046458(*(_QWORD *)(a2 + 20));
  *(_QWORD *)(a2 + 28) = sub_94046458(*(_QWORD *)(a2 + 28));
  if ( (unsigned int)sub_9404649C(a2, "AVBf", 4) != 0 )
  {
    sub_940407DC(0, "Footer magic is incorrect.\n", v3, v4, v5, v6, v7, v8, v9, v10);
    return 0;
  }
  else if ( *(_DWORD *)(a2 + 4) <= 1u )
  {
    return 1;
  }
  else
  {
    sub_940407DC(0, "No support for footer version.\n", v3, v4, v5, v6, v7, v8, v9, v10);
    return 0;
  }
}

/* ===== sub_940430CC @ 0x940430CC size 280 ===== */
__int64 __fastcall sub_940430CC(_QWORD *a1, __int64 a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int64 v21; // [xsp+28h] [xbp+28h] BYREF

  sub_940463E0(a2, a1, 132);
  result = sub_94042CC8(a1, (_QWORD *)a2);
  if ( (_DWORD)result != 0 )
  {
    if ( *(_QWORD *)a2 == 2 )
    {
      *(_QWORD *)(a2 + 16) = sub_94046458(*(_QWORD *)(a2 + 16));
      *(_DWORD *)(a2 + 56) = sub_94046434(*(unsigned int *)(a2 + 56));
      *(_DWORD *)(a2 + 60) = sub_94046434(*(unsigned int *)(a2 + 60));
      *(_DWORD *)(a2 + 64) = sub_94046434(*(unsigned int *)(a2 + 64));
      v21 = 116;
      if ( (unsigned int)sub_940464DC(&v21, *(unsigned int *)(a2 + 56)) != 0
        && (unsigned int)sub_940464DC(&v21, *(unsigned int *)(a2 + 60)) != 0
        && (unsigned int)sub_940464DC(&v21, *(unsigned int *)(a2 + 64)) != 0 )
      {
        result = 1;
        if ( *(_QWORD *)(a2 + 8) < v21 )
        {
          sub_940407DC(0, "Descriptor payload size overflow.\n", v13, v14, v15, v16, v17, v18, v19, v20);
          return 0;
        }
      }
      else
      {
        sub_940407DC(0, "Overflow while adding up sizes.\n", v13, v14, v15, v16, v17, v18, v19, v20);
        return 0;
      }
    }
    else
    {
      sub_940407DC(0, "Invalid tag for hash descriptor.\n", v5, v6, v7, v8, v9, v10, v11, v12);
      return 0;
    }
  }
  return result;
}

/* ===== sub_940431E4 @ 0x940431E4 size 216 ===== */
__int64 __fastcall sub_940431E4(_QWORD *a1, __int64 a2)
{
  unsigned int v4; // w20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int64 v23; // [xsp+28h] [xbp+28h] BYREF

  sub_940463E0(a2, a1, 24);
  v4 = sub_94042CC8(a1, (_QWORD *)a2);
  if ( v4 != 0 )
  {
    if ( *(_QWORD *)a2 == 3 )
    {
      *(_DWORD *)(a2 + 16) = sub_94046434(*(unsigned int *)(a2 + 16));
      v14 = sub_94046434(*(unsigned int *)(a2 + 20));
      *(_DWORD *)(a2 + 20) = v14;
      v23 = 8;
      v4 = sub_940464DC(&v23, v14);
      if ( v4 != 0 )
      {
        v4 = 1;
        if ( *(_QWORD *)(a2 + 8) < v23 )
        {
          v4 = 0;
          sub_940407DC(0, "Descriptor payload size overflow.\n", v15, v16, v17, v18, v19, v20, v21, v22);
        }
      }
      else
      {
        sub_940407DC(0, "Overflow while adding up sizes.\n", v15, v16, v17, v18, v19, v20, v21, v22);
      }
    }
    else
    {
      v4 = 0;
      sub_940407DC(0, "Invalid tag for kernel cmdline descriptor.\n", v5, v6, v7, v8, v9, v10, v11, v12);
    }
  }
  return v4;
}

/* ===== sub_940432BC @ 0x940432BC size 280 ===== */
__int64 __fastcall sub_940432BC(__int64 result, _DWORD *a2, __int64 a3, _DWORD *a4)
{
  unsigned int v4; // w4
  unsigned int v5; // w6
  unsigned int *v6; // x11
  unsigned int i; // w12
  unsigned int v8; // w14
  bool v9; // cc
  unsigned __int64 v10; // x5
  unsigned int v11; // w13
  unsigned __int64 v12; // x6
  unsigned int v13; // w4
  __int64 v14; // x10
  unsigned int v15; // w8
  unsigned int v16; // w7
  unsigned int v17; // w9
  unsigned __int64 v18; // x5
  __int64 v19; // x4
  unsigned int v20; // w5
  __int64 v21; // x4
  __int64 v22; // x4

  v4 = 0;
  if ( *(_DWORD *)result != 0 )
  {
    do
    {
      a2[v4++] = 0;
      v5 = *(_DWORD *)result;
    }
    while ( *(_DWORD *)result > v4 );
    if ( v5 != 0 )
    {
      v6 = *(unsigned int **)(result + 8);
      for ( i = 0; i < v5; ++i )
      {
        while ( 1 )
        {
          v8 = *(_DWORD *)(a3 + 4LL * i);
          v9 = v5 > 1;
          v10 = (unsigned int)*a2 + v8 * (unsigned __int64)(unsigned int)*a4;
          v11 = *(_DWORD *)(result + 4) * v10;
          v12 = *a2 + v8 * *a4 + v11 * (unsigned __int64)*v6;
          if ( v9 )
          {
            v13 = 1;
            do
            {
              v14 = (unsigned int)a2[v13];
              v15 = v13 - 1;
              v16 = v6[v13];
              v17 = a4[v13++];
              v10 = v14 + HIDWORD(v10) + v17 * (unsigned __int64)v8;
              v12 = HIDWORD(v12) + v16 * (unsigned __int64)v11 + (unsigned int)v10;
              a2[v15] = v12;
            }
            while ( v13 < *(_DWORD *)result );
            v22 = v13 - 1;
          }
          else
          {
            v22 = 0;
          }
          v18 = HIDWORD(v12) + HIDWORD(v10);
          a2[v22] = v18;
          if ( HIDWORD(v18) != 0 )
            break;
          v5 = *(_DWORD *)result;
          if ( ++i >= *(_DWORD *)result )
            return result;
        }
        if ( *(_DWORD *)result == 0 )
          break;
        v19 = 0;
        v20 = 0;
        do
        {
          v21 = (unsigned int)a2[v20] + v19 - v6[v20];
          a2[v20++] = v21;
          v19 = v21 >> 32;
          v5 = *(_DWORD *)result;
        }
        while ( v20 < *(_DWORD *)result );
      }
    }
  }
  return result;
}

/* ===== sub_940433D4 @ 0x940433D4 size 384 ===== */
__int64 __fastcall sub_940433D4(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned __int64 v13; // x0
  __int64 v14; // x21
  __int64 v15; // x0
  __int64 v16; // x20
  __int64 v17; // x24
  __int64 v18; // x1
  unsigned int v19; // w19
  __int64 v20; // x24
  unsigned int v21[2]; // [xsp+48h] [xbp+48h] BYREF

  if ( (unsigned int)sub_94042C50(a1, v21) != 0 )
  {
    if ( ((v21[0] - 2048) & 0xFFFFF7FF) == 0 || v21[0] == 0x2000 )
    {
      v13 = ((unsigned __int64)v21[0] >> 2) & 0x1FFFFFFF;
      if ( a2 == v13 + 8 )
      {
        v14 = (v21[0] >> 3) + 8LL;
        v15 = sub_94046700(v13 + 24);
        v16 = v15;
        if ( v15 != 0 )
        {
          v17 = v15 + 24;
          v18 = v21[0] >> 5;
          *(_DWORD *)(v15 + 4) = v21[1];
          *(_DWORD *)v15 = v18;
          *(_QWORD *)(v15 + 8) = v15 + 24;
          *(_QWORD *)(v15 + 16) = v15 + 24 + 4 * v18;
          if ( (_DWORD)v18 != 0 )
          {
            v19 = 0;
            while ( 1 )
            {
              *(_DWORD *)(v17 + 4LL * v19) = sub_94046434(*(unsigned int *)(a1 + 4LL * ((unsigned int)v18 + ~v19) + 8));
              v20 = *(_QWORD *)(v16 + 16);
              *(_DWORD *)(v20 + 4LL * v19) = sub_94046434(*(unsigned int *)(a1 + v14 + 4LL * (*(_DWORD *)v16 - 1 - v19)));
              ++v19;
              LODWORD(v18) = *(_DWORD *)v16;
              if ( *(_DWORD *)v16 <= v19 )
                break;
              v17 = *(_QWORD *)(v16 + 8);
            }
          }
          return v16;
        }
        else
        {
          return 0;
        }
      }
      else
      {
        sub_940407DC(0, "Key does not match expected length.\n", v4, v5, v6, v7, v8, v9, v10, v11);
        return 0;
      }
    }
    else
    {
      sub_940407DC(0, "Unexpected key length.\n", v4, v5, v6, v7, v8, v9, v10, v11);
      return 0;
    }
  }
  else
  {
    sub_940407DC(0, "Invalid key.\n", v4, v5, v6, v7, v8, v9, v10, v11);
    return 0;
  }
}

/* ===== sub_94043554 @ 0x94043554 size 4 ===== */
// attributes: thunk
__int64 __fastcall sub_94043554(__int64 a1)
{
  return sub_94046430(a1);
}

/* ===== sub_94043558 @ 0x94043558 size 1120 ===== */
__int64 __fastcall sub_94043558(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  unsigned int *v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  signed int *v25; // x20
  __int64 v26; // x22
  __int64 v28; // x19
  __int64 v29; // x0
  __int64 v30; // x3
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x21
  int *v40; // x23
  _DWORD *v41; // x22
  __int64 v42; // x0
  _DWORD *v43; // x24
  __int64 v44; // x4
  __int64 v45; // x5
  __int64 v46; // x6
  signed int v47; // w2
  int *v48; // x7
  signed int i; // w1
  int v50; // w0
  __int64 v51; // x3
  int v52; // w25
  __int64 v53; // x4
  __int64 v54; // x5
  __int64 v55; // x6
  signed int v56; // w1
  unsigned int v57; // w0
  __int64 v58; // x7
  unsigned int v59; // w2
  unsigned int v60; // w3
  unsigned int v61; // w3
  unsigned int v62; // w2
  __int64 v63; // x0
  unsigned int v64; // w2
  __int64 v65; // x0
  int v66; // w1
  __int64 v67; // x0
  int *v68; // x3
  int v69; // t1
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned int v78; // w19
  __int64 v79; // x0
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v92; // [xsp+68h] [xbp+68h]
  __int64 v93; // [xsp+68h] [xbp+68h]
  __int64 v94; // [xsp+68h] [xbp+68h]
  __int64 v95; // [xsp+68h] [xbp+68h]
  __int64 v97; // [xsp+70h] [xbp+70h]
  __int64 v98; // [xsp+70h] [xbp+70h]
  __int64 v99; // [xsp+70h] [xbp+70h]
  __int64 v100; // [xsp+70h] [xbp+70h]
  __int64 v101; // [xsp+70h] [xbp+70h]
  __int64 v103; // [xsp+78h] [xbp+78h]
  __int64 v104; // [xsp+78h] [xbp+78h]
  __int64 v105; // [xsp+78h] [xbp+78h]
  __int64 v106; // [xsp+78h] [xbp+78h]
  __int64 v107; // [xsp+78h] [xbp+78h]

  if ( a1 == 0 || a3 == 0 || a5 == 0 || a7 == 0 )
  {
    sub_940407DC(0, "Invalid input.\n", a9, a10, a11, a12, a13, a14, a15, a16);
    return 0;
  }
  v16 = (unsigned int *)sub_940433D4(a1, a2);
  v25 = (signed int *)v16;
  if ( v16 == nullptr )
  {
    sub_940407DC(0, "Error parsing key.\n", v17, v18, v19, v20, v21, v22, v23, v24, a3, a4, a5, a6, a7, a8);
    return 0;
  }
  v26 = 4LL * *v16;
  if ( v26 != a4 )
  {
    sub_940407DC(
      0,
      "Signature length does not match key length.\n",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8);
LABEL_8:
    sub_94043554((__int64)v25);
    return 0;
  }
  v28 = v26 - a6;
  if ( v26 - a6 != a8 )
  {
    sub_940407DC(
      0,
      "Padding length does not match hash and signature lengths.\n",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      a3);
    goto LABEL_8;
  }
  v29 = sub_94046700(4LL * *v16);
  v39 = v29;
  if ( v29 == 0 )
  {
    sub_940407DC(0, "Error allocating memory.\n", v31, v32, v33, v34, v35, v36, v37, v38, a3, v30, a5, a6, a7);
    goto LABEL_8;
  }
  sub_940463E0(v29, a3, v26);
  v40 = (int *)sub_94046700(4LL * (unsigned int)*v25);
  v41 = (_DWORD *)sub_94046700(4LL * (unsigned int)*v25);
  v42 = sub_94046700(4LL * (unsigned int)*v25);
  v43 = (_DWORD *)v42;
  v44 = a5;
  v45 = a6;
  v46 = a7;
  if ( v41 != nullptr && v40 != nullptr )
  {
    if ( v42 != 0 )
    {
      v47 = *v25;
      v48 = v40;
      for ( i = 0; i < *v25; v47 = *v25 )
      {
        v50 = 0x3FFFFFFF - i++;
        v51 = (unsigned int)(4 * (v47 + v50));
        *v48++ = *(unsigned __int8 *)(v39 + (unsigned int)(v51 + 3))
               | (*(unsigned __int8 *)(v39 + v51) << 24)
               | (*(unsigned __int8 *)(v39 + (unsigned int)(v51 + 1)) << 16)
               | (*(unsigned __int8 *)(v39 + (unsigned int)(v51 + 2)) << 8);
      }
      v52 = 8;
      sub_940432BC((__int64)v25, v41, (__int64)v40, *((_DWORD **)v25 + 2));
      v53 = a5;
      v54 = a6;
      v55 = a7;
      do
      {
        v92 = v55;
        v97 = v54;
        v103 = v53;
        sub_940432BC((__int64)v25, v43, (__int64)v41, v41);
        sub_940432BC((__int64)v25, v41, (__int64)v43, v43);
        --v52;
        v53 = v103;
        v54 = v97;
        v55 = v92;
      }
      while ( v52 != 0 );
      sub_940432BC((__int64)v25, v43, (__int64)v41, v40);
      v56 = *v25;
      v44 = v103;
      v45 = v97;
      v46 = v92;
      if ( *v25 != 0 )
      {
        v57 = v56 - 1;
        v58 = *((_QWORD *)v25 + 1);
        v59 = v43[v56 - 1];
        v60 = *(_DWORD *)(v58 + 4LL * (unsigned int)(v56 - 1));
        if ( v60 <= v59 )
        {
          if ( v60 >= v59 )
          {
            do
            {
              if ( v57 == 0 )
                break;
              v61 = v43[--v57];
              v62 = *(_DWORD *)(v58 + 4LL * v57);
              if ( v61 < v62 )
                goto LABEL_30;
            }
            while ( v61 <= v62 );
          }
          v63 = 0;
          v64 = 0;
          do
          {
            v65 = (unsigned int)v43[v64] + v63 - *(unsigned int *)(v58 + 4LL * v64);
            v43[v64++] = v65;
            v63 = v65 >> 32;
            v56 = *v25;
          }
          while ( v64 < *v25 );
        }
LABEL_30:
        v66 = v56 - 1;
        if ( v66 >= 0 )
        {
          v67 = v39;
          v68 = &v43[v66];
          do
          {
            v69 = *v68--;
            v67 += 4;
            --v66;
            *(_BYTE *)(v67 - 1) = v69;
            *(_BYTE *)(v67 - 4) = HIBYTE(v69);
            *(_BYTE *)(v67 - 3) = BYTE2(v69);
            *(_BYTE *)(v67 - 2) = BYTE1(v69);
          }
          while ( v66 != -1 );
        }
      }
    }
  }
  else if ( v40 == nullptr )
  {
    goto LABEL_34;
  }
  v93 = v46;
  v98 = v45;
  v104 = v44;
  sub_94046430((__int64)v40);
  v44 = v104;
  v45 = v98;
  v46 = v93;
LABEL_34:
  if ( v41 != nullptr )
  {
    v94 = v46;
    v99 = v45;
    v105 = v44;
    sub_94046430((__int64)v41);
    v46 = v94;
    v45 = v99;
    v44 = v105;
  }
  if ( v43 != nullptr )
  {
    v95 = v46;
    v100 = v45;
    v106 = v44;
    sub_94046430((__int64)v43);
    v46 = v95;
    v45 = v100;
    v44 = v106;
  }
  v101 = v45;
  v107 = v44;
  if ( (unsigned int)sub_9404649C(v39, v46, v28) != 0 )
  {
    v78 = 0;
    sub_940407DC(0, "Padding check failed.\n", v70, v71, v72, v73, v74, v75, v76, v77);
  }
  else
  {
    v79 = v39 + v28;
    v78 = 1;
    if ( (unsigned int)sub_9404649C(v79, v107, v101) != 0 )
    {
      v78 = 0;
      sub_940407DC(0, "Hash check failed.\n", v80, v81, v82, v83, v84, v85, v86, v87);
    }
  }
  sub_94043554((__int64)v25);
  sub_94046430(v39);
  return v78;
}

/* ===== sub_940439B8 @ 0x940439B8 size 548 ===== */
unsigned int *__fastcall sub_940439B8(unsigned int *result, __int64 a2, int a3)
{
  unsigned int v3; // w28
  int v4; // w26
  unsigned int v5; // w27
  unsigned int v6; // w25
  unsigned int v7; // w24
  unsigned int v8; // w23
  unsigned int v9; // w22
  unsigned int v10; // w21
  __int64 i; // x5
  __int64 *v12; // x7
  unsigned int v13; // w2
  int v14; // w3
  unsigned __int64 v15; // t2
  int v16; // w5
  unsigned int v17; // w11
  unsigned int v18; // w14
  unsigned int v19; // w13
  unsigned int v20; // w17
  unsigned int v21; // w10
  unsigned int v22; // w16
  unsigned int v23; // w15
  unsigned int v24; // w1
  __int64 v25; // x12
  int v26; // w4
  unsigned __int64 v27; // t2
  int v28; // w3
  unsigned __int64 v29; // t2
  int v30; // w2
  int v31; // w5
  int v32; // w9
  int v33; // w5
  unsigned __int64 v34; // t2
  unsigned int v35; // w2
  unsigned int v36; // w4
  unsigned int v37; // w2
  unsigned int v38; // [xsp+50h] [xbp-110h]
  _DWORD v41[48]; // [xsp+60h] [xbp-100h] BYREF
  __int64 v42; // [xsp+120h] [xbp-40h] BYREF

  if ( a3 > 0 )
  {
    v3 = *result;
    v4 = 0;
    v5 = result[1];
    v6 = result[2];
    v7 = result[3];
    v8 = result[4];
    v9 = result[5];
    v10 = result[6];
    v38 = result[7];
    do
    {
      for ( i = 0; i != 16; ++i )
        v41[i] = _byteswap_ulong(*(_DWORD *)(a2 + (v4 << 6) + 4 * (int)i));
      v12 = (__int64 *)v41;
      do
      {
        v13 = *((_DWORD *)v12 + 14);
        v12 = (__int64 *)((char *)v12 + 4);
        HIDWORD(v15) = v13;
        LODWORD(v15) = v13;
        v14 = v15 >> 17;
        HIDWORD(v15) = v13;
        LODWORD(v15) = v13;
        v16 = (v15 >> 19) ^ v14;
        HIDWORD(v15) = *(_DWORD *)v12;
        LODWORD(v15) = *(_DWORD *)v12;
        *((_DWORD *)v12 + 15) = *((_DWORD *)v12 - 1)
                              + *((_DWORD *)v12 + 8)
                              + (v16 ^ (v13 >> 10))
                              + ((v15 >> 18) ^ __ROR4__(*(_DWORD *)v12, 7) ^ (*(_DWORD *)v12 >> 3));
      }
      while ( v12 != &v42 );
      v17 = v3;
      v18 = v5;
      v19 = v6;
      v20 = v7;
      v21 = v8;
      v22 = v9;
      v23 = v10;
      v24 = v38;
      v25 = 0;
      while ( 1 )
      {
        HIDWORD(v27) = v21;
        LODWORD(v27) = v21;
        v26 = v27 >> 6;
        v29 = __PAIR64__(v21, __ROR4__(v21, 11));
        v28 = v26 ^ v29;
        LODWORD(v29) = v21;
        v30 = v28 ^ (v29 >> 25);
        HIDWORD(v29) = v17;
        LODWORD(v29) = v17;
        v31 = v29 >> 2;
        v32 = v41[v25] + *(_DWORD *)((char *)qword_94058968 + v25 * 4);
        v34 = __PAIR64__(v17, __ROR4__(v17, 13));
        v33 = v31 ^ v34;
        LODWORD(v34) = v17;
        ++v25;
        v35 = v32 + v30 + (v23 & ~v21 ^ v22 & v21) + v24;
        v24 = v23;
        v36 = v20 + v35;
        v37 = ((v19 ^ v18) & v17 ^ v19 & v18) + (v33 ^ (v34 >> 22)) + v35;
        v20 = v19;
        if ( v25 == 64 )
          break;
        v19 = v18;
        v23 = v22;
        v18 = v17;
        v22 = v21;
        v17 = v37;
        v21 = v36;
      }
      v3 += v37;
      v8 += v36;
      ++v4;
      v5 += v17;
      v6 += v18;
      v7 += v19;
      v9 += v21;
      v10 += v22;
      v38 += v23;
      *result = v3;
      result[1] = v5;
      result[2] = v6;
      result[3] = v7;
      result[4] = v8;
      result[5] = v9;
      result[6] = v10;
      result[7] = v38;
    }
    while ( v4 != a3 );
  }
  return result;
}

/* ===== sub_94043BDC @ 0x94043BDC size 108 ===== */
_DWORD *__fastcall sub_94043BDC(_DWORD *result)
{
  *result = 1779033703;
  result[1] = -1150833019;
  result[2] = 1013904242;
  result[3] = -1521486534;
  result[4] = 1359893119;
  result[5] = -1694144372;
  result[6] = 528734635;
  result[7] = 1541459225;
  result[9] = 0;
  result[8] = 0;
  return result;
}

/* ===== sub_94043C48 @ 0x94043C48 size 224 ===== */
__int64 __fastcall sub_94043C48(unsigned int *a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w3
  unsigned int v5; // w19
  __int64 v7; // x22
  __int64 result; // x0
  unsigned int v10; // w19
  __int64 v11; // x22
  unsigned int v12; // w21
  int v13; // w2
  int v14; // w19

  v3 = a1[9];
  if ( a3 > 64 - v3 )
    v5 = 64 - v3;
  else
    v5 = a3;
  v7 = v5;
  sub_940463E0((char *)a1 + v3 + 40, a2, v5);
  result = a3 + a1[9];
  if ( (unsigned int)result > 0x3F )
  {
    v10 = a3 - v5;
    v11 = a2 + v7;
    sub_940439B8(a1, (__int64)(a1 + 10), 1);
    v12 = v10 >> 6;
    v13 = v10 >> 6;
    v14 = v10 & 0x3F;
    sub_940439B8(a1, v11, v13);
    sub_940463E0(a1 + 10, v11 + ((unsigned __int64)v12 << 6), v14 & 0x3F);
    a1[9] = v14;
    result = a1[8];
    a1[8] = result + ((v12 + 1) << 6);
  }
  else
  {
    a1[9] = result;
  }
  return result;
}

/* ===== sub_94043D28 @ 0x94043D28 size 520 ===== */
__int64 __fastcall sub_94043D28(__int64 a1)
{
  unsigned int v1; // w3
  unsigned int v3; // w0
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 v7; // x24
  int v8; // w2
  __int64 v9; // x2
  int v10; // w25
  unsigned int v11; // w20
  int v13; // w3
  int v14; // w2
  int v15; // w9
  int v16; // w1
  int v17; // w8
  int v18; // w7
  int v19; // w13
  int v20; // w6
  int v21; // w5
  int v22; // w1

  v1 = *(_DWORD *)(a1 + 36);
  v3 = v1 & 0x3F;
  v4 = 60;
  if ( v3 >= 0x38 )
    v4 = 124;
  v5 = 125;
  if ( v3 < 0x38 )
    v5 = 61;
  v6 = 126;
  if ( v3 < 0x38 )
    v6 = 62;
  v7 = 127;
  if ( v3 >= 0x38 )
  {
    v8 = 128;
  }
  else
  {
    v7 = 63;
    v8 = 64;
  }
  v9 = v8 - v1;
  if ( v3 < 0x38 )
    v10 = 1;
  else
    v10 = 2;
  v11 = v1 + *(_DWORD *)(a1 + 32);
  sub_940463F8(a1 + v1 + 40, 0, v9);
  v11 *= 8;
  *(_BYTE *)(a1 + *(unsigned int *)(a1 + 36) + 40) = 0x80;
  *(_BYTE *)(a1 + v7 + 40) = v11;
  *(_BYTE *)(a1 + v6 + 40) = BYTE1(v11);
  *(_BYTE *)(a1 + v5 + 40) = BYTE2(v11);
  *(_BYTE *)(a1 + v4 + 40) = HIBYTE(v11);
  sub_940439B8((unsigned int *)a1, a1 + 40, v10);
  v13 = *(_DWORD *)(a1 + 4);
  v14 = *(_DWORD *)(a1 + 8);
  v15 = *(_DWORD *)a1 >> 8;
  v16 = *(_DWORD *)(a1 + 12);
  v17 = HIWORD(*(_DWORD *)a1);
  v18 = *(_DWORD *)(a1 + 16);
  v19 = HIBYTE(*(_DWORD *)a1);
  v20 = *(_DWORD *)(a1 + 20);
  v21 = *(_DWORD *)(a1 + 24);
  *(_BYTE *)(a1 + 171) = *(_DWORD *)a1;
  *(_BYTE *)(a1 + 170) = v15;
  *(_BYTE *)(a1 + 169) = v17;
  *(_BYTE *)(a1 + 175) = v13;
  *(_BYTE *)(a1 + 168) = v19;
  *(_BYTE *)(a1 + 174) = BYTE1(v13);
  *(_BYTE *)(a1 + 173) = BYTE2(v13);
  *(_BYTE *)(a1 + 172) = HIBYTE(v13);
  *(_BYTE *)(a1 + 179) = v14;
  *(_BYTE *)(a1 + 178) = BYTE1(v14);
  *(_BYTE *)(a1 + 177) = BYTE2(v14);
  *(_BYTE *)(a1 + 176) = HIBYTE(v14);
  *(_BYTE *)(a1 + 183) = v16;
  *(_BYTE *)(a1 + 182) = BYTE1(v16);
  *(_BYTE *)(a1 + 181) = BYTE2(v16);
  *(_BYTE *)(a1 + 180) = HIBYTE(v16);
  *(_BYTE *)(a1 + 187) = v18;
  *(_BYTE *)(a1 + 186) = BYTE1(v18);
  *(_BYTE *)(a1 + 185) = BYTE2(v18);
  *(_BYTE *)(a1 + 184) = HIBYTE(v18);
  *(_BYTE *)(a1 + 191) = v20;
  *(_BYTE *)(a1 + 190) = BYTE1(v20);
  *(_BYTE *)(a1 + 189) = BYTE2(v20);
  *(_BYTE *)(a1 + 188) = HIBYTE(v20);
  *(_BYTE *)(a1 + 195) = v21;
  *(_BYTE *)(a1 + 194) = BYTE1(v21);
  *(_BYTE *)(a1 + 193) = BYTE2(v21);
  v22 = *(_DWORD *)(a1 + 28);
  *(_BYTE *)(a1 + 192) = HIBYTE(v21);
  *(_BYTE *)(a1 + 199) = v22;
  *(_BYTE *)(a1 + 198) = BYTE1(v22);
  *(_BYTE *)(a1 + 197) = BYTE2(v22);
  *(_BYTE *)(a1 + 196) = HIBYTE(v22);
  return a1 + 168;
}

/* ===== sub_94043F30 @ 0x94043F30 size 584 ===== */
__int64 *__fastcall sub_94043F30(__int64 *result, __int64 a2, int a3)
{
  __int64 v3; // x28
  int v4; // w26
  __int64 v5; // x27
  __int64 v6; // x25
  __int64 v7; // x24
  __int64 v8; // x23
  __int64 v9; // x22
  __int64 v10; // x21
  __int64 i; // x7
  __int64 *v12; // x7
  unsigned __int64 v13; // x2
  __int64 v14; // x11
  __int64 v15; // x14
  __int64 v16; // x13
  __int64 v17; // x17
  __int64 v18; // x10
  __int64 v19; // x16
  __int64 v20; // x15
  __int64 v21; // x1
  __int64 v22; // x12
  __int64 v23; // x9
  __int64 v24; // x2
  __int64 v25; // x4
  __int64 v26; // x2
  __int64 v27; // [xsp+58h] [xbp-298h]
  _QWORD v30[64]; // [xsp+70h] [xbp-280h] BYREF
  __int64 v31; // [xsp+270h] [xbp-80h] BYREF

  if ( a3 > 0 )
  {
    v3 = *result;
    v4 = 0;
    v5 = result[1];
    v6 = result[2];
    v7 = result[3];
    v8 = result[4];
    v9 = result[5];
    v10 = result[6];
    v27 = result[7];
    do
    {
      for ( i = 0; i != 16; ++i )
        v30[i] = _byteswap_uint64(*(_QWORD *)(a2 + (v4 << 7) + 8 * (int)i));
      v12 = v30;
      do
      {
        v13 = v12[14];
        ++v12;
        v12[15] = *(v12 - 1)
                + v12[8]
                + (__ROR8__(v13, 61) ^ __ROR8__(v13, 19) ^ (v13 >> 6))
                + (__ROR8__(*v12, 1) ^ __ROR8__(*v12, 8) ^ ((unsigned __int64)*v12 >> 7));
      }
      while ( v12 != &v31 );
      v14 = v3;
      v15 = v5;
      v16 = v6;
      v17 = v7;
      v18 = v8;
      v19 = v9;
      v20 = v10;
      v21 = v27;
      v22 = 0;
      while ( 1 )
      {
        v23 = v30[v22] + *(_QWORD *)((char *)&unk_94058A68 + v22 * 8);
        ++v22;
        v24 = v23 + (__ROR8__(v18, 14) ^ __ROR8__(v18, 18) ^ __ROR8__(v18, 41)) + (v20 & ~v18 ^ v19 & v18) + v21;
        v21 = v20;
        v25 = v17 + v24;
        v26 = ((v16 ^ v15) & v14 ^ v16 & v15) + (__ROR8__(v14, 34) ^ __ROR8__(v14, 28) ^ __ROR8__(v14, 39)) + v24;
        v17 = v16;
        if ( v22 == 80 )
          break;
        v16 = v15;
        v20 = v19;
        v15 = v14;
        v19 = v18;
        v14 = v26;
        v18 = v25;
      }
      v3 += v26;
      v8 += v25;
      ++v4;
      v5 += v14;
      v6 += v15;
      v7 += v16;
      v9 += v18;
      v10 += v19;
      v27 += v20;
      *result = v3;
      result[1] = v5;
      result[2] = v6;
      result[3] = v7;
      result[4] = v8;
      result[5] = v9;
      result[6] = v10;
      result[7] = v27;
    }
    while ( v4 != a3 );
  }
  return result;
}

/* ===== sub_94044178 @ 0x94044178 size 172 ===== */
__int64 __fastcall sub_94044178(__int64 result)
{
  *(_QWORD *)result = 0x6A09E667F3BCC908LL;
  *(_QWORD *)(result + 8) = 0xBB67AE8584CAA73BLL;
  *(_QWORD *)(result + 16) = 0x3C6EF372FE94F82BLL;
  *(_QWORD *)(result + 24) = 0xA54FF53A5F1D36F1LL;
  *(_QWORD *)(result + 32) = 0x510E527FADE682D1LL;
  *(_QWORD *)(result + 40) = 0x9B05688C2B3E6C1FLL;
  *(_QWORD *)(result + 48) = 0x1F83D9ABFB41BD6BLL;
  *(_QWORD *)(result + 56) = 0x5BE0CD19137E2179LL;
  *(_DWORD *)(result + 68) = 0;
  *(_DWORD *)(result + 64) = 0;
  return result;
}

/* ===== sub_94044224 @ 0x94044224 size 224 ===== */
__int64 __fastcall sub_94044224(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w3
  unsigned int v5; // w19
  __int64 v7; // x22
  __int64 result; // x0
  unsigned int v10; // w19
  __int64 v11; // x22
  unsigned int v12; // w21
  int v13; // w2
  int v14; // w19

  v3 = *(_DWORD *)(a1 + 68);
  if ( a3 > 128 - v3 )
    v5 = 128 - v3;
  else
    v5 = a3;
  v7 = v5;
  sub_940463E0(a1 + v3 + 72, a2, v5);
  result = a3 + *(_DWORD *)(a1 + 68);
  if ( (unsigned int)result > 0x7F )
  {
    v10 = a3 - v5;
    v11 = a2 + v7;
    sub_94043F30((__int64 *)a1, a1 + 72, 1);
    v12 = v10 >> 7;
    v13 = v10 >> 7;
    v14 = v10 & 0x7F;
    sub_94043F30((__int64 *)a1, v11, v13);
    sub_940463E0(a1 + 72, v11 + ((unsigned __int64)v12 << 7), v14 & 0x7F);
    *(_DWORD *)(a1 + 68) = v14;
    result = *(unsigned int *)(a1 + 64);
    *(_DWORD *)(a1 + 64) = result + ((v12 + 1) << 7);
  }
  else
  {
    *(_DWORD *)(a1 + 68) = result;
  }
  return result;
}

/* ===== sub_94044304 @ 0x94044304 size 352 ===== */
__int64 __fastcall sub_94044304(__int64 a1)
{
  unsigned int v1; // w3
  unsigned int v3; // w0
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 v7; // x24
  int v8; // w2
  __int64 v9; // x2
  unsigned int v10; // w20
  int v11; // w25
  int v12; // w20
  __int64 v13; // x2
  __int64 v14; // x1
  int v15; // w0
  _BYTE *v16; // x0

  v1 = *(_DWORD *)(a1 + 68);
  v3 = v1 & 0x7F;
  v4 = 124;
  if ( v3 >= 0x70 )
    v4 = 252;
  v5 = 253;
  if ( v3 < 0x70 )
    v5 = 125;
  v6 = 254;
  if ( v3 < 0x70 )
    v6 = 126;
  v7 = 255;
  if ( v3 >= 0x70 )
  {
    v8 = 256;
  }
  else
  {
    v7 = 127;
    v8 = 128;
  }
  v9 = v8 - v1;
  v10 = v1 + *(_DWORD *)(a1 + 64);
  if ( v3 < 0x70 )
    v11 = 1;
  else
    v11 = 2;
  sub_940463F8(a1 + v1 + 72, 0, v9);
  v12 = 8 * v10;
  *(_BYTE *)(a1 + *(unsigned int *)(a1 + 68) + 72) = 0x80;
  *(_BYTE *)(a1 + v7 + 72) = v12;
  *(_BYTE *)(a1 + v6 + 72) = BYTE1(v12);
  *(_BYTE *)(a1 + v5 + 72) = BYTE2(v12);
  *(_BYTE *)(a1 + v4 + 72) = HIBYTE(v12);
  sub_94043F30((__int64 *)a1, a1 + 72, v11);
  v13 = 0;
  do
  {
    v14 = *(_QWORD *)(a1 + 8 * v13);
    v15 = 8 * v13++;
    v16 = (_BYTE *)(a1 + v15);
    v16[335] = v14;
    v16[334] = BYTE1(v14);
    v16[333] = BYTE2(v14);
    v16[332] = BYTE3(v14);
    v16[331] = BYTE4(v14);
    v16[330] = BYTE5(v14);
    v16[329] = BYTE6(v14);
    v16[328] = HIBYTE(v14);
  }
  while ( v13 != 8 );
  return a1 + 328;
}

/* ===== sub_94044464 @ 0x94044464 size 132 ===== */
__int64 __fastcall sub_94044464(unsigned __int64 a1, __int64 a2)
{
  __int64 v2; // x3
  int v3; // w2
  __int64 v4; // x6
  __int64 result; // x0
  _BYTE v6[32]; // [xsp-20h] [xbp-20h] BYREF

  v2 = 0;
  do
  {
    ++v2;
    v3 = a1 % 0xA;
    a1 /= 0xAu;
    v6[v2 - 1] = v3 + 48;
    if ( a1 == 0 )
    {
      v4 = v2 - 1;
      goto LABEL_5;
    }
  }
  while ( v2 != 31 );
  v4 = 30;
LABEL_5:
  result = 0;
  do
  {
    *(_BYTE *)(a2 + result) = v6[v4 - result];
    ++result;
  }
  while ( result != v2 );
  *(_BYTE *)(a2 + result) = 0;
  return result;
}

/* ===== sub_940444E8 @ 0x940444E8 size 296 ===== */
__int64 __fastcall sub_940444E8(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x22
  __int64 v7; // x24
  __int64 v8; // x0
  __int64 v9; // x27
  __int64 v10; // x20
  __int64 v11; // x21
  __int64 v12; // x0
  __int64 v13; // x19

  v6 = sub_94046414(a2);
  v7 = sub_94046414(a3);
  if ( *a1 != 0 )
  {
    v8 = sub_94046414(*a1);
    v9 = v8;
    if ( v8 != 0 )
    {
      v10 = v8 + 1;
      v11 = v8 + 1 + v6;
      v12 = sub_94046748(v7 + 2 + v11);
      v13 = v12;
      if ( v12 != 0 )
      {
        if ( v10 != 0 )
        {
          sub_940463E0(v12, *a1, v9);
          *(_BYTE *)(v13 + v9) = 32;
        }
        goto LABEL_6;
      }
      return 0;
    }
  }
  v13 = sub_94046748(v6 + v7 + 2);
  if ( v13 == 0 )
    return 0;
  v11 = v6;
  v10 = 0;
LABEL_6:
  sub_940463E0(v13 + v10, a2, v6);
  *(_BYTE *)(v13 + v11) = 61;
  sub_940463E0(v13 + v11 + 1, a3, v7);
  if ( *a1 != 0 )
    sub_94046430(*a1);
  *a1 = v13;
  return 1;
}

/* ===== sub_94044610 @ 0x94044610 size 204 ===== */
__int64 __fastcall sub_94044610(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v5; // x19
  __int64 result; // x0
  __int64 v7; // x3
  __int64 i; // x0
  char v9; // w4
  unsigned int v10; // w20
  char v13[24]; // [xsp+48h] [xbp+48h] BYREF

  v3 = 2 * a3;
  strcpy(v13, "0123456789abcdef");
  v5 = sub_94046700(2 * a3 + 1);
  result = 0;
  if ( v5 != 0 )
  {
    v7 = v5;
    for ( i = 0; i != a3; ++i )
    {
      v7 += 2;
      *(_BYTE *)(v7 - 2) = v13[*(_BYTE *)(a2 + i) >> 4];
      v9 = *(_BYTE *)(a2 + i);
      *(_BYTE *)(v7 - 1) = v13[v9 & 0xF];
    }
    *(_BYTE *)(v5 + v3) = 0;
    v10 = sub_940444E8((__int64 *)(a1 + 40), (__int64)"androidboot.vbmeta.digest", v5);
    sub_94046430(v5);
    return v10;
  }
  return result;
}

/* ===== sub_940446DC @ 0x940446DC size 4620 ===== */
__int64 __fastcall sub_940446DC(
        __int64 a1,
        __int64 *a2,
        __int64 a3,
        unsigned int a4,
        int a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        __int64 a17,
        _QWORD *a18,
        _DWORD *a19,
        __int64 a20)
{
  int v28; // w20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w20
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned __int64 v48; // x20
  __int64 v49; // x25
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x1
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 v100; // x0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x3
  unsigned int v110; // w0
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  int v119; // w0
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  unsigned __int64 v144; // x0
  __int64 v145; // x1
  __int64 v146; // x22
  __int64 v147; // x24
  __int64 v148; // x0
  __int64 v149; // x4
  __int64 v150; // x3
  __int64 v151; // x1
  unsigned __int64 v152; // x1
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  double v169; // d0
  double v170; // d1
  double v171; // d2
  double v172; // d3
  double v173; // d4
  double v174; // d5
  double v175; // d6
  double v176; // d7
  __int64 v177; // x24
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  __int64 v194; // x23
  __int64 v195; // x0
  __int64 v196; // x19
  __int64 v197; // x0
  __int64 v198; // x28
  unsigned int v199; // w0
  double v200; // d0
  double v201; // d1
  double v202; // d2
  double v203; // d3
  double v204; // d4
  double v205; // d5
  double v206; // d6
  double v207; // d7
  double v208; // d0
  double v209; // d1
  double v210; // d2
  double v211; // d3
  double v212; // d4
  double v213; // d5
  double v214; // d6
  double v215; // d7
  _QWORD *v216; // x23
  double v217; // d0
  double v218; // d1
  double v219; // d2
  double v220; // d3
  double v221; // d4
  double v222; // d5
  double v223; // d6
  double v224; // d7
  __int64 v225; // x3
  int v226; // w4
  double v227; // d0
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  double v235; // d0
  double v236; // d1
  double v237; // d2
  double v238; // d3
  double v239; // d4
  double v240; // d5
  double v241; // d6
  double v242; // d7
  __int64 v243; // x23
  __int64 v244; // x19
  double v245; // d0
  double v246; // d1
  double v247; // d2
  double v248; // d3
  double v249; // d4
  double v250; // d5
  double v251; // d6
  double v252; // d7
  __int64 v253; // x0
  double v254; // d0
  double v255; // d1
  double v256; // d2
  double v257; // d3
  double v258; // d4
  double v259; // d5
  double v260; // d6
  double v261; // d7
  __int64 v262; // x0
  double v263; // d0
  double v264; // d1
  double v265; // d2
  double v266; // d3
  double v267; // d4
  double v268; // d5
  double v269; // d6
  double v270; // d7
  int v271; // w0
  __int64 v272; // x0
  char *v273; // x23
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  __int64 v282; // x0
  double v283; // d0
  double v284; // d1
  double v285; // d2
  double v286; // d3
  double v287; // d4
  double v288; // d5
  double v289; // d6
  double v290; // d7
  __int64 v291; // x0
  __int64 v292; // x0
  __int64 v293; // x28
  __int64 v294; // x19
  __int64 v295; // x0
  double v296; // d0
  double v297; // d1
  double v298; // d2
  double v299; // d3
  double v300; // d4
  double v301; // d5
  double v302; // d6
  double v303; // d7
  __int64 v304; // x2
  const char *v305; // x2
  double v306; // d0
  double v307; // d1
  double v308; // d2
  double v309; // d3
  double v310; // d4
  double v311; // d5
  double v312; // d6
  double v313; // d7
  __int64 v314; // x0
  double v315; // d0
  double v316; // d1
  double v317; // d2
  double v318; // d3
  double v319; // d4
  double v320; // d5
  double v321; // d6
  double v322; // d7
  __int64 v323; // x0
  __int64 v324; // x1
  __int64 v325; // x19
  __int64 v326; // x23
  __int64 v327; // x0
  __int64 v328; // x4
  __int64 v329; // x3
  double v330; // d0
  double v331; // d1
  double v332; // d2
  double v333; // d3
  double v334; // d4
  double v335; // d5
  double v336; // d6
  double v337; // d7
  __int64 v338; // x0
  __int64 v339; // x1
  __int64 v340; // x19
  __int64 v341; // x23
  __int64 v342; // x0
  __int64 v343; // x1
  double v344; // d0
  double v345; // d1
  double v346; // d2
  double v347; // d3
  double v348; // d4
  double v349; // d5
  double v350; // d6
  double v351; // d7
  double v352; // d0
  double v353; // d1
  double v354; // d2
  double v355; // d3
  double v356; // d4
  double v357; // d5
  double v358; // d6
  double v359; // d7
  double v360; // d0
  double v361; // d1
  double v362; // d2
  double v363; // d3
  double v364; // d4
  double v365; // d5
  double v366; // d6
  double v367; // d7
  __int64 v368; // [xsp+80h] [xbp+60h]
  int v369; // [xsp+98h] [xbp+78h]
  unsigned int v370; // [xsp+9Ch] [xbp+7Ch]
  __int64 v371; // [xsp+A0h] [xbp+80h]
  unsigned int v372; // [xsp+A8h] [xbp+88h]
  __int64 v373; // [xsp+A8h] [xbp+88h]
  char v374; // [xsp+B0h] [xbp+90h]
  unsigned int v375; // [xsp+C8h] [xbp+A8h]
  int v376; // [xsp+D8h] [xbp+B8h]
  __int64 v377; // [xsp+D8h] [xbp+B8h]
  BOOL v378; // [xsp+E8h] [xbp+C8h]
  __int64 v379; // [xsp+E8h] [xbp+C8h]
  __int64 v380; // [xsp+F0h] [xbp+D0h]
  BOOL v381; // [xsp+F0h] [xbp+D0h]
  int v382; // [xsp+F8h] [xbp+D8h]
  unsigned __int64 v383; // [xsp+108h] [xbp+E8h] BYREF
  __int64 v384; // [xsp+110h] [xbp+F0h] BYREF
  __int64 v385; // [xsp+118h] [xbp+F8h] BYREF
  unsigned __int64 v386; // [xsp+120h] [xbp+100h] BYREF
  unsigned __int64 v387; // [xsp+128h] [xbp+108h] BYREF
  __int64 v388; // [xsp+130h] [xbp+110h] BYREF
  char v389[32]; // [xsp+140h] [xbp+120h] BYREF
  char v390[32]; // [xsp+160h] [xbp+140h] BYREF
  _QWORD v391[3]; // [xsp+180h] [xbp+160h] BYREF
  unsigned int v392[28]; // [xsp+198h] [xbp+178h] BYREF
  _QWORD v393[32]; // [xsp+208h] [xbp+1E8h] BYREF
  unsigned int v394[4]; // [xsp+308h] [xbp+2E8h] BYREF
  int v395; // [xsp+318h] [xbp+2F8h]
  __int64 v396; // [xsp+31Ch] [xbp+2FCh]
  unsigned __int64 v397; // [xsp+324h] [xbp+304h]

  if ( a18 == nullptr )
    sub_940407DC(0, "assert fail: slot_data != NULL\n", a9, a10, a11, a12, a13, a14, a15, a16);
  v28 = sub_94046410(a6, (__int64)"vbmeta");
  if ( (unsigned int)sub_94046570(a6, a7) == 0 )
  {
    v37 = 6;
    sub_940407DC(0, "Partition name is not valid UTF-8.\n", v29, v30, v31, v32, v33, v34, v35, v36);
    return v37;
  }
  v39 = sub_94046414(a3);
  if ( (unsigned int)sub_94046608(v389, 32, a6, a7, a3, v39) == 0 )
  {
    v37 = 6;
    sub_940407DC(0, "Partition name and suffix does not fit.\n", v40, v41, v42, v43, v44, v45, v46, v47);
    return v37;
  }
  v378 = v28 == 0;
  sub_940407DC(7u, "Loading vbmeta struct from partition '%s'.\n", v40, v41, v42, v43, v44, v45, v46, v47, v389, 0);
  if ( v28 != 0 )
  {
    if ( (unsigned int)sub_94046410(a6, (__int64)"system") != 0
      && (unsigned int)sub_94046410(a6, (__int64)"vendor") != 0 )
    {
      v199 = (*(__int64 (__fastcall **)(__int64, char *, __int64, __int64, _QWORD *, _QWORD *))(a1 + 24))(
               a1,
               v389,
               -64,
               64,
               v393,
               v391);
      if ( v199 == 1 )
      {
        v37 = 1;
        sub_940407DC(
          7u,
          "in %s, l:%d, return err %d. \n",
          v200,
          v201,
          v202,
          v203,
          v204,
          v205,
          v206,
          v207,
          "load_and_verify_vbmeta",
          327);
        return v37;
      }
      if ( v199 != 0 )
      {
        v37 = 2;
        sub_940407DC(0, v389, v200, v201, v202, v203, v204, v205, v206, v207, ": Error loading footer.\n", 0, v199);
        return v37;
      }
      if ( v391[0] != 64 )
        sub_940407DC(
          0,
          "assert fail: footer_num_read == AVB_FOOTER_SIZE\n",
          v200,
          v201,
          v202,
          v203,
          v204,
          v205,
          v206,
          v207);
      if ( (unsigned int)sub_94042FF4((__int64)v393, (__int64)v394) == 0 )
      {
        v37 = 6;
        sub_940407DC(0, v389, v208, v209, v210, v211, v212, v213, v214, v215, ": Error validating footer.\n", 0);
        return v37;
      }
      v48 = v397;
      if ( v397 > 0x10000 )
      {
        v37 = 6;
        sub_940407DC(0, v389, v208, v209, v210, v211, v212, v213, v214, v215, ": Invalid vbmeta size in footer.\n", 0);
        return v37;
      }
      v380 = v396;
    }
    else
    {
      v380 = 0;
      v48 = MEMORY[0xFFFFFFFFE0064404];
    }
  }
  else
  {
    v380 = 0;
    v48 = MEMORY[0xFFFFFFFFE0064408];
  }
  v49 = sub_94046700(v48);
  if ( v49 == 0 )
  {
    v37 = 1;
    sub_940407DC(
      7u,
      "in %s, l:%d, return err %d. \n",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "load_and_verify_vbmeta",
      358);
    return v37;
  }
  sub_940407DC(7u, ">>> begin to load vbmeta image of partition:%s.\n", v50, v51, v52, v53, v54, v55, v56, v57, v389, 0);
  v58 = (*(__int64 (__fastcall **)(__int64, char *, __int64, unsigned __int64, __int64, unsigned __int64 *))(a1 + 24))(
          a1,
          v389,
          v380,
          v48,
          v49,
          &v383);
  if ( v58 == 1 )
  {
    v37 = 1;
    sub_940407DC(
      7u,
      "in %s, l:%d, return err %d. \n",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "load_and_verify_vbmeta",
      371);
    goto LABEL_27;
  }
  v381 = a5 == 0;
  if ( v58 != 0 )
  {
    if ( v378 && a5 == 0 && v58 == 3 )
    {
      sub_940407DC(7u, v389, v59, v60, v61, v62, v63, v64, v65, v66, ": No such partition. Trying 'boot' instead.\n", 0);
      v272 = sub_94046414("boot");
      v37 = sub_940446DC(a1, a2, a3, a4, 0, "boot", v272, 0, 0, a18, a19, a20);
    }
    else
    {
      v37 = 2;
      sub_940407DC(0, v389, v59, v60, v61, v62, v63, v64, v65, v66, ": Error loading vbmeta data.\n", 0, v58);
    }
    goto LABEL_27;
  }
  if ( v48 < v383 )
    sub_940407DC(0, "assert fail: vbmeta_num_read <= vbmeta_size\n", v59, v60, v61, v62, v63, v64, v65, v66);
  if ( !v378 || MEMORY[0xFFFFFFFFE0057F10] == 0 )
  {
    v375 = sub_94046B5C(v49, v383, &v384, &v385, 0);
    sub_940407DC(
      7u,
      "partition: %s vbmeta_verify_ret is :%d. \n",
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v389,
      v375,
      0);
    switch ( v375 )
    {
      case 0u:
        if ( v384 == 0 || (v37 = 0, v385 == 0) )
        {
          v37 = 0;
          sub_940407DC(0, "assert fail: pk_data != NULL && pk_len > 0\n", v92, v93, v94, v95, v96, v97, v98, v99);
        }
        goto LABEL_18;
      case 1u:
      case 4u:
      case 5u:
        v37 = 3;
        v100 = sub_94047050(v375);
        sub_940407DC(
          0,
          v389,
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          ": Error verifying vbmeta image: ",
          v100,
          "\n",
          0);
        if ( a4 != 0 )
          goto LABEL_18;
        goto LABEL_27;
      case 2u:
        v37 = 6;
        sub_940407DC(
          0,
          v389,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          ": Error verifying vbmeta image: invalid vbmeta header\n",
          0);
        goto LABEL_27;
      case 3u:
        v37 = 7;
        sub_940407DC(
          0,
          v389,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          ": Error verifying vbmeta image: unsupported AVB version\n",
          0);
        goto LABEL_27;
      default:
        v37 = 0;
        goto LABEL_18;
    }
  }
  v37 = 0;
  v375 = 0;
  v384 = 0;
  v385 = 0;
LABEL_18:
  sub_94046A64(v49, v393);
  if ( a5 != 0 )
  {
    v374 = 0;
    if ( LODWORD(v393[15]) != 0 )
    {
      v37 = 6;
      sub_940407DC(0, v389, v67, v68, v69, v70, v71, v72, v73, v74, ": chained vbmeta image has non-zero flags\n", 0);
      goto LABEL_27;
    }
  }
  else
  {
    v374 = v393[15];
  }
  if ( v384 != 0 )
  {
    nullsub_9("pk_data", v384, (unsigned int)v385);
    v83 = v384;
    if ( v384 != 0 )
    {
      if ( a8 != 0 )
      {
        if ( a5 == 0 )
          sub_940407DC(0, "assert fail: !is_main_vbmeta\n", v75, v76, v77, v78, v79, v80, v81, v82);
        if ( v385 != a17 || (unsigned int)sub_9404649C(a8, v384, a17) != 0 )
        {
          v37 = 5;
          sub_940407DC(
            0,
            v389,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            ": Public key used to sign data does not match key in chain partition descriptor.\n",
            0);
          if ( a4 == 0 )
            goto LABEL_27;
        }
      }
      else
      {
        v394[0] = 0;
        v109 = 0;
        if ( v393[11] != 0 )
          v109 = v49 + *(_QWORD *)((char *)&v393[1] + 4) + v393[10] + 256LL;
        if ( a5 != 0 )
        {
          v373 = v109;
          sub_940407DC(0, "assert fail: is_main_vbmeta\n", v75, v76, v77, v78, v79, v80, v81, v82);
          v109 = v373;
          v83 = v384;
        }
        v110 = (*(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 40))(a1, v83, v385, v109);
        if ( v110 == 1 )
        {
          v37 = 1;
          sub_940407DC(
            7u,
            "in %s, l:%d, return err %d. \n",
            v111,
            v112,
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            "load_and_verify_vbmeta",
            508);
          goto LABEL_27;
        }
        if ( v110 != 0 )
        {
          v37 = 2;
          sub_940407DC(
            0,
            v389,
            v111,
            v112,
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            ": Error while checking public key used to sign data.\n",
            0,
            v110);
          goto LABEL_27;
        }
        if ( v394[0] == 0 )
        {
          v37 = 5;
          sub_940407DC(
            0,
            v389,
            v111,
            v112,
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            ": Public key used to sign data rejected.\n",
            0,
            v110);
          if ( a4 == 0 )
            goto LABEL_27;
        }
        if ( v378 )
          MEMORY[0xFFFFFFFFE0057F10] = 1;
      }
    }
  }
  v379 = a5;
  v119 = (*(__int64 (__fastcall **)(__int64, _QWORD, unsigned __int64 *))(a1 + 48))(a1, a5, &v386);
  if ( v119 == 1 )
  {
    v37 = 1;
    goto LABEL_27;
  }
  if ( v119 != 0 )
  {
    v37 = 2;
    sub_940407DC(
      0,
      v389,
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      v127,
      ": Error getting rollback index for location.\n",
      0);
    goto LABEL_27;
  }
  if ( v393[14] >= v386 )
  {
    sub_940407DC(
      7u,
      "Info: vbmeta_header.rollback_index:%d, >= stored_rollback_index:%d.\n",
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      v127);
    v144 = v393[14];
    *(_DWORD *)(4LL * a5 - 536460624) = v393[14];
  }
  else
  {
    v37 = 4;
    sub_940407DC(
      7u,
      "Error: vbmeta_header.rollback_index:%d, < stored_rollback_index:%d.\n",
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      v127);
    sub_940407DC(
      0,
      v389,
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      v135,
      ": Image rollback index is less than the stored rollback index.\n",
      0);
    if ( a4 == 0 )
      goto LABEL_27;
    v144 = v393[14];
    *(_DWORD *)(4LL * a5 - 536460624) = v386;
  }
  if ( v386 < v144 )
  {
    sub_940407DC(7u, "set update version flag.\n", v136, v137, v138, v139, v140, v141, v142, v143);
    MEMORY[0xFFFFFFFFE00642E4] = 1;
  }
  if ( a5 != 0 )
  {
    v291 = a18[2];
    if ( v291 == 0 )
    {
      sub_940407DC(0, "assert fail: slot_data->num_vbmeta_images > 0\n", v136, v137, v138, v139, v140, v141, v142, v143);
      v291 = a18[2];
    }
  }
  else
  {
    v145 = a18[2];
    if ( v145 == 0 )
      goto LABEL_65;
    sub_940407DC(0, "assert fail: slot_data->num_vbmeta_images == 0\n", v136, v137, v138, v139, v140, v141, v142, v143);
    v291 = a18[2];
  }
  v145 = v291;
  if ( v291 == 32 )
  {
    v37 = 1;
    sub_940407DC(0, v389, v136, v137, v138, v139, v140, v141, v142, v143, ": Too many vbmeta images.\n", 0);
    goto LABEL_27;
  }
LABEL_65:
  v146 = 32 * v145;
  v147 = a18[1];
  a18[2] = v145 + 1;
  v148 = sub_94046780(a6);
  v149 = v147 + v146;
  v150 = *(_QWORD *)((char *)&v393[1] + 4);
  v151 = *(_QWORD *)((char *)&v393[2] + 4);
  *(_QWORD *)(v147 + v146) = v148;
  *(_QWORD *)(v149 + 16) = v150 + v151 + 256;
  v152 = v383;
  *(_QWORD *)(v149 + 8) = v49;
  *(_DWORD *)(v149 + 24) = v375;
  v49 = sub_94042F48(v49, v152, &v387, v153, v154, v155, v156, v157, v158, v159, v160);
  sub_940407DC(
    7u,
    "in %s, l:%d. num_descriptors:%d.\n",
    v161,
    v162,
    v163,
    v164,
    v165,
    v166,
    v167,
    v168,
    "load_and_verify_vbmeta",
    605,
    v387,
    0);
  if ( v387 != 0 )
  {
    v376 = v37;
    v177 = 0;
    v382 = 0;
    v372 = a4;
    v369 = a5;
    while ( 1 )
    {
      if ( (unsigned int)sub_94042CC8(*(_QWORD **)(v49 + 8 * v177), &v388) == 0 )
      {
        v37 = 6;
        sub_940407DC(0, v389, v178, v179, v180, v181, v182, v183, v184, v185, &loc_940562B0, 0);
        goto LABEL_27;
      }
      sub_940407DC(
        7u,
        "in %s, l:%d. desc.tag:0x%llx.\n",
        v178,
        v179,
        v180,
        v181,
        v182,
        v183,
        v184,
        v185,
        "load_and_verify_vbmeta",
        615,
        v388,
        0);
      switch ( v388 )
      {
        case 3LL:
          if ( (unsigned int)sub_940431E4(*(_QWORD **)(v49 + 8 * v177), (__int64)v394) == 0 )
          {
            v37 = 6;
            sub_940407DC(
              0,
              v389,
              v186,
              v187,
              v188,
              v189,
              v190,
              v191,
              v192,
              v193,
              ": Kernel cmdline descriptor is invalid.\n",
              0);
            goto LABEL_27;
          }
          v194 = *(_QWORD *)(v49 + 8 * v177) + 24LL;
          if ( (unsigned int)sub_94046570(v194, (unsigned int)v396) == 0 )
          {
            v37 = 6;
            sub_940407DC(
              0,
              v389,
              v169,
              v170,
              v171,
              v172,
              v173,
              v174,
              v175,
              v176,
              ": Kernel cmdline is not valid UTF-8.\n",
              0);
            sub_940407DC(
              7u,
              "in %s, l:%d. \n",
              v360,
              v361,
              v362,
              v363,
              v364,
              v365,
              v366,
              v367,
              "load_and_verify_vbmeta",
              727,
              0);
            goto LABEL_27;
          }
          if ( (v374 & 1) != 0 )
          {
            if ( (v395 & 1) == 0 )
              goto LABEL_76;
          }
          else if ( (v395 & 2) == 0 )
          {
LABEL_76:
            v195 = a18[5];
            if ( v195 != 0 )
            {
              v196 = sub_94046414(v195);
              v197 = sub_94046748((unsigned int)v396 + 2LL + v196);
              v198 = v197;
              if ( v197 == 0 )
                goto LABEL_165;
              sub_940463E0(v197, a18[5], v196);
              *(_BYTE *)(v198 + v196) = 32;
              sub_940463E0(v198 + v196 + 1, v194, (unsigned int)v396);
              sub_94046430(a18[5]);
              a18[5] = v198;
            }
            else
            {
              v314 = sub_94046748((unsigned int)(v396 + 1));
              a18[5] = v314;
              if ( v314 == 0 )
              {
LABEL_165:
                v37 = 1;
                goto LABEL_27;
              }
              sub_940463E0(v314, v194, (unsigned int)v396);
            }
          }
          break;
        case 4LL:
          if ( v382 == 0 )
          {
            if ( !v381 )
            {
              v37 = 6;
              sub_940407DC(
                0,
                v389,
                v169,
                v170,
                v171,
                v172,
                v173,
                v174,
                v175,
                v176,
                ": Encountered chain descriptor not in main image.\n",
                0);
              sub_940407DC(
                7u,
                "in %s, l:%d, return err %d. \n",
                v352,
                v353,
                v354,
                v355,
                v356,
                v357,
                v358,
                v359,
                "load_and_verify_vbmeta",
                650,
                6,
                0);
              goto LABEL_27;
            }
            if ( (unsigned int)sub_94042B10(*(_QWORD *)(v49 + 8 * v177), (__int64)v394) == 0 )
            {
              v37 = 6;
              sub_940407DC(
                0,
                v389,
                v235,
                v236,
                v237,
                v238,
                v239,
                v240,
                v241,
                v242,
                ": Chain partition descriptor is invalid.\n",
                0);
              sub_940407DC(
                7u,
                "in %s, l:%d, return err %d. \n",
                v344,
                v345,
                v346,
                v347,
                v348,
                v349,
                v350,
                v351,
                "load_and_verify_vbmeta",
                660,
                6,
                0);
              goto LABEL_27;
            }
            if ( v395 == 0 )
            {
              v37 = 6;
              sub_940407DC(
                0,
                v389,
                v235,
                v236,
                v237,
                v238,
                v239,
                v240,
                v241,
                v242,
                ": Chain partition has invalid rollback_index_location field.\n",
                0);
              goto LABEL_27;
            }
            v243 = (unsigned int)v396;
            v244 = *(_QWORD *)(v49 + 8 * v177) + 92LL;
            if ( *(_QWORD *)(v49 + 8 * v177) != -92 && *a2 != 0 && (unsigned int)sub_940463DC(v244, *a2, v396) != 0 )
            {
              v376 = 6;
              sub_940407DC(
                7u,
                "Info::>>> chain_partition_name:%s != requested_partitions[0]:%s. skip .... \n",
                v245,
                v246,
                v247,
                v248,
                v249,
                v250,
                v251,
                v252,
                v244,
                *a2,
                0);
            }
            else
            {
              v253 = sub_94046700((unsigned int)(v396 + 1));
              *(_QWORD *)(a20 + 8) = v253;
              if ( v253 != 0 )
              {
                sub_940463E0(v253, v244, (unsigned int)v396);
                *(_BYTE *)(*(_QWORD *)(a20 + 8) + (unsigned int)v396) = 0;
              }
              else
              {
                sub_940407DC(0, "partname buffer NULL\n", v254, v255, v256, v257, v258, v259, v260, v261);
              }
              v262 = sub_94046700(HIDWORD(v396));
              *(_QWORD *)(a20 + 16) = v262;
              if ( v262 != 0 )
                sub_940463E0(v262, v244 + v243, HIDWORD(v396));
              else
                sub_940407DC(0, (const char *)&loc_94056568, v263, v264, v265, v266, v267, v268, v269, v270);
              v382 = 1;
              v271 = v395;
              v376 = 0;
              *(_QWORD *)(a20 + 24) = HIDWORD(v396);
              *(_DWORD *)a20 = v271;
            }
          }
          break;
        case 2LL:
          v216 = *(_QWORD **)(v49 + 8 * v177);
          if ( (unsigned int)sub_940430CC(v216, (__int64)v391) == 0 )
          {
            v225 = 100;
            v226 = 6;
            goto LABEL_89;
          }
          v273 = (char *)v216 + 132;
          v371 = v392[8];
          v370 = v392[9];
          if ( (unsigned int)sub_94046570(v273, v392[8]) == 0 )
          {
            v37 = 6;
            sub_940407DC(0, "Partition name is not valid UTF-8.\n", v274, v275, v276, v277, v278, v279, v280, v281);
            v225 = 112;
            goto LABEL_90;
          }
          v368 = v392[8];
          v282 = sub_94046414(a3);
          if ( (unsigned int)sub_94046608(v390, 32, v273, v368, a3, v282) == 0 )
          {
            v37 = 6;
            sub_940407DC(0, "Partition name and suffix does not fit.\n", v283, v284, v285, v286, v287, v288, v289, v290);
            goto LABEL_91;
          }
          v292 = sub_940407DC(
                   7u,
                   "in %s, l:%d.hash_desc.image_size:0x%llx.\n",
                   v283,
                   v284,
                   v285,
                   v286,
                   v287,
                   v288,
                   v289,
                   v290,
                   "load_and_verify_hash_partition",
                   127,
                   v391[2],
                   0);
          v293 = sub_940475E8(v292);
          if ( v293 == 0 )
          {
            v225 = 135;
            v226 = 1;
LABEL_89:
            v37 = v226;
LABEL_90:
            sub_940407DC(
              7u,
              "in %s, l:%d, return err %d. \n",
              v217,
              v218,
              v219,
              v220,
              v221,
              v222,
              v223,
              v224,
              "load_and_verify_hash_partition",
              v225);
LABEL_91:
            sub_940407DC(
              7u,
              "in %s, l:%d.sub_ret:%d.\n",
              v227,
              v228,
              v229,
              v230,
              v231,
              v232,
              v233,
              v234,
              "load_and_verify_vbmeta",
              627,
              v37,
              0);
            goto LABEL_92;
          }
          v294 = (__int64)&v273[v371];
          sub_940407DC(
            7u,
            "in %s, l:%d. Warning: Read partition to be verified... name:%s, size:0x%llx >>>>> \n",
            v217,
            v218,
            v219,
            v220,
            v221,
            v222,
            v223,
            v224,
            "load_and_verify_hash_partition",
            139,
            v390,
            v391[2],
            0);
          if ( (unsigned int)sub_94046410((__int64)v392, (__int64)"sha256") != 0 )
          {
            if ( (unsigned int)sub_94046410((__int64)v392, (__int64)"sha512") != 0 )
            {
              v305 = ": Unsupported hash algorithm.\n";
              v37 = 6;
              goto LABEL_126;
            }
            sub_94044178((__int64)v394);
            sub_94044224((__int64)v394, v294, v392[9]);
            sub_94044224((__int64)v394, v293, v391[2]);
            v295 = sub_94044304((__int64)v394);
            v304 = 64;
          }
          else
          {
            sub_94043BDC(v394);
            sub_94043C48(v394, v294, v392[9]);
            sub_94043C48(v394, v293, v391[2]);
            v295 = sub_94043D28((__int64)v394);
            v304 = 32;
          }
          if ( v392[10] != v304 )
          {
            v305 = ": Digest in descriptor not of expected size.\n";
            v37 = 6;
            goto LABEL_126;
          }
          if ( (unsigned int)sub_9404649C(v295, v294 + v370, v304) != 0 )
          {
            sub_940407DC(
              0,
              v390,
              v315,
              v316,
              v317,
              v318,
              v319,
              v320,
              v321,
              v322,
              ": Hash of data does not match digest in descriptor.\n",
              0);
            v338 = sub_9404684C(a2, v273, v392[8]);
            if ( v338 != 0 )
            {
              v339 = a18[4];
              if ( v339 == 32 )
              {
LABEL_163:
                v305 = ": Too many loaded partitions.\n";
                v37 = 1;
LABEL_126:
                sub_940407DC(0, v390, v296, v297, v298, v299, v300, v301, v302, v303, v305, 0);
                sub_940407DC(
                  7u,
                  "in %s, l:%d.sub_ret:%d.\n",
                  v306,
                  v307,
                  v308,
                  v309,
                  v310,
                  v311,
                  v312,
                  v313,
                  "load_and_verify_vbmeta",
                  627,
                  v37,
                  0);
LABEL_92:
                sub_940407DC(
                  7u,
                  "in %s, l:%d. \n",
                  v169,
                  v170,
                  v171,
                  v172,
                  v173,
                  v174,
                  v175,
                  v176,
                  "load_and_verify_vbmeta",
                  632,
                  0);
                goto LABEL_27;
              }
              v340 = 24 * v339;
              v377 = a18[3];
              v341 = v377 + 24 * v339;
              a18[4] = v339 + 1;
              v342 = sub_94046780(v338);
              v343 = v391[2];
              *(_QWORD *)(v377 + v340) = v342;
              *(_QWORD *)(v341 + 16) = v343;
              *(_QWORD *)(v341 + 8) = v293;
            }
            sub_940407DC(
              7u,
              "in %s, l:%d.sub_ret:%d.\n",
              v296,
              v297,
              v298,
              v299,
              v300,
              v301,
              v302,
              v303,
              "load_and_verify_vbmeta",
              627,
              3,
              0);
            if ( v372 == 0 )
            {
              v37 = 3;
              goto LABEL_92;
            }
            v376 = 3;
          }
          else
          {
            v323 = sub_9404684C(a2, v273, v392[8]);
            if ( v323 != 0 )
            {
              v324 = a18[4];
              if ( v324 == 32 )
                goto LABEL_163;
              v325 = 24 * v324;
              v326 = a18[3];
              a18[4] = v324 + 1;
              v327 = sub_94046780(v323);
              v328 = v326 + v325;
              v329 = v391[2];
              *(_QWORD *)(v326 + v325) = v327;
              *(_QWORD *)(v328 + 16) = v329;
              *(_QWORD *)(v328 + 8) = v293;
              sub_940407DC(
                7u,
                "in %s, l:%d.sub_ret:%d.\n",
                v330,
                v331,
                v332,
                v333,
                v334,
                v335,
                v336,
                v337,
                "load_and_verify_vbmeta",
                627,
                0,
                0);
            }
            else
            {
              sub_940407DC(
                7u,
                "in %s, l:%d.sub_ret:%d.\n",
                v296,
                v297,
                v298,
                v299,
                v300,
                v301,
                v302,
                v303,
                "load_and_verify_vbmeta",
                627,
                0,
                0);
            }
          }
          break;
        default:
          break;
      }
      if ( ++v177 >= v387 )
      {
        v37 = v376;
        a5 = v369;
        break;
      }
    }
  }
  if ( a5 <= 31 )
  {
    a18[v379 + 6] = v393[14];
    if ( a19 != nullptr )
      *a19 = HIDWORD(v393[3]);
    if ( v49 == 0 )
      return v37;
LABEL_27:
    sub_94046430(v49);
    return v37;
  }
  v37 = 6;
  sub_940407DC(0, v389, v169, v170, v171, v172, v173, v174, v175, v176, ": Invalid rollback_index_location.\n", 0);
  if ( v49 != 0 )
    goto LABEL_27;
  return v37;
}

/* ===== sub_940458E8 @ 0x940458E8 size 220 ===== */
__int64 __fastcall sub_940458E8(__int64 *a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  unsigned __int64 v5; // x20
  __int64 v6; // x1
  __int64 v7; // x21
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x2
  unsigned __int64 v11; // x3
  __int64 v12; // x21
  unsigned __int64 i; // x20
  __int64 v14; // x1

  v2 = *a1;
  if ( v2 != 0 )
    sub_94046430(v2);
  v3 = a1[5];
  if ( v3 != 0 )
    sub_94046430(v3);
  v4 = a1[1];
  if ( v4 != 0 )
  {
    if ( a1[2] != 0 )
    {
      v5 = 0;
      do
      {
        v6 = 32 * v5++;
        v7 = v4 + v6;
        v8 = *(_QWORD *)(v4 + v6);
        if ( v8 != 0 )
          sub_94046430(v8);
        v9 = *(_QWORD *)(v7 + 8);
        if ( v9 != 0 )
          sub_94046430(v9);
        v4 = a1[1];
      }
      while ( a1[2] > v5 );
    }
    sub_94046430(v4);
  }
  v10 = a1[3];
  if ( v10 != 0 )
  {
    v11 = a1[4];
    if ( v11 != 0 )
    {
      v12 = 0;
      for ( i = 0; i < v11; ++i )
      {
        v14 = *(_QWORD *)(v10 + v12);
        v12 += 24;
        if ( v14 != 0 )
        {
          sub_94046430(v14);
          v11 = a1[4];
          v10 = a1[3];
        }
      }
    }
    sub_94046430(v10);
  }
  return sub_94046430((__int64)a1);
}

/* ===== sub_940459C4 @ 0x940459C4 size 2384 ===== */
__int64 __fastcall sub_940459C4(
        __int64 a1,
        __int64 *a2,
        __int64 a3,
        unsigned int a4,
        __int64 *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v18; // x19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w20
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v72; // x0
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned int v81; // w0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  __int64 v106; // x0
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  int v123; // w0
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  const char *v132; // x6
  const char *v133; // x5
  __int64 v134; // x28
  __int64 v135; // x0
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  int v144; // w0
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  __int64 v153; // x1
  __int64 v154; // x1
  __int64 v155; // x0
  int v156; // w0
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  const char *v165; // x2
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  __int64 v182; // x1
  unsigned __int64 v183; // x26
  unsigned __int64 v184; // x25
  __int64 v185; // x23
  __int64 v186; // x2
  __int64 v187; // x1
  unsigned __int64 v188; // x26
  unsigned __int64 v189; // x25
  __int64 v190; // x23
  __int64 v191; // x2
  double v192; // d0
  double v193; // d1
  double v194; // d2
  double v195; // d3
  double v196; // d4
  double v197; // d5
  double v198; // d6
  double v199; // d7
  __int64 v200; // x0
  __int64 v201; // x0
  __int64 v202; // [xsp+80h] [xbp+60h]
  __int64 v203; // [xsp+90h] [xbp+70h]
  __int64 v204; // [xsp+90h] [xbp+70h]
  __int64 *v205; // [xsp+98h] [xbp+78h]
  __int64 v206; // [xsp+A0h] [xbp+80h]
  __int64 v207; // [xsp+A0h] [xbp+80h]
  int v208; // [xsp+A8h] [xbp+88h]
  __int64 v209; // [xsp+B0h] [xbp+90h]
  int v210; // [xsp+B8h] [xbp+98h]
  __int64 v211; // [xsp+B8h] [xbp+98h]
  unsigned int v212; // [xsp+CCh] [xbp+ACh] BYREF
  _QWORD v213[2]; // [xsp+D0h] [xbp+B0h]
  const char *v214; // [xsp+E0h] [xbp+C0h]
  __int64 v215[4]; // [xsp+E8h] [xbp+C8h] BYREF
  _QWORD v216[4]; // [xsp+108h] [xbp+E8h] BYREF
  _BYTE v217[32]; // [xsp+128h] [xbp+108h] BYREF
  unsigned int v218[98]; // [xsp+148h] [xbp+128h] BYREF

  v212 = 0;
  if ( a5 != nullptr )
    *a5 = 0;
  sub_940407DC(7u, "### enter avb_slot_verify. ###\n", a6, a7, a8, a9, a10, a11, a12, a13);
  v18 = sub_94046748(304);
  if ( v18 == 0 )
  {
    v54 = 1;
    sub_940407DC(7u, "in %s, l:%d. \n", v19, v20, v21, v22, v23, v24, v25, v26, "avb_slot_verify", 1024, 0);
    goto LABEL_10;
  }
  v27 = sub_94046748(1024);
  *(_QWORD *)(v18 + 8) = v27;
  if ( v27 != 0 )
  {
    v36 = sub_94046748(768);
    *(_QWORD *)(v18 + 24) = v36;
    if ( v36 != 0 )
    {
      v45 = sub_94046414("vbmeta");
      v54 = sub_940446DC(
              a1,
              a2,
              a3,
              a4,
              0,
              (__int64)"vbmeta",
              v45,
              0,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              0,
              (_QWORD *)v18,
              &v212,
              (__int64)v215);
      if ( v54 != 0 && a4 == 0 )
        goto LABEL_8;
      sub_940407DC(7u, "allow_verification_error:%d, ret:%d\n", v55, v56, v57, v58, v59, v60, v61, v62, a4, v54, 0);
      v208 = v215[0];
      v209 = v215[1];
      v72 = sub_94046414(v215[1]);
      v81 = sub_940446DC(
              a1,
              a2,
              a3,
              a4,
              v208,
              v209,
              v72,
              v215[2],
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              v215[3],
              (_QWORD *)v18,
              &v212,
              (__int64)v215);
      v54 |= v81;
      sub_940407DC(
        7u,
        "allow_verification_error:%d, subret:%d, ret:%d\n",
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        a4,
        v81,
        v54,
        0);
      if ( v215[1] != 0 )
        sub_94046430(v215[1]);
      if ( v215[2] != 0 )
        sub_94046430(v215[2]);
      if ( v54 != 0 && a4 == 0 )
      {
LABEL_8:
        sub_940407DC(7u, "allow_verification_error:%d, ret:%d\n", v55, v56, v57, v58, v59, v60, v61, v62, 0, v54, 0);
      }
      else
      {
        v210 = 0;
        sub_940407DC(
          7u,
          "in %s, l:%d. load_and_verify_vbmeta ret is %d, algorithm_type: %d. \n",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "avb_slot_verify",
          1088,
          v54,
          v212,
          0);
        if ( (unsigned int)sub_94046410(**(_QWORD **)(v18 + 8), (__int64)"vbmeta") != 0 )
        {
          v210 = 1;
          if ( (unsigned int)sub_94046410(**(_QWORD **)(v18 + 8), (__int64)"boot") != 0 )
            sub_940407DC(
              0,
              "assert fail: avb_strcmp(slot_data->vbmeta_images[0].partition_name, \"boot\") == 0\n",
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              v96,
              v97);
        }
        sub_940407DC(
          7u,
          "in %s, l:%d, %s, %d, %d\n",
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          "avb_slot_verify",
          1097,
          **(_QWORD **)(v18 + 8),
          *(_QWORD *)(v18 + 16),
          *(_QWORD *)(v18 + 32),
          0);
        if ( v54 != 0 && v54 - 3 > 2 )
        {
LABEL_21:
          sub_940407DC(7u, "in %s, l:%d. \n", v98, v99, v100, v101, v102, v103, v104, v105, "avb_slot_verify", 1234, 0);
          return v54;
        }
        v106 = sub_94046780(a3);
        *(_QWORD *)v18 = v106;
        if ( v106 != 0 )
        {
          v205 = (__int64 *)(v18 + 40);
          sub_940407DC(
            7u,
            "in %s, l:%d. \n",
            v107,
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            v114,
            "avb_slot_verify",
            1109,
            0);
          if ( (unsigned int)sub_940444E8(
                               (__int64 *)(v18 + 40),
                               (__int64)"androidboot.vbmeta.device",
                               (__int64)"PARTUUID=$(ANDROID_VBMETA_PARTUUID)") != 0 )
          {
            sub_940407DC(
              7u,
              "in %s, l:%d. \n",
              v115,
              v116,
              v117,
              v118,
              v119,
              v120,
              v121,
              v122,
              "avb_slot_verify",
              1118,
              0);
            v206 = sub_94044464(1u, (__int64)v216);
            v203 = sub_94044464(0, (__int64)v217);
            sub_940463E0(v218, v216, v206);
            *((_BYTE *)v218 + v206) = 46;
            sub_940463E0((char *)v218 + v206 + 1, v217, v203);
            *((_BYTE *)v218 + v206 + v203 + 1) = 0;
            v123 = sub_940444E8(v205, (__int64)"androidboot.vbmeta.avb_version", (__int64)v218);
            v132 = "in %s, l:%d. \n";
            v133 = "avb_slot_verify";
            if ( v123 != 0 )
            {
              v202 = *(_QWORD *)(v18 + 40);
              if ( v202 != 0 )
              {
                v213[0] = "system";
                v213[1] = "boot";
                v214 = "vbmeta";
                v216[0] = "$(ANDROID_SYSTEM_PARTUUID)";
                v216[1] = "$(ANDROID_BOOT_PARTUUID)";
                v216[2] = "$(ANDROID_VBMETA_PARTUUID)";
                if ( v210 != 0 )
                  v214 = "boot";
                v211 = 0;
                v134 = 0;
                while ( 1 )
                {
                  v204 = v213[v211];
                  v207 = sub_94046414(v204);
                  v135 = sub_94046414(a3);
                  if ( (unsigned int)sub_94046608(v217, 32, v204, v207, a3, v135) == 0 )
                  {
                    sub_940407DC(
                      0,
                      "Partition name and suffix does not fit.\n",
                      v136,
                      v137,
                      v138,
                      v139,
                      v140,
                      v141,
                      v142,
                      v143);
                    goto LABEL_71;
                  }
                  v144 = (*(__int64 (__fastcall **)(__int64, _BYTE *, unsigned int *, __int64))(a1 + 72))(
                           a1,
                           v217,
                           v218,
                           37);
                  if ( v144 == 1 )
                    goto LABEL_73;
                  if ( v144 != 0 )
                    break;
                  v153 = v216[v211];
                  if ( v134 != 0 )
                  {
                    v154 = sub_940468C4(v134, v153, v218);
                    v155 = v134;
                    v134 = v154;
                    sub_94046430(v155);
                  }
                  else
                  {
                    v134 = sub_940468C4(v202, v153, v218);
                  }
                  if ( v134 == 0 )
                    goto LABEL_73;
                  if ( ++v211 == 3 )
                  {
                    sub_94046430(*(_QWORD *)(v18 + 40));
                    *(_QWORD *)(v18 + 40) = v134;
                    goto LABEL_40;
                  }
                }
                sub_940407DC(
                  0,
                  "Error getting unique GUID for partition.\n",
                  v145,
                  v146,
                  v147,
                  v148,
                  v149,
                  v150,
                  v151,
                  v152);
LABEL_71:
                if ( v134 != 0 )
                  sub_94046430(v134);
LABEL_73:
                v54 = 1;
                sub_940407DC(
                  7u,
                  "in %s, l:%d. \n",
                  v145,
                  v146,
                  v147,
                  v148,
                  v149,
                  v150,
                  v151,
                  v152,
                  "avb_slot_verify",
                  1136,
                  0);
                goto LABEL_9;
              }
LABEL_40:
              sub_940407DC(
                7u,
                "in %s, l:%d. \n",
                v124,
                v125,
                v126,
                v127,
                v128,
                v129,
                v130,
                v131,
                "avb_slot_verify",
                1142,
                0,
                v133,
                v132);
              v156 = (*(__int64 (__fastcall **)(__int64, _QWORD *))(a1 + 64))(a1, v216);
              if ( v156 != 1 )
              {
                if ( v156 != 0 )
                {
                  v54 = 2;
                  sub_940407DC(0, "Error getting device state.\n", v157, v158, v159, v160, v161, v162, v163, v164);
                  goto LABEL_9;
                }
                if ( LODWORD(v216[0]) != 0 )
                  v165 = "unlocked";
                else
                  v165 = "locked";
                if ( (unsigned int)sub_940444E8(v205, (__int64)"androidboot.vbmeta.device_state", (__int64)v165) != 0 )
                {
                  sub_940407DC(
                    7u,
                    "in %s, l:%d. \n",
                    v166,
                    v167,
                    v168,
                    v169,
                    v170,
                    v171,
                    v172,
                    v173,
                    "avb_slot_verify",
                    1160,
                    0);
                  switch ( v212 )
                  {
                    case 0u:
                    case 1u:
                    case 2u:
                    case 3u:
                      sub_94043BDC(v218);
                      if ( *(_QWORD *)(v18 + 16) != 0 )
                      {
                        v187 = *(_QWORD *)(v18 + 8);
                        v188 = 0;
                        v189 = 0;
                        do
                        {
                          v190 = 32 * v189;
                          v191 = v187 + 32 * v189++;
                          sub_94043C48(v218, *(_QWORD *)(v191 + 8), *(_DWORD *)(v191 + 16));
                          v187 = *(_QWORD *)(v18 + 8);
                          v188 += *(_QWORD *)(v187 + v190 + 16);
                        }
                        while ( *(_QWORD *)(v18 + 16) > v189 );
                      }
                      else
                      {
                        v188 = 0;
                      }
                      if ( (unsigned int)sub_940444E8(v205, (__int64)"androidboot.vbmeta.hash_alg", (__int64)"sha256") != 0 )
                      {
                        sub_94044464(v188, (__int64)v217);
                        if ( (unsigned int)sub_940444E8(v205, (__int64)"androidboot.vbmeta.size", (__int64)v217) != 0 )
                        {
                          v200 = sub_94043D28((__int64)v218);
                          if ( (unsigned int)sub_94044610(v18, v200, 32) != 0 )
                            goto LABEL_61;
                        }
                      }
                      v54 = 1;
                      sub_940407DC(
                        7u,
                        "in %s, l:%d. \n",
                        v174,
                        v175,
                        v176,
                        v177,
                        v178,
                        v179,
                        v180,
                        v181,
                        "avb_slot_verify",
                        1188,
                        0);
                      goto LABEL_9;
                    case 4u:
                    case 5u:
                    case 6u:
                      sub_94044178((__int64)v218);
                      if ( *(_QWORD *)(v18 + 16) != 0 )
                      {
                        v182 = *(_QWORD *)(v18 + 8);
                        v183 = 0;
                        v184 = 0;
                        do
                        {
                          v185 = 32 * v184;
                          v186 = v182 + 32 * v184++;
                          sub_94044224((__int64)v218, *(_QWORD *)(v186 + 8), *(_DWORD *)(v186 + 16));
                          v182 = *(_QWORD *)(v18 + 8);
                          v183 += *(_QWORD *)(v182 + v185 + 16);
                        }
                        while ( *(_QWORD *)(v18 + 16) > v184 );
                      }
                      else
                      {
                        v183 = 0;
                      }
                      if ( (unsigned int)sub_940444E8(v205, (__int64)"androidboot.vbmeta.hash_alg", (__int64)"sha512") != 0 )
                      {
                        sub_94044464(v183, (__int64)v217);
                        if ( (unsigned int)sub_940444E8(v205, (__int64)"androidboot.vbmeta.size", (__int64)v217) != 0 )
                        {
                          v201 = sub_94044304((__int64)v218);
                          if ( (unsigned int)sub_94044610(v18, v201, 64) != 0 )
                            goto LABEL_61;
                        }
                      }
                      v54 = 1;
                      sub_940407DC(
                        7u,
                        "in %s, l:%d. \n",
                        v174,
                        v175,
                        v176,
                        v177,
                        v178,
                        v179,
                        v180,
                        v181,
                        "avb_slot_verify",
                        1214,
                        0);
                      goto LABEL_9;
                    case 7u:
                      sub_940407DC(0, (const char *)&loc_940568B0, v174, v175, v176, v177, v178, v179, v180, v181);
                      goto LABEL_61;
                    default:
LABEL_61:
                      sub_940407DC(
                        7u,
                        "in %s, l:%d. \n",
                        v174,
                        v175,
                        v176,
                        v177,
                        v178,
                        v179,
                        v180,
                        v181,
                        "avb_slot_verify",
                        1222,
                        0);
                      if ( a5 != nullptr )
                      {
                        *a5 = v18;
                        sub_940407DC(
                          7u,
                          "in %s, l:%d. \n",
                          v192,
                          v193,
                          v194,
                          v195,
                          v196,
                          v197,
                          v198,
                          v199,
                          "avb_slot_verify",
                          1225,
                          0);
                      }
                      else
                      {
                        sub_940458E8((__int64 *)v18);
                      }
                      goto LABEL_21;
                  }
                }
              }
              v54 = 1;
            }
            else
            {
              v54 = 1;
              sub_940407DC(
                7u,
                "in %s, l:%d. \n",
                v124,
                v125,
                v126,
                v127,
                v128,
                v129,
                v130,
                v131,
                "avb_slot_verify",
                1125,
                0);
            }
          }
          else
          {
            v54 = 1;
            sub_940407DC(
              7u,
              "in %s, l:%d. \n",
              v115,
              v116,
              v117,
              v118,
              v119,
              v120,
              v121,
              v122,
              "avb_slot_verify",
              1115,
              0);
          }
        }
        else
        {
          v54 = 1;
          sub_940407DC(
            7u,
            "in %s, l:%d. \n",
            v107,
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            v114,
            "avb_slot_verify",
            1106,
            0);
        }
      }
    }
    else
    {
      v54 = 1;
      sub_940407DC(7u, "in %s, l:%d. \n", v37, v38, v39, v40, v41, v42, v43, v44, "avb_slot_verify", 1038, 0);
    }
  }
  else
  {
    v54 = 1;
    sub_940407DC(7u, "in %s, l:%d. \n", v28, v29, v30, v31, v32, v33, v34, v35, "avb_slot_verify", 1031, 0);
  }
LABEL_9:
  sub_940458E8((__int64 *)v18);
LABEL_10:
  sub_940407DC(7u, "in %s, l:%d. \n", v63, v64, v65, v66, v67, v68, v69, v70, "avb_slot_verify", 1241, 0);
  return v54;
}

/* ===== sub_94046314 @ 0x94046314 size 200 ===== */
const char *__fastcall sub_94046314(
        int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *result; // x0

  switch ( a1 )
  {
    case 0:
      result = "OK";
      break;
    case 1:
      result = "ERROR_OOM";
      break;
    case 2:
      result = "ERROR_IO";
      break;
    case 3:
      result = "ERROR_VERIFICATION";
      break;
    case 4:
      result = "ERROR_ROLLBACK_INDEX";
      break;
    case 5:
      result = "ERROR_PUBLIC_KEY_REJECTED";
      break;
    case 6:
      result = "ERROR_INVALID_METADATA";
      break;
    case 7:
      result = "ERROR_UNSUPPORTED_VERSION";
      break;
    default:
      sub_940407DC(0, "Unknown AvbSlotVerifyResult value.\n", a2, a3, a4, a5, a6, a7, a8, a9);
      result = "(unknown)";
      break;
  }
  return result;
}

/* ===== sub_940463DC @ 0x940463DC size 4 ===== */
// attributes: thunk
__int64 __fastcall sub_940463DC(__int64 a1, __int64 a2, unsigned int a3)
{
  return sub_94040870(a1, a2, a3);
}

/* ===== sub_940463E0 @ 0x940463E0 size 24 ===== */
__int64 __fastcall sub_940463E0(__int64 a1, __int64 a2, unsigned int a3)
{
  sub_94040880(a1, a2, a3);
  return 0;
}

/* ===== sub_940463F8 @ 0x940463F8 size 24 ===== */
__int64 __fastcall sub_940463F8(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  sub_94040888(a1, a2, a3);
  return 0;
}

/* ===== sub_94046410 @ 0x94046410 size 4 ===== */
// attributes: thunk
__int64 __fastcall sub_94046410(__int64 a1, __int64 a2)
{
  return sub_94040878(a1, a2);
}

/* ===== sub_94046414 @ 0x94046414 size 24 ===== */
__int64 __fastcall sub_94046414(__int64 a1)
{
  return (unsigned int)sub_94040AC4(a1);
}

/* ===== sub_9404642C @ 0x9404642C size 4 ===== */
// attributes: thunk
__int64 __fastcall sub_9404642C(unsigned int a1)
{
  return sub_94040894(a1);
}

/* ===== sub_94046430 @ 0x94046430 size 4 ===== */
// attributes: thunk
__int64 __fastcall sub_94046430(__int64 a1)
{
  return sub_940408AC(a1);
}

/* ===== sub_94046434 @ 0x94046434 size 36 ===== */
__int64 __fastcall sub_94046434(unsigned int a1)
{
  return (BYTE1(a1) << 16) | (a1 << 24) | HIBYTE(a1) | (BYTE2(a1) << 8);
}

/* ===== sub_94046458 @ 0x94046458 size 68 ===== */
unsigned __int64 __fastcall sub_94046458(unsigned __int64 a1)
{
  return ((unsigned __int64)BYTE1(a1) << 48)
       | (a1 << 56)
       | HIBYTE(a1)
       | ((unsigned __int64)BYTE2(a1) << 40)
       | ((unsigned __int64)BYTE3(a1) << 32)
       | ((unsigned __int64)BYTE4(a1) << 24)
       | ((unsigned __int64)BYTE5(a1) << 16)
       | ((unsigned __int64)BYTE6(a1) << 8);
}

/* ===== sub_9404649C @ 0x9404649C size 64 ===== */
__int64 __fastcall sub_9404649C(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w3
  __int64 v4; // x4
  int v5; // w5
  char v6; // w6
  char v7; // w3

  v3 = 0;
  if ( a3 != 0 )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      v6 = *(_BYTE *)(a2 + v4);
      v7 = *(_BYTE *)(a1 + v4++);
      v5 |= (unsigned __int8)(v6 ^ v7);
    }
    while ( v4 != a3 );
    return v5 != 0;
  }
  return v3;
}

/* ===== sub_940464DC @ 0x940464DC size 100 ===== */
__int64 __fastcall sub_940464DC(
        unsigned __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 v12; // x2
  __int64 result; // x0
  unsigned __int64 v14; // x1

  if ( a1 == nullptr )
    sub_940407DC(0, "assert fail: value != NULL\n", a3, a4, a5, a6, a7, a8, a9, a10);
  v12 = *a1;
  result = 1;
  v14 = *a1 + a2;
  *a1 = v14;
  if ( v12 > v14 )
  {
    sub_940407DC(0, "Overflow when adding values.\n", a3, a4, a5, a6, a7, a8, a9, a10);
    return 0;
  }
  return result;
}

/* ===== sub_94046540 @ 0x94046540 size 48 ===== */
__int64 __fastcall sub_94046540(
        unsigned __int64 *a1,
        unsigned __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 *v11; // x3
  char v13; // [xsp+18h] [xbp+18h] BYREF

  v11 = a1;
  if ( a1 == nullptr )
    v11 = (unsigned __int64 *)&v13;
  *v11 = a2;
  return sub_940464DC(v11, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

/* ===== sub_94046570 @ 0x94046570 size 152 ===== */
__int64 __fastcall sub_94046570(char *a1, __int64 a2)
{
  int v2; // w3
  char *v3; // x1
  char v4; // w2

  if ( a2 != 0 )
  {
    v2 = 0;
    v3 = &a1[a2];
    while ( 1 )
    {
      while ( 1 )
      {
        v4 = *a1;
        if ( v2 != 0 )
        {
          if ( (v4 & 0xC0) != 0x80 )
            return 0;
          --v2;
          goto LABEL_5;
        }
        if ( *a1 < 0 )
          break;
LABEL_5:
        if ( ++a1 == v3 )
          return v2 == 0;
      }
      if ( (v4 & 0xE0) == 0xC0 )
      {
        v2 = 1;
        goto LABEL_5;
      }
      if ( (v4 & 0xF0) == 0xE0 )
      {
        v2 = 2;
        goto LABEL_5;
      }
      if ( (v4 & 0xF8) != 0xF0 )
        return 0;
      ++a1;
      v2 = 3;
      if ( a1 == v3 )
        return v2 == 0;
    }
  }
  return 1;
}

/* ===== sub_94046608 @ 0x94046608 size 248 ===== */
__int64 __fastcall sub_94046608(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int64 a4,
        __int64 a5,
        __int64 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned int v19; // w22
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned __int64 v29; // [xsp+58h] [xbp+58h] BYREF

  v19 = a6;
  if ( (unsigned int)sub_94046540(&v29, a4, a6, a7, a8, a9, a10, a11, a12, a13, a14) != 0 )
  {
    if ( a2 - 1 < v29 )
    {
      sub_940407DC(0, "Insufficient buffer space.\n", v20, v21, v22, v23, v24, v25, v26, v27);
      return 0;
    }
    else
    {
      sub_940463E0(a1, a3, a4);
      sub_940463E0(a1 + a4, a5, v19);
      *(_BYTE *)(a1 + v29) = 0;
      return 1;
    }
  }
  else
  {
    sub_940407DC(0, "Overflow when adding string sizes.\n", v20, v21, v22, v23, v24, v25, v26, v27);
    return 0;
  }
}

/* ===== sub_94046700 @ 0x94046700 size 72 ===== */
__int64 __fastcall sub_94046700(__int64 a1)
{
  __int64 v2; // x19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  v2 = sub_9404642C(a1);
  if ( v2 == 0 )
    sub_940407DC(7u, "Failed to allocate memory. size:%d\n", v3, v4, v5, v6, v7, v8, v9, v10, a1, 0);
  return v2;
}

/* ===== sub_94046748 @ 0x94046748 size 56 ===== */
__int64 __fastcall sub_94046748(__int64 a1)
{
  __int64 v1; // x0
  __int64 v2; // x19
  unsigned int v4; // [xsp+28h] [xbp+28h]

  v4 = a1;
  v1 = sub_94046700(a1);
  v2 = v1;
  if ( v1 != 0 )
    sub_940463F8(v1, 0, v4);
  return v2;
}

/* ===== sub_94046780 @ 0x94046780 size 72 ===== */
__int64 __fastcall sub_94046780(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x0
  __int64 v3; // x19

  v1 = sub_94046414(a1);
  v2 = sub_94046700(v1 + 1);
  v3 = v2;
  if ( v2 != 0 )
  {
    sub_940463E0(v2, a1, v1);
    *(_BYTE *)(v3 + v1) = 0;
  }
  return v3;
}

/* ===== sub_940467C8 @ 0x940467C8 size 132 ===== */
_BYTE *__fastcall sub_940467C8(_BYTE *result, unsigned __int8 *a2)
{
  int v2; // w8
  _BYTE *v3; // x4
  unsigned __int8 *v4; // x7
  int i; // w6
  __int64 v6; // x2

  if ( *result != 0 )
  {
    v2 = *a2;
    v3 = result;
    v4 = result + 1;
    if ( v2 == (unsigned __int8)*result )
      goto LABEL_6;
LABEL_3:
    for ( i = *v4; i != 0; i = *v4 )
    {
LABEL_5:
      ++v3;
      ++v4;
      result = v3;
      if ( v2 != i )
        goto LABEL_3;
LABEL_6:
      i = a2[1];
      if ( a2[1] == 0 )
        return result;
      if ( i == *v4 )
      {
        v6 = 1;
        while ( 1 )
        {
          if ( a2[++v6] == 0 )
            return result;
          if ( (unsigned __int8)v3[v6] != a2[v6] )
            goto LABEL_5;
        }
      }
    }
  }
  return nullptr;
}

/* ===== sub_9404684C @ 0x9404684C size 120 ===== */
__int64 __fastcall sub_9404684C(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 *v3; // x19
  __int64 v4; // x0
  __int64 v7; // t1

  v3 = a1;
  v4 = *a1;
  if ( v4 == 0 )
    return 0;
  while ( sub_94046414(v4) != a3 || (unsigned int)sub_940463DC(*v3, a2, a3) != 0 )
  {
    v7 = v3[1];
    ++v3;
    v4 = v7;
    if ( v7 == 0 )
      return 0;
  }
  return *v3;
}

/* ===== sub_940468C4 @ 0x940468C4 size 416 ===== */
__int64 __fastcall sub_940468C4(_BYTE *a1, unsigned __int8 *a2, __int64 a3)
{
  __int64 v4; // x26
  __int64 v5; // x25
  __int64 v6; // x23
  __int64 v7; // x20
  __int64 v8; // x21
  __int64 v9; // x1
  __int64 v10; // x0
  __int64 v11; // x0
  _BYTE *v12; // x0
  __int64 v13; // x27
  _BYTE *v14; // x19
  __int64 v15; // x28
  __int64 v16; // x24
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x21
  unsigned int v20; // w24
  __int64 v21; // x19

  v4 = sub_94046414((__int64)a2);
  v5 = sub_94046414(a3);
  if ( *a1 == 0 )
    return sub_94046780((__int64)a1);
  v6 = 0;
  v7 = 0;
  while ( 1 )
  {
    v12 = sub_940467C8(a1, a2);
    v13 = v12 - a1;
    v14 = v12;
    v15 = v12 - a1 + v6;
    if ( v12 == nullptr )
      break;
    v16 = v15 + v5;
    if ( v7 != 0 )
    {
      v8 = sub_94046700(v16 + 1);
      sub_940463E0(v8, v7, v6);
      v9 = (__int64)a1;
      v10 = v8 + v6;
      v6 = v15 + v5;
      a1 = &v14[v4];
      sub_940463E0(v10, v9, v13);
      sub_940463E0(v8 + v15, a3, v5);
      *(_BYTE *)(v8 + v16) = 0;
      v11 = v7;
      v7 = v8;
      sub_94046430(v11);
      if ( v14[v4] == 0 )
        break;
    }
    else
    {
      v6 = v13 + v5;
      v17 = sub_94046700(v13 + v5 + 1);
      v7 = v17;
      if ( v17 == 0 )
        return 0;
      sub_940463E0(v17, (__int64)a1, v13);
      a1 = &v14[v4];
      sub_940463E0(v7 + v13, a3, v5);
      *(_BYTE *)(v7 + v6) = 0;
      if ( v14[v4] == 0 )
        break;
    }
  }
  if ( v7 == 0 )
    return sub_94046780((__int64)a1);
  v18 = sub_94046414((__int64)a1);
  v19 = v18 + v6;
  v20 = v18;
  v21 = sub_94046700(v18 + v6 + 1);
  sub_940463E0(v21, v7, v6);
  sub_940463E0(v21 + v6, (__int64)a1, v20);
  *(_BYTE *)(v21 + v19) = 0;
  sub_94046430(v7);
  return v21;
}

/* ===== sub_94046A64 @ 0x94046A64 size 248 ===== */
__int64 __fastcall sub_94046A64(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  sub_940463E0(a2, a1, 0x100u);
  *(_DWORD *)(a2 + 4) = sub_94046434(*(_DWORD *)(a2 + 4));
  *(_DWORD *)(a2 + 8) = sub_94046434(*(_DWORD *)(a2 + 8));
  *(_QWORD *)(a2 + 12) = sub_94046458(*(_QWORD *)(a2 + 12));
  *(_QWORD *)(a2 + 20) = sub_94046458(*(_QWORD *)(a2 + 20));
  *(_DWORD *)(a2 + 28) = sub_94046434(*(_DWORD *)(a2 + 28));
  *(_QWORD *)(a2 + 32) = sub_94046458(*(_QWORD *)(a2 + 32));
  *(_QWORD *)(a2 + 40) = sub_94046458(*(_QWORD *)(a2 + 40));
  *(_QWORD *)(a2 + 48) = sub_94046458(*(_QWORD *)(a2 + 48));
  *(_QWORD *)(a2 + 56) = sub_94046458(*(_QWORD *)(a2 + 56));
  *(_QWORD *)(a2 + 64) = sub_94046458(*(_QWORD *)(a2 + 64));
  *(_QWORD *)(a2 + 72) = sub_94046458(*(_QWORD *)(a2 + 72));
  *(_QWORD *)(a2 + 80) = sub_94046458(*(_QWORD *)(a2 + 80));
  *(_QWORD *)(a2 + 88) = sub_94046458(*(_QWORD *)(a2 + 88));
  *(_QWORD *)(a2 + 96) = sub_94046458(*(_QWORD *)(a2 + 96));
  *(_QWORD *)(a2 + 104) = sub_94046458(*(_QWORD *)(a2 + 104));
  *(_QWORD *)(a2 + 112) = sub_94046458(*(_QWORD *)(a2 + 112));
  result = sub_94046434(*(_DWORD *)(a2 + 120));
  *(_DWORD *)(a2 + 120) = result;
  return result;
}

/* ===== sub_94046B5C @ 0x94046B5C size 1268 ===== */
__int64 __fastcall sub_94046B5C(unsigned __int64 a1, unsigned __int64 a2, _QWORD *a3, _QWORD *a4, _QWORD *a5)
{
  __int64 v10; // x21
  unsigned int *v11; // x19
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w24
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x1
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x2
  unsigned int v82; // w0
  __int64 *v83; // x0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 *v92; // x28
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  __int64 v101; // x27
  __int64 v102; // x0
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 v111; // x1
  unsigned __int64 v112; // [xsp+68h] [xbp+68h]
  unsigned __int64 v113; // [xsp+78h] [xbp+78h] BYREF
  unsigned __int64 v114; // [xsp+80h] [xbp+80h] BYREF
  unsigned __int64 v115; // [xsp+88h] [xbp+88h] BYREF
  unsigned __int64 v116; // [xsp+90h] [xbp+90h] BYREF
  unsigned __int64 v117; // [xsp+98h] [xbp+98h] BYREF

  if ( a3 != nullptr )
    *a3 = 0;
  if ( a4 != nullptr )
    *a4 = 0;
  v10 = sub_94046700(256);
  v11 = (unsigned int *)sub_94046700(200);
  v12 = sub_94046700(392);
  v21 = v12;
  if ( v11 != nullptr && v10 != 0 )
  {
    if ( v12 != 0 )
    {
      if ( (unsigned int)sub_9404649C(a1, (__int64)"AVB0", 4) != 0 )
      {
        v30 = 2;
        sub_940407DC(0, "Magic is incorrect.\n", v22, v23, v24, v25, v26, v27, v28, v29);
      }
      else
      {
        if ( a2 <= 0xFF )
        {
          v30 = 2;
          sub_940407DC(0, "Length is smaller than header.\n", v22, v23, v24, v25, v26, v27, v28, v29);
          sub_94046430(v10);
          goto LABEL_11;
        }
        sub_94046A64(a1, v10);
        if ( *(_DWORD *)(v10 + 4) != 1 || *(_DWORD *)(v10 + 8) != 0 )
        {
          v30 = 3;
          sub_940407DC(
            0,
            "Mismatch between image version and libavb version.\n",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39);
        }
        else if ( *(_BYTE *)(v10 + 175) != 0 )
        {
          v30 = 2;
          sub_940407DC(0, "Release string does not end with a NUL byte.\n", v32, v33, v34, v35, v36, v37, v38, v39);
        }
        else
        {
          v40 = *(_QWORD *)(v10 + 12);
          if ( (v40 & 0x3F) != 0 || (*(_QWORD *)(v10 + 20) & 0x3FLL) != 0 )
          {
            v30 = 2;
            sub_940407DC(0, "Block size is not a multiple of 64.\n", v32, v33, v34, v35, v36, v37, v38, v39);
          }
          else
          {
            v113 = 256;
            if ( (unsigned int)sub_940464DC(&v113, v40, v32, v33, v34, v35, v36, v37, v38, v39) != 0
              && (unsigned int)sub_940464DC(&v113, *(_QWORD *)(v10 + 20), v41, v42, v43, v44, v45, v46, v47, v48) != 0 )
            {
              if ( a2 >= v113 )
              {
                if ( (unsigned int)sub_94046540(nullptr, a1, a2, v41, v42, v43, v44, v45, v46, v47, v48) != 0 )
                {
                  if ( (unsigned int)sub_94046540(
                                       &v114,
                                       *(_QWORD *)(v10 + 32),
                                       *(_QWORD *)(v10 + 40),
                                       v49,
                                       v50,
                                       v51,
                                       v52,
                                       v53,
                                       v54,
                                       v55,
                                       v56) != 0
                    && *(_QWORD *)(v10 + 12) >= v114 )
                  {
                    if ( (unsigned int)sub_94046540(
                                         &v115,
                                         *(_QWORD *)(v10 + 48),
                                         *(_QWORD *)(v10 + 56),
                                         v57,
                                         v58,
                                         v59,
                                         v60,
                                         v61,
                                         v62,
                                         v63,
                                         v64) != 0
                      && *(_QWORD *)(v10 + 12) >= v115 )
                    {
                      if ( (unsigned int)sub_94046540(
                                           &v116,
                                           *(_QWORD *)(v10 + 64),
                                           *(_QWORD *)(v10 + 72),
                                           v65,
                                           v66,
                                           v67,
                                           v68,
                                           v69,
                                           v70,
                                           v71,
                                           v72) != 0
                        && *(_QWORD *)(v10 + 20) >= v116 )
                      {
                        v81 = *(_QWORD *)(v10 + 88);
                        if ( v81 == 0
                          || (unsigned int)sub_94046540(
                                             &v117,
                                             *(_QWORD *)(v10 + 80),
                                             v81,
                                             v73,
                                             v74,
                                             v75,
                                             v76,
                                             v77,
                                             v78,
                                             v79,
                                             v80) != 0
                          && *(_QWORD *)(v10 + 20) >= v117 )
                        {
                          v82 = *(_DWORD *)(v10 + 28);
                          v30 = 1;
                          if ( v82 != 0 )
                          {
                            v83 = sub_94042C24(v82);
                            v92 = v83;
                            if ( v83 != nullptr )
                            {
                              if ( *(_QWORD *)(v10 + 40) == v83[2] )
                              {
                                v112 = a1 + 256;
                                v101 = a1 + 256 + *(_QWORD *)(v10 + 12);
                                switch ( *(_DWORD *)(v10 + 28) )
                                {
                                  case 1:
                                  case 2:
                                  case 3:
                                    sub_94043BDC(v11);
                                    sub_94043C48(v11, a1, 0x100u);
                                    sub_94043C48(v11, v101, *(_DWORD *)(v10 + 20));
                                    v102 = sub_94043D28((__int64)v11);
                                    goto LABEL_56;
                                  case 4:
                                  case 5:
                                  case 6:
                                    sub_94044178(v21);
                                    sub_94044224(v21, a1, 0x100u);
                                    sub_94044224(v21, v101, *(_DWORD *)(v10 + 20));
                                    v102 = sub_94044304(v21);
LABEL_56:
                                    if ( (unsigned int)sub_9404649C(
                                                         v112 + *(_QWORD *)(v10 + 32),
                                                         v102,
                                                         *(_QWORD *)(v10 + 40)) != 0 )
                                    {
                                      v30 = 4;
                                      sub_940407DC(
                                        0,
                                        "Hash does not match!\n",
                                        v103,
                                        v104,
                                        v105,
                                        v106,
                                        v107,
                                        v108,
                                        v109,
                                        v110);
                                    }
                                    else
                                    {
                                      v30 = 5;
                                      if ( (unsigned int)sub_94043558(
                                                           v101 + *(_QWORD *)(v10 + 64),
                                                           *(_QWORD *)(v10 + 72),
                                                           v112 + *(_QWORD *)(v10 + 48),
                                                           *(_QWORD *)(v10 + 56),
                                                           v112 + *(_QWORD *)(v10 + 32),
                                                           *(_QWORD *)(v10 + 40),
                                                           *v92,
                                                           v92[1],
                                                           v103,
                                                           v104,
                                                           v105,
                                                           v106,
                                                           v107,
                                                           v108,
                                                           v109,
                                                           v110) != 0 )
                                      {
                                        v111 = *(_QWORD *)(v10 + 72);
                                        if ( v111 != 0 )
                                        {
                                          if ( a3 != nullptr )
                                            *a3 = v101 + *(_QWORD *)(v10 + 64);
                                          if ( a4 != nullptr )
                                            *a4 = v111;
                                        }
                                        v30 = 0;
                                        if ( a5 != nullptr )
                                          *a5 = *(_QWORD *)(v10 + 112);
                                      }
                                    }
                                    break;
                                  default:
                                    v30 = 2;
                                    sub_940407DC(0, "Unknown algorithm.\n", v84, v85, v86, v87, v88, v89, v90, v91);
                                    break;
                                }
                              }
                              else
                              {
                                v30 = 2;
                                sub_940407DC(
                                  0,
                                  "Embedded hash has wrong size.\n",
                                  v84,
                                  v85,
                                  v86,
                                  v87,
                                  v88,
                                  v89,
                                  v90,
                                  v91);
                              }
                            }
                            else
                            {
                              v30 = 2;
                              sub_940407DC(0, "Invalid or unknown algorithm.\n", v84, v85, v86, v87, v88, v89, v90, v91);
                            }
                          }
                        }
                        else
                        {
                          v30 = 2;
                          sub_940407DC(0, (const char *)&loc_94056CC8, v93, v94, v95, v96, v97, v98, v99, v100);
                        }
                      }
                      else
                      {
                        v30 = 2;
                        sub_940407DC(0, (const char *)&loc_94056C98, v73, v74, v75, v76, v77, v78, v79, v80);
                      }
                    }
                    else
                    {
                      v30 = 2;
                      sub_940407DC(
                        0,
                        "Signature is not entirely in its block.\n",
                        v65,
                        v66,
                        v67,
                        v68,
                        v69,
                        v70,
                        v71,
                        v72);
                    }
                  }
                  else
                  {
                    v30 = 2;
                    sub_940407DC(0, "Hash is not entirely in its block.\n", v57, v58, v59, v60, v61, v62, v63, v64);
                  }
                }
                else
                {
                  v30 = 2;
                  sub_940407DC(0, "Boot image location and length mismatch.\n", v49, v50, v51, v52, v53, v54, v55, v56);
                }
              }
              else
              {
                v30 = 2;
                sub_940407DC(
                  0,
                  "Block sizes add up to more than given length.\n",
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  v48);
              }
            }
            else
            {
              v30 = 2;
              sub_940407DC(0, "Overflow while computing size of boot image.\n", v41, v42, v43, v44, v45, v46, v47, v48);
            }
          }
        }
      }
    }
    else
    {
      v30 = 2;
      sub_940407DC(0, "malloc failed.\n", v13, v14, v15, v16, v17, v18, v19, v20);
    }
    goto LABEL_17;
  }
  v30 = 2;
  sub_940407DC(0, "malloc failed.\n", v13, v14, v15, v16, v17, v18, v19, v20);
  if ( v10 != 0 )
LABEL_17:
    sub_94046430(v10);
LABEL_11:
  if ( v11 != nullptr )
    sub_94046430((__int64)v11);
  if ( v21 != 0 )
    sub_94046430(v21);
  return v30;
}

/* ===== sub_94047050 @ 0x94047050 size 168 ===== */
const char *__fastcall sub_94047050(
        int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *result; // x0

  switch ( a1 )
  {
    case 0:
      result = "OK";
      break;
    case 1:
      result = "OK_NOT_SIGNED";
      break;
    case 2:
      result = "INVALID_VBMETA_HEADER";
      break;
    case 3:
      result = "UNSUPPORTED_VERSION";
      break;
    case 4:
      result = "HASH_MISMATCH";
      break;
    case 5:
      result = "SIGNATURE_MISMATCH";
      break;
    default:
      sub_940407DC(0, "Unknown AvbVBMetaVerifyResult value.\n", a2, a3, a4, a5, a6, a7, a8, a9);
      result = "(unknown)";
      break;
  }
  return result;
}

/* ===== sub_940470F8 @ 0x940470F8 size 8 ===== */
__int64 sub_940470F8()
{
  return 0;
}

/* ===== sub_94047100 @ 0x94047100 size 36 ===== */
__int64 __fastcall sub_94047100(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  sub_940407DC(7u, "TODO: implement write_rollback_index().\n", a1, a2, a3, a4, a5, a6, a7, a8);
  return 0;
}

/* ===== sub_94047124 @ 0x94047124 size 68 ===== */
__int64 __fastcall sub_94047124(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _DWORD *a10)
{
  *a10 = MEMORY[0xFFFFFFFFE0064418] == 1;
  sub_940407DC(
    7u,
    "read_is_device_unlocked() get vb_unlock_status 0x%x, *out_is_unlocked is %d.\n",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    MEMORY[0xFFFFFFFFE0064418]);
  return 0;
}

/* ===== sub_94047168 @ 0x94047168 size 76 ===== */
__int64 __fastcall sub_94047168(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _QWORD *a11)
{
  sub_940407DC(7u, (const char *)&loc_94056E88, a1, a2, a3, a4, a5, a6, a7, a8);
  if ( a11 != nullptr )
    *a11 = *(unsigned int *)(4 * a10 - 536460624);
  return 0;
}

/* ===== sub_940471B4 @ 0x940471B4 size 408 ===== */
__int64 __fastcall sub_940471B4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 *a6)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned __int64 v29; // x1
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  if ( (unsigned int)sub_94040878(a2, (__int64)"vbmeta") != 0 )
  {
    v19 = MEMORY[0xFFFFFFFFE0064404];
    if ( (a3 & 0x8000000000000000LL) == 0 )
      goto LABEL_3;
  }
  else
  {
    v19 = MEMORY[0xFFFFFFFFE0064408];
    if ( (a3 & 0x8000000000000000LL) == 0 )
      goto LABEL_3;
  }
  v29 = -a3;
  a3 += v19;
  if ( v19 < v29 )
  {
    sub_940407DC(7u, "Offset outside range.\n", v11, v12, v13, v14, v15, v16, v17, v18);
    return 4;
  }
LABEL_3:
  sub_940407DC(
    7u,
    "read partition %s, offset: 0x%llx, bytes: 0x%x.\n",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    a2,
    a3,
    a4);
  if ( (unsigned int)sub_94040878(a2, (__int64)"vbmeta") != 0 )
  {
    sub_940407DC(
      7u,
      "buf:0x%x, g_avbUserData.img_addr:0x%x, offset_from_partition:0x%llx num_bytes:0x%llx\n",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      a5,
      MEMORY[0xFFFFFFFFE00643D8],
      a3,
      a4);
    sub_94040880(a5, MEMORY[0xFFFFFFFFE00643D8] + a3, a4);
    *a6 = a4;
  }
  else
  {
    sub_940407DC(
      7u,
      "buf:0x%x, g_avbUserData.vbmeta_img_addr:0x%x, offset_from_partition:0x%llx num_bytes:0x%llx\n",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      a5,
      MEMORY[0xFFFFFFFFE00643E0],
      a3,
      a4);
    sub_94040880(a5, MEMORY[0xFFFFFFFFE00643E0] + a3, a4);
    *a6 = a4;
    sub_940407DC(7u, "[kbc] save vbmeta image for cp verify.\n", v30, v31, v32, v33, v34, v35, v36, v37);
    sub_94040880(-536576240, MEMORY[0xFFFFFFFFE00643E0] + a3, a4);
  }
  return 0;
}

/* ===== sub_9404734C @ 0x9404734C size 204 ===== */
__int64 __fastcall sub_9404734C(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  __int64 v22; // x19
  __int64 v23; // x2
  __int64 v24; // x2
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  sub_940407DC(7u, "%s", a4, a5, a6, a7, a8, a9, a10, a11, a1);
  if ( a3 > 0 )
  {
    v21 = (unsigned int)(a3 - 1) + 1LL;
    v22 = 0;
    do
    {
      while ( (v22 & 0xF) != 0 )
      {
        v23 = *(unsigned __int8 *)(a2 + v22++);
        sub_940407DC(7u, " %02x", v13, v14, v15, v16, v17, v18, v19, v20, v23);
        if ( v22 == v21 )
          return sub_940407DC(7u, "\n", v13, v14, v15, v16, v17, v18, v19, v20);
      }
      sub_940407DC(7u, "\n%04x", v13, v14, v15, v16, v17, v18, v19, v20, (unsigned int)v22);
      v24 = *(unsigned __int8 *)(a2 + v22++);
      sub_940407DC(7u, " %02x", v25, v26, v27, v28, v29, v30, v31, v32, v24);
    }
    while ( v22 != v21 );
  }
  return sub_940407DC(7u, "\n", v13, v14, v15, v16, v17, v18, v19, v20);
}

/* ===== sub_94047418 @ 0x94047418 size 364 ===== */
__int64 __fastcall sub_94047418(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 *a14)
{
  unsigned int v14; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7

  v14 = a11;
  sub_940407DC(
    7u,
    "[kbc]read partition name: %s, offset = 0x%llx, num_bytes = 0x%x\n",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a10,
    a11,
    a12);
  if ( (unsigned int)sub_94040878(a10, (__int64)"vbmeta") != 0 )
  {
    if ( a12 == 64 )
    {
      sub_940407DC(7u, "[kbc]read footer\n", v19, v20, v21, v22, v23, v24, v25, v26);
      sub_94040880(a13, MEMORY[0xFFFFFFFFE00643F8], 0x40u);
      sub_9404734C((__int64)"dump footer", a13, 64, v52, v53, v54, v55, v56, v57, v58, v59);
    }
    else
    {
      sub_940407DC(
        7u,
        "[kbc]read certificate: img_addr = 0x%x\n",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        MEMORY[0xFFFFFFFFE00643D8]);
      if ( sub_9404087C() != 0 )
        v14 -= MEMORY[0xFFFFFFFFE0064414];
      sub_940407DC(7u, "[kbc]read certificate: offset = 0x%x\n", v27, v28, v29, v30, v31, v32, v33, v34, v14);
      sub_94040880(a13, MEMORY[0xFFFFFFFFE00643D8] + v14, a12);
      sub_9404734C((__int64)sub_940570A8, a13, 16, v35, v36, v37, v38, v39, v40, v41, v42);
    }
    *a14 = a12;
  }
  else
  {
    sub_94040880(a13, -536576240, a12);
    *a14 = a12;
  }
  sub_940407DC(7u, "[kbc]read_from_partition_kbc leave buf = 0x%x\n", v43, v44, v45, v46, v47, v48, v49, v50, a13);
  return 0;
}

/* ===== sub_94047584 @ 0x94047584 size 100 ===== */
__int64 sub_94047584()
{
  MEMORY[0xFFFFFFFFE00643A8] = -536709184;
  MEMORY[0xFFFFFFFFE0064388] = 0;
  MEMORY[0xFFFFFFFFE0064398] = -536710732;
  MEMORY[0xFFFFFFFFE00643A0] = 0;
  MEMORY[0xFFFFFFFFE00643B0] = sub_94047168;
  MEMORY[0xFFFFFFFFE00643B8] = -536710912;
  MEMORY[0xFFFFFFFFE00643C0] = -536710876;
  MEMORY[0xFFFFFFFFE00643C8] = -536710920;
  MEMORY[0xFFFFFFFFE0064380] = 0;
  return 0;
}

/* ===== sub_940475E8 @ 0x940475E8 size 448 ===== */
__int64 __fastcall sub_940475E8(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  __int64 v8; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int16 v33; // w0
  char *v34; // x1
  __int64 v35; // x3
  __int64 v36; // x2
  __int64 v38; // [xsp+30h] [xbp+30h] BYREF
  _QWORD v39[2]; // [xsp+38h] [xbp+38h] BYREF
  __int64 v40; // [xsp+48h] [xbp+48h] BYREF
  _QWORD v41[2]; // [xsp+50h] [xbp+50h] BYREF
  __int64 v42; // [xsp+60h] [xbp+60h] BYREF
  _QWORD v43[2]; // [xsp+68h] [xbp+68h] BYREF
  __int64 v44; // [xsp+78h] [xbp+78h] BYREF
  _QWORD v45[2]; // [xsp+80h] [xbp+80h] BYREF

  v8 = 0;
  sub_940407DC(
    7u,
    "avb_ops_get_image_buffer: img_addr = 0x%x\n",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    MEMORY[0xFFFFFFFFE00643D8]);
  sub_940407DC(7u, "check dat cp\n", v9, v10, v11, v12, v13, v14, v15, v16);
  if ( (unsigned int)sub_9404649C(MEMORY[0xFFFFFFFFE00643D8], (__int64)"SCI1", 5) == 0 )
  {
    sub_940407DC(7u, "the image is new packed modem image\n", v17, v18, v19, v20, v21, v22, v23, v24);
    v38 = 0;
    v39[0] = 0;
    v39[1] = 0;
    v40 = 0;
    v41[0] = 0;
    v41[1] = 0;
    v42 = 0;
    v43[0] = 0;
    v43[1] = 0;
    v44 = 0;
    v45[0] = 0;
    v45[1] = 0;
    sub_94040880((__int64)&v38, MEMORY[0xFFFFFFFFE00643D8], 0x60u);
    if ( (unsigned int)sub_9404649C((__int64)&v38, (__int64)"SCI1", 5) == 0 )
    {
      v33 = WORD2(v39[0]);
      if ( BYTE4(v39[0]) == 1 )
      {
        v34 = (char *)v39 + 4;
      }
      else
      {
        v33 = v40;
        v34 = (char *)&v40;
        if ( (unsigned __int8)v40 != 1 )
        {
          v33 = WORD2(v41[0]);
          v34 = (char *)v41 + 4;
          if ( BYTE4(v41[0]) != 1 )
          {
            v33 = v42;
            v34 = (char *)&v42;
            if ( (unsigned __int8)v42 != 1 )
            {
              v33 = WORD2(v43[0]);
              v34 = (char *)v43 + 4;
              if ( BYTE4(v43[0]) != 1 )
              {
                v33 = v44;
                v34 = (char *)&v44;
                if ( (unsigned __int8)v44 != 1 )
                {
                  v33 = WORD2(v45[0]);
                  v34 = (char *)v45 + 4;
                  if ( BYTE4(v45[0]) != 1 )
                  {
                    v8 = 0;
                    sub_940407DC(7u, "no MODEM exe found in SCI header!", v25, v26, v27, v28, v29, v30, v31, v32);
                    v35 = 0;
                    v36 = 0;
LABEL_11:
                    sub_940407DC(
                      7u,
                      "modem offset: 0x%x, length: 0x%x\n",
                      v25,
                      v26,
                      v27,
                      v28,
                      v29,
                      v30,
                      v31,
                      v32,
                      v36,
                      v35);
                    return MEMORY[0xFFFFFFFFE00643D8] + v8;
                  }
                }
              }
            }
          }
        }
      }
      LODWORD(v36) = *((_DWORD *)v34 + 1);
      v35 = *((unsigned int *)v34 + 2);
      if ( (v33 & 0x400) != 0 )
        v36 = (unsigned int)(v36 + 20);
      else
        v36 = (unsigned int)v36;
      v8 = (unsigned int)v36;
      goto LABEL_11;
    }
    v8 = 0;
    sub_940407DC(7u, "old image format!\n", v25, v26, v27, v28, v29, v30, v31, v32);
    v35 = 0;
    v36 = 0;
    goto LABEL_11;
  }
  return MEMORY[0xFFFFFFFFE00643D8] + v8;
}

/* ===== sub_940477A8 @ 0x940477A8 size 24 ===== */
__int64 __fastcall sub_940477A8(_QWORD *a1)
{
  *a1 = MEMORY[0xFFFFFFFFE006440C];
  return MEMORY[0xFFFFFFFFE00643E8];
}

/* ===== sub_940477C0 @ 0x940477C0 size 436 ===== */
__int64 __fastcall sub_940477C0(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        _DWORD *a14)
{
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x23
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // [xsp+48h] [xbp+48h] BYREF
  _BYTE v84[32]; // [xsp+50h] [xbp+50h] BYREF

  sub_940407DC(7u, (const char *)&loc_94057158, a1, a2, a3, a4, a5, a6, a7, a8);
  if ( a10 == 0 || a11 == 0 || a14 == nullptr )
  {
    sub_940407DC(0, "invalid: para is null.\n", v17, v18, v19, v20, v21, v22, v23, v24, 0);
    sub_940407DC(0, "Info: out_key_is_trusted is 0x%llx.\n", v59, v60, v61, v62, v63, v64, v65, v66, a14, 0);
    sub_940407DC(0, "Info: public_key_data is 0x%llx.\n", v67, v68, v69, v70, v71, v72, v73, v74, a10, 0);
    sub_940407DC(0, "Info: public_key_length is 0x%llx.\n", v75, v76, v77, v78, v79, v80, v81, v82, a11, 0);
    return 1;
  }
  else
  {
    v25 = sub_940477A8(&v83);
    sub_940407DC(
      7u,
      "dump public_key_hash: public_key_hash_length:%d. \n",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v83,
      0);
    if ( v25 != 0 && v83 != 0 )
      nullsub_9("vboot key hash from uboot", v25, v83);
    sub_94041994(a10, a11, (__int64)v84, v34, v35, v36, v37, v38, v39, v40, v41);
    nullsub_9("pk_data sha256", v84, 32);
    if ( v83 != 32 || (unsigned int)sub_9404649C(v25, (__int64)v84, 32) != 0 )
    {
      sub_940407DC(7u, "expected_public_key is not matched.\n", v42, v43, v44, v45, v46, v47, v48, v49, 0);
      sub_940407DC(
        0,
        "vbmeta",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        ": Public key used to sign data does not match key in chain partition descriptor.\n",
        0);
      *a14 = 0;
      return 5;
    }
    else
    {
      sub_940407DC(7u, "expected_public_key is matched.\n", v42, v43, v44, v45, v46, v47, v48, v49, 0);
      *a14 = 1;
      return 0;
    }
  }
}

/* ===== sub_94047974 @ 0x94047974 size 96 ===== */
__int64 sub_94047974()
{
  MEMORY[0xFFFFFFFFE00643A8] = -536709184;
  MEMORY[0xFFFFFFFFE0064388] = 0;
  MEMORY[0xFFFFFFFFE0064398] = -536710120;
  MEMORY[0xFFFFFFFFE00643A0] = 0;
  MEMORY[0xFFFFFFFFE00643B0] = sub_94047168;
  MEMORY[0xFFFFFFFFE00643B8] = -536710912;
  MEMORY[0xFFFFFFFFE00643C0] = -536710876;
  MEMORY[0xFFFFFFFFE00643C8] = -536710920;
  MEMORY[0xFFFFFFFFE0064380] = 0;
  return -536460416;
}

/* ===== sub_940479D4 @ 0x940479D4 size 308 ===== */
__int64 __fastcall sub_940479D4(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w3
  unsigned int v19; // w20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  int v62; // w0
  __int64 v63[2]; // [xsp+30h] [xbp+30h] BYREF

  v63[0] = 0;
  v63[1] = 0;
  if ( a1 != 0 )
  {
    sub_940407DC(1u, "avb check image name:%s.\n", a2, a3, a4, a5, a6, a7, a8, a9, a1);
    v63[0] = a1;
  }
  else
  {
    sub_940407DC(1u, "avb check image name is null.\n", a2, a3, a4, a5, a6, a7, a8, a9);
    v63[0] = (__int64)"";
  }
  v18 = 0;
  if ( MEMORY[0xFFFFFFFFE0064418] == 1 )
  {
    v62 = sub_94040878(a1, (__int64)"boot");
    v18 = 1;
    if ( v62 != 0 )
      v18 = sub_94040878(a1, (__int64)"recovery") == 0;
  }
  v19 = sub_940459C4(
          -536460416,
          v63,
          (__int64)"",
          v18,
          (__int64 *)0xFFFFFFFFE0057F18LL,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17);
  sub_940407DC(1u, ">>>>>>>>>>>>>>>>  avb_slot_verify result is %d.\n", v20, v21, v22, v23, v24, v25, v26, v27, v19);
  v36 = sub_94046314(v19, v28, v29, v30, v31, v32, v33, v34, v35);
  sub_940407DC(1u, ">>>>>>>>>>>>>>>>  avb_slot_verify result is %s.\n", v37, v38, v39, v40, v41, v42, v43, v44, v36);
  sub_940407DC(1u, "slot_data[0] is 0x%x.\n", v45, v46, v47, v48, v49, v50, v51, v52, MEMORY[0xFFFFFFFFE0057F18]);
  sub_940407DC(1u, "slot_data[1] is 0x%x.\n", v53, v54, v55, v56, v57, v58, v59, v60, MEMORY[0xFFFFFFFFE0057F20]);
  return v19;
}

/* ===== nullsub_9 @ 0x94047B08 size 4 ===== */
void nullsub_9()
{
  ;
}

/* ===== sub_94047B0C @ 0x94047B0C size 292 ===== */
__int64 __fastcall sub_94047B0C(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w19
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v38; // [xsp+38h] [xbp+38h]
  __int64 v39; // [xsp+48h] [xbp+48h] BYREF

  sub_940407DC(1u, "enter vboot set_version\n", a2, a3, a4, a5, a6, a7, a8, a9);
  v10 = *(_DWORD *)(a1 + 8);
  v38 = *(unsigned int *)(a1 + 12);
  sub_94040888(-536460624, 0, 0x38u);
  sub_940407DC(1u, "from uboot smc...addr:0x%x len:0x%x\n", v11, v12, v13, v14, v15, v16, v17, v18, v10, v38);
  v19 = sub_940408CC((__int64)"sprdsec", v10, 0x1000u, 0x30u, (__int64)&v39);
  if ( v19 != 0 )
  {
    sub_940407DC(1u, "can not map phy addr 1 , ret:%d\n", v20, v21, v22, v23, v24, v25, v26, v27, v19);
    return (int)v19;
  }
  else
  {
    sub_94040880(-536460624, v39, 0x38u);
    nullsub_9();
    if ( v39 != 0 && (v28 = sub_940408F4(v39)) != 0 )
    {
      sub_940407DC(1u, "can not unmap virt addr, ret:%d\n", v29, v30, v31, v32, v33, v34, v35, v36, v28);
      return (int)v28;
    }
    else
    {
      return 0;
    }
  }
}

/* ===== sub_94047C30 @ 0x94047C30 size 1928 ===== */
__int64 __fastcall sub_94047C30(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w20
  unsigned int v19; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x0
  unsigned int v37; // w25
  unsigned int v38; // w24
  unsigned int v39; // w23
  unsigned int v40; // w22
  unsigned int v41; // w20
  unsigned int v42; // w21
  unsigned int v43; // w19
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // w1
  unsigned int v61; // w19
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int v86; // w19
  unsigned int v87; // w27
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned int v96; // w0
  __int64 v97; // x0
  unsigned int v98; // w0
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  unsigned int v107; // w19
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  unsigned int v117; // w19
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  unsigned int v134; // w0
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  __int64 v151; // x27
  unsigned int v152; // w0
  __int64 v153; // x19
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  __int64 v162; // [xsp+68h] [xbp+68h]
  unsigned int v163; // [xsp+70h] [xbp+70h] BYREF
  unsigned int v164; // [xsp+74h] [xbp+74h] BYREF
  __int64 v165; // [xsp+78h] [xbp+78h] BYREF
  __int64 v166; // [xsp+80h] [xbp+80h] BYREF
  unsigned __int64 v167; // [xsp+88h] [xbp+88h] BYREF
  __int64 v168; // [xsp+90h] [xbp+90h] BYREF
  __int64 v169; // [xsp+98h] [xbp+98h] BYREF
  __int64 v170; // [xsp+A0h] [xbp+A0h] BYREF
  __int64 v171; // [xsp+A8h] [xbp+A8h] BYREF
  __int64 v172; // [xsp+B0h] [xbp+B0h] BYREF
  __int64 v173; // [xsp+B8h] [xbp+B8h] BYREF
  unsigned __int64 v174; // [xsp+C0h] [xbp+C0h] BYREF
  unsigned __int64 v175; // [xsp+C8h] [xbp+C8h] BYREF

  v165 = 0;
  v166 = 0;
  v167 = 0;
  v168 = 0;
  v169 = 0;
  v170 = 0;
  v163 = 0;
  v171 = 0;
  v172 = 0;
  v173 = 0;
  v164 = 0;
  v174 = 0;
  v175 = 0;
  sub_940407DC(1u, "enter vboot verify\n", a2, a3, a4, a5, a6, a7, a8, a9);
  sub_94040EFC(v10, v11, v12, v13, v14, v15, v16, v17);
  v18 = *(_DWORD *)(a1 + 12);
  v19 = *(_DWORD *)(a1 + 8);
  sub_940407DC(1u, "from uboot smc...addr:0x%x len:0x%x\n", v20, v21, v22, v23, v24, v25, v26, v27, v19, v18);
  if ( v18 != 0 && v19 != 0 )
  {
    v117 = sub_940408CC((__int64)"sprdsec", v19, 0x1000u, 0x30u, (__int64)&v171);
    if ( v117 != 0 )
    {
      sub_940407DC(1u, "can not map phy addr 1 , ret:%d\n", v28, v29, v30, v31, v32, v33, v34, v35, v117);
      return (int)v117;
    }
  }
  v36 = v171;
  v37 = *(_DWORD *)(v171 + 8);
  if ( v37 != 0 )
  {
    sub_940407DC(
      1u,
      "from uboot smc...addr:0x%x len:0x%x\n",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      *(_QWORD *)v171,
      v37);
    v43 = sub_940408CC((__int64)"sprdsec", *(_QWORD *)v171, (v37 & 0xFFFFF000) + 4096, 0x30u, (__int64)&v165);
    if ( v43 != 0 )
      goto LABEL_55;
    v36 = v171;
  }
  v38 = *(_DWORD *)(v36 + 24);
  if ( v38 != 0 )
  {
    sub_940407DC(
      1u,
      "from uboot smc...addr:0x%x len:0x%x\n",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      *(_QWORD *)(v36 + 16),
      v38);
    v43 = sub_940408CC((__int64)"sprdsec", *(_QWORD *)(v171 + 16), (v38 & 0xFFFFF000) + 4096, 0x30u, (__int64)&v166);
    if ( v43 != 0 )
      goto LABEL_55;
    v36 = v171;
  }
  v39 = *(_DWORD *)(v36 + 40);
  if ( v39 == 0 )
  {
    v40 = *(_DWORD *)(v36 + 56);
    if ( v40 == 0 )
      goto LABEL_7;
LABEL_44:
    sub_940407DC(
      1u,
      "from uboot smc...addr:0x%x len:0x%x\n",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      *(_QWORD *)(v36 + 48),
      v40);
    v43 = sub_940408CC((__int64)"sprdsec", *(_QWORD *)(v171 + 48), (v40 & 0xFFFFF000) + 4096, 0x30u, (__int64)&v168);
    if ( v43 != 0 )
      goto LABEL_55;
    v36 = v171;
    v41 = *(_DWORD *)(v171 + 72);
    if ( v41 == 0 )
      goto LABEL_8;
    goto LABEL_46;
  }
  sub_940407DC(
    1u,
    "from uboot smc...addr:0x%x len:0x%x\n",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    *(_QWORD *)(v36 + 32),
    v39);
  v43 = sub_940408CC((__int64)"sprdsec", *(_QWORD *)(v171 + 32), (v39 & 0xFFFFF000) + 4096, 0x30u, (__int64)&v167);
  if ( v43 != 0 )
    goto LABEL_55;
  v36 = v171;
  v40 = *(_DWORD *)(v171 + 56);
  if ( v40 != 0 )
    goto LABEL_44;
LABEL_7:
  v41 = *(_DWORD *)(v36 + 72);
  if ( v41 != 0 )
  {
LABEL_46:
    sub_940407DC(
      1u,
      "from uboot smc...addr:0x%x len:0x%x\n",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      *(_QWORD *)(v36 + 64),
      v41);
    v43 = sub_940408CC((__int64)"sprdsec", *(_QWORD *)(v171 + 64), (v41 & 0xFFFFF000) + 4096, 0x30u, (__int64)&v169);
    if ( v43 == 0 )
    {
      v36 = v171;
      goto LABEL_8;
    }
LABEL_55:
    sub_940407DC(1u, "can not map phy addr 2 , ret:%d\n", v28, v29, v30, v31, v32, v33, v34, v35, v43);
    return (int)v43;
  }
LABEL_8:
  v42 = *(_DWORD *)(v36 + 88);
  if ( v42 != 0 )
  {
    sub_940407DC(
      1u,
      "from uboot smc...addr:0x%x len:0x%x\n",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      *(_QWORD *)(v36 + 80),
      v42);
    v43 = sub_940408CC((__int64)"sprdsec", *(_QWORD *)(v171 + 80), (v42 & 0xFFFFF000) + 4096, 0x30u, (__int64)&v170);
    if ( v43 != 0 )
      goto LABEL_55;
  }
  sub_940407DC(1u, "vb_cmdline_len:%d, vbmeta_pubkey_addr:0x%x\n", v28, v29, v30, v31, v32, v33, v34, v35, v41, v169);
  sub_940407DC(1u, "vb_cmdline_len:%d, vbmeta_pubkey_addr:0x%x\n", v44, v45, v46, v47, v48, v49, v50, v51, v42, v170);
  MEMORY[0xFFFFFFFFE00643D0] = v165;
  MEMORY[0xFFFFFFFFE00643E0] = v167;
  v60 = *(_DWORD *)(v171 + 92);
  MEMORY[0xFFFFFFFFE00643E8] = v168;
  MEMORY[0xFFFFFFFFE0064400] = v37;
  MEMORY[0xFFFFFFFFE00643D8] = v166;
  MEMORY[0xFFFFFFFFE0064404] = v38;
  MEMORY[0xFFFFFFFFE0064408] = v39;
  MEMORY[0xFFFFFFFFE006440C] = v40;
  MEMORY[0xFFFFFFFFE0064410] = v41;
  MEMORY[0xFFFFFFFFE00643F0] = v169;
  MEMORY[0xFFFFFFFFE0064418] = v60;
  if ( v166 != 0 && v38 != 0 )
  {
    sub_94047584();
    v87 = 0;
    sub_940407DC(
      1u,
      "img_name:%s, g_avbUserData.img_name:%s.\n",
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v165,
      MEMORY[0xFFFFFFFFE00643D0]);
    v86 = sub_940479D4(v165, v126, v127, v128, v129, v130, v131, v132, v133);
    v163 = v86;
  }
  else
  {
    sub_940407DC(1u, "enter vbmeta check\n", v52, v53, v54, v55, v56, v57, v58, v59);
    sub_94047584();
    v61 = sub_94046B5C(v167, v39, &v172, &v173, &v174);
    sub_940407DC(1u, (const char *)sub_94057450, v62, v63, v64, v65, v66, v67, v68, v69, v61);
    sub_940407DC(1u, "rollback_index is %lld.\n", v70, v71, v72, v73, v74, v75, v76, v77, v174);
    if ( v61 != 0 )
    {
      v86 = 1;
      v163 = 1;
      v87 = 1;
    }
    else
    {
      v87 = 1;
      v163 = MEMORY[0xFFFFFFFFE00643A8](-536460416, v172, v173, 0, 0, &v164);
      sub_940407DC(1u, (const char *)&loc_94057488, v154, v155, v156, v157, v158, v159, v160, v161, v163, v164);
      v86 = v163;
      if ( v163 == 0 )
      {
        sub_940407DC(1u, "Check rollback index for vbmeta \n", v78, v79, v80, v81, v82, v83, v84, v85);
        if ( (unsigned int)MEMORY[0xFFFFFFFFE00643B0](-536460416, 0, &v175) != 0 )
        {
          v86 = 4;
          v163 = 4;
        }
        else if ( v174 >= v175 )
        {
          sub_940407DC(
            1u,
            "Info: vbmeta rollback_index:%lld, >= stored_rollback_index:%lld.\n",
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85);
          v163 = 0;
        }
        else
        {
          sub_940407DC(
            1u,
            "Error: vbmeta rollback_index:%lld, < stored_rollback_index:%lld.\n",
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85);
          v163 = 4;
          v86 = 4;
        }
      }
    }
  }
  sub_940407DC(1u, (const char *)&loc_940575A0, v78, v79, v80, v81, v82, v83, v84, v85, v86);
  if ( (unsigned int)sub_94040878(v165, (__int64)"boot") == 0 && MEMORY[0xFFFFFFFFE0064418] == 1 )
  {
    v96 = v163;
    if ( v163 == 5 )
      goto LABEL_60;
  }
  else
  {
    v96 = v163;
  }
  if ( v96 != 0 )
  {
    while ( 1 )
      ;
  }
  if ( v87 == 0 )
  {
    if ( MEMORY[0xFFFFFFFFE0057F18] != 0 )
    {
      v97 = *(_QWORD *)(MEMORY[0xFFFFFFFFE0057F18] + 40LL);
      if ( v97 != 0 )
      {
        if ( (unsigned int)sub_94040AC4(v97) != 0 )
        {
          v134 = sub_94040AC4(*(_QWORD *)(MEMORY[0xFFFFFFFFE0057F18] + 40LL));
          sub_940407DC(1u, (const char *)&loc_940575C0, v135, v136, v137, v138, v139, v140, v141, v142, v134);
          sub_94040AC4(*(_QWORD *)(MEMORY[0xFFFFFFFFE0057F18] + 40LL));
          nullsub_9();
          sub_940407DC(
            1u,
            "avb_slot_data[0]->cmdline is %s\n",
            v143,
            v144,
            v145,
            v146,
            v147,
            v148,
            v149,
            v150,
            *(_QWORD *)(MEMORY[0xFFFFFFFFE0057F18] + 40LL));
          v151 = v169;
          v162 = *(_QWORD *)(MEMORY[0xFFFFFFFFE0057F18] + 40LL);
          v152 = sub_94040AC4(v162);
          sub_94040880(v151, v162, v152);
          v153 = v169;
          *(_BYTE *)(v153 + (unsigned int)sub_94040AC4(*(_QWORD *)(MEMORY[0xFFFFFFFFE0057F18] + 40LL))) = 0;
          sub_940408B0(v169, v41);
LABEL_24:
          if ( MEMORY[0xFFFFFFFFE0057F18] != 0 )
            sub_940458E8(MEMORY[0xFFFFFFFFE0057F18]);
          goto LABEL_26;
        }
        v97 = *(_QWORD *)(MEMORY[0xFFFFFFFFE0057F18] + 40LL);
      }
    }
    else
    {
      v97 = MEMORY[0x28];
    }
    v98 = sub_94040AC4(v97);
    sub_940407DC(1u, "avb_slot_data[0]->cmdline para error,  %d\n", v99, v100, v101, v102, v103, v104, v105, v106, v98);
    goto LABEL_24;
  }
LABEL_60:
  sub_940407DC(1u, (const char *)&loc_94057648, v88, v89, v90, v91, v92, v93, v94, v95, v87);
LABEL_26:
  sub_94040880(v170, (__int64)&v163, 4u);
  if ( (v171 == 0 || (v107 = sub_940408F4(v171)) == 0)
    && (v165 == 0 || (v107 = sub_940408F4(v165)) == 0)
    && (v166 == 0 || (v107 = sub_940408F4(v166)) == 0)
    && (v167 == 0 || (v107 = sub_940408F4(v167)) == 0)
    && (v168 == 0 || (v107 = sub_940408F4(v168)) == 0)
    && (v169 == 0 || (v107 = sub_940408F4(v169)) == 0) )
  {
    if ( v170 == 0 )
      return 0;
    v107 = sub_940408F4(v170);
    if ( v107 == 0 )
      return 0;
  }
  sub_940407DC(1u, "can not unmap virt addr, ret:%d\n", v108, v109, v110, v111, v112, v113, v114, v115, v107);
  return (int)v107;
}

/* ===== sub_940483B8 @ 0x940483B8 size 1564 ===== */
__int64 __fastcall sub_940483B8(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w20
  unsigned int v19; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w19
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x0
  unsigned int v38; // w24
  unsigned int v39; // w20
  unsigned int v40; // w21
  unsigned int v41; // w22
  unsigned int v42; // w23
  unsigned int v43; // w19
  unsigned int v44; // w19
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w25
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned int v70; // w19
  unsigned int v71; // w19
  unsigned int v72; // w19
  unsigned int v73; // w19
  unsigned int *v75; // x19
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 *v84; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  unsigned int v101; // w19
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 v110; // [xsp+58h] [xbp+58h]
  int v111; // [xsp+68h] [xbp+68h] BYREF
  int v112; // [xsp+6Ch] [xbp+6Ch] BYREF
  unsigned __int64 v113; // [xsp+70h] [xbp+70h] BYREF
  __int64 v114; // [xsp+78h] [xbp+78h] BYREF
  __int64 v115; // [xsp+80h] [xbp+80h] BYREF
  __int64 v116; // [xsp+88h] [xbp+88h] BYREF
  __int64 v117; // [xsp+90h] [xbp+90h] BYREF
  __int64 v118; // [xsp+98h] [xbp+98h] BYREF
  __int64 v119; // [xsp+A0h] [xbp+A0h] BYREF
  __int64 v120; // [xsp+A8h] [xbp+A8h] BYREF

  v113 = 0;
  v114 = 0;
  v115 = 0;
  v116 = 0;
  v117 = 0;
  v118 = 0;
  v119 = 0;
  v120 = 0;
  v111 = 0;
  sub_940407DC(1u, "enter vboot verify\n", a2, a3, a4, a5, a6, a7, a8, a9);
  sub_94040EFC(v10, v11, v12, v13, v14, v15, v16, v17);
  v18 = *(_DWORD *)(a1 + 12);
  v19 = *(_DWORD *)(a1 + 8);
  sub_940407DC(1u, "from uboot smc...addr:0x%x len:0x%x\n", v20, v21, v22, v23, v24, v25, v26, v27, v19, v18);
  if ( v18 == 0 || v19 == 0 )
    return -1;
  v28 = sub_940408CC((__int64)"sprdsec", v19, 0x1000u, 0x30u, (__int64)&v118);
  if ( v28 != 0 )
  {
    sub_940407DC(1u, "can not map phy addr ns_addr , ret:%d\n", v29, v30, v31, v32, v33, v34, v35, v36, v28);
    return (int)v28;
  }
  v37 = v118;
  if ( v118 == 0 )
  {
    sub_940407DC(1u, "imginfo address error\n", v29, v30, v31, v32, v33, v34, v35, v36);
    return -1;
  }
  v38 = *(_DWORD *)(v118 + 8);
  if ( v38 != 0 )
  {
    sub_940407DC(
      1u,
      "from uboot smc...addr:0x%x len:0x%x\n",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      *(_QWORD *)v118,
      v38);
    v73 = sub_940408CC((__int64)"sprdsec", *(_QWORD *)v118, (v38 & 0xFFFFF000) + 4096, 0x30u, (__int64)&v113);
    if ( v73 != 0 )
    {
      sub_940407DC(1u, "can not map phy addr vbmeta_img_paddr , ret:%d\n", v29, v30, v31, v32, v33, v34, v35, v36, v73);
      return (int)v73;
    }
    v37 = v118;
  }
  v39 = *(_DWORD *)(v37 + 24);
  if ( v39 != 0 )
  {
    sub_940407DC(
      1u,
      "from uboot smc...addr:0x%x len:0x%x\n",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      *(_QWORD *)(v37 + 16),
      v39);
    v72 = sub_940408CC((__int64)"sprdsec", *(_QWORD *)(v118 + 16), (v39 & 0xFFFFF000) + 4096, 0x30u, (__int64)&v114);
    if ( v72 != 0 )
    {
      sub_940407DC(
        1u,
        "can not map phy addr vbmeta_pubkey_addr , ret:%d\n",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v72);
      return (int)v72;
    }
    v37 = v118;
  }
  v40 = *(_DWORD *)(v37 + 40);
  if ( v40 != 0 )
  {
    sub_940407DC(
      1u,
      "from uboot smc...addr:0x%x len:0x%x\n",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      *(_QWORD *)(v37 + 32),
      v40);
    v70 = sub_940408CC((__int64)"sprdsec", *(_QWORD *)(v118 + 32), (v40 & 0xFFFFF000) + 4096, 0x30u, (__int64)&v115);
    if ( v70 != 0 )
    {
      sub_940407DC(1u, "can not map phy addr product_sn_addr , ret:%d\n", v29, v30, v31, v32, v33, v34, v35, v36, v70);
      return (int)v70;
    }
    v37 = v118;
    v41 = *(_DWORD *)(v118 + 56);
    if ( v41 == 0 )
      goto LABEL_9;
  }
  else
  {
    v41 = *(_DWORD *)(v37 + 56);
    if ( v41 == 0 )
      goto LABEL_9;
  }
  sub_940407DC(
    1u,
    "from uboot smc...addr:0x%x len:0x%x\n",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    *(_QWORD *)(v37 + 48),
    v41);
  v71 = sub_940408CC((__int64)"sprdsec", *(_QWORD *)(v118 + 48), (v41 & 0xFFFFF000) + 4096, 0x30u, (__int64)&v116);
  if ( v71 != 0 )
  {
    sub_940407DC(
      1u,
      "can not map phy addr product_sn_signature_addr , ret:%d\n",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v71);
    return (int)v71;
  }
  v37 = v118;
LABEL_9:
  v42 = *(_DWORD *)(v37 + 72);
  if ( v42 != 0
    && (sub_940407DC(
          1u,
          "from uboot smc...addr:0x%x len:0x%x\n",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          *(_QWORD *)(v37 + 64),
          v42),
        (v43 = sub_940408CC(
                 (__int64)"sprdsec",
                 *(_QWORD *)(v118 + 64),
                 (v42 & 0xFFFFF000) + 4096,
                 0x30u,
                 (__int64)&v117)) != 0) )
  {
    sub_940407DC(1u, "can not map phy addr 2 , ret:%d\n", v29, v30, v31, v32, v33, v34, v35, v36, v43);
    return (int)v43;
  }
  else
  {
    v44 = 1;
    sub_940407DC(1u, (const char *)&loc_94057780, v29, v30, v31, v32, v33, v34, v35, v36, v42, v117);
    MEMORY[0xFFFFFFFFE00643E0] = v113;
    MEMORY[0xFFFFFFFFE00643E8] = v114;
    MEMORY[0xFFFFFFFFE0064408] = v38;
    MEMORY[0xFFFFFFFFE006440C] = v39;
    sub_940407DC(1u, "Enter vbmeta check\n", v45, v46, v47, v48, v49, v50, v51, v52);
    sub_94047584();
    v53 = sub_94046B5C(v113, v38, &v119, &v120, nullptr);
    sub_940407DC(1u, (const char *)sub_94057450, v54, v55, v56, v57, v58, v59, v60, v61, v53);
    if ( v53 == 0 )
      v44 = MEMORY[0xFFFFFFFFE00643A8](-536460416, v119, v120, 0, 0, &v111);
    sub_940407DC(1u, (const char *)&loc_940575A0, v62, v63, v64, v65, v66, v67, v68, v69, v44);
    if ( v44 != 0 )
    {
      while ( 1 )
        ;
    }
    v75 = (unsigned int *)sub_94046700(200);
    if ( v75 != nullptr )
    {
      sub_940407DC(1u, "Calculate hash with product_sn\n", v76, v77, v78, v79, v80, v81, v82, v83);
      sub_94043BDC(v75);
      sub_94043C48(v75, v115, v40);
      v110 = sub_94043D28((__int64)v75);
      v84 = sub_94042C24(2u);
      if ( v84 != nullptr )
      {
        v112 = sub_94043558(
                 v119,
                 v120,
                 v116,
                 v41,
                 v110,
                 *((unsigned int *)v84 + 4),
                 *v84,
                 v84[1],
                 v85,
                 v86,
                 v87,
                 v88,
                 v89,
                 v90,
                 v91,
                 v92);
        if ( v112 != 0 )
          sub_940407DC(1u, (const char *)&loc_940577F8, v93, v94, v95, v96, v97, v98, v99, v100);
      }
      else
      {
        sub_940407DC(0, "Invalid or unknown algorithm.\n", v85, v86, v87, v88, v89, v90, v91, v92);
      }
      sub_94046430((__int64)v75);
    }
    else
    {
      sub_940407DC(0, "malloc failed.\n", v76, v77, v78, v79, v80, v81, v82, v83);
    }
    sub_94040880(v117, (__int64)&v112, 4u);
    v101 = sub_940408F4(v118);
    if ( v101 != 0
      || v113 != 0 && (v101 = sub_940408F4(v113)) != 0
      || v114 != 0 && (v101 = sub_940408F4(v114)) != 0
      || v115 != 0 && (v101 = sub_940408F4(v115)) != 0
      || v116 != 0 && (v101 = sub_940408F4(v116)) != 0
      || v117 != 0 && (v101 = sub_940408F4(v117)) != 0 )
    {
      sub_940407DC(1u, "can not unmap virt addr, ret:%d\n", v102, v103, v104, v105, v106, v107, v108, v109, v101);
      return (int)v101;
    }
    else
    {
      return 0;
    }
  }
}

/* ===== sub_940489D4 @ 0x940489D4 size 472 ===== */
__int64 __fastcall sub_940489D4(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w19
  unsigned __int64 v29; // x25
  unsigned __int64 v30; // x22
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  int v39; // w4
  int v40; // w23
  unsigned int v41; // w19
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w19
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v60; // [xsp+58h] [xbp+58h]
  unsigned int v61; // [xsp+6Ch] [xbp+6Ch] BYREF
  __int64 v62; // [xsp+70h] [xbp+70h] BYREF
  _DWORD v63[2]; // [xsp+78h] [xbp+78h] BYREF

  v61 = 0;
  sub_940407DC(1u, "enter sprd_vboot_config_os_version\n", a2, a3, a4, a5, a6, a7, a8, a9);
  v10 = *(_DWORD *)(a1 + 8);
  v60 = *(unsigned int *)(a1 + 12);
  sub_94040888(-536477112, 0, 0x1000u);
  sub_940407DC(1u, "from uboot smc...addr:0x%x len:0x%x\n", v11, v12, v13, v14, v15, v16, v17, v18, v10, v60);
  v19 = sub_940408CC((__int64)"sprdsec", v10, 0x1000u, 0x30u, (__int64)&v62);
  if ( v19 != 0 )
  {
    sub_940407DC(1u, "can not map phy addr 1 , ret:%d\n", v20, v21, v22, v23, v24, v25, v26, v27, v19);
    return (int)v19;
  }
  else
  {
    sub_94040880((__int64)&v61, v62, 4u);
    v28 = v61 >> 25;
    v29 = ((unsigned __int64)v61 >> 18) & 0x7F;
    v30 = ((unsigned __int64)v61 >> 11) & 0x7F;
    sub_940407DC(
      1u,
      "System version(Major.Minor.Sub_minor): (%d.%d.%d)\n",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v61 >> 25,
      (unsigned int)v29,
      (unsigned int)v30);
    v39 = v29 + 100 * v28;
    v40 = v61 & 0xF;
    v41 = ((v61 >> 4) & 0x7F) + 2000;
    v63[0] = v30 + 100 * v39;
    sub_940407DC(
      1u,
      "System security patch level(Year-Month): (%04d-%02d)\n",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v41,
      v61 & 0xF);
    v63[1] = v40 + 100 * v41;
    sub_94040880(-536477112, (__int64)v63, 8u);
    MEMORY[0xFFFFFFFFE0061248] = 8;
    nullsub_9();
    if ( v62 != 0 && (v50 = sub_940408F4(v62)) != 0 )
    {
      sub_940407DC(1u, "can not unmap virt addr, ret:%d\n", v51, v52, v53, v54, v55, v56, v57, v58, v50);
      return (int)v50;
    }
    else
    {
      return 0;
    }
  }
}

/* ===== sub_94048BAC @ 0x94048BAC size 204 ===== */
__int64 __fastcall sub_94048BAC(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  __int64 v22; // x19
  __int64 v23; // x2
  __int64 v24; // x2
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  sub_940407DC(1u, "%s", a4, a5, a6, a7, a8, a9, a10, a11, a1);
  if ( a3 > 0 )
  {
    v21 = (unsigned int)(a3 - 1) + 1LL;
    v22 = 0;
    do
    {
      while ( (v22 & 0xF) != 0 )
      {
        v23 = *(unsigned __int8 *)(a2 + v22++);
        sub_940407DC(1u, " %02x", v13, v14, v15, v16, v17, v18, v19, v20, v23);
        if ( v22 == v21 )
          return sub_940407DC(1u, "\n", v13, v14, v15, v16, v17, v18, v19, v20);
      }
      sub_940407DC(1u, "\n%04x", v13, v14, v15, v16, v17, v18, v19, v20, (unsigned int)v22);
      v24 = *(unsigned __int8 *)(a2 + v22++);
      sub_940407DC(1u, " %02x", v25, v26, v27, v28, v29, v30, v31, v32, v24);
    }
    while ( v22 != v21 );
  }
  return sub_940407DC(1u, "\n", v13, v14, v15, v16, v17, v18, v19, v20);
}

/* ===== sub_94048C78 @ 0x94048C78 size 200 ===== */
const char *__fastcall sub_94048C78(int a1)
{
  const char *result; // x0

  switch ( a1 )
  {
    case 0:
      result = "VBMETA";
      break;
    case 1:
      result = "BOOT";
      break;
    case 2:
      result = "RECOVERY";
      break;
    case 3:
      result = "SYSTEM";
      break;
    case 4:
      result = "VENDOR";
      break;
    case 5:
      result = "MODEM";
      break;
    case 6:
      result = "LDSP";
      break;
    case 7:
      result = "LGDSP";
      break;
    case 8:
      result = "PM_SYS";
      break;
    case 9:
      result = "AGDSP";
      break;
    case 10:
      result = "WCN";
      break;
    case 11:
      result = "GPS";
      break;
    case 12:
      result = "GPU";
      break;
    default:
      result = "Unknown";
      break;
  }
  return result;
}

/* ===== sub_94048D40 @ 0x94048D40 size 108 ===== */
__int64 __fastcall sub_94048D40(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x19
  __int64 result; // x0
  const char *v12; // x0
  __int64 v13; // x3
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v10 = 0;
  result = sub_940407DC(1u, "kbc_v2_dump_version \n", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( a1 != 0 )
  {
    do
    {
      v12 = sub_94048C78(v10);
      v13 = *(unsigned int *)(a1 + 4 * v10++);
      result = sub_940407DC(1u, "%8s ver = %d \n", v14, v15, v16, v17, v18, v19, v20, v21, v12, v13);
    }
    while ( v10 != 13 );
  }
  return result;
}

/* ===== sub_94048DAC @ 0x94048DAC size 104 ===== */
__int64 __fastcall sub_94048DAC(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  sub_940407DC(1u, "[kbc]avb_userdata_set() packed offset = 0x%x\n", a4, a5, a6, a7, a8, a9, a10, a11);
  sub_94040888(-536460336, 0, 0x50u);
  MEMORY[0xFFFFFFFFE00643D8] = a1;
  MEMORY[0xFFFFFFFFE00643F8] = a2;
  MEMORY[0xFFFFFFFFE0064414] = a3;
  MEMORY[0xFFFFFFFFE0064408] = 0x10000;
  return 0x10000;
}

/* ===== sub_94048E14 @ 0x94048E14 size 216 ===== */
__int64 __fastcall sub_94048E14(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v61[2]; // [xsp+20h] [xbp+20h] BYREF

  v61[1] = 0;
  sub_940407DC(1u, "[kbc]avb_check_kbc_image() name = %s\n", a2, a3, a4, a5, a6, a7, a8, a9, a1);
  v61[0] = a1;
  v18 = sub_940459C4(
          -536460416,
          v61,
          (__int64)"",
          0,
          (__int64 *)0xFFFFFFFFE0057F18LL,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17);
  sub_940407DC(1u, "[kbc]avb_slot_verify result is %d.\n", v19, v20, v21, v22, v23, v24, v25, v26, v18);
  v35 = sub_94046314(v18, v27, v28, v29, v30, v31, v32, v33, v34);
  sub_940407DC(1u, "[kbc]avb_slot_verify result is %s.\n", v36, v37, v38, v39, v40, v41, v42, v43, v35);
  sub_940407DC(1u, "[kbc]slot_data[0] is 0x%x.\n", v44, v45, v46, v47, v48, v49, v50, v51, MEMORY[0xFFFFFFFFE0057F18]);
  sub_940407DC(1u, "[kbc]slot_data[1] is 0x%x.\n", v52, v53, v54, v55, v56, v57, v58, v59, MEMORY[0xFFFFFFFFE0057F20]);
  if ( MEMORY[0xFFFFFFFFE0057F18] != 0 )
    sub_940458E8(MEMORY[0xFFFFFFFFE0057F18]);
  return v18;
}

/* ===== sub_94048EEC @ 0x94048EEC size 480 ===== */
__int64 __fastcall sub_94048EEC(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x19
  unsigned int v11; // w20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v37; // w21
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned int v78; // w21
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  unsigned int v95; // w21
  __int64 v96; // [xsp+58h] [xbp+58h] BYREF

  v10 = a1 + 112;
  v11 = 0;
  v96 = 0;
  sub_940407DC(1u, "[kbc]kbc_image_verify_v2() enter.\n", a2, a3, a4, a5, a6, a7, a8, a9);
  sub_94047974();
  while ( 1 )
  {
    if ( *(_QWORD *)(v10 - 112) == 0 )
    {
      sub_940407DC(1u, "[kbc]invalid image [%d]\n", v12, v13, v14, v15, v16, v17, v18, v19, v11);
      goto LABEL_4;
    }
    sub_940407DC(
      1u,
      "[kbc]call mem map:ns addr = %p map len = 0x%x \n",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      *(_QWORD *)(v10 - 112),
      *(unsigned int *)(v10 - 100));
    v37 = sub_940408CC(
            (__int64)"sprdsec",
            *(_QWORD *)(v10 - 112),
            (*(_DWORD *)(v10 - 100) & 0xFFFFF000) + 4096,
            0x30u,
            (__int64)&v96);
    if ( v37 != 0 )
      break;
    sub_940407DC(1u, "[kbc]after map:pAddr = %p\n", v38, v39, v40, v41, v42, v43, v44, v45, v96);
    sub_94048BAC((__int64)"pAddr:", v96, 16, v46, v47, v48, v49, v50, v51, v52, v53);
    sub_94048DAC(v96, v10 - 96, *(_DWORD *)(a1 + 452), v54, v55, v56, v57, v58, v59, v60, v61);
    sub_940407DC(1u, "[kbc]start verify... \n", v62, v63, v64, v65, v66, v67, v68, v69);
    v78 = sub_94048E14(v10 - 32, v70, v71, v72, v73, v74, v75, v76, v77);
    sub_940407DC(1u, "[kbc]ret = %d\n", v79, v80, v81, v82, v83, v84, v85, v86, v78);
    if ( v78 != 0 )
    {
      sub_940407DC(1u, "[kbc]kbc verify failed!\n", v87, v88, v89, v90, v91, v92, v93, v94);
      sub_94040A88(0x3E8u);
      while ( 1 )
        ;
    }
    v95 = sub_940408F4(v96);
    if ( v95 != 0 )
    {
      sub_940407DC(1u, "[kbc]can not unmap virt addr, ret = %d \n", v12, v13, v14, v15, v16, v17, v18, v19, v95);
      return (int)v95;
    }
LABEL_4:
    ++v11;
    v10 += 112;
    if ( v11 == 4 )
    {
      sub_940407DC(1u, "[kbc]verify success. \n", v12, v13, v14, v15, v16, v17, v18, v19);
      sub_94048BAC((__int64)"version:", -536460624, 56, v20, v21, v22, v23, v24, v25, v26, v27);
      sub_94048D40(-536460624, v28, v29, v30, v31, v32, v33, v34, v35);
      return 0;
    }
  }
  sub_940407DC(1u, "[kbc]can not map, ret = %d \n", v38, v39, v40, v41, v42, v43, v44, v45, v37);
  return (int)v37;
}

/* ===== sub_940490CC @ 0x940490CC size 24 ===== */
__int64 __fastcall sub_940490CC(__int64 a1)
{
  return (*(__int64 (**)(void))(a1 + 48))();
}

/* ===== sub_940490E4 @ 0x940490E4 size 24 ===== */
__int64 __fastcall sub_940490E4(__int64 a1)
{
  return (*(__int64 (**)(void))(a1 + 40))();
}

/* ===== sub_940490FC @ 0x940490FC size 20 ===== */
__int64 __fastcall sub_940490FC(int a1)
{
  return ((__int64)a1 << 6) - 536622672;
}

/* ===== sub_94049110 @ 0x94049110 size 32 ===== */
__int64 __fastcall sub_94049110(__int64 a1)
{
  if ( (*(_DWORD *)(**(_QWORD **)(a1 + 56) + 24LL) & 0x1FF) == *(_DWORD *)(**(_QWORD **)(a1 + 56) + 60LL) )
    return 0;
  else
    return 0xFFFFFFFFLL;
}

/* ===== sub_94049130 @ 0x94049130 size 52 ===== */
__int64 __fastcall sub_94049130(__int64 *a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x1

  v3 = *a1;
  *(_DWORD *)(v3 + 24) &= 0xFFFFFC00;
  *(_DWORD *)(v3 + 24) |= a3 & 0x1FF;
  *(_DWORD *)(v3 + 24) |= 0x200u;
  return a3;
}

/* ===== sub_94049164 @ 0x94049164 size 48 ===== */
__int64 __fastcall sub_94049164(_BYTE **a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x3
  char v4; // w5

  if ( a3 == 0 )
    return 0;
  v3 = 0;
  do
  {
    v4 = *(_BYTE *)(a2 + v3++);
    **a1 = v4;
  }
  while ( a3 > (unsigned int)v3 );
  return a3;
}

/* ===== sub_94049194 @ 0x94049194 size 48 ===== */
__int64 __fastcall sub_94049194(_WORD **a1, __int64 a2, unsigned int a3)
{
  _WORD *v3; // x0
  __int64 v4; // x3
  __int16 v5; // w4

  if ( a3 == 0 )
    return 0;
  v3 = *a1;
  v4 = 0;
  do
  {
    v5 = *(_WORD *)(a2 + 2 * v4++);
    *v3 = v5;
  }
  while ( a3 > (unsigned int)v4 );
  return 2 * a3;
}

/* ===== sub_940491C4 @ 0x940491C4 size 48 ===== */
__int64 __fastcall sub_940491C4(_DWORD **a1, __int64 a2, unsigned int a3)
{
  _DWORD *v3; // x0
  __int64 v4; // x3
  int v5; // w4

  if ( a3 == 0 )
    return 0;
  v3 = *a1;
  v4 = 0;
  do
  {
    v5 = *(_DWORD *)(a2 + 4 * v4++);
    *v3 = v5;
  }
  while ( a3 > (unsigned int)v4 );
  return 4 * a3;
}

/* ===== sub_940491F4 @ 0x940491F4 size 48 ===== */
__int64 __fastcall sub_940491F4(_BYTE **a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x3

  if ( a3 == 0 )
    return 0;
  v3 = 0;
  do
    *(_BYTE *)(a2 + v3++) = **a1;
  while ( a3 > (unsigned int)v3 );
  return a3;
}

/* ===== sub_94049224 @ 0x94049224 size 48 ===== */
__int64 __fastcall sub_94049224(_WORD **a1, __int64 a2, unsigned int a3)
{
  _WORD *v3; // x0
  __int64 v4; // x3

  if ( a3 == 0 )
    return 0;
  v3 = *a1;
  v4 = 0;
  do
    *(_WORD *)(a2 + 2 * v4++) = *v3;
  while ( a3 > (unsigned int)v4 );
  return 2 * a3;
}

/* ===== sub_94049254 @ 0x94049254 size 48 ===== */
__int64 __fastcall sub_94049254(_DWORD **a1, __int64 a2, unsigned int a3)
{
  _DWORD *v3; // x0
  __int64 v4; // x3

  if ( a3 == 0 )
    return 0;
  v3 = *a1;
  v4 = 0;
  do
    *(_DWORD *)(a2 + 4 * v4++) = *v3;
  while ( a3 > (unsigned int)v4 );
  return 4 * a3;
}

/* ===== sub_94049284 @ 0x94049284 size 56 ===== */
__int64 __fastcall sub_94049284(__int64 result, int a2)
{
  __int64 v2; // x3
  int v3; // w2
  int v4; // w2

  v2 = **(_QWORD **)(result + 56);
  v3 = *(_DWORD *)(v2 + 8);
  if ( a2 != 0 )
  {
    result = (unsigned int)(1 << (*(_BYTE *)(result + 4) + 8));
    v4 = v3 & ~(_DWORD)result;
  }
  else
  {
    v4 = v3 | 0xF00;
  }
  *(_DWORD *)(v2 + 8) = v4;
  return result;
}

/* ===== sub_940492BC @ 0x940492BC size 324 ===== */
__int64 __fastcall sub_940492BC(__int64 a1, __int64 *a2)
{
  __int64 v2; // x19
  unsigned int v4; // w21
  unsigned int v6; // w22
  __int64 v7; // x1
  __int64 (__fastcall *v8)(__int64, __int64, __int64); // x3
  unsigned int (__fastcall *v9)(__int64); // x2
  __int64 v11; // x1
  __int64 (__fastcall *v12)(__int64, __int64, _QWORD); // x3

  v2 = *(_QWORD *)(a1 + 56);
  v4 = *(_DWORD *)(v2 + 12);
  v6 = 0;
  while ( v4 > 0x1F )
  {
    v7 = *a2;
    v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v2 + 56);
    v4 -= 32;
    *(_DWORD *)(*(_QWORD *)v2 + 88LL) = 32;
    v6 += v8(v2, v7, 32);
    v9 = *(unsigned int (__fastcall **)(__int64))(v2 + 88);
    *a2 += 32;
    if ( v9(a1) != 0 )
      return 0xFFFFFFFFLL;
    if ( *(_DWORD *)(v2 + 40) != 2 )
    {
      (*(void (__fastcall **)(__int64, __int64))(v2 + 48))(v2, a2[1]);
      a2[1] += 32;
    }
  }
  if ( v4 != 0 )
  {
    v11 = *a2;
    v12 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD))(v2 + 56);
    *(_DWORD *)(*(_QWORD *)v2 + 88LL) = v4;
    v6 += v12(v2, v11, v4);
    if ( (*(unsigned int (__fastcall **)(__int64))(v2 + 88))(a1) != 0 )
      return 0xFFFFFFFFLL;
    if ( *(_DWORD *)(v2 + 40) != 2 )
      (*(void (__fastcall **)(__int64, __int64, _QWORD))(v2 + 48))(v2, a2[1], v4);
  }
  *(_DWORD *)(*(_QWORD *)v2 + 12LL) &= 0xFFFFCFFF;
  return v6;
}

/* ===== sub_94049400 @ 0x94049400 size 320 ===== */
__int64 __fastcall sub_94049400(unsigned __int64 a1, __int64 *a2)
{
  int v2; // w2
  __int64 v3; // x3
  _DWORD *v5; // x2
  __int64 v6; // x5
  __int64 v7; // x1
  __int64 v8; // x0
  int v9; // w2
  int v10; // w2

  v2 = *((unsigned __int8 *)a2 + 21);
  v3 = *(_QWORD *)(a1 + 56);
  if ( *((_BYTE *)a2 + 21) == 0 )
    v2 = *(unsigned __int8 *)(a1 + 6);
  switch ( v2 )
  {
    case 16:
      v10 = *((_DWORD *)a2 + 4);
      *(_QWORD *)(v3 + 48) = sub_94049224;
      *(_DWORD *)(v3 + 12) = (unsigned int)(v10 + 1) >> 1;
      *(_QWORD *)(v3 + 56) = sub_94049194;
      break;
    case 32:
      v9 = *((_DWORD *)a2 + 4);
      *(_QWORD *)(v3 + 48) = sub_94049254;
      *(_DWORD *)(v3 + 12) = (unsigned int)(v9 + 3) >> 2;
      *(_QWORD *)(v3 + 56) = sub_940491C4;
      break;
    case 8:
      *(_DWORD *)(v3 + 12) = *((_DWORD *)a2 + 4);
      *(_QWORD *)(v3 + 48) = sub_940491F4;
      *(_QWORD *)(v3 + 56) = sub_94049164;
      break;
    default:
      return 0xFFFFFFFFLL;
  }
  v5 = *(_DWORD **)v3;
  v6 = *a2;
  v7 = a2[1];
  v5[2] = (4 * (*(_BYTE *)(a1 + 6) & 0x1F)) | *(_DWORD *)(*(_QWORD *)v3 + 8LL);
  LODWORD(a1) = v5[3] & 0xFFFFCFFF;
  if ( v6 != 0 )
    LODWORD(a1) = a1 | 0x2000;
  if ( v7 != 0 )
    a1 = (unsigned int)a1 | 0x1000;
  else
    a1 = (unsigned int)a1;
  v5[3] = a1;
  v8 = (a1 >> 12) & 3;
  *(_DWORD *)(v3 + 40) = v8;
  *(_QWORD *)(v3 + 88) = sub_940496C4;
  if ( (_DWORD)v8 == 1 )
  {
    *(_QWORD *)(v3 + 56) = sub_94049130;
    *(_QWORD *)(v3 + 88) = sub_94049110;
  }
  v5[18] = 1;
  v5[18] = 0;
  v5[9] = 256;
  return 0;
}

/* ===== sub_94049540 @ 0x94049540 size 140 ===== */
__int64 __fastcall sub_94049540(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  int v5; // w22

  v3 = *(_QWORD *)(a1 + 56);
  sub_94034308(*(_DWORD *)(a1 + 28));
  (*(void (__fastcall **)(__int64, __int64))(v3 + 64))(a1, a2);
  (*(void (__fastcall **)(__int64, __int64))(v3 + 72))(a1, 1);
  v5 = (*(__int64 (__fastcall **)(__int64, __int64))(v3 + 80))(a1, a2);
  (*(void (__fastcall **)(__int64, _QWORD))(v3 + 72))(a1, 0);
  sub_940343A8(*(_DWORD *)(a1 + 28));
  if ( v5 == *(_DWORD *)(a2 + 16) )
    return 0;
  else
    return 0xFFFFFFFFLL;
}

/* ===== sub_940495CC @ 0x940495CC size 248 ===== */
__int64 __fastcall sub_940495CC(__int64 a1)
{
  __int64 v1; // x19
  int v3; // w0
  bool v4; // zf
  __int64 v5; // x0
  unsigned int v6; // w1
  __int64 v7; // x0
  unsigned int v8; // w3
  __int64 v9; // x2
  _DWORD *v10; // x19

  v1 = *(_QWORD *)(a1 + 56);
  *(_DWORD *)(v1 + 16) = *(_DWORD *)a1;
  *(_QWORD *)(v1 + 32) = 4LL * (*(_BYTE *)(a1 + 6) & 0x1F);
  v3 = *(_BYTE *)(a1 + 5) & 3;
  if ( v3 == 2 )
  {
    *(_QWORD *)(v1 + 24) |= 0x2002uLL;
  }
  else if ( v3 == 3 )
  {
    *(_QWORD *)(v1 + 24) |= 0x2001uLL;
  }
  else
  {
    v4 = v3 == 1;
    v5 = *(_QWORD *)(v1 + 24);
    if ( v4 )
      *(_QWORD *)(v1 + 24) = v5 | 1;
    else
      *(_QWORD *)(v1 + 24) = v5 | 2;
  }
  sub_94034308(*(_DWORD *)(a1 + 28));
  v6 = *(_DWORD *)(v1 + 20);
  v7 = *(_QWORD *)(v1 + 32);
  v8 = 2 * *(_DWORD *)(v1 + 16);
  v9 = *(_QWORD *)(v1 + 24);
  v10 = *(_DWORD **)v1;
  LODWORD(v9) = v7 | v9;
  LODWORD(v7) = *(_DWORD *)(a1 + 28);
  v10[2] = v9 | 0xF00;
  v10[1] = v6 / v8 - 1;
  v10[3] = 0;
  v10[4] = 0;
  v10[6] = 0;
  v10[7] = 0;
  v10[8] = 0;
  v10[18] = 1;
  v10[18] = 0;
  sub_940343A8(v7);
  return 0;
}

/* ===== sub_940496C4 @ 0x940496C4 size 92 ===== */
__int64 __fastcall sub_940496C4(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x1
  int v10; // w0
  __int64 v11; // x2

  v9 = *(__int64 **)(a1 + 56);
  v10 = 16711681;
  v11 = *v9;
  do
  {
    --v10;
    if ( (*(_DWORD *)(v11 + 40) & 0x100) != 0 )
    {
      *(_DWORD *)(v11 + 36) = 256;
      return 0;
    }
  }
  while ( v10 != 0 );
  sub_940407DC(0, "SPI error, spi send timeout = %x!\n", a2, a3, a4, a5, a6, a7, a8, a9);
  return 0xFFFFFFFFLL;
}

/* ===== sub_94049720 @ 0x94049720 size 252 ===== */
__int64 sub_94049720()
{
  unsigned int v0; // w20
  __int64 v1; // x19
  __int64 result; // x0
  __int64 v3; // x5
  __int64 v4; // x4
  __int64 v5; // x1
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  v0 = 0;
  v1 = -536622664;
  do
  {
    result = sub_94040894(0x60u);
    v3 = result;
    v4 = result;
    if ( result != 0 )
    {
      *(_QWORD *)(result + 64) = sub_94049400;
      *(_QWORD *)(result + 72) = sub_94049284;
      *(_QWORD *)(result + 80) = sub_940492BC;
      *(_DWORD *)(result + 20) = *(_DWORD *)(v1 + 16);
      *(_QWORD *)(result + 24) = 0;
      *(_WORD *)(v1 + 26) = 4;
      v5 = *(_QWORD *)(v1 + 8);
      *(_QWORD *)(v1 + 32) = sub_940495CC;
      v6 = *(_QWORD *)v1;
      *(_WORD *)(v1 + 24) = v0;
      *(_QWORD *)(v1 + 40) = sub_94049540;
      *(_QWORD *)(v1 + 48) = v3;
      if ( (unsigned int)sub_940408CC(v6, v5, 0x1000u, 2u, v4) != 0 )
        result = sub_940407DC(2u, "%s: mem map failed %d\n", v7, v8, v9, v10, v11, v12, v13, v14, "sprd_spi_bus_init");
      else
        result = sub_940407DC(2u, "spi%d init ok\n", v7, v8, v9, v10, v11, v12, v13, v14, v0);
    }
    ++v0;
    v1 += 64;
  }
  while ( v0 != 3 );
  return result;
}

/* ===== sub_9404981C @ 0x9404981C size 80 ===== */
bool sub_9404981C()
{
  return (unsigned int)sub_940408CC((__int64)"sprd_timer", 1076035584, 0x10000u, 2u, (__int64)&qword_94077F28) != 0;
}

/* ===== nullsub_7 @ 0x9404986C size 4 ===== */
void nullsub_7()
{
  ;
}

/* ===== nullsub_8 @ 0x94049870 size 4 ===== */
void nullsub_8()
{
  ;
}

/* ===== sub_94049874 @ 0x94049874 size 40 ===== */
unsigned __int64 __fastcall sub_94049874(__int64 a1)
{
  unsigned __int64 v1; // x1
  unsigned __int64 result; // x0

  v1 = (a1 + 7) & 0xFFFFFFFFFFFFFFF8LL;
  result = (MEMORY[0xFFFFFFFFE003CA78] + 7LL) & 0xFFFFFFFFFFFFFFF8LL;
  MEMORY[0xFFFFFFFFE003CA78] = v1 + result;
  return result;
}

/* ===== sub_9404989C @ 0x9404989C size 100 ===== */
__int64 __fastcall sub_9404989C(unsigned __int64 a1)
{
  __int64 v1; // x1
  unsigned __int64 v2; // x3

  v1 = -536622408;
  if ( &qword_9405CAB8 == (__int64 *)-536622408LL )
    return 0;
  while ( 1 )
  {
    v2 = *(_QWORD *)(v1 + 32);
    if ( v2 <= a1 && a1 <= v2 + *(_QWORD *)(v1 + 40) - 1 )
      break;
    v1 = *(_QWORD *)(v1 + 8);
    if ( (__int64 *)v1 == &qword_9405CAB8 )
      return 0;
  }
  return *(_QWORD *)(v1 + 56) + 24 * ((a1 - v2) >> 12);
}

/* ===== sub_94049900 @ 0x94049900 size 844 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_94049900(__int64 a1)
{
  __int64 v1; // x30
  unsigned __int64 v3; // x22
  __int64 v4; // x0
  unsigned int v5; // w2
  unsigned __int64 v6; // x22
  unsigned __int64 v7; // x0
  _QWORD *v8; // x0
  _QWORD *v9; // x1
  __int64 v10; // x4
  _QWORD *v11; // x3
  __int64 v13; // x0
  unsigned int v14; // w1
  __int64 v15; // x2
  unsigned int v16; // w3
  __int64 v17; // x30
  __int64 v18; // x21
  unsigned int v19; // w23
  __int64 v20; // x20
  unsigned __int64 v21; // x19
  unsigned int v22; // w22
  __int64 *v23; // x9
  __int64 v24; // x6
  unsigned __int64 v25; // x1
  unsigned __int64 v26; // x7
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x7
  unsigned __int64 v29; // x3
  __int64 v30; // x5
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x0
  __int64 *v34; // x2
  __int64 v35; // x0

  if ( (*(_QWORD *)(a1 + 32) & 0xFFFLL) != 0 )
  {
    sub_9404B508(
      v1,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/vm/pmm.c",
      83,
      "IS_PAGE_ALIGNED(arena->base)");
    goto LABEL_17;
  }
  v3 = *(_QWORD *)(a1 + 40);
  if ( (v3 & 0xFFF) != 0 )
  {
LABEL_17:
    sub_9404B508(
      v1,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/vm/pmm.c",
      84,
      "IS_PAGE_ALIGNED(arena->size)");
    goto LABEL_18;
  }
  if ( v3 != 0 )
  {
    v4 = -536622408;
    if ( &qword_9405CAB8 != (__int64 *)-536622408LL )
    {
      v5 = *(_DWORD *)(a1 + 28);
      if ( MEMORY[0xFFFFFFFFE003CAD4] > v5 )
      {
LABEL_15:
        *(_QWORD *)a1 = *(_QWORD *)v4;
        *(_QWORD *)(a1 + 8) = v4;
        *(_QWORD *)(*(_QWORD *)v4 + 8LL) = a1;
        *(_QWORD *)v4 = a1;
        goto LABEL_10;
      }
      while ( 1 )
      {
        v4 = *(_QWORD *)(v4 + 8);
        if ( (__int64 *)v4 == &qword_9405CAB8 )
          break;
        if ( v5 < *(_DWORD *)(v4 + 28) )
          goto LABEL_15;
      }
    }
    *(_QWORD *)a1 = -536622408;
    *(_QWORD *)(a1 + 8) = &qword_9405CAB8;
    qword_9405CAB8 = a1;
    MEMORY[0xFFFFFFFFE003CAC0] = a1;
LABEL_10:
    v6 = v3 >> 12;
    *(_QWORD *)(a1 + 48) = 0;
    *(_QWORD *)(a1 + 72) = a1 + 64;
    *(_QWORD *)(a1 + 64) = a1 + 64;
    v7 = sub_94049874(24 * v6);
    *(_QWORD *)(a1 + 56) = v7;
    sub_9404CDC4(v7, 0, 24 * v6);
    if ( v6 != 0 )
    {
      v8 = *(_QWORD **)(a1 + 56);
      v9 = *(_QWORD **)(a1 + 64);
      v10 = *(_QWORD *)(a1 + 48);
      v11 = &v8[3 * v6];
      do
      {
        *v8 = v9;
        v9 = v8;
        v8[1] = a1 + 64;
        *(_QWORD *)(*(_QWORD *)(a1 + 64) + 8LL) = v8;
        *(_QWORD *)(a1 + 64) = v8;
        v8 += 3;
      }
      while ( v8 != v11 );
      *(_QWORD *)(a1 + 48) = v6 + v10;
    }
    return 0;
  }
LABEL_18:
  v13 = sub_9404B508(v1, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/vm/pmm.c", 85, "arena->size > 0");
  v16 = 0;
  v18 = v17;
  if ( v14 != 0 )
  {
    v19 = v14;
    v20 = v15;
    v21 = v13 & 0xFFFFFFFFFFFFF000LL;
    v22 = 0;
    sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
    v23 = &qword_9405CAB8;
    v24 = -536622408;
    if ( &qword_9405CAB8 != (__int64 *)-536622408LL )
    {
      while ( 1 )
      {
        if ( v19 > v22 )
        {
          v25 = *(_QWORD *)(v24 + 32);
          if ( v21 >= v25 )
          {
            v26 = *(_QWORD *)(v24 + 40);
            v27 = v25 + v26 - 1;
            if ( v21 <= v27 )
            {
              v28 = v26 >> 12;
              v29 = (v21 - v25) >> 12;
              if ( v28 > v29 )
              {
                v30 = *(_QWORD *)(v24 + 56);
                goto LABEL_26;
              }
LABEL_32:
              v33 = sub_9404B508(
                      v18,
                      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
                      "external/lk/kernel/vm/pmm.c",
                      179,
                      "index < a->size / PAGE_SIZE");
LABEL_33:
              if ( v34 != nullptr )
              {
                while ( 1 )
                {
                  *v34 = v33;
                  ++v22;
                  v21 += 4096LL;
                  v35 = *(_QWORD *)(v24 + 48) - 1LL;
                  *(_QWORD *)(*(_QWORD *)(v30 + v31) + 8LL) = v34;
                  *(_QWORD *)(v30 + v31) = 0;
                  *(_BYTE *)(v32 + 16) |= 1u;
                  *(_QWORD *)(v30 + v31) = *(_QWORD *)v20;
                  *(_QWORD *)(v32 + 8) = v20;
                  *(_QWORD *)(*(_QWORD *)v20 + 8LL) = v32;
                  *(_QWORD *)v20 = v32;
                  *(_QWORD *)(v24 + 48) = v35;
                  if ( v19 <= v22 || v21 < v25 || v21 > v27 )
                    break;
                  v29 = (v21 - v25) >> 12;
                  if ( v29 >= v28 )
                    goto LABEL_32;
LABEL_26:
                  v31 = 24 * v29;
                  v32 = v30 + v31;
                  if ( (*(_BYTE *)(v30 + v31 + 16) & 1) != 0 )
                    break;
                  v33 = *(_QWORD *)(v30 + v31);
                  v34 = *(__int64 **)(v32 + 8);
                  if ( v33 == 0 )
                    goto LABEL_33;
                }
              }
              else
              {
                sub_9404B508(
                  v18,
                  "DEBUG ASSERT FAILED at (%s:%d): %s\n",
                  "external/lk/kernel/vm/pmm.c",
                  187,
                  "list_in_list(&page->node)");
              }
            }
          }
        }
        if ( v19 != v22 )
        {
          v24 = *(_QWORD *)(v24 + 8);
          if ( (__int64 *)v24 != v23 )
            continue;
        }
        break;
      }
    }
    sub_9402530C((__int64)"xtum");
    return v22;
  }
  return v16;
}

/* ===== sub_94049C4C @ 0x94049C4C size 296 ===== */
__int64 __fastcall sub_94049C4C(__int64 a1)
{
  __int64 v1; // x30
  unsigned int v2; // w21
  __int64 v4; // x19
  unsigned __int64 v5; // x3
  _QWORD *v6; // x0
  char v7; // w6
  __int64 v8; // x0
  unsigned __int64 v9; // x1
  __int64 v10; // x1
  __int64 v12; // x0

  v2 = 0;
  v4 = v1;
  sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
LABEL_2:
  v5 = *(_QWORD *)(a1 + 8);
  if ( a1 == v5 )
  {
LABEL_10:
    sub_9402530C((__int64)"xtum");
    return v2;
  }
  else
  {
    while ( 1 )
    {
      v6 = *(_QWORD **)(v5 + 8);
      *v6 = *(_QWORD *)v5;
      *(_QWORD *)(*(_QWORD *)v5 + 8LL) = v6;
      *(_QWORD *)(v5 + 8) = 0;
      v7 = *(_BYTE *)(v5 + 16);
      *(_QWORD *)v5 = 0;
      if ( (v7 & 1) == 0 )
        break;
      v8 = -536622408;
      if ( &qword_9405CAB8 == (__int64 *)-536622408LL )
        goto LABEL_2;
      while ( 1 )
      {
        v9 = *(_QWORD *)(v8 + 56);
        if ( v9 <= v5 && v5 < 24LL * (*(_QWORD *)(v8 + 40) >> 12) + v9 )
          break;
        v8 = *(_QWORD *)(v8 + 8);
        if ( (__int64 *)v8 == &qword_9405CAB8 )
          goto LABEL_2;
      }
      *(_BYTE *)(v5 + 16) = v7 & 0xFE;
      v10 = *(_QWORD *)(v8 + 48);
      ++v2;
      *(_QWORD *)(v5 + 8) = *(_QWORD *)(v8 + 72);
      *(_QWORD *)v5 = v8 + 64;
      **(_QWORD **)(v8 + 72) = v5;
      *(_QWORD *)(v8 + 72) = v5;
      *(_QWORD *)(v8 + 48) = v10 + 1;
      v5 = *(_QWORD *)(a1 + 8);
      if ( a1 == v5 )
        goto LABEL_10;
    }
    v12 = sub_9404B508(
            v4,
            "DEBUG ASSERT FAILED at (%s:%d): %s\n",
            "external/lk/kernel/vm/pmm.c",
            219,
            "page->flags & VM_PAGE_FLAG_NONFREE");
    return sub_94049D74(v12);
  }
}

/* ===== sub_94049D74 @ 0x94049D74 size 48 ===== */
__int64 __fastcall sub_94049D74(_QWORD *a1)
{
  _QWORD v2[2]; // [xsp+10h] [xbp+10h] BYREF

  a1[1] = v2;
  *a1 = v2;
  v2[0] = a1;
  v2[1] = a1;
  return sub_94049C4C((__int64)v2);
}

/* ===== sub_94049DA4 @ 0x94049DA4 size 688 ===== */
__int64 __fastcall sub_94049DA4(unsigned int a1, unsigned __int8 a2, _QWORD *a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x19
  char v6; // w24
  __int64 *v10; // x0
  __int64 v11; // x2
  __int64 v12; // x9
  int v13; // w13
  __int64 v14; // x12
  int v15; // w10
  unsigned __int64 v16; // x7
  unsigned __int64 v17; // x1
  unsigned __int64 v18; // x3
  unsigned __int64 v19; // x3
  unsigned __int64 v20; // x5
  __int64 v21; // x8
  int v22; // w15
  unsigned int v23; // w14
  __int64 v24; // x11
  int v25; // w16
  __int64 i; // x1
  int v27; // w4
  __int64 v28; // x1
  __int64 v29; // x4
  __int64 v30; // x0
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x0
  char v34; // w3
  _QWORD *v35; // x3

  v5 = v4;
  v6 = a2;
  if ( a1 == 0 )
    return 0;
  if ( a2 <= 0xBu )
    v6 = 12;
  sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
  v10 = &qword_9405CAB8;
  v11 = -536622408;
  if ( &qword_9405CAB8 == (__int64 *)-536622408LL )
  {
LABEL_27:
    sub_9402530C((__int64)"xtum");
    return 0;
  }
  v12 = 1LL << v6;
  v13 = 1LL << (v6 - 12);
  v14 = -(1LL << v6);
  v15 = -(1 << (v6 - 12));
  while ( 1 )
  {
    if ( (*(_DWORD *)(v11 + 24) & 1) != 0 )
    {
      v16 = *(_QWORD *)(v11 + 32);
      v17 = (v16 - 1 + v12) & v14;
      if ( v16 <= v17 )
      {
        v18 = *(_QWORD *)(v11 + 40);
        if ( v17 <= v16 + v18 - 1 )
        {
          v19 = v18 >> 12;
          v20 = (v17 - v16) >> 12;
          v21 = (unsigned int)v20;
          v22 = v20;
          if ( v19 > (unsigned int)v20 )
          {
            v23 = a1 + v20;
            if ( v19 >= a1 + (unsigned int)v20 )
              break;
          }
        }
      }
    }
LABEL_26:
    v11 = *(_QWORD *)(v11 + 8);
    if ( (__int64 *)v11 == v10 )
      goto LABEL_27;
  }
  v24 = *(_QWORD *)(v11 + 56);
  v25 = v13 - v20;
  for ( i = v24 + 24LL * (unsigned int)v20; (*(_BYTE *)(i + 16) & 1) != 0; i = v24 + 24LL * (unsigned int)v20 )
  {
    v27 = 0;
LABEL_29:
    LODWORD(v20) = ((v20 + v25 + v27) & v15) + v22;
    v21 = (unsigned int)v20;
    if ( (unsigned int)v20 >= v19 )
      goto LABEL_26;
    v23 = v20 + a1;
    if ( v19 < (unsigned int)v20 + a1 )
      goto LABEL_26;
  }
  v27 = 0;
  while ( 1 )
  {
    ++v27;
    i += 24;
    if ( v27 == a1 )
      break;
    if ( (*(_BYTE *)(i + 16) & 1) != 0 )
      goto LABEL_29;
  }
  if ( v23 <= (unsigned int)v20 )
    goto LABEL_34;
  v28 = v24 + 24LL * (unsigned int)v20;
  if ( (*(_BYTE *)(v28 + 16) & 1) == 0 )
  {
    v29 = (unsigned int)(v20 + 1);
    v30 = v23 - 1 - (unsigned int)v20 + v29;
    v31 = v24 + 24 * v29;
    v32 = v24 + 24 * v30;
    while ( 1 )
    {
      v35 = *(_QWORD **)(v28 + 8);
      if ( *(_QWORD *)v28 == 0 && v35 == nullptr )
        break;
      *v35 = *(_QWORD *)v28;
      v33 = *(_QWORD *)(v11 + 48) - 1LL;
      *(_QWORD *)(*(_QWORD *)v28 + 8LL) = v35;
      *(_QWORD *)(v28 + 8) = 0;
      v34 = *(_BYTE *)(v28 + 16);
      *(_QWORD *)v28 = 0;
      *(_BYTE *)(v28 + 16) = v34 | 1;
      *(_QWORD *)(v11 + 48) = v33;
      if ( a4 != 0 )
      {
        *(_QWORD *)v28 = *(_QWORD *)a4;
        *(_QWORD *)(v28 + 8) = a4;
        *(_QWORD *)(*(_QWORD *)a4 + 8LL) = v28;
        *(_QWORD *)a4 = v28;
      }
      if ( v31 == v32 )
        goto LABEL_34;
      v28 = v31;
      v31 += 24;
      if ( (*(_BYTE *)(v28 + 16) & 1) != 0 )
        goto LABEL_33;
    }
    v10 = (__int64 *)sub_9404B508(
                       v5,
                       "DEBUG ASSERT FAILED at (%s:%d): %s\n",
                       "external/lk/kernel/vm/pmm.c",
                       318,
                       "list_in_list(&p->node)");
    goto LABEL_26;
  }
LABEL_33:
  sub_9404B508(
    v5,
    "DEBUG ASSERT FAILED at (%s:%d): %s\n",
    "external/lk/kernel/vm/pmm.c",
    317,
    "!(p->flags & VM_PAGE_FLAG_NONFREE)");
LABEL_34:
  if ( a3 != nullptr )
    *a3 = v16 + (v21 << 12);
  sub_9402530C((__int64)"xtum");
  return a1;
}

/* ===== sub_9404A054 @ 0x9404A054 size 56 ===== */
__int64 __fastcall sub_9404A054(unsigned int a1, __int64 a2)
{
  __int64 v3; // [xsp+18h] [xbp+18h] BYREF

  if ( (unsigned int)sub_94049DA4(a1, 0xCu, &v3, a2) != 0 )
    return sub_9404A1F0(v3);
  else
    return 0;
}

/* ===== sub_9404A08C @ 0x9404A08C size 252 ===== */
__int64 __fastcall sub_9404A08C(__int64 result, __int64 a2)
{
  __int64 v2; // x30
  unsigned __int64 v3; // x20
  unsigned __int64 v4; // x21
  __int64 v5; // x25
  unsigned __int64 v6; // x19
  __int64 v7; // x30
  __int64 v8; // [xsp+8h] [xbp-8h]
  int v9; // [xsp+64h] [xbp+54h] BYREF
  __int64 v10; // [xsp+68h] [xbp+58h] BYREF
  _QWORD v11[2]; // [xsp+70h] [xbp+60h] BYREF

  while ( 1 )
  {
    v3 = (a2 + 4095 + (result & 0xFFF)) & 0xFFFFFFFFFFFFF000LL;
    v11[1] = v11;
    v4 = result & 0xFFFFFFFFFFFFF000LL;
    v11[0] = v11;
    if ( v3 == 0 )
      break;
    v5 = v2;
    v6 = 0;
    while ( (sub_94022C68(v6 + v4, &v10, &v9) & 0x80000000) == 0 )
    {
      v6 += 4096LL;
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))loc_94049A9C)(v10, 1, v11);
      if ( v3 <= v6 )
        return result;
    }
    sub_9404B508(v5, (const char *)&loc_94058F00, v4);
    v8 = v7;
    sub_9404A08C(-536870912, 4063232);
    result = MEMORY[0xFFFFFFFFE003CA70];
    if ( MEMORY[0xFFFFFFFFE003CA78] == MEMORY[0xFFFFFFFFE003CA70] )
      break;
    v2 = v8;
    a2 = MEMORY[0xFFFFFFFFE003CA78] - MEMORY[0xFFFFFFFFE003CA70];
  }
  return result;
}

/* ===== sub_9404A188 @ 0x9404A188 size 104 ===== */
__int64 sub_9404A188()
{
  __int64 result; // x0
  __int64 v1; // x19
  __int64 v2; // x1

  sub_9404A274();
  result = -536633344;
  v1 = -536633336;
  if ( MEMORY[0xFFFFFFFFE003A010] != 0 )
  {
    do
    {
      while ( 1 )
      {
        result = *(unsigned int *)(v1 + 16);
        if ( (result & 1) == 0 )
          break;
        v1 += 40;
        if ( *(_QWORD *)(v1 + 8) == 0 )
          return result;
      }
      v2 = *(_QWORD *)(v1 + 24);
      v1 += 40;
      result = ((__int64 (__fastcall *)(__int64, __int64))loc_9404A720)(-536460256, v2);
    }
    while ( *(_QWORD *)(v1 + 8) != 0 );
  }
  return result;
}

/* ===== sub_9404A1F0 @ 0x9404A1F0 size 88 ===== */
__int64 __fastcall sub_9404A1F0(unsigned __int64 a1)
{
  __int64 v1; // x1
  __int64 v2; // x2
  unsigned __int64 v3; // x2

  v1 = -536633344;
  v2 = MEMORY[0xFFFFFFFFE003A010];
  if ( MEMORY[0xFFFFFFFFE003A010] == 0 )
    return 0;
  while ( 1 )
  {
    if ( (*(_DWORD *)(v1 + 24) & 1) == 0 )
    {
      v3 = *(_QWORD *)v1 - 1LL + v2;
      if ( *(_QWORD *)v1 <= a1 && a1 <= v3 )
        break;
    }
    v1 += 40;
    v2 = *(_QWORD *)(v1 + 16);
    if ( v2 == 0 )
      return 0;
  }
  return a1 + *(_QWORD *)(v1 + 8) - *(_QWORD *)v1;
}

/* ===== sub_9404A248 @ 0x9404A248 size 44 ===== */
__int64 __fastcall sub_9404A248(unsigned __int64 a1)
{
  int v1; // w0
  __int64 v2; // x1
  __int64 v4; // [xsp+18h] [xbp+18h] BYREF

  v1 = sub_94022C68(a1, &v4, nullptr);
  v2 = 0;
  if ( v1 == 0 )
    return v4;
  return v2;
}

/* ===== sub_9404A274 @ 0x9404A274 size 108 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 *sub_9404A274()
{
  sub_9404CF6C(-536460240, "kernel", 32);
  MEMORY[0xFFFFFFFFE0064458] = -536870912;
  MEMORY[0xFFFFFFFFE0064420] = &qword_9405CAC8;
  MEMORY[0xFFFFFFFFE0064470] = -536460184;
  MEMORY[0xFFFFFFFFE0064460] = 0x20000000;
  MEMORY[0xFFFFFFFFE0064468] = -536460184;
  MEMORY[0xFFFFFFFFE0064428] = -536622392;
  MEMORY[0xFFFFFFFFE003CAC8] = -536460256;
  off_9405CAD0 = (_UNKNOWN *)-536460256LL;
  return &qword_9405CAC8;
}

/* ===== sub_9404A2E0 @ 0x9404A2E0 size 20 ===== */
__int64 __fastcall sub_9404A2E0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  return -a5 & (a1 - 1 + a5);
}

/* ===== sub_9404A2F4 @ 0x9404A2F4 size 1412 ===== */
__int64 __fastcall sub_9404A2F4(
        __int64 *a1,
        __int64 a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        unsigned __int8 a5,
        char a6,
        int a7,
        int a8)
{
  __int64 v8; // x19
  __int64 v9; // x30
  __int64 v10; // x24
  unsigned int v14; // w21
  __int64 v18; // x0
  __int64 v19; // x26
  _QWORD *v20; // x28
  __int64 i; // x21
  unsigned __int64 v22; // x27
  __int64 v23; // x1
  __int64 v24; // x3
  unsigned __int64 v25; // x23
  unsigned __int64 v26; // x0
  __int64 result; // x0
  __int64 *v28; // x1
  unsigned __int64 v29; // x1
  unsigned __int64 v30; // x0
  unsigned __int64 v31; // x22
  __int64 *v32; // x0
  unsigned __int64 v33; // x21
  __int64 *v34; // x1
  __int64 v35; // x2
  __int64 v36; // x27
  __int64 v37; // x0
  unsigned __int64 v38; // x27
  __int64 v39; // x1
  unsigned __int64 v40; // x23
  __int64 v41; // x3
  unsigned __int64 v42; // x0
  __int64 *v43; // x1
  __int64 v44; // x23
  unsigned __int64 v45; // x23
  __int64 v46; // x0
  char *v47; // x1
  __int64 v48; // x2
  unsigned __int64 v49; // x3
  __int64 v50; // x30
  char *v51; // x20
  __int64 v52; // x21
  __int64 v53; // x19
  unsigned __int64 v54; // x1
  __int64 v55; // x4
  __int64 v56; // x2
  unsigned __int64 v57; // x0
  __int64 v58; // x2
  __int64 v59; // x19
  __int64 v60; // x0
  __int64 v61; // x1
  __int64 v62; // x2
  __int64 v63; // x3
  __int64 v64; // x4
  __int64 v65; // x5
  __int64 v66; // x6
  __int64 v67; // x7
  __int64 v68; // [xsp+8h] [xbp-48h]
  __int64 v69; // [xsp+10h] [xbp-40h]
  __int64 *v70; // [xsp+18h] [xbp-38h]
  unsigned __int64 v71; // [xsp+38h] [xbp-18h]
  unsigned int v72; // [xsp+4Ch] [xbp-4h] BYREF
  __int64 v73; // [xsp+50h] [xbp+0h] BYREF
  __int64 v74; // [xsp+B8h] [xbp+68h]

  v10 = v9;
  v14 = a5;
  if ( a2 == 0 )
  {
    sub_9404B508(v9, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/vm/vmm.c", 105, "name");
LABEL_54:
    v32 = (__int64 *)sub_9404B508(
                       v10,
                       "DEBUG ASSERT FAILED at (%s:%d): %s\n",
                       "external/lk/kernel/vm/vmm.c",
                       230,
                       "size > 0 && IS_PAGE_ALIGNED(size)");
    goto LABEL_55;
  }
  v74 = a2;
  v18 = sub_9404CBC4(88);
  v8 = v18;
  if ( v18 == 0 )
    return 0;
  sub_9404CF6C(v18 + 16, v74, 32);
  *(_QWORD *)(v8 + 56) = a4;
  *(_QWORD *)(v8 + 64) = a3;
  *(_DWORD *)(v8 + 48) = a7;
  *(_DWORD *)(v8 + 52) = a8;
  *(_QWORD *)(v8 + 80) = v8 + 72;
  *(_QWORD *)(v8 + 72) = v8 + 72;
  if ( (a6 & 1) != 0 )
  {
    if ( a1 != nullptr )
    {
      if ( a3 == 0 )
        goto LABEL_44;
      v29 = a1[7];
      if ( a4 < v29 )
        goto LABEL_44;
      v30 = v29 + a1[8] - 1;
      if ( a4 > v30 )
        goto LABEL_44;
      v31 = a3 - 1 + a4;
      if ( a4 > v31 || v30 < v31 )
        goto LABEL_44;
      a1 += 9;
      v32 = (__int64 *)a1[1];
      if ( a1 != v32 && v32 != nullptr )
      {
        v33 = v32[7];
        if ( v33 <= v31 )
        {
          if ( a1 != v32 )
          {
            while ( 1 )
            {
              if ( a4 > v32[8] - 1 + v33 )
              {
                v34 = (__int64 *)v32[1];
                if ( a1 == v34 || v34 == nullptr || v34[7] > v31 )
                {
                  *(_QWORD *)(v8 + 8) = v34;
                  *(_QWORD *)v8 = v32;
                  *(_QWORD *)v32[1] = v8;
                  v32[1] = v8;
                  return v8;
                }
              }
              v32 = (__int64 *)v32[1];
              if ( a1 == v32 )
                break;
              v33 = v32[7];
            }
          }
          goto LABEL_44;
        }
      }
LABEL_55:
      *(_QWORD *)(v8 + 8) = v32;
      *(_QWORD *)v8 = a1;
      *v32 = v8;
      a1[1] = v8;
      return v8;
    }
    goto LABEL_59;
  }
  if ( a1 == nullptr )
  {
    sub_9404B508(v10, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/vm/vmm.c", 229, "aspace");
LABEL_59:
    sub_9404B508(v10, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/vm/vmm.c", 125, "aspace");
    return 0;
  }
  if ( a3 == 0 || (a3 & 0xFFF) != 0 )
    goto LABEL_54;
  v19 = 4096;
  if ( v14 > 0xB )
    v19 = 1LL << v14;
  v20 = a1 + 9;
  i = a1[10];
  if ( a1 + 9 == (__int64 *)i || i == 0 )
  {
    v22 = a1[7];
    v45 = v22 + a1[8];
    if ( v22 == v45 )
      goto LABEL_44;
    v25 = v45 - 1;
    v24 = 128;
  }
  else
  {
    v22 = a1[7];
    v23 = *(_QWORD *)(i + 56);
    if ( v22 == v23 )
      goto LABEL_38;
    v24 = *(unsigned int *)(i + 52);
    v25 = v23 - 1;
  }
  v26 = sub_9404A2E0(v22, 128, v25, v24, v19);
  if ( v26 < v22 )
  {
LABEL_44:
    sub_9404CC20(v8);
    return 0;
  }
  if ( v25 > v26 && a3 <= v25 + 1 - v26 )
  {
    if ( v26 != -1 )
    {
      *(_QWORD *)(v8 + 8) = a1[10];
      *(_QWORD *)(v8 + 56) = v26;
      v28 = (__int64 *)a1[10];
      *(_QWORD *)v8 = v20;
      *v28 = v8;
      a1[10] = v8;
      return v8;
    }
    goto LABEL_44;
  }
  for ( i = a1[10]; ; i = *(_QWORD *)(i + 8) )
  {
    while ( 1 )
    {
LABEL_38:
      if ( v20 == (_QWORD *)i )
        goto LABEL_44;
      v35 = *(_QWORD *)(i + 8);
      v36 = *(_QWORD *)(i + 64);
      if ( v20 == (_QWORD *)v35 || v35 == 0 )
        break;
      v37 = *(_QWORD *)(v35 + 56);
      v38 = v36 + *(_QWORD *)(i + 56);
      if ( v38 != v37 )
      {
        v39 = *(unsigned int *)(i + 52);
        v40 = v37 - 1;
        v41 = *(unsigned int *)(v35 + 52);
        goto LABEL_43;
      }
      i = *(_QWORD *)(i + 8);
    }
    v38 = v36 + *(_QWORD *)(i + 56);
    v44 = a1[8] + a1[7];
    if ( v44 == v38 )
      goto LABEL_44;
    v39 = *(unsigned int *)(i + 52);
    v40 = v44 - 1;
    v41 = 128;
LABEL_43:
    v42 = sub_9404A2E0(v38, v39, v40, v41, v19);
    if ( v38 > v42 )
      goto LABEL_44;
    if ( v40 > v42 && a3 <= v40 + 1 - v42 )
      break;
  }
  if ( v42 == -1 )
    goto LABEL_44;
  if ( i != 0 )
  {
    *(_QWORD *)(v8 + 8) = *(_QWORD *)(i + 8);
    *(_QWORD *)(v8 + 56) = v42;
    v43 = *(__int64 **)(i + 8);
    *(_QWORD *)v8 = i;
    *v43 = v8;
    *(_QWORD *)(i + 8) = v8;
    return v8;
  }
  v46 = sub_9404B508(v10, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/vm/vmm.c", 295, "before != NULL");
  v68 = v50;
  v69 = v8;
  v70 = a1;
  v51 = v47;
  v52 = v46;
  v53 = v48;
  if ( (v49 & 0xFFF) != 0 )
  {
    sub_9404B508(
      v50,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/vm/vmm.c",
      311,
      "IS_PAGE_ALIGNED(vaddr)");
  }
  else if ( (v48 & 0xFFF) == 0 )
  {
    if ( v47 == nullptr )
    {
      v51 = "";
      if ( v48 != 0 )
        goto LABEL_65;
      return 0;
    }
    if ( v48 == 0 )
      return 0;
LABEL_65:
    v54 = *(_QWORD *)(v46 + 56);
    result = 4294967259LL;
    if ( v49 >= v54 )
    {
      v55 = *(_QWORD *)(v52 + 64);
      if ( v49 <= v54 + v55 - 1 )
      {
        v56 = v49 - v54;
        v57 = v49 - v54 + v53;
        if ( v49 - v54 > v57 )
        {
          v57 = -2;
          v53 = -2 - v56;
        }
        v58 = v55 - v56;
        if ( v55 - 1 <= v57 )
          v53 = v58;
        v71 = v49;
        sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
        v72 = 0;
        sub_94022C68(v71, nullptr, (int *)&v72);
        v59 = sub_9404A2F4(v52, v51, v53, v71, 0, 1, 1, v72, &v73, v68, v69, v70, 0, a3);
        sub_9402530C((__int64)"xtum");
        if ( v59 == 0 )
          return 4294967291LL;
        return 0;
      }
    }
    return result;
  }
  v60 = sub_9404B508(
          v50,
          "DEBUG ASSERT FAILED at (%s:%d): %s\n",
          "external/lk/kernel/vm/vmm.c",
          312,
          "IS_PAGE_ALIGNED(size)");
  return sub_9404A878(v60, v61, v62, v63, v64, v65, v66, v67);
}

/* ===== sub_9404A878 @ 0x9404A878 size 396 ===== */
__int64 __fastcall sub_9404A878(
        __int64 *a1,
        char *a2,
        unsigned __int64 a3,
        __int64 *a4,
        unsigned __int8 a5,
        __int64 a6,
        char a7,
        int a8)
{
  __int64 v8; // x30
  char *v11; // x20
  __int64 result; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x1
  unsigned int v20; // w21
  unsigned __int64 v21; // [xsp+50h] [xbp+50h]

  v11 = a2;
  if ( (a6 & 0xFFF) != 0 )
  {
    sub_9404B508(
      v8,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      "external/lk/kernel/vm/vmm.c",
      351,
      "IS_PAGE_ALIGNED(paddr)");
  }
  else if ( (a3 & 0xFFF) == 0 )
  {
    if ( a2 == nullptr )
      v11 = "";
    result = 0;
    if ( a3 != 0 )
    {
      if ( (a7 & 1) == 0 )
      {
        sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
        v17 = sub_9404A2F4(a1, (__int64)v11, a3, 0, a5, a7, 2, a8);
        if ( v17 != 0 )
        {
          if ( a4 == nullptr )
          {
            v18 = *(_QWORD *)(v17 + 56);
            goto LABEL_10;
          }
LABEL_9:
          v18 = *(_QWORD *)(v17 + 56);
          *a4 = v18;
LABEL_10:
          v19 = a6;
          v20 = 0;
          sub_94023290(v18, v19, a3 >> 12, a8);
LABEL_11:
          sub_9402530C((__int64)"xtum");
          return v20;
        }
LABEL_16:
        v20 = -5;
        goto LABEL_11;
      }
      if ( a4 != nullptr )
      {
        v21 = *a4;
        sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
        v17 = sub_9404A2F4(a1, (__int64)v11, a3, v21, a5, a7, 2, a8);
        if ( v17 != 0 )
          goto LABEL_9;
        goto LABEL_16;
      }
      return 4294967288LL;
    }
    return result;
  }
  sub_9404B508(v8, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/vm/vmm.c", 352, "IS_PAGE_ALIGNED(size)");
  return 4294967288LL;
}

/* ===== sub_9404AA04 @ 0x9404AA04 size 472 ===== */
__int64 __fastcall sub_9404AA04(
        __int64 *a1,
        char *a2,
        __int64 a3,
        unsigned __int64 *a4,
        unsigned __int8 a5,
        char a6,
        int a7)
{
  unsigned __int64 v7; // x19
  char *v9; // x28
  unsigned __int64 v13; // x27
  unsigned __int64 v14; // x22
  __int64 v16; // x0
  __int64 v17; // x19
  __int64 v18; // x0
  __int64 *v19; // x0
  __int64 v20; // x1
  __int64 *v21; // x2
  __int64 v23; // [xsp+78h] [xbp+78h] BYREF
  __int64 v24; // [xsp+80h] [xbp+80h] BYREF
  __int64 *v25; // [xsp+88h] [xbp+88h]

  v7 = (a3 + 4095) & 0xFFFFFFFFFFFFF000LL;
  v9 = a2;
  if ( v7 != 0 )
  {
    if ( a2 == nullptr )
      v9 = "";
    if ( (a6 & 1) == 0 )
    {
      v13 = 0;
      goto LABEL_7;
    }
    if ( a4 != nullptr )
    {
      v13 = *a4;
LABEL_7:
      v14 = v7 >> 12;
      v23 = 0;
      v25 = &v24;
      v24 = (__int64)&v24;
      if ( v7 >> 12 > (unsigned int)sub_94049DA4(v7 >> 12, a5, &v23, (__int64)&v24) )
        return 4294967291LL;
      sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
      v16 = sub_9404A2F4(a1, (__int64)v9, v7, v13, a5, a6, 2, a7);
      v17 = v16;
      if ( v16 == 0 )
      {
        sub_9402530C((__int64)"xtum");
        sub_94049C4C((__int64)&v24);
        return 4294967291LL;
      }
      v18 = *(_QWORD *)(v16 + 56);
      if ( a4 != nullptr )
        *a4 = v18;
      sub_94023290(v18, v23, v14, a7);
      v19 = v25;
      if ( v25 != &v24 )
      {
        v20 = v17 + 72;
        do
        {
          v21 = (__int64 *)v19[1];
          *v21 = *v19;
          *(_QWORD *)(*v19 + 8) = v21;
          *v19 = 0;
          *v19 = *(_QWORD *)v20;
          v19[1] = v20;
          *(_QWORD *)(*(_QWORD *)v20 + 8LL) = v19;
          *(_QWORD *)v20 = v19;
          v19 = v25;
        }
        while ( v25 != &v24 );
      }
      sub_9402530C((__int64)"xtum");
      return 0;
    }
  }
  return 4294967288LL;
}

/* ===== sub_9404ABDC @ 0x9404ABDC size 256 ===== */
__int64 __fastcall sub_9404ABDC(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x30
  __int64 v5; // x19
  _QWORD *v6; // x19
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x1
  _QWORD *v10; // x2
  __int64 v11; // x0

  v5 = v2;
  sub_940251F8((__int64)"xtum", 0xFFFFFFFFLL);
  if ( a1 != 0 )
  {
    v6 = *(_QWORD **)(a1 + 80);
    if ( v6 == (_QWORD *)(a1 + 72) )
    {
LABEL_6:
      sub_9402530C((__int64)"xtum");
      return 4294967294LL;
    }
    else
    {
      while ( 1 )
      {
        v7 = v6[7];
        if ( a2 >= v7 )
        {
          v8 = v6[8];
          if ( a2 <= v7 + v8 - 1 )
            break;
        }
        v6 = (_QWORD *)v6[1];
        if ( (_QWORD *)(a1 + 72) == v6 )
          goto LABEL_6;
      }
      v10 = (_QWORD *)v6[1];
      *v10 = *v6;
      *(_QWORD *)(*v6 + 8LL) = v10;
      v6[1] = 0;
      *v6 = 0;
      sub_94023364(v7, v8 >> 12);
      sub_9402530C((__int64)"xtum");
      sub_94049C4C((__int64)(v6 + 9));
      sub_9404CC20(v6);
      return 0;
    }
  }
  else
  {
    v11 = sub_9404B508(v5, "DEBUG ASSERT FAILED at (%s:%d): %s\n", "external/lk/kernel/vm/vmm.c", 559, "aspace");
    return sub_9404ACDC(v11);
  }
}

/* ===== sub_9404ACDC @ 0x9404ACDC size 124 ===== */
bool sub_9404ACDC()
{
  return &qword_9405CB88 == (__int64 *)-536622200LL;
}

/* ===== sub_9404AD58 @ 0x9404AD58 size 36 ===== */
__int64 sub_9404AD58()
{
  __int64 result; // x0
  unsigned __int8 v1; // [xsp+1Fh] [xbp+1Fh] BYREF

  result = sub_94022058(&v1, 1);
  if ( (result & 0x80000000) == 0 )
    return v1;
  return result;
}

/* ===== sub_9404AD7C @ 0x9404AD7C size 412 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_9404AD7C(unsigned __int8 *a1, unsigned __int64 a2)
{
  unsigned __int8 *v2; // x19
  __int64 result; // x0
  unsigned __int8 *v5; // x20
  unsigned int v6; // t1
  unsigned __int8 *v7; // x21
  unsigned int v8; // t1
  __int64 v9; // x20
  __int64 v10; // x20

  v2 = a1;
  if ( MEMORY[0xFFFFFFFFE0057F30] != 0 )
  {
    result = MEMORY[0xFFFFFFFFE0059F48];
    if ( MEMORY[0xFFFFFFFFE0059F48] != 0 )
    {
      v5 = &v2[a2];
      if ( a2 != 0 )
      {
        do
        {
          v6 = *v2++;
          result = sub_94022000(v6);
        }
        while ( v2 != v5 );
      }
    }
    else
    {
      v9 = -536622200;
      if ( &qword_9405CB88 != (__int64 *)-536622200LL )
      {
        do
        {
          result = (*(__int64 (__fastcall **)(__int64, unsigned __int8 *, unsigned __int64))(v9 + 16))(v9, v2, a2);
          v9 = *(_QWORD *)(v9 + 8);
        }
        while ( (__int64 *)v9 != &qword_9405CB88 );
      }
    }
  }
  else
  {
    v10 = 0x2000;
    if ( a2 < 0x2000 )
      v10 = a2;
    sub_9404CC78(qword_94077F48, a1, v10);
    dword_94077F40 = v10;
    result = MEMORY[0xFFFFFFFFE0059F48];
    if ( MEMORY[0xFFFFFFFFE0059F48] != 0 && a2 != 0 )
    {
      v7 = &v2[a2];
      do
      {
        v8 = *v2++;
        result = sub_94022000(v8);
      }
      while ( v2 != v7 );
    }
  }
  return result;
}

/* ===== sub_9404AF18 @ 0x9404AF18 size 52 ===== */
__int64 __fastcall sub_9404AF18(unsigned __int8 *a1, __int64 a2)
{
  unsigned __int64 v3; // x0
  unsigned int v4; // w19

  v3 = sub_9404D0A0(a1, a2);
  v4 = v3;
  sub_9404AD7C(a1, v3);
  return v4;
}

/* ===== sub_9404AF4C @ 0x9404AF4C size 200 ===== */
// write access to const memory has been detected, the output may be wrong!
unsigned __int64 *__fastcall sub_9404AF4C(__int64 a1)
{
  char v2; // w20
  unsigned __int64 *result; // x0

  v2 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v2 = 1;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) != 0 )
  {
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    *(_QWORD *)(a1 + 8) = -536622200;
    *(_QWORD *)a1 = &qword_9405CB88;
    MEMORY[0xFFFFFFFFE003CB88] = a1;
    off_9405CB90 = (_UNKNOWN *)a1;
    result = sub_940223D4((unsigned __int64 *)&qword_94077F38);
  }
  else
  {
    v2 |= 2u;
    __asm { MSR             DAIFSet, #1 }
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    *(_QWORD *)(a1 + 8) = -536622200;
    *(_QWORD *)a1 = &qword_9405CB88;
    MEMORY[0xFFFFFFFFE003CB88] = a1;
    off_9405CB90 = (_UNKNOWN *)a1;
    result = sub_940223D4((unsigned __int64 *)&qword_94077F38);
    __asm { MSR             DAIFClr, #1 }
  }
  if ( (v2 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  return result;
}

/* ===== sub_9404B014 @ 0x9404B014 size 192 ===== */
unsigned __int64 *__fastcall sub_9404B014(_QWORD *a1)
{
  char v2; // w20
  _QWORD *v9; // x1
  unsigned __int64 *result; // x0
  _QWORD *v13; // x1

  v2 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v2 = 1;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) != 0 )
  {
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    v13 = (_QWORD *)a1[1];
    *v13 = *a1;
    *(_QWORD *)(*a1 + 8LL) = v13;
    a1[1] = 0;
    *a1 = 0;
    result = sub_940223D4((unsigned __int64 *)&qword_94077F38);
  }
  else
  {
    v2 |= 2u;
    __asm { MSR             DAIFSet, #1 }
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    v9 = (_QWORD *)a1[1];
    *v9 = *a1;
    *(_QWORD *)(*a1 + 8LL) = v9;
    a1[1] = 0;
    *a1 = 0;
    result = sub_940223D4((unsigned __int64 *)&qword_94077F38);
    __asm { MSR             DAIFClr, #1 }
  }
  if ( (v2 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  return result;
}

/* ===== sub_9404B0D4 @ 0x9404B0D4 size 168 ===== */
unsigned __int64 *__fastcall sub_9404B0D4(unsigned __int8 a1)
{
  char v2; // w19
  unsigned __int64 *result; // x0
  unsigned __int8 v12; // [xsp+3Fh] [xbp+3Fh] BYREF

  v2 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v2 = 1;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) != 0 )
  {
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    v12 = a1;
    sub_9404AD7C(&v12, 1u);
    result = sub_940223D4((unsigned __int64 *)&qword_94077F38);
  }
  else
  {
    v2 |= 2u;
    __asm { MSR             DAIFSet, #1 }
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    v12 = a1;
    sub_9404AD7C(&v12, 1u);
    result = sub_940223D4((unsigned __int64 *)&qword_94077F38);
    __asm { MSR             DAIFClr, #1 }
  }
  if ( (v2 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  return result;
}

/* ===== sub_9404B17C @ 0x9404B17C size 28 ===== */
__int64 __fastcall sub_9404B17C(__int64 a1, unsigned __int8 a2)
{
  sub_9404B0D4(a2);
  return 0;
}

/* ===== sub_9404B198 @ 0x9404B198 size 180 ===== */
__int64 __fastcall sub_9404B198(unsigned __int8 *a1)
{
  char v2; // w19
  unsigned __int64 v9; // x0
  unsigned __int64 v13; // x0

  v2 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v2 = 1;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) != 0 )
  {
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    v13 = sub_9404CFF4(a1);
    sub_9404AD7C(a1, v13);
    sub_940223D4((unsigned __int64 *)&qword_94077F38);
  }
  else
  {
    v2 |= 2u;
    __asm { MSR             DAIFSet, #1 }
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    v9 = sub_9404CFF4(a1);
    sub_9404AD7C(a1, v9);
    sub_940223D4((unsigned __int64 *)&qword_94077F38);
    __asm { MSR             DAIFClr, #1 }
  }
  if ( (v2 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  return 0;
}

/* ===== sub_9404B24C @ 0x9404B24C size 8 ===== */
__int64 __fastcall sub_9404B24C(__int64 a1, unsigned __int8 *a2)
{
  return sub_9404B198(a2);
}

/* ===== sub_9404B254 @ 0x9404B254 size 168 ===== */
__int64 __fastcall sub_9404B254(unsigned __int8 *a1, unsigned __int64 a2)
{
  char v3; // w19

  v3 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v3 = 1;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) != 0 )
  {
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    sub_9404AD7C(a1, a2);
    sub_940223D4((unsigned __int64 *)&qword_94077F38);
  }
  else
  {
    v3 |= 2u;
    __asm { MSR             DAIFSet, #1 }
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    sub_9404AD7C(a1, a2);
    sub_940223D4((unsigned __int64 *)&qword_94077F38);
    __asm { MSR             DAIFClr, #1 }
  }
  if ( (v3 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  return 0;
}

/* ===== sub_9404B2FC @ 0x9404B2FC size 288 ===== */
__int64 sub_9404B2FC(
        const char *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        ...)
{
  char v10; // w19
  unsigned int v17; // w21
  va_list va1; // [xsp+30h] [xbp+30h] BYREF
  va_list va; // [xsp+50h] [xbp+50h] BYREF

  va_start(va, a9);
  v10 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v10 = 1;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) != 0 )
  {
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    va_copy(va1, va);
    v17 = sub_9404BF38(sub_9404AF18, 0, a1, va1);
    sub_940223D4((unsigned __int64 *)&qword_94077F38);
  }
  else
  {
    v10 |= 2u;
    __asm { MSR             DAIFSet, #1 }
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    va_copy(va1, va);
    v17 = sub_9404BF38(sub_9404AF18, 0, a1, va1);
    sub_940223D4((unsigned __int64 *)&qword_94077F38);
    __asm { MSR             DAIFClr, #1 }
  }
  if ( (v10 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  return v17;
}

/* ===== sub_9404B41C @ 0x9404B41C size 236 ===== */
__int64 __fastcall sub_9404B41C(__int64 a1, _QWORD *a2)
{
  char v3; // w19
  __int64 v10; // x7
  __int64 v11; // x4
  __int64 v12; // x5
  unsigned int v13; // w20
  __int64 v17; // x7
  __int64 v18; // x4
  __int64 v19; // x5
  _QWORD v21[2]; // [xsp+40h] [xbp+40h] BYREF
  __int64 v22; // [xsp+50h] [xbp+50h]
  __int64 v23; // [xsp+58h] [xbp+58h]

  v3 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    __asm { MSR             DAIFSet, #2 }
    v3 = 1;
  }
  if ( (_ReadStatusReg(DAIF) & 0x40) != 0 )
  {
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    v17 = a2[1];
    v18 = a2[2];
    v19 = a2[3];
    v21[0] = *a2;
    v21[1] = v17;
    v22 = v18;
    v23 = v19;
    v13 = sub_9404BF38(sub_9404AF18, 0, a1, v21);
    sub_940223D4((unsigned __int64 *)&qword_94077F38);
  }
  else
  {
    v3 |= 2u;
    __asm { MSR             DAIFSet, #1 }
    sub_940223B4((unsigned __int64 *)&qword_94077F38);
    v10 = a2[1];
    v11 = a2[2];
    v12 = a2[3];
    v21[0] = *a2;
    v21[1] = v10;
    v22 = v11;
    v23 = v12;
    v13 = sub_9404BF38(sub_9404AF18, 0, a1, v21);
    sub_940223D4((unsigned __int64 *)&qword_94077F38);
    __asm { MSR             DAIFClr, #1 }
  }
  if ( (v3 & 1) != 0 )
    __asm { MSR             DAIFClr, #2 }
  return v13;
}

/* ===== sub_9404B508 @ 0x9404B508 size 188 ===== */
__int64 sub_9404B508(
        __int64 a1,
        const char *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        ...)
{
  __int64 *v11; // x2
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x2
  __int64 v15; // x3
  _QWORD *v16; // t2
  __int64 v17; // x1
  _QWORD v19[4]; // [xsp+10h] [xbp-20h] BYREF
  va_list va; // [xsp+50h] [xbp+20h] BYREF
  va_list va1; // [xsp+70h] [xbp+40h] BYREF

  if ( (MEMORY[0xFFFFFFFFE003CB98] & 0x8000000000000000LL) == 0 )
    sub_9404B2FC("panic (caller %p): ", a3, a4, a5, a6, a7, a8, a9, a10, a1);
  va_start(va1, a10);
  va_start(va, a10);
  sub_9404B41C((__int64)a2, va);
  sub_94028A08(0, 9);
  v12 = *v11;
  v13 = v11[1];
  v16 = v11 + 2;
  v14 = v11[2];
  v15 = v16[1];
  v19[0] = v12;
  v19[1] = v13;
  v19[2] = v14;
  v19[3] = v15;
  return sub_9404B41C(v17, v19);
}

/* ===== sub_9404B5C4 @ 0x9404B5C4 size 420 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_9404B5C4(unsigned __int64 a1)
{
  __int64 v1; // x30
  unsigned __int64 v2; // x19
  __int64 v3; // x23
  __int64 v4; // x22
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x3
  unsigned __int64 *v14; // x0
  unsigned __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x1
  _QWORD *v18; // x2
  _QWORD *v19; // x3
  unsigned __int64 *v21; // x4
  __int64 v22; // x0

  v2 = a1;
  v3 = v1;
  v4 = *(_QWORD *)(a1 + 16);
  sub_940251F8((__int64)qword_94079FA0, 0xFFFFFFFFLL);
  v13 = *(_QWORD *)(v2 + 16);
  v14 = nullptr;
  qword_94079F90 = v13;
  if ( &off_94079FD8 == nullptr )
  {
LABEL_13:
    *(_QWORD *)v2 = 0;
    *(_QWORD *)(v2 + 8) = &off_94079FD8;
    MEMORY[8] = v2;
    off_94079FD8 = (_UNKNOWN *)v2;
    v15 = *(_QWORD *)v2;
    if ( *(_UNKNOWN ***)v2 != &off_94079FD8 && v15 != 0 )
    {
      v16 = *(_QWORD *)(v15 + 16);
      if ( v2 == v15 + v16 )
      {
LABEL_16:
        v21 = *(unsigned __int64 **)(v2 + 8);
        *(_QWORD *)(v15 + 16) = v13 + v16;
        *v21 = v15;
        *(_QWORD *)(*(_QWORD *)v2 + 8LL) = v21;
        *(_QWORD *)(v2 + 8) = 0;
        *(_QWORD *)v2 = 0;
        v2 = v15;
      }
    }
LABEL_9:
    if ( v14 == nullptr )
    {
LABEL_12:
      sub_9402530C((__int64)qword_94079FA0);
      return v2;
    }
LABEL_10:
    v17 = *(_QWORD *)(v2 + 16);
    if ( v14 == (unsigned __int64 *)(v2 + v17) )
    {
      v18 = (_QWORD *)v14[1];
      v19 = (_QWORD *)*v14;
      *(_QWORD *)(v2 + 16) = v14[2] + v17;
      *v18 = v19;
      *(_QWORD *)(*v14 + 8) = v18;
      v14[1] = 0;
      *v14 = 0;
    }
    goto LABEL_12;
  }
  while ( v2 >= (unsigned __int64)v14 )
  {
    v14 = (unsigned __int64 *)v14[1];
    if ( v14 == (unsigned __int64 *)&off_94079FD8 )
      goto LABEL_13;
  }
  if ( (unsigned __int64)v14 >= v2 + v4 )
  {
    *(_QWORD *)v2 = *v14;
    *(_QWORD *)(v2 + 8) = v14;
    *(_QWORD *)(*v14 + 8) = v2;
    *v14 = v2;
    v15 = *(_QWORD *)v2;
    if ( *(_UNKNOWN ***)v2 == &off_94079FD8 || v15 == 0 )
      goto LABEL_10;
    v16 = *(_QWORD *)(v15 + 16);
    if ( v2 == v15 + v16 )
      goto LABEL_16;
    goto LABEL_9;
  }
  v22 = sub_9404B508(
          v3,
          "DEBUG ASSERT FAILED at (%s:%d): %s\n",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "external/lk/lib/heap/heap.c",
          212,
          "chunk_end <= (vaddr_t)next_chunk");
  return sub_9404B768(v22);
}

/* ===== sub_9404B768 @ 0x9404B768 size 44 ===== */
__int64 __fastcall sub_9404B768(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  __int64 v8; // x30
  __int64 v9; // x0

  v9 = sub_9404B508(
         v8,
         "DEBUG ASSERT FAILED at (%s:%d): %s\n",
         a1,
         a2,
         a3,
         a4,
         a5,
         a6,
         a7,
         a8,
         "external/lk/lib/heap/heap.c",
         258,
         "(len % sizeof(void *)) == 0");
  return sub_9404B794(v9);
}

/* ===== sub_9404B794 @ 0x9404B794 size 316 ===== */
__int64 sub_9404B794()
{
  int v5; // w21
  __int64 v6; // x2
  __int64 result; // x0
  __int64 *i; // x1
  __int64 *v10; // x2
  __int64 v12; // [xsp+40h] [xbp+40h] BYREF
  __int64 *v13; // [xsp+48h] [xbp+48h]

  v13 = &v12;
  v12 = (__int64)&v12;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    v5 = 0;
    sub_940223B4((unsigned __int64 *)&qword_94079FF8);
    if ( &qword_94079FE8 == nullptr )
    {
      result = (__int64)sub_940223D4((unsigned __int64 *)&qword_94079FF8);
      goto LABEL_7;
    }
  }
  else
  {
    __asm { MSR             DAIFSet, #2 }
    sub_940223B4((unsigned __int64 *)&qword_94079FF8);
    if ( &qword_94079FE8 == nullptr )
    {
      result = (__int64)sub_940223D4((unsigned __int64 *)&qword_94079FF8);
      __asm { MSR             DAIFClr, #2 }
      goto LABEL_7;
    }
    v5 = 1;
  }
  do
  {
    v6 = MEMORY[8];
    *MEMORY[8] = MEMORY[0];
    *(_QWORD *)(MEMORY[0] + 8LL) = v6;
    MEMORY[8] = v13;
    MEMORY[0] = &v12;
    *v13 = 0;
    v13 = nullptr;
  }
  while ( &qword_94079FE8 != nullptr );
  result = (__int64)sub_940223D4((unsigned __int64 *)&qword_94079FF8);
  if ( v5 != 0 )
    __asm { MSR             DAIFClr, #2 }
LABEL_7:
  for ( i = v13; v13 != &v12; i = v13 )
  {
    v10 = (__int64 *)i[1];
    *v10 = *i;
    *(_QWORD *)(*i + 8) = v10;
    i[1] = 0;
    *i = 0;
    result = sub_9404B5C4((unsigned __int64)i);
  }
  return result;
}

/* ===== sub_9404B8D0 @ 0x9404B8D0 size 768 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_9404B8D0(__int64 a1, unsigned int a2)
{
  __int64 v2; // x30
  __int64 v3; // x27
  __int64 v4; // x23
  unsigned __int64 v5; // x19
  unsigned __int64 v6; // x20
  int v7; // w24
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x1
  unsigned __int64 v17; // x0
  __int64 v18; // x0
  unsigned __int64 v19; // x0
  unsigned __int64 v20; // x24
  __int64 v21; // x24
  _UNKNOWN **v23; // x2
  __int64 *v24; // x5
  _UNKNOWN **v25; // x6
  _UNKNOWN **v26; // x4
  unsigned __int64 v27; // x20
  __int64 v28; // x19
  unsigned __int64 v29; // x0
  _QWORD *v30; // x2
  __int64 v31; // [xsp+68h] [xbp+68h]

  v3 = a2;
  v4 = v2;
  if ( &qword_94079FE8 != nullptr )
  {
    v31 = a1;
    sub_9404B794();
    a1 = v31;
  }
  if ( (((_DWORD)v3 - 1) & (unsigned int)v3) != 0 )
    return 0;
  v5 = 24;
  if ( (unsigned __int64)(a1 + 24) > 0x17 )
  {
    v5 = (a1 + 31) & 0xFFFFFFFFFFFFFFF8LL;
    if ( (_DWORD)v3 == 0 )
      goto LABEL_6;
  }
  else if ( (_DWORD)v3 == 0 )
  {
    goto LABEL_6;
  }
LABEL_14:
  v18 = (unsigned int)v3;
  if ( (unsigned int)v3 <= 0xF )
  {
    v18 = 16;
    v3 = 16;
  }
  v5 += v18;
LABEL_6:
  v6 = 0x2000;
  v7 = 0;
  if ( ((v5 + 4095) & 0xFFFFFFFFFFFFF000LL) >= 0x2000 )
    v6 = (v5 + 4095) & 0xFFFFFFFFFFFFF000LL;
  while ( 1 )
  {
    sub_940251F8((__int64)qword_94079FA0, 0xFFFFFFFFLL);
    v16 = 0;
    if ( &off_94079FD8 != nullptr )
      break;
LABEL_19:
    sub_9402530C((__int64)qword_94079FA0);
    if ( v7 != 0 )
      return 0;
    v19 = sub_9404A054(v6 >> 12, 0);
    v20 = v19;
    if ( v19 == 0 )
      goto LABEL_39;
    *(_QWORD *)(v19 + 16) = v6;
    sub_9404B5C4(v19);
    v21 = v20 + v6;
    if ( v21 != 0 )
      qword_94079F88 = v21;
    v7 = 1;
    if ( (v6 & 0x8000000000000000LL) != 0 )
      return 0;
  }
  while ( 1 )
  {
    v17 = *(_QWORD *)(v16 + 16);
    if ( (v17 & 7) != 0 )
    {
      sub_9404B508(
        v4,
        "DEBUG ASSERT FAILED at (%s:%d): %s\n",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "external/lk/lib/heap/heap.c",
        344,
        "(chunk->len % sizeof(void *)) == 0");
      goto LABEL_14;
    }
    if ( v5 <= v17 )
      break;
    v16 = *(_QWORD *)(v16 + 8);
    if ( (_UNKNOWN **)v16 == &off_94079FD8 )
      goto LABEL_19;
  }
  v23 = *(_UNKNOWN ***)(v16 + 8);
  v24 = &qword_94079F80;
  v25 = &off_94079FD8;
  *v23 = *(_UNKNOWN **)v16;
  if ( v23 == &off_94079FD8 )
    v26 = nullptr;
  else
    v26 = v23;
  *(_QWORD *)(*(_QWORD *)v16 + 8LL) = v23;
  *(_QWORD *)(v16 + 8) = 0;
  *(_QWORD *)v16 = 0;
  if ( v5 + 24 < v17 )
  {
    v29 = v17 - v5;
    v30 = (_QWORD *)(v16 + v5);
    if ( (v29 & 7) != 0 )
    {
      sub_9404B768(v8, v9, v10, v11, v12, v13, v14, v15);
LABEL_39:
      sub_9404CB4C("%s:%d: failed to grow kernel heap by 0x%zx bytes\n", "heap_grow", 518, v6);
      return 0;
    }
    v30[2] = v29;
    *(_QWORD *)(v16 + 16) = v5;
    if ( v26 != nullptr )
    {
      v27 = v5;
      *v30 = *v26;
      v30[1] = v26;
      *((_QWORD *)*v26 + 1) = v30;
      *v26 = v30;
      goto LABEL_30;
    }
LABEL_37:
    v27 = v5;
    *v30 = v24[11];
    v30[1] = v25;
    *(_QWORD *)(v24[11] + 8) = v30;
    v24[11] = (__int64)v30;
    goto LABEL_30;
  }
  v27 = *(_QWORD *)(v16 + 16);
  if ( v5 > v27 )
  {
    sub_9404B508(
      v4,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "external/lk/lib/heap/heap.c",
      369,
      "chunk->len >= size");
    goto LABEL_37;
  }
LABEL_30:
  v28 = v16 + 24;
  if ( (_DWORD)v3 != 0 )
    v28 = (v3 - 1 + v28) & -v3;
  *(_DWORD *)(v28 - 24) = 1212498256;
  *(_QWORD *)(v28 - 16) = v16;
  *(_QWORD *)(v28 - 8) = v27;
  qword_94079F90 = -(__int64)v27;
  sub_9402530C((__int64)qword_94079FA0);
  return v28;
}

/* ===== sub_9404BBD0 @ 0x9404BBD0 size 108 ===== */
__int64 __fastcall sub_9404BBD0(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x30
  __int64 v10; // x1
  unsigned __int64 v11; // x0
  __int64 v12; // x0

  if ( result != 0 )
  {
    if ( *(_DWORD *)(result - 24) == 1212498256 )
    {
      v10 = *(_QWORD *)(result - 8);
      v11 = *(_QWORD *)(result - 16);
      if ( (v10 & 7) == 0 )
      {
        *(_QWORD *)(v11 + 16) = v10;
        return sub_9404B5C4(v11);
      }
    }
    else
    {
      sub_9404B508(
        v9,
        "DEBUG ASSERT FAILED at (%s:%d): %s\n",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "external/lk/lib/heap/heap.c",
        438,
        "as->magic == HEAP_MAGIC");
    }
    v12 = sub_9404B768(a2, a3, a4, a5, a6, a7, a8, a9);
    return sub_9404BC3C(v12);
  }
  return result;
}

/* ===== sub_9404BC3C @ 0x9404BC3C size 252 ===== */
// write access to const memory has been detected, the output may be wrong!
unsigned __int64 *__fastcall sub_9404BC3C(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x30
  __int64 v10; // x1
  __int64 v11; // x19
  unsigned __int64 *result; // x0
  __int64 v19; // x0

  if ( *(_DWORD *)(a1 - 24) != 1212498256 )
  {
    sub_9404B508(
      v9,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "external/lk/lib/heap/heap.c",
      469,
      "as->magic == HEAP_MAGIC");
    goto LABEL_7;
  }
  v10 = *(_QWORD *)(a1 - 8);
  v11 = *(_QWORD *)(a1 - 16);
  if ( (v10 & 7) != 0 )
  {
LABEL_7:
    v19 = sub_9404B768(a2, a3, a4, a5, a6, a7, a8, a9);
    return (unsigned __int64 *)sub_9404BD38(v19);
  }
  *(_QWORD *)(v11 + 16) = v10;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    sub_940223B4((unsigned __int64 *)&qword_94079FF8);
    *(_QWORD *)(v11 + 8) = 0;
    *(_QWORD *)v11 = &qword_94079FE8;
    MEMORY[0] = v11;
    off_94079FF0 = (_UNKNOWN *)v11;
    return sub_940223D4((unsigned __int64 *)&qword_94079FF8);
  }
  else
  {
    __asm { MSR             DAIFSet, #2 }
    sub_940223B4((unsigned __int64 *)&qword_94079FF8);
    *(_QWORD *)(v11 + 8) = 0;
    *(_QWORD *)v11 = &qword_94079FE8;
    MEMORY[0] = v11;
    off_94079FF0 = (_UNKNOWN *)v11;
    result = sub_940223D4((unsigned __int64 *)&qword_94079FF8);
    __asm { MSR             DAIFClr, #2 }
  }
  return result;
}

/* ===== sub_9404BD38 @ 0x9404BD38 size 228 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_9404BD38()
{
  __int64 v0; // x30
  __int64 v1; // x21
  unsigned __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _BYTE *v12; // x0
  __int64 v13; // x1
  _QWORD *v14; // x2
  __int64 v15; // x3
  unsigned __int64 v16; // x4

  v1 = v0;
  sub_940251C4((__int64)qword_94079FA0);
  qword_94079FF8 = 0;
  off_94079FF0 = &qword_94079FE8;
  qword_94079FE8 = (__int64)&qword_94079FE8;
  qword_94079FE0 = (__int64)&off_94079FD8;
  off_94079FD8 = &off_94079FD8;
  v2 = sub_9404A054(2u, 0);
  qword_94079F80 = v2;
  qword_94079F88 = 0x2000;
  if ( v2 != 0 )
  {
    qword_94079F90 = 0;
    qword_94079F98 = 0x2000;
    *(_QWORD *)(v2 + 16) = 0x2000;
    return sub_9404B5C4(v2);
  }
  else
  {
    v12 = (_BYTE *)sub_9404B508(v1, "HEAP: error allocating initial heap size\n", v3, v4, v5, v6, v7, v8, v9, v10);
    if ( v13 != 0 && *v12 != 0 )
    {
      v15 = 0;
      do
      {
        v16 = v14[2];
        if ( v16 < v14[1] )
        {
          v14[2] = v16 + 1;
          *(_BYTE *)(*v14 + v16) = v12[v15];
        }
        ++v15;
      }
      while ( v15 != v13 && v12[v15] != 0 );
      return (unsigned int)v15;
    }
    else
    {
      return 0;
    }
  }
}

/* ===== sub_9404BE1C @ 0x9404BE1C size 224 ===== */
_BYTE *__fastcall sub_9404BE1C(__int64 a1, unsigned __int64 a2, __int16 a3, _BYTE *a4)
{
  int v4; // w9
  __int64 v5; // x5
  unsigned __int64 v6; // kr00_8
  int v7; // w4
  _BYTE *v8; // x4

  if ( (a3 & 0x400) != 0 && (a2 & 0x8000000000000000LL) != 0 )
  {
    a2 = -(__int64)a2;
    *(_BYTE *)(a1 + 31) = 0;
    if ( a2 <= 9 )
    {
      v8 = (_BYTE *)(a1 + 30);
      *(_BYTE *)(a1 + 30) = a2 + 48;
LABEL_12:
      *a4 = 45;
      return v8;
    }
    v4 = 1;
  }
  else
  {
    *(_BYTE *)(a1 + 31) = 0;
    v4 = 0;
    if ( a2 <= 9 )
    {
      *(_BYTE *)(a1 + 30) = a2 + 48;
      v8 = (_BYTE *)(a1 + 30);
      if ( (a3 & 0x200) == 0 )
        goto LABEL_8;
LABEL_13:
      *a4 = 43;
      return v8;
    }
  }
  v5 = 31;
  do
  {
    v6 = a2;
    --v5;
    v7 = a2 % 0xA;
    a2 /= 0xAu;
    *(_BYTE *)(a1 + v5) = v7 + 48;
  }
  while ( v6 / 0xA > 9 );
  v8 = (_BYTE *)(a1 + v5 - 1);
  *v8 = a2 + 48;
  if ( v4 != 0 )
    goto LABEL_12;
  if ( (a3 & 0x200) != 0 )
    goto LABEL_13;
LABEL_8:
  if ( (a3 & 0x2000) != 0 )
    *a4 = 32;
  else
    *a4 = 0;
  return v8;
}

/* ===== sub_9404BEFC @ 0x9404BEFC size 60 ===== */
_BYTE *__fastcall sub_9404BEFC(__int64 a1, unsigned __int64 a2, __int16 a3)
{
  char *v3; // x4
  _BYTE *v4; // x3
  __int64 v5; // x2
  _BYTE *result; // x0

  if ( (a3 & 0x100) != 0 )
    v3 = "0123456789ABCDEF%p invalid syscall %d requested\n";
  else
    v3 = "0123456789abcdef0123456789ABCDEF%p invalid syscall %d requested\n";
  *(_BYTE *)(a1 + 31) = 0;
  v4 = (_BYTE *)(a1 + 30);
  do
  {
    v5 = a2 & 0xF;
    result = v4;
    a2 >>= 4;
    *v4-- = v3[v5];
  }
  while ( a2 != 0 );
  return result;
}

/* ===== sub_9404BF38 @ 0x9404BF38 size 2832 ===== */
__int64 __fastcall sub_9404BF38(
        __int64 (__fastcall *a1)(unsigned __int8 *, __int64, __int64),
        __int64 a2,
        unsigned __int8 *a3)
{
  unsigned __int8 *v5; // x28
  __int64 v6; // x19
  int v7; // w0
  unsigned __int8 *v8; // x24
  int v9; // w0
  int v10; // t1
  __int64 result; // x0
  __int64 v12; // x1
  unsigned __int8 *v13; // x24
  int v14; // w28
  int v15; // t1
  unsigned int v16; // w20
  _BYTE v17[7]; // [xsp+A8h] [xbp+A8h] BYREF
  char v18; // [xsp+AFh] [xbp+AFh]

  v5 = a3;
  v6 = 0;
  v7 = *a3;
  v8 = a3 + 1;
  v18 = 0;
  if ( v7 != 0 )
  {
    while ( v7 == 37 )
    {
      v12 = 0;
LABEL_10:
      result = a1(v5, v12, a2);
      if ( (result & 0x80000000) != 0 )
        return result;
      v6 += (int)result;
      v15 = *v8;
      v13 = v8 + 1;
      v14 = v15;
      if ( v15 == 0 )
        return (unsigned int)v6;
      if ( (unsigned int)(v14 - 32) <= 0x5A )
        __asm { BR              X0; switch jump }
      v17[0] = 37;
      v16 = a1(v17, 1, a2);
      if ( (v16 & 0x80000000) != 0 )
        return v16;
      v17[0] = v14;
      result = a1(v17, 1, a2);
      if ( (result & 0x80000000) != 0 )
        return result;
      v5 = v13;
      v6 += (int)v16 + (__int64)(int)result;
      v18 = 0;
      v8 = v13 + 1;
      v7 = *v5;
      if ( *v5 == 0 )
        goto LABEL_16;
    }
    while ( 1 )
    {
      v12 = v8 - v5;
      v10 = *v8++;
      v9 = v10;
      if ( v10 == 0 )
        break;
      if ( v9 == 37 )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_16:
    v12 = 0;
  }
  result = a1(v5, v12, a2);
  if ( (result & 0x80000000) == 0 )
  {
    LODWORD(v6) = v6 + result;
    return (unsigned int)v6;
  }
  return result;
}

/* ===== sub_9404CA48 @ 0x9404CA48 size 120 ===== */
__int64 __fastcall sub_9404CA48(__int64 a1, unsigned __int64 a2, unsigned __int8 *a3)
{
  __int64 result; // x0
  _QWORD v6[2]; // [xsp+48h] [xbp+48h] BYREF
  unsigned __int64 v7; // [xsp+58h] [xbp+58h]

  v6[0] = a1;
  v6[1] = a2;
  v7 = 0;
  result = sub_9404BF38((__int64 (__fastcall *)(unsigned __int8 *, __int64, __int64))&loc_9404BDC0, (__int64)v6, a3);
  if ( a2 <= v7 )
    *(_BYTE *)(a1 + a2 - 1) = 0;
  else
    *(_BYTE *)(a1 + (int)result) = 0;
  return result;
}

/* ===== sub_9404CAC0 @ 0x9404CAC0 size 92 ===== */
__int64 __fastcall sub_9404CAC0(
        __int64 a1,
        unsigned __int64 a2,
        char *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  return sub_9404CA48(a1, a2, (unsigned __int8 *)a3);
}

/* ===== sub_9404CB1C @ 0x9404CB1C size 48 ===== */
__int64 __fastcall sub_9404CB1C(__int64 *a1, __int64 a2, _QWORD *a3)
{
  __int64 v3; // x7
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 (__fastcall *v6)(__int64, __int64, _QWORD *); // x3
  __int64 v7; // x0
  _QWORD v9[4]; // [xsp+10h] [xbp+10h] BYREF

  v3 = a3[1];
  v4 = a3[2];
  v5 = a3[3];
  v9[0] = *a3;
  v9[1] = v3;
  v6 = (__int64 (__fastcall *)(__int64, __int64, _QWORD *))a1[4];
  v7 = *a1;
  v9[2] = v4;
  v9[3] = v5;
  return v6(v7, a2, v9);
}

/* ===== sub_9404CB4C @ 0x9404CB4C size 120 ===== */
__int64 sub_9404CB4C(
        const char *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        ...)
{
  va_list va; // [xsp+10h] [xbp+10h] BYREF
  va_list va1; // [xsp+30h] [xbp+30h] BYREF

  va_start(va, a9);
  va_start(va1, a9);
  return sub_9404CB1C((__int64 *)0xFFFFFFFFE003CB38LL, (__int64)a1, va);
}

/* ===== sub_9404CBC4 @ 0x9404CBC4 size 8 ===== */
__int64 __fastcall sub_9404CBC4(__int64 a1)
{
  return sub_9404B8D0(a1, 0);
}

/* ===== sub_9404CBCC @ 0x9404CBCC size 16 ===== */
__int64 __fastcall sub_9404CBCC(unsigned int a1, __int64 a2)
{
  return sub_9404B8D0(a2, a1);
}

/* ===== sub_9404CBDC @ 0x9404CBDC size 68 ===== */
__int64 __fastcall sub_9404CBDC(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v5; // [xsp+28h] [xbp+28h]

  v5 = a1 * a2;
  v2 = sub_9404B8D0(a1 * a2, 0);
  v3 = v2;
  if ( v2 != 0 )
    sub_9404CDC4(v2, 0, v5);
  return v3;
}

/* ===== sub_9404CC20 @ 0x9404CC20 size 4 ===== */
// attributes: thunk
__int64 __fastcall sub_9404CC20(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  return sub_9404BBD0(result, a2, a3, a4, a5, a6, a7, a8, a9);
}

/* ===== sub_9404CC24 @ 0x9404CC24 size 84 ===== */
__int64 __fastcall sub_9404CC24(_BYTE *a1, _BYTE *a2, __int64 a3)
{
  char *v3; // x4
  char *v4; // x2
  char v5; // t1
  __int64 result; // x0

  if ( a3 != 0 )
  {
    if ( *a1 != *a2 )
      return (unsigned int)(char)(*a1 - *a2);
    v3 = a1 + 1;
    v4 = &a1[a3];
    while ( 1 )
    {
      ++a2;
      if ( v3 == v4 )
        break;
      v5 = *v3++;
      result = (unsigned int)(char)(v5 - *a2);
      if ( v5 != *a2 )
        return result;
    }
  }
  return 0;
}

/* ===== sub_9404CC78 @ 0x9404CC78 size 332 ===== */
_BYTE *__fastcall sub_9404CC78(_BYTE *result, _BYTE *a2, unsigned __int64 a3)
{
  _BYTE *v3; // x5
  __int64 v4; // x3
  __int64 v5; // x7
  __int64 v6; // x7
  int v7; // w2
  int v8; // w6
  bool v9; // cc
  __int64 v10; // x3
  __int64 v11; // x6
  __int64 v12; // x6

  if ( result == a2 || a3 == 0 )
    return result;
  v3 = result;
  if ( (((unsigned __int8)result | (unsigned __int8)a2) & 7) != 0 )
  {
    if ( (((unsigned __int8)result ^ (unsigned __int8)a2) & 7) != 0 || a3 <= 7 )
    {
      v8 = a3;
      v3 = result;
      v9 = (int)a3 <= 0;
      a3 -= (int)a3;
      if ( v9 )
        goto LABEL_4;
    }
    else
    {
      v8 = 8 - ((unsigned __int8)result & 7);
      a3 -= v8;
    }
    v10 = 0;
    v11 = (unsigned int)(v8 - 1);
    do
    {
      result[v10] = a2[v10];
      ++v10;
    }
    while ( v10 != v11 + 1 );
    v12 = (int)v11 + 1LL;
    v3 = &result[v12];
    a2 += v12;
  }
LABEL_4:
  if ( (int)(a3 >> 3) > 0 )
  {
    v4 = 0;
    v5 = (unsigned int)(a3 >> 3) - 1;
    do
    {
      *(_QWORD *)&v3[v4] = *(_QWORD *)&a2[v4];
      v4 += 8;
    }
    while ( v4 != 8 * (v5 + 1) );
    v6 = 8 * ((int)v5 + 1LL);
    v3 += v6;
    a2 += v6;
  }
  v7 = a3 & 7;
  if ( v7 != 0 )
  {
    *v3 = *a2;
    if ( v7 != 1 )
    {
      v3[1] = a2[1];
      if ( v7 != 2 )
      {
        v3[2] = a2[2];
        if ( v7 != 3 )
        {
          v3[3] = a2[3];
          if ( v7 != 4 )
          {
            v3[4] = a2[4];
            if ( v7 != 5 )
            {
              v3[5] = a2[5];
              if ( v7 != 6 )
                v3[6] = a2[6];
            }
          }
        }
      }
    }
  }
  return result;
}

/* ===== sub_9404CDC4 @ 0x9404CDC4 size 276 ===== */
__int64 __fastcall sub_9404CDC4(__int64 result, unsigned __int8 a2, unsigned __int64 a3)
{
  unsigned __int64 *v3; // x4
  unsigned __int64 v4; // x3
  unsigned __int64 v5; // x2
  unsigned __int64 v6; // x5
  unsigned __int64 v7; // x5
  unsigned __int64 *v8; // x3

  v3 = (unsigned __int64 *)result;
  v4 = -result & 7;
  if ( v4 < a3 )
  {
    v5 = a3 - v4;
    v6 = a2 | ((unsigned __int64)a2 << 8) | ((a2 | ((unsigned __int64)a2 << 8)) << 16);
    v7 = v6 | (v6 << 32);
    if ( v4 != 0 )
    {
      *(_BYTE *)result = a2;
      if ( v4 != 1 )
      {
        *(_BYTE *)(result + 1) = a2;
        if ( v4 != 2 )
        {
          *(_BYTE *)(result + 2) = a2;
          if ( v4 != 3 )
          {
            *(_BYTE *)(result + 3) = a2;
            if ( v4 != 4 )
            {
              *(_BYTE *)(result + 4) = a2;
              if ( v4 != 5 )
              {
                *(_BYTE *)(result + 5) = a2;
                if ( v4 != 6 )
                  *(_BYTE *)(result + 6) = a2;
              }
            }
          }
        }
      }
      v8 = (unsigned __int64 *)(result + v4);
    }
    else
    {
      v8 = (unsigned __int64 *)result;
    }
    if ( v5 >> 3 != 0 )
    {
      v3 = &v8[v5 >> 3];
      do
        *v8++ = v7;
      while ( v8 != v3 );
      a3 = v5 & 7;
    }
    else
    {
      v3 = v8;
      a3 = v5 & 7;
    }
  }
  if ( a3 != 0 )
  {
    *(_BYTE *)v3 = a2;
    if ( a3 != 1 )
    {
      *((_BYTE *)v3 + 1) = a2;
      if ( a3 != 2 )
      {
        *((_BYTE *)v3 + 2) = a2;
        if ( a3 != 3 )
        {
          *((_BYTE *)v3 + 3) = a2;
          if ( a3 != 4 )
          {
            *((_BYTE *)v3 + 4) = a2;
            if ( a3 != 5 )
            {
              *((_BYTE *)v3 + 5) = a2;
              if ( a3 != 6 )
                *((_BYTE *)v3 + 6) = a2;
            }
          }
        }
      }
    }
  }
  return result;
}

/* ===== sub_9404CED8 @ 0x9404CED8 size 52 ===== */
__int64 __fastcall sub_9404CED8(__int64 a1, __int64 a2)
{
  __int64 v2; // x3
  int v3; // w4
  char v4; // w2
  unsigned int v5; // w2

  v2 = 0;
  do
  {
    v3 = *(unsigned __int8 *)(a1 + v2);
    v4 = *(_BYTE *)(a2 + v2++);
    v5 = (char)(v3 - v4);
    if ( v5 != 0 )
      return v5;
  }
  while ( v3 != 0 );
  return 0;
}

/* ===== sub_9404CF0C @ 0x9404CF0C size 24 ===== */
__int64 __fastcall sub_9404CF0C(__int64 result, __int64 a2)
{
  __int64 v2; // x2
  int v3; // w3

  v2 = 0;
  do
  {
    v3 = *(unsigned __int8 *)(a2 + v2);
    *(_BYTE *)(result + v2++) = v3;
  }
  while ( v3 != 0 );
  return result;
}

/* ===== sub_9404CF24 @ 0x9404CF24 size 72 ===== */
_BYTE *__fastcall sub_9404CF24(_BYTE *a1)
{
  _BYTE *v1; // x0
  _BYTE *v2; // x19
  __int64 v5; // [xsp+28h] [xbp+28h]

  v5 = sub_9404CFF4(a1) + 1;
  v1 = (_BYTE *)sub_9404CBC4(v5);
  v2 = v1;
  if ( v1 != nullptr )
    sub_9404CC78(v1, a1, v5);
  return v2;
}

/* ===== sub_9404CF6C @ 0x9404CF6C size 136 ===== */
__int64 __fastcall sub_9404CF6C(__int64 a1, _BYTE *a2, __int64 a3)
{
  __int64 v3; // x2
  __int64 v4; // x19
  _BYTE *v5; // x5
  unsigned __int8 *v6; // x3
  char v7; // w4
  int v8; // t1

  if ( a3 == 0 )
    return sub_9404CFF4(a2);
  v3 = a3 - 1;
  if ( v3 != 0 )
  {
    v4 = 0;
    v5 = a2;
    v6 = a2 + 1;
    v7 = *a2;
    if ( *a2 != 0 )
    {
      while ( 1 )
      {
        *(_BYTE *)(a1 + v4++) = v7;
        v5 = v6;
        if ( v4 == v3 )
          break;
        v8 = *v6++;
        v7 = v8;
        if ( v8 == 0 )
          goto LABEL_8;
      }
      v5 = &a2[v4];
    }
  }
  else
  {
    v5 = a2;
    v4 = 0;
  }
LABEL_8:
  *(_BYTE *)(a1 + v4) = 0;
  return sub_9404CFF4(v5) + v4;
}

/* ===== sub_9404CFF4 @ 0x9404CFF4 size 40 ===== */
__int64 __fastcall sub_9404CFF4(_BYTE *a1)
{
  __int64 result; // x0

  if ( *a1 == 0 )
    return 0;
  result = 0;
  do
    ++result;
  while ( a1[result] != 0 );
  return result;
}

/* ===== sub_9404D01C @ 0x9404D01C size 36 ===== */
__int64 __fastcall sub_9404D01C(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x3
  int v4; // w4

  v3 = 0;
  do
  {
    if ( v3 == a3 )
      break;
    v4 = *(unsigned __int8 *)(a2 + v3);
    *(_BYTE *)(result + v3++) = v4;
  }
  while ( v4 != 0 );
  return result;
}

/* ===== sub_9404D040 @ 0x9404D040 size 96 ===== */
__int64 __fastcall sub_9404D040(_BYTE *a1, _BYTE *a2, __int64 a3)
{
  char *v3; // x5
  unsigned __int8 *v4; // x4
  char *v5; // x2
  int v6; // w3
  char v7; // t1
  __int64 result; // x0

  if ( a3 != 0 )
  {
    v3 = a2 + 1;
    if ( *a1 != *a2 )
      return (unsigned int)(char)(*a1 - *a2);
    v4 = a1 + 1;
    if ( *a1 != 0 )
    {
      v5 = &a2[a3];
      do
      {
        if ( v3 == v5 )
          break;
        v6 = *v4++;
        v7 = *v3++;
        result = (unsigned int)(char)(v6 - v7);
        if ( (_BYTE)v6 != v7 )
          return result;
      }
      while ( v6 != 0 );
    }
  }
  return 0;
}

/* ===== sub_9404D0A0 @ 0x9404D0A0 size 68 ===== */
__int64 __fastcall sub_9404D0A0(_BYTE *a1, __int64 a2)
{
  unsigned __int8 *v2; // x2
  unsigned __int8 *v3; // x1
  int v4; // t1
  unsigned __int8 *v5; // x4

  if ( a2 == 0 || *a1 == 0 )
    return 0;
  v2 = a1 + 1;
  v3 = &a1[a2];
  do
  {
    v5 = v2;
    if ( v2 == v3 )
      return v2 - a1;
    v4 = *v2++;
  }
  while ( v4 != 0 );
  return v5 - a1;
}

/* ===== sub_9404D0E4 @ 0x9404D0E4 size 160 ===== */
_BYTE *__fastcall sub_9404D0E4(_BYTE *a1, _BYTE *a2)
{
  int v4; // w21
  _BYTE *result; // x0
  int v6; // w19

  v4 = sub_9404CFF4(a2);
  result = a1;
  if ( v4 != 0 )
  {
    v6 = sub_9404CFF4(a1);
    if ( v4 > v6 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        --v6;
        if ( (unsigned int)sub_9404CC24(a1, a2, v4) == 0 )
          break;
        ++a1;
        if ( v4 > v6 )
          return nullptr;
      }
      return a1;
    }
  }
  return result;
}

/* ===== sub_9404D188 @ 0x9404D188 size 72 ===== */
__int64 __fastcall sub_9404D188(__int64 a1)
{
  unsigned __int64 v1; // x12
  __int64 v7; // x14
  __int64 result; // x0

  v1 = *(unsigned int *)(a1 + 96);
  __asm { MSR             DAIFClr, #7 }
  if ( v1 >= MEMORY[0xFFFFFFFFE003CBA0] || (v7 = *(_QWORD *)(8 * v1 - 536622168)) == 0 )
    v7 = -536686104;
  result = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD))v7)(
             *(_QWORD *)a1,
             *(_QWORD *)(a1 + 8),
             *(_QWORD *)(a1 + 16),
             *(_QWORD *)(a1 + 24));
  __asm { MSR             DAIFSet, #7 }
  *(_QWORD *)a1 = result;
  return result;
}

/* ===== sub_9404D224 @ 0x9404D224 size 32 ===== */
__int64 __fastcall sub_9404D224(__int64 a1, unsigned __int8 *a2, unsigned __int64 a3)
{
  int v4; // t1

  if ( a3 != 0 )
  {
    do
    {
      v4 = *a2++;
      _W9 = v4;
      __asm { STTRB           W9, [X0] }
      ++a1;
    }
    while ( a3-- > 1 );
  }
  return 0;
}

/* ===== sub_9404D244 @ 0x9404D244 size 32 ===== */
__int64 __fastcall sub_9404D244(_BYTE *a1, __int64 _X1, unsigned __int64 a3)
{
  if ( a3 == 0 )
    JUMPOUT(0x9404D23CLL);
  do
  {
    __asm { LDTRB           W9, [X1] }
    ++_X1;
    *a1++ = _X9;
  }
  while ( a3-- > 1 );
  return 0;
}

/* ===== sub_9404D264 @ 0x9404D264 size 44 ===== */
__int64 __fastcall sub_9404D264(_BYTE *a1, __int64 _X1, __int64 a3)
{
  __int64 v3; // x10
  char v10; // w11

  v3 = _X1;
  do
  {
    __asm { LDTRB           W9, [X1] }
    if ( (_DWORD)_X9 != 0 )
      ++_X1;
    if ( a3 != 0 )
    {
      if ( a3-- != 1 )
        v10 = _X9;
      else
        v10 = 0;
      *a1++ = v10;
    }
  }
  while ( (_DWORD)_X9 != 0 );
  return _X1 - v3;
}

/* ===== sub_9404D290 @ 0x9404D290 size 24 ===== */
__int64 __fastcall sub_9404D290(_BYTE *a1, __int64 a2, unsigned __int64 a3)
{
  if ( a3 != 0 )
  {
    do
      *a1++ = 0;
    while ( a3-- > 1 );
  }
  return -40;
}

/* ===== sub_9404D2A8 @ 0x9404D2A8 size 104 ===== */
__int64 __fastcall sub_9404D2A8(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x1
  __int64 v10; // x20
  _QWORD *v11; // x2
  _QWORD *v12; // x19
  bool v13; // zf

  v9 = *(_QWORD *)(result + 32) - 24LL;
  v10 = result;
  v11 = *(_QWORD **)(*(_QWORD *)(result + 32) + 8LL);
  v12 = v11 - 3;
  if ( result != v9 )
  {
    do
    {
      *v11 = *(_QWORD *)(v9 + 24);
      *(_QWORD *)(*(_QWORD *)(v9 + 24) + 8LL) = v11;
      *(_QWORD *)(v9 + 32) = 0;
      *(_QWORD *)(v9 + 24) = 0;
      result = sub_9404CC20(v9, a2, a3, a4, a5, a6, a7, a8, a9);
      v11 = (_QWORD *)v12[4];
      v13 = v10 == (_QWORD)v12;
      v9 = (__int64)v12;
      v12 = v11 - 3;
    }
    while ( !v13 );
  }
  return result;
}

/* ===== sub_9404D310 @ 0x9404D310 size 20 ===== */
// write access to const memory has been detected, the output may be wrong!
void sub_9404D310()
{
  qword_9407A010 = (__int64)&qword_9407A010;
  off_9407A018 = &qword_9407A010;
  JUMPOUT(0x9404DCD4LL);
}

/* ===== sub_9404D324 @ 0x9404D324 size 24 ===== */
unsigned __int64 *__fastcall sub_9404D324(__int64 a1)
{
  _DWORD *v1; // x0

  if ( a1 != 0 && (v1 = *(_DWORD **)(a1 + 120)) != nullptr )
    return sub_940260B0(v1);
  else
    return (unsigned __int64 *)4294967288LL;
}

/* ===== sub_9404D33C @ 0x9404D33C size 240 ===== */
void __fastcall __noreturn sub_9404D33C(
        int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x1
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _QWORD *v33; // x1

  v10 = *(__int64 **)(_ReadStatusReg(TPIDR_EL1) + 688);
  if ( v10 != nullptr )
  {
    sub_9402BC98();
    sub_9404D2A8((__int64)v10, a2, a3, a4, a5, a6, a7, a8, a9);
    sub_9404CC20(v10[2], v11, v12, v13, v14, v15, v16, v17, v18);
    sub_9404DDA8(v10);
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
      goto LABEL_6;
    sub_940223B4((unsigned __int64 *)&qword_9407A008);
    v19 = (_QWORD *)v10[17];
    *v19 = v10[16];
    *(_QWORD *)(v10[16] + 8) = v19;
    v10[17] = 0;
    v10[16] = 0;
    sub_940223D4((unsigned __int64 *)&qword_9407A008);
    while ( 1 )
    {
      sub_9404CC20((__int64)v10, v20, v21, v22, v23, v24, v25, v26, v27);
LABEL_5:
      sub_9402753C(a1);
LABEL_6:
      __asm { MSR             DAIFSet, #2 }
      sub_940223B4((unsigned __int64 *)&qword_9407A008);
      v33 = (_QWORD *)v10[17];
      *v33 = v10[16];
      *(_QWORD *)(v10[16] + 8) = v33;
      v10[17] = 0;
      v10[16] = 0;
      sub_940223D4((unsigned __int64 *)&qword_9407A008);
      __asm { MSR             DAIFClr, #2 }
    }
  }
  sub_9404CB4C(
    "%s:%d: WARNING: unexpected call on kernel thread %s!",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "uthread_exit",
    386,
    _ReadStatusReg(TPIDR_EL1) + 696);
  goto LABEL_5;
}

/* ===== sub_9404D42C @ 0x9404D42C size 12 ===== */
__int64 __fastcall sub_9404D42C(__int64 a1, __int64 a2)
{
  return sub_9404DD14(*(_QWORD *)(a1 + 688), *(_QWORD *)(a2 + 688));
}

/* ===== sub_9404D438 @ 0x9404D438 size 944 ===== */
__int64 __fastcall sub_9404D438(
        unsigned __int64 *a1,
        unsigned __int64 *a2,
        _BYTE *a3,
        unsigned __int64 a4,
        int a5,
        int a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v14; // x20
  __int64 v15; // x30
  __int64 v17; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int64 v31; // x19
  __int64 v32; // x27
  __int64 v33; // x0
  __int64 v34; // x24
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int64 v43; // x5
  unsigned __int64 v44; // x0
  unsigned __int64 v45; // x1
  unsigned __int64 v46; // x2
  unsigned __int64 v47; // x3
  __int64 v48; // x0
  unsigned __int64 v49; // x1
  unsigned int v50; // w24
  unsigned __int64 v51; // x1
  __int64 v52; // x6
  __int64 v53; // x7
  unsigned __int64 *v54; // x2
  unsigned __int64 v55; // x0
  unsigned __int64 v56; // x4
  unsigned __int64 i; // x1
  unsigned __int64 v58; // x3
  __int64 v59; // x5
  unsigned __int64 v60; // x1
  __int64 v62; // x0
  __int64 v63; // x2
  unsigned __int64 *v64; // x2
  __int64 v65; // x5
  unsigned __int64 v66; // x7
  unsigned __int64 *v67; // x4
  __int64 v68; // x1
  unsigned __int64 v69; // x3
  unsigned __int64 v70; // x1
  __int64 v71; // x0
  __int64 v72; // x1
  __int64 v73; // x2
  __int64 v74; // x3
  __int64 v75; // x4
  __int64 v76; // x5

  v17 = v15;
  if ( a1 == nullptr )
  {
    v55 = sub_9404B508(
            v15,
            "DEBUG ASSERT FAILED at (%s:%d): %s\n",
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            a14,
            "lk/trusty/lib/uthread/uthread.c",
            45,
            "ut");
    goto LABEL_58;
  }
  v14 = (__int64)(a1 + 5);
  sub_940251F8((__int64)(a1 + 5), 0xFFFFFFFFLL);
  if ( a2 == nullptr || a3 == nullptr )
    goto LABEL_61;
  if ( (a4 & 0xFFF) != 0 )
  {
    v50 = -7;
    goto LABEL_38;
  }
  if ( (a5 & 0x100) != 0 )
  {
    v31 = *a2;
    goto LABEL_7;
  }
  if ( (a5 & 0x40) == 0 )
  {
    v51 = a1[4];
    v52 = (unsigned int)(a6 - 1);
    v53 = (unsigned int)-a6;
    v54 = (unsigned __int64 *)(v51 - 24);
    v55 = (v52 + *a1) & v53;
    v56 = v55 + a4;
    if ( a1 != (unsigned __int64 *)(v51 - 24) )
    {
      for ( i = *(_QWORD *)(v51 - 24); i < v56; i = *(_QWORD *)(v58 - 24) )
      {
        v58 = v54[4];
        v59 = v52 + v54[1];
        v54 = (unsigned __int64 *)(v58 - 24);
        v60 = (v59 + i) & v53;
        if ( v55 < v60 )
          v55 = v60;
        v56 = v55 + a4;
        if ( a1 == v54 )
          break;
      }
    }
    if ( a1[12] >= v56 && v55 <= v56 )
    {
LABEL_32:
      *a2 = v55;
      v31 = v55;
      v50 = -5;
      if ( v55 == 0 )
        goto LABEL_38;
LABEL_7:
      if ( v31 < v31 + a4 )
      {
        if ( (a5 & 0x20) != 0 )
        {
          v32 = 1;
          v33 = sub_9404CBC4(48);
          v34 = v33;
          if ( v33 != 0 )
          {
LABEL_10:
            *(_QWORD *)v34 = v31;
            *(_QWORD *)(v34 + 8) = a4;
            *(_DWORD *)(v34 + 16) = a5;
            *(_DWORD *)(v34 + 20) = a6;
            sub_9404CC78((_BYTE *)(v33 + 40), a3, 8 * v32);
            v43 = a1[12];
            if ( (*(_DWORD *)(v34 + 16) & 0x40) != 0 && v43 > *(_QWORD *)v34 )
              v43 = *(_QWORD *)v34 & 0xFFFFFFFFFFF00000LL;
            v44 = a1[4];
            v45 = v44 - 24;
            if ( a1 != (unsigned __int64 *)(v44 - 24) )
            {
              v46 = *(_QWORD *)(v44 - 24);
              v47 = *(_QWORD *)v34;
              if ( *(_QWORD *)v34 < v46 )
              {
LABEL_42:
                if ( v47 + *(_QWORD *)(v34 + 8) > v46 )
                {
LABEL_41:
                  v62 = v34;
                  v50 = -8;
                  sub_9404CC20(v62, v35, v36, v37, v38, v39, v40, v41, v42);
                  goto LABEL_38;
                }
                *(_QWORD *)(v34 + 24) = *(_QWORD *)(v45 + 24);
                a1[12] = v43;
                v63 = *(_QWORD *)(v45 + 24);
                *(_QWORD *)(v34 + 32) = v45 + 24;
                *(_QWORD *)(v63 + 8) = v34 + 24;
                *(_QWORD *)(v45 + 24) = v34 + 24;
                goto LABEL_21;
              }
              if ( v46 + *(_QWORD *)(v44 - 16) > v47 )
                goto LABEL_41;
              while ( 1 )
              {
                v48 = *(_QWORD *)(v45 + 32);
                v45 = v48 - 24;
                if ( a1 == (unsigned __int64 *)(v48 - 24) )
                  break;
                v46 = *(_QWORD *)(v48 - 24);
                if ( v46 > v47 )
                  goto LABEL_42;
                if ( v46 + *(_QWORD *)(v48 - 16) > v47 )
                  goto LABEL_41;
              }
            }
            v49 = a1[3];
            *(_QWORD *)(v34 + 24) = v49;
            a1[12] = v43;
            *(_QWORD *)(v34 + 32) = a1 + 3;
            *(_QWORD *)(v49 + 8) = v34 + 24;
            a1[3] = v34 + 24;
LABEL_21:
            v50 = sub_9404DE34(a1, v34);
LABEL_38:
            sub_9402530C(v14);
            return v50;
          }
        }
        else
        {
          v32 = (unsigned int)(a4 >> 12);
          v33 = sub_9404CBC4(8 * (v32 + 5));
          v34 = v33;
          if ( v33 != 0 )
            goto LABEL_10;
        }
        v50 = -5;
        goto LABEL_38;
      }
LABEL_61:
      v50 = -8;
      goto LABEL_38;
    }
LABEL_37:
    *a2 = 0;
    v50 = -5;
    goto LABEL_38;
  }
  v64 = (unsigned __int64 *)a1[3];
  v65 = (unsigned int)-a6;
  v55 = (0x2000000 - a4) & v65;
  v66 = v55 + a4;
  if ( a1 + 3 == v64 )
    goto LABEL_58;
  if ( v64 == nullptr )
    goto LABEL_58;
  v67 = v64 - 3;
  if ( v64 == (unsigned __int64 *)24 )
    goto LABEL_58;
  v68 = *(v64 - 3);
  v69 = v68 + *(v64 - 2);
  if ( v55 < v69 )
  {
    while ( (*(_DWORD *)(v64 - 1) & 0x40) != 0 )
    {
      v64 = (unsigned __int64 *)v67[3];
      v70 = (v68 - a4) & v65;
      if ( v55 > v70 )
        v55 = v70;
      v66 = v55 + a4;
      if ( a1 + 3 == v64 )
        goto LABEL_58;
      if ( v64 == nullptr )
        goto LABEL_58;
      v67 = v64 - 3;
      if ( v64 == (unsigned __int64 *)24 )
        goto LABEL_58;
      v68 = *(v64 - 3);
      v69 = v68 + *(v64 - 2);
      if ( v69 <= v55 )
        goto LABEL_34;
    }
    goto LABEL_37;
  }
LABEL_34:
  if ( a1[12] <= v55 )
  {
LABEL_58:
    if ( v55 >= *a1 && v55 <= v66 )
      goto LABEL_32;
    goto LABEL_37;
  }
  if ( (v67[2] & 0x40) == 0 )
  {
    if ( (v55 & 0xFFFFFFFFFFF00000LL) < v69 )
      goto LABEL_37;
    goto LABEL_58;
  }
  v71 = sub_9404B508(
          v17,
          "DEBUG ASSERT FAILED at (%s:%d): %s\n",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "lk/trusty/lib/uthread/uthread.c",
          91,
          "(mp->flags & UTM_NS_MEM) == 0");
  return sub_9404D7E8(v71, v72, v73, v74, v75, v76);
}

/* ===== sub_9404D7E8 @ 0x9404D7E8 size 592 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_9404D7E8(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, unsigned __int64 a5, __int64 a6)
{
  __int64 v12; // x0
  __int64 v13; // x19
  unsigned __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned __int64 v57; // [xsp+60h] [xbp+60h] BYREF
  __int64 v58; // [xsp+68h] [xbp+68h] BYREF

  v12 = sub_9404CBDC(1, 168);
  v13 = v12;
  if ( v12 == 0 )
    return 0;
  *(_QWORD *)(v12 + 32) = v12 + 24;
  *(_QWORD *)(v12 + 24) = v12 + 24;
  sub_940251C4(v12 + 40);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    sub_940223B4((unsigned __int64 *)&qword_9407A008);
    dword_9407A000 = 1;
    sub_940223D4((unsigned __int64 *)&qword_9407A008);
  }
  else
  {
    __asm { MSR             DAIFSet, #2 }
    sub_940223B4((unsigned __int64 *)&qword_9407A008);
    dword_9407A000 = 1;
    sub_940223D4((unsigned __int64 *)&qword_9407A008);
    __asm { MSR             DAIFClr, #2 }
  }
  *(_DWORD *)(v13 + 104) = 0;
  *(_QWORD *)(v13 + 144) = a6;
  *(_QWORD *)(v13 + 8) = a2;
  *(_QWORD *)(v13 + 96) = 0x2000000;
  v14 = sub_9404CBCC(0x1000u, a5);
  *(_QWORD *)(v13 + 16) = v14;
  if ( v14 == 0 )
  {
LABEL_15:
    sub_9404CC20(v13, v15, v16, v17, v18, v19, v20, v21, v22);
    return 0;
  }
  v57 = a4 - a5;
  v58 = sub_9404A248(v14);
  if ( (unsigned int)sub_9404D438(
                       (unsigned __int64 *)v13,
                       &v57,
                       &v58,
                       a5,
                       307,
                       4096,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30) != 0 )
  {
LABEL_14:
    sub_9404CC20(*(_QWORD *)(v13 + 16), v31, v32, v33, v34, v35, v36, v37, v38);
    goto LABEL_15;
  }
  *(_QWORD *)v13 = a4;
  v39 = sub_940268B8(a1, -536683304, 0, a3, 4096);
  *(_QWORD *)(v13 + 120) = v39;
  if ( v39 == 0 || (unsigned int)sub_9404DD90(v13) != 0 )
  {
    sub_9404D2A8(v13, v40, v41, v42, v43, v44, v45, v46, v47);
    goto LABEL_14;
  }
  *(_QWORD *)(*(_QWORD *)(v13 + 120) + 688LL) = v13;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    sub_940223B4((unsigned __int64 *)&qword_9407A008);
    *(_QWORD *)(v13 + 128) = &qword_9407A010;
    *(_QWORD *)(v13 + 136) = 0;
    MEMORY[0] = v13 + 128;
    off_9407A018 = (_UNKNOWN *)(v13 + 128);
    sub_940223D4((unsigned __int64 *)&qword_9407A008);
    return v13;
  }
  else
  {
    __asm { MSR             DAIFSet, #2 }
    sub_940223B4((unsigned __int64 *)&qword_9407A008);
    *(_QWORD *)(v13 + 128) = &qword_9407A010;
    *(_QWORD *)(v13 + 136) = 0;
    MEMORY[0] = v13 + 128;
    off_9407A018 = (_UNKNOWN *)(v13 + 128);
    sub_940223D4((unsigned __int64 *)&qword_9407A008);
    __asm { MSR             DAIFClr, #2 }
    return v13;
  }
}

/* ===== sub_9404DA38 @ 0x9404DA38 size 460 ===== */
__int64 __fastcall sub_9404DA38(
        _QWORD *a1,
        unsigned __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x22
  __int64 v12; // x30
  __int64 v14; // x23
  __int64 v16; // x19
  unsigned __int64 v17; // x0
  unsigned int v18; // w20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _QWORD *v28; // x0
  _QWORD *v29; // x1
  __int64 v30; // x0
  __int64 v31; // x1
  __int64 v32; // x2

  v14 = v12;
  if ( a1 == nullptr )
  {
    sub_9404B508(
      v12,
      "DEBUG ASSERT FAILED at (%s:%d): %s\n",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lk/trusty/lib/uthread/uthread.c",
      45,
      "ut");
    goto LABEL_25;
  }
  v11 = (__int64)(a1 + 5);
  sub_940251F8((__int64)(a1 + 5), 0xFFFFFFFFLL);
  if ( a2 == 0 )
  {
LABEL_25:
    v18 = -8;
    goto LABEL_10;
  }
  if ( a2 > a2 + a3 || (v16 = a1[4] - 24LL, a1 == (_QWORD *)v16) )
  {
LABEL_9:
    v18 = -2;
LABEL_10:
    sub_9402530C(v11);
    return v18;
  }
  while ( 1 )
  {
    if ( a2 >= *(_QWORD *)v16 )
    {
      v17 = *(_QWORD *)v16 + *(_QWORD *)(v16 + 8);
      if ( a2 + a3 <= v17 && a2 < v17 )
        break;
    }
    v16 = *(_QWORD *)(v16 + 32) - 24LL;
    if ( a1 == (_QWORD *)v16 )
      goto LABEL_9;
  }
  v18 = sub_9404DFD8(a1, v16);
  if ( v18 != 0 )
    goto LABEL_10;
  if ( (*(_DWORD *)(v16 + 16) & 0x40) == 0 )
  {
    v29 = *(_QWORD **)(v16 + 32);
    v28 = *(_QWORD **)(v16 + 24);
    goto LABEL_22;
  }
  v28 = *(_QWORD **)(v16 + 24);
  if ( a1 + 3 != v28 && v28 != nullptr && v28 != (_QWORD *)24 && (*(_DWORD *)(v28 - 1) & 0x40) != 0 )
  {
    v29 = *(_QWORD **)(v16 + 32);
    goto LABEL_22;
  }
  v29 = *(_QWORD **)(v16 + 32);
  if ( a1 + 3 == v29 || v29 == nullptr || v29 == (_QWORD *)24 )
  {
    a1[12] = 0x2000000;
    goto LABEL_22;
  }
  if ( (*(_DWORD *)(v29 - 1) & 0x40) != 0 )
  {
    a1[12] = *(v29 - 3) & 0xFFFFFFFFFFF00000LL;
LABEL_22:
    *v29 = v28;
    *(_QWORD *)(*(_QWORD *)(v16 + 24) + 8LL) = v29;
    *(_QWORD *)(v16 + 32) = 0;
    *(_QWORD *)(v16 + 24) = 0;
    sub_9404CC20(v16, v20, v21, v22, v23, v24, v25, v26, v27);
    sub_9402530C(v11);
    return 0;
  }
  v30 = sub_9404B508(
          v14,
          "DEBUG ASSERT FAILED at (%s:%d): %s\n",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "lk/trusty/lib/uthread/uthread.c",
          252,
          "item->flags & UTM_NS_MEM");
  return sub_9404DC04(v30, v31, v32);
}

/* ===== sub_9404DC04 @ 0x9404DC04 size 212 ===== */
__int64 __fastcall sub_9404DC04(
        unsigned __int64 *a1,
        unsigned __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x30
  __int64 v14; // x22
  unsigned __int64 *v15; // x0
  BOOL v16; // w19

  if ( a1 == nullptr )
    return sub_9404B508(
             v11,
             "DEBUG ASSERT FAILED at (%s:%d): %s\n",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lk/trusty/lib/uthread/uthread.c",
             45,
             "ut");
  v14 = (__int64)(a1 + 5);
  sub_940251F8((__int64)(a1 + 5), 0xFFFFFFFFLL);
  if ( a2 > a2 + a3 || (v15 = (unsigned __int64 *)(a1[4] - 24), a1 == v15) )
  {
LABEL_7:
    v16 = false;
  }
  else
  {
    while ( 1 )
    {
      if ( a2 >= *v15 )
      {
        v16 = a2 + a3 <= *v15 + v15[1] && a2 < *v15 + v15[1];
        if ( a2 + a3 <= *v15 + v15[1] && a2 < *v15 + v15[1] )
          break;
      }
      v15 = (unsigned __int64 *)(v15[4] - 24);
      if ( a1 == v15 )
        goto LABEL_7;
    }
  }
  sub_9402530C(v14);
  return v16;
}

/* ===== sub_9404DCD8 @ 0x9404DCD8 size 56 ===== */
void __noreturn sub_9404DCD8()
{
  unsigned __int64 v0; // x3

  v0 = *(_QWORD *)(*(_QWORD *)(_ReadStatusReg(TPIDR_EL1) + 688) + 8LL);
  __asm { MSR             DAIFSet, #2 }
  _WriteStatusReg(SPSR_EL1, 0x10u);
  _WriteStatusReg(ELR_EL1, v0);
  __asm { ERET }
}

/* ===== nullsub_10 @ 0x9404DD10 size 4 ===== */
void nullsub_10()
{
  ;
}

/* ===== sub_9404DD14 @ 0x9404DD14 size 124 ===== */
__int64 __fastcall sub_9404DD14(__int64 result, __int64 a2)
{
  __int64 v2; // x19

  if ( result == 0 || a2 != 0 )
  {
    if ( a2 != 0 )
    {
      v2 = result;
      result = sub_9404A248(*(_QWORD *)(a2 + 112)) | ((unsigned __int64)*(unsigned int *)(a2 + 152) << 48);
      _WriteStatusReg(TTBR0_EL1, result);
      __isb(0xFu);
      if ( v2 == 0 )
      {
        _WriteStatusReg(TCR_EL1, 0x2B5233527uLL);
        __isb(0xFu);
        return 0x2B5233527LL;
      }
    }
  }
  else
  {
    result = 0x2B52335A7LL;
    _WriteStatusReg(TCR_EL1, 0x2B52335A7uLL);
    __isb(0xFu);
  }
  return result;
}

/* ===== sub_9404DD90 @ 0x9404DD90 size 24 ===== */
__int64 __fastcall sub_9404DD90(__int64 a1)
{
  *(_DWORD *)(a1 + 152) = *(_DWORD *)(a1 + 104);
  *(_QWORD *)(a1 + 160) = a1;
  return 0;
}

/* ===== sub_9404DDA8 @ 0x9404DDA8 size 68 ===== */
__int64 __fastcall sub_9404DDA8(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  sub_940231E0(0, 0x2000000u, 0, 25, 0x15u, 0xCu, *(_QWORD *)(a1 + 112), *(_DWORD *)(a1 + 152));
  return sub_9404CC20(*(_QWORD *)(a1 + 112), v2, v3, v4, v5, v6, v7, v8, v9);
}

/* ===== sub_9404DDEC @ 0x9404DDEC size 72 ===== */
__int64 __fastcall sub_9404DDEC(__int64 a1)
{
  __int64 v2; // x0

  v2 = sub_9404CBCC(0x80u, 128);
  *(_QWORD *)(a1 + 112) = v2;
  if ( v2 == 0 )
    return 4294967291LL;
  sub_9404CDC4(v2, 0, 0x80u);
  return 0;
}

/* ===== sub_9404DE34 @ 0x9404DE34 size 420 ===== */
__int64 __fastcall sub_9404DE34(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x30
  __int64 v12; // x21
  __int64 v13; // x19
  unsigned __int64 v14; // x0
  __int64 v15; // x25
  int v16; // w19
  __int64 v17; // x20
  __int64 v18; // x24
  __int64 v19; // x24
  unsigned __int64 v20; // x19
  __int64 *v21; // x23
  __int64 v22; // x22
  unsigned __int64 v23; // x20
  unsigned int v24; // w27
  unsigned int i; // w22
  __int64 result; // x0

  v12 = a1;
  v13 = v10;
  if ( *(_QWORD *)(a1 + 112) == 0 )
    goto LABEL_20;
  while ( 1 )
  {
    v14 = *(_QWORD *)(a2 + 8);
    v15 = v14 & 0xFFF;
    if ( (v14 & 0xFFF) == 0 )
      break;
    a1 = sub_9404B508(
           v13,
           "ASSERT FAILED at (%s:%d): %s\n",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "lk/trusty/lib/uthread/arch/arm64/uthread.c",
           138,
           "!(mp->size & USER_PAGE_MASK)");
LABEL_20:
    result = sub_9404DDEC(a1);
    if ( (_DWORD)result != 0 )
      return result;
  }
  v16 = *(_DWORD *)(a2 + 16);
  v17 = 3104;
  v18 = 64;
  if ( (v16 & 0x40) == 0 )
    v17 = 3072;
  if ( (v16 & 2) == 0 )
    v18 = 192;
  v19 = v18 | v17;
  if ( (v16 & 0x80) == 0 )
    v19 |= 0x308uLL;
  v20 = 4096;
  if ( (*(_DWORD *)(a2 + 16) & 0x20) != 0 )
    v20 = *(_QWORD *)(a2 + 8);
  if ( v14 / v20 == 0 )
    return 0;
  v21 = (__int64 *)(a2 + 40);
  v22 = 0;
  v23 = 0;
  while ( 1 )
  {
    v24 = sub_94023114(
            v22 + *(_QWORD *)a2,
            *v21,
            v20,
            v19,
            0,
            25,
            0x15u,
            0xCu,
            *(_QWORD *)(v12 + 112),
            *(_DWORD *)(v12 + 152));
    if ( v24 != 0 )
      break;
    ++v23;
    v22 += v20;
    ++v21;
    if ( *(_QWORD *)(a2 + 8) / v20 <= v23 )
      return 0;
  }
  for ( i = 0; v23 > i; v15 = i )
  {
    sub_940231E0(*(_QWORD *)a2 + v15 * v20, v20, 0, 25, 0x15u, 0xCu, *(_QWORD *)(v12 + 112), *(_DWORD *)(v12 + 152));
    ++i;
  }
  return v24;
}

/* ===== sub_9404DFD8 @ 0x9404DFD8 size 40 ===== */
__int64 __fastcall sub_9404DFD8(__int64 a1, __int64 a2)
{
  return sub_940231E0(
           *(_QWORD *)a2,
           *(_QWORD *)(a2 + 8),
           0,
           25,
           0x15u,
           0xCu,
           *(_QWORD *)(a1 + 112),
           *(_DWORD *)(a1 + 152));
}

/* ===== sub_9404E298 @ 0x9404E298 size 16 ===== */
void __fastcall __noreturn sub_9404E298(__int64 a1, char _W1)
{
  __asm { WHILEWR         P0.H, X1, X24 }
  __udf(0xA78u);
}

/* ===== sub_94051138 @ 0x94051138 size 24 ===== */
void __noreturn sub_94051138()
{
  __udf(0);
}

/* ===== sub_94053770 @ 0x94053770 size 28 ===== */
void __fastcall __noreturn sub_94053770(double a1, double a2, double a3, __n128 _Q3)
{
  __asm
  {
    FCMLA           Z6.H, P4/M, Z3.H, Z31.H, #270
    FNMLS           Z18.H, P2/M, Z11.H, Z22.H
    FMLS            Z18.H, P0/M, Z3.H, Z2.H
    FNMLS           Z6.H, P3/M, Z27.H, Z18.H
  }
  __udf(0xA63u);
}

/* ===== sub_94054F40 @ 0x94054F40 size 20 ===== */
void __fastcall sub_94054F40(int a1, double a2, double a3, double a4, double a5, double a6, __n128 a7)
{
  __int64 v7; // x27

  *(_BYTE *)(v7 + 2073) = a7.n128_u8[0];
  if ( a1 != 0 )
    __udf(0xA78u);
  JUMPOUT(0x940B53F0LL);
}

/* ===== sub_94054F58 @ 0x94054F58 size 20 ===== */
void __fastcall sub_94054F58(int a1, double a2, double a3, double a4, double a5, double a6, __n128 a7)
{
  __int64 v7; // x27

  __asm { FNMLS           Z1.H, P1/M, Z19.H, Z20.H }
  *(_BYTE *)(v7 + 2073) = a7.n128_u8[0];
  if ( a1 != 0 )
    __udf(0xA78u);
  JUMPOUT(0x940B5408LL);
}

/* ===== sub_940570A8 @ 0x940570A8 size 20 ===== */
void __noreturn sub_940570A8()
{
  __asm { FNMLS           Z3.H, P0/M, Z11.H, Z20.H }
  __udf(0);
}

/* ===== sub_94057450 @ 0x94057450 size 20 ===== */
void __fastcall __noreturn sub_94057450(
        double a1,
        double a2,
        double a3,
        __n128 _Q3,
        double a5,
        __n128 _Q5,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 _X3)
{
  __asm { FNMLS           Z22.H, P0/M, Z19.H, Z13.H }
  __asm
  {
    STGP            X5, X29, [X3,#-0x100]
    FMUL            Z19.H, Z3.H, Z5.H[0]
  }
  __udf(0xA2Eu);
}


// END total=715 ok=715 fail=0
