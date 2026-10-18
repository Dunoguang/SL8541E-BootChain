// pseudo-C decompilation of BootROM_sc9832e (bare image, base 0x100000)  entry=brom_entry@0x100000 main=brom_main@0x10E730
// produced headlessly by IDA 9.4.0.260714 + Hex-Rays (hexarm)
// functions: 287 (ok 287, fail 0)

/* ===== sub_10016C @ 0x10016C (file 0x16C) size 4 ===== */
// attributes: thunk
__int64 __fastcall sub_10016C(__int64 (*a1)(void))
{
  return a1();
}


/* ===== nullsub_3 @ 0x100170 (file 0x170) size 4 ===== */
void nullsub_3()
{
  ;
}


/* ===== sub_100174 @ 0x100174 (file 0x174) size 24 ===== */
__int64 sub_100174()
{
  __int16 StatusReg; // w1

  StatusReg = _ReadStatusReg(MPIDR_EL1);
  return (unsigned __int8)StatusReg + 4LL * HIBYTE(StatusReg);
}


/* ===== sub_100800 @ 0x100800 (file 0x800) size 4 ===== */
// attributes: thunk
void __noreturn sub_100800()
{
  while ( 1 )
    ;
}


/* ===== sub_100880 @ 0x100880 (file 0x880) size 4 ===== */
// attributes: thunk
void __noreturn sub_100880()
{
  while ( 1 )
    ;
}


/* ===== sub_100900 @ 0x100900 (file 0x900) size 4 ===== */
// attributes: thunk
void __noreturn sub_100900()
{
  while ( 1 )
    ;
}


/* ===== sub_100980 @ 0x100980 (file 0x980) size 4 ===== */
// attributes: thunk
void __noreturn sub_100980()
{
  while ( 1 )
    ;
}


/* ===== sub_100A00 @ 0x100A00 (file 0xA00) size 4 ===== */
// attributes: thunk
void __noreturn sub_100A00()
{
  while ( 1 )
    ;
}


/* ===== sub_100A80 @ 0x100A80 (file 0xA80) size 4 ===== */
// attributes: thunk
void __noreturn sub_100A80()
{
  while ( 1 )
    ;
}


/* ===== sub_100B00 @ 0x100B00 (file 0xB00) size 4 ===== */
// attributes: thunk
void __noreturn sub_100B00()
{
  while ( 1 )
    ;
}


/* ===== sub_100B80 @ 0x100B80 (file 0xB80) size 4 ===== */
// attributes: thunk
void __noreturn sub_100B80()
{
  while ( 1 )
    ;
}


/* ===== sub_100C00 @ 0x100C00 (file 0xC00) size 4 ===== */
// attributes: thunk
void __noreturn sub_100C00()
{
  while ( 1 )
    ;
}


/* ===== sub_100C80 @ 0x100C80 (file 0xC80) size 4 ===== */
// attributes: thunk
void __noreturn sub_100C80()
{
  while ( 1 )
    ;
}


/* ===== sub_100D00 @ 0x100D00 (file 0xD00) size 4 ===== */
// attributes: thunk
void __noreturn sub_100D00()
{
  while ( 1 )
    ;
}


/* ===== sub_100D80 @ 0x100D80 (file 0xD80) size 4 ===== */
// attributes: thunk
void __noreturn sub_100D80()
{
  while ( 1 )
    ;
}


/* ===== sub_100E00 @ 0x100E00 (file 0xE00) size 4 ===== */
// attributes: thunk
void __noreturn sub_100E00()
{
  while ( 1 )
    ;
}


/* ===== sub_100E80 @ 0x100E80 (file 0xE80) size 4 ===== */
// attributes: thunk
void __noreturn sub_100E80()
{
  while ( 1 )
    ;
}


/* ===== sub_100F00 @ 0x100F00 (file 0xF00) size 4 ===== */
// attributes: thunk
void __noreturn sub_100F00()
{
  while ( 1 )
    ;
}


/* ===== sub_100F80 @ 0x100F80 (file 0xF80) size 4 ===== */
// attributes: thunk
void __noreturn sub_100F80()
{
  while ( 1 )
    ;
}


/* ===== sub_101000 @ 0x101000 (file 0x1000) size 92 ===== */
__int64 __fastcall sub_101000(__int64 a1, unsigned int a2)
{
  unsigned int i; // [xsp+1Ch] [xbp-4h]

  for ( i = 0; i < a2; ++i )
  {
    if ( *(_BYTE *)(a1 + i) != 0 )
      return 1;
  }
  return 0;
}


/* ===== sub_10105C @ 0x10105C (file 0x105C) size 192 ===== */
__int64 sub_10105C()
{
  __int64 v0; // x0
  __int64 v1; // x0
  int v3; // [xsp+18h] [xbp+18h]
  unsigned int i; // [xsp+1Ch] [xbp+1Ch]

  v3 = 0;
  sub_1018F8();
  sub_1023B8(1);
  for ( i = 0; i <= 3; ++i )
  {
    sub_1017AC(0);
    sub_101704(*(unsigned int *)(0x1000 + 4LL * i));
    sub_1017AC(1);
    v0 = sub_10D9D0(2);
    v1 = sub_1018A0(v0);
    v3 = sub_1026F4(v1);
    if ( v3 == 1 )
      break;
  }
  if ( v3 != 0 )
  {
    sub_10DF40(4096);
    sub_10E254(5);
    return 1;
  }
  else
  {
    sub_10DF40(0x2000);
    sub_10E254(6);
    return 0;
  }
}


/* ===== sub_10111C @ 0x10111C (file 0x111C) size 136 ===== */
__int64 __fastcall sub_10111C(unsigned int a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  unsigned int v9; // [xsp+3Ch] [xbp+3Ch]

  v9 = sub_10105C();
  if ( v9 == 1 )
  {
    sub_1017AC(0);
    sub_1015D0(26000000);
    sub_101704(6500000);
    sub_1017AC(1);
    v9 = sub_102950(a1, a2, a3, a4);
  }
  sub_10192C();
  sub_1023B8(0);
  return v9;
}


/* ===== sub_1011A4 @ 0x1011A4 (file 0x11A4) size 108 ===== */
__int64 sub_1011A4()
{
  __int64 v0; // x0

  sub_1018F8();
  v0 = sub_10D9D0(2);
  sub_1018A0(v0);
  sub_1017AC(0);
  sub_1015D0(26000000);
  sub_101704(6500000);
  sub_1017AC(1);
  return (unsigned int)sub_102B34(128, 20480, 1);
}


/* ===== sub_101210 @ 0x101210 (file 0x1210) size 388 ===== */
__int64 __fastcall sub_101210(unsigned int a1)
{
  _BYTE v3[32]; // [xsp+28h] [xbp+28h] BYREF
  __int64 v4; // [xsp+48h] [xbp+48h]
  unsigned int i; // [xsp+54h] [xbp+54h]
  unsigned int v6; // [xsp+58h] [xbp+58h]
  int v7; // [xsp+5Ch] [xbp+5Ch]

  v7 = 0;
  memset(v3, 0, sizeof(v3));
  v4 = 20480;
  v6 = 0;
  if ( a1 != 0 )
    sub_10DF40(1024);
  else
    sub_10DF40(512);
  for ( i = 0; i <= 1; ++i )
  {
    if ( i != 0 )
      v7 = sub_10111C(a1, 0, 0x80u, 20480);
    else
      v7 = sub_1011A4();
    if ( v7 != 0 && *(_DWORD *)v4 == 1112819780 && *(_DWORD *)(v4 + 48) <= 0xFFFFu )
    {
      sub_10DF40(0x20000);
      sub_10E254(10);
      if ( (unsigned int)sub_101000(v4 + 8, 0x20u) == 0 )
        return 1;
      sub_10E798(20992, *(unsigned int *)(v4 + 48), v3);
      if ( (unsigned int)sub_10FB08(v3, v4 + 8, 32) == 0 )
        return 1;
      v6 = 4;
      sub_10DF40(256);
      sub_10E254(23);
    }
    else
    {
      v6 = 3;
      sub_10DF40(0x8000);
      sub_10E254(8);
    }
  }
  return v6;
}


/* ===== sub_101394 @ 0x101394 (file 0x1394) size 160 ===== */
__int64 __fastcall sub_101394(int a1)
{
  unsigned int i; // [xsp+1Ch] [xbp-4h]

  if ( a1 != 0 )
  {
    MEMORY[0x20E00000] |= 0x800u;
    MEMORY[0x20E00004] |= 0x4000u;
    for ( i = 0; i <= 0xFE; ++i )
      ;
    MEMORY[0x20E00004] &= ~0x4000u;
    return 551550980;
  }
  else
  {
    MEMORY[0x20E00000] &= ~0x800u;
    return 551550976;
  }
}


/* ===== nullsub_1 @ 0x101434 (file 0x1434) size 4 ===== */
void nullsub_1()
{
  ;
}


/* ===== sub_101438 @ 0x101438 (file 0x1438) size 408 ===== */
__int64 sub_101438()
{
  MEMORY[0x402A00D4] = 0;
  MEMORY[0x402A00C8] = 0;
  MEMORY[0x402A00D8] = 0;
  MEMORY[0x402A00C4] = 0;
  MEMORY[0x402A00B0] = 0;
  MEMORY[0x402A00B8] = 0;
  MEMORY[0x402A00C0] = 0;
  MEMORY[0x402A00BC] = 0;
  MEMORY[0x402A00CC] = 0;
  MEMORY[0x402A00DC] = 0;
  MEMORY[0x402A00B4] = 0;
  MEMORY[0x402A00AC] = 0;
  MEMORY[0x402A00D0] = 0;
  MEMORY[0x402A04D4] = 1572992;
  MEMORY[0x402A04C8] = 1572992;
  MEMORY[0x402A04D8] = 1572992;
  MEMORY[0x402A04C4] = 1572864;
  MEMORY[0x402A04B0] = 1572992;
  MEMORY[0x402A04B8] = 1572992;
  MEMORY[0x402A04C0] = 64;
  MEMORY[0x402A04BC] = 64;
  MEMORY[0x402A04CC] = 1572992;
  MEMORY[0x402A04DC] = 1572992;
  MEMORY[0x402A04B4] = 1572992;
  MEMORY[0x402A04AC] = 1572992;
  MEMORY[0x402A04D0] = 1572992;
  return 1076495568;
}


/* ===== sub_1015D0 @ 0x1015D0 (file 0x15D0) size 136 ===== */
__int64 sub_1015D0()
{
  MEMORY[0x21500090] &= 0xFFFFFFF8;
  MEMORY[0x21500090] |= 1u;
  MEMORY[0x1010] = 26000000;
  return 26000000;
}


/* ===== sub_101658 @ 0x101658 (file 0x1658) size 172 ===== */
bool sub_101658()
{
  int v1; // [xsp+14h] [xbp+14h]
  int i; // [xsp+18h] [xbp+18h]
  int v3; // [xsp+1Ch] [xbp+1Ch]

  MEMORY[0x2060002C] |= 0x1000000u;
  v3 = MEMORY[0x2060002C];
  v1 = sub_10D9B0();
  for ( i = v1; (v3 & 0x1000000) != 0 && (unsigned int)(i - v1) <= 0x63; i = sub_10D9B0() )
    v3 = MEMORY[0x2060002C];
  return (unsigned int)(i - v1) <= 0x64;
}


/* ===== sub_101704 @ 0x101704 (file 0x1704) size 168 ===== */
__int64 __fastcall sub_101704(int a1)
{
  MEMORY[0x2060002C] = MEMORY[0x2060002C] & 0xFFFF003F
                     | (unsigned __int16)((unsigned __int16)(MEMORY[0x1010] / (unsigned int)(4 * a1)) << 8)
                     | (unsigned __int8)((unsigned __int16)(MEMORY[0x1010] / (unsigned int)(4 * a1)) >> 8 << 6);
  return MEMORY[0x1010] / (4 * (MEMORY[0x1010] / (unsigned int)(4 * a1)));
}


/* ===== sub_1017AC @ 0x1017AC (file 0x17AC) size 244 ===== */
__int64 __fastcall sub_1017AC(int a1)
{
  int v2; // [xsp+24h] [xbp+24h]
  int i; // [xsp+28h] [xbp+28h]
  char v4; // [xsp+2Ch] [xbp+2Ch]

  if ( a1 != 0 )
  {
    MEMORY[0x2060002C] |= 1u;
    v4 = MEMORY[0x2060002C];
    v2 = sub_10D9B0();
    for ( i = v2; (v4 & 2) == 0 && (unsigned int)(i - v2) <= 0x63; i = sub_10D9B0() )
      v4 = MEMORY[0x2060002C];
    MEMORY[0x2060002C] |= 4u;
    return 543162412;
  }
  else
  {
    MEMORY[0x2060002C] &= ~4u;
    MEMORY[0x2060002C] &= ~1u;
    return 543162412;
  }
}


/* ===== sub_1018A0 @ 0x1018A0 (file 0x18A0) size 88 ===== */
__int64 sub_1018A0()
{
  MEMORY[0x2060002C] &= ~0x8000000u;
  sub_10D9D0(1);
  MEMORY[0x2060002C] |= 0x8000000u;
  return sub_10D9D0(1);
}


/* ===== sub_1018F8 @ 0x1018F8 (file 0x18F8) size 52 ===== */
bool sub_1018F8()
{
  __int64 v0; // x0

  v0 = sub_101394(1);
  sub_10D310(v0);
  nullsub_1();
  sub_101438();
  sub_1015D0();
  return sub_101658();
}


/* ===== sub_10192C @ 0x10192C (file 0x192C) size 32 ===== */
__int64 sub_10192C()
{
  sub_1017AC(0);
  return sub_101394(0);
}


/* ===== sub_10194C @ 0x10194C (file 0x194C) size 104 ===== */
__int64 __fastcall sub_10194C(int a1, int a2)
{
  if ( a2 != 0 )
    MEMORY[0x20600034] |= a1;
  else
    MEMORY[0x20600034] &= ~a1;
  return 543162420;
}


/* ===== sub_1019B4 @ 0x1019B4 (file 0x19B4) size 104 ===== */
__int64 __fastcall sub_1019B4(int a1, int a2)
{
  if ( a2 != 0 )
    MEMORY[0x20600038] |= a1;
  else
    MEMORY[0x20600038] &= ~a1;
  return 543162424;
}


/* ===== sub_101A1C @ 0x101A1C (file 0x1A1C) size 32 ===== */
__int64 __fastcall sub_101A1C(int a1)
{
  MEMORY[0x20600030] = a1;
  return 543162416;
}


/* ===== sub_101A3C @ 0x101A3C (file 0x1A3C) size 32 ===== */
__int64 sub_101A3C()
{
  return MEMORY[0x20600030];
}


/* ===== sub_101A5C @ 0x101A5C (file 0x1A5C) size 84 ===== */
__int64 __fastcall sub_101A5C(unsigned __int8 a1)
{
  unsigned int v2; // [xsp+1Ch] [xbp-4h]

  v2 = MEMORY[0x2060002C] & 0xFFF0FFFF | (a1 << 16);
  MEMORY[0x2060002C] = v2;
  return 543162412;
}


/* ===== sub_101AB0 @ 0x101AB0 (file 0x1AB0) size 80 ===== */
__int64 __fastcall sub_101AB0(__int64 a1)
{
  MEMORY[0x2060003C] |= 0x20000000u;
  MEMORY[0x20600058] = a1;
  return 543162460;
}


/* ===== sub_101B00 @ 0x101B00 (file 0x1B00) size 32 ===== */
__int64 __fastcall sub_101B00(int a1)
{
  MEMORY[0x20600004] = a1;
  return 543162372;
}


/* ===== sub_101B20 @ 0x101B20 (file 0x1B20) size 28 ===== */
__int64 __fastcall sub_101B20(int a1)
{
  MEMORY[0x20600000] = a1;
  return 543162368;
}


/* ===== sub_101B3C @ 0x101B3C (file 0x1B3C) size 32 ===== */
__int64 __fastcall sub_101B3C(int a1)
{
  MEMORY[0x20600008] = a1;
  return 543162376;
}


/* ===== sub_101B5C @ 0x101B5C (file 0x1B5C) size 648 ===== */
__int64 __fastcall sub_101B5C(int a1, char a2, int a3, int a4)
{
  int v5; // [xsp+1Ch] [xbp-4h]

  if ( (a2 & 0x40) != 0 )
    v5 = 0x200000;
  else
    v5 = 0x40000;
  if ( (a2 & 0x20) != 0 )
    v5 |= 0x20u;
  if ( (a2 & 0x10) != 0 )
    v5 |= 0x10u;
  if ( (a2 & 8) != 0 )
  {
    v5 |= 0xCu;
    MEMORY[0x2060003C] &= ~0x8000000u;
  }
  else if ( (a2 & 4) != 0 )
  {
    v5 |= 0xCu;
    MEMORY[0x2060003C] |= 0x8000000u;
  }
  else
  {
    MEMORY[0x2060003C] &= ~0x8000000u;
  }
  if ( (a2 & 2) != 0 )
    v5 |= 2u;
  if ( (a2 & 1) != 0 )
    v5 |= 1u;
  if ( a3 == 1 )
    v5 |= 0xC00000u;
  switch ( a4 )
  {
    case 1:
      v5 |= 0x1A0000u;
      break;
    case 2:
      v5 |= 0x90000u;
      break;
    case 3:
      v5 |= 0x20000u;
      break;
    case 4:
      v5 |= 0x20000u;
      break;
    case 5:
      v5 |= 0x1A0000u;
      break;
    case 6:
      v5 |= 0x1A0000u;
      break;
    case 7:
      v5 |= 0x1A0000u;
      break;
    case 8:
      v5 |= 0x1B0000u;
      break;
    case 9:
      v5 |= 0x1B0000u;
      break;
    default:
      break;
  }
  MEMORY[0x2060000C] = (a1 << 24) | v5;
  return 543162380;
}


/* ===== sub_101DE4 @ 0x101DE4 (file 0x1DE4) size 568 ===== */
char *__fastcall sub_101DE4(unsigned int a1, _BYTE *a2)
{
  char *v2; // kr08_8
  char *result; // x0
  __int64 v4; // kr00_8
  int v5; // [xsp+10h] [xbp-10h]
  int v6; // [xsp+14h] [xbp-Ch]
  int v7; // [xsp+18h] [xbp-8h]
  __int16 v8; // [xsp+1Ch] [xbp-4h]

  v5 = MEMORY[0x20600010];
  v6 = MEMORY[0x20600014];
  v7 = MEMORY[0x20600018];
  v8 = MEMORY[0x2060001C];
  v2 = (char *)a1;
  v4 = a1;
  result = (char *)&loc_101E54 + 4 * jpt_101E50[a1];
  switch ( v4 )
  {
    case 0LL:
      return result;
    case 1LL:
    case 3LL:
    case 4LL:
    case 5LL:
    case 6LL:
    case 7LL:
    case 8LL:
    case 9LL:
      *a2 = MEMORY[0x20600013];
      a2[1] = BYTE2(v5);
      a2[2] = BYTE1(v5);
      a2[3] = v5;
      result = a2 + 3;
      break;
    case 2LL:
      *a2 = MEMORY[0x2060001E];
      a2[1] = HIBYTE(v8);
      a2[2] = v8;
      a2[3] = HIBYTE(v7);
      a2[4] = BYTE2(v7);
      a2[5] = BYTE1(v7);
      a2[6] = v7;
      a2[7] = HIBYTE(v6);
      a2[8] = BYTE2(v6);
      a2[9] = BYTE1(v6);
      a2[10] = v6;
      a2[11] = HIBYTE(v5);
      a2[12] = BYTE2(v5);
      a2[13] = BYTE1(v5);
      a2[14] = v5;
      result = a2 + 14;
      break;
    default:
      result = v2;
      break;
  }
  return result;
}


/* ===== sub_10201C @ 0x10201C (file 0x201C) size 924 ===== */
__int64 __fastcall sub_10201C(unsigned int a1, int a2, __int64 a3, _BYTE *a4)
{
  __int64 v4; // x0
  __int64 v6; // x0
  unsigned int v11; // [xsp+3Ch] [xbp+3Ch]
  int v12; // [xsp+40h] [xbp+40h]
  unsigned int v13; // [xsp+44h] [xbp+44h]
  int i; // [xsp+48h] [xbp+48h]
  int v15; // [xsp+4Ch] [xbp+4Ch]

  v13 = 500;
  sub_1019B4(-1, 0);
  sub_10194C(-1, 0);
  sub_101A1C(-1);
  sub_101A5C(8u);
  v15 = qword_102D00[3 * a1 + 1];
  if ( LODWORD(qword_102D00[3 * a1 + 2]) != 0 )
    v15 |= 0x8000u;
  if ( a3 != 0 )
    v15 |= 8u;
  sub_10194C(LODWORD(qword_102D00[3 * a1 + 2]) | v15, 1);
  sub_1019B4(LODWORD(qword_102D00[3 * a1 + 2]) | v15, 1);
  if ( a3 != 0 )
  {
    sub_101B00(*(_DWORD *)(a3 + 8));
    sub_101B20(*(_DWORD *)(a3 + 12));
    sub_101AB0(*(_QWORD *)a3);
    v13 = 4000;
  }
  sub_101B3C(a2);
  v4 = sub_101B5C(
         HIDWORD(qword_102D00[3 * a1]),
         HIDWORD(qword_102D00[3 * a1 + 2]),
         0,
         HIDWORD(qword_102D00[3 * a1 + 1]));
  v12 = sub_10D9B0(v4);
  for ( i = v12; i - v12 < v13; i = sub_10D9B0(v6) )
  {
    v11 = sub_101A3C();
    if ( (qword_102D00[3 * a1 + 2] & v11) != 0 )
    {
      sub_101A1C(LODWORD(qword_102D00[3 * a1 + 2]) | v15);
      return qword_102D00[3 * a1 + 2] & v11;
    }
    v6 = qword_102D00[3 * a1 + 1] & v11;
    if ( LODWORD(qword_102D00[3 * a1 + 1]) == (_DWORD)v6 )
    {
      sub_101A1C(LODWORD(qword_102D00[3 * a1 + 2]) | v15);
      sub_101DE4(HIDWORD(qword_102D00[3 * a1 + 1]), a4);
      return 0;
    }
  }
  return 0xFFFFFFFFLL;
}


/* ===== sub_1023B8 @ 0x1023B8 (file 0x23B8) size 16 ===== */
void sub_1023B8()
{
  ;
}


/* ===== sub_1023C8 @ 0x1023C8 (file 0x23C8) size 56 ===== */
bool sub_1023C8()
{
  char v1; // [xsp+10h] [xbp+10h] BYREF

  return (unsigned int)sub_10201C(0, 0, 0, &v1) == 0;
}


/* ===== sub_102400 @ 0x102400 (file 0x2400) size 196 ===== */
__int64 __fastcall sub_102400(__int64 a1)
{
  __int64 v2; // x0
  _BYTE v3[16]; // [xsp+18h] [xbp+18h] BYREF
  int v4; // [xsp+28h] [xbp+28h]
  int v5; // [xsp+2Ch] [xbp+2Ch]

  v5 = sub_10D9B0(a1);
  v4 = v5;
  do
  {
    if ( (unsigned int)sub_10201C(1u, 1090486400, 0, v3) != 0 )
      return 0;
    v2 = v3[0];
    if ( (int)v2 < 0 )
    {
      MEMORY[0x2000] = (v3[0] & 0x40) != 0;
      return 1;
    }
    v4 = sub_10D9B0(v2);
  }
  while ( (unsigned int)(v4 - v5) <= 0xFA0 );
  return 0;
}


/* ===== sub_1024C4 @ 0x1024C4 (file 0x24C4) size 56 ===== */
bool sub_1024C4()
{
  char v1; // [xsp+10h] [xbp+10h] BYREF

  return (unsigned int)sub_10201C(2u, 0, 0, &v1) == 0;
}


/* ===== sub_1024FC @ 0x1024FC (file 0x24FC) size 84 ===== */
__int64 __fastcall sub_1024FC(_WORD *a1)
{
  char v3; // [xsp+20h] [xbp+20h] BYREF

  if ( (unsigned int)sub_10201C(3u, 0x10000, 0, &v3) != 0 )
    return 0;
  if ( a1 != nullptr )
    *a1 = 1;
  return 1;
}


/* ===== sub_102550 @ 0x102550 (file 0x2550) size 84 ===== */
bool __fastcall sub_102550(unsigned __int16 a1)
{
  _BYTE v2[20]; // [xsp+28h] [xbp+28h] BYREF
  int v3; // [xsp+3Ch] [xbp+3Ch]

  v3 = a1 << 16;
  return (unsigned int)sub_10201C(6u, v3, 0, v2) == 0;
}


/* ===== sub_1025A4 @ 0x1025A4 (file 0x25A4) size 84 ===== */
bool __fastcall sub_1025A4(unsigned __int16 a1)
{
  _BYTE v2[20]; // [xsp+28h] [xbp+28h] BYREF
  int v3; // [xsp+3Ch] [xbp+3Ch]

  v3 = a1 << 16;
  return (unsigned int)sub_10201C(5u, v3, 0, v2) == 0;
}


/* ===== sub_1025F8 @ 0x1025F8 (file 0x25F8) size 164 ===== */
__int64 sub_1025F8()
{
  _BYTE v1[2]; // [xsp+10h] [xbp+10h] BYREF
  char v2; // [xsp+12h] [xbp+12h]
  int v3; // [xsp+24h] [xbp+24h]
  int v4; // [xsp+28h] [xbp+28h]
  unsigned int v5; // [xsp+2Ch] [xbp+2Ch]

  v5 = MEMORY[0x2004] << 16;
  v4 = sub_10D9B0(v5);
  v3 = v4;
  do
  {
    if ( (unsigned int)sub_10201C(8u, v5, 0, v1) != 0 )
      return 0;
    if ( (v2 & 1) != 0 )
      return 1;
    v3 = sub_10D9B0(v2 & 1);
  }
  while ( (unsigned int)(v3 - v4) <= 0xFA0 );
  return 0;
}


/* ===== sub_10269C @ 0x10269C (file 0x269C) size 88 ===== */
bool __fastcall sub_10269C(int a1)
{
  char v3; // [xsp+20h] [xbp+20h] BYREF

  if ( MEMORY[0x2000] != 0 )
    a1 = 512;
  return (unsigned int)sub_10201C(9u, a1, 0, &v3) == 0;
}


/* ===== sub_1026F4 @ 0x1026F4 (file 0x26F4) size 220 ===== */
bool sub_1026F4()
{
  _BOOL8 v0; // x0

  v0 = sub_1023C8();
  if ( !v0 )
    return false;
  if ( (unsigned int)sub_102400(v0) == 0 )
    return false;
  if ( !sub_1024C4() )
    return false;
  if ( (unsigned int)sub_1024FC((_WORD *)0x2004) == 0 )
    return false;
  if ( !sub_102550(MEMORY[0x2004]) )
    return false;
  if ( !sub_1025A4(MEMORY[0x2004]) )
    return false;
  if ( sub_10269C(512) )
    return (unsigned int)sub_10285C(0) != 0;
  return false;
}


/* ===== sub_1027D0 @ 0x1027D0 (file 0x27D0) size 140 ===== */
bool __fastcall sub_1027D0(int a1)
{
  _BYTE v2[16]; // [xsp+28h] [xbp+28h] BYREF
  int v3; // [xsp+38h] [xbp+38h]
  int v4; // [xsp+3Ch] [xbp+3Ch]

  v3 = 0;
  v4 = 0;
  if ( a1 != 0 )
  {
    if ( a1 == 1 )
      v4 = 18;
  }
  else
  {
    v4 = 9;
  }
  v3 = (v4 << 8) | 0x3B30001;
  return (unsigned int)sub_10201C(4u, v3, 0, v2) == 0;
}


/* ===== sub_10285C @ 0x10285C (file 0x285C) size 116 ===== */
__int64 __fastcall sub_10285C(unsigned int a1)
{
  _BYTE v3[20]; // [xsp+28h] [xbp+28h] BYREF
  unsigned int v4; // [xsp+3Ch] [xbp+3Ch]

  v4 = (a1 << 8) | 0x3B70000;
  if ( (unsigned int)sub_10201C(4u, v4, 0, v3) != 0 )
    return 0;
  sub_1028D0(a1);
  return 1;
}


/* ===== sub_1028D0 @ 0x1028D0 (file 0x28D0) size 128 ===== */
__int64 __fastcall sub_1028D0(int a1)
{
  unsigned int v2; // [xsp+1Ch] [xbp-4h]

  v2 = MEMORY[0x20600028] & 0xFFFFFFDD;
  if ( a1 == 1 )
  {
    v2 |= 2u;
  }
  else if ( a1 == 2 )
  {
    v2 |= 0x20u;
  }
  MEMORY[0x20600028] = v2;
  return 543162408;
}


/* ===== sub_102950 @ 0x102950 (file 0x2950) size 252 ===== */
bool __fastcall sub_102950(int a1, int a2, int a3, __int64 a4)
{
  _QWORD v8[2]; // [xsp+38h] [xbp+38h] BYREF
  _BYTE v9[20]; // [xsp+48h] [xbp+48h] BYREF
  int v10; // [xsp+5Ch] [xbp+5Ch]

  if ( !sub_1027D0(a1) )
    return false;
  if ( (unsigned int)sub_1025F8() == 0 )
    return false;
  if ( MEMORY[0x2000] != 0 )
    v10 = a2;
  else
    v10 = a2 << 9;
  LODWORD(v8[1]) = 512;
  HIDWORD(v8[1]) = a3;
  v8[0] = a4;
  if ( (unsigned int)sub_10201C(0xBu, v10, (__int64)v8, v9) == 0 )
    return (unsigned int)sub_10201C(7u, 0, 0, v9) == 0;
  sub_10201C(7u, 0, 0, v9);
  return false;
}


/* ===== sub_102A4C @ 0x102A4C (file 0x2A4C) size 232 ===== */
bool __fastcall sub_102A4C(int a1, int a2, int a3, __int64 a4)
{
  _QWORD v8[2]; // [xsp+38h] [xbp+38h] BYREF
  _BYTE v9[20]; // [xsp+48h] [xbp+48h] BYREF
  int v10; // [xsp+5Ch] [xbp+5Ch]

  if ( !sub_1027D0(a1) )
    return false;
  if ( MEMORY[0x2000] != 0 )
    v10 = a2;
  else
    v10 = a2 << 9;
  LODWORD(v8[1]) = 512;
  HIDWORD(v8[1]) = a3;
  v8[0] = a4;
  if ( (unsigned int)sub_10201C(0xEu, v10, (__int64)v8, v9) == 0 )
    return (unsigned int)sub_10201C(7u, 0, 0, v9) == 0;
  sub_10201C(7u, 0, 0, v9);
  return false;
}


/* ===== sub_102B34 @ 0x102B34 (file 0x2B34) size 456 ===== */
__int64 __fastcall sub_102B34(int a1, __int64 a2, int a3)
{
  __int64 v4; // x0
  _BYTE v8[20]; // [xsp+28h] [xbp+28h] BYREF
  int v9; // [xsp+3Ch] [xbp+3Ch]
  int v10; // [xsp+40h] [xbp+40h]
  int v11; // [xsp+44h] [xbp+44h]
  unsigned int v12; // [xsp+48h] [xbp+48h]
  int v13; // [xsp+4Ch] [xbp+4Ch]

  v13 = 0;
  if ( (unsigned int)sub_10201C(0, -252645136, 0, v8) != 0 )
    return 0;
  sub_1019B4(-1, 0);
  sub_10194C(-1, 0);
  sub_101A5C(0xEu);
  MEMORY[0x20600030] = 7372811;
  MEMORY[0x20600034] = 7340043;
  v13 = 7340043;
  MEMORY[0x20600038] = 7340043;
  sub_101B00(512);
  sub_101B20(a1);
  sub_101AB0(a2);
  if ( a3 != 0 )
  {
    v13 = 1075839027;
  }
  else
  {
    MEMORY[0x20600008] = -6;
    v13 = 2097203;
  }
  MEMORY[0x2060000C] = v13;
  if ( a3 != 0 )
  {
    v4 = 2;
    v12 = 2;
  }
  else
  {
    v4 = 3;
    v12 = 3;
  }
  v10 = sub_10D9B0(v4);
  v11 = v10;
  v13 = 0;
  v9 = 7372800;
  while ( (unsigned int)(v11 - v10) <= 0x7CF )
  {
    v13 = MEMORY[0x20600030];
    if ( (MEMORY[0x20600030] & v9) != 0 )
      return 0;
    if ( (v13 & v12) == v12 )
      return 1;
    v11 = sub_10D9B0(v12);
  }
  return 0;
}


/* ===== sub_102ED0 @ 0x102ED0 (file 0x2ED0) size 720 ===== */
__int64 __fastcall sub_102ED0(unsigned int a1)
{
  __int64 result; // x0
  unsigned int v3; // [xsp+24h] [xbp+24h]
  int v4; // [xsp+28h] [xbp+28h]
  unsigned int v5; // [xsp+2Ch] [xbp+2Ch]
  unsigned int j; // [xsp+30h] [xbp+30h]
  unsigned int i; // [xsp+34h] [xbp+34h]
  unsigned int v8; // [xsp+38h] [xbp+38h]
  int v9; // [xsp+3Ch] [xbp+3Ch]

  result = a1 & 0xFFFFFF00;
  if ( (_DWORD)result == 0 )
  {
    sub_10FA50(MEMORY[0x1320], 0, 272);
    v5 = a1 >> 4;
    for ( i = 0; i <= 0x3F; ++i )
    {
      switch ( i & 3 )
      {
        case 0u:
          v9 = 13;
          break;
        case 1u:
          v9 = 17;
          break;
        case 2u:
          v9 = 19;
          break;
        case 3u:
          v9 = 23;
          break;
      }
      for ( j = 0; v9 - 1 >= j; ++j )
      {
        if ( (*((_DWORD *)qword_103B10 + i) & (1 << j)) != 0 )
          *(_DWORD *)(MEMORY[0x1320] + 4LL * i) |= 1 << (v9 - j - 1);
      }
      if ( v5 != 0 )
      {
        if ( v9 - 1 >= v5 )
          v8 = a1 >> 4;
        else
          LOBYTE(v8) = v5 - v9;
        v4 = ((1 << v9) - 1) >> v8;
        v3 = (*(_DWORD *)(MEMORY[0x1320] + 4LL * i) & (unsigned int)~v4) >> (v9 - v8);
        *(_DWORD *)(MEMORY[0x1320] + 4LL * i) &= v4;
        *(_DWORD *)(MEMORY[0x1320] + 4LL * i) <<= v8;
        *(_DWORD *)(MEMORY[0x1320] + 4LL * i) |= v3;
      }
    }
    *(_DWORD *)(MEMORY[0x1320] + 256LL) = *MEMORY[0x1320];
    *(_DWORD *)(MEMORY[0x1320] + 260LL) = *(_DWORD *)(MEMORY[0x1320] + 4LL);
    *(_DWORD *)(MEMORY[0x1320] + 264LL) = *(_DWORD *)(MEMORY[0x1320] + 8LL);
    result = MEMORY[0x1320];
    *(_DWORD *)(MEMORY[0x1320] + 268LL) = *(_DWORD *)(MEMORY[0x1320] + 12LL);
  }
  return result;
}


/* ===== sub_1031A0 @ 0x1031A0 (file 0x31A0) size 300 ===== */
__int64 __fastcall sub_1031A0(__int64 a1, _DWORD *a2)
{
  *(_BYTE *)(a1 + 16) = a2[90];
  *(_DWORD *)(a1 + 20) = a2[84];
  *(_DWORD *)(a1 + 68) = a2[85];
  *(_DWORD *)(a1 + 24) = a2[86];
  *(_BYTE *)(a1 + 28) = a2[89];
  *(_BYTE *)(a1 + 29) = a2[87];
  *(_BYTE *)(a1 + 30) = a2[91];
  *(_BYTE *)(a1 + 31) = a2[92];
  *(_BYTE *)(a1 + 32) = a2[90];
  *(_BYTE *)(a1 + 33) = a2[88];
  *(_WORD *)(a1 + 34) = a2[83];
  sub_10FAA4(a1 + 36, a2 + 122, 20);
  *(_DWORD *)(a1 + 56) = a2[120];
  *(_DWORD *)(a1 + 60) = a2[121];
  return 1;
}


/* ===== sub_1032CC @ 0x1032CC (file 0x32CC) size 236 ===== */
__int64 __fastcall sub_1032CC(__int64 a1)
{
  _QWORD v3[5]; // [xsp+20h] [xbp+20h] BYREF
  int v4; // [xsp+4Ch] [xbp+4Ch]
  __int64 v5; // [xsp+50h] [xbp+50h]
  __int64 v6; // [xsp+58h] [xbp+58h]

  v6 = MEMORY[0x1370];
  v5 = a1;
  sub_10D4FC(MEMORY[0x1370], 0, 108);
  sub_10D4C8(v6, v5 + 372, 108);
  sub_10D4FC(v5 + 372, 0, 108);
  sub_10D4FC(v3, 0, 40);
  v3[0] = 108;
  LODWORD(v3[4]) = 512;
  v3[2] = a1;
  LOBYTE(v3[1]) = 11;
  v3[3] = MEMORY[0x1370];
  v4 = sub_104DD0(v3);
  if ( v4 != 0 )
    return 5;
  else
    return 0;
}


/* ===== sub_1033B8 @ 0x1033B8 (file 0x33B8) size 600 ===== */
__int64 __fastcall sub_1033B8(_DWORD **a1, __int64 a2, unsigned int a3)
{
  _DWORD *v7; // [xsp+48h] [xbp+48h]
  unsigned int v8; // [xsp+54h] [xbp+54h]
  int v9; // [xsp+54h] [xbp+54h]
  unsigned int j; // [xsp+58h] [xbp+58h]
  unsigned int i; // [xsp+5Ch] [xbp+5Ch]

  sub_10DF40(0x1000000000000LL);
  for ( i = 0; i < a3; ++i )
  {
    sub_103F34(*((unsigned __int16 *)a1 + 32));
    v8 = sub_104308(*((unsigned __int16 *)a1 + 32));
    if ( v8 != 0 )
      return v8;
    v7 = (_DWORD *)(a2 + 16LL * i);
    if ( v7[3] != 512 || *((_WORD *)a1 + 33) != 0 )
    {
      *((_WORD *)a1 + 17) = 512;
      *((_BYTE *)a1 + 16) = 4;
    }
    else
    {
      *((_WORD *)a1 + 17) = 512;
      *((_BYTE *)a1 + 16) = 1;
    }
    *a1 = (_DWORD *)20480;
    a1[1] = (_DWORD *)0xFFFFFFFFLL;
    if ( v7[2] == 3 && *((_WORD *)a1 + 33) != 0 )
      *((_DWORD *)a1 + 5) = 5;
    else
      *((_DWORD *)a1 + 5) = v7[2];
    *((_DWORD *)a1 + 17) = v7[1];
    sub_102ED0(0);
    sub_105174(MEMORY[0x1320]);
    for ( j = 0; j <= 8; ++j )
    {
      v9 = sub_104F28(a1, *((unsigned int *)qword_103AE8 + j));
      if ( v9 != 0 )
      {
        if ( v9 == 2 )
          break;
      }
      else if ( (unsigned int)sub_1032CC((__int64)*a1) == 0
             && **a1 == 1112819780
             && (*a1)[1] == 1
             && (unsigned __int8)sub_1031A0((__int64)a1, *a1) != 0 )
      {
        sub_10DF40(0x2000000000000LL);
        return 0;
      }
    }
  }
  sub_10DF40(0x4000000000000LL);
  return 1;
}


/* ===== sub_103610 @ 0x103610 (file 0x3610) size 560 ===== */
__int64 __fastcall sub_103610(__int64 a1, int a2, int a3)
{
  int v6; // [xsp+24h] [xbp+24h]
  int v7; // [xsp+2Ch] [xbp+2Ch]
  unsigned int v8; // [xsp+30h] [xbp+30h]
  int v9; // [xsp+34h] [xbp+34h]
  unsigned int v10; // [xsp+38h] [xbp+38h]
  unsigned int v11; // [xsp+3Ch] [xbp+3Ch]
  unsigned int v12; // [xsp+3Ch] [xbp+3Ch]
  unsigned int v13; // [xsp+40h] [xbp+40h]
  unsigned int v14; // [xsp+44h] [xbp+44h]
  __int64 v15; // [xsp+48h] [xbp+48h]

  v14 = 0;
  v9 = 4;
  v15 = 20480;
  v11 = a2 << *(_DWORD *)(a1 + 56);
  if ( *(unsigned __int8 *)(a1 + 16) * *(unsigned __int16 *)(a1 + 34) == 512 )
    v12 = v11 >> 8;
  else
    v12 = v11 >> *(_DWORD *)(a1 + 60);
  v10 = v12;
  v7 = *(_DWORD *)(a1 + 36);
  v8 = 0x10000 / *(unsigned __int16 *)(a1 + 34);
  while ( 1 )
  {
    *(_QWORD *)a1 = v15;
    if ( v8 - v14 <= *(unsigned __int8 *)(a1 + 16) )
      v13 = v8 - v14;
    else
      v13 = *(unsigned __int8 *)(a1 + 16);
    sub_102ED0(v10 - v12);
    sub_105174(16LL * (v10 & 0xF) + MEMORY[0x1320]);
    v6 = sub_104520(a1, v10, v13);
    if ( v6 == 2 )
      return 2;
    if ( a3 != 0 && v6 == 5 )
      return 5;
    v14 += v13;
    if ( v14 >= v8 )
      break;
    if ( v7 != 0 )
      v10 = *(unsigned __int8 *)(a1 + (unsigned int)++v9 + 36) + v12;
    else
      ++v10;
    v15 += *(unsigned __int16 *)(a1 + 34) * v13;
  }
  return 0;
}


/* ===== sub_103840 @ 0x103840 (file 0x3840) size 224 ===== */
__int64 __fastcall sub_103840(__int64 a1)
{
  unsigned int i; // [xsp+28h] [xbp+28h]
  unsigned int v4; // [xsp+2Ch] [xbp+2Ch]

  sub_10DF40(0x40000000000000LL);
  sub_103F34(*(unsigned __int16 *)(a1 + 64));
  v4 = sub_104308(*(unsigned __int16 *)(a1 + 64));
  if ( v4 == 2 )
    return 2;
  for ( i = 0; i <= 2; ++i )
  {
    v4 = sub_103610(a1, i, 1);
    switch ( v4 )
    {
      case 0u:
        sub_10DF40(0x8000000000000LL);
        return 0;
      case 2u:
        sub_10DF40(0x10000000000000LL);
        return 2;
      case 5u:
        sub_10DF40(0x20000000000000LL << i);
        break;
      default:
        break;
    }
  }
  return v4;
}


/* ===== sub_103920 @ 0x103920 (file 0x3920) size 324 ===== */
bool sub_103920()
{
  _DWORD *v1[8]; // [xsp+18h] [xbp+18h] BYREF
  int v2; // [xsp+58h] [xbp+58h]
  int v3; // [xsp+64h] [xbp+64h]
  int v4; // [xsp+68h] [xbp+68h]
  unsigned int i; // [xsp+6Ch] [xbp+6Ch]

  v3 = 1;
  v4 = 1;
  sub_10D4FC(v1, 0, 72);
  switch ( *MEMORY[0x1300] )
  {
    case 1:
      v2 = 0x10000;
      break;
    case 2:
      v2 = 0x20000;
      break;
    case 3:
      v2 = 65538;
      break;
    case 4:
      v2 = 131074;
      break;
    default:
      break;
  }
  for ( i = 0; i <= 1; ++i )
  {
    v3 = sub_1033B8(v1, (__int64)qword_103A68, 8u);
    if ( v3 == 0 )
      v4 = sub_103840((__int64)v1);
    if ( v4 == 0 )
      break;
  }
  return v4 == 0;
}


/* ===== sub_103C30 @ 0x103C30 (file 0x3C30) size 160 ===== */
__int64 __fastcall sub_103C30(int a1)
{
  unsigned int i; // [xsp+1Ch] [xbp-4h]

  if ( a1 != 0 )
  {
    MEMORY[0x20E00000] |= 0x400u;
    MEMORY[0x20E00004] |= 0x80u;
    for ( i = 0; i <= 0xFE; ++i )
      ;
    MEMORY[0x20E00004] &= ~0x80u;
    return 551550980;
  }
  else
  {
    MEMORY[0x20E00000] &= ~0x400u;
    return 551550976;
  }
}


/* ===== sub_103CD0 @ 0x103CD0 (file 0x3CD0) size 556 ===== */
__int64 sub_103CD0()
{
  MEMORY[0x402A00F0] = 16;
  MEMORY[0x402A00DC] = 16;
  MEMORY[0x402A00D8] = 16;
  MEMORY[0x402A00C8] = 16;
  MEMORY[0x402A00EC] = 16;
  MEMORY[0x402A00C4] = 16;
  MEMORY[0x402A00D4] = 16;
  MEMORY[0x402A00D0] = 16;
  MEMORY[0x402A00B4] = 16;
  MEMORY[0x402A00E4] = 16;
  MEMORY[0x402A00E8] = 16;
  MEMORY[0x402A00E0] = 16;
  MEMORY[0x402A00C0] = 16;
  MEMORY[0x402A00B0] = 16;
  MEMORY[0x402A00B8] = 16;
  MEMORY[0x402A00AC] = 16;
  MEMORY[0x402A00CC] = 16;
  MEMORY[0x402A04F0] = 1572864;
  MEMORY[0x402A04DC] = 1572992;
  MEMORY[0x402A04D8] = 1572864;
  MEMORY[0x402A04C8] = 1572864;
  MEMORY[0x402A04EC] = 1572864;
  MEMORY[0x402A04C4] = 1572864;
  MEMORY[0x402A04D0] = 1572864;
  MEMORY[0x402A04B4] = 1572864;
  MEMORY[0x402A04E4] = 1572864;
  MEMORY[0x402A04E8] = 1572864;
  MEMORY[0x402A04E0] = 1572864;
  MEMORY[0x402A04C0] = 1572864;
  MEMORY[0x402A04B0] = 1572864;
  MEMORY[0x402A04B8] = 1572864;
  MEMORY[0x402A04AC] = 1572864;
  MEMORY[0x402A04CC] = 1572864;
  MEMORY[0x402A04D4] = 1577088;
  return 1076495572;
}


/* ===== sub_103EFC @ 0x103EFC (file 0x3EFC) size 56 ===== */
__int64 __fastcall sub_103EFC(__int64 result)
{
  MEMORY[0x21500078] = 6;
  result = (unsigned int)result;
  if ( (_DWORD)result == 2 )
  {
    MEMORY[0x21500078] = 0;
    return 558891128;
  }
  return result;
}


/* ===== sub_103F34 @ 0x103F34 (file 0x3F34) size 352 ===== */
__int64 __fastcall sub_103F34(unsigned int a1)
{
  __int64 v1; // x0
  __int64 result; // x0

  sub_103C30(1);
  v1 = sub_103CD0();
  sub_10D2C0(v1);
  sub_103EFC(a1);
  sub_10FA50(564134400, 0, 128);
  MEMORY[0x21A000DC] = 6;
  MEMORY[0x21A000F8] = 65918;
  MEMORY[0x21A000E0] = 319;
  MEMORY[0x21A000E4] = 319;
  MEMORY[0x21A000E8] = 319;
  MEMORY[0x21A000EC] = 0;
  MEMORY[0x21A00014] = 977875143;
  MEMORY[0x21A00018] = 421527552;
  MEMORY[0x21A0001C] = 0;
  result = a1;
  if ( a1 == 2 )
  {
    MEMORY[0x21A000F8] = 67174783;
    MEMORY[0x21A000E0] = 48;
    MEMORY[0x21A000E4] = 48;
    MEMORY[0x21A000E8] = 48;
    MEMORY[0x21A000EC] = 1024;
    MEMORY[0x21A00014] = 943659266;
    MEMORY[0x21A00018] = 63569920;
    MEMORY[0x21A0001C] = 0;
    return 564133916;
  }
  return result;
}


/* ===== sub_104094 @ 0x104094 (file 0x4094) size 16 ===== */
unsigned __int64 sub_104094()
{
  MEMORY[0x2008] = 0;
  return 0x2008u;
}


/* ===== sub_1040A4 @ 0x1040A4 (file 0x40A4) size 232 ===== */
unsigned __int64 __fastcall sub_1040A4(unsigned __int16 a1)
{
  int v2; // [xsp+1Ch] [xbp-4h]
  unsigned int v3; // [xsp+1Ch] [xbp-4h]

  v2 = *(_DWORD *)(4 * (unsigned int)(MEMORY[0x2008] >> 1) + 0x21A00220LL);
  if ( (MEMORY[0x2008] & 1) != 0 )
    v3 = (unsigned __int16)v2 | (a1 << 16);
  else
    v3 = v2 & 0xFFFF0000 | a1;
  *(_DWORD *)(4 * (unsigned int)(MEMORY[0x2008]++ >> 1) + 0x21A00220LL) = v3;
  return 0x2008u;
}


/* ===== sub_10418C @ 0x10418C (file 0x418C) size 36 ===== */
__int64 sub_10418C()
{
  MEMORY[0x21A00010] |= 0x7F00u;
  return 0;
}


/* ===== sub_1041B0 @ 0x1041B0 (file 0x41B0) size 136 ===== */
__int64 __fastcall sub_1041B0(__int64 a1)
{
  __int64 v1; // x0
  unsigned int v3; // [xsp+1Ch] [xbp+1Ch]
  int v4; // [xsp+24h] [xbp+24h]
  int v5; // [xsp+28h] [xbp+28h]
  unsigned int v6; // [xsp+2Ch] [xbp+2Ch]

  v3 = a1;
  v6 = 0;
  v5 = 0;
  v1 = sub_10D9B0(a1);
  v4 = v1;
  do
  {
    if ( (unsigned int)sub_10D9B0(v1) - v4 >= v3 )
      break;
    v5 = MEMORY[0x21A00010];
    v1 = MEMORY[0x21A00010] & 0x1000000;
  }
  while ( (_DWORD)v1 == 0 );
  if ( (v5 & 0x1000000) == 0 )
    v6 = 2;
  sub_10418C();
  return v6;
}


/* ===== sub_104238 @ 0x104238 (file 0x4238) size 136 ===== */
__int64 __fastcall sub_104238(int a1)
{
  if ( ((*(_DWORD *)(2 * ((a1 & 0xFFFFFFFE) + 282066976)) >> (16 * (a1 & 1))) & 0x1FF) == 0x1FF )
    return 5;
  else
    return 0;
}


/* ===== sub_1042C0 @ 0x1042C0 (file 0x42C0) size 72 ===== */
__int64 __fastcall sub_1042C0(unsigned int a1)
{
  if ( a1 == 512 )
    return 3;
  else
    return 20 * (a1 >> 9);
}


/* ===== sub_104308 @ 0x104308 (file 0x4308) size 296 ===== */
__int64 __fastcall sub_104308(int a1)
{
  __int64 v1; // x0
  __int64 v2; // x0
  int v5; // [xsp+24h] [xbp+24h]
  int v6; // [xsp+24h] [xbp+24h]
  int i; // [xsp+2Ch] [xbp+2Ch]

  sub_104094();
  sub_1040A4(0xFFCDu);
  sub_1040A4(0xFFu);
  MEMORY[0x21A00008] = a1 << 12;
  sub_10418C();
  MEMORY[0x21A00004] = 2;
  MEMORY[0x21A00000] = 1;
  v1 = sub_10D9B0(564133888);
  v5 = v1;
  do
    v1 = (unsigned int)sub_10D9B0(v1) - v5;
  while ( (unsigned int)v1 <= 1 );
  v6 = sub_10D9B0(v1);
  for ( i = v6; (unsigned int)(i - v6) <= 4; i = sub_10D9B0(v2) )
  {
    v2 = MEMORY[0x21A00000] & 0x40000000;
    if ( (_DWORD)v2 != 0 )
      break;
  }
  if ( (MEMORY[0x21A00010] & 0x1000000) != 0 )
    return 0;
  MEMORY[0x21A00000] |= 2u;
  return 2;
}


/* ===== sub_104430 @ 0x104430 (file 0x4430) size 240 ===== */
unsigned __int64 __fastcall sub_104430(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned __int64 result; // x0
  unsigned int v5; // [xsp+10h] [xbp+10h]

  sub_1040A4(((_WORD)a2 << 8) | 0xA0);
  sub_1040A4(((unsigned __int16)(a2 >> 8) << 8) | 0xA0);
  sub_1040A4(((_WORD)a3 << 8) | 0xA0);
  v5 = a3 >> 8;
  sub_1040A4(((_WORD)v5 << 8) | 0xA0);
  result = *(unsigned int *)(a1 + 20);
  if ( (_DWORD)result == 5 )
    return sub_1040A4(((unsigned __int16)(v5 >> 8) << 8) | 0xA0u);
  return result;
}


/* ===== sub_104520 @ 0x104520 (file 0x4520) size 1188 ===== */
__int64 __fastcall sub_104520(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int v6; // [xsp+14h] [xbp+14h]
  unsigned int v8; // [xsp+28h] [xbp+28h]
  int v9; // [xsp+30h] [xbp+30h]
  int v10; // [xsp+34h] [xbp+34h]
  unsigned int v11; // [xsp+3Ch] [xbp+3Ch]
  int v12; // [xsp+40h] [xbp+40h]
  int v13; // [xsp+40h] [xbp+40h]
  unsigned int i; // [xsp+44h] [xbp+44h]
  unsigned int v15; // [xsp+48h] [xbp+48h]
  unsigned int v16; // [xsp+4Ch] [xbp+4Ch]

  v12 = 0;
  v11 = *(unsigned __int8 *)(a1 + 16) * *(unsigned __int16 *)(a1 + 34);
  v8 = sub_1042C0(v11);
  sub_104094();
  if ( v11 == 512 )
  {
    sub_1040A4(0xCDu);
    sub_1040A4(0xA0u);
    sub_1040A4(((_WORD)a2 << 8) | 0xA0);
    v6 = a2 >> 8;
    sub_1040A4(((_WORD)v6 << 8) | 0xA0);
    if ( *(_DWORD *)(a1 + 20) == 4 )
      sub_1040A4(((unsigned __int16)(v6 >> 8) << 8) | 0xA0);
    sub_1040A4(0xB0u);
    sub_1040A4(0xD0u);
    sub_1040A4(0xD2u);
  }
  else
  {
    v15 = v11;
    if ( *(_DWORD *)(a1 + 24) == 1 )
      v15 = v11 >> 1;
    if ( *(_WORD *)(a1 + 66) == 2 )
      sub_1040A4(0xA2CDu);
    sub_1040A4(0xCDu);
    sub_104430(a1, v15, a2);
    sub_1040A4(0x30CDu);
    sub_1040A4(0xB0u);
    if ( *(_WORD *)(a1 + 66) == 2 )
    {
      sub_1040A4(0x5CDu);
      if ( *(_DWORD *)(a1 + 68) == 1 )
      {
        sub_104430(a1, v15, a2);
      }
      else
      {
        sub_1040A4(((_WORD)v15 << 8) | 0xA0);
        sub_1040A4(((unsigned __int16)(v15 >> 8) << 8) | 0xA0);
      }
      sub_1040A4(0xE0CDu);
    }
    sub_1040A4(0xD2u);
    sub_1040A4(0x5CDu);
    if ( *(_WORD *)(a1 + 66) == 2 && *(_DWORD *)(a1 + 68) == 1 )
    {
      sub_104430(a1, 0, a2);
    }
    else
    {
      sub_1040A4(0xA0u);
      sub_1040A4(0xA0u);
    }
    sub_1040A4(0xE0CDu);
    sub_1040A4(0xD0u);
    v12 = 64;
  }
  sub_1040A4(0xFFu);
  v13 = ((a3 - 1) << 24) | v12 | 0x34;
  if ( *(_DWORD *)(a1 + 24) != 0 )
    v13 |= 0x4000u;
  v10 = (*(unsigned __int16 *)(a1 + 34) - 1)
      | ((*(unsigned __int8 *)(a1 + 29) - 1) << 16)
      | (*(unsigned __int8 *)(a1 + 31) << 24)
      | (*(unsigned __int16 *)(a1 + 64) << 12);
  v9 = *(unsigned __int8 *)(a1 + 28) | (*(unsigned __int8 *)(a1 + 30) << 16) | ((a3 - 1) << 24);
  MEMORY[0x21A00000] = *(unsigned __int8 *)(a1 + 33) << 11;
  MEMORY[0x21A00004] = v13;
  MEMORY[0x21A00008] = v10;
  MEMORY[0x21A0000C] = v9;
  MEMORY[0x21A000F8] &= ~0x4000u;
  MEMORY[0x21A00200] = 0;
  MEMORY[0x21A00204] = *(_QWORD *)a1;
  MEMORY[0x21A00208] = -1;
  MEMORY[0x21A0020C] = -1;
  MEMORY[0x21A00210] = -1;
  MEMORY[0x21A00214] = -1;
  sub_10418C();
  MEMORY[0x21A00000] |= 1u;
  v16 = sub_1041B0(v8);
  if ( v16 != 2 )
  {
    for ( i = 0; i < a3; ++i )
    {
      v16 = sub_104238(i);
      if ( v16 == 5 )
        return 5;
    }
  }
  return v16;
}


/* ===== sub_1049C4 @ 0x1049C4 (file 0x49C4) size 672 ===== */
__int64 __fastcall sub_1049C4(__int64 a1)
{
  unsigned int v3; // [xsp+30h] [xbp+30h]
  int v4; // [xsp+34h] [xbp+34h]
  int v5; // [xsp+38h] [xbp+38h]
  int v6; // [xsp+3Ch] [xbp+3Ch]

  v3 = MEMORY[0x21A000F8] & 0xFFFFBFFF;
  sub_104094();
  sub_1040A4(0x1F0u);
  sub_1040A4(0xFFu);
  if ( *(_BYTE *)(a1 + 16) != 0 )
  {
    MEMORY[0x21A00200] = 0;
    MEMORY[0x21A00204] = *(_QWORD *)a1;
  }
  if ( *(_BYTE *)(a1 + 17) != 0 )
  {
    MEMORY[0x21A00208] = 0;
    MEMORY[0x21A0020C] = *(_QWORD *)(a1 + 8);
  }
  MEMORY[0x21A00004] = 2;
  MEMORY[0x21A00008] = 0;
  MEMORY[0x21A0000C] = 0;
  MEMORY[0x21A000F8] = v3;
  sub_10418C();
  MEMORY[0x21A00000] = 1;
  v5 = 0;
  v4 = 0;
  v6 = 65;
  if ( *(_BYTE *)(a1 + 18) != 0 )
    v6 = 321;
  if ( *(_BYTE *)(a1 + 16) != 0 )
  {
    v6 |= ((*(unsigned __int8 *)(a1 + 16) - 1) << 24) | 0x10;
    v5 = *(unsigned __int16 *)(a1 + 20) - 1;
    MEMORY[0x21A00200] = 0;
    MEMORY[0x21A00204] = *(_QWORD *)a1;
  }
  if ( *(_BYTE *)(a1 + 17) != 0 )
  {
    v6 |= 0x20u;
    v5 |= (*(unsigned __int16 *)(a1 + 22) - 1) << 16;
    v4 = (*(unsigned __int8 *)(a1 + 17) - 1) << 24;
    MEMORY[0x21A00208] = 0;
    MEMORY[0x21A0020C] = *(_QWORD *)(a1 + 8);
  }
  MEMORY[0x21A00004] = v6;
  MEMORY[0x21A00008] = v5;
  MEMORY[0x21A0000C] = v4;
  MEMORY[0x21A000F8] |= 0x4000u;
  sub_10418C();
  MEMORY[0x21A00000] = 8;
  return (unsigned int)sub_1041B0(4);
}


/* ===== sub_104C64 @ 0x104C64 (file 0x4C64) size 364 ===== */
__int64 __fastcall sub_104C64(unsigned __int16 *a1, int a2)
{
  int v3; // [xsp+30h] [xbp+30h]
  int v4; // [xsp+34h] [xbp+34h]
  int v5; // [xsp+3Ch] [xbp+3Ch]

  v5 = 67;
  if ( a2 != 0 )
    v5 = 323;
  v4 = (a1[2] << 24) | ((*a1 - 1) << 16) | (*((_DWORD *)a1 + 8) - 1);
  v3 = (a1[3] << 16) | a1[1];
  MEMORY[0x21A00000] = *((unsigned __int8 *)a1 + 8) << 11;
  MEMORY[0x21A00004] = v5;
  MEMORY[0x21A00008] = v4;
  MEMORY[0x21A0000C] = v3;
  MEMORY[0x21A000F8] |= 0x4000u;
  sub_10418C();
  MEMORY[0x21A00000] |= 8u;
  return (unsigned int)sub_1041B0(3);
}


/* ===== sub_104DD0 @ 0x104DD0 (file 0x4DD0) size 344 ===== */
__int64 __fastcall sub_104DD0(__int64 a1)
{
  _QWORD v3[3]; // [xsp+20h] [xbp+20h] BYREF
  int v4; // [xsp+3Ch] [xbp+3Ch]

  v4 = 0;
  memset(v3, 0, sizeof(v3));
  v3[0] = *(_QWORD *)(a1 + 16);
  LOWORD(v3[2]) = 257;
  v3[1] = *(_QWORD *)(a1 + 24);
  WORD2(v3[2]) = *(_DWORD *)(a1 + 32);
  HIWORD(v3[2]) = *(_WORD *)a1;
  BYTE2(v3[2]) = 1;
  sub_10418C();
  if ( (unsigned int)sub_1049C4((__int64)v3) == 2 )
    return 2;
  if ( (unsigned int)sub_104C64((unsigned __int16 *)a1, 0) == 2 )
    return 2;
  v4 = sub_104238(0);
  if ( v4 != 0 )
    return 5;
  v3[1] = *(_QWORD *)(a1 + 24);
  LOWORD(v3[2]) = 257;
  WORD2(v3[2]) = *(_DWORD *)(a1 + 32);
  HIWORD(v3[2]) = *(_WORD *)a1;
  BYTE2(v3[2]) = 0;
  sub_10418C();
  if ( (unsigned int)sub_1049C4((__int64)v3) == 2 )
    return 2;
  else
    return 0;
}


/* ===== sub_104F28 @ 0x104F28 (file 0x4F28) size 588 ===== */
__int64 __fastcall sub_104F28(__int64 a1, unsigned int a2)
{
  unsigned int v4; // [xsp+14h] [xbp+14h]
  int v6; // [xsp+28h] [xbp+28h]

  sub_104094();
  if ( *(unsigned __int8 *)(a1 + 16) * *(unsigned __int16 *)(a1 + 34) == 512 )
  {
    sub_1040A4(0xCDu);
    sub_1040A4(0xA0u);
    sub_1040A4(((_WORD)a2 << 8) | 0xA0);
    v4 = a2 >> 8;
    sub_1040A4(((_WORD)v4 << 8) | 0xA0);
    if ( *(_DWORD *)(a1 + 20) == 4 )
      sub_1040A4(((unsigned __int16)(v4 >> 8) << 8) | 0xA0);
    sub_1040A4(0xB0u);
    sub_1040A4(0xD0u);
  }
  else
  {
    if ( *(_WORD *)(a1 + 66) == 2 )
      sub_1040A4(0xA2CDu);
    sub_1040A4(0xCDu);
    sub_104430(a1, 0, a2);
    sub_1040A4(0x30CDu);
    sub_1040A4(0xB0u);
    if ( *(_WORD *)(a1 + 66) == 2 )
    {
      sub_1040A4(0x5CDu);
      if ( *(_DWORD *)(a1 + 68) == 1 )
      {
        sub_104430(a1, 0, a2);
      }
      else
      {
        sub_1040A4(0xA0u);
        sub_1040A4(0xA0u);
      }
      sub_1040A4(0xE0CDu);
    }
    sub_1040A4(0xD0u);
  }
  sub_1040A4(0xFFu);
  sub_10418C();
  v6 = (*(unsigned __int16 *)(a1 + 34) - 1) | (*(unsigned __int16 *)(a1 + 64) << 12);
  MEMORY[0x21A00004] = 80;
  MEMORY[0x21A00008] = v6;
  MEMORY[0x21A000F8] &= ~0x4000u;
  MEMORY[0x21A00200] = 0;
  MEMORY[0x21A00204] = *(_QWORD *)a1;
  MEMORY[0x21A00000] = 1;
  return (unsigned int)sub_1041B0(50);
}


/* ===== sub_105174 @ 0x105174 (file 0x5174) size 212 ===== */
__int64 __fastcall sub_105174(int a1)
{
  MEMORY[0x21A000B0] = 4109;
  MEMORY[0x21A000B4] = 65540;
  MEMORY[0x21A000B8] = 262163;
  MEMORY[0x21A000BC] = 4194320;
  MEMORY[0x21A00060] = 4109;
  MEMORY[0x21A00064] = 65540;
  MEMORY[0x21A00068] = 262163;
  MEMORY[0x21A0006C] = 4194320;
  MEMORY[0x21A00218] = 0;
  MEMORY[0x21A0021C] = a1;
  MEMORY[0x21A00038] = 3;
  return 564133944;
}


/* ===== sub_105248 @ 0x105248 (file 0x5248) size 92 ===== */
__int64 __fastcall sub_105248(__int64 a1, unsigned int a2)
{
  unsigned int i; // [xsp+1Ch] [xbp-4h]

  for ( i = 0; i < a2; ++i )
  {
    if ( *(_BYTE *)(a1 + i) != 0 )
      return 1;
  }
  return 0;
}


/* ===== sub_1052A4 @ 0x1052A4 (file 0x52A4) size 184 ===== */
__int64 sub_1052A4()
{
  __int64 v0; // x0
  unsigned int i; // [xsp+18h] [xbp+18h]
  unsigned int v3; // [xsp+1Ch] [xbp+1Ch]

  v3 = 0;
  sub_105908();
  sub_1063AC(1);
  for ( i = 0; i <= 3; ++i )
  {
    sub_105814(0);
    sub_105784(*(unsigned int *)(0x1018 + 4LL * i));
    sub_105814(1);
    v0 = sub_10D9D0(2);
    v3 = sub_10669C(v0);
    if ( v3 == 1 )
      break;
  }
  if ( v3 != 0 )
  {
    sub_10DF40(0x100000);
    sub_10E254(13);
  }
  else
  {
    sub_10DF40(0x200000);
    sub_10E254(12);
  }
  return v3;
}


/* ===== sub_10535C @ 0x10535C (file 0x535C) size 116 ===== */
__int64 sub_10535C()
{
  unsigned int v1; // [xsp+1Ch] [xbp+1Ch]

  v1 = sub_1052A4();
  if ( v1 == 1 )
  {
    sub_105814(0);
    sub_105650(26000000);
    sub_105784(6500000);
    sub_105814(1);
    v1 = sub_106814(0, 128, 20480);
  }
  sub_10593C();
  sub_1063AC(0);
  return v1;
}


/* ===== sub_1053D0 @ 0x1053D0 (file 0x53D0) size 284 ===== */
__int64 sub_1053D0()
{
  _BYTE v1[32]; // [xsp+10h] [xbp+10h] BYREF
  __int64 v2; // [xsp+30h] [xbp+30h]
  int v3; // [xsp+38h] [xbp+38h]
  unsigned int i; // [xsp+3Ch] [xbp+3Ch]

  v3 = 0;
  memset(v1, 0, sizeof(v1));
  v2 = 20480;
  for ( i = 0; i <= 1; ++i )
  {
    v3 = sub_10535C();
    if ( v3 != 0 && *(_DWORD *)v2 == 1112819780 && *(_DWORD *)(v2 + 48) <= 0xFFFFu )
    {
      sub_10DF40(0x400000);
      sub_10E254(15);
      if ( (unsigned int)sub_105248(v2 + 8, 0x20u) == 0 )
        return 1;
      sub_10E798(20992, *(unsigned int *)(v2 + 48), v1);
      if ( (unsigned int)sub_10FB08(v1, v2 + 8, 32) == 0 )
        return 1;
      sub_10DF40(256);
      sub_10E254(23);
    }
    else
    {
      sub_10DF40(0x800000);
      sub_10E254(14);
    }
  }
  return 0;
}


/* ===== sub_1054EC @ 0x1054EC (file 0x54EC) size 160 ===== */
__int64 __fastcall sub_1054EC(int a1)
{
  unsigned int i; // [xsp+1Ch] [xbp-4h]

  if ( a1 != 0 )
  {
    MEMORY[0x20E00000] |= 0x100u;
    MEMORY[0x20E00004] |= 0x800u;
    for ( i = 0; i <= 0xFE; ++i )
      ;
    MEMORY[0x20E00004] &= ~0x800u;
    return 551550980;
  }
  else
  {
    MEMORY[0x20E00000] &= ~0x100u;
    return 551550976;
  }
}


/* ===== nullsub_2 @ 0x10558C (file 0x558C) size 4 ===== */
void nullsub_2()
{
  ;
}


/* ===== sub_105590 @ 0x105590 (file 0x5590) size 192 ===== */
__int64 sub_105590()
{
  MEMORY[0x402A013C] = 0;
  MEMORY[0x402A0140] = 0;
  MEMORY[0x402A0144] = 0;
  MEMORY[0x402A0148] = 0;
  MEMORY[0x402A014C] = 0;
  MEMORY[0x402A0150] = 0;
  MEMORY[0x402A053C] = 1572992;
  MEMORY[0x402A0540] = 1572992;
  MEMORY[0x402A0544] = 1572992;
  MEMORY[0x402A0548] = 1572992;
  MEMORY[0x402A054C] = 1572992;
  MEMORY[0x402A0550] = 2621440;
  return 1076495696;
}


/* ===== sub_105650 @ 0x105650 (file 0x5650) size 136 ===== */
__int64 sub_105650()
{
  MEMORY[0x21500080] &= 0xFFFFFFF8;
  MEMORY[0x21500080] |= 1u;
  MEMORY[0x1028] = 26000000;
  return 26000000;
}


/* ===== sub_1056D8 @ 0x1056D8 (file 0x56D8) size 172 ===== */
bool sub_1056D8()
{
  int v1; // [xsp+14h] [xbp+14h]
  int i; // [xsp+18h] [xbp+18h]
  int v3; // [xsp+1Ch] [xbp+1Ch]

  MEMORY[0x2030002C] |= 0x1000000u;
  v3 = MEMORY[0x2030002C];
  v1 = sub_10D9B0(MEMORY[0x2030002C]);
  for ( i = v1; (v3 & 0x1000000) != 0 && (unsigned int)(i - v1) <= 0x63; i = sub_10D9B0(MEMORY[0x2030002C]) )
    v3 = MEMORY[0x2030002C];
  return (unsigned int)(i - v1) <= 0x64;
}


/* ===== sub_105784 @ 0x105784 (file 0x5784) size 144 ===== */
__int64 __fastcall sub_105784(int a1)
{
  MEMORY[0x2030002C] = MEMORY[0x2030002C] & 0xFFFF003F | ((MEMORY[0x1028] / (unsigned int)(4 * a1)) << 8);
  return MEMORY[0x1028] / (4 * (MEMORY[0x1028] / (unsigned int)(4 * a1)));
}


/* ===== sub_105814 @ 0x105814 (file 0x5814) size 244 ===== */
__int64 __fastcall sub_105814(int a1)
{
  int v2; // [xsp+24h] [xbp+24h]
  int i; // [xsp+28h] [xbp+28h]
  char v4; // [xsp+2Ch] [xbp+2Ch]

  if ( a1 != 0 )
  {
    MEMORY[0x2030002C] |= 1u;
    v4 = MEMORY[0x2030002C];
    v2 = sub_10D9B0(MEMORY[0x2030002C]);
    for ( i = v2; (v4 & 2) == 0 && (unsigned int)(i - v2) <= 0x63; i = sub_10D9B0(MEMORY[0x2030002C]) )
      v4 = MEMORY[0x2030002C];
    MEMORY[0x2030002C] |= 4u;
    return 540016684;
  }
  else
  {
    MEMORY[0x2030002C] &= ~4u;
    MEMORY[0x2030002C] &= ~1u;
    return 540016684;
  }
}


/* ===== sub_105908 @ 0x105908 (file 0x5908) size 52 ===== */
bool sub_105908()
{
  __int64 v0; // x0

  v0 = sub_1054EC(1);
  sub_10D360(v0);
  nullsub_2();
  sub_105590();
  sub_105650();
  return sub_1056D8();
}


/* ===== sub_10593C @ 0x10593C (file 0x593C) size 32 ===== */
__int64 sub_10593C()
{
  sub_105814(0);
  return sub_1054EC(0);
}


/* ===== sub_10595C @ 0x10595C (file 0x595C) size 104 ===== */
__int64 __fastcall sub_10595C(int a1, int a2)
{
  if ( a2 != 0 )
    MEMORY[0x20300034] |= a1;
  else
    MEMORY[0x20300034] &= ~a1;
  return 540016692;
}


/* ===== sub_1059C4 @ 0x1059C4 (file 0x59C4) size 104 ===== */
__int64 __fastcall sub_1059C4(int a1, int a2)
{
  if ( a2 != 0 )
    MEMORY[0x20300038] |= a1;
  else
    MEMORY[0x20300038] &= ~a1;
  return 540016696;
}


/* ===== sub_105A2C @ 0x105A2C (file 0x5A2C) size 32 ===== */
__int64 __fastcall sub_105A2C(int a1)
{
  MEMORY[0x20300030] = a1;
  return 540016688;
}


/* ===== sub_105A4C @ 0x105A4C (file 0x5A4C) size 32 ===== */
__int64 sub_105A4C()
{
  return MEMORY[0x20300030];
}


/* ===== sub_105A6C @ 0x105A6C (file 0x5A6C) size 84 ===== */
__int64 __fastcall sub_105A6C(unsigned __int8 a1)
{
  unsigned int v2; // [xsp+1Ch] [xbp-4h]

  v2 = MEMORY[0x2030002C] & 0xFFF0FFFF | (a1 << 16);
  MEMORY[0x2030002C] = v2;
  return 540016684;
}


/* ===== sub_105AC0 @ 0x105AC0 (file 0x5AC0) size 52 ===== */
__int64 __fastcall sub_105AC0(__int64 a1)
{
  MEMORY[0x20300058] = a1;
  return 540016732;
}


/* ===== sub_105AF4 @ 0x105AF4 (file 0x5AF4) size 32 ===== */
__int64 __fastcall sub_105AF4(int a1)
{
  MEMORY[0x20300004] = a1;
  return 540016644;
}


/* ===== sub_105B14 @ 0x105B14 (file 0x5B14) size 28 ===== */
__int64 __fastcall sub_105B14(int a1)
{
  MEMORY[0x20300000] = a1;
  return 540016640;
}


/* ===== sub_105B30 @ 0x105B30 (file 0x5B30) size 32 ===== */
__int64 __fastcall sub_105B30(int a1)
{
  MEMORY[0x20300008] = a1;
  return 540016648;
}


/* ===== sub_105B50 @ 0x105B50 (file 0x5B50) size 648 ===== */
__int64 __fastcall sub_105B50(int a1, char a2, int a3, int a4)
{
  int v5; // [xsp+1Ch] [xbp-4h]

  if ( (a2 & 0x40) != 0 )
    v5 = 0x200000;
  else
    v5 = 0x40000;
  if ( (a2 & 0x20) != 0 )
    v5 |= 0x20u;
  if ( (a2 & 0x10) != 0 )
    v5 |= 0x10u;
  if ( (a2 & 8) != 0 )
  {
    v5 |= 0xCu;
    MEMORY[0x2030003C] &= ~0x8000000u;
  }
  else if ( (a2 & 4) != 0 )
  {
    v5 |= 0xCu;
    MEMORY[0x2030003C] |= 0x8000000u;
  }
  else
  {
    MEMORY[0x2030003C] &= ~0x8000000u;
  }
  if ( (a2 & 2) != 0 )
    v5 |= 2u;
  if ( (a2 & 1) != 0 )
    v5 |= 1u;
  if ( a3 == 1 )
    v5 |= 0xC00000u;
  switch ( a4 )
  {
    case 1:
      v5 |= 0x1A0000u;
      break;
    case 2:
      v5 |= 0x90000u;
      break;
    case 3:
      v5 |= 0x20000u;
      break;
    case 4:
      v5 |= 0x20000u;
      break;
    case 5:
      v5 |= 0x1A0000u;
      break;
    case 6:
      v5 |= 0x1A0000u;
      break;
    case 7:
      v5 |= 0x1A0000u;
      break;
    case 8:
      v5 |= 0x1B0000u;
      break;
    case 9:
      v5 |= 0x1B0000u;
      break;
    default:
      break;
  }
  MEMORY[0x2030000C] = (a1 << 24) | v5;
  return 540016652;
}


/* ===== sub_105DD8 @ 0x105DD8 (file 0x5DD8) size 568 ===== */
char *__fastcall sub_105DD8(unsigned int a1, _BYTE *a2)
{
  char *v2; // kr08_8
  char *result; // x0
  __int64 v4; // kr00_8
  int v5; // [xsp+10h] [xbp-10h]
  int v6; // [xsp+14h] [xbp-Ch]
  int v7; // [xsp+18h] [xbp-8h]
  __int16 v8; // [xsp+1Ch] [xbp-4h]

  v5 = MEMORY[0x20300010];
  v6 = MEMORY[0x20300014];
  v7 = MEMORY[0x20300018];
  v8 = MEMORY[0x2030001C];
  v2 = (char *)a1;
  v4 = a1;
  result = (char *)&loc_105E48 + 4 * jpt_105E44[a1];
  switch ( v4 )
  {
    case 0LL:
      return result;
    case 1LL:
    case 3LL:
    case 4LL:
    case 5LL:
    case 6LL:
    case 7LL:
    case 8LL:
    case 9LL:
      *a2 = MEMORY[0x20300013];
      a2[1] = BYTE2(v5);
      a2[2] = BYTE1(v5);
      a2[3] = v5;
      result = a2 + 3;
      break;
    case 2LL:
      *a2 = MEMORY[0x2030001E];
      a2[1] = HIBYTE(v8);
      a2[2] = v8;
      a2[3] = HIBYTE(v7);
      a2[4] = BYTE2(v7);
      a2[5] = BYTE1(v7);
      a2[6] = v7;
      a2[7] = HIBYTE(v6);
      a2[8] = BYTE2(v6);
      a2[9] = BYTE1(v6);
      a2[10] = v6;
      a2[11] = HIBYTE(v5);
      a2[12] = BYTE2(v5);
      a2[13] = BYTE1(v5);
      a2[14] = v5;
      result = a2 + 14;
      break;
    default:
      result = v2;
      break;
  }
  return result;
}


/* ===== sub_106010 @ 0x106010 (file 0x6010) size 924 ===== */
__int64 __fastcall sub_106010(unsigned int a1, int a2, __int64 a3, _BYTE *a4)
{
  __int64 v4; // x0
  __int64 v6; // x0
  unsigned int v11; // [xsp+3Ch] [xbp+3Ch]
  int v12; // [xsp+40h] [xbp+40h]
  unsigned int v13; // [xsp+44h] [xbp+44h]
  int i; // [xsp+48h] [xbp+48h]
  int v15; // [xsp+4Ch] [xbp+4Ch]

  v13 = 500;
  sub_1059C4(-1, 0);
  sub_10595C(-1, 0);
  sub_105A2C(-1);
  sub_105A6C(8u);
  v15 = qword_1068E0[3 * a1 + 1];
  if ( LODWORD(qword_1068E0[3 * a1 + 2]) != 0 )
    v15 |= 0x8000u;
  if ( a3 != 0 )
    v15 |= 8u;
  sub_10595C(LODWORD(qword_1068E0[3 * a1 + 2]) | v15, 1);
  sub_1059C4(LODWORD(qword_1068E0[3 * a1 + 2]) | v15, 1);
  if ( a3 != 0 )
  {
    sub_105AF4(*(_DWORD *)(a3 + 8));
    sub_105B14(*(_DWORD *)(a3 + 12));
    sub_105AC0(*(_QWORD *)a3);
    v13 = 4000;
  }
  sub_105B30(a2);
  v4 = sub_105B50(
         HIDWORD(qword_1068E0[3 * a1]),
         HIDWORD(qword_1068E0[3 * a1 + 2]),
         0,
         HIDWORD(qword_1068E0[3 * a1 + 1]));
  v12 = sub_10D9B0(v4);
  for ( i = v12; i - v12 < v13; i = sub_10D9B0(v6) )
  {
    v11 = sub_105A4C();
    if ( (qword_1068E0[3 * a1 + 2] & v11) != 0 )
    {
      sub_105A2C(LODWORD(qword_1068E0[3 * a1 + 2]) | v15);
      return qword_1068E0[3 * a1 + 2] & v11;
    }
    v6 = qword_1068E0[3 * a1 + 1] & v11;
    if ( LODWORD(qword_1068E0[3 * a1 + 1]) == (_DWORD)v6 )
    {
      sub_105A2C(LODWORD(qword_1068E0[3 * a1 + 2]) | v15);
      sub_105DD8(HIDWORD(qword_1068E0[3 * a1 + 1]), a4);
      return 0;
    }
  }
  return 0xFFFFFFFFLL;
}


/* ===== sub_1063AC @ 0x1063AC (file 0x63AC) size 16 ===== */
void sub_1063AC()
{
  ;
}


/* ===== sub_1063BC @ 0x1063BC (file 0x63BC) size 56 ===== */
bool sub_1063BC()
{
  char v1; // [xsp+10h] [xbp+10h] BYREF

  return (unsigned int)sub_106010(0, 0, 0, &v1) == 0;
}


/* ===== sub_1063F4 @ 0x1063F4 (file 0x63F4) size 88 ===== */
bool sub_1063F4()
{
  _BYTE v1[16]; // [xsp+10h] [xbp+10h] BYREF

  if ( (unsigned int)sub_106010(5u, 426, 0, v1) != 0 )
    return false;
  return v1[3] == 170 && v1[2] == 1;
}


/* ===== sub_10644C @ 0x10644C (file 0x644C) size 228 ===== */
__int64 __fastcall sub_10644C(__int64 a1)
{
  __int64 v2; // x0
  _BYTE v3[20]; // [xsp+10h] [xbp+10h] BYREF
  int v4; // [xsp+24h] [xbp+24h]
  int v5; // [xsp+28h] [xbp+28h]
  int v6; // [xsp+2Ch] [xbp+2Ch]

  v6 = sub_10D9B0(a1);
  v5 = v6;
  do
  {
    if ( (unsigned int)sub_106010(0xFu, 0, 0, v3) != 0 )
      return 0;
    v4 = 1090486272;
    if ( (unsigned int)sub_106010(0x12u, 1090486272, 0, v3) != 0 )
      return 0;
    v2 = v3[0];
    if ( (int)v2 < 0 )
    {
      MEMORY[0x2010] = (v3[0] & 0x40) != 0;
      return 1;
    }
    v5 = sub_10D9B0(v2);
  }
  while ( (unsigned int)(v5 - v6) <= 0xFA0 );
  return 0;
}


/* ===== sub_106530 @ 0x106530 (file 0x6530) size 56 ===== */
bool sub_106530()
{
  char v1; // [xsp+10h] [xbp+10h] BYREF

  return (unsigned int)sub_106010(1u, 0, 0, &v1) == 0;
}


/* ===== sub_106568 @ 0x106568 (file 0x6568) size 136 ===== */
__int64 __fastcall sub_106568(unsigned __int16 *a1)
{
  unsigned __int16 v3[11]; // [xsp+28h] [xbp+28h] BYREF
  unsigned __int16 v4; // [xsp+3Eh] [xbp+3Eh]

  if ( (unsigned int)sub_106010(2u, 0, 0, v3) != 0 )
    return 0;
  v4 = _byteswap_ushort(v3[0]);
  if ( a1 != nullptr )
    *a1 = v4;
  return 1;
}


/* ===== sub_1065F0 @ 0x1065F0 (file 0x65F0) size 84 ===== */
bool __fastcall sub_1065F0(unsigned __int16 a1)
{
  _BYTE v2[20]; // [xsp+28h] [xbp+28h] BYREF
  int v3; // [xsp+3Ch] [xbp+3Ch]

  v3 = a1 << 16;
  return (unsigned int)sub_106010(4u, v3, 0, v2) == 0;
}


/* ===== sub_106644 @ 0x106644 (file 0x6644) size 88 ===== */
bool __fastcall sub_106644(int a1)
{
  char v3; // [xsp+20h] [xbp+20h] BYREF

  if ( MEMORY[0x2010] != 0 )
    a1 = 512;
  return (unsigned int)sub_106010(9u, a1, 0, &v3) == 0;
}


/* ===== sub_10669C @ 0x10669C (file 0x669C) size 172 ===== */
bool sub_10669C()
{
  _BOOL8 v1; // x0
  unsigned __int16 v2; // [xsp+1Eh] [xbp+1Eh] BYREF

  if ( !sub_1063BC() )
    return false;
  v1 = sub_1063F4();
  if ( !v1 )
    return false;
  if ( (unsigned int)sub_10644C(v1) == 0 )
    return false;
  if ( !sub_106530() )
    return false;
  if ( (unsigned int)sub_106568(&v2) == 0 )
    return false;
  if ( sub_1065F0(v2) )
    return sub_106644(512);
  return false;
}


/* ===== sub_106748 @ 0x106748 (file 0x6748) size 204 ===== */
bool __fastcall sub_106748(int a1, int a2, __int64 a3)
{
  _QWORD v4[2]; // [xsp+28h] [xbp+28h] BYREF
  _BYTE v5[20]; // [xsp+38h] [xbp+38h] BYREF
  int v6; // [xsp+4Ch] [xbp+4Ch]

  if ( MEMORY[0x2010] != 0 )
    v6 = a1;
  else
    v6 = a1 << 9;
  LODWORD(v4[1]) = 512;
  HIDWORD(v4[1]) = a2;
  v4[0] = a3;
  if ( (unsigned int)sub_106010(0xEu, v6, (__int64)v4, v5) == 0 )
    return (unsigned int)sub_106010(7u, 0, 0, v5) == 0;
  sub_106010(7u, 0, 0, v5);
  return false;
}


/* ===== sub_106814 @ 0x106814 (file 0x6814) size 204 ===== */
bool __fastcall sub_106814(int a1, int a2, __int64 a3)
{
  _QWORD v4[2]; // [xsp+28h] [xbp+28h] BYREF
  _BYTE v5[20]; // [xsp+38h] [xbp+38h] BYREF
  int v6; // [xsp+4Ch] [xbp+4Ch]

  if ( MEMORY[0x2010] != 0 )
    v6 = a1;
  else
    v6 = a1 << 9;
  LODWORD(v4[1]) = 512;
  HIDWORD(v4[1]) = a2;
  v4[0] = a3;
  if ( (unsigned int)sub_106010(0xBu, v6, (__int64)v4, v5) == 0 )
    return (unsigned int)sub_106010(7u, 0, 0, v5) == 0;
  sub_106010(7u, 0, 0, v5);
  return false;
}


/* ===== sub_106B10 @ 0x106B10 (file 0x6B10) size 80 ===== */
__int64 __fastcall sub_106B10(int a1)
{
  if ( a1 != 0 )
    MEMORY[0x20200001] = 96;
  else
    MEMORY[0x20200001] = 64;
  MEMORY[0x2020000B] = -1;
  return 538968075;
}


/* ===== sub_106B60 @ 0x106B60 (file 0x6B60) size 372 ===== */
__int64 sub_106B60()
{
  MEMORY[0x2020000E] = 5;
  MEMORY[0x20200006] = 33;
  MEMORY[0x20200008] = 64;
  MEMORY[0x20200062] = 23;
  MEMORY[0x20200064] = 264;
  if ( MEMORY[0x2020] != 0 )
    MEMORY[0x20200150] = 64;
  else
    MEMORY[0x20200150] = 512;
  MEMORY[0x20200152] = 72;
  MEMORY[0x20200153] = -76;
  MEMORY[0x2020000E] = 6;
  MEMORY[0x20200063] = 23;
  MEMORY[0x20200066] = 8;
  if ( MEMORY[0x2020] != 0 )
    MEMORY[0x20200164] = 64;
  else
    MEMORY[0x20200164] = 512;
  MEMORY[0x20200166] = -112;
  MEMORY[0x20200167] |= 0xA8u;
  return 538968423;
}


/* ===== sub_106CD4 @ 0x106CD4 (file 0x6CD4) size 928 ===== */
_WORD *__fastcall sub_106CD4(int a1, int a2, __int16 a3, __int64 a4)
{
  _WORD *result; // x0
  _WORD *v6; // [xsp+38h] [xbp+38h]
  int v7; // [xsp+44h] [xbp+44h]
  __int64 v8; // [xsp+48h] [xbp+48h]

  if ( a1 != 0 )
  {
    *MEMORY[0x13B8] = a4;
    *(_WORD *)(MEMORY[0x13B8] + 8LL) = a3;
    *(_WORD *)(MEMORY[0x13B8] + 10LL) = 32;
    *(_BYTE *)(MEMORY[0x13B8] + 12LL) = a2;
    *(_BYTE *)(MEMORY[0x13B8] + 13LL) = 1;
    *(_BYTE *)(MEMORY[0x13B8] + 14LL) = 0;
    *(_BYTE *)(MEMORY[0x13B8] + 15LL) = 1;
    v8 = MEMORY[0x1310];
    sub_10FA50(MEMORY[0x1310], 0, 12);
    sub_10FAA4(v8, MEMORY[0x13B8], 4);
    v8 += 4;
    *(_WORD *)v8 = *(_WORD *)(MEMORY[0x13B8] + 10LL);
    v8 += 2;
    *(_WORD *)v8 = *(_WORD *)(MEMORY[0x13B8] + 8LL);
    *(_BYTE *)(v8 + 2) = (4 * *(_BYTE *)(MEMORY[0x13B8] + 13LL))
                       | (2 * *(_BYTE *)(MEMORY[0x13B8] + 14LL))
                       | *(_BYTE *)(MEMORY[0x13B8] + 15LL);
    v7 = a2 + 15;
    *(_DWORD *)(32 * (v7 - 1) + 538975240) |= 0x14u;
    *(_DWORD *)(32 * (v7 - 1) + 538975252) = MEMORY[0x1310];
    result = (_WORD *)(*(_DWORD *)(32 * (a2 + 14) + 538975236) | 1u);
    *(_DWORD *)(32 * (v7 - 1) + 538975236) = (_DWORD)result;
  }
  else
  {
    *MEMORY[0x12D8] = a4;
    *(_WORD *)(MEMORY[0x12D8] + 8LL) = a3;
    *(_WORD *)(MEMORY[0x12D8] + 10LL) = 32;
    *(_BYTE *)(MEMORY[0x12D8] + 12LL) = a2;
    *(_BYTE *)(MEMORY[0x12D8] + 13LL) = 1;
    *(_BYTE *)(MEMORY[0x12D8] + 14LL) = 0;
    *(_BYTE *)(MEMORY[0x12D8] + 15LL) = 1;
    v6 = (_WORD *)MEMORY[0x1388];
    sub_10FA50(MEMORY[0x1388], 0, 12);
    sub_10FAA4(v6, MEMORY[0x12D8], 4);
    v6 += 2;
    *v6++ = *(_WORD *)(MEMORY[0x12D8] + 10LL);
    *v6++ = *(_WORD *)(MEMORY[0x12D8] + 8LL);
    *(_BYTE *)v6 = (4 * *(_BYTE *)(MEMORY[0x12D8] + 13LL))
                 | (2 * *(_BYTE *)(MEMORY[0x12D8] + 14LL))
                 | *(_BYTE *)(MEMORY[0x12D8] + 15LL);
    return v6 + 2;
  }
  return result;
}


/* ===== sub_107074 @ 0x107074 (file 0x7074) size 408 ===== */
__int64 __fastcall sub_107074(unsigned __int8 a1, __int64 a2, __int16 a3)
{
  int i; // [xsp+28h] [xbp+28h]
  int v5; // [xsp+2Ch] [xbp+2Ch]

  v5 = a1;
  sub_106CD4(0, a1, a3, a2);
  *(_DWORD *)(32 * (v5 - 1) + 538975240) |= 4u;
  *(_DWORD *)(32 * (v5 - 1) + 538975252) = MEMORY[0x1388];
  *(_DWORD *)(32 * (v5 - 1) + 538975236) |= 1u;
  for ( i = *(_DWORD *)(32 * (v5 - 1) + 538975240); (i & 0x40000) == 0; i = *(_DWORD *)(32 * (v5 - 1) + 538975240) )
    ;
  *(_DWORD *)(32 * (v5 - 1) + 538975240) |= 0x4000000u;
  return 0;
}


/* ===== sub_10720C @ 0x10720C (file 0x720C) size 508 ===== */
__int64 sub_10720C()
{
  unsigned int v0; // w0
  __int64 result; // x0
  unsigned int i; // [xsp+4h] [xbp-Ch]

  MEMORY[0x20201E88] |= 0x14000000u;
  MEMORY[0x201C] = 1024 - HIWORD(MEMORY[0x20201E90]);
  for ( i = 0; i < MEMORY[0x201C]; ++i )
  {
    v0 = *(_DWORD *)(MEMORY[0x1368] + 4LL);
    *(_DWORD *)(MEMORY[0x1368] + 4LL) = v0 + 1;
    *(_BYTE *)(MEMORY[0x1368] + v0 + 8LL) = *(_BYTE *)(0x2024LL + i);
    if ( *(_DWORD *)(MEMORY[0x1368] + 4LL) > 0x3FFu )
      *(_DWORD *)(MEMORY[0x1368] + 4LL) = 0;
  }
  MEMORY[0x20201E88] |= 0x14u;
  MEMORY[0x20201E94] = MEMORY[0x1310];
  result = MEMORY[0x20201E84] | 1u;
  MEMORY[0x20201E84] |= 1u;
  return result;
}


/* ===== sub_107408 @ 0x107408 (file 0x7408) size 504 ===== */
__int64 __fastcall sub_107408(_DWORD *a1, _DWORD *a2)
{
  int v2; // w0
  int v3; // w0
  int v4; // w0
  int v5; // w0
  int v6; // w0
  unsigned int i; // [xsp+2Ch] [xbp+2Ch]
  _BYTE *v9; // [xsp+30h] [xbp+30h]
  unsigned int v10; // [xsp+3Ch] [xbp+3Ch]
  unsigned int v11; // [xsp+3Ch] [xbp+3Ch]

  MEMORY[0x20200012] |= 0x40u;
  v10 = (unsigned __int8)BYTE2(*a2) | ((unsigned __int8)HIBYTE(*a2) << 8);
  v2 = (unsigned __int8)HIBYTE(*a1);
  switch ( v2 )
  {
    case 2:
      v9 = (_BYTE *)sub_1088AC();
      if ( MEMORY[0x2020] != 0 )
      {
        v9[29] = 64;
        v9[22] = v9[29];
        v9[30] = 0;
        v9[23] = v9[30];
      }
      if ( v10 > 0x20 )
        v4 = 32;
      else
        v4 = v10;
      v11 = v4;
      break;
    case 6:
      v9 = (_BYTE *)sub_1088B8();
      if ( v10 > 0xA )
        v5 = 10;
      else
        v5 = v10;
      v11 = v5;
      break;
    case 1:
      v9 = (_BYTE *)sub_1088A0();
      if ( v10 > 0x12 )
        v3 = 18;
      else
        v3 = v10;
      v11 = v3;
      break;
    default:
      v9 = (_BYTE *)sub_1088B8();
      if ( v10 > 0xA )
        v6 = 10;
      else
        v6 = v10;
      v11 = v6;
      break;
  }
  for ( i = 0; i < v11; ++i )
    MEMORY[0x20200020] = v9[i];
  MEMORY[0x20200012] |= 0xAu;
  return 538968082;
}


/* ===== sub_107600 @ 0x107600 (file 0x7600) size 212 ===== */
__int64 __fastcall sub_107600(char a1)
{
  __int64 result; // x0

  result = a1 & 0x7F;
  if ( (_DWORD)result != 0 )
  {
    if ( a1 < 0 )
    {
      MEMORY[0x20200152] |= 0x40u;
      MEMORY[0x20200152] |= 8u;
      return 538968402;
    }
    else
    {
      MEMORY[0x20200166] |= 0x80u;
      MEMORY[0x20200166] |= 0x10u;
      return 538968422;
    }
  }
  return result;
}


/* ===== sub_1076D4 @ 0x1076D4 (file 0x76D4) size 1584 ===== */
__int64 sub_1076D4()
{
  __int64 result; // x0
  int v1; // w0
  unsigned int i; // [xsp+20h] [xbp+20h]
  unsigned int ii; // [xsp+20h] [xbp+20h]
  unsigned int m; // [xsp+20h] [xbp+20h]
  char jj; // [xsp+26h] [xbp+26h]
  char kk; // [xsp+26h] [xbp+26h]
  char mm; // [xsp+26h] [xbp+26h]
  char j; // [xsp+26h] [xbp+26h]
  char k; // [xsp+26h] [xbp+26h]
  char n; // [xsp+26h] [xbp+26h]
  _DWORD *v11; // [xsp+28h] [xbp+28h]
  unsigned int v12; // [xsp+3Ch] [xbp+3Ch]
  unsigned int v13; // [xsp+3Ch] [xbp+3Ch]

  result = MEMORY[0x20200012] & 1;
  if ( (MEMORY[0x20200012] & 1) != 0 )
  {
    for ( i = 0; i <= 7; ++i )
      *(_BYTE *)(MEMORY[0x1378] + i) = MEMORY[0x20200020];
    v11 = (_DWORD *)(MEMORY[0x1378] + 4LL);
    v1 = (*MEMORY[0x1378] >> 5) & 3;
    if ( v1 == 1 )
    {
      if ( (*MEMORY[0x1378] & 0x1F) == 1 )
      {
        MEMORY[0x20200012] |= 0x48u;
        for ( j = MEMORY[0x20200002]; (j & 1) == 0; j = MEMORY[0x20200002] )
          ;
        result = (unsigned __int8)BYTE2(*MEMORY[0x1378]);
        if ( (unsigned __int8)BYTE2(*MEMORY[0x1378]) != 0 )
        {
          sub_106B60();
          return (__int64)sub_106CD4(1, 6, 1024, 0x2024);
        }
      }
      else
      {
        MEMORY[0x20200012] |= 0x48u;
        for ( k = MEMORY[0x20200002]; ; k = MEMORY[0x20200002] )
        {
          result = k & 1;
          if ( (k & 1) != 0 )
            break;
        }
      }
    }
    else if ( v1 == 2 )
    {
      MEMORY[0x20200012] |= 0x40u;
      v13 = (unsigned __int8)BYTE2(*v11) | ((unsigned __int8)HIBYTE(*v11) << 8);
      for ( m = 0; m < v13; ++m )
        MEMORY[0x20200020] = *(_BYTE *)(MEMORY[0x1348] + m);
      MEMORY[0x20200012] |= 0xAu;
      return 538968082;
    }
    else if ( v1 != 0 )
    {
      MEMORY[0x20200012] |= 0x48u;
      for ( n = MEMORY[0x20200002]; ; n = MEMORY[0x20200002] )
      {
        result = n & 1;
        if ( (n & 1) != 0 )
          break;
      }
    }
    else
    {
      switch ( BYTE1(*MEMORY[0x1378]) )
      {
        case 0u:
          MEMORY[0x20200012] |= 0x40u;
          v12 = (unsigned __int8)BYTE2(*v11) | ((unsigned __int8)HIBYTE(*v11) << 8);
          for ( ii = 0; ii < v12; ++ii )
            MEMORY[0x20200020] = *(_BYTE *)(MEMORY[0x1348] + ii);
          MEMORY[0x20200012] |= 0xAu;
          result = 538968082;
          break;
        case 1u:
          MEMORY[0x20200012] |= 0x48u;
          result = *MEMORY[0x1378] & 0x1F;
          if ( (*MEMORY[0x1378] & 0x1F) == 2 )
            result = sub_107600(*v11);
          break;
        case 5u:
          MEMORY[0x20200012] |= 0x48u;
          for ( jj = MEMORY[0x20200002]; (jj & 1) == 0; jj = MEMORY[0x20200002] )
            ;
          MEMORY[0x20200000] = BYTE2(*MEMORY[0x1378]);
          result = 538968064;
          break;
        case 6u:
          result = sub_107408(MEMORY[0x1378], v11);
          break;
        case 9u:
          MEMORY[0x20200012] |= 0x48u;
          for ( kk = MEMORY[0x20200002]; ; kk = MEMORY[0x20200002] )
          {
            result = kk & 1;
            if ( (kk & 1) != 0 )
              break;
          }
          break;
        default:
          MEMORY[0x20200012] |= 0x48u;
          for ( mm = MEMORY[0x20200002]; ; mm = MEMORY[0x20200002] )
          {
            result = mm & 1;
            if ( (mm & 1) != 0 )
              break;
          }
          break;
      }
    }
  }
  return result;
}


/* ===== sub_107D04 @ 0x107D04 (file 0x7D04) size 220 ===== */
__int64 sub_107D04()
{
  __int64 result; // x0
  int v1; // [xsp+18h] [xbp+18h]

  if ( (MEMORY[0x2020000A] & 4) != 0 )
    MEMORY[0x2020] = (MEMORY[0x20200001] & 0x10) == 0;
  v1 = MEMORY[0x20201E88];
  if ( (MEMORY[0x20200002] & 1) != 0 )
  {
    MEMORY[0x2020000E] = 0;
    sub_1076D4();
  }
  result = v1 & 0x40000;
  if ( (_DWORD)result != 0 )
    return sub_10720C();
  return result;
}


/* ===== sub_107DE0 @ 0x107DE0 (file 0x7DE0) size 312 ===== */
__int64 __fastcall sub_107DE0(_DWORD *a1)
{
  __int64 v1; // x0
  __int64 v4; // [xsp+30h] [xbp+30h]
  unsigned __int8 v5; // [xsp+3Bh] [xbp+3Bh]
  int v6; // [xsp+3Ch] [xbp+3Ch]

  v5 = 0;
  v6 = 1;
  v4 = (unsigned int)sub_10D9B0(1);
  while ( 1 )
  {
    sub_107D04();
    if ( *MEMORY[0x1368] != *(_DWORD *)(MEMORY[0x1368] + 4LL) )
    {
      v5 = *(_BYTE *)(MEMORY[0x1368] + (unsigned int)(*MEMORY[0x1368])++ + 8LL);
      if ( *MEMORY[0x1368] > 0x3FFu )
        *MEMORY[0x1368] = 0;
      v6 = 0;
    }
    v1 = (unsigned int)*MEMORY[0x1338];
    if ( (_DWORD)v1 != 0 && (unsigned __int64)(unsigned int)sub_10D9B0(v1) - v4 > 0x3E80 )
      break;
    if ( v6 == 0 )
      return v5;
  }
  if ( a1 != nullptr )
  {
    *a1 = 1;
    sub_10E254(1);
    sub_10DF40(4);
  }
  return v5;
}


/* ===== sub_107F40 @ 0x107F40 (file 0x7F40) size 60 ===== */
__int64 __fastcall sub_107F40(unsigned __int16 a1)
{
  return (unsigned __int16)((a1 << 8) | HIBYTE(a1));
}


/* ===== sub_107F7C @ 0x107F7C (file 0x7F7C) size 76 ===== */
__int64 __fastcall sub_107F7C(int a1)
{
  unsigned __int64 v1; // t2
  unsigned int v3; // [xsp+1Ch] [xbp-4h]

  HIDWORD(v1) = a1;
  LODWORD(v1) = a1;
  v3 = ((v1 >> 16) ^ a1) & 0xFF00FFFF;
  HIDWORD(v1) = a1;
  LODWORD(v1) = a1;
  return (v3 >> 8) ^ (unsigned int)(v1 >> 8);
}


/* ===== sub_107FC8 @ 0x107FC8 (file 0x7FC8) size 340 ===== */
__int64 sub_107FC8()
{
  _WORD *v0; // x19
  __int64 v1; // x19
  unsigned __int16 v2; // w0
  __int64 v3; // x19
  unsigned int v4; // w0
  __int64 v5; // x19
  int v6; // w0
  __int64 v7; // x0
  unsigned int v9; // [xsp+28h] [xbp+28h] BYREF
  char v10; // [xsp+2Fh] [xbp+2Fh]

  v9 = 0;
  v10 = 0;
  *MEMORY[0x1340] = MEMORY[0x1318];
  *MEMORY[0x1360] = MEMORY[0x1370];
  *(_DWORD *)(MEMORY[0x12E0] + 12LL) = 1024;
  *(_QWORD *)(MEMORY[0x12E0] + 24LL) = *MEMORY[0x1360];
  *MEMORY[0x1368] = 0;
  *(_DWORD *)(MEMORY[0x1368] + 4LL) = 0;
  do
    v10 = sub_107DE0(&v9);
  while ( (v10 != 126 || v9 != 0) && v9 != 1 );
  if ( v9 == 0 )
  {
    v0 = (_WORD *)*MEMORY[0x1340];
    *v0 = sub_107F40(0x81u);
    v1 = *MEMORY[0x1340];
    v2 = sub_108F60();
    *(_WORD *)(v1 + 2) = sub_107F40(v2);
    v3 = *MEMORY[0x1340] + 4LL;
    v4 = sub_108F60();
    sub_10D4C8(v3, MEMORY[0x12C0], v4);
    v5 = *MEMORY[0x1340];
    v6 = sub_108F60();
    v7 = sub_1084D8(v5, (unsigned int)(v6 + 6));
    sub_10811C(v7);
  }
  return v9;
}


/* ===== sub_10811C @ 0x10811C (file 0x811C) size 156 ===== */
__int64 sub_10811C()
{
  unsigned __int16 v0; // w0
  __int64 result; // x0
  unsigned __int16 *v2; // [xsp+18h] [xbp+18h] BYREF
  _DWORD v3[2]; // [xsp+20h] [xbp+20h] BYREF
  unsigned int v4; // [xsp+28h] [xbp+28h]
  unsigned int v5; // [xsp+2Ch] [xbp+2Ch]

  v5 = 145;
  while ( 1 )
  {
    result = v5;
    if ( v5 != 145 )
      break;
    v4 = sub_10842C(&v2, v3);
    if ( v4 == 143 )
    {
      v0 = sub_107F40(*v2);
      v3[1] = v0;
      (*(void (__fastcall **)(unsigned __int16 *, _QWORD))(MEMORY[0x13A8] + 8LL * v0))(v2, v3[0]);
    }
    else
    {
      sub_1081B8(v4);
      sub_10D4FC(MEMORY[0x12B8], 0, 48);
    }
  }
  return result;
}


/* ===== sub_1081B8 @ 0x1081B8 (file 0x81B8) size 96 ===== */
__int64 __fastcall sub_1081B8(unsigned __int16 a1)
{
  _WORD *v1; // x19

  v1 = (_WORD *)*MEMORY[0x1340];
  *v1 = sub_107F40(a1);
  *(_WORD *)(*MEMORY[0x1340] + 2LL) = 0;
  return sub_1084D8(*MEMORY[0x1340], 6);
}


/* ===== sub_108218 @ 0x108218 (file 0x8218) size 88 ===== */
__int64 sub_108218()
{
  if ( *(_DWORD *)(MEMORY[0x12B8] + 8LL) != 1 )
  {
    sub_1081B8(0x80u);
    *(_DWORD *)(MEMORY[0x12B8] + 8LL) = 1;
  }
  return sub_10D4FC(MEMORY[0x12B8], 0, 48);
}


/* ===== sub_108270 @ 0x108270 (file 0x8270) size 128 ===== */
__int64 __fastcall sub_108270(__int64 a1)
{
  unsigned int v1; // w0
  unsigned int v4; // [xsp+2Ch] [xbp+2Ch]

  v4 = sub_107F7C(*(_DWORD *)(a1 + 4));
  v1 = sub_107F7C(*(_DWORD *)(a1 + 8));
  *(_QWORD *)(MEMORY[0x12B8] + 32LL) = v4;
  *(_QWORD *)(MEMORY[0x12B8] + 40LL) = *(_QWORD *)(MEMORY[0x12B8] + 32LL);
  *(_QWORD *)(MEMORY[0x12B8] + 16LL) = v1;
  return sub_1081B8(0x80u);
}


/* ===== sub_1082F0 @ 0x1082F0 (file 0x82F0) size 144 ===== */
__int64 __fastcall sub_1082F0(__int64 a1)
{
  unsigned __int16 v3; // [xsp+2Eh] [xbp+2Eh]

  v3 = sub_107F40(*(_WORD *)(a1 + 2));
  sub_10D4C8(*(_QWORD *)(MEMORY[0x12B8] + 40LL), a1 + 4, v3);
  *(_QWORD *)(MEMORY[0x12B8] + 40LL) += v3;
  *(_QWORD *)(MEMORY[0x12B8] + 24LL) += v3;
  return sub_1081B8(0x80u);
}


/* ===== sub_108380 @ 0x108380 (file 0x8380) size 112 ===== */
__int64 sub_108380()
{
  if ( *(_QWORD *)(MEMORY[0x12B8] + 24LL) == *(_QWORD *)(MEMORY[0x12B8] + 16LL) )
  {
    *MEMORY[0x12B8] = 143;
    return sub_1081B8(0x80u);
  }
  else
  {
    *(_DWORD *)(MEMORY[0x12B8] + 8LL) = 5;
    return sub_1081B8(0x8Bu);
  }
}


/* ===== sub_1083F0 @ 0x1083F0 (file 0x83F0) size 60 ===== */
__int64 sub_1083F0()
{
  sub_1081B8(0x80u);
  sub_10D9D0(300);
  return sub_10E3F0(*(_QWORD *)(MEMORY[0x12B8] + 32LL));
}


/* ===== sub_10842C @ 0x10842C (file 0x842C) size 172 ===== */
__int64 __fastcall sub_10842C(_QWORD *a1, _DWORD *a2)
{
  *(_QWORD *)(MEMORY[0x12E0] + 32LL) = *(_QWORD *)(MEMORY[0x12E0] + 24LL);
  *(_DWORD *)(MEMORY[0x12E0] + 16LL) = 0;
  *(_DWORD *)(MEMORY[0x12E0] + 4LL) = 0;
  sub_1085D8();
  if ( (unsigned int)sub_10D400(*(_QWORD *)(MEMORY[0x12E0] + 24LL), *(unsigned int *)(MEMORY[0x12E0] + 16LL)) != 0 )
    return 139;
  *a1 = *(_QWORD *)(MEMORY[0x12E0] + 24LL);
  *a2 = *(_DWORD *)(MEMORY[0x12E0] + 16LL);
  return 143;
}


/* ===== sub_1084D8 @ 0x1084D8 (file 0x84D8) size 256 ===== */
__int64 __fastcall sub_1084D8(_BYTE *a1, int a2)
{
  __int16 v2; // w0
  int v5; // [xsp+14h] [xbp+14h]
  int i; // [xsp+2Ch] [xbp+2Ch]

  v2 = sub_10D400(a1, (unsigned int)(a2 - 2));
  a1[a2 - 2] = HIBYTE(v2);
  a1[a2 - 1] = v2;
  a1[a2] = 126;
  v5 = a2 + 2;
  for ( i = v5; i > 0; --i )
    a1[i] = a1[i - 1];
  *a1 = 126;
  return sub_107074(5u, (__int64)a1, v5);
}


/* ===== sub_1085D8 @ 0x1085D8 (file 0x85D8) size 420 ===== */
__int64 sub_1085D8()
{
  int v0; // w0
  _BYTE *v1; // x0
  _BYTE *v2; // x0
  __int64 result; // x0
  int v4; // [xsp+18h] [xbp+18h] BYREF
  int v5; // [xsp+1Ch] [xbp+1Ch]

  v4 = 0;
  while ( 1 )
  {
    result = *(unsigned int *)(MEMORY[0x12E0] + 4LL);
    if ( (_DWORD)result == 3 )
      break;
    v5 = (unsigned __int8)sub_107DE0(&v4);
    v0 = *(_DWORD *)(MEMORY[0x12E0] + 4LL);
    if ( v0 == 1 )
    {
      if ( v5 != 126 )
      {
        if ( v5 == 125 )
          v5 = (unsigned __int8)sub_107DE0(&v4) ^ 0x20;
        *(_DWORD *)(MEMORY[0x12E0] + 4LL) = 2;
        v1 = *(_BYTE **)(MEMORY[0x12E0] + 32LL);
        *(_QWORD *)(MEMORY[0x12E0] + 32LL) = v1 + 1;
        *v1 = v5;
        ++*(_DWORD *)(MEMORY[0x12E0] + 16LL);
      }
    }
    else if ( v0 != 0 )
    {
      if ( v0 == 2 )
      {
        if ( v5 == 126 )
        {
          *(_DWORD *)(MEMORY[0x12E0] + 4LL) = 3;
        }
        else
        {
          if ( v5 == 125 )
            v5 = (unsigned __int8)sub_107DE0(&v4) ^ 0x20;
          v2 = *(_BYTE **)(MEMORY[0x12E0] + 32LL);
          *(_QWORD *)(MEMORY[0x12E0] + 32LL) = v2 + 1;
          *v2 = v5;
          ++*(_DWORD *)(MEMORY[0x12E0] + 16LL);
        }
      }
    }
    else if ( v5 == 126 )
    {
      *(_DWORD *)(MEMORY[0x12E0] + 4LL) = 1;
    }
  }
  return result;
}


/* ===== sub_10877C @ 0x10877C (file 0x877C) size 196 ===== */
__int64 __fastcall sub_10877C(int a1)
{
  sub_10D3B0();
  MEMORY[0x20E00000] |= 0x10u;
  MEMORY[0x20E03024] |= 0x1400000u;
  MEMORY[0x20E03028] |= 0x60000000u;
  MEMORY[0x20E00004] |= 0x70u;
  sub_10D9D0(10);
  MEMORY[0x20E00004] &= 0xFFFFFF8F;
  sub_10E168(90);
  sub_10D9D0(30);
  return sub_106B10(a1);
}


/* ===== sub_108840 @ 0x108840 (file 0x8840) size 96 ===== */
__int64 __fastcall sub_108840(unsigned int a1)
{
  __int64 result; // x0

  sub_10E254(0);
  if ( (unsigned int)sub_10DBC0(a1) == 0 )
  {
    sub_10E18C();
    sub_10877C(a1);
  }
  sub_10DF40(2);
  result = (unsigned int)sub_107FC8();
  if ( (_DWORD)result != 1 )
  {
    while ( 1 )
      ;
  }
  return result;
}


/* ===== sub_1088A0 @ 0x1088A0 (file 0x88A0) size 12 ===== */
__int64 sub_1088A0()
{
  return MEMORY[0x1380];
}


/* ===== sub_1088AC @ 0x1088AC (file 0x88AC) size 12 ===== */
__int64 sub_1088AC()
{
  return MEMORY[0x12C8];
}


/* ===== sub_1088B8 @ 0x1088B8 (file 0x88B8) size 12 ===== */
__int64 sub_1088B8()
{
  return MEMORY[0x1330];
}


/* ===== sub_1088C4 @ 0x1088C4 (file 0x88C4) size 60 ===== */
__int64 __fastcall sub_1088C4(unsigned __int16 a1)
{
  return (unsigned __int16)((a1 << 8) | HIBYTE(a1));
}


/* ===== sub_108900 @ 0x108900 (file 0x8900) size 76 ===== */
__int64 __fastcall sub_108900(int a1)
{
  unsigned __int64 v1; // t2
  unsigned int v3; // [xsp+1Ch] [xbp-4h]

  HIDWORD(v1) = a1;
  LODWORD(v1) = a1;
  v3 = ((v1 >> 16) ^ a1) & 0xFF00FFFF;
  HIDWORD(v1) = a1;
  LODWORD(v1) = a1;
  return (v3 >> 8) ^ (unsigned int)(v1 >> 8);
}


/* ===== sub_10894C @ 0x10894C (file 0x894C) size 92 ===== */
unsigned __int64 __fastcall sub_10894C(unsigned int a1, _DWORD *a2)
{
  unsigned __int64 result; // x0
  unsigned int v4; // [xsp+1Ch] [xbp-4h]

  result = *(_DWORD *)(a1 + 8LL) & 0x1000;
  if ( (_DWORD)result == 0 )
  {
    v4 = *(_DWORD *)(a1 + 4LL);
    result = v4;
    if ( v4 == 126 )
    {
      ++*a2;
      return (unsigned __int64)a2;
    }
  }
  return result;
}


/* ===== sub_1089A8 @ 0x1089A8 (file 0x89A8) size 56 ===== */
__int64 __fastcall sub_1089A8(__int64 result)
{
  while ( (*(_DWORD *)((unsigned int)result + 8LL) & 0x8000) == 0 )
    ;
  result = (unsigned int)result;
  *(_DWORD *)(unsigned int)result = 85;
  return result;
}


/* ===== sub_1089E0 @ 0x1089E0 (file 0x89E0) size 156 ===== */
unsigned __int64 __fastcall sub_1089E0(unsigned int a1)
{
  unsigned __int64 result; // x0
  unsigned int v2; // [xsp+2Ch] [xbp+2Ch]

  v2 = a1 / 0x14;
  result = a1 / 0x14;
  if ( v2 <= 0x1E )
  {
    result = (unsigned int)(1 << v2) & MEMORY[0x2424];
    if ( (_DWORD)result == 0 )
    {
      sub_1089A8(1880096768);
      MEMORY[0x2424] |= 1 << v2;
      return 0x2424u;
    }
  }
  return result;
}


/* ===== sub_108A7C @ 0x108A7C (file 0x8A7C) size 160 ===== */
__int64 sub_108A7C()
{
  __int64 v0; // x0
  __int64 v1; // x0
  unsigned int v3; // [xsp+14h] [xbp+14h] BYREF
  int v4; // [xsp+18h] [xbp+18h]
  int v5; // [xsp+1Ch] [xbp+1Ch]

  v3 = 0;
  v0 = sub_108B1C();
  v1 = sub_10D9B0(v0);
  v4 = v1;
  v5 = sub_10D9B0(v1);
  sub_1089E0(0);
  do
  {
    sub_1089E0(v5 - v4);
    sub_10894C(0x70100000u, &v3);
    if ( v3 > 2 )
    {
      *MEMORY[0x12F0] = 1880096768;
      sub_10E168(106);
      return 1;
    }
    v5 = sub_10D9B0(v3);
  }
  while ( (unsigned int)(v5 - v4) <= 0x50 );
  return 0;
}


/* ===== sub_108B1C @ 0x108B1C (file 0x8B1C) size 64 ===== */
__int64 sub_108B1C()
{
  unsigned __int8 v1; // [xsp+Fh] [xbp-1h]

  v1 = 0;
  while ( (MEMORY[0x70100008] & 0x1000) == 0 )
    v1 = MEMORY[0x70100004];
  return v1;
}


/* ===== sub_108B5C @ 0x108B5C (file 0x8B5C) size 256 ===== */
void __noreturn sub_108B5C()
{
  __int64 v0; // x0
  _WORD *v1; // x19
  __int64 v2; // x19
  __int64 v3; // x0

  sub_10DF40(8);
  sub_10D4FC(MEMORY[0x12B8], 0, 48);
  *(_DWORD *)(MEMORY[0x12B8] + 8LL) = 0;
  *MEMORY[0x1340] = 0;
  *MEMORY[0x1360] = 0;
  *MEMORY[0x1340] = MEMORY[0x1318];
  *MEMORY[0x1360] = MEMORY[0x1370];
  v0 = sub_10D4FC(MEMORY[0x13A0], 0, 48);
  sub_108F70(v0);
  v1 = (_WORD *)*MEMORY[0x1340];
  *v1 = sub_1088C4(0x81u);
  v2 = *MEMORY[0x1340];
  *(_WORD *)(v2 + 2) = sub_1088C4(6u);
  sub_10D4C8(*MEMORY[0x1340] + 4LL, MEMORY[0x12C0], 6);
  v3 = sub_109028(*MEMORY[0x1340], 12);
  sub_108C5C(v3);
  while ( 1 )
    ;
}


/* ===== sub_108C5C @ 0x108C5C (file 0x8C5C) size 156 ===== */
__int64 sub_108C5C()
{
  unsigned __int16 v0; // w0
  __int64 result; // x0
  unsigned __int16 *v2; // [xsp+18h] [xbp+18h] BYREF
  _DWORD v3[2]; // [xsp+20h] [xbp+20h] BYREF
  unsigned int v4; // [xsp+28h] [xbp+28h]
  unsigned int v5; // [xsp+2Ch] [xbp+2Ch]

  v5 = 145;
  while ( 1 )
  {
    result = v5;
    if ( v5 != 145 )
      break;
    v4 = sub_10918C(&v2, v3);
    if ( v4 == 143 )
    {
      v0 = sub_1088C4(*v2);
      v3[1] = v0;
      (*(void (__fastcall **)(unsigned __int16 *, _QWORD))(MEMORY[0x1328] + 8LL * v0))(v2, v3[0]);
    }
    else
    {
      sub_108CF8(v4);
      sub_10D4FC(MEMORY[0x12B8], 0, 48);
    }
  }
  return result;
}


/* ===== sub_108CF8 @ 0x108CF8 (file 0x8CF8) size 96 ===== */
__int64 __fastcall sub_108CF8(unsigned __int16 a1)
{
  _WORD *v1; // x19

  v1 = (_WORD *)*MEMORY[0x1340];
  *v1 = sub_1088C4(a1);
  *(_WORD *)(*MEMORY[0x1340] + 2LL) = 0;
  return sub_109028(*MEMORY[0x1340], 6);
}


/* ===== sub_108D58 @ 0x108D58 (file 0x8D58) size 88 ===== */
__int64 sub_108D58()
{
  if ( *(_DWORD *)(MEMORY[0x12B8] + 8LL) != 1 )
  {
    sub_108CF8(0x80u);
    *(_DWORD *)(MEMORY[0x12B8] + 8LL) = 1;
  }
  return sub_10D4FC(MEMORY[0x12B8], 0, 48);
}


/* ===== sub_108DB0 @ 0x108DB0 (file 0x8DB0) size 128 ===== */
__int64 __fastcall sub_108DB0(__int64 a1)
{
  unsigned int v1; // w0
  unsigned int v4; // [xsp+2Ch] [xbp+2Ch]

  v4 = sub_108900(*(_DWORD *)(a1 + 4));
  v1 = sub_108900(*(_DWORD *)(a1 + 8));
  *(_QWORD *)(MEMORY[0x12B8] + 32LL) = v4;
  *(_QWORD *)(MEMORY[0x12B8] + 40LL) = *(_QWORD *)(MEMORY[0x12B8] + 32LL);
  *(_QWORD *)(MEMORY[0x12B8] + 16LL) = v1;
  return sub_108CF8(0x80u);
}


/* ===== sub_108E30 @ 0x108E30 (file 0x8E30) size 144 ===== */
__int64 __fastcall sub_108E30(__int64 a1)
{
  unsigned __int16 v3; // [xsp+2Eh] [xbp+2Eh]

  v3 = sub_1088C4(*(_WORD *)(a1 + 2));
  sub_10D4C8(*(_QWORD *)(MEMORY[0x12B8] + 40LL), a1 + 4, v3);
  *(_QWORD *)(MEMORY[0x12B8] + 40LL) += v3;
  *(_QWORD *)(MEMORY[0x12B8] + 24LL) += v3;
  return sub_108CF8(0x80u);
}


/* ===== sub_108EC0 @ 0x108EC0 (file 0x8EC0) size 112 ===== */
__int64 sub_108EC0()
{
  if ( *(_QWORD *)(MEMORY[0x12B8] + 24LL) == *(_QWORD *)(MEMORY[0x12B8] + 16LL) )
  {
    *MEMORY[0x12B8] = 143;
    return sub_108CF8(0x80u);
  }
  else
  {
    *(_DWORD *)(MEMORY[0x12B8] + 8LL) = 5;
    return sub_108CF8(0x8Bu);
  }
}


/* ===== sub_108F30 @ 0x108F30 (file 0x8F30) size 48 ===== */
__int64 sub_108F30()
{
  sub_108CF8(0x80u);
  return sub_10E3F0(*(_QWORD *)(MEMORY[0x12B8] + 32LL));
}


/* ===== sub_108F60 @ 0x108F60 (file 0x8F60) size 8 ===== */
__int64 sub_108F60()
{
  return 6;
}


/* ===== sub_108F70 @ 0x108F70 (file 0x8F70) size 184 ===== */
__int64 sub_108F70()
{
  __int64 result; // x0

  *MEMORY[0x13A0] = 133;
  *(_DWORD *)(MEMORY[0x13A0] + 8LL) = 226;
  *(_DWORD *)(MEMORY[0x13A0] + 12LL) = 1024;
  *(_QWORD *)(MEMORY[0x13A0] + 24LL) = *MEMORY[0x1360];
  sub_10967C((unsigned int)*MEMORY[0x12F0]);
  while ( 1 )
  {
    result = (unsigned int)*MEMORY[0x13A0];
    if ( (_DWORD)result == 144 )
      break;
    *(_DWORD *)(MEMORY[0x13A0] + 8LL) >>= 1;
    sub_10967C((unsigned int)*MEMORY[0x12F0]);
  }
  return result;
}


/* ===== sub_109028 @ 0x109028 (file 0x9028) size 356 ===== */
__int64 __fastcall sub_109028(unsigned __int8 *a1, int a2)
{
  __int16 v2; // w0
  unsigned __int8 *v3; // x0
  __int64 result; // x0
  int v6; // [xsp+14h] [xbp+14h]
  unsigned __int8 *v7; // [xsp+18h] [xbp+18h]

  v7 = a1;
  v2 = sub_10D400(a1, (unsigned int)(a2 - 2));
  v7[a2 - 2] = HIBYTE(v2);
  v7[a2 - 1] = v2;
  v7[a2] = 126;
  v6 = a2 + 1;
  while ( (*(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 8LL) & 0x8000) == 0 )
    ;
  *(_DWORD *)(unsigned int)*MEMORY[0x12F0] = 126;
  while ( v6 != 0 )
  {
    while ( (*(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 8LL) & 0x8000) == 0 )
      ;
    v3 = v7++;
    *(_DWORD *)(unsigned int)*MEMORY[0x12F0] = *v3;
    --v6;
  }
  do
    result = (unsigned __int16)*(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 8LL) & 0x8000;
  while ( (*(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 8LL) & 0x8000) == 0 );
  return result;
}


/* ===== sub_10918C @ 0x10918C (file 0x918C) size 172 ===== */
__int64 __fastcall sub_10918C(_QWORD *a1, _DWORD *a2)
{
  *(_QWORD *)(MEMORY[0x13A0] + 32LL) = *(_QWORD *)(MEMORY[0x13A0] + 24LL);
  *(_DWORD *)(MEMORY[0x13A0] + 16LL) = 0;
  *(_DWORD *)(MEMORY[0x13A0] + 4LL) = 0;
  sub_109238();
  if ( (unsigned int)sub_10D400(*(_QWORD *)(MEMORY[0x13A0] + 24LL), *(unsigned int *)(MEMORY[0x13A0] + 16LL)) != 0 )
    return 139;
  *a1 = *(_QWORD *)(MEMORY[0x13A0] + 24LL);
  *a2 = *(_DWORD *)(MEMORY[0x13A0] + 16LL);
  return 143;
}


/* ===== sub_109238 @ 0x109238 (file 0x9238) size 1000 ===== */
__int64 sub_109238()
{
  __int64 result; // x0
  int v1; // w0
  _BYTE *v2; // x0
  _BYTE *v3; // x0
  unsigned int v4; // [xsp+8h] [xbp-8h]
  int v5; // [xsp+Ch] [xbp-4h]

  while ( (*(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 8LL) & 0x1000) == 0 )
    ;
  if ( *MEMORY[0x13A0] == 133 )
  {
    while ( 1 )
    {
      while ( (*(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 8LL) & 0x1000) != 0 )
        ;
      if ( (*(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 8LL) & 0x80) == 0 )
        break;
      *(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 0x14LL) |= 0x80u;
    }
    if ( *(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 4LL) == 126 )
    {
      result = MEMORY[0x13A0];
      *MEMORY[0x13A0] = 144;
    }
    else
    {
      v4 = 15000;
      do
        result = v4--;
      while ( (_DWORD)result != 0 );
    }
  }
  else
  {
    while ( 1 )
    {
      result = *(unsigned int *)(MEMORY[0x13A0] + 4LL);
      if ( (_DWORD)result == 3 )
        break;
      while ( 1 )
      {
        while ( (*(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 8LL) & 0x1000) != 0 )
          ;
        v5 = *(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 4LL);
        if ( (*(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 8LL) & 0x80) == 0 )
          break;
        *(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 0x14LL) |= 0x80u;
      }
      v1 = *(_DWORD *)(MEMORY[0x13A0] + 4LL);
      if ( v1 == 1 )
      {
        if ( v5 != 126 )
        {
          if ( v5 == 125 )
          {
            while ( (*(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 8LL) & 0x1000) != 0 )
              ;
            v5 = *(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 4LL) ^ 0x20;
          }
          *(_DWORD *)(MEMORY[0x13A0] + 4LL) = 2;
          v2 = *(_BYTE **)(MEMORY[0x13A0] + 32LL);
          *(_QWORD *)(MEMORY[0x13A0] + 32LL) = v2 + 1;
          *v2 = v5;
          ++*(_DWORD *)(MEMORY[0x13A0] + 16LL);
        }
      }
      else if ( v1 != 0 )
      {
        if ( v1 == 2 )
        {
          if ( v5 == 126 )
          {
            *(_DWORD *)(MEMORY[0x13A0] + 4LL) = 3;
          }
          else
          {
            if ( v5 == 125 )
            {
              while ( (*(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 8LL) & 0x1000) != 0 )
                ;
              v5 = *(_DWORD *)((unsigned int)*MEMORY[0x12F0] + 4LL) ^ 0x20;
            }
            v3 = *(_BYTE **)(MEMORY[0x13A0] + 32LL);
            *(_QWORD *)(MEMORY[0x13A0] + 32LL) = v3 + 1;
            *v3 = v5;
            ++*(_DWORD *)(MEMORY[0x13A0] + 16LL);
          }
        }
      }
      else if ( v5 == 126 )
      {
        *(_DWORD *)(MEMORY[0x13A0] + 4LL) = 1;
      }
    }
  }
  return result;
}


/* ===== sub_109620 @ 0x109620 (file 0x9620) size 92 ===== */
__int64 __fastcall sub_109620(unsigned int a1)
{
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 36) = 226;
  *(_DWORD *)(a1 + 0x18LL) = 28;
  *(_DWORD *)(a1 + 0x1CLL) = 0;
  *(_DWORD *)(a1 + 0x20LL) = 0;
  return a1 + 32LL;
}


/* ===== sub_10967C @ 0x10967C (file 0x967C) size 120 ===== */
__int64 __fastcall sub_10967C(unsigned int a1)
{
  MEMORY[0x71300000] |= 0xC000u;
  *(_DWORD *)(a1 + 0x10LL) = 0;
  *(_DWORD *)(a1 + 0x24LL) = *(_DWORD *)(MEMORY[0x13A0] + 8LL);
  *(_DWORD *)(a1 + 0x18LL) = 28;
  *(_DWORD *)(a1 + 0x1CLL) = 0;
  *(_DWORD *)(a1 + 0x20LL) = 0;
  return sub_109238();
}


/* ===== sub_1096F4 @ 0x1096F4 (file 0x96F4) size 108 ===== */
__int64 __fastcall sub_1096F4(unsigned int a1, unsigned __int8 *a2, unsigned int a3)
{
  unsigned __int8 *v3; // x0
  __int64 result; // x0

  while ( 1 )
  {
    result = a3;
    if ( a3 == 0 )
      break;
    while ( (*(_DWORD *)(a1 + 8LL) & 0x8000) == 0 )
      ;
    v3 = a2++;
    *(_DWORD *)a1 = *v3;
    --a3;
  }
  return result;
}


/* ===== sub_109760 @ 0x109760 (file 0x9760) size 124 ===== */
__int64 sub_109760()
{
  unsigned int i; // [xsp+Ch] [xbp-4h]

  MEMORY[0x402E0000] |= 0x2000u;
  MEMORY[0x402E0008] |= 0x4000u;
  for ( i = 0; i <= 0x63; ++i )
    ;
  MEMORY[0x402E0008] &= ~0x4000u;
  return 1076756488;
}


/* ===== sub_1097DC @ 0x1097DC (file 0x97DC) size 24 ===== */
__int64 sub_1097DC()
{
  MEMORY[0x402E0000] &= ~0x2000u;
  return 1076756480;
}


/* ===== sub_1097F4 @ 0x1097F4 (file 0x97F4) size 296 ===== */
__int64 __fastcall sub_1097F4(unsigned int a1, _DWORD *a2, int a3)
{
  int v4; // [xsp+18h] [xbp-8h]

  if ( a1 > 0x30 )
    return 6;
  MEMORY[0x40240048] = 0xFFFF;
  MEMORY[0x40240050] |= 2u;
  MEMORY[0x40240040] = 1;
  if ( a3 == 1 )
    MEMORY[0x40240040] |= 4u;
  else
    MEMORY[0x40240040] &= ~4u;
  MEMORY[0x40240054] |= 4u;
  v4 = *(_DWORD *)(4 * a1 + 1076105216);
  MEMORY[0x40240054] &= ~4u;
  *a2 = v4;
  return 0;
}


/* ===== sub_10991C @ 0x10991C (file 0x991C) size 88 ===== */
__int64 __fastcall sub_10991C(__int64 a1)
{
  unsigned int i; // [xsp+2Ch] [xbp+2Ch]

  for ( i = 2; i <= 0x23; ++i )
    sub_1097F4(i, (_DWORD *)(a1 + 4LL * i), 1);
  return 0;
}


/* ===== sub_109974 @ 0x109974 (file 0x9974) size 84 ===== */
__int64 __fastcall sub_109974(__int64 a1)
{
  unsigned int i; // [xsp+2Ch] [xbp+2Ch]

  for ( i = 0; i <= 2; ++i )
    sub_1097F4(i, (_DWORD *)(a1 + 4LL * i), 0);
  return 0;
}


/* ===== sub_1099C8 @ 0x1099C8 (file 0x99C8) size 460 ===== */
__int64 __fastcall sub_1099C8(unsigned int a1, int a2, int a3)
{
  if ( a1 > 0x30 )
    return 6;
  MEMORY[0x40240048] = 0xFFFF;
  MEMORY[0x40240050] |= 2u;
  MEMORY[0x40240040] = 19;
  if ( a3 == 1 )
    MEMORY[0x40240040] |= 4u;
  else
    MEMORY[0x40240040] &= ~4u;
  MEMORY[0x4024004C] = 34832;
  MEMORY[0x40240054] |= 4u;
  MEMORY[0x40240054] &= ~2u;
  sub_10D9D0(1);
  MEMORY[0x40240054] |= 1u;
  sub_10D9D0(1);
  *(_DWORD *)(4 * a1 + 1076105216) = a2;
  MEMORY[0x40240054] &= ~1u;
  sub_10D9D0(1);
  MEMORY[0x40240054] |= 2u;
  sub_10D9D0(1);
  MEMORY[0x40240054] &= ~4u;
  MEMORY[0x4024004C] = 0;
  return 0;
}


/* ===== sub_109B94 @ 0x109B94 (file 0x9B94) size 40 ===== */
__int64 __fastcall sub_109B94(unsigned int a1, int a2)
{
  return sub_1099C8(a1, a2, 1);
}


/* ===== sub_109BBC @ 0x109BBC (file 0x9BBC) size 40 ===== */
__int64 __fastcall sub_109BBC(unsigned int a1, int a2)
{
  return sub_1099C8(a1, a2, 0);
}


/* ===== sub_109BE4 @ 0x109BE4 (file 0x9BE4) size 536 ===== */
__int64 sub_109BE4()
{
  sub_109B94(0x18u, 0);
  sub_109B94(0x19u, 0);
  sub_109B94(0x1Au, 0);
  sub_109B94(0x1Bu, 0);
  sub_109B94(0x1Cu, 0);
  sub_109B94(0x1Du, 0);
  sub_109B94(0x1Eu, 0);
  sub_109B94(0x1Fu, 0);
  sub_109B94(0x10u, 1466975291);
  sub_109B94(0x11u, 564832926);
  sub_109B94(0x12u, -1901259723);
  sub_109B94(0x13u, -567158153);
  sub_109B94(0x14u, -24765094);
  sub_109B94(0x15u, -1309566323);
  sub_109B94(0x16u, -1260917267);
  sub_109B94(0x17u, 1276455581);
  sub_109B94(8u, 448553605);
  sub_109B94(9u, -1875839732);
  sub_109B94(0xAu, 155172119);
  sub_109B94(0xBu, -1640382273);
  sub_109B94(0xCu, -1724818657);
  sub_109B94(0xDu, 1517154272);
  sub_109B94(0xEu, 1650889739);
  sub_109B94(0xFu, 1805924899);
  sub_109B94(2u, 448553605);
  sub_109B94(3u, -1875839732);
  sub_109B94(4u, 155172119);
  sub_109B94(5u, -1640382273);
  sub_109B94(0x20u, -1724818657);
  sub_109B94(0x21u, 1517154272);
  sub_109B94(0x22u, 1650889739);
  sub_109B94(0x23u, 1805924899);
  sub_109B94(7u, 0);
  sub_109B94(6u, 65538);
  return sub_109BBC(1u, -1);
}


/* ===== sub_109DFC @ 0x109DFC (file 0x9DFC) size 100 ===== */
__int64 sub_109DFC()
{
  int v0; // w0
  int v2; // [xsp+Ch] [xbp-4h]

  MEMORY[0x20E0303C] |= 1u;
  v2 = 50;
  do
    v0 = v2--;
  while ( v0 != 0 );
  MEMORY[0x20E0303C] &= ~1u;
  return 551563324;
}


/* ===== sub_109E60 @ 0x109E60 (file 0x9E60) size 32 ===== */
__int64 sub_109E60()
{
  MEMORY[0x20E03038] |= 1u;
  return 551563320;
}


/* ===== sub_109E80 @ 0x109E80 (file 0x9E80) size 24 ===== */
__int64 sub_109E80()
{
  MEMORY[0x21E00018] = 4129263;
  return 568328216;
}


/* ===== sub_109E98 @ 0x109E98 (file 0x9E98) size 24 ===== */
__int64 sub_109E98()
{
  MEMORY[0x21E00044] = 3149854;
  return 568328260;
}


/* ===== sub_109EB0 @ 0x109EB0 (file 0x9EB0) size 140 ===== */
__int64 __fastcall sub_109EB0(int a1, int a2, int a3, int a4)
{
  MEMORY[0x21E00050] = a3;
  MEMORY[0x21E00048] = a4 & 0xFFFFFF;
  MEMORY[0x21E00054] = a1;
  MEMORY[0x21E0004C] = a2 & 0xFFFFFF;
  return 568328268;
}


/* ===== sub_109F3C @ 0x109F3C (file 0x9F3C) size 52 ===== */
__int64 __fastcall sub_109F3C(int a1, int a2)
{
  MEMORY[0x21E00064] = a1;
  MEMORY[0x21E00060] = a2;
  return 568328288;
}


/* ===== sub_109F70 @ 0x109F70 (file 0x9F70) size 20 ===== */
__int64 sub_109F70()
{
  MEMORY[0x21E00028] = 1;
  return 568328232;
}


/* ===== sub_109F84 @ 0x109F84 (file 0x9F84) size 20 ===== */
__int64 sub_109F84()
{
  MEMORY[0x21E0001C] = 1;
  return 568328220;
}


/* ===== sub_109F98 @ 0x109F98 (file 0x9F98) size 40 ===== */
__int64 sub_109F98()
{
  MEMORY[0x21E00030] = 0;
  MEMORY[0x21E00038] = 0;
  MEMORY[0x21E000CC] = 0;
  return 568328396;
}


/* ===== sub_109FC0 @ 0x109FC0 (file 0x9FC0) size 212 ===== */
__int64 sub_109FC0()
{
  int v1; // [xsp+14h] [xbp+14h]
  unsigned int v2; // [xsp+18h] [xbp+18h]
  int v3; // [xsp+1Ch] [xbp+1Ch]

  v2 = 1;
  v3 = MEMORY[0x21E00020] & 0x2001;
  v1 = sub_10D9B0(MEMORY[0x21E00020] & 0x2001);
  do
  {
    if ( v3 != 0 )
      break;
    v3 = MEMORY[0x21E00020] & 0x2001;
  }
  while ( (unsigned int)sub_10D9B0(MEMORY[0x21E00020] & 0x2001) - v1 <= 0x3E8 );
  if ( v3 != 0 )
    MEMORY[0x21E00024] = -1;
  else
    v2 = 0;
  sub_109F98();
  return v2;
}


/* ===== sub_10A094 @ 0x10A094 (file 0xA094) size 32 ===== */
__int64 sub_10A094()
{
  MEMORY[0x20E03038] &= ~1u;
  return 551563320;
}


/* ===== sub_10A0B4 @ 0x10A0B4 (file 0xA0B4) size 20 ===== */
__int64 sub_10A0B4()
{
  MEMORY[0x21E00038] = 65;
  return 568328248;
}


/* ===== sub_10A0C8 @ 0x10A0C8 (file 0xA0C8) size 64 ===== */
__int64 __fastcall sub_10A0C8(int a1, int a2, int a3)
{
  sub_109EB0(a1, 32, a2, a3);
  sub_109E98();
  sub_10A0B4();
  sub_109F70();
  return sub_109FC0();
}


/* ===== sub_10A108 @ 0x10A108 (file 0xA108) size 152 ===== */
__int64 __fastcall sub_10A108(__int64 a1, int a2)
{
  __int64 result; // x0
  char v4; // [xsp+17h] [xbp-9h]
  unsigned int i; // [xsp+18h] [xbp-8h]
  int v6; // [xsp+1Ch] [xbp-4h]

  v6 = 0;
  for ( i = a2 - 1; ; --i )
  {
    result = i;
    if ( v6 >= (int)i )
      break;
    v4 = *(_BYTE *)(a1 + v6);
    *(_BYTE *)(a1 + v6) = *(_BYTE *)(a1 + (int)i);
    *(_BYTE *)(a1 + (int)i) = v4;
    ++v6;
  }
  return result;
}


/* ===== sub_10A1A0 @ 0x10A1A0 (file 0xA1A0) size 108 ===== */
__int64 __fastcall sub_10A1A0(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  int i; // [xsp+3Ch] [xbp+3Ch]

  sub_10FAA4(a1, a2, 4LL * a3);
  for ( i = a3; ; ++i )
  {
    result = (unsigned int)i;
    if ( i > 65 )
      break;
    *(_DWORD *)(a1 + 4LL * i) = 0;
  }
  return result;
}


/* ===== sub_10A20C @ 0x10A20C (file 0xA20C) size 76 ===== */
__int64 __fastcall sub_10A20C(__int64 a1, __int64 a2, int a3)
{
  sub_10A108(a2, a3);
  sub_10A1A0(a1, a2, a3 >> 2);
  return sub_10A108(a2, a3);
}


/* ===== sub_10A258 @ 0x10A258 (file 0xA258) size 180 ===== */
__int64 __fastcall sub_10A258(int a1, int a2)
{
  __int64 v3; // [xsp+10h] [xbp-20h]
  __int64 v4; // [xsp+18h] [xbp-18h]
  int v5; // [xsp+20h] [xbp-10h]
  int v6; // [xsp+28h] [xbp-8h]
  unsigned int i; // [xsp+2Ch] [xbp-4h]

  v3 = 0;
  v4 = 0;
  v5 = 0;
  i = 0;
  v6 = 0;
  do
    v6 = MEMORY[0x21E00604];
  while ( 10 - MEMORY[0x21E00604] <= 0 );
  LODWORD(v3) = 542113792;
  HIDWORD(v3) = a1;
  LODWORD(v4) = a2;
  for ( i = 0; i <= 2; ++i )
    MEMORY[0x21E00600] = *((_DWORD *)&v3 + i);
  return 1;
}


/* ===== sub_10A30C @ 0x10A30C (file 0xA30C) size 856 ===== */
__int64 __fastcall sub_10A30C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  __int64 v11; // [xsp+40h] [xbp+40h]
  unsigned __int64 v12; // [xsp+48h] [xbp+48h]
  unsigned __int64 v13; // [xsp+50h] [xbp+50h]
  __int64 v14; // [xsp+58h] [xbp+58h]

  v14 = MEMORY[0x13C0];
  v13 = MEMORY[0x13C0] + 512LL;
  v12 = MEMORY[0x13C0] + 256LL;
  v11 = MEMORY[0x13C0] + 768LL;
  sub_10FA50(0x2428u, 0, 40);
  sub_10FA50(MEMORY[0x13C0], 0, 2048);
  if ( a4 != 0 )
    sub_10A20C(v11, a4, 4);
  if ( a3 != 0 )
    sub_10A20C(v14, a3, a5);
  sub_10A20C(v12, a2, a5);
  MEMORY[0x2428] = (4 * ((v12 >> 17) & 0x7FFF)) | 0xE0C0001;
  MEMORY[0x242C] = (4 * ((v13 >> 17) & 0x7FFF)) | 0xE100001;
  MEMORY[0x2430] = (4 * (unsigned __int16)a5) | 0x8D00001;
  MEMORY[0x2434] = v14 & 0x1FFFF | 0xB0000000;
  MEMORY[0x2438] = v12 & 0x1FFFF | 0xB0040000;
  MEMORY[0x243C] = v11 & 0x1FFFF | 0xB0080000;
  MEMORY[0x2440] = 1477185664;
  MEMORY[0x2444] = v13 & 0x1FFFF | 0xB80C0000;
  MEMORY[0x2448] = -1;
  sub_10A258(134217729, 0x2428);
  sub_109FC0();
  sub_10FAA4(a1, v13, a5);
  return sub_10A108(a1, a5);
}


/* ===== sub_10A664 @ 0x10A664 (file 0xA664) size 856 ===== */
__int64 __fastcall sub_10A664(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  unsigned __int64 v11; // [xsp+40h] [xbp+40h]
  unsigned __int64 v12; // [xsp+48h] [xbp+48h]
  __int64 v13; // [xsp+50h] [xbp+50h]
  __int64 v14; // [xsp+58h] [xbp+58h]

  v14 = MEMORY[0x13C0];
  v13 = MEMORY[0x13C0] + 768LL;
  v12 = MEMORY[0x13C0] + 256LL;
  v11 = MEMORY[0x13C0] + 512LL;
  sub_10FA50(0x2428u, 0, 40);
  sub_10FA50(MEMORY[0x13C0], 0, 2048);
  if ( a4 != 0 )
    sub_10A20C(v13, a4, 4);
  if ( a3 != 0 )
    sub_10A20C(v14, a3, a5);
  sub_10A20C(v12, a2, a5);
  MEMORY[0x2428] = (4 * ((v11 >> 17) & 0x7FFF)) | 0xE0C0001;
  MEMORY[0x242C] = (4 * ((v12 >> 17) & 0x7FFF)) | 0xE100001;
  MEMORY[0x2430] = (4 * (unsigned __int16)a5) | 0x8D00001;
  MEMORY[0x2434] = v14 & 0x1FFFF | 0xB0000000;
  MEMORY[0x2438] = v13 & 0x1FFFF | 0xB0040000;
  MEMORY[0x243C] = v11 & 0x1FFFF | 0xB0080000;
  MEMORY[0x2440] = 1477189696;
  MEMORY[0x2444] = v12 & 0x1FFFF | 0xB80C0000;
  MEMORY[0x2448] = -1;
  sub_10A258(134217729, 0x2428);
  sub_109FC0();
  sub_10FAA4(a1, v12, a5);
  return sub_10A108(a1, a5);
}


/* ===== sub_10A9BC @ 0x10A9BC (file 0xA9BC) size 40 ===== */
__int64 sub_10A9BC()
{
  MEMORY[0x21E00030] = 8465;
  MEMORY[0x21E00044] = 3150358;
  return 568328260;
}


/* ===== sub_10A9E4 @ 0x10A9E4 (file 0xA9E4) size 160 ===== */
__int64 __fastcall sub_10A9E4(unsigned __int8 *a1)
{
  __int64 result; // x0
  int v3; // [xsp+18h] [xbp-8h]
  unsigned int i; // [xsp+1Ch] [xbp-4h]

  v3 = 0;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i > 0xF )
      break;
    v3 |= *a1++ << (8 * (~(_BYTE)i & 3));
    if ( (i & 3) == 3 )
    {
      *(_DWORD *)(i + 568328301) = v3;
      v3 = 0;
    }
  }
  return result;
}


/* ===== sub_10AA84 @ 0x10AA84 (file 0xAA84) size 88 ===== */
__int64 __fastcall sub_10AA84(char a1, int a2)
{
  int v3; // [xsp+1Ch] [xbp-4h]

  v3 = (2 * (unsigned __int8)(4 * a1)) | (a2 << 21);
  MEMORY[0x21E00340] = v3;
  return 568329024;
}


/* ===== sub_10AADC @ 0x10AADC (file 0xAADC) size 88 ===== */
__int64 __fastcall sub_10AADC(int a1, int a2, int a3, unsigned __int8 *a4, char a5)
{
  sub_109EB0(a2, a3, a1, a3);
  sub_10A9BC();
  sub_10A9E4(a4);
  sub_10AA84(a5, 32);
  sub_109F70();
  return sub_109FC0();
}


/* ===== sub_10AB34 @ 0x10AB34 (file 0xAB34) size 28 ===== */
__int64 sub_10AB34()
{
  sub_109E60();
  sub_109DFC();
  return sub_109E80();
}


/* ===== sub_10AB50 @ 0x10AB50 (file 0xAB50) size 20 ===== */
__int64 sub_10AB50()
{
  return sub_10A094();
}


/* ===== sub_10AB64 @ 0x10AB64 (file 0xAB64) size 180 ===== */
__int64 __fastcall sub_10AB64(__int64 a1, __int64 a2, int a3, __int64 a4, unsigned int a5, __int64 a6)
{
  _BYTE v12[260]; // [xsp+48h] [xbp+48h] BYREF
  unsigned int v13; // [xsp+14Ch] [xbp+14Ch]

  v13 = a3 >> 3;
  sub_10FA50(v12, 0, a3 >> 3);
  if ( (int)sub_10F44C(v12, v13, a4, a5) <= 0 )
    return 0;
  sub_10A664(a6, (__int64)v12, a2, a1, v13);
  return 1;
}


/* ===== sub_10AC18 @ 0x10AC18 (file 0xAC18) size 160 ===== */
__int64 __fastcall sub_10AC18(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  char v10; // [xsp+48h] [xbp+48h] BYREF
  _BYTE v11[7]; // [xsp+49h] [xbp+49h] BYREF
  unsigned int v12; // [xsp+14Ch] [xbp+14Ch]

  v12 = a3 >> 3;
  sub_10FA50(&v10, 0, a3 >> 3);
  sub_10A30C((__int64)&v10, a4, a2, a1, v12);
  return sub_10F510(a5, v12, v11, v12 - 1, v12);
}


/* ===== sub_10ACB8 @ 0x10ACB8 (file 0xACB8) size 44 ===== */
__int64 __fastcall sub_10ACB8(int a1, int a2, int a3)
{
  return sub_10A0C8(a3, a1, a2);
}


/* ===== sub_10ACE4 @ 0x10ACE4 (file 0xACE4) size 60 ===== */
__int64 __fastcall sub_10ACE4(int a1, int a2, int a3, unsigned __int8 *a4, char a5)
{
  return sub_10AADC(a1, a2, a3, a4, a5);
}


/* ===== sub_10AD20 @ 0x10AD20 (file 0xAD20) size 40 ===== */
__int64 sub_10AD20()
{
  MEMORY[0x21E00030] = 13313;
  MEMORY[0x21E00044] = 3150354;
  return 568328260;
}


/* ===== sub_10AD48 @ 0x10AD48 (file 0xAD48) size 140 ===== */
__int64 __fastcall sub_10AD48(int a1, unsigned __int8 a2, int a3, int a4)
{
  MEMORY[0x21E00050] = a3;
  MEMORY[0x21E00048] = a4 & 0xFFFFFF;
  MEMORY[0x21E0006C] = a1;
  MEMORY[0x21E00068] = a2;
  return 568328296;
}


/* ===== sub_10ADD4 @ 0x10ADD4 (file 0xADD4) size 88 ===== */
__int64 __fastcall sub_10ADD4(int a1, int a2, char a3, int a4)
{
  sub_10AD20();
  sub_10AD48(a4, 0x10u, a1, a2);
  sub_10AA84(a3, 32);
  sub_109F70();
  return (unsigned int)sub_109FC0();
}


/* ===== sub_10AE2C @ 0x10AE2C (file 0xAE2C) size 124 ===== */
__int64 __fastcall sub_10AE2C(_DWORD *a1)
{
  a1[5] = 0;
  a1[6] = 0;
  a1[7] = 0;
  *a1 = 1732584193;
  a1[1] = -271733879;
  a1[2] = -1732584194;
  a1[3] = 271733878;
  a1[4] = -1009589776;
  return 0;
}


/* ===== sub_10AEA8 @ 0x10AEA8 (file 0xAEA8) size 8332 ===== */
__int64 __fastcall sub_10AEA8(_DWORD *a1)
{
  unsigned __int64 v1; // t2
  unsigned __int64 v2; // t2
  int v4; // [xsp+14h] [xbp-2Ch]
  int v5; // [xsp+14h] [xbp-2Ch]
  int v6; // [xsp+14h] [xbp-2Ch]
  int v7; // [xsp+14h] [xbp-2Ch]
  int v8; // [xsp+14h] [xbp-2Ch]
  int v9; // [xsp+14h] [xbp-2Ch]
  int v10; // [xsp+14h] [xbp-2Ch]
  int v11; // [xsp+14h] [xbp-2Ch]
  int v12; // [xsp+14h] [xbp-2Ch]
  int v13; // [xsp+14h] [xbp-2Ch]
  int v14; // [xsp+14h] [xbp-2Ch]
  int v15; // [xsp+14h] [xbp-2Ch]
  int v16; // [xsp+14h] [xbp-2Ch]
  int v17; // [xsp+14h] [xbp-2Ch]
  int v18; // [xsp+14h] [xbp-2Ch]
  int v19; // [xsp+14h] [xbp-2Ch]
  int v20; // [xsp+14h] [xbp-2Ch]
  int v21; // [xsp+14h] [xbp-2Ch]
  int v22; // [xsp+14h] [xbp-2Ch]
  int v23; // [xsp+14h] [xbp-2Ch]
  int v24; // [xsp+14h] [xbp-2Ch]
  int v25; // [xsp+14h] [xbp-2Ch]
  int v26; // [xsp+14h] [xbp-2Ch]
  int v27; // [xsp+14h] [xbp-2Ch]
  int v28; // [xsp+14h] [xbp-2Ch]
  int v29; // [xsp+14h] [xbp-2Ch]
  int v30; // [xsp+14h] [xbp-2Ch]
  int v31; // [xsp+14h] [xbp-2Ch]
  int v32; // [xsp+14h] [xbp-2Ch]
  int v33; // [xsp+14h] [xbp-2Ch]
  int v34; // [xsp+14h] [xbp-2Ch]
  int v35; // [xsp+14h] [xbp-2Ch]
  int v36; // [xsp+18h] [xbp-28h]
  int v37; // [xsp+18h] [xbp-28h]
  int v38; // [xsp+18h] [xbp-28h]
  int v39; // [xsp+18h] [xbp-28h]
  int v40; // [xsp+18h] [xbp-28h]
  int v41; // [xsp+18h] [xbp-28h]
  int v42; // [xsp+18h] [xbp-28h]
  int v43; // [xsp+18h] [xbp-28h]
  int v44; // [xsp+18h] [xbp-28h]
  int v45; // [xsp+18h] [xbp-28h]
  int v46; // [xsp+18h] [xbp-28h]
  int v47; // [xsp+18h] [xbp-28h]
  int v48; // [xsp+18h] [xbp-28h]
  int v49; // [xsp+18h] [xbp-28h]
  int v50; // [xsp+18h] [xbp-28h]
  int v51; // [xsp+18h] [xbp-28h]
  int v52; // [xsp+18h] [xbp-28h]
  int v53; // [xsp+18h] [xbp-28h]
  int v54; // [xsp+18h] [xbp-28h]
  int v55; // [xsp+18h] [xbp-28h]
  int v56; // [xsp+18h] [xbp-28h]
  int v57; // [xsp+18h] [xbp-28h]
  int v58; // [xsp+18h] [xbp-28h]
  int v59; // [xsp+18h] [xbp-28h]
  int v60; // [xsp+18h] [xbp-28h]
  int v61; // [xsp+18h] [xbp-28h]
  int v62; // [xsp+18h] [xbp-28h]
  int v63; // [xsp+18h] [xbp-28h]
  int v64; // [xsp+18h] [xbp-28h]
  int v65; // [xsp+18h] [xbp-28h]
  int v66; // [xsp+18h] [xbp-28h]
  int v67; // [xsp+18h] [xbp-28h]
  int v68; // [xsp+18h] [xbp-28h]
  int v69; // [xsp+1Ch] [xbp-24h]
  int v70; // [xsp+1Ch] [xbp-24h]
  int v71; // [xsp+1Ch] [xbp-24h]
  int v72; // [xsp+1Ch] [xbp-24h]
  int v73; // [xsp+1Ch] [xbp-24h]
  int v74; // [xsp+1Ch] [xbp-24h]
  int v75; // [xsp+1Ch] [xbp-24h]
  int v76; // [xsp+1Ch] [xbp-24h]
  int v77; // [xsp+1Ch] [xbp-24h]
  int v78; // [xsp+1Ch] [xbp-24h]
  int v79; // [xsp+1Ch] [xbp-24h]
  int v80; // [xsp+1Ch] [xbp-24h]
  int v81; // [xsp+1Ch] [xbp-24h]
  int v82; // [xsp+1Ch] [xbp-24h]
  int v83; // [xsp+1Ch] [xbp-24h]
  int v84; // [xsp+1Ch] [xbp-24h]
  int v85; // [xsp+1Ch] [xbp-24h]
  int v86; // [xsp+1Ch] [xbp-24h]
  int v87; // [xsp+1Ch] [xbp-24h]
  int v88; // [xsp+1Ch] [xbp-24h]
  int v89; // [xsp+1Ch] [xbp-24h]
  int v90; // [xsp+1Ch] [xbp-24h]
  int v91; // [xsp+1Ch] [xbp-24h]
  int v92; // [xsp+1Ch] [xbp-24h]
  int v93; // [xsp+1Ch] [xbp-24h]
  int v94; // [xsp+1Ch] [xbp-24h]
  int v95; // [xsp+1Ch] [xbp-24h]
  int v96; // [xsp+1Ch] [xbp-24h]
  int v97; // [xsp+1Ch] [xbp-24h]
  int v98; // [xsp+1Ch] [xbp-24h]
  int v99; // [xsp+1Ch] [xbp-24h]
  int v100; // [xsp+1Ch] [xbp-24h]
  int v101; // [xsp+20h] [xbp-20h]
  int v102; // [xsp+20h] [xbp-20h]
  int v103; // [xsp+20h] [xbp-20h]
  int v104; // [xsp+20h] [xbp-20h]
  int v105; // [xsp+20h] [xbp-20h]
  int v106; // [xsp+20h] [xbp-20h]
  int v107; // [xsp+20h] [xbp-20h]
  int v108; // [xsp+20h] [xbp-20h]
  int v109; // [xsp+20h] [xbp-20h]
  int v110; // [xsp+20h] [xbp-20h]
  int v111; // [xsp+20h] [xbp-20h]
  int v112; // [xsp+20h] [xbp-20h]
  int v113; // [xsp+20h] [xbp-20h]
  int v114; // [xsp+20h] [xbp-20h]
  int v115; // [xsp+20h] [xbp-20h]
  int v116; // [xsp+20h] [xbp-20h]
  int v117; // [xsp+20h] [xbp-20h]
  int v118; // [xsp+20h] [xbp-20h]
  int v119; // [xsp+20h] [xbp-20h]
  int v120; // [xsp+20h] [xbp-20h]
  int v121; // [xsp+20h] [xbp-20h]
  int v122; // [xsp+20h] [xbp-20h]
  int v123; // [xsp+20h] [xbp-20h]
  int v124; // [xsp+20h] [xbp-20h]
  int v125; // [xsp+20h] [xbp-20h]
  int v126; // [xsp+20h] [xbp-20h]
  int v127; // [xsp+20h] [xbp-20h]
  int v128; // [xsp+20h] [xbp-20h]
  int v129; // [xsp+20h] [xbp-20h]
  int v130; // [xsp+20h] [xbp-20h]
  int v131; // [xsp+20h] [xbp-20h]
  int v132; // [xsp+20h] [xbp-20h]
  int v133; // [xsp+24h] [xbp-1Ch]
  int v134; // [xsp+24h] [xbp-1Ch]
  int v135; // [xsp+24h] [xbp-1Ch]
  int v136; // [xsp+24h] [xbp-1Ch]
  int v137; // [xsp+24h] [xbp-1Ch]
  int v138; // [xsp+24h] [xbp-1Ch]
  int v139; // [xsp+24h] [xbp-1Ch]
  int v140; // [xsp+24h] [xbp-1Ch]
  int v141; // [xsp+24h] [xbp-1Ch]
  int v142; // [xsp+24h] [xbp-1Ch]
  int v143; // [xsp+24h] [xbp-1Ch]
  int v144; // [xsp+24h] [xbp-1Ch]
  int v145; // [xsp+24h] [xbp-1Ch]
  int v146; // [xsp+24h] [xbp-1Ch]
  int v147; // [xsp+24h] [xbp-1Ch]
  int v148; // [xsp+24h] [xbp-1Ch]
  int v149; // [xsp+24h] [xbp-1Ch]
  int v150; // [xsp+24h] [xbp-1Ch]
  int v151; // [xsp+24h] [xbp-1Ch]
  int v152; // [xsp+24h] [xbp-1Ch]
  int v153; // [xsp+24h] [xbp-1Ch]
  int v154; // [xsp+24h] [xbp-1Ch]
  int v155; // [xsp+24h] [xbp-1Ch]
  int v156; // [xsp+24h] [xbp-1Ch]
  int v157; // [xsp+24h] [xbp-1Ch]
  int v158; // [xsp+24h] [xbp-1Ch]
  int v159; // [xsp+24h] [xbp-1Ch]
  int v160; // [xsp+24h] [xbp-1Ch]
  int v161; // [xsp+24h] [xbp-1Ch]
  int v162; // [xsp+24h] [xbp-1Ch]
  int v163; // [xsp+24h] [xbp-1Ch]
  int v164; // [xsp+24h] [xbp-1Ch]
  int i; // [xsp+3Ch] [xbp-4h]

  for ( i = 16; i <= 79; ++i )
  {
    HIDWORD(v1) = a1[i + 5] ^ a1[i] ^ a1[i - 6] ^ a1[i - 8];
    LODWORD(v1) = HIDWORD(v1);
    a1[i + 8] = v1 >> 31;
  }
  v69 = a1[2];
  v36 = a1[3];
  HIDWORD(v2) = *a1;
  LODWORD(v2) = *a1;
  v4 = a1[4] + (v2 >> 27) + (a1[1] & v69 | ~a1[1] & v36) + a1[8] + 1518500249;
  HIDWORD(v2) = a1[1];
  LODWORD(v2) = HIDWORD(v2);
  v101 = v2 >> 2;
  HIDWORD(v2) = v4;
  LODWORD(v2) = v4;
  v37 = v36 + (v2 >> 27) + (*a1 & v101 | ~*a1 & v69) + a1[9] + 1518500249;
  HIDWORD(v2) = *a1;
  LODWORD(v2) = *a1;
  v133 = v2 >> 2;
  HIDWORD(v2) = v37;
  LODWORD(v2) = v37;
  v70 = v69 + (v2 >> 27) + (v4 & v133 | ~v4 & v101) + a1[10] + 1518500249;
  HIDWORD(v2) = v4;
  LODWORD(v2) = v4;
  v5 = v2 >> 2;
  HIDWORD(v2) = v70;
  LODWORD(v2) = v70;
  v102 = v101 + (v2 >> 27) + (v37 & v5 | ~v37 & v133) + a1[11] + 1518500249;
  HIDWORD(v2) = v37;
  LODWORD(v2) = v37;
  v38 = v2 >> 2;
  HIDWORD(v2) = v102;
  LODWORD(v2) = v102;
  v134 = v133 + (v2 >> 27) + (v70 & v38 | ~v70 & v5) + a1[12] + 1518500249;
  HIDWORD(v2) = v70;
  LODWORD(v2) = v70;
  v71 = v2 >> 2;
  HIDWORD(v2) = v134;
  LODWORD(v2) = v134;
  v6 = v5 + (v2 >> 27) + (v102 & v71 | ~v102 & v38) + a1[13] + 1518500249;
  HIDWORD(v2) = v102;
  LODWORD(v2) = v102;
  v103 = v2 >> 2;
  HIDWORD(v2) = v6;
  LODWORD(v2) = v6;
  v39 = v38 + (v2 >> 27) + (v134 & v103 | ~v134 & v71) + a1[14] + 1518500249;
  HIDWORD(v2) = v134;
  LODWORD(v2) = v134;
  v135 = v2 >> 2;
  HIDWORD(v2) = v39;
  LODWORD(v2) = v39;
  v72 = v71 + (v2 >> 27) + (v6 & v135 | ~v6 & v103) + a1[15] + 1518500249;
  HIDWORD(v2) = v6;
  LODWORD(v2) = v6;
  v7 = v2 >> 2;
  HIDWORD(v2) = v72;
  LODWORD(v2) = v72;
  v104 = v103 + (v2 >> 27) + (v39 & v7 | ~v39 & v135) + a1[16] + 1518500249;
  HIDWORD(v2) = v39;
  LODWORD(v2) = v39;
  v40 = v2 >> 2;
  HIDWORD(v2) = v104;
  LODWORD(v2) = v104;
  v136 = v135 + (v2 >> 27) + (v72 & v40 | ~v72 & v7) + a1[17] + 1518500249;
  HIDWORD(v2) = v72;
  LODWORD(v2) = v72;
  v73 = v2 >> 2;
  HIDWORD(v2) = v136;
  LODWORD(v2) = v136;
  v8 = v7 + (v2 >> 27) + (v104 & v73 | ~v104 & v40) + a1[18] + 1518500249;
  HIDWORD(v2) = v104;
  LODWORD(v2) = v104;
  v105 = v2 >> 2;
  HIDWORD(v2) = v8;
  LODWORD(v2) = v8;
  v41 = v40 + (v2 >> 27) + (v136 & v105 | ~v136 & v73) + a1[19] + 1518500249;
  HIDWORD(v2) = v136;
  LODWORD(v2) = v136;
  v137 = v2 >> 2;
  HIDWORD(v2) = v41;
  LODWORD(v2) = v41;
  v74 = v73 + (v2 >> 27) + (v8 & v137 | ~v8 & v105) + a1[20] + 1518500249;
  HIDWORD(v2) = v8;
  LODWORD(v2) = v8;
  v9 = v2 >> 2;
  HIDWORD(v2) = v74;
  LODWORD(v2) = v74;
  v106 = v105 + (v2 >> 27) + (v41 & v9 | ~v41 & v137) + a1[21] + 1518500249;
  HIDWORD(v2) = v41;
  LODWORD(v2) = v41;
  v42 = v2 >> 2;
  HIDWORD(v2) = v106;
  LODWORD(v2) = v106;
  v138 = v137 + (v2 >> 27) + (v74 & v42 | ~v74 & v9) + a1[22] + 1518500249;
  HIDWORD(v2) = v74;
  LODWORD(v2) = v74;
  v75 = v2 >> 2;
  HIDWORD(v2) = v138;
  LODWORD(v2) = v138;
  v10 = v9 + (v2 >> 27) + (v106 & v75 | ~v106 & v42) + a1[23] + 1518500249;
  HIDWORD(v2) = v106;
  LODWORD(v2) = v106;
  v107 = v2 >> 2;
  HIDWORD(v2) = v10;
  LODWORD(v2) = v10;
  v43 = v42 + (v2 >> 27) + (v138 & v107 | ~v138 & v75) + a1[24] + 1518500249;
  HIDWORD(v2) = v138;
  LODWORD(v2) = v138;
  v139 = v2 >> 2;
  HIDWORD(v2) = v43;
  LODWORD(v2) = v43;
  v76 = v75 + (v2 >> 27) + (v10 & v139 | ~v10 & v107) + a1[25] + 1518500249;
  HIDWORD(v2) = v10;
  LODWORD(v2) = v10;
  v11 = v2 >> 2;
  HIDWORD(v2) = v76;
  LODWORD(v2) = v76;
  v108 = v107 + (v2 >> 27) + (v43 & v11 | ~v43 & v139) + a1[26] + 1518500249;
  HIDWORD(v2) = v43;
  LODWORD(v2) = v43;
  v44 = v2 >> 2;
  HIDWORD(v2) = v108;
  LODWORD(v2) = v108;
  v140 = v139 + (v2 >> 27) + (v76 & v44 | ~v76 & v11) + a1[27] + 1518500249;
  HIDWORD(v2) = v76;
  LODWORD(v2) = v76;
  v77 = v2 >> 2;
  HIDWORD(v2) = v140;
  LODWORD(v2) = v140;
  v12 = v11 + (v2 >> 27) + (v108 ^ v77 ^ v44) + a1[28] + 1859775393;
  HIDWORD(v2) = v108;
  LODWORD(v2) = v108;
  v109 = v2 >> 2;
  HIDWORD(v2) = v12;
  LODWORD(v2) = v12;
  v45 = v44 + (v2 >> 27) + (v140 ^ v109 ^ v77) + a1[29] + 1859775393;
  HIDWORD(v2) = v140;
  LODWORD(v2) = v140;
  v141 = v2 >> 2;
  HIDWORD(v2) = v45;
  LODWORD(v2) = v45;
  v78 = v77 + (v2 >> 27) + (v12 ^ v141 ^ v109) + a1[30] + 1859775393;
  HIDWORD(v2) = v12;
  LODWORD(v2) = v12;
  v13 = v2 >> 2;
  HIDWORD(v2) = v78;
  LODWORD(v2) = v78;
  v110 = v109 + (v2 >> 27) + (v45 ^ v13 ^ v141) + a1[31] + 1859775393;
  HIDWORD(v2) = v45;
  LODWORD(v2) = v45;
  v46 = v2 >> 2;
  HIDWORD(v2) = v110;
  LODWORD(v2) = v110;
  v142 = v141 + (v2 >> 27) + (v78 ^ v46 ^ v13) + a1[32] + 1859775393;
  HIDWORD(v2) = v78;
  LODWORD(v2) = v78;
  v79 = v2 >> 2;
  HIDWORD(v2) = v142;
  LODWORD(v2) = v142;
  v14 = v13 + (v2 >> 27) + (v110 ^ v79 ^ v46) + a1[33] + 1859775393;
  HIDWORD(v2) = v110;
  LODWORD(v2) = v110;
  v111 = v2 >> 2;
  HIDWORD(v2) = v14;
  LODWORD(v2) = v14;
  v47 = v46 + (v2 >> 27) + (v142 ^ v111 ^ v79) + a1[34] + 1859775393;
  HIDWORD(v2) = v142;
  LODWORD(v2) = v142;
  v143 = v2 >> 2;
  HIDWORD(v2) = v47;
  LODWORD(v2) = v47;
  v80 = v79 + (v2 >> 27) + (v14 ^ v143 ^ v111) + a1[35] + 1859775393;
  HIDWORD(v2) = v14;
  LODWORD(v2) = v14;
  v15 = v2 >> 2;
  HIDWORD(v2) = v80;
  LODWORD(v2) = v80;
  v112 = v111 + (v2 >> 27) + (v47 ^ v15 ^ v143) + a1[36] + 1859775393;
  HIDWORD(v2) = v47;
  LODWORD(v2) = v47;
  v48 = v2 >> 2;
  HIDWORD(v2) = v112;
  LODWORD(v2) = v112;
  v144 = v143 + (v2 >> 27) + (v80 ^ v48 ^ v15) + a1[37] + 1859775393;
  HIDWORD(v2) = v80;
  LODWORD(v2) = v80;
  v81 = v2 >> 2;
  HIDWORD(v2) = v144;
  LODWORD(v2) = v144;
  v16 = v15 + (v2 >> 27) + (v112 ^ v81 ^ v48) + a1[38] + 1859775393;
  HIDWORD(v2) = v112;
  LODWORD(v2) = v112;
  v113 = v2 >> 2;
  HIDWORD(v2) = v16;
  LODWORD(v2) = v16;
  v49 = v48 + (v2 >> 27) + (v144 ^ v113 ^ v81) + a1[39] + 1859775393;
  HIDWORD(v2) = v144;
  LODWORD(v2) = v144;
  v145 = v2 >> 2;
  HIDWORD(v2) = v49;
  LODWORD(v2) = v49;
  v82 = v81 + (v2 >> 27) + (v16 ^ v145 ^ v113) + a1[40] + 1859775393;
  HIDWORD(v2) = v16;
  LODWORD(v2) = v16;
  v17 = v2 >> 2;
  HIDWORD(v2) = v82;
  LODWORD(v2) = v82;
  v114 = v113 + (v2 >> 27) + (v49 ^ v17 ^ v145) + a1[41] + 1859775393;
  HIDWORD(v2) = v49;
  LODWORD(v2) = v49;
  v50 = v2 >> 2;
  HIDWORD(v2) = v114;
  LODWORD(v2) = v114;
  v146 = v145 + (v2 >> 27) + (v82 ^ v50 ^ v17) + a1[42] + 1859775393;
  HIDWORD(v2) = v82;
  LODWORD(v2) = v82;
  v83 = v2 >> 2;
  HIDWORD(v2) = v146;
  LODWORD(v2) = v146;
  v18 = v17 + (v2 >> 27) + (v114 ^ v83 ^ v50) + a1[43] + 1859775393;
  HIDWORD(v2) = v114;
  LODWORD(v2) = v114;
  v115 = v2 >> 2;
  HIDWORD(v2) = v18;
  LODWORD(v2) = v18;
  v51 = v50 + (v2 >> 27) + (v146 ^ v115 ^ v83) + a1[44] + 1859775393;
  HIDWORD(v2) = v146;
  LODWORD(v2) = v146;
  v147 = v2 >> 2;
  HIDWORD(v2) = v51;
  LODWORD(v2) = v51;
  v84 = v83 + (v2 >> 27) + (v18 ^ v147 ^ v115) + a1[45] + 1859775393;
  HIDWORD(v2) = v18;
  LODWORD(v2) = v18;
  v19 = v2 >> 2;
  HIDWORD(v2) = v84;
  LODWORD(v2) = v84;
  v116 = v115 + (v2 >> 27) + (v51 ^ v19 ^ v147) + a1[46] + 1859775393;
  HIDWORD(v2) = v51;
  LODWORD(v2) = v51;
  v52 = v2 >> 2;
  HIDWORD(v2) = v116;
  LODWORD(v2) = v116;
  v148 = v147 + (v2 >> 27) + (v84 ^ v52 ^ v19) + a1[47] + 1859775393;
  HIDWORD(v2) = v84;
  LODWORD(v2) = v84;
  v85 = v2 >> 2;
  HIDWORD(v2) = v148;
  LODWORD(v2) = v148;
  v20 = v19 + (v2 >> 27) + ((v85 | v52) & v116 | v85 & v52) + a1[48] - 1894007588;
  HIDWORD(v2) = v116;
  LODWORD(v2) = v116;
  v117 = v2 >> 2;
  HIDWORD(v2) = v20;
  LODWORD(v2) = v20;
  v53 = v52 + (v2 >> 27) + ((v117 | v85) & v148 | v117 & v85) + a1[49] - 1894007588;
  HIDWORD(v2) = v148;
  LODWORD(v2) = v148;
  v149 = v2 >> 2;
  HIDWORD(v2) = v53;
  LODWORD(v2) = v53;
  v86 = v85 + (v2 >> 27) + ((v149 | v117) & v20 | v149 & v117) + a1[50] - 1894007588;
  HIDWORD(v2) = v20;
  LODWORD(v2) = v20;
  v21 = v2 >> 2;
  HIDWORD(v2) = v86;
  LODWORD(v2) = v86;
  v118 = v117 + (v2 >> 27) + ((v21 | v149) & v53 | v21 & v149) + a1[51] - 1894007588;
  HIDWORD(v2) = v53;
  LODWORD(v2) = v53;
  v54 = v2 >> 2;
  HIDWORD(v2) = v118;
  LODWORD(v2) = v118;
  v150 = v149 + (v2 >> 27) + ((v54 | v21) & v86 | v54 & v21) + a1[52] - 1894007588;
  HIDWORD(v2) = v86;
  LODWORD(v2) = v86;
  v87 = v2 >> 2;
  HIDWORD(v2) = v150;
  LODWORD(v2) = v150;
  v22 = v21 + (v2 >> 27) + ((v87 | v54) & v118 | v87 & v54) + a1[53] - 1894007588;
  HIDWORD(v2) = v118;
  LODWORD(v2) = v118;
  v119 = v2 >> 2;
  HIDWORD(v2) = v22;
  LODWORD(v2) = v22;
  v55 = v54 + (v2 >> 27) + ((v119 | v87) & v150 | v119 & v87) + a1[54] - 1894007588;
  HIDWORD(v2) = v150;
  LODWORD(v2) = v150;
  v151 = v2 >> 2;
  HIDWORD(v2) = v55;
  LODWORD(v2) = v55;
  v88 = v87 + (v2 >> 27) + ((v151 | v119) & v22 | v151 & v119) + a1[55] - 1894007588;
  HIDWORD(v2) = v22;
  LODWORD(v2) = v22;
  v23 = v2 >> 2;
  HIDWORD(v2) = v88;
  LODWORD(v2) = v88;
  v120 = v119 + (v2 >> 27) + ((v23 | v151) & v55 | v23 & v151) + a1[56] - 1894007588;
  HIDWORD(v2) = v55;
  LODWORD(v2) = v55;
  v56 = v2 >> 2;
  HIDWORD(v2) = v120;
  LODWORD(v2) = v120;
  v152 = v151 + (v2 >> 27) + ((v56 | v23) & v88 | v56 & v23) + a1[57] - 1894007588;
  HIDWORD(v2) = v88;
  LODWORD(v2) = v88;
  v89 = v2 >> 2;
  HIDWORD(v2) = v152;
  LODWORD(v2) = v152;
  v24 = v23 + (v2 >> 27) + ((v89 | v56) & v120 | v89 & v56) + a1[58] - 1894007588;
  HIDWORD(v2) = v120;
  LODWORD(v2) = v120;
  v121 = v2 >> 2;
  HIDWORD(v2) = v24;
  LODWORD(v2) = v24;
  v57 = v56 + (v2 >> 27) + ((v121 | v89) & v152 | v121 & v89) + a1[59] - 1894007588;
  HIDWORD(v2) = v152;
  LODWORD(v2) = v152;
  v153 = v2 >> 2;
  HIDWORD(v2) = v57;
  LODWORD(v2) = v57;
  v90 = v89 + (v2 >> 27) + ((v153 | v121) & v24 | v153 & v121) + a1[60] - 1894007588;
  HIDWORD(v2) = v24;
  LODWORD(v2) = v24;
  v25 = v2 >> 2;
  HIDWORD(v2) = v90;
  LODWORD(v2) = v90;
  v122 = v121 + (v2 >> 27) + ((v25 | v153) & v57 | v25 & v153) + a1[61] - 1894007588;
  HIDWORD(v2) = v57;
  LODWORD(v2) = v57;
  v58 = v2 >> 2;
  HIDWORD(v2) = v122;
  LODWORD(v2) = v122;
  v154 = v153 + (v2 >> 27) + ((v58 | v25) & v90 | v58 & v25) + a1[62] - 1894007588;
  HIDWORD(v2) = v90;
  LODWORD(v2) = v90;
  v91 = v2 >> 2;
  HIDWORD(v2) = v154;
  LODWORD(v2) = v154;
  v26 = v25 + (v2 >> 27) + ((v91 | v58) & v122 | v91 & v58) + a1[63] - 1894007588;
  HIDWORD(v2) = v122;
  LODWORD(v2) = v122;
  v123 = v2 >> 2;
  HIDWORD(v2) = v26;
  LODWORD(v2) = v26;
  v59 = v58 + (v2 >> 27) + ((v123 | v91) & v154 | v123 & v91) + a1[64] - 1894007588;
  HIDWORD(v2) = v154;
  LODWORD(v2) = v154;
  v155 = v2 >> 2;
  HIDWORD(v2) = v59;
  LODWORD(v2) = v59;
  v92 = v91 + (v2 >> 27) + ((v155 | v123) & v26 | v155 & v123) + a1[65] - 1894007588;
  HIDWORD(v2) = v26;
  LODWORD(v2) = v26;
  v27 = v2 >> 2;
  HIDWORD(v2) = v92;
  LODWORD(v2) = v92;
  v124 = v123 + (v2 >> 27) + ((v27 | v155) & v59 | v27 & v155) + a1[66] - 1894007588;
  HIDWORD(v2) = v59;
  LODWORD(v2) = v59;
  v60 = v2 >> 2;
  HIDWORD(v2) = v124;
  LODWORD(v2) = v124;
  v156 = v155 + (v2 >> 27) + ((v60 | v27) & v92 | v60 & v27) + a1[67] - 1894007588;
  HIDWORD(v2) = v92;
  LODWORD(v2) = v92;
  v93 = v2 >> 2;
  HIDWORD(v2) = v156;
  LODWORD(v2) = v156;
  v28 = v27 + (v2 >> 27) + (v124 ^ v93 ^ v60) + a1[68] - 899497514;
  HIDWORD(v2) = v124;
  LODWORD(v2) = v124;
  v125 = v2 >> 2;
  HIDWORD(v2) = v28;
  LODWORD(v2) = v28;
  v61 = v60 + (v2 >> 27) + (v156 ^ v125 ^ v93) + a1[69] - 899497514;
  HIDWORD(v2) = v156;
  LODWORD(v2) = v156;
  v157 = v2 >> 2;
  HIDWORD(v2) = v61;
  LODWORD(v2) = v61;
  v94 = v93 + (v2 >> 27) + (v28 ^ v157 ^ v125) + a1[70] - 899497514;
  HIDWORD(v2) = v28;
  LODWORD(v2) = v28;
  v29 = v2 >> 2;
  HIDWORD(v2) = v94;
  LODWORD(v2) = v94;
  v126 = v125 + (v2 >> 27) + (v61 ^ v29 ^ v157) + a1[71] - 899497514;
  HIDWORD(v2) = v61;
  LODWORD(v2) = v61;
  v62 = v2 >> 2;
  HIDWORD(v2) = v126;
  LODWORD(v2) = v126;
  v158 = v157 + (v2 >> 27) + (v94 ^ v62 ^ v29) + a1[72] - 899497514;
  HIDWORD(v2) = v94;
  LODWORD(v2) = v94;
  v95 = v2 >> 2;
  HIDWORD(v2) = v158;
  LODWORD(v2) = v158;
  v30 = v29 + (v2 >> 27) + (v126 ^ v95 ^ v62) + a1[73] - 899497514;
  HIDWORD(v2) = v126;
  LODWORD(v2) = v126;
  v127 = v2 >> 2;
  HIDWORD(v2) = v30;
  LODWORD(v2) = v30;
  v63 = v62 + (v2 >> 27) + (v158 ^ v127 ^ v95) + a1[74] - 899497514;
  HIDWORD(v2) = v158;
  LODWORD(v2) = v158;
  v159 = v2 >> 2;
  HIDWORD(v2) = v63;
  LODWORD(v2) = v63;
  v96 = v95 + (v2 >> 27) + (v30 ^ v159 ^ v127) + a1[75] - 899497514;
  HIDWORD(v2) = v30;
  LODWORD(v2) = v30;
  v31 = v2 >> 2;
  HIDWORD(v2) = v96;
  LODWORD(v2) = v96;
  v128 = v127 + (v2 >> 27) + (v63 ^ v31 ^ v159) + a1[76] - 899497514;
  HIDWORD(v2) = v63;
  LODWORD(v2) = v63;
  v64 = v2 >> 2;
  HIDWORD(v2) = v128;
  LODWORD(v2) = v128;
  v160 = v159 + (v2 >> 27) + (v96 ^ v64 ^ v31) + a1[77] - 899497514;
  HIDWORD(v2) = v96;
  LODWORD(v2) = v96;
  v97 = v2 >> 2;
  HIDWORD(v2) = v160;
  LODWORD(v2) = v160;
  v32 = v31 + (v2 >> 27) + (v128 ^ v97 ^ v64) + a1[78] - 899497514;
  HIDWORD(v2) = v128;
  LODWORD(v2) = v128;
  v129 = v2 >> 2;
  HIDWORD(v2) = v32;
  LODWORD(v2) = v32;
  v65 = v64 + (v2 >> 27) + (v160 ^ v129 ^ v97) + a1[79] - 899497514;
  HIDWORD(v2) = v160;
  LODWORD(v2) = v160;
  v161 = v2 >> 2;
  HIDWORD(v2) = v65;
  LODWORD(v2) = v65;
  v98 = v97 + (v2 >> 27) + (v32 ^ v161 ^ v129) + a1[80] - 899497514;
  HIDWORD(v2) = v32;
  LODWORD(v2) = v32;
  v33 = v2 >> 2;
  HIDWORD(v2) = v98;
  LODWORD(v2) = v98;
  v130 = v129 + (v2 >> 27) + (v65 ^ v33 ^ v161) + a1[81] - 899497514;
  HIDWORD(v2) = v65;
  LODWORD(v2) = v65;
  v66 = v2 >> 2;
  HIDWORD(v2) = v130;
  LODWORD(v2) = v130;
  v162 = v161 + (v2 >> 27) + (v98 ^ v66 ^ v33) + a1[82] - 899497514;
  HIDWORD(v2) = v98;
  LODWORD(v2) = v98;
  v99 = v2 >> 2;
  HIDWORD(v2) = v162;
  LODWORD(v2) = v162;
  v34 = v33 + (v2 >> 27) + (v130 ^ v99 ^ v66) + a1[83] - 899497514;
  HIDWORD(v2) = v130;
  LODWORD(v2) = v130;
  v131 = v2 >> 2;
  HIDWORD(v2) = v34;
  LODWORD(v2) = v34;
  v67 = v66 + (v2 >> 27) + (v162 ^ v131 ^ v99) + a1[84] - 899497514;
  HIDWORD(v2) = v162;
  LODWORD(v2) = v162;
  v163 = v2 >> 2;
  HIDWORD(v2) = v67;
  LODWORD(v2) = v67;
  v100 = v99 + (v2 >> 27) + (v34 ^ v163 ^ v131) + a1[85] - 899497514;
  HIDWORD(v2) = v34;
  LODWORD(v2) = v34;
  v35 = v2 >> 2;
  HIDWORD(v2) = v100;
  LODWORD(v2) = v100;
  v132 = v131 + (v2 >> 27) + (v67 ^ v35 ^ v163) + a1[86] - 899497514;
  HIDWORD(v2) = v67;
  LODWORD(v2) = v67;
  v68 = v2 >> 2;
  HIDWORD(v2) = v132;
  LODWORD(v2) = v132;
  v164 = v163 + (v2 >> 27) + (v100 ^ v68 ^ v35) + a1[87] - 899497514;
  HIDWORD(v2) = v100;
  LODWORD(v2) = v100;
  *a1 += v164;
  a1[1] += v132;
  a1[2] += v2 >> 2;
  a1[3] += v68;
  a1[4] += v35;
  return 0;
}


/* ===== sub_10CF34 @ 0x10CF34 (file 0xCF34) size 200 ===== */
__int64 __fastcall sub_10CF34(_DWORD *a1, _DWORD *a2, int a3)
{
  int v3; // w0
  int v4; // w0

  while ( 1 )
  {
    v4 = a3--;
    if ( v4 == 0 )
      break;
    v3 = a1[7];
    a1[7] = v3 + 1;
    a1[v3 + 8] = *a2++;
    a1[5] += 32;
    if ( a1[5] == 0 )
      ++a1[6];
    if ( a1[7] == 16 )
    {
      sub_10AEA8(a1);
      a1[7] = 0;
    }
  }
  return 0;
}


/* ===== sub_10CFFC @ 0x10CFFC (file 0xCFFC) size 228 ===== */
__int64 __fastcall sub_10CFFC(_DWORD *a1)
{
  int v1; // w0
  unsigned int i; // [xsp+2Ch] [xbp+2Ch]
  unsigned int j; // [xsp+2Ch] [xbp+2Ch]

  v1 = a1[7];
  a1[v1 + 8] = 0x80000000;
  for ( i = v1 + 1; i <= 0xF; ++i )
    a1[i + 8] = 0;
  if ( (unsigned int)(v1 + 1) > 0xE )
  {
    sub_10AEA8(a1);
    for ( j = 0; j <= 0xD; ++j )
      a1[j + 8] = 0;
  }
  a1[22] = a1[6];
  a1[23] = a1[5];
  sub_10AEA8(a1);
  return 0;
}


/* ===== sub_10D0E0 @ 0x10D0E0 (file 0xD0E0) size 208 ===== */
__int64 __fastcall sub_10D0E0(_DWORD *a1, __int64 a2)
{
  _DWORD *v5; // [xsp+20h] [xbp+20h]
  int i; // [xsp+2Ch] [xbp+2Ch]
  int j; // [xsp+2Ch] [xbp+2Ch]

  v5 = a1 + 8;
  sub_10CFFC(a1);
  for ( i = 0; i <= 15; ++i )
    v5[i] = 0;
  a1[5] = 0;
  a1[6] = 0;
  for ( j = 0; j <= 19; ++j )
    *(_BYTE *)(a2 + j) = a1[j >> 2] >> (8 * (~(_BYTE)j & 3));
  return 0;
}


/* ===== sub_10D1C0 @ 0x10D1C0 (file 0xD1C0) size 176 ===== */
__int64 __fastcall sub_10D1C0(char a1)
{
  MEMORY[0x3201102C] |= 1 << a1;
  MEMORY[0x3201103C] |= 1 << a1;
  MEMORY[0x3201104C] |= 1 << a1;
  MEMORY[0x3201105C] |= 1 << a1;
  return 838930524;
}


/* ===== sub_10D270 @ 0x10D270 (file 0xD270) size 80 ===== */
__int64 sub_10D270()
{
  MEMORY[0x32011024] = 1280;
  MEMORY[0x32011028] = 5376;
  sub_10D1C0(1);
  sub_10D1C0(2);
  sub_10D1C0(9);
  return sub_10D1C0(5);
}


/* ===== sub_10D2C0 @ 0x10D2C0 (file 0xD2C0) size 80 ===== */
__int64 sub_10D2C0()
{
  MEMORY[0x32018000] |= 0xC0u;
  MEMORY[0x32018004] |= 0xC0u;
  return sub_10D1C0(7);
}


/* ===== sub_10D310 @ 0x10D310 (file 0xD310) size 80 ===== */
__int64 sub_10D310()
{
  MEMORY[0x32018000] |= 0x300u;
  MEMORY[0x32018004] |= 0x300u;
  return sub_10D1C0(6);
}


/* ===== sub_10D360 @ 0x10D360 (file 0xD360) size 80 ===== */
__int64 sub_10D360()
{
  MEMORY[0x32018000] |= 0x3000u;
  MEMORY[0x32018004] |= 0x3000u;
  return sub_10D1C0(3);
}


/* ===== sub_10D3B0 @ 0x10D3B0 (file 0xD3B0) size 80 ===== */
__int64 sub_10D3B0()
{
  MEMORY[0x32018000] |= 0xC000u;
  MEMORY[0x32018004] |= 0xC000u;
  return sub_10D1C0(8);
}


/* ===== sub_10D400 @ 0x10D400 (file 0xD400) size 200 ===== */
__int64 __fastcall sub_10D400(_BYTE *a1, int a2)
{
  int v2; // w0
  unsigned __int16 v6; // [xsp+1Ah] [xbp-6h]
  unsigned int i; // [xsp+1Ch] [xbp-4h]

  v6 = 0;
  while ( 1 )
  {
    v2 = a2--;
    if ( v2 == 0 )
      break;
    for ( i = 128; i != 0; i >>= 1 )
    {
      if ( (v6 & 0x8000u) == 0 )
        v6 *= 2;
      else
        v6 = (2 * v6) ^ 0x1021;
      if ( (*a1 & (unsigned __int8)i) != 0 )
        v6 ^= 0x1021u;
    }
    ++a1;
  }
  return v6;
}


/* ===== sub_10D4C8 @ 0x10D4C8 (file 0xD4C8) size 52 ===== */
__int64 __fastcall sub_10D4C8(__int64 a1, __int64 a2, unsigned int a3)
{
  return sub_10FAA4(a1, a2, a3);
}


/* ===== sub_10D4FC @ 0x10D4FC (file 0xD4FC) size 52 ===== */
__int64 __fastcall sub_10D4FC(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  return sub_10FA50(a1, a2, a3);
}


/* ===== sub_10D530 @ 0x10D530 (file 0xD530) size 236 ===== */
__int64 __fastcall sub_10D530(unsigned __int16 *a1, int a2)
{
  _DWORD *v2; // x0
  unsigned __int8 *v6; // [xsp+10h] [xbp-10h]
  unsigned int v7; // [xsp+1Ch] [xbp-4h]

  v7 = 0;
  while ( a2 > 3 )
  {
    v2 = a1;
    a1 += 2;
    v7 += *v2;
    a2 -= 4;
  }
  v6 = (unsigned __int8 *)a1;
  if ( (a2 & 2) != 0 )
  {
    v7 += *a1;
    v6 = (unsigned __int8 *)(a1 + 1);
  }
  if ( (a2 & 1) != 0 )
    v7 += *v6;
  return (unsigned __int16)~(HIWORD(v7) + v7 + ((unsigned int)(HIWORD(v7) + (unsigned __int16)v7) >> 16));
}


/* ===== sub_10D61C @ 0x10D61C (file 0xD61C) size 216 ===== */
__int64 sub_10D61C()
{
  unsigned int i; // [xsp+Ch] [xbp-4h]

  MEMORY[0x402E0000] |= 0x100000u;
  MEMORY[0x402E00B0] |= 0x1000u;
  for ( i = 1076495780; i <= 0x402A05A8; i += 4 )
  {
    *(_DWORD *)i &= ~0x40u;
    *(_DWORD *)i |= 0x1080u;
  }
  MEMORY[0x402A0598] &= ~0x40u;
  MEMORY[0x402A059C] &= ~0x40u;
  return 1076495772;
}


/* ===== sub_10D6F4 @ 0x10D6F4 (file 0xD6F4) size 52 ===== */
__int64 sub_10D6F4()
{
  MEMORY[0x402E0000] |= 0x400u;
  MEMORY[0x402E0010] |= 8u;
  return 1076756496;
}


/* ===== sub_10D728 @ 0x10D728 (file 0xD728) size 132 ===== */
__int64 sub_10D728()
{
  int v0; // w0
  int v2; // [xsp+1Ch] [xbp+1Ch]

  MEMORY[0x71300000] |= 0x4000u;
  MEMORY[0x71300004] |= 0x4000u;
  v2 = 50;
  do
    v0 = v2--;
  while ( v0 != 0 );
  MEMORY[0x71300004] &= ~0x4000u;
  return sub_109620(0x70100000u);
}


/* ===== sub_10D7AC @ 0x10D7AC (file 0xD7AC) size 284 ===== */
__int64 sub_10D7AC()
{
  unsigned int i; // [xsp+Ch] [xbp-4h]

  MEMORY[0x402E0000] |= 0x100u;
  MEMORY[0x402E0010] |= 2u;
  MEMORY[0x402E0008] |= 0x100u;
  for ( i = 0; i <= 9; ++i )
    ;
  MEMORY[0x402E0008] &= ~0x100u;
  MEMORY[0x40250010] = 4095;
  MEMORY[0x40250018] = 0xFFFF;
  MEMORY[0x40250028] = 0;
  MEMORY[0x4025001C] = 15;
  MEMORY[0x40250000] |= 0x30300u;
  MEMORY[0x40250000] |= 0x30301u;
  return 1076166656;
}


/* ===== sub_10D8C8 @ 0x10D8C8 (file 0xD8C8) size 72 ===== */
__int64 sub_10D8C8()
{
  MEMORY[0x40250010] = 4095;
  MEMORY[0x402E0000] &= ~0x100u;
  MEMORY[0x402E0010] &= ~2u;
  return 1076756496;
}


/* ===== sub_10D910 @ 0x10D910 (file 0xD910) size 76 ===== */
__int64 sub_10D910()
{
  sub_10D9D0(20);
  MEMORY[0x2450] = MEMORY[0x40250008];
  MEMORY[0x2454] = MEMORY[0x4025002C];
  return sub_10D8C8();
}


/* ===== sub_10D95C @ 0x10D95C (file 0xD95C) size 84 ===== */
__int64 sub_10D95C()
{
  __int64 v0; // x0

  MEMORY[0x402E058C] &= ~2u;
  sub_10D270();
  v0 = sub_109760();
  sub_10DDD4(v0);
  sub_10D61C();
  sub_10D6F4();
  sub_10D728();
  sub_10D7AC();
  sub_10AB34();
  return sub_10DF40(32);
}


/* ===== sub_10D9B0 @ 0x10D9B0 (file 0xD9B0) size 32 ===== */
__int64 sub_10D9B0()
{
  return MEMORY[0x4023000C];
}


/* ===== sub_10D9D0 @ 0x10D9D0 (file 0xD9D0) size 64 ===== */
__int64 __fastcall sub_10D9D0(int a1)
{
  unsigned int v1; // w1
  __int64 result; // x0
  unsigned int v3; // [xsp+2Ch] [xbp+2Ch]

  v3 = sub_10D9B0() + a1;
  do
  {
    v1 = sub_10D9B0();
    result = v3;
  }
  while ( v1 < v3 );
  return result;
}


/* ===== sub_10DA10 @ 0x10DA10 (file 0xDA10) size 296 ===== */
__int64 __fastcall sub_10DA10(_DWORD *a1)
{
  int v2; // [xsp+18h] [xbp-28h]
  unsigned int i; // [xsp+38h] [xbp-8h]
  unsigned int v4; // [xsp+3Ch] [xbp-4h]

  v2 = 0;
  v4 = 0;
  if ( (MEMORY[0x402E002C] & 0x10) != 0 )
  {
    if ( (MEMORY[0x2450] & 0xF) != 0 )
    {
      for ( i = 0; i <= 3; ++i )
      {
        if ( ((1 << i) & MEMORY[0x2450] & 0xF) != 0 && ((MEMORY[0x2454] >> (8 * i)) & 0x77) == 0 )
          v2 = 1;
      }
      if ( v2 == 1 )
      {
        *a1 = 1;
        return 1;
      }
    }
  }
  else
  {
    return 1;
  }
  return v4;
}


/* ===== sub_10DB38 @ 0x10DB38 (file 0xDB38) size 68 ===== */
bool sub_10DB38()
{
  return (MEMORY[0x402E0568] & 1) != 0;
}


/* ===== sub_10DB7C @ 0x10DB7C (file 0xDB7C) size 68 ===== */
bool sub_10DB7C()
{
  return (MEMORY[0x402E0568] & 0x800) == 0;
}


/* ===== sub_10DBC0 @ 0x10DBC0 (file 0xDBC0) size 164 ===== */
__int64 __fastcall sub_10DBC0(unsigned int a1)
{
  if ( (MEMORY[0x402E0568] & 0x20000) == 0
    || (unsigned int)sub_10111C(0, 0x400u, 8u, 143360) != 1
    || *(_QWORD *)(MEMORY[0x12D0] + 8LL) != 0x48435441504D4F52LL )
  {
    return 0;
  }
  (*(void (__fastcall **)(_QWORD))(MEMORY[0x12D0] + 16LL))(a1);
  return 1;
}


/* ===== sub_10DC64 @ 0x10DC64 (file 0xDC64) size 60 ===== */
bool sub_10DC64()
{
  return (*(_DWORD *)(MEMORY[0x12F8] + 24LL) & 0x10000) != 0;
}


/* ===== sub_10DCA0 @ 0x10DCA0 (file 0xDCA0) size 308 ===== */
__int64 sub_10DCA0()
{
  unsigned int v1; // [xsp+1Ch] [xbp+1Ch]

  sub_109974(MEMORY[0x12B0]);
  if ( (*(_DWORD *)(MEMORY[0x12B0] + 4LL) & 0xFFFF0000) != 0xFFFF0000 )
  {
    sub_10DF40(0x80000000000LL);
    return 0;
  }
  if ( (*(_DWORD *)(MEMORY[0x12F8] + 24LL) & 2) != 0 )
  {
    if ( (*MEMORY[0x12B0] & 0xFF0) == 0xFF0 || (unsigned __int8)*(_DWORD *)(MEMORY[0x12B0] + 8LL) == 255 )
    {
      sub_10FAA4(MEMORY[0x1390], MEMORY[0x12F8] + 8LL, 16);
      sub_10FAA4(MEMORY[0x1390] + 16LL, MEMORY[0x12F8] + 128LL, 16);
      v1 = 1;
      sub_10DF40(0x800000000000LL);
    }
    else
    {
      v1 = 0;
      sub_10DF40(0x200000000000LL);
    }
  }
  else
  {
    if ( (*MEMORY[0x12B0] & 0xFFFF0000) != 0xFFFF0000 )
    {
      sub_10DF40(0x100000000000LL);
      return 0;
    }
    v1 = 1;
    sub_10DF40(0x400000000000LL);
  }
  return v1;
}


/* ===== sub_10DDD4 @ 0x10DDD4 (file 0xDDD4) size 292 ===== */
__int64 sub_10DDD4()
{
  __int64 result; // x0
  unsigned int v1; // [xsp+10h] [xbp+10h] BYREF
  char v2; // [xsp+15h] [xbp+15h]
  char v3; // [xsp+16h] [xbp+16h]
  char v4; // [xsp+17h] [xbp+17h]
  unsigned int v5; // [xsp+18h] [xbp+18h]
  int v6; // [xsp+1Ch] [xbp+1Ch]

  v1 = 0;
  v6 = 0;
  v5 = 0;
  v4 = 0;
  v3 = 0;
  v2 = 0;
  sub_1097F4(0x2Du, &v1, 1);
  result = v1 & 0x40000000;
  if ( (_DWORD)result != 0 )
  {
    v5 = MEMORY[0x20E03030] & 0xFFFFC007 | (8 * (BYTE2(v1) & 0x1F));
    v5 |= ((v1 >> 21) & 0x3F) << 8;
    MEMORY[0x20E0302C] = MEMORY[0x20E0302C] & 0xFF1FFFFF | (((v1 >> 27) & 7) << 21);
    MEMORY[0x20E03030] = v5;
    return 551563312;
  }
  return result;
}


/* ===== sub_10DEF8 @ 0x10DEF8 (file 0xDEF8) size 16 ===== */
void sub_10DEF8()
{
  ;
}


/* ===== sub_10DF08 @ 0x10DF08 (file 0xDF08) size 56 ===== */
bool sub_10DF08()
{
  return (MEMORY[0x402E002C] & 8) != 0;
}


/* ===== sub_10DF40 @ 0x10DF40 (file 0xDF40) size 48 ===== */
unsigned __int64 __fastcall sub_10DF40(__int64 a1)
{
  __int64 v1; // x1

  v1 = MEMORY[0x3000] | a1;
  MEMORY[0x3000] = v1;
  return 0x3000u;
}


/* ===== sub_10DF70 @ 0x10DF70 (file 0xDF70) size 52 ===== */
unsigned __int64 __fastcall sub_10DF70(__int64 a1)
{
  __int64 v1; // x1

  v1 = ~a1 & MEMORY[0x3000];
  MEMORY[0x3000] = v1;
  return 0x3000u;
}


/* ===== sub_10DFA4 @ 0x10DFA4 (file 0xDFA4) size 264 ===== */
__int64 sub_10DFA4()
{
  int v0; // w0
  __int64 v2; // [xsp+8h] [xbp-28h]
  unsigned int v3; // [xsp+28h] [xbp-8h]
  unsigned int i; // [xsp+2Ch] [xbp-4h]

  v3 = 0;
  v2 = 0;
  if ( (MEMORY[0x2450] & 0xF) != 0 )
  {
    for ( i = 0; i <= 3; ++i )
    {
      if ( ((1 << i) & MEMORY[0x2450] & 0xF) != 0 )
      {
        v0 = (MEMORY[0x2454] >> (8 * i)) & 0x77;
        if ( v0 != 0 )
        {
          if ( v0 == 1 )
            HIDWORD(v2) = 1;
        }
        else
        {
          LODWORD(v2) = 1;
        }
      }
    }
    if ( v2 == 0x100000001LL )
      return 1;
  }
  return v3;
}


/* ===== sub_10E0AC @ 0x10E0AC (file 0xE0AC) size 188 ===== */
__int64 sub_10E0AC()
{
  __int64 result; // x0

  switch ( MEMORY[0x402E002C] & 7 )
  {
    case 1:
      *MEMORY[0x1300] = 4;
      result = 3;
      break;
    case 2:
      *MEMORY[0x1300] = 1;
      result = 3;
      break;
    case 3:
      result = 1;
      break;
    case 4:
      *MEMORY[0x1300] = 3;
      result = 3;
      break;
    case 5:
      *MEMORY[0x1300] = 2;
      result = 3;
      break;
    case 7:
      result = 0;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


/* ===== sub_10E168 @ 0x10E168 (file 0xE168) size 36 ===== */
unsigned __int64 __fastcall sub_10E168(int a1)
{
  int v1; // w1

  v1 = a1 << 8;
  MEMORY[0x3008] = v1;
  return 0x3008u;
}


/* ===== sub_10E18C @ 0x10E18C (file 0xE18C) size 200 ===== */
__int64 sub_10E18C()
{
  MEMORY[0x20E00000] |= 0x80u;
  MEMORY[0x21500020] = MEMORY[0x21500020] & 0xFFFFFFFC | 2;
  MEMORY[0x402D02D0] = MEMORY[0x402D02D0] & 0xFFFFFFFC | 2;
  MEMORY[0x20E00054] = MEMORY[0x20E00054] & 0xFFFFFFFC | 1;
  return 551551060;
}


/* ===== sub_10E254 @ 0x10E254 (file 0xE254) size 164 ===== */
__int64 __fastcall sub_10E254(int a1)
{
  __int64 result; // x0
  unsigned int i; // [xsp+2Ch] [xbp+2Ch]

  for ( i = 0; i <= 0x1A && *(unsigned __int8 *)(0x10E0 + 16LL * i) != a1; ++i )
    ;
  result = i;
  if ( i <= 0x1A )
  {
    sub_1096F4(0x70100000u, *(unsigned __int8 **)(0x10E0 + 16LL * i + 8), 3u);
    return sub_1096F4(0x70100000u, (unsigned __int8 *)&qword_10E3E8, 2u);
  }
  return result;
}


/* ===== sub_10E3F0 @ 0x10E3F0 (file 0xE3F0) size 316 ===== */
__int64 __fastcall sub_10E3F0(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // [xsp+2Ch] [xbp+2Ch]

  v3 = 1;
  sub_10DF40(0x100000000LL);
  sub_10FA50(MEMORY[0x12F8], 0, 144);
  if ( (unsigned int)sub_10991C(MEMORY[0x12F8]) != 0 )
  {
    v3 = 0;
    sub_10DF40(64);
  }
  else if ( (*(_DWORD *)(MEMORY[0x12F8] + 24LL) & 1) != 0 || !sub_10DB38() )
  {
    sub_10F29C(-1);
    if ( sub_10DB38() && (unsigned int)sub_10DCA0() == 1 )
      v3 = sub_10EC3C(a1);
  }
  else if ( (unsigned int)sub_10DCA0() == 1 )
  {
    v3 = sub_10EC3C(a1);
    if ( v3 == 1 && sub_10DC64() && (unsigned int)sub_10F138(a1) == 0 )
    {
      sub_10E254(24);
      sub_10F29C(0);
    }
  }
  else
  {
    sub_10F29C(-1);
  }
  result = v3;
  if ( v3 == 1 )
  {
    sub_10DF40(0x8000000000000000LL);
    sub_10E254(26);
    return sub_10016C((__int64 (*)(void))(unsigned int)(a1 + 512));
  }
  return result;
}


/* ===== sub_10E52C @ 0x10E52C (file 0xE52C) size 64 ===== */
__int64 sub_10E52C()
{
  unsigned int v0; // w0
  __int64 result; // x0

  if ( (unsigned int)sub_10DA10(MEMORY[0x1338]) == 1 )
  {
    v0 = sub_10DF08();
    return sub_108840(v0);
  }
  else
  {
    result = sub_108A7C();
    if ( (_DWORD)result == 1 )
      sub_108B5C();
  }
  return result;
}


/* ===== sub_10E56C @ 0x10E56C (file 0xE56C) size 80 ===== */
__int64 sub_10E56C()
{
  unsigned int v1; // w0

  if ( (unsigned int)sub_1053D0() == 1 )
  {
    sub_10DF70(0xFFFF00000000LL);
    return sub_10E3F0(20480);
  }
  else
  {
    *MEMORY[0x1338] = 0;
    v1 = sub_10DF08();
    return sub_108840(v1);
  }
}


/* ===== sub_10E5BC @ 0x10E5BC (file 0xE5BC) size 100 ===== */
__int64 sub_10E5BC()
{
  __int64 result; // x0
  unsigned int v1; // [xsp+1Ch] [xbp+1Ch]

  sub_10DF70(66060544);
  v1 = sub_1053D0();
  MEMORY[0x402E0088] |= 0x200u;
  result = v1;
  if ( v1 == 1 )
  {
    sub_10DF70(0xFFFF00000000LL);
    sub_10E3F0(20480);
    while ( 1 )
      ;
  }
  return result;
}


/* ===== sub_10E620 @ 0x10E620 (file 0xE620) size 160 ===== */
__int64 sub_10E620()
{
  __int64 result; // x0
  unsigned int v1; // [xsp+18h] [xbp+18h]
  unsigned int i; // [xsp+1Ch] [xbp+1Ch]

  v1 = 0;
  for ( i = 0; i <= 1; ++i )
  {
    sub_10DF70(259840);
    v1 = sub_101210(i);
    MEMORY[0x402E0088] |= 0x200u;
    sub_10E254(11);
    if ( v1 == 1 )
    {
      sub_10DF70(0xFFFF00000000LL);
      sub_10E3F0(20480);
    }
  }
  result = v1;
  if ( v1 != 1 )
    return sub_10E56C();
  return result;
}


/* ===== nullsub_4 @ 0x10E6C0 (file 0xE6C0) size 4 ===== */
void nullsub_4()
{
  ;
}


/* ===== sub_10E6C4 @ 0x10E6C4 (file 0xE6C4) size 108 ===== */
__int64 sub_10E6C4()
{
  __int64 result; // x0
  BOOL v1; // [xsp+1Ch] [xbp+1Ch]

  v1 = sub_103920();
  MEMORY[0x402E0088] |= 0x200u;
  sub_10E254(11);
  if ( v1 )
  {
    sub_10DF70(0xFFFF00000000LL);
    sub_10E3F0(20480);
  }
  result = v1;
  if ( !v1 )
    return sub_10E56C();
  return result;
}


/* ===== brom_main @ 0x10E730 (file 0xE730) size 104 ===== */
void __noreturn brom_main()
{
  unsigned int v0; // [xsp+1Ch] [xbp+1Ch]

  MEMORY[0x402E0004] |= 0x10u;
  sub_10D95C();
  sub_10D910();
  if ( (unsigned int)sub_10DFA4() == 1 )
    sub_10E5BC();
  else
    sub_10E52C();
  v0 = sub_10E0AC();
  (*(void (**)(void))(MEMORY[0x13C8] + 8LL * v0))();
  while ( 1 )
    ;
}


/* ===== sub_10E798 @ 0x10E798 (file 0xE798) size 88 ===== */
__int64 __fastcall sub_10E798(int a1, int a2, __int64 a3)
{
  sub_10FA50(MEMORY[0x12E8], 0, 32);
  sub_10ACB8(a1, a2, MEMORY[0x12E8]);
  return sub_10D4C8(a3, MEMORY[0x12E8], 0x20u);
}


/* ===== sub_10E7F0 @ 0x10E7F0 (file 0xE7F0) size 116 ===== */
__int64 __fastcall sub_10E7F0(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  unsigned int v11; // [xsp+4Ch] [xbp+4Ch]

  sub_10FA50(MEMORY[0x13B0], 0, 256);
  v11 = sub_10AC18(a1, a2, a3, a4, MEMORY[0x13B0]);
  sub_10D4C8(a5, MEMORY[0x13B0], 0x100u);
  return v11;
}


/* ===== sub_10E864 @ 0x10E864 (file 0xE864) size 108 ===== */
__int64 __fastcall sub_10E864(int a1, int a2, char a3, __int64 a4)
{
  unsigned int v9; // [xsp+3Ch] [xbp+3Ch]

  sub_10FA50(MEMORY[0x1398], 0, 16);
  v9 = sub_10ADD4(a1, a2, a3, MEMORY[0x1398]);
  sub_10D4C8(a4, MEMORY[0x1398], 0x20u);
  return v9;
}


/* ===== sub_10E8D0 @ 0x10E8D0 (file 0xE8D0) size 876 ===== */
__int64 __fastcall sub_10E8D0(__int64 a1, __int64 a2, _DWORD *a3)
{
  _DWORD v7[8]; // [xsp+30h] [xbp+30h] BYREF
  _BYTE v8[260]; // [xsp+50h] [xbp+50h] BYREF
  int v9; // [xsp+154h] [xbp+154h]
  _DWORD *v10; // [xsp+158h] [xbp+158h]
  int v11; // [xsp+164h] [xbp+164h]
  _DWORD *v12; // [xsp+168h] [xbp+168h]
  _BYTE *v13; // [xsp+170h] [xbp+170h]
  char v14; // [xsp+17Eh] [xbp+17Eh]
  unsigned __int8 i; // [xsp+17Fh] [xbp+17Fh]

  v14 = *(_BYTE *)a3;
  v13 = v8;
  sub_10FA50(v8, 0, 256);
  sub_10FA50(v7, 0, 32);
  if ( v14 != 0 && v14 != 1 )
  {
    sub_10DF40(0x1000000000LL);
    return 0;
  }
  else
  {
    if ( v14 == 1 )
    {
      v12 = a3;
      if ( a3[83] != 1 || v12[84] < *(_DWORD *)(MEMORY[0x12F8] + 28LL) )
      {
LABEL_6:
        sub_10DF40(0x8000000000LL);
        return 0;
      }
      sub_10E798((_DWORD)v12 + 4, (v12[1] >> 3) + 8, (__int64)v7);
      for ( i = 0; i <= 7u; ++i )
      {
        v7[i] &= ~0x80000000;
        *(_DWORD *)(a1 + 4 * i) &= ~0x80000000;
      }
      if ( (unsigned int)sub_10FB08(a2, v12 + 67, 32) != 0 || (unsigned int)sub_10FB08(a1, v7, 32) != 0 )
        goto LABEL_21;
      v11 = sub_10E7F0((__int64)(v12 + 2), (__int64)(v12 + 3), v12[1], (__int64)(v12 + 85), (__int64)v13);
      if ( (32 << *v12) + 8 != v11 || (unsigned int)sub_10FB08(v12 + 67, v13, v11) != 0 )
      {
        sub_10DF40(0x2000000000LL);
        return 0;
      }
    }
    else
    {
      v10 = a3;
      if ( a3[75] != 1 || v10[76] < *(_DWORD *)(MEMORY[0x12F8] + 28LL) )
        goto LABEL_6;
      sub_10E798((_DWORD)v10 + 4, (v10[1] >> 3) + 8, (__int64)v7);
      if ( (unsigned int)sub_10FB08(a2, v10 + 67, 32) != 0 )
      {
LABEL_21:
        sub_10DF40(0x400000000LL);
        return 0;
      }
      v9 = sub_10E7F0((__int64)(v10 + 2), (__int64)(v10 + 3), v10[1], (__int64)(v10 + 77), (__int64)v13);
      if ( (32 << *v10) + 8 != v9 || (unsigned int)sub_10FB08(v10 + 67, v13, v9) != 0 )
      {
        sub_10DF40(0x4000000000LL);
        return 0;
      }
    }
    return 1;
  }
}


/* ===== sub_10EC3C @ 0x10EC3C (file 0xEC3C) size 500 ===== */
__int64 __fastcall sub_10EC3C(_DWORD *a1)
{
  _BYTE v3[32]; // [xsp+28h] [xbp+28h] BYREF
  __int64 v4; // [xsp+48h] [xbp+48h]
  _DWORD *v5; // [xsp+50h] [xbp+50h]
  _DWORD *v6; // [xsp+58h] [xbp+58h]
  unsigned int v7; // [xsp+64h] [xbp+64h]
  __int64 v8; // [xsp+68h] [xbp+68h]

  v7 = 0;
  v6 = a1;
  MEMORY[0x2518] = (char *)a1 + (unsigned int)a1[12] + 512;
  sub_10FA50(v3, 0, 32);
  sub_10DF40(0x40000000000LL);
  if ( (*(_DWORD *)(MEMORY[0x12F8] + 24LL) & 2) != 0 )
    v8 = MEMORY[0x1390];
  else
    v8 = MEMORY[0x12F8] + 32LL;
  if ( *(_QWORD *)(MEMORY[0x2518] + 32LL) != 0 )
  {
    sub_10E798((_DWORD)a1 + 512, v6[12], (__int64)v3);
    v5 = (_DWORD *)((char *)a1 + *(_QWORD *)(MEMORY[0x2518] + 40LL));
    v7 = sub_10E8D0(v8, (__int64)v3, v5);
    if ( v7 != 0
      && sub_10DB7C()
      && (unsigned __int16)*(_DWORD *)(MEMORY[0x12B0] + 4LL) == 0xFFFF
      && (*(_DWORD *)(MEMORY[0x12F8] + 24LL) & 1) == 0 )
    {
      sub_10D4C8(MEMORY[0x1308], (__int64)(v6 + 13), 0x20u);
      v4 = MEMORY[0x1308] + 8LL;
      *(_DWORD *)(MEMORY[0x1308] + 8LL) ^= *v6;
      v4 = MEMORY[0x1308] + 12LL;
      *(_DWORD *)(MEMORY[0x1308] + 12LL) ^= v6[12];
      sub_10ACE4((_DWORD)a1 + 512, (_DWORD)a1 + 512, v6[12], MEMORY[0x1308], 8);
      sub_10DF40(0x4000000000000000LL);
    }
  }
  else
  {
    sub_10DF40(0x800000000LL);
  }
  return v7;
}


/* ===== sub_10EE30 @ 0x10EE30 (file 0xEE30) size 468 ===== */
__int64 __fastcall sub_10EE30(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  _BYTE v9[256]; // [xsp+38h] [xbp+38h] BYREF
  _BYTE v10[36]; // [xsp+138h] [xbp+138h] BYREF
  int v11; // [xsp+15Ch] [xbp+15Ch]

  sub_10FA50(v10, 0, 32);
  sub_10FA50(v9, 0, 256);
  if ( a4 != 0 )
  {
    if ( a4 == 1 )
    {
      sub_10E798(a1 + 4, 264, (__int64)v10);
      if ( (unsigned int)sub_10FB08(a2 + 268, v10, 32) != 0 )
        return 0;
      v11 = sub_10E7F0(a1 + 8, a1 + 12, *(_DWORD *)(a1 + 4), a1 + 308, (__int64)v9);
      if ( v11 > 0 && (unsigned int)sub_10FB08(a1 + 268, v9, 40) != 0 )
        return 0;
    }
  }
  else
  {
    sub_10E798(a2 + 4, 264, (__int64)v10);
    if ( (unsigned int)sub_10FB08(a3 + 300, v10, 32) != 0 )
      return 0;
    v11 = sub_10E7F0(a2 + 8, a2 + 12, *(_DWORD *)(a2 + 4), a2 + 312, (__int64)v9);
    if ( v11 > 0 && (unsigned int)sub_10FB08(a2 + 268, v9, 44) != 0 )
      return 0;
  }
  return 1;
}


/* ===== sub_10F004 @ 0x10F004 (file 0xF004) size 308 ===== */
__int64 __fastcall sub_10F004(__int64 a1)
{
  unsigned int v3; // [xsp+20h] [xbp+20h]

  sub_10FA50(MEMORY[0x1358], 0, 48);
  sub_10FA50(MEMORY[0x1350], 0, 36);
  if ( (*(_DWORD *)(MEMORY[0x12F8] + 24LL) & 2) != 0 )
    sub_10FAA4(MEMORY[0x1358], MEMORY[0x1390], 32);
  else
    sub_10FAA4(MEMORY[0x1358], MEMORY[0x12F8] + 32LL, 32);
  *MEMORY[0x1350] = 1;
  *(_BYTE *)(MEMORY[0x1350] + 1LL) = 73;
  *(_BYTE *)(MEMORY[0x1350] + 2LL) = 0;
  *(_BYTE *)(MEMORY[0x1350] + 35LL) = 0x80;
  v3 = sub_10E864(MEMORY[0x1350], 36, 24, MEMORY[0x1358] + 32LL);
  sub_10E798(MEMORY[0x1358], 48, a1);
  return v3;
}


/* ===== sub_10F138 @ 0x10F138 (file 0xF138) size 356 ===== */
__int64 __fastcall sub_10F138(__int64 a1)
{
  _BYTE v2[32]; // [xsp+20h] [xbp+20h] BYREF
  int v3; // [xsp+44h] [xbp+44h]
  __int64 v4; // [xsp+48h] [xbp+48h]
  __int64 v5; // [xsp+50h] [xbp+50h]
  __int64 v6; // [xsp+58h] [xbp+58h]
  _QWORD *v7; // [xsp+60h] [xbp+60h]
  __int64 v8; // [xsp+68h] [xbp+68h]

  memset(v2, 0, sizeof(v2));
  v8 = a1;
  v7 = (_QWORD *)(a1 + *(unsigned int *)(a1 + 48) + 512LL);
  v6 = a1 + v7[11];
  v5 = a1 + v7[9];
  v4 = a1 + v7[5];
  sub_10DF40(0x10000000000LL);
  if ( v7[8] == 0 )
    return 0;
  if ( (unsigned int)sub_10EE30(v6, v5, v4, 0) != 1 )
    return 0;
  v3 = sub_10EE30(v6, v5, v4, 1);
  if ( v3 != 1 )
    return 0;
  if ( (unsigned int)sub_10F004((__int64)v2) != 1 )
    return 0;
  if ( (unsigned int)sub_10FB08(v6 + 276, v2, 32) != 0 )
    return 0;
  sub_10F29C((unsigned int)*(_QWORD *)(v6 + 268) & (unsigned int)*(_QWORD *)(v5 + 300));
  return 1;
}


/* ===== sub_10F29C @ 0x10F29C (file 0xF29C) size 200 ===== */
__int64 __fastcall sub_10F29C(unsigned __int64 a1)
{
  if ( a1 == -1 )
  {
    MEMORY[0x402E0204] = 0xFFFF;
    MEMORY[0x402E0208] = -536866817;
    MEMORY[0x402E0210] = 3;
  }
  else
  {
    MEMORY[0x402E0204] = (unsigned __int16)a1;
    MEMORY[0x402E0208] = (a1 >> 16) & 0xFFF | ((unsigned int)(a1 >> 28) << 29);
    MEMORY[0x402E0210] = (a1 >> 31) & 3;
  }
  return 1076757008;
}


/* ===== sub_10F364 @ 0x10F364 (file 0xF364) size 152 ===== */
__int64 __fastcall sub_10F364(__int64 a1, int a2)
{
  __int64 result; // x0
  char v4; // [xsp+17h] [xbp-9h]
  unsigned int i; // [xsp+18h] [xbp-8h]
  int v6; // [xsp+1Ch] [xbp-4h]

  v6 = 0;
  for ( i = a2 - 1; ; --i )
  {
    result = i;
    if ( v6 >= (int)i )
      break;
    v4 = *(_BYTE *)(a1 + v6);
    *(_BYTE *)(a1 + v6) = *(_BYTE *)(a1 + (int)i);
    *(_BYTE *)(a1 + (int)i) = v4;
    ++v6;
  }
  return result;
}


/* ===== sub_10F3FC @ 0x10F3FC (file 0xF3FC) size 80 ===== */
__int64 __fastcall sub_10F3FC(__int64 a1, int a2)
{
  int i; // [xsp+1Ch] [xbp-4h]

  for ( i = 0; i < a2; ++i )
    *(_BYTE *)(a1 + i) = -86;
  return 1;
}


/* ===== sub_10F44C @ 0x10F44C (file 0xF44C) size 196 ===== */
__int64 __fastcall sub_10F44C(_BYTE *a1, int a2, __int64 a3, unsigned int a4)
{
  _BYTE *v5; // x0
  unsigned int v9; // [xsp+34h] [xbp+34h]

  if ( a2 - 11 < (int)a4 )
    return 0;
  *a1 = 0;
  a1[1] = 1;
  v9 = a2 - 3 - a4;
  sub_10FA50(a1 + 2, 255, (int)v9);
  v5 = &a1[v9 + 2];
  *v5 = 0;
  sub_10FAA4(v5 + 1, a3, a4);
  return 1;
}


/* ===== sub_10F510 @ 0x10F510 (file 0xF510) size 332 ===== */
__int64 __fastcall sub_10F510(__int64 a1, int a2, _BYTE *a3, int a4, int a5)
{
  int v6; // [xsp+3Ch] [xbp+3Ch]
  unsigned int v7; // [xsp+3Ch] [xbp+3Ch]
  _BYTE *v8; // [xsp+40h] [xbp+40h]
  int i; // [xsp+4Ch] [xbp+4Ch]

  if ( a4 + 1 != a5 )
    return 0xFFFFFFFFLL;
  v8 = a3 + 1;
  if ( *a3 != 1 )
    return 0xFFFFFFFFLL;
  v6 = a4 - 1;
  for ( i = 0; i < v6; ++i )
  {
    if ( (unsigned __int8)*v8 != 255 )
    {
      if ( *v8 != 0 )
        return 0xFFFFFFFFLL;
      ++v8;
      break;
    }
    ++v8;
  }
  if ( i == v6 )
    return 0xFFFFFFFFLL;
  if ( i <= 7 )
    return 0xFFFFFFFFLL;
  v7 = v6 - (i + 1);
  if ( (int)v7 > a2 )
    return 0xFFFFFFFFLL;
  sub_10FAA4(a1, v8, v7);
  return v7;
}


/* ===== sub_10F65C @ 0x10F65C (file 0xF65C) size 300 ===== */
__int64 __fastcall sub_10F65C(_BYTE *a1, int a2, __int64 a3, unsigned int a4)
{
  _BYTE *v8; // [xsp+40h] [xbp+40h]
  int i; // [xsp+4Ch] [xbp+4Ch]

  if ( a2 - 11 < (int)a4 )
    return 0;
  *a1 = 0;
  v8 = a1 + 2;
  a1[1] = 2;
  if ( (int)sub_10F3FC((__int64)(a1 + 2), a2 - 3 - a4) <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    if ( i >= (int)(a2 - 3 - a4) )
    {
      *v8 = 0;
      sub_10FAA4(v8 + 1, a3, a4);
      return 1;
    }
    if ( *v8 == 0 )
      break;
LABEL_10:
    ++v8;
  }
  while ( (int)sub_10F3FC((__int64)v8, 1) > 0 )
  {
    if ( *v8 != 0 )
      goto LABEL_10;
  }
  return 0;
}


/* ===== sub_10F788 @ 0x10F788 (file 0xF788) size 292 ===== */
__int64 __fastcall sub_10F788(__int64 a1, int a2, _BYTE *a3, int a4, int a5)
{
  _BYTE *v6; // x0
  int v8; // [xsp+3Ch] [xbp+3Ch]
  unsigned int v9; // [xsp+3Ch] [xbp+3Ch]
  _BYTE *v10; // [xsp+40h] [xbp+40h]
  int i; // [xsp+4Ch] [xbp+4Ch]

  if ( a4 + 1 != a5 )
    return 0xFFFFFFFFLL;
  v10 = a3 + 1;
  if ( *a3 != 2 )
    return 0xFFFFFFFFLL;
  v8 = a4 - 1;
  for ( i = 0; i < v8; ++i )
  {
    v6 = v10++;
    if ( *v6 == 0 )
      break;
  }
  if ( i == v8 )
    return 0xFFFFFFFFLL;
  if ( i <= 7 )
    return 0xFFFFFFFFLL;
  v9 = v8 - (i + 1);
  if ( (int)v9 > a2 )
    return 0xFFFFFFFFLL;
  sub_10FAA4(a1, v10, v9);
  return v9;
}


/* ===== sub_10F8AC @ 0x10F8AC (file 0xF8AC) size 20 ===== */
__int64 sub_10F8AC()
{
  return 0;
}


/* ===== sub_10F8C0 @ 0x10F8C0 (file 0xF8C0) size 4 ===== */
// attributes: thunk
void __noreturn sub_10F8C0()
{
  while ( 1 )
    ;
}


/* ===== sub_10F8C4 @ 0x10F8C4 (file 0xF8C4) size 80 ===== */
_BYTE *__fastcall sub_10F8C4(_BYTE *a1, _BYTE *a2)
{
  _BYTE *v2; // x0
  _BYTE *v3; // x1
  _BYTE *v6; // [xsp+8h] [xbp-18h]

  v6 = a1;
  do
  {
    v2 = v6++;
    v3 = a2++;
    *v2 = *v3;
  }
  while ( *v2 != 0 );
  return a1;
}


/* ===== sub_10F914 @ 0x10F914 (file 0xF914) size 112 ===== */
_BYTE *__fastcall sub_10F914(_BYTE *a1, _BYTE *a2)
{
  _BYTE *v2; // x0
  _BYTE *v3; // x1
  _BYTE *i; // [xsp+8h] [xbp-18h]

  for ( i = a1; *i != 0; ++i )
    ;
  do
  {
    v2 = i++;
    v3 = a2++;
    *v2 = *v3;
  }
  while ( *v2 != 0 );
  return a1;
}


/* ===== sub_10F984 @ 0x10F984 (file 0xF984) size 136 ===== */
__int64 __fastcall sub_10F984(unsigned __int8 *a1, _BYTE *a2)
{
  unsigned __int8 *v2; // x0
  _BYTE *v3; // x0
  unsigned __int8 v7; // [xsp+1Fh] [xbp-1h]

  while ( 1 )
  {
    v2 = a1++;
    v7 = *v2;
    v3 = a2++;
    if ( v7 != (unsigned __int8)*v3 )
      break;
    if ( v7 == 0 )
      return 0;
  }
  if ( v7 >= (unsigned int)(unsigned __int8)*v3 )
    return 1;
  else
    return 0xFFFFFFFFLL;
}


/* ===== sub_10FA0C @ 0x10FA0C (file 0xFA0C) size 68 ===== */
_BYTE *__fastcall sub_10FA0C(_BYTE *a1)
{
  _BYTE *i; // [xsp+18h] [xbp-8h]

  for ( i = a1; *i != 0; ++i )
    ;
  return (_BYTE *)(i - a1);
}


/* ===== sub_10FA50 @ 0x10FA50 (file 0xFA50) size 84 ===== */
_BYTE *__fastcall sub_10FA50(_BYTE *a1, char a2, __int64 a3)
{
  _BYTE *v3; // x0
  __int64 v4; // x0
  _BYTE *i; // [xsp+28h] [xbp-8h]

  for ( i = a1; ; ++i )
  {
    v4 = a3--;
    if ( v4 == 0 )
      break;
    v3 = i;
    *v3 = a2;
  }
  return a1;
}


/* ===== sub_10FAA4 @ 0x10FAA4 (file 0xFAA4) size 100 ===== */
_BYTE *__fastcall sub_10FAA4(_BYTE *a1, _BYTE *a2, __int64 a3)
{
  _BYTE *v3; // x0
  _BYTE *v4; // x1
  __int64 v5; // x0
  _BYTE *v10; // [xsp+28h] [xbp-8h]

  v10 = a1;
  while ( 1 )
  {
    v5 = a3--;
    if ( v5 == 0 )
      break;
    v3 = v10++;
    v4 = a2++;
    *v3 = *v4;
  }
  return a1;
}


/* ===== sub_10FB08 @ 0x10FB08 (file 0xFB08) size 144 ===== */
__int64 __fastcall sub_10FB08(unsigned __int8 *a1, unsigned __int8 *a2, __int64 a3)
{
  unsigned int v5; // [xsp+2Ch] [xbp-14h]

  v5 = 0;
  while ( a3 != 0 )
  {
    v5 = *a1 - *a2;
    if ( v5 != 0 )
      break;
    ++a1;
    ++a2;
    --a3;
  }
  return v5;
}


// END total=287 ok=287 fail=0
