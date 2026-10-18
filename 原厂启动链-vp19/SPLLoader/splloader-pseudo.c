// pseudo-C decompilation of splloader.bin (vp19)
// source: /root/华强北手表/原厂启动链-vp19/SPLLoader/splloader.bin
//         md5 7bffee812fd10f4379f804a5c34ff678  size 262144 (trimmed 0x9694)
// VA = file offset + 0x5000 ; entry VA 0x5200
// produced headlessly by IDA 9.4.0.260714 + Hex-Rays (hexarm)
// functions: 176 (ok 176, fail 0)

/* ===== start @ 0x5200 (file 0x200) size 4 ===== */
// attributes: thunk
__int64 start()
{
  return start_0();
}


/* ===== sub_5208 @ 0x5208 (file 0x208) size 40 ===== */
unsigned __int64 sub_5208()
{
  unsigned __int64 result; // x0

  for ( result = 61408; result < 0xF218; result += 8LL )
    *(_QWORD *)result = 0;
  return result;
}


/* ===== start_0 @ 0x5238 (file 0x238) size 116 ===== */
__int64 __fastcall start_0(unsigned __int64 a1)
{
  unsigned __int64 StatusReg; // x1
  __int64 v2; // x0
  __int64 v3; // x0
  unsigned __int64 v4; // x0

  StatusReg = _ReadStatusReg(CurrentEL);
  if ( StatusReg != 12 )
  {
    if ( StatusReg == 8 )
    {
      _WriteStatusReg(VBAR_EL2, a1);
      _WriteStatusReg(CPTR_EL2, 0x33FFu);
      goto LABEL_7;
    }
    if ( StatusReg == 4 )
    {
      _WriteStatusReg(VBAR_EL1, a1);
      _WriteStatusReg(CPACR_EL1, 0x300000u);
      goto LABEL_7;
    }
  }
  _WriteStatusReg(VBAR_EL3, a1);
  _WriteStatusReg(CPTR_EL3, 0);
  _WriteStatusReg(CNTFRQ_EL0, 0x1800000u);
LABEL_7:
  v2 = sub_A154();
  v3 = sub_A1E4(v2);
  sub_A1F0(v3);
  v4 = sub_5208();
  sub_5888(v4);
  return sub_A45C();
}


/* ===== sub_52D8 @ 0x52D8 (file 0x2D8) size 16 ===== */
__int64 sub_52D8()
{
  return MEMORY[0x3009];
}


/* ===== sub_52E8 @ 0x52E8 (file 0x2E8) size 44 ===== */
__int64 sub_52E8()
{
  __int64 result; // x0
  unsigned int i; // [xsp+Ch] [xbp-4h]

  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i > 0xFF )
      break;
  }
  return result;
}


/* ===== sub_5314 @ 0x5314 (file 0x314) size 584 ===== */
__int64 sub_5314()
{
  unsigned int v0; // w3
  __int64 *v1; // x1
  unsigned __int64 v2; // x2
  __int64 *v3; // x5

  sub_9F14("vddcpu", 1100);
  sub_9F14("vddcore", 900);
  sub_52E8();
  MEMORY[0x402D02D0] = MEMORY[0x402D02D0] & 0xFFFFFFFC | 3;
  sub_52E8();
  MEMORY[0x20E00038] = MEMORY[0x20E00038] & 0xFFF8F8F8 | 0x10101;
  MEMORY[0x402D0274] |= 3u;
  v0 = MEMORY[0x403F0000] & 0xFFFFFF3A | 5;
  v1 = qword_DC30;
  while ( 1 )
  {
    v2 = *(v1 - 2);
    v3 = v1 - 2;
    if ( v2 > 0xFFFFFFFF )
      break;
    v1 += 2;
    if ( v2 >= 0x4D7C6D00 )
    {
      v0 |= (v3[1] & 3) << 6;
      break;
    }
  }
  MEMORY[0x403F0000] = v0;
  MEMORY[0x403F0004] = MEMORY[0x403F0004] & 0xC0000000 | 0x19000000;
  sub_9FCC(200);
  MEMORY[0x20E00054] = 3;
  sub_52E8();
  MEMORY[0x21500020] = MEMORY[0x21500020] & 0xFFFFFFFC | 3;
  MEMORY[0x402D0220] = MEMORY[0x402D0220] & 0xFFFFFFFC | 3;
  MEMORY[0x402D02C4] |= 1u;
  return 0;
}


/* ===== sub_555C @ 0x555C (file 0x55C) size 72 ===== */
__int64 __fastcall sub_555C(__int64 result)
{
  MEMORY[0x82000004] = result;
  MEMORY[0x82000000] = 1128615510;
  MEMORY[0x82000008] = 0;
  if ( (_DWORD)result == 258 )
  {
    result = sub_52D8();
    MEMORY[0x8200001C] = result;
  }
  else
  {
    MEMORY[0x8200001C] = 0;
  }
  return result;
}


/* ===== sub_55A4 @ 0x55A4 (file 0x5A4) size 144 ===== */
__int64 sub_55A4()
{
  __int64 result; // x0

  MEMORY[0x40410014] |= 1u;
  MEMORY[0x402B009C] &= 0xFFFFFCFF;
  MEMORY[0x402B009C] |= 0x100u;
  MEMORY[0x402B00A0] &= 0xFFFFFCFF;
  result = MEMORY[0x402B00A0] | 0x100u;
  MEMORY[0x402B00A0] |= 0x100u;
  return result;
}


/* ===== sub_5634 @ 0x5634 (file 0x634) size 288 ===== */
__int64 sub_5634()
{
  MEMORY[0x402B0080] |= 0x3Fu;
  MEMORY[0x402B0084] &= 0xFFFFFFC0;
  MEMORY[0x402B008C] |= 0x3Fu;
  MEMORY[0x402B0090] &= 0xFFFFFFC0;
  MEMORY[0x402B0088] &= ~1u;
  MEMORY[0x402B00A8] &= ~1u;
  MEMORY[0x402B009C] |= 2u;
  MEMORY[0x402B009C] &= 0xFFFFFFC2;
  MEMORY[0x402B00A0] |= 0x3Fu;
  MEMORY[0x402B00AC] |= 0x3Fu;
  return sub_52E8();
}


/* ===== sub_5754 @ 0x5754 (file 0x754) size 288 ===== */
__int64 sub_5754()
{
  __int64 result; // x0

  MEMORY[0x402E0120] |= 0xF000Fu;
  MEMORY[0x20E0000C] |= 1u;
  MEMORY[0x20E00010] |= 0x193Bu;
  MEMORY[0x20E00058] |= 0x20000u;
  MEMORY[0x20E00088] |= 0x20000u;
  MEMORY[0x20E00090] |= 0x20000u;
  MEMORY[0x20E00094] |= 0x20000u;
  MEMORY[0x20E00098] |= 0x20000u;
  MEMORY[0x20E0009C] |= 0x20000u;
  result = MEMORY[0x20E000AC] | 0x20000u;
  MEMORY[0x20E000AC] |= 0x20000u;
  return result;
}


/* ===== sub_5874 @ 0x5874 (file 0x874) size 20 ===== */
__int64 sub_5874()
{
  MEMORY[0x402E2004] = 48;
  return 1076764676;
}


/* ===== sub_5888 @ 0x5888 (file 0x888) size 308 ===== */
__int64 sub_5888()
{
  __int64 v0; // x0
  __int64 v1; // x0

  MEMORY[0x402B0300] |= 0x40000u;
  sub_A0A8();
  MEMORY[0x30040020] = 16434824;
  MEMORY[0x402E00B0] |= 0x2800u;
  MEMORY[0x21500020] &= 0xFFFFFFFC;
  MEMORY[0x402D02D0] &= 0xFFFFFFFC;
  MEMORY[0x40411000] = 8;
  v0 = sub_55A4();
  v1 = sub_9C50(v0);
  sub_9E38(v1);
  sub_5634();
  sub_5314();
  MEMORY[0x403C003C] |= 0xAu;
  MEMORY[0x403C0040] = MEMORY[0x403C0040] & 0xC0000000 | 0x11E27627;
  sub_9FCC(200);
  sub_5754();
  sub_5874();
  MEMORY[0x2150009C] |= 3u;
  return sub_82D8();
}


/* ===== sub_59BC @ 0x59BC (file 0x9BC) size 292 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_59BC()
{
  int v0; // w20
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 result; // x0

  dword_DC60 = 0;
  MEMORY[0x30000184] = 0x10000;
  v0 = 0x80000;
  v1 = sub_6B24(MEMORY[0x30000180], 13, 1, 1);
  v2 = sub_6B24(v1, 0, 1, 1);
  MEMORY[0x30000180] = v2;
  v3 = sub_6B24(v2, 12, 2, 0);
  MEMORY[0x30000180] = sub_6B24(v3, 0, 2, 3);
  do
  {
    if ( (MEMORY[0x30000180] & 4) != 0 )
      break;
    --v0;
  }
  while ( v0 != 0 );
  MEMORY[0x30000180] = sub_6B24(MEMORY[0x30000180], 0, 1, 0);
  result = 4294967294LL;
  if ( v0 != 0 )
    return (MEMORY[0x30000180] ^ 8LL) << 60 >> 63;
  return result;
}


/* ===== sub_5AE0 @ 0x5AE0 (file 0xAE0) size 192 ===== */
__int64 sub_5AE0()
{
  unsigned __int64 v1; // [xsp+28h] [xbp+28h] BYREF
  _DWORD v2[8]; // [xsp+30h] [xbp+30h] BYREF
  _DWORD v3[2]; // [xsp+50h] [xbp+50h] BYREF
  unsigned int v4; // [xsp+58h] [xbp+58h]
  char v5; // [xsp+5Ch] [xbp+5Ch] BYREF

  v2[0] = -286295074;
  v2[1] = 1108401006;
  v2[6] = 0;
  v2[2] = -1840740216;
  v2[7] = 0;
  v2[3] = -947419257;
  v3[0] = 0;
  v2[4] = 858987633;
  v2[5] = 85;
  v4 = 0x40000;
  sub_7694(&v1);
  if ( v4 > v1 )
    v4 = v1;
  v3[1] = v1 - v4;
  sub_70A4(&v5, v2, 32);
  if ( (unsigned int)sub_87CC(1, v3) != 0 )
    return 0xFFFFFFFFLL;
  else
    return 0;
}


/* ===== sub_5BA0 @ 0x5BA0 (file 0xBA0) size 28 ===== */
bool sub_5BA0()
{
  return (*(_DWORD *)(((((unsigned __int64)MEMORY[0x3000012C] >> 4) & 3) << 6) + 0x30000230) & 0x8000LL) != 0;
}


/* ===== sub_5BBC @ 0x5BBC (file 0xBBC) size 28 ===== */
bool sub_5BBC()
{
  return (*(_DWORD *)(((((unsigned __int64)MEMORY[0x3000012C] >> 4) & 3) << 6) + 0x3000022C) & 0x100LL) != 0;
}


/* ===== sub_5BD8 @ 0x5BD8 (file 0xBD8) size 64 ===== */
__int64 __fastcall sub_5BD8(unsigned int a1)
{
  unsigned __int64 v1; // x19
  __int64 result; // x0

  v1 = ((((unsigned __int64)MEMORY[0x3000012C] >> 4) & 3) << 6) + 805306368;
  result = sub_6B24(*(unsigned int *)(((((unsigned __int64)MEMORY[0x3000012C] >> 4) & 3) << 6) + 0x3000022C), 8, 1, a1);
  *(_DWORD *)(v1 + 556) = result;
  return result;
}


/* ===== sub_5C18 @ 0x5C18 (file 0xC18) size 244 ===== */
__int64 sub_5C18()
{
  unsigned int v0; // w24
  unsigned int v1; // w19
  unsigned int v2; // w23
  unsigned int v3; // w22
  unsigned int v4; // w21
  unsigned int v5; // w20
  __int64 i; // x0
  unsigned int v8; // [xsp+40h] [xbp+40h] BYREF
  unsigned int v9; // [xsp+44h] [xbp+44h]
  unsigned int v10; // [xsp+48h] [xbp+48h]
  unsigned int v11; // [xsp+4Ch] [xbp+4Ch]

  v0 = sub_5BBC();
  sub_5BD8(0);
  sub_6B48(100);
  sub_7BA8(8);
  sub_6B48(100);
  v1 = MEMORY[0x30000304] & 0x7F;
  v2 = MEMORY[0x30000404] & 0x7F;
  v8 = v2;
  v3 = MEMORY[0x30000504] & 0x7F;
  v9 = v3;
  v4 = MEMORY[0x30000604] & 0x7F;
  v10 = v4;
  v5 = MEMORY[0x30000704] & 0x7F;
  v11 = v5;
  if ( sub_5BA0() )
  {
    v1 >>= 1;
    v8 = v2 >> 1;
    v9 = v3 >> 1;
    v10 = v4 >> 1;
    v11 = v5 >> 1;
  }
  for ( i = 0; i != 16; i += 4 )
    *(_DWORD *)(i + 0xEFF0) = 4 * *(unsigned int *)((char *)&v8 + i);
  MEMORY[0xEFE0] = 4 * v1;
  return sub_5BD8(v0);
}


/* ===== sub_5D0C @ 0x5D0C (file 0xD0C) size 328 ===== */
__int64 __fastcall sub_5D0C(int *a1, unsigned int a2)
{
  int v2; // w2
  int v3; // w19
  int v4; // w20
  int v5; // w0
  __int64 result; // x0
  int v8; // w19
  int v9; // w20
  unsigned int v10; // w19
  __int64 v11; // x0
  __int64 v12; // x3
  __int64 v13; // x0
  __int64 v14; // x0

  v2 = *a1;
  v3 = a1[2];
  v4 = a1[1];
  v5 = a1[3];
  if ( v2 >= v3 )
    v3 = v2;
  if ( v5 <= v4 )
    v4 = v5;
  result = 0xFFFFFFFFLL;
  if ( (unsigned int)(v4 - v3) > 9 )
  {
    v8 = 2 * (v4 + v3) - 32;
    v9 = 4 * (MEMORY[0x30000304] & 0x7F);
    if ( !sub_5BA0() && !sub_5BBC() )
      v9 >>= 1;
    if ( sub_5BA0() && !sub_5BBC() )
      v9 >>= 2;
    if ( sub_5BA0() && sub_5BBC() )
      v9 >>= 1;
    if ( v8 >= v9 )
    {
      v10 = v8 - v9;
      v11 = a2;
      v12 = 2;
    }
    else
    {
      v10 = v9 - v8;
      v11 = a2;
      v12 = 3;
    }
    v13 = sub_6B24(v11, 30, 2, v12);
    v14 = sub_6B24(v13, 16, 7, v10 >> 2);
    MEMORY[0x30000308] = sub_6B24(v14, 28, 2, v10);
    MEMORY[0x30000300] |= 0x800u;
    sub_6B48(1);
    MEMORY[0x30000300] &= ~0x800u;
    return 0;
  }
  return result;
}


/* ===== sub_5E54 @ 0x5E54 (file 0xE54) size 548 ===== */
__int64 __fastcall sub_5E54(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  unsigned int v6; // w26
  unsigned int v7; // w25
  unsigned int v10; // w20
  unsigned int v11; // w19
  __int64 i; // x19
  unsigned int v13; // w20
  unsigned int v14; // w1
  unsigned int v15; // w20
  __int64 v16; // x3
  __int64 v17; // x0
  __int64 v18; // x0
  _DWORD *v19; // x20
  unsigned int v21; // [xsp+50h] [xbp+50h]
  unsigned int v22; // [xsp+54h] [xbp+54h]
  unsigned int v23; // [xsp+58h] [xbp+58h]
  unsigned int v24; // [xsp+5Ch] [xbp+5Ch]
  _QWORD v25[4]; // [xsp+60h] [xbp+60h]

  v6 = 4 * (MEMORY[0x30000404] & 0x7F);
  v21 = v6;
  v7 = 4 * (MEMORY[0x30000504] & 0x7F);
  v22 = v7;
  v10 = 4 * (MEMORY[0x30000604] & 0x7F);
  v23 = v10;
  v25[0] = 805307392;
  v25[1] = 805307648;
  v11 = 4 * (MEMORY[0x30000704] & 0x7F);
  v24 = v11;
  v25[2] = 805307904;
  v25[3] = 805308160;
  if ( !sub_5BA0() && !sub_5BBC() )
  {
    v21 = v6 >> 1;
    v22 = v7 >> 1;
    v23 = v10 >> 1;
    v24 = v11 >> 1;
  }
  if ( sub_5BA0() && !sub_5BBC() )
  {
    v21 >>= 2;
    v22 >>= 2;
    v23 >>= 2;
    v24 >>= 2;
  }
  if ( sub_5BA0() && sub_5BBC() )
  {
    v21 >>= 1;
    v22 >>= 1;
    v23 >>= 1;
    v24 >>= 1;
  }
  for ( i = 0; i != 4; ++i )
  {
    v13 = *(_DWORD *)(a3 + 4 * i) - a4;
    v14 = *(&v21 + i);
    if ( v13 >= v14 )
    {
      v15 = v13 - v14;
      v16 = 2;
    }
    else
    {
      v15 = v14 - v13;
      v16 = 3;
    }
    v17 = sub_6B24(*(unsigned int *)(a2 + 4 * i), 30, 2, v16);
    v18 = sub_6B24(v17, 16, 7, v15 >> 2);
    **(_DWORD **)(a1 + 8 * i) = sub_6B24(v18, 28, 2, v15);
    v19 = (_DWORD *)v25[i];
    *v19 |= 0x800u;
    sub_6B48(10);
    *v19 &= ~0x800u;
    sub_7668();
  }
  return 0;
}


/* ===== sub_6078 @ 0x6078 (file 0x1078) size 64 ===== */
__int64 __fastcall sub_6078(unsigned int a1)
{
  __int64 v1; // x3
  __int64 result; // x0

  if ( a1 > 0x1F )
    v1 = 31;
  else
    v1 = a1;
  result = sub_6B24(MEMORY[0x30000318], 24, 5, v1);
  MEMORY[0x30000318] = result;
  return result;
}


/* ===== sub_60B8 @ 0x60B8 (file 0x10B8) size 736 ===== */
__int64 __fastcall sub_60B8(int a1, unsigned int *a2)
{
  unsigned int v4; // w20
  unsigned int v5; // w20
  int v6; // w23
  int v7; // w22
  int v8; // w19
  unsigned int v9; // w27
  unsigned int v10; // w1
  int v11; // w1
  unsigned int v12; // w28
  __int64 v13; // x0
  __int64 v14; // x3
  __int64 result; // x0

  v4 = MEMORY[0xEFE0] + 32;
  sub_6078(0x1Fu);
  v5 = v4 >> 2;
  v6 = -1;
  if ( a1 != 0 )
    v7 = 257;
  else
    v7 = 21845;
  v8 = 0;
  v9 = 0;
  do
  {
    sub_6B48(2);
    MEMORY[0x30000108] = 0;
    MEMORY[0x30000104] = 553649151;
    while ( ((MEMORY[0x30000104] >> 20) & 0x7F) != 0 )
      ;
    sub_6B48(2);
    v10 = MEMORY[0x3000001C] & 0xF80
        | (MEMORY[0x3000001C] >> 4) & 3
        | (8 * (MEMORY[0x3000001C] & 1))
        | (((MEMORY[0x3000001C] & 0x8000) != 0) << 14)
        | (((MEMORY[0x3000001C] & 0x4000) != 0) << 12)
        | (((MEMORY[0x3000001C] & 0x2000) != 0) << 15)
        | (((MEMORY[0x3000001C] & 0x1000) != 0) << 13)
        | (16 * ((MEMORY[0x3000001C] & 0x40) != 0))
        | (32 * ((MEMORY[0x3000001C] & 8) != 0))
        | (((MEMORY[0x3000001C] & 4) != 0) << 6)
        | (4 * ((MEMORY[0x3000001C] & 2) != 0));
    v11 = (v10 ^ v7 | (v10 >> 1)) & v7;
    if ( v11 == 0 && v8 == 0 )
    {
      *a2 = v9;
      v6 = v9;
      v8 = 1;
    }
    if ( v8 != 0 && v11 != 0 )
    {
      if ( v6 == -1 || v9 == 0 )
      {
        v8 = 1;
      }
      else
      {
        if ( (int)(v9 - 1 - v6) > 10 )
          goto LABEL_22;
        v6 = -1;
        v8 = 0;
      }
    }
    ++v9;
    v12 = MEMORY[0x30000308];
    if ( v9 >= v5 - 8 )
    {
      sub_6078(0);
      v13 = v12;
      v14 = v9 - 8;
    }
    else
    {
      v13 = MEMORY[0x30000308];
      v14 = v9;
    }
    MEMORY[0x30000308] = sub_6B24(v13, 0, 7, v14);
  }
  while ( v9 < v5 );
  result = 0xFFFFFFFFLL;
  if ( v8 == 0 )
    return result;
LABEL_22:
  a2[1] = v9 - 1;
  return 0;
}


/* ===== sub_6398 @ 0x6398 (file 0x1398) size 512 ===== */
__int64 sub_6398()
{
  int v0; // w21
  unsigned int v1; // w22
  int v2; // w1
  unsigned __int16 v3; // w0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v7; // x0
  __int64 v8; // [xsp+48h] [xbp+48h] BYREF
  _QWORD v9[2]; // [xsp+50h] [xbp+50h] BYREF

  v0 = 0;
  v1 = MEMORY[0x30000308];
  MEMORY[0x30000480] = -1;
  MEMORY[0x30000484] = 0;
  MEMORY[0x30000488] = 0;
  MEMORY[0x3000048C] = -1;
  MEMORY[0x30000580] = -1;
  MEMORY[0x30000584] = 0;
  MEMORY[0x30000588] = 0;
  MEMORY[0x3000058C] = -1;
  MEMORY[0x30000680] = -1;
  MEMORY[0x30000684] = 0;
  MEMORY[0x30000688] = 0;
  MEMORY[0x3000068C] = -1;
  MEMORY[0x30000780] = -1;
  MEMORY[0x30000784] = 0;
  MEMORY[0x30000788] = 0;
  MEMORY[0x3000078C] = -1;
  v2 = 164;
  while ( 1 )
  {
    MEMORY[0x30000108] = v2;
    v3 = 48;
    if ( v0 == 0 )
      v3 = 41;
    MEMORY[0x30000104] = v3 | 0x1000000;
    while ( ((MEMORY[0x30000104] >> 20) & 0x7F) != 0 )
      ;
    MEMORY[0x30000100] = sub_6B24(MEMORY[0x30000100], 14, 1, 0);
    v4 = sub_6B24(MEMORY[0x30000308], 31, 1, 0);
    v5 = sub_6B24(v4, 0, 7, 0);
    MEMORY[0x30000308] = sub_6B24(v5, 24, 2, 0);
    if ( (sub_60B8(v0, (unsigned int *)&v8) & 0x80000000) != 0 )
    {
      MEMORY[0x30000308] = v1;
      return 0xFFFFFFFFLL;
    }
    v9[v0] = v8;
    MEMORY[0x30000100] = sub_6B24(MEMORY[0x30000100], 14, 1, 1);
    MEMORY[0x30000308] = sub_6B24(MEMORY[0x30000308], 31, 1, 1);
    MEMORY[0x30000108] = 168;
    MEMORY[0x30000104] = 16777258;
    while ( ((MEMORY[0x30000104] >> 20) & 0x7F) != 0 )
      ;
    v2 = 192;
    if ( v0 != 0 )
      break;
    v0 = 1;
  }
  MEMORY[0x30000480] = 0;
  MEMORY[0x30000484] = 0;
  MEMORY[0x30000488] = 0;
  MEMORY[0x3000048C] = 0;
  MEMORY[0x30000580] = 0;
  MEMORY[0x30000584] = 0;
  MEMORY[0x30000588] = 0;
  MEMORY[0x3000058C] = 0;
  MEMORY[0x30000680] = 0;
  MEMORY[0x30000684] = 0;
  MEMORY[0x30000688] = 0;
  MEMORY[0x3000068C] = 0;
  MEMORY[0x30000780] = 0;
  MEMORY[0x30000784] = 0;
  MEMORY[0x30000788] = 0;
  MEMORY[0x3000078C] = 0;
  if ( (unsigned int)sub_5D0C((int *)v9, v1) != 0 )
    MEMORY[0x30000308] = v1;
  v7 = sub_6078(0);
  sub_7668(v7);
  return 0;
}


/* ===== sub_6598 @ 0x6598 (file 0x1598) size 568 ===== */
__int64 __fastcall sub_6598(int a1)
{
  _DWORD *v1; // x0
  int v2; // w23
  int v3; // w5
  int v4; // w4
  int v5; // w3
  __int64 v6; // x22
  int v7; // w19
  int v8; // w20
  int v9; // w28
  int v10; // w26
  int *v11; // x0
  _DWORD *v12; // x0
  __int64 v13; // x0
  _DWORD v15[4]; // [xsp+60h] [xbp+60h] BYREF
  _DWORD v16[4]; // [xsp+70h] [xbp+70h] BYREF
  _QWORD v17[4]; // [xsp+80h] [xbp+80h] BYREF

  v1 = (_DWORD *)(4LL * a1);
  v2 = MEMORY[0x30000194];
  v17[0] = v1 + 201326851;
  v17[1] = v1 + 201326915;
  v17[2] = v1 + 201326979;
  v3 = v1[201326851];
  v4 = v1[201326915];
  v5 = v1[201326979];
  v15[3] = v1[201327043];
  v17[3] = v1 + 201327043;
  v6 = 0;
  v15[0] = v3;
  v15[1] = v4;
  v15[2] = v5;
  MEMORY[0x30000420] = 471604252;
  MEMORY[0x30000520] = 471604252;
  MEMORY[0x30000620] = 471604252;
  MEMORY[0x30000720] = 471604252;
  MEMORY[0x30000424] = 471604252;
  MEMORY[0x30000524] = 471604252;
  MEMORY[0x30000624] = 471604252;
  MEMORY[0x30000724] = 471604252;
  do
  {
    v7 = -1;
    v8 = -1;
    v9 = -1;
    v10 = 0;
    MEMORY[0x30000194] = *((_DWORD *)qword_D590 + v6);
    do
    {
      v11 = (int *)v17[v6];
      *v11 = v10;
      sub_7668(v11);
      if ( (unsigned int)sub_59BC() != 0 )
      {
        v7 = v10 - 1;
        if ( v10 != 0 && v8 != -1 )
        {
          if ( v7 - v8 > 10 )
          {
            v9 = 1;
            goto LABEL_16;
          }
          v7 = -1;
          v8 = -1;
        }
      }
      else
      {
        if ( v8 == -1 )
          v8 = v10;
        if ( v10 == 127 )
          v9 = 1;
      }
      ++v10;
    }
    while ( v10 != 128 );
    if ( v8 == -1 )
    {
      *(_DWORD *)v17[(int)v6] = v15[(int)v6];
      goto LABEL_23;
    }
LABEL_16:
    if ( ((v7 < v8) | ((unsigned int)v7 >> 31)) != 0 && v9 == 1 )
      v7 = 127;
    if ( v7 - v8 <= 9 )
    {
      v8 = -1;
      *(_DWORD *)v17[(int)v6] = v15[(int)v6];
      goto LABEL_23;
    }
    v12 = (_DWORD *)v17[v6];
    *v12 = v15[v6];
    sub_7668(v12);
    v16[v6++] = 2 * (v8 + v7);
  }
  while ( v6 != 4 );
  v8 = 0;
LABEL_23:
  v13 = 805306368;
  MEMORY[0x30000194] = v2;
  MEMORY[0x30000420] = 0;
  MEMORY[0x30000520] = 0;
  MEMORY[0x30000620] = 0;
  MEMORY[0x30000720] = 0;
  MEMORY[0x30000424] = 0;
  MEMORY[0x30000524] = 0;
  MEMORY[0x30000624] = 0;
  MEMORY[0x30000724] = 0;
  if ( v8 == 0 )
    v13 = sub_5E54((__int64)v17, (__int64)v15, (__int64)v16, 28);
  sub_7668(v13);
  return 0;
}


/* ===== sub_67D0 @ 0x67D0 (file 0x17D0) size 136 ===== */
__int64 __fastcall sub_67D0(unsigned int a1)
{
  unsigned int v1; // w20
  __int64 result; // x0

  if ( a1 > 0x1F )
    v1 = 31;
  else
    v1 = a1;
  MEMORY[0x30000428] = sub_6B24(MEMORY[0x30000428], 0, 5, v1);
  MEMORY[0x30000528] = sub_6B24(MEMORY[0x30000528], 0, 5, v1);
  MEMORY[0x30000628] = sub_6B24(MEMORY[0x30000628], 0, 5, v1);
  result = sub_6B24(MEMORY[0x30000728], 0, 5, v1);
  MEMORY[0x30000728] = result;
  return result;
}


/* ===== sub_6858 @ 0x6858 (file 0x1858) size 536 ===== */
__int64 sub_6858()
{
  __int64 v0; // x21
  unsigned int v1; // w25
  int v2; // w19
  int v3; // w20
  int v4; // w23
  unsigned int v5; // w24
  unsigned int *v6; // x0
  _DWORD *v7; // x0
  __int64 v8; // x0
  int v10; // [xsp+6Ch] [xbp+6Ch]
  _DWORD v11[4]; // [xsp+70h] [xbp+70h] BYREF
  _DWORD v12[4]; // [xsp+80h] [xbp+80h] BYREF
  _QWORD v13[4]; // [xsp+90h] [xbp+90h] BYREF

  v0 = 0;
  v10 = MEMORY[0x30000194];
  v13[0] = 805307400;
  v13[1] = 805307656;
  v13[2] = 805307912;
  v13[3] = 805308168;
  v11[0] = MEMORY[0x30000408];
  v11[1] = MEMORY[0x30000508];
  v11[2] = MEMORY[0x30000608];
  v11[3] = MEMORY[0x30000708];
  do
  {
    v1 = 0;
    MEMORY[0x30000194] = *((_DWORD *)qword_D590 + v0);
    sub_67D0(0x1Fu);
    v2 = -1;
    v3 = -1;
    v4 = -1;
    v5 = *(_DWORD *)(4 * v0 + 0xEFF0) >> 2;
    while ( v1 < v5 + 8 )
    {
      if ( v1 >= v5 )
      {
        sub_67D0(0);
        v6 = (unsigned int *)v13[v0];
        *v6 = v1 - 8;
      }
      else
      {
        v6 = (unsigned int *)v13[v0];
        *v6 = v1;
      }
      sub_7668(v6);
      if ( (unsigned int)sub_59BC() != 0 )
      {
        v2 = v1 - 1;
        if ( v1 != 0 && v3 != -1 )
        {
          if ( v2 - v3 > 10 )
          {
            v4 = 1;
            goto LABEL_20;
          }
          v2 = -1;
          v3 = -1;
        }
      }
      else
      {
        if ( v3 == -1 )
          v3 = v1;
        if ( v1 == v5 + 7 )
          v4 = 1;
      }
      ++v1;
    }
    if ( v3 == -1 )
    {
      *(_DWORD *)v13[(int)v0] = v11[(int)v0];
      goto LABEL_25;
    }
LABEL_20:
    if ( ((v2 < v3) | ((unsigned int)v2 >> 31)) != 0 && v4 == 1 )
      v2 = v5 + 7;
    v7 = (_DWORD *)v13[v0];
    *v7 = v11[v0];
    sub_7668(v7);
    v12[v0++] = 2 * (v3 + v2) - 32;
  }
  while ( v0 != 4 );
  v3 = 0;
LABEL_25:
  MEMORY[0x30000194] = v10;
  if ( v3 == 0 )
    sub_5E54((__int64)v13, (__int64)v11, (__int64)v12, 0);
  v8 = sub_67D0(0);
  sub_7668(v8);
  return 0;
}


/* ===== sub_6A70 @ 0x6A70 (file 0x1A70) size 8 ===== */
__int64 sub_6A70()
{
  return 0;
}


/* ===== sub_6A78 @ 0x6A78 (file 0x1A78) size 172 ===== */
__int64 __fastcall sub_6A78(int a1)
{
  const char *v2; // x0

  if ( (unsigned int)sub_5AE0() != 0 )
    sub_7074("sipi_bist_simple_test  first faile do not care\r\n");
  if ( a1 == 667 )
  {
    if ( (unsigned int)sub_6858() != 0 )
    {
      v2 = "dmc_lpddr3_wde_training  Failed\r\n";
LABEL_8:
      sub_7074(v2);
      return 0xFFFFFFFFLL;
    }
    if ( (unsigned int)sub_6598(0) != 0 )
    {
      v2 = "dmc_lpddr3_rde_training_pos failed\r\n";
      goto LABEL_8;
    }
    if ( (unsigned int)sub_6598(1) != 0 )
    {
      v2 = "dmc_lpddr3_rde_training_neg failed\r\n";
      goto LABEL_8;
    }
    if ( (unsigned int)sub_5AE0() != 0 )
    {
      v2 = "sipi_bist_simple_test  lasted Failed\r\n";
      goto LABEL_8;
    }
  }
  return 0;
}


/* ===== sub_6B24 @ 0x6B24 (file 0x1B24) size 36 ===== */
__int64 __fastcall sub_6B24(int a1, char a2, char a3, unsigned int a4)
{
  return a1 & ~(((1 << a3) - 1) << a2) | ((((1 << a3) - 1) & a4) << a2);
}


/* ===== sub_6B48 @ 0x6B48 (file 0x1B48) size 68 ===== */
__int64 __fastcall sub_6B48(int a1)
{
  int v1; // w0
  int i; // [xsp+8h] [xbp-8h]
  unsigned int v4; // [xsp+Ch] [xbp-4h]

  v1 = 2 * a1;
  for ( i = 0; i < v1; ++i )
    v4 = MEMORY[0x402B00C4];
  return v4;
}


/* ===== sub_6B8C @ 0x6B8C (file 0x1B8C) size 216 ===== */
__int64 __fastcall sub_6B8C(unsigned int a1, unsigned int a2, _BYTE *a3, int a4)
{
  unsigned int v4; // w20
  int v8; // w0
  int v9; // w0
  int v10; // w0
  unsigned __int64 v11; // x0
  int i; // w3
  __int64 v13; // x0

  v4 = -1;
  if ( a1 <= 1 )
  {
    v8 = sub_6B24(MEMORY[0x30000104], 0, 16, a2);
    v9 = sub_6B24(v8, 31, 1, 0);
    v10 = sub_6B24(v9, 28, 1, a1 != 0);
    MEMORY[0x30000104] = sub_6B24(v10, 25, 1, 1u);
    do
      v11 = ((unsigned __int64)MEMORY[0x30000104] >> 20) & 0x7F;
    while ( (_DWORD)v11 != 0 );
    for ( i = a4; i > 0; --i )
    {
      v11 = MEMORY[0x30000108];
      if ( (MEMORY[0x30000108] & 0x10000) != 0 )
      {
        v13 = MEMORY[0x30000108] >> 8;
        *a3 = MEMORY[0x30000109];
        v4 = 0;
        sub_7668(v13);
        return v4;
      }
    }
    v4 = -1;
    sub_7668(v11);
  }
  return v4;
}


/* ===== sub_6C64 @ 0x6C64 (file 0x1C64) size 332 ===== */
__int64 __fastcall sub_6C64(unsigned int a1, unsigned int a2, _BYTE *a3, int a4, unsigned int a5)
{
  unsigned int v6; // w1
  int v10; // w0
  int v11; // w0
  int v12; // w0
  unsigned __int64 v13; // x0
  int i; // w3
  __int64 v15; // x0

  v6 = -1;
  if ( a1 <= 1 )
  {
    MEMORY[0x30000110] = sub_6B24(MEMORY[0x30000110], 0, 24, a5);
    v10 = sub_6B24(MEMORY[0x30000104], 0, 16, a2);
    v11 = sub_6B24(v10, 31, 1, 0);
    v12 = sub_6B24(v11, 28, 1, a1 != 0);
    MEMORY[0x30000104] = sub_6B24(v12, 25, 1, 1u);
    do
      v13 = ((unsigned __int64)MEMORY[0x30000104] >> 20) & 0x7F;
    while ( (_DWORD)v13 != 0 );
    for ( i = a4; i > 0; --i )
    {
      v13 = MEMORY[0x30000108];
      if ( (MEMORY[0x30000108] & 0x10000) != 0 )
      {
        v15 = MEMORY[0x30000108] >> 8;
        *a3 = MEMORY[0x30000109];
        sub_7668(v15);
        return 0;
      }
    }
    sub_7668(v13);
    return (unsigned int)-1;
  }
  return v6;
}


/* ===== sub_6DB0 @ 0x6DB0 (file 0x1DB0) size 200 ===== */
unsigned __int64 __fastcall sub_6DB0(int a1, unsigned int a2, unsigned __int8 a3)
{
  int v5; // w0
  char v6; // w1
  unsigned int v7; // w3
  int v8; // w0
  unsigned __int64 result; // x0

  MEMORY[0x30000108] = sub_6B24(MEMORY[0x30000108], 0, 8, a3);
  v5 = sub_6B24(MEMORY[0x30000104], 0, 16, a2);
  v6 = 31;
  if ( a1 != 0 )
  {
    if ( a1 == 1 )
    {
      v5 = sub_6B24(v5, 31, 1, 0);
      v6 = 28;
    }
    v7 = 1;
  }
  else
  {
    v5 = sub_6B24(v5, 31, 1, 0);
    v6 = 28;
    v7 = 0;
  }
  v8 = sub_6B24(v5, v6, 1, v7);
  MEMORY[0x30000104] = sub_6B24(v8, 24, 1, 1u);
  do
    result = ((unsigned __int64)MEMORY[0x30000104] >> 20) & 0x7F;
  while ( (_DWORD)result != 0 );
  return result;
}


/* ===== sub_6E78 @ 0x6E78 (file 0x1E78) size 408 ===== */
__int64 __fastcall sub_6E78(int a1, int a2)
{
  unsigned __int8 v2; // w2
  BOOL v3; // w1

  if ( a1 == 3 && a2 == 1 )
  {
    v2 = 1;
LABEL_34:
    sub_6DB0(2, 2u, v2);
    return 0;
  }
  if ( a1 == 4 && a2 == 2 )
  {
    v2 = 2;
    goto LABEL_34;
  }
  if ( a1 == 5 && a2 == 2 )
  {
    v2 = 3;
    goto LABEL_34;
  }
  if ( a1 == 6 && a2 == 3 )
  {
    v2 = 4;
    goto LABEL_34;
  }
  if ( a1 == 7 && a2 == 4 )
  {
    v2 = 5;
    goto LABEL_34;
  }
  if ( a1 == 8 && a2 == 4 )
  {
    v2 = 6;
    goto LABEL_34;
  }
  if ( a1 == 9 && a2 == 5 )
  {
    v2 = 7;
    goto LABEL_34;
  }
  if ( a1 == 10 && a2 == 6 )
  {
    v2 = 8;
    goto LABEL_34;
  }
  if ( a1 == 11 && a2 == 6 )
  {
    v2 = 9;
    goto LABEL_34;
  }
  if ( a1 == 12 && a2 == 6 )
  {
    v2 = 10;
    goto LABEL_34;
  }
  v3 = a2 == 8;
  if ( a1 == 14 && v3 )
  {
    v2 = 12;
    goto LABEL_34;
  }
  if ( a1 == 16 && v3 )
  {
    v2 = 14;
    goto LABEL_34;
  }
  return 0xFFFFFFFFLL;
}


/* ===== sub_7010 @ 0x7010 (file 0x2010) size 100 ===== */
__int64 __fastcall sub_7010(int a1)
{
  unsigned __int8 v1; // w2
  bool v2; // zf

  v1 = 4;
  if ( a1 != 60 )
  {
    if ( a1 > 60 )
    {
      v1 = 6;
      if ( a1 == 80 )
        goto LABEL_9;
      v1 = 7;
      v2 = a1 == 120;
    }
    else
    {
      v1 = 1;
      if ( a1 == 34 )
        goto LABEL_9;
      v1 = 3;
      v2 = a1 == 48;
    }
    if ( !v2 )
      v1 = 2;
  }
LABEL_9:
  sub_6DB0(2, 3u, v1);
  return 0;
}


/* ===== sub_7074 @ 0x7074 (file 0x2074) size 48 ===== */
_BYTE *__fastcall sub_7074(_BYTE *result)
{
  while ( *result != 0 )
  {
    while ( MEMORY[0x7010000D] != 0 )
      ;
    MEMORY[0x70100000] = (unsigned __int8)*result++;
  }
  return result;
}


/* ===== sub_70A4 @ 0x70A4 (file 0x20A4) size 88 ===== */
__int64 __fastcall sub_70A4(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x4
  __int64 v4; // x3
  __int64 i; // x3

  v3 = result;
  v4 = ((unsigned __int8)result | (unsigned __int8)a2) & 7;
  if ( (((unsigned __int8)result | (unsigned __int8)a2) & 7) == 0 )
  {
    while ( v4 != (a3 & 0xFFFFFFFFFFFFFFF8LL) )
    {
      *(_QWORD *)(result + v4) = *(_QWORD *)(a2 + v4);
      v4 += 8;
    }
    a3 &= 7u;
    v3 = result + v4;
    a2 += v4;
  }
  for ( i = 0; i != a3; ++i )
    *(_BYTE *)(v3 + i) = *(_BYTE *)(a2 + i);
  return result;
}


/* ===== sub_70FC @ 0x70FC (file 0x20FC) size 200 ===== */
__int64 __fastcall sub_70FC(int a1, int a2)
{
  MEMORY[0x300E32A8] |= 0x3FFFu;
  MEMORY[0x300E32AC] = a1;
  MEMORY[0x300E32B0] = a2;
  MEMORY[0x300E32B4] = a1;
  MEMORY[0x300E32B8] = a2;
  MEMORY[0x300E32BC] = a1;
  MEMORY[0x300E32C0] = a2;
  MEMORY[0x300E32C4] = a1;
  MEMORY[0x300E32C8] = a2;
  MEMORY[0x300E32CC] = a1;
  MEMORY[0x300E32D0] = a2;
  MEMORY[0x300E32D4] = a1;
  MEMORY[0x300E32D8] = a2;
  MEMORY[0x300E32DC] = a1;
  MEMORY[0x300E32E0] = a2;
  return 806236896;
}


/* ===== sub_71C4 @ 0x71C4 (file 0x21C4) size 472 ===== */
__int64 __fastcall sub_71C4(__int64 result)
{
  int v1; // w7
  unsigned int v2; // w5
  int v3; // w1
  unsigned __int64 v4; // x6
  unsigned int v5; // w2
  int v6; // w1
  unsigned int v7; // w19
  unsigned int v8; // w3
  int v9; // w0
  unsigned int v10; // w21
  unsigned int v11; // w19
  int v12; // w0
  int v13; // w0
  int v14; // w0
  int v15; // [xsp+38h] [xbp+38h]
  int v16; // [xsp+3Ch] [xbp+3Ch]

  v1 = MEMORY[0x403D0000] >> 20;
  v2 = ((MEMORY[0x403D0000] >> 22) & 3) - 1;
  v3 = 2;
  v4 = ((unsigned __int64)MEMORY[0x403D0004] >> 23) & 0x7F;
  if ( v2 <= 2 )
    v3 = *((unsigned __int8 *)qword_D580 + v2);
  if ( (((MEMORY[0x403D0000] & 0x40000LL) != 0) & (unsigned __int8)v1) != 0 )
  {
    v5 = v3 * (MEMORY[0x403D0004] & 0x7FFFFF);
    v6 = v3 * v4 + (v5 >> 23);
    if ( (v5 & 0x7FFFFF) > 0x3FFFFE )
      ++v6;
  }
  else if ( (((MEMORY[0x403D0000] & 0x40000LL) == 0) & (unsigned __int8)v1) != 0 )
  {
    v6 = v3 * v4;
  }
  else
  {
    v6 = v3 * (MEMORY[0x403D0000] & 0x7FF);
  }
  if ( v6 != (_DWORD)result )
  {
    v7 = result;
    v16 = MEMORY[0x403D0004];
    if ( (unsigned int)(result - 1241) > 0x167 )
      v8 = (unsigned int)result > 0x3A8;
    else
      v8 = 2;
    v9 = sub_6B24(MEMORY[0x403D0000], 15, 2, v8);
    v10 = v7 / 0x1A;
    v11 = v7 % 0x1A;
    if ( v11 != 0 )
    {
      v13 = sub_6B24(v9, 9, 1, 1u);
      v15 = sub_6B24(v13, 11, 1, 1u);
      v14 = sub_6B24(v16, 23, 7, v10);
      v16 = sub_6B24(v14, 0, 23, (v11 << 23) / 0x1A);
    }
    else
    {
      v12 = sub_6B24(v9, 17, 11, v10);
      v15 = sub_6B24(v12, 9, 1, 0);
    }
    MEMORY[0x403D0000] = v15;
    MEMORY[0x403D0004] = v16;
    return sub_6B48(200);
  }
  return result;
}


/* ===== sub_739C @ 0x739C (file 0x239C) size 716 ===== */
__int64 sub_739C()
{
  int v0; // w20
  int v1; // w0
  int v2; // w0
  int v3; // w22
  int v4; // w22
  int v5; // w0
  int v6; // w23
  unsigned int v7; // w3
  int v8; // w20
  int v9; // w0
  int v10; // w22
  int v11; // w22
  int v12; // w0
  int v13; // w23
  unsigned int v14; // w20
  unsigned __int64 v15; // x21
  int v16; // w0
  int v17; // w0
  int v18; // w0
  int v19; // w0
  __int64 result; // x0

  v0 = 0;
  v1 = sub_6B24(MEMORY[0x30000008], 16, 1, 0);
  MEMORY[0x30000008] = sub_6B24(v1, 10, 5, 0x1Eu);
  sub_6B48(2);
  v2 = sub_6B24(MEMORY[0x30000008], 15, 1, 0);
  v3 = sub_6B24(v2, 0, 5, 0);
  MEMORY[0x30000008] = v3;
  while ( (MEMORY[0x30000008] & 0x20000) != 0 )
  {
    v3 = sub_6B24(v3, 0, 5, ++v0);
    MEMORY[0x30000008] = v3;
    sub_6B48(1);
  }
  v4 = 31;
  v5 = sub_6B24(MEMORY[0x30000008], 15, 1, 0);
  v6 = sub_6B24(v5, 0, 5, 0x1Fu);
  MEMORY[0x30000008] = v6;
  while ( (MEMORY[0x30000008] & 0x20000) == 0 )
  {
    v6 = sub_6B24(v6, 0, 5, --v4);
    MEMORY[0x30000008] = v6;
    sub_6B48(1);
  }
  v7 = (unsigned int)(v4 + v0) >> 1;
  v8 = 0;
  MEMORY[0x30000008] = sub_6B24(MEMORY[0x30000008], 0, 5, v7);
  v9 = sub_6B24(MEMORY[0x30000008], 15, 1, 1u);
  v10 = sub_6B24(v9, 5, 5, 0);
  MEMORY[0x30000008] = v10;
  while ( (MEMORY[0x30000008] & 0x20000) == 0 )
  {
    v10 = sub_6B24(v10, 5, 5, ++v8);
    MEMORY[0x30000008] = v10;
    sub_6B48(1);
  }
  v11 = 31;
  v12 = sub_6B24(MEMORY[0x30000008], 15, 1, 1u);
  v13 = sub_6B24(v12, 5, 5, 0x1Fu);
  MEMORY[0x30000008] = v13;
  while ( (MEMORY[0x30000008] & 0x20000) != 0 )
  {
    v13 = sub_6B24(v13, 5, 5, --v11);
    MEMORY[0x30000008] = v13;
    sub_6B48(1);
  }
  MEMORY[0x30000008] = sub_6B24(MEMORY[0x30000008], 5, 5, (unsigned int)(v11 + v8) >> 1);
  MEMORY[0x30000008] = sub_6B24(MEMORY[0x30000008], 16, 1, 1u);
  v14 = MEMORY[0x30000008] & 0x1F;
  v15 = ((unsigned __int64)MEMORY[0x30000008] >> 5) & 0x1F;
  v16 = sub_6B24(MEMORY[0x30000390], 21, 1, 1u);
  v17 = sub_6B24(v16, 0, 5, v15);
  MEMORY[0x30000390] = sub_6B24(v17, 8, 5, v14);
  v18 = sub_6B24(MEMORY[0x30000490], 21, 1, 1u);
  v19 = sub_6B24(v18, 0, 5, v15);
  result = sub_6B24(v19, 8, 5, v14);
  MEMORY[0x30000490] = result;
  return result;
}


/* ===== sub_7668 @ 0x7668 (file 0x2668) size 32 ===== */
__int64 sub_7668()
{
  MEMORY[0x30000100] |= 0x10000u;
  MEMORY[0x30000100] &= ~0x10000u;
  return 805306368;
}


/* ===== sub_7688 @ 0x7688 (file 0x2688) size 12 ===== */
__int64 sub_7688()
{
  return 32;
}


/* ===== sub_7694 @ 0x7694 (file 0x2694) size 80 ===== */
__int64 __fastcall sub_7694(_QWORD *a1)
{
  *a1 = 0x40000000;
  return 0;
}


/* ===== sub_76E4 @ 0x76E4 (file 0x26E4) size 52 ===== */
__int64 __fastcall sub_76E4(int a1, _DWORD *a2)
{
  __int64 result; // x0

  if ( a1 == 0 || (result = 0xFFFFFFFFLL, a1 == 1) )
  {
    *a2 = 0x40000000;
    return 0;
  }
  return result;
}


/* ===== sub_7718 @ 0x7718 (file 0x2718) size 36 ===== */
__int64 sub_7718()
{
  return 4096;
}


/* ===== sub_773C @ 0x773C (file 0x273C) size 44 ===== */
__int64 sub_773C()
{
  return 0x8000;
}


/* ===== sub_7768 @ 0x7768 (file 0x2768) size 44 ===== */
__int64 sub_7768()
{
  return 0x8000;
}


/* ===== sub_7794 @ 0x7794 (file 0x2794) size 28 ===== */
__int64 sub_7794()
{
  return 4;
}


/* ===== sub_77B0 @ 0x77B0 (file 0x27B0) size 252 ===== */
__int64 __fastcall sub_77B0(unsigned int a1, unsigned int *a2)
{
  unsigned int v4; // w23
  unsigned int v5; // w24
  unsigned int v6; // w22
  int v7; // w0
  unsigned int v8; // w1
  unsigned int v9; // w2
  unsigned int v10; // w19
  unsigned int v11; // w19
  unsigned int v13; // [xsp+44h] [xbp+44h] BYREF
  unsigned __int64 v14; // [xsp+48h] [xbp+48h] BYREF

  v4 = sub_7718();
  v5 = sub_773C();
  v6 = sub_7794();
  if ( a1 > 0x40000000 )
    v5 = sub_7768();
  v7 = sub_7694(&v14);
  v8 = -1;
  if ( v7 == 0 )
  {
    v8 = sub_76E4(0, &v13);
    if ( v8 != 0 )
    {
      return (unsigned int)-2;
    }
    else if ( a1 % 4 != 0 )
    {
      return (unsigned int)-3;
    }
    else if ( v14 < a1 )
    {
      return (unsigned int)-4;
    }
    else
    {
      v9 = v13;
      *a2 = a1 / v13;
      v10 = a1 % v9;
      a2[2] = v10 / v5;
      v11 = v10 % v5;
      a2[1] = v11 / v4;
      a2[3] = v11 % v4 / v6;
    }
  }
  return v8;
}


/* ===== sub_78AC @ 0x78AC (file 0x28AC) size 260 ===== */
__int64 __fastcall sub_78AC(unsigned int a1)
{
  int v1; // w19
  int v2; // w0
  unsigned int v3; // w3
  __int64 v4; // x0
  int v5; // w0
  unsigned int v6; // w3
  __int64 result; // x0

  v1 = MEMORY[0x402E00AC];
  if ( a1 == 400 )
  {
    v4 = 800;
    goto LABEL_15;
  }
  if ( a1 > 0x190 )
  {
    if ( a1 == 533 )
    {
      v4 = 1067;
    }
    else
    {
      if ( a1 != 466 )
        goto LABEL_14;
      v4 = 932;
    }
LABEL_15:
    sub_71C4(v4);
    v5 = v1;
    v6 = 4;
    goto LABEL_16;
  }
  if ( a1 == 256 )
  {
    v5 = MEMORY[0x402E00AC];
    v6 = 1;
LABEL_16:
    v2 = sub_6B24(v5, 6, 3, v6);
    v3 = 0;
    goto LABEL_17;
  }
  if ( a1 == 384 )
  {
    v5 = MEMORY[0x402E00AC];
    v6 = 3;
    goto LABEL_16;
  }
  if ( a1 != 166 )
  {
LABEL_14:
    v4 = 1334;
    goto LABEL_15;
  }
  sub_71C4(1334);
  v2 = sub_6B24(v1, 6, 3, 4u);
  v3 = 3;
LABEL_17:
  result = sub_6B24(v2, 2, 4, v3);
  MEMORY[0x402E00AC] = result;
  return result;
}


/* ===== sub_79B0 @ 0x79B0 (file 0x29B0) size 184 ===== */
__int64 __fastcall sub_79B0(unsigned int a1, unsigned int a2)
{
  int v4; // w0

  MEMORY[0x30000398] = 1749045779;
  MEMORY[0x3000039C] = 151;
  nullsub_1();
  sub_8AA0(258, a1, a2);
  MEMORY[0x3000000C] = sub_6B24(MEMORY[0x3000000C], 0, 15, 0);
  MEMORY[0x30000100] = sub_6B24(MEMORY[0x30000100], 17, 1, 1u);
  v4 = sub_6B24(MEMORY[0x3000012C], 0, 4, 0);
  MEMORY[0x3000012C] = sub_6B24(v4, 4, 2, a2);
  return 0;
}


/* ===== sub_7A68 @ 0x7A68 (file 0x2A68) size 320 ===== */
__int64 __fastcall sub_7A68(int a1)
{
  int v2; // w0
  int v3; // w0
  int v4; // w0
  unsigned int v5; // w3

  MEMORY[0x30000398] = 1749045779;
  MEMORY[0x3000039C] = 151;
  nullsub_1();
  v2 = sub_6B24(MEMORY[0x30000004], 0, 3, 1u);
  v3 = sub_6B24(v2, 16, 3, 1u);
  MEMORY[0x30000004] = sub_6B24(v3, 20, 6, 0);
  sub_8B80(258, &dword_DD80);
  MEMORY[0x3000000C] = sub_6B24(MEMORY[0x3000000C], 0, 15, 0);
  MEMORY[0x30000100] = sub_6B24(MEMORY[0x30000100], 17, 1, 1u);
  v4 = sub_6B24(MEMORY[0x3000012C], 0, 4, 0);
  switch ( a1 )
  {
    case 667:
      v5 = 0;
      break;
    case 384:
      v5 = 1;
      break;
    case 256:
      v5 = 2;
      break;
    default:
      v5 = 3;
      break;
  }
  MEMORY[0x3000012C] = sub_6B24(v4, 4, 2, v5);
  return 0;
}


/* ===== sub_7BA8 @ 0x7BA8 (file 0x2BA8) size 204 ===== */
__int64 __fastcall sub_7BA8(unsigned int a1)
{
  int v2; // w0
  int v3; // w0
  int v4; // w0
  int v5; // w0

  sub_8C88(258);
  while ( (MEMORY[0x30000304]
         & MEMORY[0x30000404]
         & 0x10000000
         & MEMORY[0x30000504]
         & MEMORY[0x30000604]
         & MEMORY[0x30000704]) == 0 )
    ;
  v2 = sub_6B24(MEMORY[0x30000300], 9, 2, 3u);
  v3 = sub_6B24(v2, 12, 1, 1u);
  v4 = sub_6B24(v3, 14, 1, 1u);
  v5 = sub_6B24(v4, 27, 1, 1u);
  MEMORY[0x30000300] = sub_6B24(v5, 0, 7, a1);
  MEMORY[0x30000400] = MEMORY[0x30000300];
  MEMORY[0x30000500] = MEMORY[0x30000300];
  MEMORY[0x30000600] = MEMORY[0x30000300];
  MEMORY[0x30000700] = MEMORY[0x30000300];
  return 0;
}


/* ===== sub_7C74 @ 0x7C74 (file 0x2C74) size 104 ===== */
__int64 __fastcall sub_7C74(int *a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int v7; // w0
  int v8; // w0
  __int64 result; // x0

  v7 = sub_6B24(*a1, 0, 4, a2);
  v8 = sub_6B24(v7, 16, 8, a3);
  result = sub_6B24(v8, 24, 8, a4);
  *a1 = result;
  return result;
}


/* ===== sub_7CDC @ 0x7CDC (file 0x2CDC) size 104 ===== */
__int64 __fastcall sub_7CDC(int *a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int v7; // w0
  int v8; // w0
  __int64 result; // x0

  v7 = sub_6B24(*a1, 0, 4, a2);
  v8 = sub_6B24(v7, 16, 10, a3);
  result = sub_6B24(v8, 31, 1, a4);
  *a1 = result;
  return result;
}


/* ===== sub_7D44 @ 0x7D44 (file 0x2D44) size 1192 ===== */
_BYTE *__fastcall sub_7D44(int a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5)
{
  int v6; // w20
  int v7; // w0
  int v8; // w1
  __int64 *v9; // x3
  unsigned int v10; // w3
  int v11; // w0
  int v12; // w0
  int v13; // w0
  int v14; // w0
  int v16; // w0
  int v17; // w0
  int v18; // w0
  int v19; // w0
  int v20; // w0
  int v21; // w0
  int v22; // w1
  int v23; // w0
  int v24; // w0
  char v25; // [xsp+37h] [xbp+37h] BYREF
  unsigned __int64 v26; // [xsp+38h] [xbp+38h] BYREF

  do
    sub_6C64(0, 0, &v25, 10000, a5);
  while ( (v25 & 1) != 0 );
  if ( (unsigned int)sub_92E4() != 0 )
    return sub_7074("lpddr auto detect failed\r\n");
  if ( a1 == 667 )
  {
    sub_6398();
    sub_6A70();
  }
  v6 = MEMORY[0x30000000];
  sub_7694(&v26);
  v7 = sub_6B24(v6, 4, 3, 3u);
  v8 = 0;
  v9 = &qword_D768[1];
  do
  {
    if ( v26 <= *v9 )
    {
      v10 = LODWORD(qword_D768[2 * v8]) - 24;
      goto LABEL_9;
    }
    ++v8;
    v9 += 2;
  }
  while ( v8 != 9 );
  v10 = 7;
LABEL_9:
  v11 = sub_6B24(v7, 0, 3, v10);
  v12 = sub_6B24(v11, 0, 3, 7u);
  v13 = sub_6B24(v12, 14, 2, 1u);
  v14 = sub_6B24(v13, 9, 2, 3u);
  MEMORY[0x30000000] = sub_6B24(v14, 28, 1, 1u);
  v16 = sub_6B24(MEMORY[0x30000100], 4, 3, 2u);
  v17 = sub_6B24(v16, 8, 1, 1u);
  MEMORY[0x30000100] = sub_6B24(v17, 7, 1, 1u);
  v18 = sub_6B24(MEMORY[0x30000124], 0, 3, 5u);
  v19 = sub_6B24(v18, 4, 8, 0xFFu);
  MEMORY[0x30000124] = sub_6B24(v19, 16, 4, 0xFu);
  v20 = sub_6B24(MEMORY[0x30000114], 0, 24, 0x600000u);
  MEMORY[0x30000114] = sub_6B24(v20, 24, 2, 1u);
  v21 = sub_6B24(MEMORY[0x3000010C], 12, 1, 1u);
  v22 = sub_6B24(v21, 13, 1, 0);
  MEMORY[0x3000010C] = sub_6B24(v22, 15, 1, 1u);
  v23 = sub_6B24(MEMORY[0x3000012C], 0, 4, 7u);
  v24 = sub_6B24(v23, 17, 1, 1u);
  MEMORY[0x3000012C] = sub_6B24(v24, 20, 12, 0);
  MEMORY[0x3000000C] = sub_6B24(MEMORY[0x3000000C], 0, 15, 0x7FFFu);
  return (_BYTE *)sub_7668();
}


/* ===== sub_81EC @ 0x81EC (file 0x31EC) size 236 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 sub_81EC()
{
  MEMORY[0x82000020] = 1;
  dword_DDC8 = 0;
  MEMORY[0x82000028] = 0;
  MEMORY[0x82000008] = 0x40000000;
  MEMORY[0x82000024] = 1073479680;
  MEMORY[0x300001B4] = 0x40000000;
  return 0;
}


/* ===== sub_82D8 @ 0x82D8 (file 0x32D8) size 1268 ===== */
__int64 sub_82D8()
{
  __int64 v0; // x1
  __int64 v1; // x2
  __int64 v2; // x3
  unsigned int v3; // w4
  __int64 *v4; // x23
  __int64 v5; // x22
  unsigned int v6; // w1
  int *v7; // x0
  unsigned int v8; // w2
  unsigned int v9; // w3
  unsigned __int8 *v10; // x20
  __int64 i; // x22
  unsigned int v12; // t1
  int *v13; // x0
  int v14; // w0
  __int64 v16; // [xsp+48h] [xbp+48h] BYREF

  sub_7074("DDR init start\r\n");
  MEMORY[0x402B0130] = 0;
  sub_78AC(0xA6u);
  MEMORY[0x402E000C] |= 0x10u;
  MEMORY[0x402E000C] &= ~0x10u;
  MEMORY[0x402B00D0] |= 0x70u;
  sub_6B48(1);
  MEMORY[0x402B00D0] &= 0xFFFFFFF0;
  sub_739C();
  if ( (unsigned int)sub_79B0(0xA6u, 3u) != 0 )
  {
    sub_7074("error:-3\r\n");
    while ( 1 )
      ;
  }
  if ( (unsigned int)sub_7BA8(8u) != 0 )
  {
    sub_7074("error:-4\r\n");
    while ( 1 )
      ;
  }
  if ( (unsigned int)sub_950C() != 0 )
  {
    sub_7074("error:-3\r\n");
    while ( 1 )
      ;
  }
  sub_78AC(0x29Bu);
  MEMORY[0x402E000C] |= 0x10u;
  MEMORY[0x402E000C] &= ~0x10u;
  MEMORY[0x402B00D0] |= 0x70u;
  sub_6B48(1);
  MEMORY[0x402B00D0] &= 0xFFFFFFF0;
  sub_739C();
  if ( (unsigned int)sub_7A68(667) != 0 )
  {
    sub_7074("error:-3\r\n");
    while ( 1 )
      ;
  }
  sub_5C18();
  if ( (unsigned int)sub_7BA8(8u) != 0 )
  {
    sub_7074("error:-4\r\n");
    while ( 1 )
      ;
  }
  if ( (unsigned int)sub_95DC(667) != 0 )
  {
    sub_7074("error:-5\r\n");
    while ( 1 )
      ;
  }
  sub_7D44(667, v0, v1, v2, v3);
  if ( (unsigned int)sub_7694(&v16) != -1 && v16 == 805306368 )
    sub_70FC(34603536, 34603536);
  v4 = qword_D7F8;
  v5 = 805306400;
  do
  {
    v6 = *(unsigned __int8 *)v4;
    v7 = (int *)v5;
    v8 = *((unsigned __int8 *)v4 + 1);
    v5 += 8;
    v9 = *((unsigned __int8 *)v4 + 2);
    v4 = (__int64 *)((char *)v4 + 6);
    sub_7C74(v7, v6, v8, v9);
  }
  while ( v5 != 805306464 );
  v10 = (unsigned __int8 *)qword_D7F8 + 3;
  for ( i = 805306404; i != 805306468; i += 8 )
  {
    v12 = *v10;
    v10 += 6;
    v13 = (int *)i;
    sub_7CDC(v13, v12, 0, 0);
  }
  v14 = sub_6B24(MEMORY[0x30000000], 16, 11, 0x190u);
  MEMORY[0x30000000] = sub_6B24(v14, 27, 1, 0);
  MEMORY[0x30000128] = -1073729536;
  MEMORY[0x300E32EC] = -859846315;
  MEMORY[0x20E000B0] = 1431655782;
  MEMORY[0x20E000B8] = 1431655765;
  MEMORY[0x20E000BC] = -11180321;
  if ( (unsigned int)sub_6A78(667) != 0 )
  {
    sub_7074("error:-6\r\n");
    while ( 1 )
      ;
  }
  MEMORY[0x402B0250] |= 1u;
  sub_81EC();
  MEMORY[0x402B0230] |= 0x400u;
  MEMORY[0x402B00CC] = sub_6B24(MEMORY[0x402B00CC], 29, 2, 0);
  MEMORY[0x300E3348] = sub_6B24(MEMORY[0x300E3348], 0, 30, 0x536u);
  sub_7074("DDR init OK\r\n");
  return 0;
}


/* ===== sub_87CC @ 0x87CC (file 0x37CC) size 564 ===== */
__int64 __fastcall sub_87CC(unsigned int a1, unsigned int *a2)
{
  unsigned int v2; // w25
  unsigned int v3; // w26
  unsigned int v4; // w21
  __int64 v5; // x19
  unsigned int v6; // w23
  unsigned __int64 v7; // x22
  unsigned int v8; // w24
  int v10; // w0
  int v11; // w0
  int v12; // w0
  int v13; // w0
  int v14; // w0
  int i; // w20
  unsigned int v17; // [xsp+50h] [xbp+50h] BYREF
  int v18; // [xsp+54h] [xbp+54h]
  int v19; // [xsp+58h] [xbp+58h]
  int v20; // [xsp+5Ch] [xbp+5Ch]

  v2 = a2[2];
  v3 = a2[1];
  v4 = *a2;
  if ( a1 != 0 )
  {
    LODWORD(v5) = -3;
    if ( a1 > 3 )
      return (unsigned int)v5;
    v6 = 0;
  }
  else
  {
    v6 = a2[3];
  }
  v7 = ((unsigned __int64)MEMORY[0x30000000] >> 4) & 7;
  if ( (unsigned int)v7 > 4 )
    goto LABEL_9;
  v8 = 1 << v7;
  if ( v4 > 2 )
    goto LABEL_9;
  if ( v3 % (((unsigned int)sub_7688() * v8) >> 3) != 0 )
  {
    sub_7074("Data len must aligned with burstlen*datawidth/8\n");
LABEL_9:
    LODWORD(v5) = -3;
    return (unsigned int)v5;
  }
  if ( (unsigned int)sub_77B0(v3, &v17) != 0 )
    goto LABEL_9;
  MEMORY[0x30000198] = v6;
  MEMORY[0x30000184] = v2 >> 2;
  MEMORY[0x30000188] = v20 & 0xFFF | (v19 << 16) | ((v17 & 1) << 15) | ((v18 & 7) << 12);
  v10 = sub_6B24(MEMORY[0x30000180], 13, 1, 1u);
  v11 = sub_6B24(v10, 0, 1, 1u);
  MEMORY[0x30000180] = sub_6B24(v11, 16, 10, v8);
  v12 = sub_6B24(MEMORY[0x30000180], 13, 1, 0);
  MEMORY[0x30000180] = sub_6B24(v12, 8, 2, a1);
  v13 = sub_6B24(MEMORY[0x30000180], 12, 2, 0);
  v14 = sub_6B24(v13, 4, 2, v4);
  MEMORY[0x30000180] = sub_6B24(v14, 0, 2, 3u);
  for ( i = 2 * MEMORY[0x30000184] - 2; i > 0 && (MEMORY[0x30000180] & 4) == 0; --i )
    ;
  MEMORY[0x30000180] = sub_6B24(MEMORY[0x30000180], 0, 1, 0);
  LODWORD(v5) = -2;
  if ( i > 0 )
    return (unsigned int)((MEMORY[0x30000180] ^ 8LL) << 60 >> 63);
  return (unsigned int)v5;
}


/* ===== sub_8A00 @ 0x8A00 (file 0x3A00) size 100 ===== */
__int64 __fastcall sub_8A00(unsigned int a1)
{
  int v1; // w4
  __int64 v2; // x3
  unsigned int v3; // w1
  char v4; // w1

  v1 = 28;
  v2 = 61458;
  MEMORY[0xF010] = 48;
  MEMORY[0xF011] = 120;
  do
  {
    v3 = (a1 >> v1) & 0xF;
    if ( v3 > 9 )
      v4 = v3 + 55;
    else
      v4 = v3 + 48;
    v1 -= 4;
    *(_BYTE *)v2++ = v4;
  }
  while ( v1 != -4 );
  MEMORY[0xF01A] = 32;
  return 61456;
}


/* ===== nullsub_1 @ 0x8A64 (file 0x3A64) size 4 ===== */
void nullsub_1()
{
  ;
}


/* ===== sub_8A68 @ 0x8A68 (file 0x3A68) size 56 ===== */
__int64 __fastcall sub_8A68(__int64 a1, int a2, int a3)
{
  __int64 v3; // x3
  unsigned int v4; // w4

  v3 = 0;
  while ( 1 )
  {
    v4 = v3;
    if ( (int)v3 >= a2 )
      break;
    ++v3;
    if ( a3 == *(_DWORD *)(a1 + 60 * v3 - 60) )
      return v4;
  }
  return 0xFFFFFFFFLL;
}


/* ===== sub_8AA0 @ 0x8AA0 (file 0x3AA0) size 224 ===== */
__int64 __fastcall sub_8AA0(int a1, int a2, int a3)
{
  __int64 *v4; // x20
  int v5; // w0
  _DWORD *v6; // x1
  _DWORD *v7; // x0

  if ( a1 == 257 )
    v4 = qword_DDF8;
  else
    v4 = qword_E038;
  v5 = sub_8A68((__int64)v4, 7, a2);
  v6 = (_DWORD *)(((__int64)a3 << 6) + 805306368);
  v7 = (_DWORD *)v4 + 15 * v5;
  *(_DWORD *)(((a3 + 8LL) << 6) + 0x30000000) = v7[1];
  v6[129] = v7[2];
  v6[130] = v7[3];
  v6[131] = v7[4];
  v6[132] = v7[5];
  v6[133] = v7[6];
  v6[134] = v7[7];
  v6[135] = v7[8];
  v6[136] = v7[9];
  v6[137] = v7[10];
  v6[138] = v7[11];
  v6[139] = v7[12];
  v6[140] = v7[13];
  v6[141] = v7[14];
  return 0;
}


/* ===== sub_8B80 @ 0x8B80 (file 0x3B80) size 264 ===== */
__int64 __fastcall sub_8B80(int a1, __int64 a2)
{
  __int64 *v3; // x19
  __int64 v4; // x20
  int v5; // w0
  __int64 v6; // x1
  _DWORD *v7; // x0
  __int64 v8; // x2
  _DWORD *v9; // x1

  if ( a1 == 257 )
    v3 = qword_DDF8;
  else
    v3 = qword_E038;
  v4 = 0;
  while ( 1 )
  {
    v5 = sub_8A68((__int64)v3, 7, *(_DWORD *)(a2 + 4 * v4));
    if ( v5 < 0 )
      break;
    v6 = (int)v4++;
    v7 = (_DWORD *)v3 + 15 * v5;
    v8 = (v6 + 8) << 6;
    v9 = (_DWORD *)((v6 << 6) + 805306368);
    *(_DWORD *)(v8 + 805306368) = v7[1];
    v9[129] = v7[2];
    v9[130] = v7[3];
    v9[131] = v7[4];
    v9[132] = v7[5];
    v9[133] = v7[6];
    v9[134] = v7[7];
    v9[135] = v7[8];
    v9[136] = v7[9];
    v9[137] = v7[10];
    v9[138] = v7[11];
    v9[139] = v7[12];
    v9[140] = v7[13];
    v9[141] = v7[14];
    if ( v4 == 4 )
      return 0;
  }
  return 0xFFFFFFFFLL;
}


/* ===== sub_8C88 @ 0x8C88 (file 0x3C88) size 344 ===== */
__int64 sub_8C88()
{
  MEMORY[0x30000308] = -2147483640;
  MEMORY[0x30000300] = -98384895;
  MEMORY[0x30000408] = -2147483640;
  MEMORY[0x3000040C] = -2147483640;
  MEMORY[0x30000410] = -2147483640;
  MEMORY[0x30000400] = -98384895;
  MEMORY[0x30000508] = -2147483640;
  MEMORY[0x3000050C] = -2147483640;
  MEMORY[0x30000510] = -2147483640;
  MEMORY[0x30000500] = -98384895;
  MEMORY[0x30000608] = -2147483640;
  MEMORY[0x3000060C] = -2147483640;
  MEMORY[0x30000610] = -2147483640;
  MEMORY[0x30000600] = -98384895;
  MEMORY[0x30000708] = -2147483640;
  MEMORY[0x3000070C] = -2147483640;
  MEMORY[0x30000710] = -2147483640;
  MEMORY[0x30000700] = -98384895;
  return 0;
}


/* ===== sub_8DE0 @ 0x8DE0 (file 0x3DE0) size 120 ===== */
__int64 sub_8DE0()
{
  int v0; // w0

  v0 = sub_6B24(MEMORY[0x3000010C], 12, 1, 0);
  MEMORY[0x3000010C] = sub_6B24(v0, 15, 1, 0);
  sub_6DB0(0, 0xAu, 0xFFu);
  sub_6B48(2);
  sub_6DB0(1, 0xAu, 0xFFu);
  sub_6B48(2);
  return 0;
}


/* ===== sub_8E58 @ 0x8E58 (file 0x3E58) size 104 ===== */
__int64 __fastcall sub_8E58(_DWORD *a1, _DWORD *a2, int a3)
{
  int i; // w3
  int v4; // w2
  int v5; // w1

  for ( i = 0; i < a3; ++i )
  {
    if ( a1[6] == *a2 && a1[4] == a2[1] && a1[1] == a2[2] )
    {
      v4 = a2[3];
      v5 = a2[4];
      a1[2] = v4;
      a1[3] = v5;
      return 0;
    }
    a2 += 5;
  }
  return 0xFFFFFFFFLL;
}


/* ===== sub_8EC0 @ 0x8EC0 (file 0x3EC0) size 292 ===== */
__int64 __fastcall sub_8EC0(unsigned __int8 a1, _DWORD *a2, _DWORD *a3, int a4)
{
  int v5; // w1
  int v6; // w1
  __int64 result; // x0
  int v8; // w0
  int v9; // w5
  int v10; // w0
  int v11; // w0
  int v12; // w0

  v5 = a1 >> 6;
  if ( v5 == 0 )
  {
    v6 = 32;
    goto LABEL_5;
  }
  if ( v5 == 1 )
  {
    v6 = 16;
LABEL_5:
    a2[4] = v6;
    if ( ((a1 >> 2) & 0xF) == 0xF )
      return 4294967292LL;
    switch ( (a1 >> 2) & 0xF )
    {
      case 0:
        v8 = 0x800000;
        goto LABEL_13;
      case 1:
        v8 = 0x1000000;
        goto LABEL_13;
      case 2:
        v8 = 0x2000000;
        goto LABEL_13;
      case 3:
        v8 = 0x4000000;
LABEL_13:
        a2[6] = v8;
        goto LABEL_18;
      case 4:
        v9 = a1 & 3;
        a2[6] = 0x8000000;
        if ( (a1 & 3) == 0 )
          goto LABEL_26;
        result = 4294967294LL;
        if ( v9 == 1 )
          goto LABEL_18;
        return result;
      case 5:
        v11 = a1 & 3;
        a2[6] = 0x10000000;
        if ( v11 == 0 )
          goto LABEL_26;
        if ( v11 == 1 )
        {
LABEL_18:
          v10 = 4;
LABEL_27:
          a2[1] = v10;
          if ( (unsigned int)sub_8E58(a2, a3, a4) != 0 )
            result = 4294967291LL;
          else
            result = 0;
        }
        else
        {
          result = 4294967293LL;
        }
        break;
      case 6:
        v12 = 0x20000000;
        goto LABEL_25;
      case 7:
        v12 = 0x40000000;
        goto LABEL_25;
      case 8:
      case 9:
      case 0xA:
      case 0xB:
      case 0xC:
      case 0xD:
        return 4294967292LL;
      case 0xE:
        v12 = 805306368;
LABEL_25:
        a2[6] = v12;
LABEL_26:
        v10 = 8;
        goto LABEL_27;
      default:
        abort();
    }
    return result;
  }
  result = 0xFFFFFFFFLL;
  if ( v5 == 2 )
    a2[4] = 8;
  return result;
}


/* ===== sub_8FE4 @ 0x8FE4 (file 0x3FE4) size 180 ===== */
__int64 __fastcall sub_8FE4(unsigned __int8 a1, _DWORD *a2, _DWORD *a3, int a4)
{
  unsigned __int64 v4; // x5
  int v6; // w1
  int v7; // w0
  __int64 result; // x0
  unsigned int v9; // w0

  v4 = a1;
  v6 = a1 >> 6;
  v7 = 32;
  if ( v6 != 0 )
  {
    result = 0xFFFFFFFFLL;
    if ( v6 != 1 )
      return result;
    v7 = 16;
  }
  a2[4] = v7;
  switch ( (v4 >> 2) & 0xF )
  {
    case 6uLL:
      v9 = 0x20000000;
      goto LABEL_10;
    case 7uLL:
      v9 = 0x40000000;
      goto LABEL_10;
    case 8uLL:
      v9 = 0x80000000;
      goto LABEL_10;
    case 0xDuLL:
      v9 = 1610612736;
      goto LABEL_10;
    case 0xEuLL:
      v9 = 805306368;
LABEL_10:
      a2[6] = v9;
      a2[1] = 8;
      if ( (unsigned int)sub_8E58(a2, a3, a4) != 0 )
        result = 4294967293LL;
      else
        result = 0;
      break;
    default:
      result = 4294967294LL;
      break;
  }
  return result;
}


/* ===== sub_9098 @ 0x9098 (file 0x4098) size 368 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_9098(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        char a9)
{
  signed int v9; // w19
  int v10; // w23
  int v11; // w22
  int v12; // w21
  unsigned int v13; // w4
  char *v14; // x0
  int v16; // w2
  _BYTE v17[8]; // [xsp+60h] [xbp+60h] BYREF
  _BYTE v18[8]; // [xsp+68h] [xbp+68h] BYREF

  v9 = 0;
  while ( 2 )
  {
    v10 = 8;
    v11 = 0;
    v12 = 0;
    while ( 1 )
    {
      sub_6C64(v9, 5u, &v17[v9], 10000, a5);
      sub_6C64(v9, 8u, &v18[v9], 10000, v13);
      v14 = &a9 + v9;
      if ( (v11 | v12) == 0 )
      {
        v12 = (unsigned __int8)*(v14 - 16);
        v11 = (unsigned __int8)*(v14 - 8);
        goto LABEL_9;
      }
      if ( v12 != (unsigned __int8)*(v14 - 16) )
      {
        *(v14 - 16) = -1;
        goto LABEL_10;
      }
      if ( v11 != (unsigned __int8)*(v14 - 8) )
        break;
LABEL_9:
      if ( --v10 == 0 )
        goto LABEL_10;
    }
    *(v14 - 8) = -1;
LABEL_10:
    if ( v9 == 0 )
    {
      v9 = 1;
      continue;
    }
    break;
  }
  if ( v18[0] >> 7 != 0 )
    return 0xFFFFFFFFLL;
  if ( v17[1] != v17[0] || v18[1] == v17[0] )
  {
    dword_DDC8 = 0;
    v16 = 1;
  }
  else
  {
    v16 = 2;
  }
  dword_DDD4 = v17[0];
  dword_DDD8 = v16;
  return 0;
}


/* ===== sub_9208 @ 0x9208 (file 0x4208) size 132 ===== */
__int64 __fastcall sub_9208(unsigned __int8 a1, int a2, _DWORD *a3, int a4)
{
  char *v4; // x1
  unsigned int v5; // w4
  int v6; // w0

  if ( a2 != 0 )
  {
    v5 = -1;
    if ( a2 != 1 )
      return v5;
    v4 = byte_DDB0;
  }
  else
  {
    v4 = byte_DD90;
  }
  v6 = sub_8FE4(a1, v4, a3, a4);
  if ( v6 != 0 )
    return (unsigned int)-3;
  else
    return 0;
}


/* ===== sub_928C @ 0x928C (file 0x428C) size 88 ===== */
__int64 __fastcall sub_928C(int a1)
{
  char *v2; // x1
  __int64 result; // x0

  if ( a1 != 0 )
  {
    result = 0xFFFFFFFFLL;
    if ( a1 != 1 )
      return result;
    v2 = byte_DDB0;
  }
  else
  {
    v2 = byte_DD90;
  }
  result = 0;
  if ( *((_DWORD *)v2 + 4) == 16 )
  {
    *((_DWORD *)v2 + 4) = 32;
    *((_DWORD *)v2 + 6) *= 2;
  }
  return result;
}


/* ===== sub_92E4 @ 0x92E4 (file 0x42E4) size 464 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_92E4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5)
{
  unsigned int v5; // w20
  _BYTE *v6; // x0
  _BYTE *v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  unsigned int v11; // w4
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x7
  char v16; // [xsp+0h] [xbp+0h]
  unsigned __int8 v17; // [xsp+5Fh] [xbp+5Fh] BYREF

  if ( (unsigned int)sub_6C64(0, 8u, &v17, 10000, a5) != 0 )
    return (unsigned int)-1;
  sub_7074("Swap later\r\n");
  sub_7074("CS0_MR8:");
  v6 = (_BYTE *)sub_8A00(v17);
  sub_7074(v6);
  v7 = sub_7074("\r\n");
  if ( (unsigned int)sub_9098((__int64)v7, v8, v9, v10, v11, v12, v13, v14, v16) != 0 )
    return (unsigned int)-1;
  v5 = sub_9208(v17, 0, qword_DC68, 14);
  if ( v5 != 0 )
  {
    return (unsigned int)-1;
  }
  else
  {
    sub_928C(0);
    dword_DDF0 = 0;
  }
  return v5;
}


/* ===== sub_94B4 @ 0x94B4 (file 0x44B4) size 88 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_94B4(char a1)
{
  int v1; // w1
  int v2; // w1
  int v3; // w1

  if ( (a1 & 0x20) != 0 )
  {
    if ( (a1 & 0x40) != 0 )
      v1 = 1;
    else
      v1 = 3;
    dword_DDDC = v1;
    v2 = 258;
  }
  else
  {
    if ( (a1 & 1) != 0 )
      v3 = 2;
    else
      v3 = 4;
    dword_DDDC = v3;
    v2 = 257;
  }
  dword_DDD0 = v2;
  return 0;
}


/* ===== sub_950C @ 0x950C (file 0x450C) size 208 ===== */
__int64 sub_950C()
{
  int v0; // w0
  unsigned int v1; // w1
  _BYTE *v2; // x0
  unsigned __int8 v4; // [xsp+2Fh] [xbp+2Fh] BYREF

  MEMORY[0x30000100] |= 0x4000u;
  sub_6B48(300);
  sub_6DB0(2, 0x3Fu, 0);
  sub_6B48(10);
  sub_8DE0();
  MEMORY[0x30000490] = sub_6B24(MEMORY[0x30000490], 24, 2, 1u);
  sub_6E78(3, 1);
  v0 = sub_6B8C(0, 8u, &v4, 10000);
  v1 = -1;
  if ( v0 == 0 )
  {
    sub_7074("Before swap\r\n");
    sub_7074("CS0_MR8:");
    v2 = (_BYTE *)sub_8A00(v4);
    sub_7074(v2);
    sub_7074("\r\n");
    if ( (unsigned int)sub_94B4(v4) != 0 )
      return (unsigned int)-1;
    else
      return 0;
  }
  return v1;
}


/* ===== sub_95DC @ 0x95DC (file 0x45DC) size 840 ===== */
// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_95DC(unsigned int a1)
{
  int v2; // w1
  int v3; // w1
  int v4; // w1
  unsigned int v5; // w19

  MEMORY[0x30000100] |= 0x4000u;
  sub_6B48(300);
  sub_6DB0(2, 0x3Fu, 0);
  sub_6B48(10);
  sub_8DE0();
  MEMORY[0x30000490] = sub_6B24(MEMORY[0x30000490], 24, 2, 1u);
  if ( a1 - 934 <= 0x84 )
  {
    v2 = 16;
LABEL_5:
    dword_E028 = v2;
    v3 = 8;
    goto LABEL_18;
  }
  if ( a1 > 0x320 )
  {
    v2 = 14;
    goto LABEL_5;
  }
  v4 = 12;
  if ( a1 > 0x2DD || (v4 = 11, a1 > 0x29B) )
  {
LABEL_10:
    dword_E028 = v4;
    v3 = 6;
    goto LABEL_18;
  }
  if ( a1 > 0x258 )
  {
    v4 = 10;
    goto LABEL_10;
  }
  if ( a1 <= 0x215 )
  {
    if ( a1 <= 0x190 )
    {
      if ( a1 <= 0xA6 )
      {
        dword_E028 = 3;
        v3 = 1;
      }
      else
      {
        dword_E028 = 6;
        v3 = 3;
      }
    }
    else
    {
      dword_E028 = 8;
      v3 = 4;
    }
  }
  else
  {
    dword_E028 = 9;
    v3 = 5;
  }
LABEL_18:
  dword_E02C = v3;
  if ( (unsigned int)sub_6E78(6, 3) != 0 )
    return (unsigned int)-1;
  sub_6DB0(2, 1u, 0x23u);
  sub_6B48(10);
  v5 = sub_7010(40);
  if ( v5 != 0 )
    return (unsigned int)-1;
  else
    sub_6B48(10);
  return v5;
}


/* ===== sub_9924 @ 0x9924 (file 0x4924) size 88 ===== */
__int64 __fastcall sub_9924(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x4
  __int64 v4; // x3
  __int64 i; // x3

  v3 = result;
  v4 = ((unsigned __int8)result | (unsigned __int8)a2) & 7;
  if ( (((unsigned __int8)result | (unsigned __int8)a2) & 7) == 0 )
  {
    while ( v4 != (a3 & 0xFFFFFFFFFFFFFFF8LL) )
    {
      *(_QWORD *)(result + v4) = *(_QWORD *)(a2 + v4);
      v4 += 8;
    }
    a3 &= 7u;
    v3 = result + v4;
    a2 += v4;
  }
  for ( i = 0; i != a3; ++i )
    *(_BYTE *)(v3 + i) = *(_BYTE *)(a2 + i);
  return result;
}


/* ===== sub_997C @ 0x997C (file 0x497C) size 40 ===== */
__int64 __fastcall sub_997C(__int64 a1, __int64 a2)
{
  __int64 v3; // x2
  int v4; // w3
  __int64 result; // x0

  v3 = 0;
  do
  {
    v4 = *(unsigned __int8 *)(a1 + v3);
    result = (unsigned int)(char)(v4 - *(_BYTE *)(a2 + v3));
    if ( (_BYTE)v4 != *(_BYTE *)(a2 + v3) )
      break;
    ++v3;
  }
  while ( v4 != 0 );
  return result;
}


/* ===== sub_99A4 @ 0x99A4 (file 0x49A4) size 96 ===== */
__int64 __fastcall sub_99A4(unsigned int a1)
{
  int v1; // w2

  v1 = 200000;
  MEMORY[0x40380028] = a1;
  while ( (MEMORY[0x4038002C] & 0x80000000) != 0 )
  {
    if ( --v1 == 0 )
      return 0xFFFFFFFFLL;
  }
  if ( (MEMORY[0xF030] & HIWORD(MEMORY[0x4038002C])) == (a1 & MEMORY[0xF030]) >> MEMORY[0xF038] )
    return MEMORY[0x4038002C];
  else
    return 0xFFFFFFFFLL;
}


/* ===== sub_9A04 @ 0x9A04 (file 0x4A04) size 104 ===== */
unsigned __int64 __fastcall sub_9A04(unsigned __int64 *a1, int a2)
{
  unsigned __int64 v2; // x2
  unsigned __int64 result; // x0

  v2 = *a1 + 8;
  if ( v2 > 0xF0B8 )
    v2 = 0xF040u;
  *a1 = v2;
  result = 0xF000u;
  if ( a2 == 1 )
    MEMORY[0xF034] = 0;
  else
    MEMORY[0xF034] = 16;
  return result;
}


/* ===== sub_9BA8 @ 0x9BA8 (file 0x4BA8) size 28 ===== */
__int64 __fastcall sub_9BA8(unsigned int a1)
{
  if ( a1 - 1077411840 > 0x9000 )
    return 0xFFFFFFFFLL;
  else
    return sub_99A4(a1);
}


/* ===== sub_9BC4 @ 0x9BC4 (file 0x4BC4) size 32 ===== */
__int64 __fastcall sub_9BC4(int a1, __int16 a2, int a3)
{
  int v4; // w19
  int v5; // w19

  if ( (unsigned int)(a1 - 1077411840) > 0x9000 )
    return 0xFFFFFFFFLL;
  MEMORY[0xF040] = a1;
  MEMORY[0xF044] = a2;
  sub_9A04((unsigned __int64 *)&off_E1E8, 0);
  while ( (MEMORY[0x40380030] & 0x800) == 0 )
  {
    if ( MEMORY[0xF034] == 0 )
    {
      if ( a3 == 0 )
        return 0;
      goto LABEL_11;
    }
    *(_DWORD *)MEMORY[0xF040] = MEMORY[0xF044];
    sub_9A04((unsigned __int64 *)&off_E1E0, 1);
  }
  if ( a3 == 0 && MEMORY[0xF034] != 16 )
    return 0;
LABEL_11:
  v4 = 1000;
  while ( (MEMORY[0x40380030] & 0x400) == 0 )
  {
    if ( --v4 == 0 )
      break;
    sub_9FCC(2);
  }
  while ( MEMORY[0xF034] != 0 )
  {
    while ( (MEMORY[0x40380030] & 0x800) != 0 )
      ;
    *(_DWORD *)MEMORY[0xF040] = MEMORY[0xF044];
    sub_9A04((unsigned __int64 *)&off_E1E0, 1);
  }
  v5 = 1000;
  while ( (MEMORY[0x40380030] & 0x400) == 0 )
  {
    if ( --v5 == 0 )
      break;
    sub_9FCC(2);
  }
  return 0;
}


/* ===== sub_9BE4 @ 0x9BE4 (file 0x4BE4) size 108 ===== */
__int64 __fastcall sub_9BE4(unsigned int a1, __int16 a2, __int16 a3)
{
  int v3; // w19
  int v4; // w19
  __int64 result; // x0

  if ( a1 - 1077411840 > 0x9000 )
    return 0xFFFFFFFFLL;
  result = sub_99A4(a1);
  if ( (result & 0x80000000) == 0 )
  {
    MEMORY[0xF040] = a1;
    MEMORY[0xF044] = result & ~a3 | a2;
    sub_9A04((unsigned __int64 *)&off_E1E8, 0);
    while ( (MEMORY[0x40380030] & 0x800) == 0 && MEMORY[0xF034] != 0 )
    {
      *(_DWORD *)MEMORY[0xF040] = MEMORY[0xF044];
      sub_9A04((unsigned __int64 *)&off_E1E0, 1);
    }
    v3 = 1000;
    while ( (MEMORY[0x40380030] & 0x400) == 0 )
    {
      if ( --v3 == 0 )
        break;
      sub_9FCC(2);
    }
    while ( MEMORY[0xF034] != 0 )
    {
      while ( (MEMORY[0x40380030] & 0x800) != 0 )
        ;
      *(_DWORD *)MEMORY[0xF040] = MEMORY[0xF044];
      sub_9A04((unsigned __int64 *)&off_E1E0, 1);
    }
    v4 = 1000;
    while ( (MEMORY[0x40380030] & 0x400) == 0 )
    {
      if ( --v4 == 0 )
        break;
      sub_9FCC(2);
    }
    return 0;
  }
  return result;
}


/* ===== sub_9C50 @ 0x9C50 (file 0x4C50) size 172 ===== */
__int64 sub_9C50()
{
  __int64 result; // x0

  MEMORY[0x402E0000] |= 0x10000u;
  MEMORY[0x402E0008] |= 0x20000u;
  sub_9FCC(2);
  MEMORY[0x402E0008] &= ~0x20000u;
  MEMORY[0x40380008] = 0;
  MEMORY[0x4038000C] = 0;
  MEMORY[0xF030] = 0xFFFF;
  MEMORY[0xF038] = 2;
  result = MEMORY[0x40380024] | 0x80000000;
  MEMORY[0x40380024] |= 0x80000000;
  return result;
}


/* ===== sub_9CFC @ 0x9CFC (file 0x4CFC) size 124 ===== */
char **__fastcall sub_9CFC(__int64 a1)
{
  __int64 v1; // x20

  v1 = 0;
  while ( (unsigned int)sub_997C((__int64)(&off_E1F0)[5 * v1], a1) != 0 )
  {
    if ( ++v1 == 8 )
      return nullptr;
  }
  if ( (_DWORD)v1 != 8 )
    return &(&off_E1F0)[5 * (int)v1];
  return nullptr;
}


/* ===== sub_9D78 @ 0x9D78 (file 0x4D78) size 192 ===== */
__int64 __fastcall sub_9D78(__int64 a1, int a2)
{
  int v2; // w21
  char **v3; // x0
  unsigned int v4; // w2
  char **v5; // x20
  int v6; // w0
  unsigned int v7; // w0
  unsigned int v8; // w19
  unsigned int v9; // w2
  __int16 v10; // w0

  v2 = 0;
  v3 = sub_9CFC(a1);
  v4 = *((_DWORD *)v3 + 8);
  v5 = v3;
  v6 = v4;
  do
  {
    if ( (v6 & 1) != 0 )
      break;
    ++v2;
    v6 >>= 1;
  }
  while ( v2 != 32 );
  v7 = *((_DWORD *)v5 + 7);
  v8 = (*((unsigned __int16 *)v5 + 12) + 1000 * (a2 - *((unsigned __int16 *)v5 + 10)) - 1)
     / *((unsigned __int16 *)v5 + 12);
  if ( (v8 & 0x80000000) != 0 || v7 == 0 )
    return 0xFFFFFFFFLL;
  v9 = v4 >> v2;
  if ( v8 > v9 )
    LOWORD(v8) = v9;
  v10 = sub_9BA8(v7);
  sub_9BC4(*((_DWORD *)v5 + 7), (_WORD)v5[4] & ((_WORD)v8 << v2) | v10 & ~*((_WORD *)v5 + 16), 1);
  return 0;
}


/* ===== sub_9E38 @ 0x9E38 (file 0x4E38) size 100 ===== */
__int64 sub_9E38()
{
  sub_9BC4(1077448316, 463, 1);
  sub_9BE4(0x40388CF4u, 1, 0);
  sub_9BE4(0x40388D00u, 1, 0);
  sub_9BC4(1077448444, 28287, 1);
  return 0;
}


/* ===== sub_9E9C @ 0x9E9C (file 0x4E9C) size 120 ===== */
__int64 __fastcall sub_9E9C(__int64 a1)
{
  char **v1; // x0
  unsigned int v2; // w1
  char **v3; // x19
  __int64 result; // x0
  int v5; // w0
  int v6; // w1
  int v7; // w2
  unsigned int v8; // w0

  v1 = sub_9CFC(a1);
  v2 = *((_DWORD *)v1 + 7);
  v3 = v1;
  result = 0xFFFFFFFFLL;
  if ( v2 != 0 )
  {
    v5 = sub_9BA8(v2);
    v6 = *((_DWORD *)v3 + 8);
    v7 = 0;
    v8 = v5 & v6;
    do
    {
      if ( (v6 & 1) != 0 )
        break;
      ++v7;
      v6 >>= 1;
    }
    while ( v7 != 32 );
    return (v8 >> v7) * *((_DWORD *)v3 + 6) / 0x3E8 + *((_DWORD *)v3 + 5);
  }
  return result;
}


/* ===== sub_9F14 @ 0x9F14 (file 0x4F14) size 184 ===== */
__int64 __fastcall sub_9F14(__int64 a1, int a2)
{
  int v4; // w0
  int v5; // w19

  v4 = (_WORD)sub_9CFC(a1)[1] & 0xF;
  if ( v4 == 2 )
  {
    v5 = sub_9E9C(a1);
    if ( v5 >= a2 )
    {
      do
      {
        v5 -= 25;
        if ( a2 >= v5 )
          v5 = a2;
        sub_9D78(a1, v5);
      }
      while ( v5 > a2 );
    }
    else
    {
      do
      {
        v5 += 25;
        if ( a2 <= v5 )
          v5 = a2;
        sub_9D78(a1, v5);
      }
      while ( v5 < a2 );
    }
  }
  else if ( v4 == 0 )
  {
    return sub_9D78(a1, a2);
  }
  return 0;
}


/* ===== sub_9FCC @ 0x9FCC (file 0x4FCC) size 84 ===== */
__int64 __fastcall sub_9FCC(int a1)
{
  __int64 result; // x0

  MEMORY[0x40050040] = 26 * a1;
  MEMORY[0x40050050] = 2;
  while ( MEMORY[0x40050058] != 0 )
    ;
  result = MEMORY[0x40050050] & 0xFFFFFFFD;
  MEMORY[0x40050050] &= ~2u;
  return result;
}


/* ===== sub_A020 @ 0xA020 (file 0x5020) size 76 ===== */
__int64 __fastcall sub_A020(int a1)
{
  __int64 result; // x0

  MEMORY[0x40050000] = 32 * a1;
  MEMORY[0x40050010] = 2;
  while ( MEMORY[0x40050018] != 0 )
    ;
  result = MEMORY[0x40050010] & 0xFFFFFFFD;
  MEMORY[0x40050010] &= ~2u;
  return result;
}


/* ===== sub_A06C @ 0xA06C (file 0x506C) size 60 ===== */
__int64 sub_A06C()
{
  __int64 result; // x0
  unsigned int i; // w1

  result = MEMORY[0x4023000C];
  for ( i = MEMORY[0x4023000C]; (_DWORD)result != i; i = MEMORY[0x4023000C] )
    result = i;
  return result;
}


/* ===== sub_A0A8 @ 0xA0A8 (file 0x50A8) size 76 ===== */
__int64 sub_A0A8()
{
  __int64 result; // x0

  MEMORY[0x402E0000] |= 0xE00u;
  MEMORY[0x402E0010] |= 0x1Cu;
  result = MEMORY[0x402E0134] | 0x800u;
  MEMORY[0x402E0134] |= 0x800u;
  return result;
}


/* ===== sub_A0F4 @ 0xA0F4 (file 0x50F4) size 96 ===== */
__int64 __fastcall sub_A0F4(__int64 result)
{
  unsigned __int64 StatusReg; // x6
  __int64 v2; // x3
  __int64 v3; // x4
  __int64 v4; // x6
  bool v9; // cc

  _WriteStatusReg(CSSELR_EL1, 2 * result);
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CCSIDR_EL1);
  v2 = (StatusReg >> 3) & 0x3FF;
  v3 = (StatusReg >> 13) & 0x7FFF;
  do
  {
    v4 = v2;
    do
    {
      __asm { DC              CISW, X9 }
      v9 = v4-- < 1;
    }
    while ( !v9 );
    v9 = v3-- < 1;
  }
  while ( !v9 );
  return result;
}


/* ===== sub_A154 @ 0xA154 (file 0x5154) size 92 ===== */
void sub_A154()
{
  unsigned __int64 StatusReg; // x10
  __int64 v1; // x11
  __int64 i; // x0

  __dsb(0xFu);
  StatusReg = _ReadStatusReg(CLIDR_EL1);
  v1 = (StatusReg >> 24) & 7;
  if ( v1 != 0 )
  {
    for ( i = 0; i < v1; ++i )
    {
      if ( ((StatusReg >> (3 * (unsigned __int8)i)) & 7) >= 2 )
        i = sub_A0F4(i);
    }
    _WriteStatusReg(CSSELR_EL1, 0);
    __dsb(0xFu);
    __isb(0xFu);
  }
}


/* ===== sub_A1B0 @ 0xA1B0 (file 0x51B0) size 52 ===== */
unsigned __int64 __fastcall sub_A1B0(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x2
  unsigned __int64 result; // x0

  v2 = 4LL << (((unsigned int)_ReadStatusReg(CTR_EL0) >> 16) & 0xF);
  result = a1 & ~(v2 - 1);
  do
  {
    __asm { DC              CIVAC, X0 }
    result += v2;
  }
  while ( result < a2 );
  __dsb(0xFu);
  return result;
}


/* ===== sub_A1E4 @ 0xA1E4 (file 0x51E4) size 12 ===== */
void sub_A1E4()
{
  __asm { IC              IALLUIS }
  __isb(0xFu);
}


/* ===== sub_A1F0 @ 0xA1F0 (file 0x51F0) size 76 ===== */
void sub_A1F0()
{
  unsigned __int64 StatusReg; // x9

  StatusReg = _ReadStatusReg(CurrentEL);
  switch ( StatusReg )
  {
    case 0xCuLL:
      goto LABEL_4;
    case 8uLL:
      __asm { TLBI            ALLE2 }
      __dsb(0xFu);
      __isb(0xFu);
      break;
    case 4uLL:
      __asm { TLBI            VMALLE1 }
      __dsb(0xFu);
      __isb(0xFu);
      break;
    default:
LABEL_4:
      __asm { TLBI            ALLE3 }
      __dsb(0xFu);
      __isb(0xFu);
      return;
  }
}


/* ===== sub_A23C @ 0xA23C (file 0x523C) size 244 ===== */
__int64 __fastcall sub_A23C(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, __int64 a5)
{
  unsigned __int64 v5; // x20
  unsigned __int64 v7; // x21
  unsigned __int64 v8; // x25
  unsigned int v9; // w24
  _QWORD v13[2]; // [xsp+0h] [xbp+0h] BYREF
  __int64 v14; // [xsp+50h] [xbp+50h]

  v5 = *(_QWORD *)(a1 + 24);
  v7 = a4 / v5;
  v8 = a4 % v5;
  if ( a5 != 0 )
  {
    v9 = sub_B50C();
    if ( v9 == 0
      && (v7 == 0
       || (*(__int64 (__fastcall **)(_QWORD, __int64, unsigned __int64, __int64))(a1 + 112))(
            *(unsigned int *)(a1 + 4),
            v14 + a3,
            v7,
            a5) != 0) )
    {
      if ( (_DWORD)v8 == 0 )
        return v9;
      if ( (*(__int64 (__fastcall **)(_QWORD, unsigned __int64, __int64, _QWORD *))(a1 + 112))(
             *(unsigned int *)(a1 + 4),
             v14 + a3 + v7,
             1,
             v13) == 1 )
      {
        sub_9924(a5 + v7 * *(_QWORD *)(a1 + 24), (__int64)v13, (unsigned int)v8);
        return v9;
      }
    }
  }
  return (unsigned int)-1;
}


/* ===== sub_A330 @ 0xA330 (file 0x5330) size 112 ===== */
__int64 __fastcall sub_A330(__int64 a1, unsigned int a2, __int64 a3)
{
  int v6; // w19
  __int64 v7; // x20
  __int64 result; // x0

  v6 = 5;
  v7 = sub_B508();
  if ( v7 == 0 )
    return 0xFFFFFFFFLL;
  while ( 1 )
  {
    result = sub_A23C(v7, a1, 0, a2, a3);
    if ( (_DWORD)result == 0 )
      break;
    if ( --v6 == 0 )
      return 0xFFFFFFFFLL;
  }
  return result;
}


/* ===== sub_A3A0 @ 0xA3A0 (file 0x53A0) size 188 ===== */
__int64 __fastcall sub_A3A0(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  int v8; // w20
  __int64 v9; // x19
  __int64 result; // x0
  unsigned int v11; // w20
  int v12; // w21

  v8 = 5;
  v9 = sub_B508();
  if ( v9 == 0 )
    return 0xFFFFFFFFLL;
  while ( (unsigned int)sub_A23C(v9, a1, 0, 0x200u, a4) != 0 )
  {
    if ( --v8 == 0 )
      return 0xFFFFFFFFLL;
  }
  result = 4294967294LL;
  v11 = *(_DWORD *)(a4 + 48) + 1024;
  if ( v11 <= a2 )
  {
    v12 = 5;
    while ( 1 )
    {
      result = sub_A23C(v9, a1, 0x200uLL / *(_QWORD *)(v9 + 24), v11, a3);
      if ( (_DWORD)result == 0 )
        break;
      if ( --v12 == 0 )
        return 4294967293LL;
    }
  }
  return result;
}


/* ===== sub_A45C @ 0xA45C (file 0x545C) size 420 ===== */
__int64 sub_A45C()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0

  v0 = sub_D1E0();
  v1 = sub_B210(v0);
  if ( (_DWORD)v1 == 1 )
  {
    sub_A330((__int64)"trustos", 0x400000u, 2483158528LL);
    sub_A330((__int64)"sml", 0x10000u, 2483027456LL);
    v1 = sub_A3A0((__int64)"uboot", 0x100000u, 2667577344LL, 2667576832LL);
  }
  nullsub_2(v1);
  if ( (unsigned int)sub_B738(20480, 2483027456LL, 0, 0, 1) != 0 )
  {
    sub_A330((__int64)"sml_bak", 0x10000u, 2483027456LL);
    if ( (unsigned int)sub_B738(20480, 2483027456LL, 0, 0, 1) != 0 )
    {
      while ( 1 )
        ;
    }
  }
  if ( (unsigned int)sub_B738(20480, 2483158528LL, 0, 0, 1) != 0 )
  {
    sub_A330((__int64)"trustos_bak", 0x400000u, 2483158528LL);
    if ( (unsigned int)sub_B738(20480, 2483158528LL, 0, 0, 1) != 0 )
    {
      while ( 1 )
        ;
    }
  }
  if ( (unsigned int)sub_B738(20480, 2667576832LL, 0, 0, 1) != 0 )
  {
    sub_A330((__int64)"uboot_bak", 0x8A000u, 2667576832LL);
    if ( (unsigned int)sub_B738(20480, 2667576832LL, 0, 0, 1) != 0 )
    {
      while ( 1 )
        ;
    }
  }
  v2 = sub_B73C();
  v3 = sub_D1C8(v2);
  v4 = nullsub_4(v3);
  v5 = sub_B4F8(v4);
  sub_D3D4(v5);
  sub_555C(260);
  MEMORY[0x94000000]();
  return sub_A600();
}


/* ===== sub_A600 @ 0xA600 (file 0x5600) size 224 ===== */
_DWORD *__fastcall sub_A600(_QWORD *a1, __int16 a2)
{
  _DWORD *result; // x0
  int v3; // [xsp+Ch] [xbp-4h]

  v3 = 0;
  if ( (a2 & 1) != 0 )
    v3 = 301924352;
  if ( (a2 & 2) != 0 )
    v3 |= 0x100u;
  if ( (a2 & 4) != 0 )
    v3 |= 0x40u;
  if ( (a2 & 8) != 0 )
    v3 |= 0x80u;
  if ( (a2 & 0x10) != 0 )
    v3 |= 0x20u;
  if ( (a2 & 0x20) != 0 )
    v3 |= 0x10u;
  if ( (a2 & 0x40) != 0 )
    v3 |= 8u;
  if ( (a2 & 0x80) != 0 )
    v3 |= 4u;
  if ( (a2 & 0x100) != 0 )
    v3 |= 2u;
  if ( (a2 & 0x200) != 0 )
    v3 |= 1u;
  result = (_DWORD *)*a1;
  result[14] &= ~v3;
  result[13] &= ~v3;
  result[12] = v3;
  return result;
}


/* ===== sub_A6E0 @ 0xA6E0 (file 0x56E0) size 364 ===== */
__int64 __fastcall sub_A6E0(__int64 *a1, __int16 a2)
{
  int v2; // w2
  __int64 result; // x0
  int v4; // [xsp+Ch] [xbp-4h]

  v4 = 0;
  if ( (a2 & 1) != 0 )
  {
    v2 = *((_DWORD *)a1 + 5);
    if ( (v2 & 1) != 0 )
      v4 = 0x10000000;
    if ( (v2 & 2) != 0 )
      v4 |= 0x1000000u;
    if ( (v2 & 4) != 0 )
      v4 |= 0x800000u;
    if ( (v2 & 8) != 0 )
      v4 |= 0x400000u;
    if ( (v2 & 0x10) != 0 )
      v4 |= 0x200000u;
    if ( (v2 & 0x20) != 0 )
      v4 |= 0x100000u;
    if ( (v2 & 0x40) != 0 )
      v4 |= 0x80000u;
    if ( (v2 & 0x80) != 0 )
      v4 |= 0x40000u;
    if ( (v2 & 0x100) != 0 )
      v4 |= 0x20000u;
    if ( (v2 & 0x200) != 0 )
      v4 |= 0x10000u;
  }
  if ( (a2 & 2) != 0 )
    v4 |= 0x100u;
  if ( (a2 & 4) != 0 )
    v4 |= 0x40u;
  if ( (a2 & 8) != 0 )
    v4 |= 0x80u;
  if ( (a2 & 0x10) != 0 )
    v4 |= 0x20u;
  if ( (a2 & 0x20) != 0 )
    v4 |= 0x10u;
  if ( (a2 & 0x40) != 0 )
    v4 |= 8u;
  if ( (a2 & 0x80) != 0 )
    v4 |= 4u;
  if ( (a2 & 0x100) != 0 )
    v4 |= 2u;
  if ( (a2 & 0x200) != 0 )
    v4 |= 1u;
  result = *a1;
  *(_DWORD *)(result + 52) |= v4;
  *(_DWORD *)(result + 56) |= v4;
  return result;
}


/* ===== sub_A84C @ 0xA84C (file 0x584C) size 248 ===== */
__int64 __fastcall sub_A84C(__int64 result, int a2)
{
  __int16 v2; // w19
  int v3; // w1
  int v4; // w1
  __int64 v5; // x1
  int v6; // [xsp+2Ch] [xbp+2Ch]

  v2 = result;
  if ( (result & 2) != 0 )
  {
    result = 0xF0C8u;
    MEMORY[0xF0E8] |= 2u;
  }
  if ( (v2 & 4) != 0 )
  {
    result = 0xF0C8u;
    v3 = MEMORY[0xF0E8] | 4;
LABEL_7:
    MEMORY[0xF0E8] = v3;
    goto LABEL_10;
  }
  if ( (v2 & 8) != 0 )
  {
    result = 0xF0C8u;
    v3 = MEMORY[0xF0E8] | 8;
    goto LABEL_7;
  }
  if ( (v2 & 1) != 0 )
  {
    result = 0xF0C8u;
    MEMORY[0xF0EC] |= a2;
    v4 = MEMORY[0xF0E8] | 0x3FF;
LABEL_16:
    MEMORY[0xF0E8] = v4;
    return result;
  }
LABEL_10:
  if ( (v2 & 0x100) != 0 )
  {
    result = 0xF0C8u;
    MEMORY[0xF0E8] |= 0x100u;
  }
  else if ( (v2 & 0x40) != 0 )
  {
    v5 = MEMORY[0xF0C8];
    v6 = *(_DWORD *)(MEMORY[0xF0C8] + 92LL);
    *(_DWORD *)(MEMORY[0xF0C8] + 88LL) = *(_DWORD *)(MEMORY[0xF0C8] + 88LL);
    *(_DWORD *)(v5 + 92) = v6;
    result = sub_A6E0((__int64 *)0xF0C8, 64);
  }
  if ( (v2 & 0x200) != 0 )
  {
    result = 0xF0C8u;
    v4 = MEMORY[0xF0E8] | 0x200;
    goto LABEL_16;
  }
  return result;
}


/* ===== sub_A944 @ 0xA944 (file 0x5944) size 156 ===== */
__int64 __fastcall sub_A944(_DWORD *a1, int a2)
{
  unsigned int v2; // w4
  unsigned int v3; // w1
  unsigned int v4; // w2
  unsigned int v5; // w1
  __int64 v6; // x5
  unsigned int v7; // w3
  unsigned int v9; // [xsp+Ch] [xbp-4h]

  v2 = a1[3];
  v3 = 2 * a2;
  v4 = 0;
  if ( v2 >= v3 )
  {
    v4 = v2 / v3;
    if ( v2 / (v2 / v3) > v3 )
      ++v4;
  }
  v5 = v4 >> 1;
  if ( (v4 & 1) != 0 )
    v5 = (v4 + 1) >> 1;
  v6 = *(_QWORD *)a1;
  v9 = ((unsigned __int8)v5 << 8) | (((v5 >> 8) & 3) << 6) | *(_DWORD *)(*(_QWORD *)a1 + 44LL) & 0xFFFF003F;
  v7 = v2 >> 1;
  if ( v5 != 0 )
    v7 = v2 / (2 * v5);
  a1[4] = v7;
  *(_DWORD *)(v6 + 44) = v9;
  return v7;
}


/* ===== sub_A9E0 @ 0xA9E0 (file 0x59E0) size 1356 ===== */
__int64 __fastcall sub_A9E0(__int64 *a1, unsigned int a2, int a3, __int64 a4, _BYTE *a5)
{
  __int64 v6; // x19
  __int64 v9; // x0
  __int64 *v10; // x1
  int v11; // w3
  int v12; // w25
  __int16 v13; // w1
  __int64 v14; // x20
  int v15; // w0
  __int64 *v16; // x0
  int v17; // w2
  int v18; // w1
  int v19; // w23
  int v20; // w0
  unsigned int v21; // w1
  int v22; // w0
  int v23; // w20
  unsigned int v24; // w20
  unsigned int v25; // w19
  _DWORD *v26; // x20
  __int64 result; // x0
  __int64 v28; // x1
  __int64 v29; // x3
  int v30; // w0
  int v31; // w2
  int v32; // w19
  unsigned int v33; // w0
  unsigned int v34; // w1
  unsigned int v35; // w0
  unsigned int v36; // w1
  int v37; // w0
  int v39; // [xsp+70h] [xbp+70h]
  unsigned int v40; // [xsp+74h] [xbp+74h]
  int v41; // [xsp+78h] [xbp+78h]
  int v42; // [xsp+7Ch] [xbp+7Ch]
  int v43; // [xsp+80h] [xbp+80h]
  int v44; // [xsp+84h] [xbp+84h]
  unsigned int v45; // [xsp+88h] [xbp+88h]
  unsigned int v46; // [xsp+8Ch] [xbp+8Ch]

  v6 = a2;
  *(_DWORD *)(*a1 + 44) |= 4u;
  sub_A600(a1, 1023);
  v9 = *a1;
  v39 = *(_DWORD *)(*a1 + 52);
  *(_DWORD *)(v9 + 52) &= ~0x100000u;
  *(_DWORD *)(v9 + 44) = *(_DWORD *)(v9 + 44) & 0xFFF0FFFF | 0xF0000;
  *(_DWORD *)(v9 + 52) = v39;
  v10 = &qword_D830[3 * (unsigned int)v6];
  v11 = *((_DWORD *)v10 + 4);
  v12 = *((_DWORD *)v10 + 2);
  *((_DWORD *)a1 + 5) = v11;
  v13 = v12 | 1;
  if ( v11 == 0 )
    v13 = v12;
  if ( a4 != 0 )
    v13 |= 0x40u;
  sub_A6E0(a1, v13);
  *((_DWORD *)a1 + 9) = 0;
  *((_DWORD *)a1 + 8) = 0;
  v14 = *a1;
  if ( a4 != 0 )
  {
    *(_QWORD *)(v14 + 88) = *(_QWORD *)a4;
    v15 = *(_DWORD *)(a4 + 12);
    *(_DWORD *)(v14 + 4) = *(_DWORD *)(a4 + 8);
    *(_DWORD *)v14 = v15;
  }
  *(_DWORD *)(v14 + 8) = a3;
  v16 = &qword_D830[3 * v6];
  v17 = *((_DWORD *)v16 + 1);
  v18 = *((_DWORD *)v16 + 5);
  v19 = *((_DWORD *)v16 + 3);
  v40 = *(_DWORD *)(v14 + 12) & 0xC004FF80;
  if ( (v18 & 1) != 0 )
    v40 |= 0x40u;
  if ( (v18 & 2) != 0 )
    v40 |= 0x20u;
  if ( (v18 & 4) != 0 )
    v40 |= 0x10u;
  if ( (v18 & 8) != 0 )
    v40 |= 4u;
  if ( (v18 & 0x10) != 0 )
    v40 |= 2u;
  if ( (v18 & 0x20) != 0 )
    v40 |= 1u;
  if ( (v18 & 0x40) != 0 )
    v40 |= 0x200000u;
  switch ( v19 )
  {
    case 0:
      v20 = v40;
      goto LABEL_28;
    case 1:
    case 5:
    case 6:
    case 7:
      v21 = v40;
      v22 = 1703936;
      goto LABEL_27;
    case 2:
      v21 = v40;
      v22 = 589824;
      goto LABEL_27;
    case 3:
    case 4:
      v20 = v40 | 0x20000;
      goto LABEL_28;
    case 8:
    case 9:
      v21 = v40;
      v22 = 1769472;
LABEL_27:
      v20 = v21 | v22;
LABEL_28:
      v40 = v20;
      break;
    default:
      break;
  }
  *(_DWORD *)(v14 + 12) = v40 | (v17 << 24);
  while ( v12 != ((_DWORD)a1[4] & v12) )
  {
    v41 = *(_DWORD *)(MEMORY[0xF0C8] + 48LL);
    v23 = (v41 & 0x8000) != 0;
    if ( (v41 & 0x100) != 0 )
      v23 |= 2u;
    if ( (*(_DWORD *)(MEMORY[0xF0C8] + 48LL) & 0x40) != 0 )
      v23 |= 4u;
    if ( (v41 & 0x80) != 0 )
      v23 |= 8u;
    if ( (v41 & 0x20) != 0 )
      v23 |= 0x10u;
    if ( (v41 & 0x10) != 0 )
      v23 |= 0x20u;
    if ( (v41 & 8) != 0 )
      v23 |= 0x40u;
    if ( (v41 & 4) != 0 )
      v23 |= 0x80u;
    if ( (v41 & 2) != 0 )
      v23 |= 0x100u;
    v24 = v23 | ((*(_DWORD *)(MEMORY[0xF0C8] + 48LL) & 1) << 9);
    v42 = *(_DWORD *)(MEMORY[0xF0C8] + 48LL);
    v25 = (v42 & 0x10000000) != 0;
    if ( (v42 & 0x1000000) != 0 )
      v25 |= 2u;
    if ( (v42 & 0x800000) != 0 )
      v25 |= 4u;
    if ( (*(_DWORD *)(MEMORY[0xF0C8] + 48LL) & 0x400000) != 0 )
      v25 |= 8u;
    if ( (*(_DWORD *)(MEMORY[0xF0C8] + 48LL) & 0x200000) != 0 )
      v25 |= 0x10u;
    if ( (*(_DWORD *)(MEMORY[0xF0C8] + 48LL) & 0x100000) != 0 )
      v25 |= 0x20u;
    if ( (*(_DWORD *)(MEMORY[0xF0C8] + 48LL) & 0x80000) != 0 )
      v25 |= 0x40u;
    if ( (*(_DWORD *)(MEMORY[0xF0C8] + 48LL) & 0x40000) != 0 )
      v25 |= 0x80u;
    if ( (*(_DWORD *)(MEMORY[0xF0C8] + 48LL) & 0x20000) != 0 )
      v25 |= 0x100u;
    if ( (*(_DWORD *)(MEMORY[0xF0C8] + 48LL) & 0x10000) != 0 )
      v25 |= 0x200u;
    sub_A600((_QWORD *)0xF0C8, v24);
    MEMORY[0xF0E0](v24, v25);
  }
  v26 = (_DWORD *)*a1;
  *(_DWORD *)(*a1 + 44) |= 0x6000000u;
  while ( (v26[11] & 0x6000000) != 0 )
    ;
  result = 255;
  if ( (a1[4] & 1) == 0 )
  {
    v28 = 0;
    v43 = v26[4];
    v44 = v26[5];
    v45 = v26[6];
    v46 = v26[7];
    do
    {
      v29 = (unsigned int)(4 * v28);
      v30 = 4 * v28;
      v31 = *(&v43 + v28++);
      a5[v29] = HIBYTE(v31);
      a5[(unsigned int)(v29 + 1)] = BYTE2(v31);
      a5[v30 + 2] = BYTE1(v31);
      a5[v30 + 3] = v31;
    }
    while ( v28 != 4 );
    v32 = v43;
    switch ( v19 )
    {
      case 1:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
        *a5 = HIBYTE(v43);
        a5[3] = v32;
        a5[1] = BYTE2(v32);
        a5[2] = BYTE1(v32);
        break;
      case 2:
        v33 = v46;
        a5[2] = v46;
        *a5 = BYTE2(v33);
        v34 = v33 >> 8;
        v35 = v45;
        a5[1] = v34;
        a5[3] = HIBYTE(v35);
        a5[6] = v35;
        a5[4] = BYTE2(v35);
        v36 = v35 >> 8;
        v37 = v44;
        a5[5] = v36;
        a5[7] = HIBYTE(v37);
        a5[10] = v37;
        a5[8] = BYTE2(v37);
        a5[11] = HIBYTE(v32);
        a5[9] = BYTE1(v37);
        a5[12] = BYTE2(v32);
        a5[14] = v32;
        a5[13] = BYTE1(v32);
        break;
      default:
        return 0;
    }
    return 0;
  }
  return result;
}


/* ===== sub_AF2C @ 0xAF2C (file 0x5F2C) size 112 ===== */
__int64 __fastcall sub_AF2C(__int64 *a1)
{
  int v2; // w19
  _BYTE v4[16]; // [xsp+30h] [xbp+30h] BYREF

  v2 = sub_A06C();
  while ( (unsigned int)sub_A9E0(a1, 8u, 0x10000, 0, v4) != 0 || (v4[2] & 1) == 0 )
  {
    if ( (unsigned int)sub_A06C() - v2 > 0xBB8 )
      return 0;
  }
  return 1;
}


/* ===== sub_AF9C @ 0xAF9C (file 0x5F9C) size 96 ===== */
__int64 __fastcall sub_AF9C(__int64 *a1, unsigned __int8 a2, unsigned __int8 a3)
{
  int v4; // w0
  unsigned int v5; // w1
  char v7; // [xsp+20h] [xbp+20h] BYREF

  v4 = sub_A9E0(a1, 0xBu, (a3 << 8) | 0x3000001 | (a2 << 16), 0, &v7);
  v5 = 0;
  if ( v4 == 0 )
    return (unsigned int)sub_AF2C(a1) != 0;
  return v5;
}


/* ===== sub_AFFC @ 0xAFFC (file 0x5FFC) size 408 ===== */
bool __fastcall sub_AFFC(int a1, int a2, int a3, __int64 a4)
{
  int v8; // w0
  BOOL v9; // w1
  __int64 v10; // x21
  unsigned int v11; // w0
  unsigned __int8 v12; // w2
  int v13; // w22
  __int64 v14; // x19
  _BYTE v16[16]; // [xsp+60h] [xbp+60h] BYREF
  __int64 v17; // [xsp+70h] [xbp+70h] BYREF
  int v18; // [xsp+78h] [xbp+78h]
  int v19; // [xsp+7Ch] [xbp+7Ch]
  _BYTE v20[16]; // [xsp+80h] [xbp+80h] BYREF

  if ( *(_DWORD *)(MEMORY[0xF0C0] + 52LL) == a1 )
    goto LABEL_13;
  v8 = sub_A9E0(MEMORY[0xF0C0], 8u, 0x10000, 0, v16);
  v9 = false;
  if ( v8 == 0 )
  {
    v10 = MEMORY[0xF0C0];
    v11 = *(_DWORD *)(MEMORY[0xF0C0] + 52LL);
    if ( v11 == a1 && v11 <= 7 )
      goto LABEL_13;
    if ( a1 == 1 )
    {
      v12 = 9;
    }
    else if ( a1 != 0 )
    {
      if ( a1 != 2 )
        return false;
      v12 = 10;
    }
    else
    {
      v12 = 8;
    }
    if ( (unsigned int)sub_AF9C(MEMORY[0xF0C0], 0xB3u, v12) != 0 )
    {
      *(_DWORD *)(v10 + 52) = a1;
LABEL_13:
      v13 = 5;
      while ( 1 )
      {
        v14 = MEMORY[0xF0C0];
        v19 = a3;
        v17 = a4;
        v18 = *(_DWORD *)(MEMORY[0xF0C0] + 48LL);
        if ( (unsigned int)sub_AF2C(MEMORY[0xF0C0]) == 0 || (unsigned int)sub_A9E0((__int64 *)v14, 9u, 512, 0, v20) != 0 )
          goto LABEL_18;
        *(_DWORD *)(v14 + 48) = 512;
        if ( (unsigned int)sub_A9E0((__int64 *)v14, 0xAu, a2, (__int64)&v17, v20) != 0 )
          break;
        v9 = sub_A9E0((__int64 *)v14, 7u, 0, 0, v20) == 0;
        if ( v9 )
          return true;
LABEL_20:
        if ( --v13 == 0 )
          return v9;
      }
      sub_A9E0((__int64 *)v14, 7u, 0, 0, v20);
LABEL_18:
      v9 = false;
      goto LABEL_20;
    }
    return false;
  }
  return v9;
}


/* ===== sub_B194 @ 0xB194 (file 0x6194) size 12 ===== */
__int64 sub_B194()
{
  return 61696;
}


/* ===== sub_B1A0 @ 0xB1A0 (file 0x61A0) size 56 ===== */
__int64 __fastcall sub_B1A0(unsigned int a1)
{
  int v2; // w0
  int v3; // w19
  __int64 result; // x0

  v2 = sub_A06C();
  v3 = v2;
  while ( 1 )
  {
    result = (unsigned int)(v2 - v3);
    if ( (unsigned int)result >= a1 )
      break;
    v2 = sub_A06C();
  }
  return result;
}


/* ===== sub_B1D8 @ 0xB1D8 (file 0x61D8) size 56 ===== */
__int64 __fastcall sub_B1D8(__int64 *a1, int a2)
{
  __int64 result; // x0
  bool v3; // zf
  int v4; // w1

  result = *a1;
  v3 = a2 == 1;
  v4 = *(_DWORD *)(result + 44);
  if ( v3 )
  {
    *(_DWORD *)(result + 44) = v4 | 4;
  }
  else if ( (v4 & 4) != 0 )
  {
    *(_DWORD *)(result + 44) &= ~4u;
    return sub_B1A0(1u);
  }
  return result;
}


/* ===== sub_B210 @ 0xB210 (file 0x6210) size 744 ===== */
__int64 sub_B210()
{
  __int64 v0; // x0
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x0
  unsigned int v4; // w1
  int v5; // w22
  int v6; // w0
  _BYTE v8[16]; // [xsp+30h] [xbp+30h] BYREF
  char v9; // [xsp+40h] [xbp+40h] BYREF

  MEMORY[0xF0C8] = 543162368;
  MEMORY[0x20E00000] |= 0x800u;
  sub_B1D8((__int64 *)0xF0C8, 0);
  MEMORY[0x20E00004] |= 0x4000u;
  sub_B1A0(1u);
  MEMORY[0x20E00004] &= ~0x4000u;
  MEMORY[0xF0D0] = 1;
  MEMORY[0xF0D4] = 384000000;
  MEMORY[0xF0DC] = 0;
  MEMORY[0xF0E0] = sub_A84C;
  MEMORY[0xF0C0] = 0xF0C8u;
  sub_B1D8((__int64 *)0xF0C8, 0);
  v0 = MEMORY[0xF0C8];
  *(_DWORD *)(MEMORY[0xF0C8] + 44LL) |= 0x1000000u;
  while ( (*(_DWORD *)(v0 + 44) & 0x1000000) != 0 )
    ;
  MEMORY[0x21500090] = 3;
  sub_A944((_DWORD *)0xF0C8, 400000);
  v1 = MEMORY[0xF0C8];
  *(_DWORD *)(MEMORY[0xF0C8] + 44LL) |= 1u;
  while ( (*(_DWORD *)(v1 + 44) & 2) == 0 )
    ;
  v2 = MEMORY[0xF0C0];
  *(_DWORD *)(v1 + 44) |= 4u;
  *(_WORD *)(v2 + 40) = 1;
  *(_DWORD *)(v2 + 52) = 8;
  v3 = *(_QWORD *)v2;
  *(_DWORD *)(v2 + 48) = 0;
  *(_DWORD *)(v2 + 44) = 0;
  *(_DWORD *)(v3 + 60) |= 0x20000000u;
  *(_DWORD *)(v3 + 40) &= 0xFFFFFFE7;
  if ( (unsigned int)sub_A9E0((__int64 *)v2, 0, 0, 0, v8) != 0 )
    goto LABEL_6;
  v5 = sub_A06C();
  while ( 1 )
  {
    while ( (unsigned int)sub_A9E0((__int64 *)v2, 1u, 1090486272, 0, v8) != 0 )
      ;
    if ( (v8[0] & 0x80000000) != 0 )
      break;
    if ( (unsigned int)sub_A06C() - v5 > 0x2710 )
      goto LABEL_6;
  }
  if ( (unsigned int)sub_A9E0((__int64 *)v2, 2u, 0, 0, v8) != 0
    || (unsigned int)sub_A9E0((__int64 *)v2, 3u, 0x10000, 0, v8) != 0
    || (unsigned int)sub_A9E0((__int64 *)v2, 5u, 0x10000, 0, v8) != 0
    || (unsigned int)sub_AF9C((__int64 *)v2, 0xB9u, 1u) == 0
    || (sub_B1D8((__int64 *)v2, 0),
        sub_A944((_DWORD *)v2, 48000000),
        *(_DWORD *)(*(_QWORD *)v2 + 44LL) |= 4u,
        (unsigned int)sub_AF9C((__int64 *)v2, 0xB7u, 2u) == 0) )
  {
LABEL_6:
    v4 = 0;
  }
  else
  {
    *(_DWORD *)(*(_QWORD *)v2 + 40LL) = *(_DWORD *)(*(_QWORD *)v2 + 40LL) & 0xFFFFFFDD | 0x20;
    *(_DWORD *)(v2 + 44) = 2;
    v6 = sub_A9E0((__int64 *)v2, 9u, 512, 0, &v9);
    v4 = 0;
    if ( v6 == 0 )
    {
      v4 = 1;
      *(_DWORD *)(v2 + 48) = 512;
    }
  }
  MEMORY[0xF108] = 5;
  MEMORY[0xF118] = 512;
  MEMORY[0xF104] = 0;
  MEMORY[0xF170] = sub_AFFC;
  return v4;
}


/* ===== sub_B4F8 @ 0xB4F8 (file 0x64F8) size 16 ===== */
__int64 sub_B4F8()
{
  return sub_B1D8(MEMORY[0xF0C0], 0);
}


/* ===== sub_B508 @ 0xB508 (file 0x6508) size 4 ===== */
// attributes: thunk
__int64 sub_B508(void)
{
  return sub_B194();
}


/* ===== sub_B50C @ 0xB50C (file 0x650C) size 48 ===== */
__int64 __fastcall sub_B50C(__int64 a1)
{
  if ( *(_BYTE *)(a1 + 8) != 5 )
    return 0xFFFFFFFFLL;
  if ( (unsigned int)sub_B600() != 0 )
    return 0xFFFFFFFFLL;
  return 0;
}


/* ===== sub_B53C @ 0xB53C (file 0x653C) size 80 ===== */
__int64 __fastcall sub_B53C(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  if ( a1 != 0
    && a2 != 0
    && (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(a1 + 112))(
         *(unsigned int *)(a1 + 4),
         *(_QWORD *)(a2 + 72) + a3,
         1) == 1 )
  {
    return a4;
  }
  else
  {
    return 0;
  }
}


/* ===== sub_B58C @ 0xB58C (file 0x658C) size 116 ===== */
bool __fastcall sub_B58C(__int64 a1, __int64 a2, _QWORD *a3)
{
  return a1 != 0
      && a3 != nullptr
      && (*(__int64 (__fastcall **)(_QWORD, __int64, __int64, _QWORD *))(a1 + 112))(
           *(unsigned int *)(a1 + 4),
           a2,
           1,
           a3) == 1
      && *a3 == 0x5452415020494645LL
      && a3[3] == a2;
}


/* ===== sub_B600 @ 0xB600 (file 0x6600) size 312 ===== */
__int64 __fastcall sub_B600(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 result; // x0
  int i; // w21
  unsigned int j; // w25
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 v11; // x1
  _QWORD v12[2]; // [xsp+0h] [xbp+0h] BYREF
  _QWORD *v13; // [xsp+50h] [xbp+50h]
  _BYTE v14[40]; // [xsp+58h] [xbp+58h] BYREF

  v13 = nullptr;
  if ( a3 != nullptr && a2 != 0 && sub_B58C(a1, 1, v12) )
  {
    for ( i = 0; i != 48; ++i )
    {
      if ( sub_B53C(a1, (__int64)v12, i, (__int64)v12) == 0 )
        break;
      for ( j = 0; *(_QWORD *)(a1 + 24) >> 7 > (unsigned __int64)j; ++j )
      {
        v9 = 0;
        v13 = &v12[16 * (unsigned __int64)(j & 0x1FFFFFF)];
        do
        {
          v14[v9] = *((_WORD *)&v12[16 * (unsigned __int64)(j & 0x1FFFFFF) + 7] + v9);
          ++v9;
        }
        while ( v9 != 36 );
        result = sub_997C((__int64)v14, a2);
        if ( (_DWORD)result == 0 )
        {
          v10 = v13[4];
          v11 = v13[5];
          *a3 = v10;
          a3[1] = v11 + 1 - v10;
          a3[2] = *(_QWORD *)(a1 + 24);
          return result;
        }
      }
    }
  }
  return 0xFFFFFFFFLL;
}


/* ===== sub_B738 @ 0xB738 (file 0x6738) size 4 ===== */
// attributes: thunk
__int64 __fastcall sub_B738(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  return sub_D15C(a1, a2, a3, a4, a5);
}


/* ===== sub_B73C @ 0xB73C (file 0x673C) size 4 ===== */
// attributes: thunk
__int64 sub_B73C(void)
{
  return sub_CDDC();
}


/* ===== nullsub_2 @ 0xB740 (file 0x6740) size 4 ===== */
void nullsub_2()
{
  ;
}


/* ===== sub_B744 @ 0xB744 (file 0x6744) size 20 ===== */
__int64 __fastcall sub_B744(__int64 a1)
{
  return sub_BC08(0, 3, a1, 0);
}


/* ===== sub_B758 @ 0xB758 (file 0x6758) size 500 ===== */
__int64 __fastcall sub_B758(unsigned int a1, _DWORD *a2)
{
  __int64 result; // x0
  int v5; // w1
  __int64 i; // x2
  int v7; // w0
  int v8; // w1
  __int64 j; // x2
  char *v10; // x0
  int v11; // w1
  __int64 k; // x2
  char *v13; // x0
  __int64 v14; // x0
  __int64 v15; // [xsp+30h] [xbp+30h] BYREF
  __int64 v16; // [xsp+38h] [xbp+38h]

  if ( a1 - 8 <= 7 )
    return 0;
  result = 3;
  if ( a1 > 0xFE )
    return result;
  if ( a1 - 34 <= 1 )
  {
    v15 = 0;
    v16 = 0;
    sub_B744((__int64)&v15);
    if ( (HIDWORD(v15) | (unsigned int)v15 | (unsigned int)v16 | HIDWORD(v16)) == 0 )
      *a2 = 0;
    v15 = 0;
    v16 = 0;
    sub_B744((__int64)&v15);
    LOBYTE(v5) = 1;
    for ( i = 0; i != 32; i += 4 )
    {
      v7 = *(_DWORD *)((char *)&qword_D590[2] + i);
      v5 = (((1 << ((2 * v7) & 0x1F)) & *((_DWORD *)&v15 + ((unsigned int)(2 * v7) >> 5))) != 0) & (unsigned __int8)v5;
    }
    if ( v5 != 0 )
      *a2 = 15;
    v15 = 0;
    v16 = 0;
    sub_B744((__int64)&v15);
    LOBYTE(v8) = 1;
    for ( j = 0; j != 32; j += 4 )
    {
      v10 = (char *)&qword_D590[2] + j;
      v8 = (((1 << ((2 * v10[64]) & 0x1F)) & *((_DWORD *)&v15 + ((unsigned int)(2 * *((_DWORD *)v10 + 16)) >> 5))) != 0)
         & (unsigned __int8)v8;
    }
    if ( v8 != 0 )
      *a2 |= 0xF00u;
    v15 = 0;
    v16 = 0;
    sub_B744((__int64)&v15);
    LOBYTE(v11) = 1;
    for ( k = 0; k != 32; k += 4 )
    {
      v13 = (char *)&qword_D590[2] + k;
      v11 = (((1 << ((2 * v13[100]) & 0x1F)) & *((_DWORD *)&v15 + ((unsigned int)(2 * *((_DWORD *)v13 + 25)) >> 5))) != 0)
          & (unsigned __int8)v11;
    }
    if ( v11 != 0 )
      *a2 |= 0xF0000u;
    return 0;
  }
  if ( a1 - 36 <= 6 )
    return 0;
  v14 = *((unsigned int *)&qword_D590[2] + a1);
  return sub_BC08(v14, (unsigned int)v14, a2, 1);
}


/* ===== sub_B94C @ 0xB94C (file 0x694C) size 128 ===== */
__int64 __fastcall sub_B94C(unsigned int a1, unsigned int a2)
{
  unsigned int v3; // w1
  bool v4; // cf
  __int64 result; // x0
  __int64 v6; // x0
  unsigned int v7; // [xsp+1Ch] [xbp+1Ch] BYREF

  v7 = a2;
  v3 = a1 - 34;
  v4 = a1 != 34;
  result = 0;
  if ( v3 != 1 && v4 )
  {
    result = 3;
    if ( a1 <= 0xFE )
    {
      result = 0;
      if ( a1 - 36 > 6 )
      {
        v6 = *((unsigned int *)&qword_D590[2] + a1);
        if ( a1 == 24 || a1 == 33 )
          return sub_BD28(v6, v7);
        else
          return sub_BA0C(v6, (unsigned int)v6, &v7, 1);
      }
    }
  }
  return result;
}


/* ===== sub_B9CC @ 0xB9CC (file 0x69CC) size 32 ===== */
__int64 sub_B9CC()
{
  __int64 result; // x0

  result = MEMORY[0x32050018] | 1u;
  MEMORY[0x32050018] |= 1u;
  return result;
}


/* ===== sub_B9EC @ 0xB9EC (file 0x69EC) size 32 ===== */
__int64 sub_B9EC()
{
  __int64 result; // x0

  result = MEMORY[0x32050018] & 0xFFFFFFFE;
  MEMORY[0x32050018] &= ~1u;
  return result;
}


/* ===== sub_BA0C @ 0xBA0C (file 0x6A0C) size 508 ===== */
__int64 __fastcall sub_BA0C(unsigned int a1, unsigned int a2, __int64 a3, int a4)
{
  unsigned int v5; // w0
  unsigned int i; // w3
  int v7; // w4
  unsigned int v8; // w0
  unsigned int v9; // w19

  sub_B9CC();
  MEMORY[0x4024004C] = 34832;
  MEMORY[0x40240048] = 0xFFFF;
  MEMORY[0x40240040] |= 0x10u;
  MEMORY[0x40240054] |= 4u;
  MEMORY[0x40240054] &= ~2u;
  sub_A020(1);
  MEMORY[0x40240054] |= 1u;
  sub_A020(1);
  MEMORY[0x40240040] |= 2u;
  if ( a4 != 0 )
    v5 = MEMORY[0x40240040] | 4;
  else
    v5 = MEMORY[0x40240040] & 0xFFFFFFFB;
  MEMORY[0x40240040] = v5;
  for ( i = a1; i <= a2; ++i )
  {
    v7 = *(_DWORD *)(a3 + 4LL * (i - a1));
    v8 = 4 * i + 1076105216;
    *(_DWORD *)v8 = v7;
  }
  if ( MEMORY[0x40240044] != 0 )
    v9 = 2;
  else
    v9 = 0;
  MEMORY[0x40240054] &= ~1u;
  sub_A020(1);
  MEMORY[0x40240054] |= 2u;
  sub_A020(1);
  MEMORY[0x40240054] &= ~4u;
  MEMORY[0x40240040] &= ~0x10u;
  MEMORY[0x4024004C] = 0;
  sub_B9EC();
  return v9;
}


/* ===== sub_BC08 @ 0xBC08 (file 0x6C08) size 288 ===== */
bool __fastcall sub_BC08(unsigned int a1, unsigned int a2, __int64 a3, int a4)
{
  unsigned int v4; // w3
  unsigned int i; // w4
  unsigned int v6; // w5
  unsigned int v7; // w3
  int v8; // w19

  sub_B9CC();
  MEMORY[0x4024004C] = 34832;
  MEMORY[0x40240048] = 0xFFFF;
  MEMORY[0x40240040] |= 1u;
  if ( a4 != 0 )
    v4 = MEMORY[0x40240040] | 4;
  else
    v4 = MEMORY[0x40240040] & 0xFFFFFFFB;
  MEMORY[0x40240040] = v4;
  for ( i = a1; ; ++i )
  {
    v6 = i - a1;
    if ( i > a2 )
      break;
    v7 = 4 * i + 1076105216;
    *(_DWORD *)(a3 + 4LL * v6) = *(_DWORD *)v7;
  }
  v8 = MEMORY[0x40240044];
  MEMORY[0x40240040] &= ~1u;
  MEMORY[0x4024004C] = 0;
  sub_B9EC();
  return v8 != 0;
}


/* ===== sub_BD28 @ 0xBD28 (file 0x6D28) size 392 ===== */
__int64 __fastcall sub_BD28(int a1, int a2)
{
  unsigned int v3; // w19

  sub_B9CC();
  MEMORY[0x4024004C] = 34832;
  MEMORY[0x40240048] = 0xFFFF;
  MEMORY[0x40240054] |= 4u;
  MEMORY[0x40240054] &= ~2u;
  sub_A020(1);
  MEMORY[0x40240054] |= 1u;
  sub_A020(1);
  MEMORY[0x40240040] &= ~2u;
  MEMORY[0x40240040] |= 4u;
  *(_DWORD *)(unsigned int)(4 * a1 + 1076105216) = a2;
  if ( MEMORY[0x40240044] != 0 )
    v3 = 2;
  else
    v3 = 0;
  MEMORY[0x40240054] &= ~1u;
  sub_A020(1);
  MEMORY[0x40240054] |= 2u;
  sub_A020(1);
  MEMORY[0x40240054] &= ~4u;
  MEMORY[0x4024004C] = 0;
  sub_B9EC();
  return v3;
}


/* ===== sub_BEB0 @ 0xBEB0 (file 0x6EB0) size 172 ===== */
__int64 __fastcall sub_BEB0(__int64 a1, signed int a2, _BYTE *a3, int a4, int a5)
{
  unsigned int v6; // w5
  unsigned __int8 *v7; // x1
  int v8; // w3
  int i; // w19
  int v10; // w2
  unsigned int v11; // w19

  v6 = -1;
  if ( a5 == a4 + 1 )
  {
    v7 = a3 + 1;
    if ( *a3 == 1 )
    {
      v8 = a4 - 1;
      for ( i = 0; i < v8; ++i )
      {
        v10 = *v7;
        if ( v10 != 255 )
        {
          v6 = -1;
          ++v7;
          if ( v10 != 0 )
            return v6;
          goto LABEL_10;
        }
        ++v7;
      }
      if ( i == v8 )
        return (unsigned int)-1;
LABEL_10:
      v6 = -1;
      if ( i > 7 )
      {
        v11 = v8 - (i + 1);
        if ( (int)v11 <= a2 )
        {
          sub_C184(a1, v7, v11);
          return v11;
        }
      }
    }
  }
  return v6;
}


/* ===== sub_BF5C @ 0xBF5C (file 0x6F5C) size 80 ===== */
__int64 __fastcall sub_BF5C(unsigned int a1, int a2)
{
  __int64 result; // x0
  int v5; // [xsp+2Ch] [xbp+2Ch] BYREF

  result = sub_B758(a1, &v5);
  if ( (_DWORD)result == 0 )
  {
    result = 0;
    if ( (a2 & ~v5) != 0 )
    {
      if ( (unsigned int)sub_B94C(a1, a2 & (unsigned int)~v5) != 0 )
        return 4294901762LL;
      else
        return 0;
    }
  }
  return result;
}


/* ===== sub_BFAC @ 0xBFAC (file 0x6FAC) size 124 ===== */
__int64 __fastcall sub_BFAC(unsigned int a1, int a2)
{
  unsigned int v4; // w1
  int v5; // w0
  int v7; // [xsp+28h] [xbp+28h] BYREF
  int v8; // [xsp+2Ch] [xbp+2Ch] BYREF

  v7 = 0;
  v8 = 0;
  if ( (unsigned int)sub_B758(a1, &v8) != 0 )
    return (unsigned int)-65533;
  v5 = sub_BF5C(a1, a2);
  v4 = -65534;
  if ( v5 != 0 )
    return v4;
  if ( (unsigned int)sub_B758(a1, &v7) != 0 )
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


/* ===== sub_C028 @ 0xC028 (file 0x7028) size 160 ===== */
__int64 __fastcall sub_C028(int a1, _DWORD *a2)
{
  __int64 result; // x0
  unsigned int v5; // w19
  int v6; // w20
  int v7; // w1
  int v8; // w3
  int v9; // [xsp+3Ch] [xbp+3Ch] BYREF

  result = 4294901761LL;
  if ( a2 != nullptr )
  {
    if ( a1 != 0 )
    {
      if ( a1 == 1 )
      {
        v5 = 36;
        v6 = 0;
        while ( 1 )
        {
          result = sub_B758(v5, &v9);
          if ( (_DWORD)result != 0 )
            break;
          v7 = v9;
          v8 = 0;
          while ( v7 != 0 )
          {
            ++v8;
            v7 &= v7 - 1;
          }
          ++v5;
          v6 += v8;
          if ( v5 == 43 )
          {
            *a2 = v6;
            return result;
          }
        }
      }
      else
      {
        return 4294901761LL;
      }
    }
    else
    {
      return sub_B758(0x18u, a2);
    }
  }
  return result;
}


/* ===== sub_C0C8 @ 0xC0C8 (file 0x70C8) size 156 ===== */
__int64 __fastcall sub_C0C8(int a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int v4; // w19
  unsigned int i; // w20
  int v6; // w1

  result = 4294901761LL;
  v4 = a2;
  if ( a2 != 0 )
  {
    if ( a1 != 0 )
    {
      if ( a1 == 1 && a2 <= 0xDF )
      {
        for ( i = 36; ; ++i )
        {
          v6 = v4 > 0x20 ? 32 : v4;
          v4 -= v6;
          result = sub_BFAC(i, 0xFFFFFFFFuLL >> (32 - (unsigned __int8)v6));
          if ( (_DWORD)result != 0 || i == 42 )
            break;
          if ( v4 == 0 )
            return 0;
        }
      }
    }
    else
    {
      return sub_BFAC(0x18u, a2);
    }
  }
  return result;
}


/* ===== sub_C164 @ 0xC164 (file 0x7164) size 32 ===== */
__int64 __fastcall sub_C164(__int64 result, char a2, int a3)
{
  __int64 i; // x3

  for ( i = 0; i != a3; ++i )
    *(_BYTE *)(result + i) = a2;
  return result;
}


/* ===== sub_C184 @ 0xC184 (file 0x7184) size 36 ===== */
__int64 __fastcall sub_C184(__int64 result, __int64 a2, int a3)
{
  __int64 i; // x3

  for ( i = 0; i != a3; ++i )
    *(_BYTE *)(result + i) = *(_BYTE *)(a2 + i);
  return result;
}


/* ===== sub_C1A8 @ 0xC1A8 (file 0x71A8) size 52 ===== */
__int64 __fastcall sub_C1A8(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x3
  int v5; // w0
  int v6; // w4
  __int64 result; // x0

  v4 = 0;
  while ( v4 != a3 )
  {
    v5 = *(unsigned __int8 *)(a1 + v4);
    v6 = *(unsigned __int8 *)(a2 + v4++);
    result = (unsigned int)(v5 - v6);
    if ( (_DWORD)result != 0 )
      return result;
  }
  return 0;
}


/* ===== sub_C1DC @ 0xC1DC (file 0x71DC) size 44 ===== */
_BYTE *__fastcall sub_C1DC(_BYTE *result)
{
  result[3] = 119;
  result[2] = 48;
  result[1] = 16;
  *result = 8;
  return result;
}


/* ===== sub_C208 @ 0xC208 (file 0x7208) size 64 ===== */
__int64 __fastcall sub_C208(unsigned __int16 a1, int a2, __int64 a3)
{
  __int64 v3; // x3
  __int64 result; // x0
  int v5; // w4

  v3 = MEMORY[0xF198];
  *(_DWORD *)(MEMORY[0xF198] + 1280LL) = a1 | 0x10000000 | ((a2 & 0x1F) << 16);
  for ( result = 0; result != a2; ++result )
  {
    v5 = *(_DWORD *)(a3 + 4 * result);
    *(_DWORD *)(v3 + 1280) = v5;
  }
  return result;
}


/* ===== sub_C248 @ 0xC248 (file 0x7248) size 76 ===== */
__int64 __fastcall sub_C248(_DWORD *a1)
{
  __int64 v1; // x2
  __int64 result; // x0

  v1 = MEMORY[0xF198];
  *(_DWORD *)(MEMORY[0xF198] + 1280LL) = ((*a1 & 0x7000000u) >> 4) | 0x20000000 | ((unsigned __int8)a1[5] << 8);
  *(_DWORD *)(v1 + 1280) = a1[1];
  *(_DWORD *)(v1 + 1280) = a1[2];
  *(_DWORD *)(v1 + 1280) = a1[3];
  result = (unsigned int)a1[4];
  *(_DWORD *)(v1 + 1280) = result;
  return result;
}


/* ===== sub_C294 @ 0xC294 (file 0x7294) size 64 ===== */
__int64 __fastcall sub_C294(unsigned __int16 a1, int a2, __int64 a3)
{
  __int64 v3; // x3
  __int64 result; // x0
  int v5; // w4

  v3 = MEMORY[0xF198];
  *(_DWORD *)(MEMORY[0xF198] + 1536LL) = a1 | 0x10000000 | ((a2 & 0x1F) << 16);
  for ( result = 0; result != a2; ++result )
  {
    v5 = *(_DWORD *)(a3 + 4 * result);
    *(_DWORD *)(v3 + 1536) = v5;
  }
  return result;
}


/* ===== sub_C2D4 @ 0xC2D4 (file 0x72D4) size 44 ===== */
__int64 __fastcall sub_C2D4(_DWORD *a1, int a2)
{
  __int64 v2; // x3
  __int64 result; // x0

  v2 = MEMORY[0xF198];
  *(_DWORD *)(MEMORY[0xF198] + 1536LL) = ((*a1 & 0x7000000u) >> 4) | 0x20000000;
  result = (unsigned int)a1[1];
  *(_DWORD *)(v2 + 1536) = result;
  *(_DWORD *)(v2 + 1536) = a2;
  return result;
}


/* ===== sub_C300 @ 0xC300 (file 0x7300) size 244 ===== */
__int64 __fastcall sub_C300(int *a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  char v4; // w1
  char v5; // w0
  int v6; // w1
  unsigned int v8; // [xsp+28h] [xbp+28h] BYREF
  unsigned int v9; // [xsp+2Ch] [xbp+2Ch]
  int v10; // [xsp+30h] [xbp+30h]
  int v11; // [xsp+34h] [xbp+34h]
  int v12; // [xsp+38h] [xbp+38h] BYREF
  __int16 v13; // [xsp+3Ch] [xbp+3Ch]
  _BYTE v14[4]; // [xsp+40h] [xbp+40h] BYREF
  int v15; // [xsp+44h] [xbp+44h]
  int v16; // [xsp+48h] [xbp+48h]
  char v17; // [xsp+4Ch] [xbp+4Ch]

  sub_C164((__int64)&v8, 0, 16);
  v2 = *((_QWORD *)a1 + 21);
  v10 = v2;
  HIBYTE(v8) = HIBYTE(v8) & 0xF0 | BYTE4(v2) & 0xF;
  v8 = v8 & 0xFF000000 | a1[44] & 0xFFFFFF;
  v3 = *((_QWORD *)a1 + 23);
  v11 = v3;
  HIBYTE(v9) = HIBYTE(v9) & 0xF0 | BYTE4(v3) & 0xF;
  v9 = v9 & 0xFF000000 | a1[48] & 0xFFFFFF;
  sub_C208(0x48u, 4, (__int64)&v8);
  sub_C164((__int64)&v12, 0, 24);
  v12 = *a1;
  sub_C1DC(v14);
  v17 = 0;
  v4 = a1[2];
  v15 = 0;
  v5 = v14[0] & 0xEF | (16 * (v4 & 1));
  v6 = *a1;
  v14[0] = v5 | 6;
  v16 = 0;
  v13 = v13 & 0xFE0F | (16 * (v6 & 0x1F)) | 1;
  return sub_C248(&v12);
}


/* ===== sub_C3F4 @ 0xC3F4 (file 0x73F4) size 768 ===== */
__int64 __fastcall sub_C3F4(int *a1)
{
  __int64 v2; // x2
  unsigned int v3; // w1
  unsigned int i; // w0
  unsigned int v5; // w5
  int v6; // w3
  __int64 v7; // x4
  __int64 v8; // x2
  unsigned int v9; // w1
  unsigned int j; // w0
  unsigned int v11; // w5
  int v12; // w3
  __int64 v13; // x4
  unsigned int v14; // w0
  __int64 v15; // x0
  int v16; // w2
  int v17; // w1
  int v18; // w2
  int v19; // w1
  int v20; // w2
  __int64 v21; // x0
  __int64 v22; // x0
  char v23; // w1
  int v24; // w2
  char v25; // w1
  char v26; // w0
  int v27; // w1
  _DWORD v29[4]; // [xsp+28h] [xbp+28h] BYREF
  unsigned int v30; // [xsp+38h] [xbp+38h] BYREF
  unsigned int v31; // [xsp+3Ch] [xbp+3Ch]
  int v32; // [xsp+40h] [xbp+40h]
  int v33; // [xsp+44h] [xbp+44h]
  int v34; // [xsp+48h] [xbp+48h] BYREF
  char v35; // [xsp+4Ch] [xbp+4Ch]
  char v36; // [xsp+4Dh] [xbp+4Dh]
  char v37; // [xsp+50h] [xbp+50h] BYREF
  char v38; // [xsp+51h] [xbp+51h]
  int v39; // [xsp+54h] [xbp+54h]
  int v40; // [xsp+58h] [xbp+58h]
  char v41; // [xsp+5Ch] [xbp+5Ch]
  _DWORD v42[8]; // [xsp+60h] [xbp+60h] BYREF

  v2 = *((_QWORD *)a1 + 3);
  v3 = a1[8];
  for ( i = 0; i < v3; i += 4 )
  {
    v5 = i >> 2;
    v6 = *(unsigned __int8 *)(v2 + i + 3)
       | (*(unsigned __int8 *)(v2 + i) << 24)
       | (*(unsigned __int8 *)(v2 + i + 1) << 16);
    v7 = i + 2;
    v42[v5] = v6 | (*(unsigned __int8 *)(v2 + v7) << 8);
  }
  sub_C208(0x80u, v3 >> 2, (__int64)v42);
  v8 = *((_QWORD *)a1 + 5);
  if ( v8 != 0 )
  {
    v9 = a1[12];
    if ( v9 != 0 )
    {
      for ( j = 0; j < v9; j += 4 )
      {
        v11 = j >> 2;
        v12 = *(unsigned __int8 *)(v8 + j + 3)
            | (*(unsigned __int8 *)(v8 + j) << 24)
            | (*(unsigned __int8 *)(v8 + j + 1) << 16);
        v13 = j + 2;
        v42[v11] = v12 | (*(unsigned __int8 *)(v8 + v13) << 8);
      }
      sub_C208(0xA0u, v9 >> 2, (__int64)v42);
    }
  }
  if ( a1[1] == 0 )
  {
    sub_C164((__int64)v29, 0, 16);
    v14 = *a1 - 1;
    if ( v14 <= 4 && ((1LL << v14) & 0x17) != 0 )
    {
      v15 = *((_QWORD *)a1 + 7);
      v16 = *(unsigned __int8 *)(v15 + 4);
      v29[0] = _byteswap_ulong(*(_DWORD *)v15);
      v17 = (*(unsigned __int8 *)(v15 + 5) << 16)
          | (v16 << 24)
          | *(unsigned __int8 *)(v15 + 7)
          | (*(unsigned __int8 *)(v15 + 6) << 8);
      v18 = *(unsigned __int8 *)(v15 + 8);
      v29[1] = v17;
      v19 = (*(unsigned __int8 *)(v15 + 9) << 16)
          | (v18 << 24)
          | *(unsigned __int8 *)(v15 + 11)
          | (*(unsigned __int8 *)(v15 + 10) << 8);
      v20 = *(unsigned __int8 *)(v15 + 12);
      v29[2] = v19;
      v29[3] = (*(unsigned __int8 *)(v15 + 13) << 16)
             | (v20 << 24)
             | *(unsigned __int8 *)(v15 + 15)
             | (*(unsigned __int8 *)(v15 + 14) << 8);
    }
    sub_C208(0x70u, 4, (__int64)v29);
  }
  sub_C164((__int64)&v30, 0, 16);
  v21 = *((_QWORD *)a1 + 21);
  v32 = v21;
  HIBYTE(v30) = HIBYTE(v30) & 0xF0 | BYTE4(v21) & 0xF;
  v30 = v30 & 0xFF000000 | a1[44] & 0xFFFFFF;
  v22 = *((_QWORD *)a1 + 23);
  v33 = v22;
  HIBYTE(v31) = HIBYTE(v31) & 0xF0 | BYTE4(v22) & 0xF;
  v31 = v31 & 0xFF000000 | a1[48] & 0xFFFFFF;
  sub_C208(0x48u, 4, (__int64)&v30);
  sub_C164((__int64)&v34, 0, 24);
  v34 = *a1;
  sub_C1DC(&v37);
  v23 = a1[2];
  v38 &= ~1u;
  v24 = a1[8];
  v37 = v37 & 0xEF | (16 * (v23 & 1)) | 6;
  if ( v24 == 24 )
  {
    v36 = v36 & 0x8F | 0x10;
  }
  else if ( v24 == 16 )
  {
    v36 &= 0x8Fu;
  }
  else
  {
    v36 = v36 & 0x8F | 0x20;
  }
  v25 = *a1;
  v41 = 0;
  v26 = v36 & 0xF8 | v25 & 7;
  v27 = a1[4];
  v36 = v26;
  v39 = 0;
  v40 = 0;
  v35 = v35 & 0xEF | (16 * (v27 & 1)) | 1;
  return sub_C248(&v34);
}


/* ===== sub_C6F4 @ 0xC6F4 (file 0x76F4) size 16 ===== */
__int64 sub_C6F4()
{
  return *(unsigned int *)(MEMORY[0xF198] + 1300LL);
}


/* ===== sub_C704 @ 0xC704 (file 0x7704) size 32 ===== */
__int64 sub_C704()
{
  while ( (*(_DWORD *)(MEMORY[0xF198] + 32LL) & 1) == 0 )
    ;
  *(_DWORD *)(MEMORY[0xF198] + 36LL) = *(_DWORD *)(MEMORY[0xF198] + 32LL);
  return 0;
}


/* ===== sub_C724 @ 0xC724 (file 0x7724) size 32 ===== */
__int64 sub_C724()
{
  while ( (*(_DWORD *)(MEMORY[0xF198] + 32LL) & 0x2000) == 0 )
    ;
  *(_DWORD *)(MEMORY[0xF198] + 36LL) = *(_DWORD *)(MEMORY[0xF198] + 32LL);
  return 0;
}


/* ===== sub_C744 @ 0xC744 (file 0x7744) size 476 ===== */
__int64 __fastcall sub_C744(__int64 a1)
{
  int *v2; // x21
  int v3; // t1
  int v5; // [xsp+3Ch] [xbp+3Ch] BYREF
  _BYTE v6[12]; // [xsp+40h] [xbp+40h] BYREF
  int v7; // [xsp+4Ch] [xbp+4Ch] BYREF
  int v8; // [xsp+50h] [xbp+50h] BYREF
  int v9; // [xsp+58h] [xbp+58h] BYREF
  char v10; // [xsp+5Ch] [xbp+5Ch]
  char v11; // [xsp+5Eh] [xbp+5Eh]
  char v12; // [xsp+5Fh] [xbp+5Fh]

  v2 = (int *)a1;
  v5 = *(_DWORD *)(a1 + 32);
  sub_C294(0xD0u, 1, (__int64)&v5);
  sub_C164((__int64)v6, 0, 20);
  v7 = (*(_QWORD *)(a1 + 184) >> 17) & 0x7FFFF;
  sub_C294(0x60Cu, 1, (__int64)&v7);
  sub_C164((__int64)&v9, 0, 24);
  v3 = *v2;
  v2 += 9;
  v9 = v3;
  v11 = -1;
  v10 |= 3u;
  v12 = (16 * (BYTE4(v2) & 0xF)) | 3;
  v8 = (*(_QWORD *)(a1 + 16) >> 17) & 0x7FFFF;
  sub_C294(0x610u, 1, (__int64)&v8);
  *(_DWORD *)(a1 + 36) = sub_CD50(0, 0, 1, *(_QWORD *)(a1 + 16) & 0x1FFFFLL);
  *(_DWORD *)(a1 + 40) = sub_CD48();
  sub_C2D4(&v9, (int)v2);
  sub_C724();
  v8 = (*(_QWORD *)(a1 + 24) >> 17) & 0x7FFFF;
  sub_C294(0x610u, 1, (__int64)&v8);
  *(_DWORD *)(a1 + 36) = sub_CD50(0, 2, 1, *(_QWORD *)(a1 + 24) & 0x1FFFFLL);
  *(_DWORD *)(a1 + 40) = sub_CD48();
  sub_C2D4(&v9, (int)v2);
  sub_C724();
  v8 = (*(_QWORD *)(a1 + 168) >> 17) & 0x7FFFF;
  sub_C294(0x610u, 1, (__int64)&v8);
  *(_DWORD *)(a1 + 36) = sub_CD50(0, 1, 1, *(_QWORD *)(a1 + 168) & 0x1FFFFLL);
  *(_DWORD *)(a1 + 40) = sub_CDA0(0, 3, 1, 2);
  *(_DWORD *)(a1 + 44) = sub_CD78(0, 3, 1, *(_QWORD *)(a1 + 184) & 0x1FFFFLL);
  *(_DWORD *)(a1 + 48) = sub_CD48();
  return sub_C2D4(&v9, (int)v2);
}


/* ===== sub_C920 @ 0xC920 (file 0x7920) size 52 ===== */
int *__fastcall sub_C920(int *a1)
{
  unsigned int v1; // w1

  v1 = *a1 & 0xFFFF0000;
  switch ( v1 )
  {
    case 0x2000000u:
      return (int *)sub_C300(a1);
    case 0x5010000u:
      return (int *)sub_C744((__int64)a1);
    case 0u:
      return (int *)sub_C3F4(a1);
    default:
      break;
  }
  return a1;
}


/* ===== sub_C954 @ 0xC954 (file 0x7954) size 24 ===== */
__int64 sub_C954()
{
  __int64 result; // x0

  result = MEMORY[0xF190] + 20480LL;
  *(_DWORD *)(MEMORY[0xF190] + 20536LL) = 1;
  return result;
}


/* ===== sub_C96C @ 0xC96C (file 0x796C) size 44 ===== */
__int64 sub_C96C()
{
  __int64 v0; // x0
  __int64 result; // x0

  v0 = MEMORY[0xF190] + 20480LL;
  *(_DWORD *)(MEMORY[0xF190] + 16444LL) = 1;
  *(_DWORD *)(v0 + 60) = 1;
  result = MEMORY[0xF198];
  *(_DWORD *)(MEMORY[0xF198] + 44LL) = 1;
  return result;
}


/* ===== sub_C998 @ 0xC998 (file 0x7998) size 100 ===== */
__int64 sub_C998()
{
  __int64 result; // x0

  if ( (MEMORY[0x21500058] & 3) != 3 )
    MEMORY[0x21500058] |= 3u;
  *(_DWORD *)(MEMORY[0xF190] + 16440LL) = 1;
  sub_C96C();
  sub_C6F4();
  result = MEMORY[0xF198];
  *(_DWORD *)(MEMORY[0xF198] + 36LL) = 32657;
  return result;
}


/* ===== sub_C9FC @ 0xC9FC (file 0x79FC) size 28 ===== */
unsigned __int64 sub_C9FC()
{
  MEMORY[0xF190] = 551550976;
  MEMORY[0xF198] = 568328192;
  return 0xF000u;
}


/* ===== nullsub_3 @ 0xCA18 (file 0x7A18) size 4 ===== */
void nullsub_3()
{
  ;
}


/* ===== sub_CA1C @ 0xCA1C (file 0x7A1C) size 512 ===== */
__int64 __fastcall sub_CA1C(
        int a1,
        __int64 a2,
        int a3,
        __int64 a4,
        int *a5,
        __int64 a6,
        int a7,
        __int64 a8,
        int a9,
        __int64 a10,
        int a11)
{
  __int64 result; // x0
  bool v14; // zf
  BOOL v15; // w0
  BOOL v16; // w2
  unsigned int v22; // w20
  int v23; // w0
  unsigned int v24; // w20
  int v26[4]; // [xsp+78h] [xbp+78h] BYREF
  __int64 v27; // [xsp+88h] [xbp+88h]
  __int64 v28; // [xsp+90h] [xbp+90h]
  int v29; // [xsp+98h] [xbp+98h]
  __int64 v30; // [xsp+A0h] [xbp+A0h]
  int v31; // [xsp+A8h] [xbp+A8h]
  __int64 v32; // [xsp+B0h] [xbp+B0h]
  int v33; // [xsp+B8h] [xbp+B8h]
  __int64 v34; // [xsp+120h] [xbp+120h]
  int v35; // [xsp+128h] [xbp+128h]
  __int64 v36; // [xsp+130h] [xbp+130h]
  int v37; // [xsp+138h] [xbp+138h]

  if ( a3 != 0 && a4 != 0 && a2 != 0 )
  {
    if ( a1 == 33554436 )
      goto LABEL_13;
    if ( a1 == 83951618 )
    {
      v14 = a7 == 256;
      v15 = a8 == 0 || a9 != 256;
    }
    else
    {
      result = 4294901761LL;
      if ( a1 != 1 )
        return result;
      v14 = a7 == 32;
      v15 = a10 == 0 || a11 != 16;
    }
    v16 = !v14;
    if ( !v16 && !v15 && a6 != 0 )
    {
LABEL_13:
      result = 4294901760LL;
      if ( MEMORY[0xF1A0] == 1 )
        return result;
      sub_C9FC();
      sub_C998();
      MEMORY[0xF1A0] = 1;
      sub_C164((__int64)v26, 0, 200);
      v26[0] = a1;
      v22 = a1 & 0xFFFF0000;
      v26[1] = 0;
      v26[2] = 1;
      v34 = a2;
      v35 = a3;
      v36 = a4;
      if ( (a1 & 0xFFFF0000) == 0x2000000 )
      {
        v37 = 32;
      }
      else
      {
        if ( v22 == 83951616 )
        {
          v27 = a6;
          v28 = a8;
          v29 = a7;
          goto LABEL_20;
        }
        if ( v22 == 0 )
        {
          v32 = a10;
          LODWORD(v27) = 1;
          v28 = a6;
          v29 = a7;
          v30 = 0;
          v31 = 0;
          v33 = a11;
LABEL_20:
          v37 = a3;
        }
      }
      sub_C920(v26);
      if ( v22 == 83951616 )
        v23 = sub_C724();
      else
        v23 = sub_C704();
      v24 = 0;
      if ( v23 != 0 )
        v24 = -65536;
      if ( a5 != nullptr )
        *a5 = v37;
      MEMORY[0xF1A0] = 0;
      sub_C954();
      nullsub_3();
      return v24;
    }
  }
  return 4294901767LL;
}


/* ===== sub_CC74 @ 0xCC74 (file 0x7C74) size 212 ===== */
__int64 __fastcall sub_CC74(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  signed int v5; // w20
  _BYTE v9[16]; // [xsp+20h] [xbp+0h] BYREF
  __int64 v10; // [xsp+60h] [xbp+40h]
  __int64 v11; // [xsp+68h] [xbp+48h]
  _BYTE v12[252]; // [xsp+70h] [xbp+50h] BYREF
  int v13; // [xsp+16Ch] [xbp+14Ch] BYREF

  v5 = a3 >> 3;
  v10 = a2;
  v11 = a4;
  sub_C164((__int64)v12, 0, 256);
  sub_C184((__int64)&v13, a1, 4);
  sub_CA1C(83951618, v11, 256, (__int64)v9, nullptr, v10, 256, (__int64)v12, 256, 0, 0);
  return sub_BEB0(a5, v5, &v9[1], v5 - 1, v5);
}


/* ===== sub_CD48 @ 0xCD48 (file 0x7D48) size 8 ===== */
__int64 sub_CD48()
{
  return 0xFFFFFFFFLL;
}


/* ===== sub_CD50 @ 0xCD50 (file 0x7D50) size 40 ===== */
__int64 __fastcall sub_CD50(char a1, char a2, char a3, int a4)
{
  return a4 & 0x1FFFF | 0xB0000000 | ((a2 & 0x1F) << 18) | ((a1 & 0xF) << 23) | ((a3 & 1) << 17);
}


/* ===== sub_CD78 @ 0xCD78 (file 0x7D78) size 40 ===== */
__int64 __fastcall sub_CD78(char a1, char a2, char a3, int a4)
{
  return a4 & 0x1FFFF | 0xB8000000 | ((a2 & 0x1F) << 18) | ((a1 & 0xF) << 23) | ((a3 & 1) << 17);
}


/* ===== sub_CDA0 @ 0xCDA0 (file 0x7DA0) size 40 ===== */
__int64 __fastcall sub_CDA0(char a1, char a2, char a3, char a4)
{
  return ((a4 & 0x1F) << 6)
       | 0x58000000
       | ((a3 & 0x1F) << 12)
       | ((a2 & 0x1F) << 18)
       | ((unsigned __int8)(a1 & 0xF) << 23);
}


/* ===== sub_CDC8 @ 0xCDC8 (file 0x7DC8) size 20 ===== */
__int64 __fastcall sub_CDC8(__int64 result, int a2, __int64 a3)
{
  if ( result != 0 && a3 != 0 )
    return sub_CA1C(33554436, result, a2, a3, nullptr, 0, 0, 0, 0, 0, 0);
  return result;
}


/* ===== sub_CDDC @ 0xCDDC (file 0x7DDC) size 124 ===== */
// write access to const memory has been detected, the output may be wrong!
void sub_CDDC()
{
  int v0; // w2
  int *v1; // x0
  int v2; // t1

  if ( MEMORY[0xF210] != 0 )
  {
    v0 = 1;
    v1 = (int *)0xF1E4;
    while ( v0 != MEMORY[0xF210] )
    {
      v2 = *v1++;
      if ( MEMORY[0xF1E0] != v2 )
        return;
      ++v0;
    }
    if ( MEMORY[0xF1E0] > 0x1234u )
      sub_C0C8(0, MEMORY[0xF1E0]);
    MEMORY[0xF210] = 0;
    dword_E33C = 0;
  }
}


/* ===== sub_CE58 @ 0xCE58 (file 0x7E58) size 216 ===== */
__int64 __fastcall sub_CE58(int a1, unsigned int a2)
{
  int v4; // w0

  if ( a1 != 1 )
  {
    if ( a1 == 0 )
      sub_C028(1, &dword_E338);
    return 0;
  }
  sub_C028(0, &dword_E33C);
  if ( a2 < 0x1234 )
    return 0;
  v4 = MEMORY[0xF210];
  *(_DWORD *)(0xF1E0 + 4LL * MEMORY[0xF210]) = a2;
  MEMORY[0xF210] = v4 + 1;
  return 1;
}


/* ===== sub_CF30 @ 0xCF30 (file 0x7F30) size 316 ===== */
__int64 __fastcall sub_CF30(__int64 a1, __int64 a2, int *a3)
{
  unsigned int v4; // w21
  __int64 v8; // x0
  int v9; // w0
  unsigned int v10; // w1
  int v11; // w0
  int v12; // w0
  _BYTE v13[32]; // [xsp+40h] [xbp+40h] BYREF
  _BYTE v14[256]; // [xsp+60h] [xbp+60h] BYREF

  v4 = *(unsigned __int8 *)a3;
  sub_C164((__int64)v14, 0, 256);
  if ( v4 > 1 )
    return 0;
  v8 = (__int64)(a3 + 1);
  if ( v4 != 1 )
  {
    sub_CDC8(v8, 264, (__int64)v13);
    v11 = sub_C1A8(a2, (__int64)(a3 + 67), 32);
    if ( v11 == 0 && (unsigned int)sub_C1A8(a1, (__int64)v13, 32) == 0 )
    {
      v12 = sub_CC74((__int64)(a3 + 2), (__int64)(a3 + 3), a3[1], (__int64)(a3 + 77), (__int64)v14);
      if ( (unsigned int)sub_C1A8((__int64)(a3 + 67), (__int64)v14, v12) == 0 )
      {
        v9 = a3[75];
        v10 = a3[76];
        return sub_CE58(v9, v10);
      }
    }
    return 0;
  }
  sub_CDC8(v8, 264, (__int64)v13);
  if ( (unsigned int)sub_C1A8(a2, (__int64)(a3 + 67), 32) != 0 )
    return 0;
  if ( (unsigned int)sub_C1A8(a1, (__int64)v13, 32) != 0 )
    return 0;
  sub_CC74((__int64)(a3 + 2), (__int64)(a3 + 3), a3[1], (__int64)(a3 + 85), (__int64)v14);
  if ( (unsigned int)sub_C1A8((__int64)(a3 + 67), (__int64)v14, 72) != 0 )
    return 0;
  v9 = a3[83];
  v10 = a3[84];
  return sub_CE58(v9, v10);
}


/* ===== sub_D06C @ 0xD06C (file 0x806C) size 16 ===== */
__int64 __fastcall sub_D06C(__int64 a1)
{
  return a1 + *(unsigned int *)(a1 + 48) + 512LL;
}


/* ===== sub_D07C @ 0xD07C (file 0x807C) size 40 ===== */
__int64 __fastcall sub_D07C(__int64 a1)
{
  return a1 + *(_QWORD *)(sub_D06C(a1) + 24);
}


/* ===== sub_D0A4 @ 0xD0A4 (file 0x80A4) size 40 ===== */
__int64 __fastcall sub_D0A4(__int64 a1)
{
  return a1 + *(_QWORD *)(sub_D06C(a1) + 40);
}


/* ===== sub_D0CC @ 0xD0CC (file 0x80CC) size 100 ===== */
__int64 __fastcall sub_D0CC(__int64 a1, __int64 a2)
{
  __int64 v4; // x22
  __int64 v5; // x0
  int *v6; // x0
  _BYTE v8[32]; // [xsp+30h] [xbp+30h] BYREF

  v4 = sub_D06C(a2);
  v5 = sub_D07C(a2);
  sub_CDC8(v5, *(_DWORD *)(v4 + 16), (__int64)v8);
  v6 = (int *)sub_D0A4(a2);
  return sub_CF30(a1, (__int64)v8, v6);
}


/* ===== sub_D130 @ 0xD130 (file 0x8130) size 44 ===== */
__int64 __fastcall sub_D130(__int64 a1, __int64 a2)
{
  __int64 v3; // x0

  v3 = sub_D0A4(a1);
  return sub_C184(a2, v3 + 300, 32);
}


/* ===== sub_D15C @ 0xD15C (file 0x815C) size 108 ===== */
bool __fastcall sub_D15C(__int64 a1, __int64 a2)
{
  _BYTE v5[16]; // [xsp+30h] [xbp+30h] BYREF
  _BYTE v6[32]; // [xsp+40h] [xbp+40h] BYREF

  sub_C164((__int64)v6, 0, 32);
  sub_D130(a1, (__int64)v6);
  sub_C164((__int64)v5, 0, 16);
  return (unsigned int)sub_D0CC((__int64)v6, a2) == 0;
}


/* ===== sub_D1C8 @ 0xD1C8 (file 0x81C8) size 20 ===== */
__int64 sub_D1C8()
{
  sub_C9FC();
  return sub_C954();
}


/* ===== nullsub_4 @ 0xD1DC (file 0x81DC) size 4 ===== */
void nullsub_4()
{
  ;
}


/* ===== sub_D1E0 @ 0xD1E0 (file 0x81E0) size 500 ===== */
__int64 sub_D1E0()
{
  unsigned int v0; // w2
  _DWORD *v1; // x0

  v0 = 0;
  MEMORY[0x32017024] &= 0xFFFFFF3F;
  MEMORY[0x32017024] |= 0x40u;
  MEMORY[0x32017030] &= 0xFFFFFF3F;
  MEMORY[0x32017030] |= 0x40u;
  MEMORY[0x32010044] &= 0xCFFFFFFF;
  MEMORY[0x32010044] |= 0x10000000u;
  MEMORY[0x30000000] |= 0x20000000u;
  MEMORY[0x3201B024] = -1;
  do
  {
    v1 = (_DWORD *)(4LL * v0 + 838971428);
    v1[2] = -1;
    ++v0;
    v1[6] = 0;
    v1[10] = -1;
    v1[14] = 0;
  }
  while ( v0 != 4 );
  MEMORY[0x3201B028] = 90111;
  MEMORY[0x3201B024] = 81920;
  MEMORY[0x32010024] = MEMORY[0x32010024] & 0xFFFFC003 | 0x1554;
  MEMORY[0x32010038] = MEMORY[0x32010038] & 0xFFFFC003 | 0x1554;
  MEMORY[0x32014038] = 1076757124;
  MEMORY[0x32014078] = 1024;
  MEMORY[0x32015030] = 1076559944;
  MEMORY[0x32015070] = 0x2000000;
  MEMORY[0x32015034] = 1076560048;
  MEMORY[0x32015074] = 2;
  MEMORY[0x32015038] = 1076560076;
  MEMORY[0x32015078] = 0x40000;
  return 838946936;
}


/* ===== sub_D3D4 @ 0xD3D4 (file 0x83D4) size 424 ===== */
__int64 sub_D3D4()
{
  unsigned int v0; // w3
  _DWORD *v1; // x0
  unsigned int v2; // w2
  _DWORD *v3; // x0

  v0 = 0;
  MEMORY[0x32018000] &= 0xFFFFFF3F;
  MEMORY[0x32018004] &= 0xFFFFFF3F;
  MEMORY[0x32018000] &= 0xFFFFFCFF;
  MEMORY[0x32018004] &= 0xFFFFFCFF;
  MEMORY[0x32018000] &= 0xFFFFCFFF;
  MEMORY[0x32018004] &= 0xFFFFCFFF;
  MEMORY[0x32018000] &= 0xFFFF3FFF;
  MEMORY[0x32018004] &= 0xFFFF3FFF;
  MEMORY[0x32011024] = -1;
  do
  {
    v1 = (_DWORD *)(4LL * v0 + 838930468);
    v1[2] = -1;
    ++v0;
    v1[6] = 0;
    v1[10] = -1;
    v1[14] = 0;
  }
  while ( v0 != 4 );
  MEMORY[0x32011028] = 511;
  v2 = 0;
  MEMORY[0x32011024] = 0;
  MEMORY[0x3201106C] = -1;
  do
  {
    v3 = (_DWORD *)(4LL * v2 + 838930540);
    v3[2] = -1;
    ++v2;
    v3[6] = 0;
    v3[10] = -1;
    v3[14] = 0;
  }
  while ( v2 != 4 );
  MEMORY[0x32011070] = 4095;
  MEMORY[0x3201106C] = 3776;
  MEMORY[0x32052000] = 1;
  return 839196672;
}


// END total=176 ok=176 fail=0
