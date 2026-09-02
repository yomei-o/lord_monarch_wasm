/* Ghidra decompilation of mem.bin - machine output, not the original source. */

/* 1000:0000  entry_1000_0000  391 bytes, 0 callers */

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */

void entry_1000_0000(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  code *pcVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  undefined2 unaff_CS;
  
  DAT_0000_3c1c = (undefined2)((ulong)uRam0000004c >> 0x10);
  DAT_0000_3c1a = (undefined2)uRam0000004c;
  puVar7 = (undefined1 *)0x1000;
  uRam00000000 = 0x73c;
  uRam00000024 = 0x7e0;
  uRam00000028 = 0x755;
  uRam0000004c = CONCAT22(unaff_CS,0x873);
  uRam00000054 = 0x8b6;
  DAT_0000_3e7e = (undefined2)((ulong)uRam0000006c >> 0x10);
  DAT_0000_3e7c = (undefined2)uRam0000006c;
  DAT_0000_0ffe = 0x5c;
  uRam00000002 = unaff_CS;
  uRam00000026 = unaff_CS;
  uRam0000002a = unaff_CS;
  uRam00000056 = unaff_CS;
  FUN_1000_0187();
  DAT_0000_0ffe = 0x5f;
  FUN_1000_01b9();
  DAT_0000_0ffe = 0x62;
  FUN_1000_024b();
  DAT_0000_32f3 = DAT_0000_0564;
  DAT_0000_32f5 = DAT_0000_056c;
  DAT_0000_3e80 = 0;
  out(0x68,0xb);
  bVar4 = in(2);
  out(2,bVar4 & 0xf9);
  out(0x6a,1);
  out(100,1);
  puVar8 = (undefined2 *)&DAT_0000_249b;
  puVar9 = (undefined2 *)&DAT_0000_3e20;
  for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {
    puVar2 = puVar9;
    puVar9 = puVar9 + 1;
    puVar1 = puVar8;
    puVar8 = puVar8 + 1;
    *puVar2 = *puVar1;
  }
  bVar4 = in(0x42);
  if ((bVar4 & 0x10) == 0) {
    DAT_0000_3286 = 1;
  }
  DAT_0000_d274 = 0;
  bVar4 = in(0x31);
  if ((bVar4 & 0x80) == 0) {
    DAT_0000_d274 = 0x4000;
  }
  DAT_0000_280d = DAT_0000_280d | DAT_0000_d274;
  DAT_0000_2811 = DAT_0000_2811 | DAT_0000_d274;
  DAT_0000_0ffe = 0xb4;
  FUN_1000_c6bc();
  DAT_0000_0ffe = 0xb8;
  FUN_1000_06e7();
  DAT_0000_0ffe = 0xbb;
  FUN_1000_7141();
  DAT_0000_c4e8 = DAT_0000_c4e6 * 8;
  puVar8 = (undefined2 *)&DAT_0000_cc00;
  for (iVar5 = 0x34; iVar5 != 0; iVar5 = iVar5 + -1) {
    puVar1 = puVar8;
    puVar8 = puVar8 + 1;
    *puVar1 = 0;
  }
  DAT_0000_0ffe = 0xda;
  FUN_1000_6c3f();
  DAT_0000_0ffe = 0xdd;
  DAT_0000_3474 = FUN_1000_69df();
  DAT_0000_347c = DAT_0000_3474 ^ 1;
  DAT_0000_0ffe = 0xf8;
  DAT_0000_3476 = DAT_0000_3474;
  DAT_0000_3478 = DAT_0000_3474;
  DAT_0000_347a = DAT_0000_3474;
  FUN_1000_072a();
  DAT_0000_0ffe = 0xfe;
  FUN_1000_072a();
  DAT_0000_3bc6 = 4;
  DAT_0000_0ffe = 0x107;
  FUN_1000_5f7e();
  DAT_0000_0ffe = 0x10a;
  FUN_1000_0ceb();
  DAT_0000_0ffe = 0x10d;
  FUN_1000_e365();
  DAT_0000_0ffe = 0x110;
  FUN_1000_5ca2();
  pcVar3 = (code *)swi(0x1c);
  (*pcVar3)();
  uVar6 = (uint)DAT_0000_3e75;
  do {
    *(undefined2 *)(puVar7 + -2) = 0x120;
    FUN_1000_9a36();
    uVar6 = uVar6 - 1;
  } while (uVar6 != 0);
  *(undefined2 *)(puVar7 + -2) = 0x125;
  FUN_1000_b729();
  *(undefined2 *)(puVar7 + -2) = 0x128;
  FUN_1000_02c3();
  *(undefined2 *)(puVar7 + -2) = 299;
  FUN_1000_bcf4();
  *(undefined2 *)(puVar7 + -2) = 0x12e;
  FUN_1000_026a();
  *(undefined2 *)(puVar7 + -2) = 0x131;
  FUN_1000_02e1();
  *(undefined2 *)(puVar7 + -2) = 0x134;
  FUN_1000_02f9();
  *(undefined2 *)(puVar7 + -2) = 0x137;
  FUN_1000_027c();
  DAT_0000_32bf = 0;
  *(undefined2 *)(puVar7 + -2) = 0x140;
  FUN_1000_0296();
  *(undefined2 *)(puVar7 + -2) = 0x143;
  FUN_1000_a6a5();
  *(undefined2 *)(puVar7 + -2) = 0x146;
  FUN_1000_c946();
  *(undefined2 *)(puVar7 + -2) = 0x149;
  FUN_1000_74c6();
  puVar8 = (undefined2 *)&DAT_0000_249b;
  puVar9 = (undefined2 *)&DAT_0000_3e20;
  for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {
    puVar2 = puVar9;
    puVar9 = puVar9 + 1;
    puVar1 = puVar8;
    puVar8 = puVar8 + 1;
    *puVar2 = *puVar1;
  }
  *(undefined2 *)(puVar7 + -2) = 0x157;
  FUN_1000_5cef();
  *(undefined2 *)(puVar7 + -2) = 0x15a;
  FUN_1000_5d0e();
  *(undefined2 *)(puVar7 + -2) = 0x15d;
  FUN_1000_96f2();
  *(undefined2 *)(puVar7 + -2) = 0x160;
  FUN_1000_977e();
  *(undefined2 *)(puVar7 + -2) = 0x163;
  FUN_1000_97a7();
  *(undefined2 *)(puVar7 + -2) = 0x166;
  FUN_1000_9355();
  *(undefined2 *)(puVar7 + -2) = 0x169;
  FUN_1000_727a();
  *(undefined2 *)(puVar7 + -2) = 0x16c;
  FUN_1000_5d0e();
  *(undefined2 *)(puVar7 + -2) = 0x16f;
  FUN_1000_9355();
  *(undefined2 *)(puVar7 + -2) = 0x172;
  FUN_1000_727a();
  *(undefined2 *)(puVar7 + -2) = 0x175;
  FUN_1000_4cdd();
  *(undefined2 *)(puVar7 + -2) = 0x178;
  FUN_1000_054b();
  DAT_0000_3bc6 = 5;
  *(undefined2 *)(puVar7 + -2) = 0x181;
  FUN_1000_5f7e();
  *(undefined2 *)(puVar7 + -2) = 0x184;
  FUN_1000_633b();
  FUN_1000_191c();
  return;
}



/* 1000:0187  FUN_1000_0187  50 bytes, 1 callers */

undefined1 __cdecl16near FUN_1000_0187(void)

{
  int iVar1;
  
  out(0x43,2);
  iVar1 = 4;
  do {
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  out(0x43,0x40);
  iVar1 = 4;
  do {
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  out(0x43,0x5e);
  iVar1 = 4;
  do {
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  out(0x43,0x3a);
  iVar1 = 0x60;
  do {
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  out(0x43,0x32);
  iVar1 = 0x40;
  do {
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  out(0x43,0x16);
  return 0x16;
}



/* 1000:01b9  FUN_1000_01b9  146 bytes, 1 callers */

byte __cdecl16near FUN_1000_01b9(void)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  undefined *puVar4;
  uint extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 *puVar5;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  bool bVar6;
  
  bVar6 = false;
  if ((*(byte *)0x538 & 1) == 0) {
    FUN_1000_73f8();
    if (!bVar6) {
      out(0x188,7);
      FUN_1000_73f8();
      if (!bVar6) {
        bVar6 = 0xfffd < extraout_DX;
        out(extraout_DX + 2,0xbf);
        FUN_1000_73f8();
        if ((!bVar6) && (cVar2 = in(extraout_DX_00), cVar2 == -0x41)) {
          *(undefined2 *)0x3b3a = 1;
          out(0x188,0xe);
          cVar2 = in(0x18a);
          puVar5 = (undefined2 *)0x50;
          if (-1 < cVar2) {
            pbVar1 = (byte *)0x3b3c;
            *pbVar1 = *pbVar1 << 1 | (char)*pbVar1 < '\0';
            puVar5 = (undefined2 *)0x54;
          }
          *puVar5 = 0xd52;
          puVar5[1] = unaff_CS;
          FUN_1000_14e8();
          FUN_1000_14c9();
          bVar3 = in(10);
          out(10,bVar3 & *(byte *)0x3b3c);
          return bVar3 & *(byte *)0x3b3c;
        }
      }
    }
  }
  *(undefined2 *)0x3b3a = 0;
  *(undefined2 *)0x20 = (undefined *)&DAT_0000_162b;
  *(undefined2 *)0x22 = unaff_CS;
  out(0x77,0x30);
  puVar4 = (undefined *)&DAT_0000_9fe8;
  if ((*(byte *)0x501 & 0x80) != 0) {
    puVar4 = (undefined *)&DAT_0000_81e8;
  }
  *(undefined2 *)0x3b4a = puVar4;
  out(0x71,(char)puVar4);
  out(0x71,(char)((uint)puVar4 >> 8));
  bVar3 = in(2);
  out(2,bVar3 & 0xfe);
  return bVar3 & 0xfe;
}



/* 1000:024b  FUN_1000_024b  31 bytes, 1 callers */

byte __cdecl16near FUN_1000_024b(void)

{
  byte bVar1;
  
  out(0x7fdf,0x93);
  out(0x7fdf,0x92);
  out(0x7fdd,0);
  out(0xbfdb,1);
  bVar1 = in(10);
  out(10,bVar1 & 0xdf);
  return bVar1 & 0xdf;
}



/* 1000:026a  FUN_1000_026a  18 bytes, 6 callers */

undefined2 __cdecl16near FUN_1000_026a(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 *puVar3;
  undefined2 unaff_ES;
  
  puVar3 = (undefined2 *)&DAT_0000_648c;
  for (iVar2 = 0x900; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0xffff;
  }
  return in_AX;
}



/* 1000:027c  FUN_1000_027c  26 bytes, 4 callers */

undefined2 __cdecl16near FUN_1000_027c(void)

{
  undefined2 in_AX;
  int iVar1;
  undefined *puVar2;
  undefined2 unaff_DS;
  
  puVar2 = (undefined *)&DAT_0000_c800;
  iVar1 = 0x40;
  do {
    *puVar2 = 0x80;
    puVar2[0xb] = 0xff;
    puVar2 = puVar2 + 0x10;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return in_AX;
}



/* 1000:0296  FUN_1000_0296  45 bytes, 4 callers */

undefined2 __cdecl16near FUN_1000_0296(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  byte *pbVar3;
  undefined2 *puVar4;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  puVar4 = (undefined2 *)&DAT_0000_e47e;
  for (iVar2 = 0x900; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = 0;
  }
  pbVar3 = (byte *)&DAT_0000_c800;
  iVar2 = 0x40;
  do {
    if ((*pbVar3 & 0x80) == 0) {
      *(byte **)((undefined *)&DAT_0000_e47e + *(int *)(pbVar3 + 4)) = pbVar3;
    }
    pbVar3 = pbVar3 + 0x10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return in_AX;
}



/* 1000:02c3  FUN_1000_02c3  30 bytes, 3 callers */

undefined2 __cdecl16near FUN_1000_02c3(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 *puVar3;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  puVar3 = (undefined2 *)&DAT_0000_d27e;
  for (iVar2 = 0x900; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = (undefined *)&DAT_0000_3030;
  }
  *(undefined1 *)0x3c08 = 0;
  *(undefined2 *)0x3bc2 = 0xffff;
  return in_AX;
}



/* 1000:02e1  FUN_1000_02e1  24 bytes, 4 callers */

undefined2 __cdecl16near FUN_1000_02e1(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 *puVar3;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  puVar3 = (undefined2 *)&DAT_0000_768e;
  for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0xffff;
  }
  *(undefined2 *)0x768c = 0;
  return in_AX;
}



/* 1000:02f9  FUN_1000_02f9  24 bytes, 4 callers */

undefined2 __cdecl16near FUN_1000_02f9(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)&DAT_0000_2400;
  for (iVar2 = 0x1000; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0;
  }
  return in_AX;
}



/* 1000:0311  FUN_1000_0311  372 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_0311(void)

{
  int *piVar1;
  byte bVar2;
  undefined2 in_AX;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined1 extraout_DL;
  undefined1 extraout_DL_00;
  char cVar6;
  undefined2 in_DX;
  char extraout_DH;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined1 *unaff_SI;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  bool bVar12;
  
  *(undefined2 *)&DAT_0000_32bf = 0;
  FUN_1000_027c();
  cVar6 = '\0';
  iVar4 = 4;
  puVar7 = (undefined2 *)0xc792;
  do {
    *puVar7 = 1;
    piVar9 = (int *)&DAT_0000_d27e;
    iVar5 = 0x900;
    bVar12 = (char)(cVar6 + '\x14') == '\0';
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      piVar1 = piVar9;
      piVar9 = piVar9 + 1;
      bVar12 = CONCAT11(100,cVar6 + '\x14') == *piVar1;
    } while (!bVar12);
    if (bVar12) {
      piVar10 = piVar9 + 0x16c0;
      puVar7[1] = CONCAT11((char)(((uint)piVar10 >> 1) / 0x30),(char)(((uint)piVar10 >> 1) % 0x30));
      puVar7[2] = piVar10;
      bVar12 = false;
      *puVar7 = 0;
      puVar7[7] = (undefined *)&DAT_0000_1388;
      puVar7[8] = 0;
      puVar7[6] = 200;
      *(undefined1 *)(puVar7 + 9) = 10;
      *(undefined1 *)((int)puVar7 + 0x13) = 0;
      *(undefined1 *)(puVar7 + 10) = 0x80;
      puVar8 = puVar7;
      uVar3 = FUN_1000_add0();
      if (!bVar12) {
        puVar8[3] = unaff_SI;
        *(undefined2 *)(unaff_SI + 2) = uVar3;
        *(int **)(unaff_SI + 4) = piVar10;
        *(undefined2 *)(unaff_SI + 8) = uVar3;
        *unaff_SI = 0;
        unaff_SI[1] = 6;
        piVar9[0x8ff] = (int)unaff_SI;
        unaff_SI[10] = 0x2d;
        unaff_SI[0xc] = extraout_DL;
        *(undefined2 *)(unaff_SI + 6) = 1000;
        uVar3 = FUN_1000_add0();
        if (!bVar12) {
          uVar3 = CONCAT11((char)((uint)uVar3 >> 8),(char)uVar3 + '\x01');
          *(undefined2 *)(unaff_SI + 2) = uVar3;
          *(int **)(unaff_SI + 4) = piVar9 + 0x16c1;
          *(undefined2 *)(unaff_SI + 8) = uVar3;
          *unaff_SI = 0;
          unaff_SI[1] = 6;
          piVar9[0x900] = (int)unaff_SI;
          unaff_SI[10] = 1;
          unaff_SI[0xc] = extraout_DL_00;
          *(undefined2 *)(unaff_SI + 6) = 200;
          FUN_1000_4881();
        }
      }
    }
    puVar7 = puVar7 + 0xb;
    cVar6 = cVar6 + '\x01';
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      uVar11 = 0;
      iVar4 = 0x900;
      bVar2 = 6;
      do {
        bVar12 = bVar2 < (byte)((undefined *)&DAT_0000_d27e)[uVar11];
        if (bVar2 == ((undefined *)&DAT_0000_d27e)[uVar11]) {
          *(undefined **)((undefined *)&DAT_0000_d27e + uVar11) = (undefined *)&DAT_0000_6400;
          bVar2 = FUN_1000_add0();
          if (!bVar12) {
            *(uint *)(unaff_SI + 2) =
                 CONCAT11((char)((uVar11 >> 1) / 0x30),(char)((uVar11 >> 1) % 0x30));
            *(uint *)(unaff_SI + 4) = uVar11;
            *unaff_SI = 0;
            unaff_SI[1] = 6;
            unaff_SI[10] = 0xf;
            *(undefined1 **)((undefined *)&DAT_0000_e47e + uVar11) = unaff_SI;
            unaff_SI[0xc] = 4;
            *(undefined2 *)(unaff_SI + 6) = 200;
            unaff_SI[0xb] = 0xff;
            bVar2 = 6;
          }
        }
        uVar11 = uVar11 + 2;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      *(undefined1 *)0xc7fc = 0;
      *(undefined1 *)0xc7fd = 0;
      *(undefined2 *)0xc7f8 = 0;
      *(undefined2 *)0xc7fa = 0;
      *(undefined1 *)0xc7fe = 0x80;
      iVar5 = 0;
      iVar4 = 0x900;
      do {
        if ((byte)(((undefined *)&DAT_0000_d27e)[iVar5] - 8) < 4) {
          FUN_1000_adeb();
          ((undefined *)&DAT_0000_d27f)[iVar5] = (extraout_DH + '\x01') * '\x10';
        }
        iVar5 = iVar5 + 2;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      iVar4 = 0xc80;
      uVar11 = *(uint *)0x3bc2;
      if (((uVar11 <= *(uint *)0xce70) && (uVar11 != 0)) &&
         (iVar4 = *(uint *)((undefined *)&DAT_0000_cc06 + (uVar11 - 1) * 0xc) + 0xc80,
         0xf37f < *(uint *)((undefined *)&DAT_0000_cc06 + (uVar11 - 1) * 0xc))) {
        iVar4 = -1;
      }
      *(int *)0x3bca = iVar4;
      *(undefined2 *)0x3bcc = 0;
      *(undefined2 *)0x3bec = 0;
      return CONCAT22(in_DX,in_AX);
    }
  } while( true );
}



/* 1000:04b8  FUN_1000_04b8  99 bytes, 3 callers */

undefined4 __cdecl16near FUN_1000_04b8(void)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int iVar3;
  undefined2 in_DX;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x3bd4 = 0;
  *(undefined2 *)0x3bd6 = 0;
  *(undefined2 *)0xc52c = 0;
  *(undefined2 *)&DAT_0000_32bf = 0;
  FUN_1000_bcf4();
  FUN_1000_026a();
  FUN_1000_02e1();
  FUN_1000_02f9();
  FUN_1000_0311();
  FUN_1000_0296();
  FUN_1000_a6a5();
  if (*(byte *)0x3c00 < 4) {
    FUN_1000_a62d();
    FUN_1000_a656();
  }
  FUN_1000_727a();
  FUN_1000_9355();
  FUN_1000_727a();
  FUN_1000_7c9e();
  puVar4 = (undefined1 *)0x3eea;
  puVar5 = (undefined2 *)&DAT_0000_3e20;
  for (iVar3 = 0x2d; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = (undefined2 *)((int)puVar5 + 1);
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *(undefined1 *)puVar2 = *puVar1;
  }
  *(byte *)0x3483 = *(byte *)0x3483 ^ 1;
  FUN_1000_727a();
  FUN_1000_9355();
  FUN_1000_727a();
  FUN_1000_7c9e();
  FUN_1000_72ad();
  return CONCAT22(in_DX,in_AX);
}



/* 1000:051b  FUN_1000_051b  48 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_051b(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x3bd4 = 0;
  *(undefined2 *)0x3bd6 = 0;
  *(undefined2 *)0xc52c = 0;
  *(undefined2 *)&DAT_0000_32bf = 0;
  *(undefined2 *)0x3bc2 = 0xffff;
  FUN_1000_02c3();
  FUN_1000_bcf4();
  FUN_1000_026a();
  FUN_1000_9355();
  FUN_1000_02e1();
  FUN_1000_02f9();
  FUN_1000_027c();
  FUN_1000_0296();
  FUN_1000_a6a5();
  return CONCAT22(in_DX,in_AX);
}



/* 1000:054b  FUN_1000_054b  412 bytes, 1 callers */

uint __cdecl16near FUN_1000_054b(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  bool bVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined1 *puVar11;
  byte *pbVar12;
  undefined1 *puVar13;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  int local_16;
  
  FUN_1000_6b12();
  bVar5 = (byte)*(undefined2 *)&DAT_0000_055c & *(byte *)0x488;
  uVar7 = CONCAT11((char)((uint)*(undefined2 *)&DAT_0000_055c >> 8),bVar5) & 0xff03;
  if ((bVar5 & 3) == 0) {
    return uVar7;
  }
  uVar10 = 0;
  uVar8 = uVar7;
  while( true ) {
    uVar14 = (byte)uVar8 & 1;
    uVar8 = (uint)(byte)((byte)uVar8 >> 1);
    if ((bool)uVar14) break;
    uVar10 = uVar10 + 1;
  }
  FUN_1000_6c3f();
  FUN_1000_69df();
  if (((bool)uVar14) || (FUN_1000_6d3a(), (bool)uVar14)) {
    FUN_1000_0ccc();
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    *(undefined2 *)0x1089 = 0x114;
    FUN_1000_49bb();
    FUN_1000_72ad();
    FUN_1000_c612();
    cVar6 = FUN_1000_4be9();
    uVar15 = 0;
    uVar14 = cVar6 == '\0';
    if (!(bool)uVar14) {
      return uVar7;
    }
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    FUN_1000_72ad();
    FUN_1000_6822();
    while( true ) {
      FUN_1000_6c3f();
      FUN_1000_69df();
      uVar16 = uVar14;
      if ((!(bool)uVar15) && (FUN_1000_6d3a(), uVar16 = uVar14, !(bool)uVar15)) break;
      FUN_1000_6cb5();
      uVar14 = 1;
      if (!(bool)uVar16) {
        return uVar7;
      }
    }
    while( true ) {
      while( true ) {
        puVar11 = (undefined1 *)*(undefined2 *)0x3e82;
        FUN_1000_6c3f();
        FUN_1000_69df();
        if (!(bool)uVar15) break;
        FUN_1000_6cb5();
        bVar4 = !(bool)uVar14;
        uVar14 = 1;
        if (bVar4) {
          return uVar7;
        }
      }
      puVar13 = (undefined1 *)*(undefined2 *)0x3e82;
      for (iVar9 = 0x20; iVar9 != 0; iVar9 = iVar9 + -1) {
        puVar2 = puVar13;
        puVar13 = puVar13 + 1;
        puVar1 = puVar11;
        puVar11 = puVar11 + 1;
        *puVar2 = *puVar1;
      }
      FUN_1000_6a55();
      if (!(bool)uVar15) break;
      FUN_1000_6cb5();
      if (!(bool)uVar14) {
        return uVar7;
      }
    }
    while( true ) {
      FUN_1000_7c9e();
      FUN_1000_4a4d();
      FUN_1000_72ad();
      FUN_1000_6c3f();
      FUN_1000_69df();
      if (!(bool)uVar15) break;
      FUN_1000_6cb5();
      bVar4 = !(bool)uVar14;
      uVar14 = 1;
      if (bVar4) {
        return uVar7;
      }
    }
    pbVar12 = (byte *)(*(int *)0x3e82 + 0x140);
    iVar9 = 0xb6;
    do {
      if (*pbVar12 == 0) break;
      uVar15 = *pbVar12 < 0xe5;
      uVar14 = *pbVar12 == 0xe5;
      if (!(bool)uVar14) {
        do {
          FUN_1000_6c3f();
          FUN_1000_687e();
          if (!(bool)uVar15) {
            local_16 = *(int *)0x3e94;
            FUN_1000_6f4b();
            FUN_1000_68bb();
            if (!(bool)uVar15) break;
          }
          FUN_1000_6cb5();
        } while ((bool)uVar14);
        do {
          uVar16 = uVar14;
          FUN_1000_6c3f();
          FUN_1000_6916();
          if ((!(bool)uVar15) && (FUN_1000_694f(), !(bool)uVar15)) {
            iVar3 = *(int *)0x3e94;
            *(undefined2 *)(iVar3 + 0x16) = *(undefined2 *)(local_16 + 0x16);
            *(undefined2 *)(iVar3 + 0x18) = *(undefined2 *)(local_16 + 0x18);
            FUN_1000_69c2();
            if (!(bool)uVar15) break;
          }
          FUN_1000_6cb5();
          uVar14 = 1;
        } while ((bool)uVar16);
      }
      pbVar12 = pbVar12 + 0x20;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    FUN_1000_72ad();
  }
  else {
    FUN_1000_0ccc();
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    FUN_1000_72ad();
    FUN_1000_c612();
  }
  FUN_1000_c90f();
  *(uint *)&DAT_0000_3474 = uVar10;
  *(uint *)&DAT_0000_3476 = uVar10;
  *(uint *)&DAT_0000_3478 = uVar10;
  *(uint *)&DAT_0000_347a = uVar10;
  *(uint *)&DAT_0000_347c = uVar10 ^ 1;
  FUN_1000_633b();
  return uVar7;
}



/* 1000:06e7  FUN_1000_06e7  67 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_06e7(void)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  undefined2 in_CX;
  int iVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  undefined2 unaff_ES;
  undefined2 in_stack_00000000;
  
  puVar4 = (undefined2 *)&DAT_0000_3e20;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar1 = puVar4;
    puVar4 = (undefined2 *)((int)puVar4 + 1);
    *(undefined1 *)puVar1 = 0;
  }
  puVar5 = (undefined1 *)((int)puVar4 + 3);
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = 0;
  }
  FUN_1000_7518();
  puVar5 = (undefined1 *)0x5f1c;
  for (iVar3 = 0x30; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = 0xff;
  }
  for (iVar3 = 0x90; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = 0;
  }
  FUN_1000_759b();
  FUN_1000_49bb();
  FUN_1000_4be9();
  FUN_1000_7518();
  return CONCAT22(in_CX,in_stack_00000000);
}



/* 1000:072a  FUN_1000_072a  18 bytes, 1 callers */

void __cdecl16near FUN_1000_072a(void)

{
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  FUN_1000_6d3a();
  if (!(bool)in_CF) {
    *unaff_DI = *(undefined2 *)(*(int *)0x3e94 + 0x12);
    return;
  }
  *unaff_DI = 0;
  return;
}



/* 1000:0ccc  FUN_1000_0ccc  23 bytes, 10 callers */

void __cdecl16near FUN_1000_0ccc(void)

{
  undefined1 in_AL;
  undefined2 unaff_DS;
  
  if (((*(byte *)0x3b3e & 1) == 0) && (*(char *)0x3b40 == '\0')) {
    *(undefined1 *)0x3b41 = in_AL;
    *(undefined1 *)0x3b40 = 0xff;
  }
  return;
}



/* 1000:0ce3  FUN_1000_0ce3  8 bytes, 1 callers */

void __cdecl16near FUN_1000_0ce3(void)

{
  undefined2 unaff_DS;
  
  do {
  } while ((*(byte *)0x3b3e & 1) == 0);
  return;
}



/* 1000:0ceb  FUN_1000_0ceb  31 bytes, 8 callers */

void __cdecl16near FUN_1000_0ceb(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  if (((*(byte *)0x3b3e & 1) == 0) && (*(char *)0x3b40 == '\0')) {
    *(undefined1 *)0x3b41 = 0x10;
    *(undefined1 *)0x3b40 = 0xff;
  }
  *(undefined2 *)0x3b44 = in_AX;
  return;
}



/* 1000:0d0a  FUN_1000_0d0a  8 bytes, 6 callers */

void __cdecl16near FUN_1000_0d0a(void)

{
  undefined2 unaff_DS;
  
  do {
  } while (*(int *)0x3b44 != 0);
  return;
}



/* 1000:0d12  FUN_1000_0d12  12 bytes, 13 callers */

void __cdecl16near FUN_1000_0d12(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  if (*(byte *)0x3b46 <= (byte)in_AX) {
    *(undefined2 *)0x3b46 = in_AX;
  }
  return;
}



/* 1000:14c9  FUN_1000_14c9  31 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_14c9(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  
  FUN_1000_740d();
  FUN_1000_740d();
  FUN_1000_740d();
  return CONCAT22(in_DX,in_AX);
}



/* 1000:14e8  FUN_1000_14e8  48 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_14e8(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  byte extraout_DH;
  byte bVar1;
  undefined2 unaff_DS;
  
  bVar1 = 0;
  do {
    if (bVar1 != 7) {
      FUN_1000_740d();
      bVar1 = extraout_DH;
    }
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0xe);
  FUN_1000_740d();
  FUN_1000_740d();
  *(undefined1 *)0x3ab7 = 0;
  *(undefined1 *)0x3ad7 = 0;
  *(undefined1 *)0x3af7 = 0;
  return CONCAT22(in_DX,in_AX);
}



/* 1000:191c  FUN_1000_191c  394 bytes, 1 callers */

void FUN_1000_191c(void)

{
  undefined2 uVar1;
  uint uVar2;
  int in_CX;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  uint uVar3;
  undefined2 unaff_DS;
  undefined1 uVar4;
  
code_r0x0001191c:
  *(undefined2 *)0x3e78 = 2;
  FUN_1000_0ccc();
  *(undefined2 *)&DAT_0000_3bc6 = 5;
  uVar1 = FUN_1000_5f7e();
  if (*(char *)0x34d6 != '\0') {
    FUN_1000_c5f4(uVar1);
  }
  FUN_1000_0ceb();
LAB_1000_193f:
  FUN_1000_1aa6();
  uVar3 = (uint)(byte)((char)(*(uint *)0x3bc4 / 10) - 1) * 2 + 0x10;
  if ((*(uint *)&DAT_0000_3bc6 & 0xfffe) != uVar3) {
    FUN_1000_0ccc();
    *(uint *)&DAT_0000_3bc6 = uVar3;
    FUN_1000_5f7e();
    FUN_1000_0ceb();
  }
  FUN_1000_7c9e();
  FUN_1000_72ad();
  FUN_1000_0d0a();
  uVar1 = *(undefined2 *)&DAT_0000_3bc6;
  *(uint *)&DAT_0000_3bc6 = *(uint *)&DAT_0000_3bc6 | 1;
  FUN_1000_5f7e();
  *(undefined2 *)&DAT_0000_3bc6 = uVar1;
  *(undefined1 *)0x32d4 = 0x1e;
  *(undefined2 *)0x32e6 = 0;
  *(undefined2 *)0x32e8 = 0;
  *(undefined2 *)0x32ea = 0;
  *(undefined2 *)0x32ec = 0;
LAB_1000_1998:
  uVar3 = FUN_1000_c8d8();
  uVar2 = uVar3 & 0xff6f;
  if ((uVar3 & 0x6f) == 0) {
    if (*(char *)0x32d4 != '\0') goto LAB_1000_1998;
  }
  else {
    if ((*(byte *)0x3c00 < 4) && (*(undefined1 *)0x32d4 = 0x1e, (uVar3 & 0x20) != 0)) {
      if (*(byte *)0x3c00 < 4) {
        FUN_1000_0d12(uVar2);
        FUN_1000_20f0();
        FUN_1000_7c9e();
        FUN_1000_72ad();
        *(undefined1 *)0x32d4 = 0x1e;
      }
      goto LAB_1000_1998;
    }
    if ((uVar3 & 0x40) != 0) goto LAB_1000_1a9b;
    uVar4 = 0;
    if (*(char *)0x32e5 == '\0') {
      FUN_1000_9ab9();
      if ((in_CX != 0) && (FUN_1000_ad80(), !(bool)uVar4)) {
        *(undefined2 *)&DAT_0000_3be4 = extraout_DX;
        FUN_1000_9b42();
        *(undefined2 *)&DAT_0000_32bf = 0;
        if (3 < *(byte *)0x3c00) goto LAB_1000_1a34;
        FUN_1000_7c9e();
        FUN_1000_72ad();
        goto LAB_1000_1998;
      }
    }
    else {
      while( true ) {
        uVar4 = 0;
        if (((uVar2 & 0xf) == 0) || (FUN_1000_9ab9(), in_CX == 0)) goto LAB_1000_1a1b;
        FUN_1000_ad80();
        if ((bool)uVar4) break;
        *(undefined2 *)&DAT_0000_3be4 = extraout_DX_00;
        uVar2 = FUN_1000_c8d8();
      }
      *(undefined2 *)0x32e6 = 0;
      *(undefined2 *)0x32e8 = 0;
LAB_1000_1a1b:
      FUN_1000_9b42();
      *(undefined2 *)&DAT_0000_32bf = 0;
      if (*(byte *)0x3c00 < 4) {
        FUN_1000_7c9e();
        FUN_1000_72ad();
        goto LAB_1000_1998;
      }
    }
  }
LAB_1000_1a34:
  uVar4 = 0;
  if (*(char *)0x32d1 == '\0') {
    *(undefined1 *)0x32d1 = 8;
    *(char *)0x3be8 = *(char *)0x3be8 + '\x01';
    *(undefined2 *)0xc4f2 = *(undefined2 *)0x3c1e;
    FUN_1000_3332();
    FUN_1000_32cc();
    FUN_1000_a6a5();
    FUN_1000_a731();
    FUN_1000_7c9e();
    FUN_1000_72ad();
    FUN_1000_b102();
    FUN_1000_b2f2();
    if (((bool)uVar4) || (FUN_1000_b28d(), (bool)uVar4)) goto code_r0x0001191c;
    FUN_1000_a75d();
  }
  goto LAB_1000_1998;
LAB_1000_1a9b:
  FUN_1000_0d12(uVar2);
  goto LAB_1000_193f;
}



/* 1000:1aa6  FUN_1000_1aa6  84 bytes, 1 callers */

void FUN_1000_1aa6(void)

{
  uint uVar1;
  undefined2 unaff_DS;
  undefined1 uVar2;
  
  FUN_1000_c6a0();
  FUN_1000_4cdd();
  do {
    FUN_1000_7c9e();
    FUN_1000_72ad();
    FUN_1000_4d4a();
    uVar2 = *(char *)0x34d6 != -1;
    if (*(char *)0x34d6 != -1) {
      FUN_1000_c612();
    }
    FUN_1000_c8fd();
    while( true ) {
      uVar1 = FUN_1000_4db2();
      if (!(bool)uVar2) break;
      uVar2 = *(int *)0x3bc2 != -1;
      if ((*(int *)0x3bc2 != -1) && (uVar2 = 0, *(int *)0x3bd4 != 0)) {
        FUN_1000_0d12(uVar1);
        uVar2 = 0;
        FUN_1000_1afa();
      }
    }
    FUN_1000_7c9e();
    FUN_1000_72ad();
    (*(code *)*(undefined2 *)((uVar1 & 0xff) * 2 + 0x202d))();
  } while( true );
}



/* 1000:1afa  FUN_1000_1afa  101 bytes, 1 callers */

void __cdecl16near FUN_1000_1afa(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  bool bVar2;
  
  bVar2 = *(int *)0x3bc2 != -1;
  if (*(int *)0x3bc2 == -1) {
    *(undefined2 *)0x3bc2 = *(undefined2 *)0xce70;
    *(undefined2 *)0x346e = 0xffff;
    FUN_1000_6033();
    if (bVar2) {
      FUN_1000_7c9e();
      FUN_1000_4cdd();
      FUN_1000_72ad();
      return;
    }
    FUN_1000_04b8();
  }
  else if ((*(int *)0x3bd4 != 0) && (*(int *)0x3bd6 != 0)) {
    uVar1 = FUN_1000_4a4d();
    FUN_1000_0d12(uVar1);
    FUN_1000_c90f();
    return;
  }
  *(undefined2 *)0x3bd4 = 0xffff;
  *(undefined2 *)0x346e = 0xffff;
  FUN_1000_7c9e();
  FUN_1000_4d86();
  FUN_1000_4cdd();
  FUN_1000_72ad();
  FUN_1000_c6a0();
  return;
}



/* 1000:20f0  FUN_1000_20f0  494 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_20f0(void)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  undefined2 in_AX;
  undefined2 uVar4;
  int iVar5;
  undefined2 uVar6;
  byte bVar7;
  undefined2 in_DX;
  int in_BX;
  byte *pbVar8;
  undefined2 unaff_DS;
  undefined1 uVar9;
  
  bVar1 = FUN_1000_9b34();
  pbVar8 = *(byte **)((undefined *)&DAT_0000_e47e + in_BX);
  if (((pbVar8 == (byte *)0x0) || (bVar1 = *(byte *)0x3c00, bVar1 != pbVar8[0xc])) ||
     ((*pbVar8 & 2) != 0)) {
    FUN_1000_0d12(bVar1);
    goto LAB_1000_22dc;
  }
  *(undefined2 *)0x3ea6 = pbVar8;
  uVar3 = 0;
  do {
    while( true ) {
      uVar9 = uVar3;
      FUN_1000_bd1e();
      FUN_1000_be36();
      uVar4 = FUN_1000_22de();
      if ((bool)uVar9) goto LAB_1000_22ce;
      *(undefined2 *)0x3ea4 = *(undefined2 *)&DAT_0000_3be4;
      FUN_1000_bd1e();
      FUN_1000_bd84();
      FUN_1000_c316();
      FUN_1000_be36();
      FUN_1000_aaae();
      if (!(bool)uVar9) goto LAB_1000_21f5;
      FUN_1000_bd1e();
      FUN_1000_bd3b();
      FUN_1000_c316();
      FUN_1000_be36();
      uVar4 = FUN_1000_aaae();
      if (!(bool)uVar9) break;
      FUN_1000_bd1e();
      FUN_1000_c316();
      FUN_1000_be36();
      uVar4 = FUN_1000_aaae();
      if ((bool)uVar9) {
        FUN_1000_0d12(uVar4);
        uVar3 = uVar9;
      }
      else {
        FUN_1000_0d12(uVar4);
        FUN_1000_7c9e();
        FUN_1000_4a4d();
        FUN_1000_49bb();
        FUN_1000_72ad();
        cVar2 = FUN_1000_4be9();
        uVar3 = uVar9;
        if ((!(bool)uVar9) && (uVar3 = 0, cVar2 == '\0')) goto LAB_1000_21f5;
      }
    }
    FUN_1000_0d12(uVar4);
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    FUN_1000_49bb();
    FUN_1000_72ad();
    cVar2 = FUN_1000_4be9();
    uVar3 = 1;
  } while (((bool)uVar9) || (uVar3 = 0, cVar2 != '\0'));
LAB_1000_21f5:
  iVar5 = FUN_1000_aaae();
  *(int *)0x3ea2 = iVar5 + -1;
  FUN_1000_0d12(iVar5 + -1);
  uVar9 = 0;
  bVar1 = 0x2d;
  uVar3 = false;
  if ((pbVar8[10] & 0x20) == 0) {
    FUN_1000_ab3e();
    FUN_1000_7c9e();
    FUN_1000_5c69();
    FUN_1000_5bd4();
    FUN_1000_49bb();
    FUN_1000_72ad();
    uVar6 = FUN_1000_4be9();
    uVar4 = uVar6;
    if ((bool)uVar9) {
LAB_1000_22ce:
      *(undefined2 *)&DAT_0000_32bf = pbVar8;
      FUN_1000_0d12(uVar4);
      goto LAB_1000_22dc;
    }
    uVar4 = 0;
    if (3 < (byte)uVar6) {
      FUN_1000_7c9e();
      FUN_1000_5c69();
      FUN_1000_5bd4();
      bVar1 = FUN_1000_4a4d();
      uVar9 = bVar1 < 7;
      FUN_1000_5bd4();
      FUN_1000_49bb();
      FUN_1000_72ad();
      uVar3 = FUN_1000_4be9();
      uVar4 = CONCAT11(uVar3,uVar3);
      if ((bool)uVar9) goto LAB_1000_22ce;
    }
    bVar7 = (byte)((uint)uVar4 >> 8);
    bVar1 = 1;
    if (*(byte *)0x3bf4 != 1) {
      bVar1 = *(byte *)0x3bf4 | 0x10;
    }
    bVar1 = bVar1 | bVar7 >> 2 | bVar7 << 6;
    uVar3 = bVar1 == 0;
  }
  pbVar8[10] = bVar1;
  *(undefined2 *)(pbVar8 + 8) = *(undefined2 *)0x3ea4;
  pbVar8[0xb] = 0xff;
  FUN_1000_b78c();
  bVar1 = FUN_1000_c0bd();
  if (!(bool)uVar3) {
    pbVar8[0xb] = bVar1;
    bVar1 = pbVar8[10] & 0xf;
    if ((((bVar1 == 10) || (bVar1 == 7)) || (bVar1 == 9)) || ((bVar1 == 6 || (bVar1 == 0xb)))) {
      FUN_1000_c2e7();
    }
  }
  *(undefined2 *)&DAT_0000_32bf = pbVar8;
LAB_1000_22dc:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:22de  FUN_1000_22de  137 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_22de(void)

{
  byte bVar1;
  byte bVar2;
  undefined2 in_AX;
  int iVar3;
  undefined2 uVar4;
  int in_CX;
  undefined2 in_DX;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
LAB_1000_22df:
  do {
    FUN_1000_9b34();
    iVar3 = FUN_1000_aad5();
    if ((bool)in_CF) {
      iVar3 = 1;
    }
    *(int *)0x3ea2 = iVar3 + -1;
    *(undefined2 *)&DAT_0000_32bf = 0;
    FUN_1000_7c9e();
    FUN_1000_5c2e();
    FUN_1000_72ad();
    do {
      do {
        bVar1 = FUN_1000_c8d8();
        bVar2 = bVar1 & 0x6f;
      } while (bVar2 == 0);
      if (((bVar1 & 0x20) != 0) || ((bVar1 & 0x40) != 0)) {
        return CONCAT22(in_DX,in_AX);
      }
      in_CF = 0;
      if (*(char *)0x32e5 != '\0') goto LAB_1000_2336;
      FUN_1000_9ab9();
    } while ((in_CX == 0) || (FUN_1000_ad80(), (bool)in_CF));
    *(undefined2 *)&DAT_0000_3be4 = extraout_DX;
    uVar4 = FUN_1000_9b42();
    FUN_1000_0d12(uVar4);
  } while( true );
LAB_1000_2336:
  in_CF = 0;
  if (((bVar2 & 0xf) == 0) || (FUN_1000_9ab9(), in_CX == 0)) goto LAB_1000_235b;
  FUN_1000_ad80();
  if (!(bool)in_CF) {
    *(undefined2 *)&DAT_0000_3be4 = extraout_DX_00;
    bVar2 = FUN_1000_c8d8();
    goto LAB_1000_2336;
  }
  in_CF = 0;
  *(undefined2 *)0x32e6 = 0;
  *(undefined2 *)0x32e8 = 0;
LAB_1000_235b:
  FUN_1000_9b42();
  goto LAB_1000_22df;
}



/* 1000:32cc  FUN_1000_32cc  102 bytes, 1 callers */

void __cdecl16near FUN_1000_32cc(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined2 unaff_DS;
  
  *(undefined2 *)0xc52c = 0;
  iVar2 = (0x40U >> (*(byte *)0x3c02 & 0x1f)) - 1;
  pbVar3 = (undefined *)&DAT_0000_c800 + *(int *)0x3bec;
  while( true ) {
    bVar1 = *pbVar3;
    if (-1 < (char)bVar1) break;
    pbVar4 = pbVar3 + 0x1f0;
    if ((byte *)0xcbff < pbVar4) {
      pbVar4 = pbVar3 + -0x210;
    }
    iVar2 = iVar2 + -1;
    pbVar3 = pbVar4;
    if (iVar2 == 0) {
      *(undefined2 *)0x3bec = pbVar4 + 0x3800;
      return;
    }
  }
  *pbVar3 = bVar1 & 0xfe;
  if ((bVar1 & 2) != 0) {
    FUN_1000_493a();
    return;
  }
  if (pbVar3[0xc] != 4) {
    if ((pbVar3[10] & 0x20) != 0) {
      FUN_1000_3a67();
      return;
    }
    if ((pbVar3[10] & 0x10) == 0) {
      FUN_1000_383e();
      return;
    }
    FUN_1000_3608();
    return;
  }
  FUN_1000_3b86();
  return;
}



/* 1000:3332  FUN_1000_3332  726 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_3332(void)

{
  uint *puVar1;
  undefined2 uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined2 extraout_DX;
  byte bVar8;
  undefined2 extraout_DX_00;
  byte bVar9;
  char cVar11;
  int iVar10;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined2 unaff_DS;
  bool bVar16;
  undefined2 uVar17;
  undefined2 uVar18;
  char *pcStack_2;
  
  if ((*(int *)0x3bce == 0) || (2 < *(uint *)0x3bc2)) {
    puVar12 = (uint *)0xc792;
    iVar6 = 4;
    cVar11 = '\0';
    cVar5 = *(char *)0x3c00;
    do {
      if (((*puVar12 & 8) == 0) && (cVar5 != cVar11)) {
        if ((puVar12[8] != 0) ||
           (bVar3 = (byte)(puVar12[7] >> 8), bVar9 = 0x12 - bVar3, 0x12 < bVar3 || bVar9 == 0)) {
          bVar9 = 1;
        }
        if ((byte)puVar12[9] != bVar9) {
          if ((byte)puVar12[9] < bVar9) {
            *(char *)(puVar12 + 9) = (char)puVar12[9] + '\x01';
          }
          else {
            *(char *)(puVar12 + 9) = (char)puVar12[9] + -1;
          }
        }
      }
      cVar11 = cVar11 + '\x01';
      puVar12 = puVar12 + 0xb;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  iVar6 = (0x90U >> (*(byte *)0x3c02 & 0x1f)) - 1;
  uVar18 = 0x500;
  iVar10 = 0x804;
  uVar13 = *(uint *)0x3bea;
  while( true ) {
    bVar3 = ((undefined *)&DAT_0000_d27e)[uVar13];
    bVar9 = (byte)((uint)uVar18 >> 8);
    if (bVar3 == bVar9) {
      pcStack_2 = (char *)s_END01_PAC_0000_33c2;
      uVar18 = 0x1418;
      if ((byte)((undefined *)&DAT_0000_d27f)[uVar13] < 0xf6) {
        ((undefined *)&DAT_0000_d27f)[uVar13] = ((undefined *)&DAT_0000_d27f)[uVar13] + 10;
      }
      else {
        bVar16 = false;
        if ((*(int *)((undefined *)&DAT_0000_e47e + uVar13) == 0) &&
           (FUN_1000_add0(uVar13,0x1200,0x2e,&pcStack_2,0x804,0x1418,iVar6), !bVar16)) {
          *(undefined2 *)0x1202 =
               CONCAT11((char)((uVar13 >> 1) / 0x30),(char)((uVar13 >> 1) % 0x30));
          *(uint *)0x1204 = uVar13;
          *(undefined1 *)0x1200 = 0;
          *(undefined1 *)0x1201 = 6;
          *(undefined1 *)0x120a = 0xf;
          *(undefined1 *)0x120c = 4;
          *(undefined2 *)0x1206 = 200;
          *(undefined1 *)0x120b = 0xff;
          *(undefined2 *)((undefined *)&DAT_0000_e47e + uVar13) = 0x1200;
          ((undefined *)&DAT_0000_d27f)[uVar13] = 0;
        }
      }
      return CONCAT22(uVar18,CONCAT11(bVar9,bVar3));
    }
    if ((0x13 < bVar3) && (bVar3 < 0x18)) {
      pcStack_2 = (char *)s_END01_PAC_0000_33c2;
      uVar18 = 0x1418;
      iVar10 = *(int *)((undefined *)&DAT_0000_e47e + uVar13);
      if (((iVar10 != 0) &&
          (((byte)(bVar3 - 0x14) == *(char *)(iVar10 + 0xc) &&
           ((*(byte *)(iVar10 + 10) & 0x20) != 0)))) &&
         ((bVar8 = ((undefined *)&DAT_0000_d282)[uVar13] - 8, 7 < bVar8 ||
          (uVar14 = CONCAT11(bVar8,bVar3 - 0x14) & 0x3ff, (char)uVar14 == (char)(uVar14 >> 8))))) {
        bVar8 = FUN_1000_adbe(uVar13,0x1200,0x2e,&pcStack_2,0x804,0x1418,iVar6);
        iVar6 = *(int *)((undefined *)&DAT_0000_12ef + (uint)bVar8 * 2);
        FUN_1000_bd1e();
        FUN_1000_be03();
        cVar5 = FUN_1000_be36();
        bVar8 = *(byte *)(iVar6 + 0x12);
        puVar12 = (uint *)0x0;
        iVar10 = 0x900;
        do {
          if ((((char)puVar12[-0x16c1] == (char)(cVar5 + '\b')) && (*puVar12 < 0x4000)) &&
             (bVar4 = (byte)((uint)bVar8 * (puVar12[-0x16c1] >> 8) >> 8), bVar4 != 0)) {
            puVar1 = (uint *)(iVar6 + 0xe);
            uVar13 = *puVar1;
            *puVar1 = *puVar1 + (uint)bVar4;
            *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + (uint)CARRY2(uVar13,(uint)bVar4);
            *(char *)((int)puVar12 + -0x2d81) = *(char *)((int)puVar12 + -0x2d81) - bVar4;
          }
          puVar12 = puVar12 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      return CONCAT22(uVar18,CONCAT11(bVar9,bVar3));
    }
    bVar3 = bVar3 - 8;
    uVar18 = CONCAT11(bVar9,bVar3);
    if (bVar3 < 4) break;
    uVar14 = uVar13 + 0x2e;
    if (0x11ff < uVar14) {
      uVar14 = uVar13 + 0xee2e;
    }
    iVar6 = iVar6 + -1;
    uVar13 = uVar14;
    if (iVar6 == 0) {
      *(uint *)0x3bea = uVar14;
      return CONCAT22(0x1418,uVar18);
    }
  }
  pcStack_2 = (char *)s_END01_PAC_0000_33c2;
  uVar17 = 0x1418;
  puVar12 = *(uint **)((undefined *)&DAT_0000_12ef + (uint)bVar3 * 2);
  if ((*puVar12 & 8) != 0) {
    cVar5 = ((undefined *)&DAT_0000_d27e)[uVar13];
    bVar3 = *(byte *)((int)puVar12 + 0x15);
    if (bVar3 < 4) {
      ((undefined *)&DAT_0000_d27e)[uVar13] = bVar3 + 8;
      iVar6 = uVar13 - 0x62;
      iVar10 = 3;
      do {
        iVar7 = 3;
        do {
          iVar15 = iVar6;
          if ((char)(cVar5 + '\x04') == ((undefined *)&DAT_0000_d27e)[iVar15]) {
            ((undefined *)&DAT_0000_d27e)[iVar15] = bVar3 + 0xc;
          }
          iVar7 = iVar7 + -1;
          iVar6 = iVar15 + 2;
        } while (iVar7 != 0);
        iVar6 = iVar15 + 0x5c;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    else {
      LOCK();
      uVar2 = *(undefined2 *)((undefined *)&DAT_0000_d27e + uVar13);
      *(undefined **)((undefined *)&DAT_0000_d27e + uVar13) = (undefined *)&DAT_0000_6400;
      UNLOCK();
      iVar6 = uVar13 - 0x62;
      iVar10 = 3;
      do {
        iVar7 = 3;
        do {
          iVar15 = iVar6;
          if ((char)((char)uVar2 + '\x04') == ((undefined *)&DAT_0000_d27e)[iVar15]) {
            ((undefined *)&DAT_0000_d27e)[iVar15] = 0;
          }
          iVar7 = iVar7 + -1;
          iVar6 = iVar15 + 2;
        } while (iVar7 != 0);
        iVar6 = iVar15 + 0x5c;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    goto LAB_1000_3531;
  }
  if ((*puVar12 & 1) != 0) goto LAB_1000_3531;
  if ((bVar3 == *(byte *)0x3c00) || (*(int *)0x347e == 0)) {
    FUN_1000_adeb(uVar13,0x1200,0x2e,&pcStack_2,0x804,0x1418,iVar6);
    cVar5 = (char)extraout_DX_00;
    bVar9 = (char)((uint)extraout_DX_00 >> 8) + 1;
    bVar8 = bVar9 * '\x10';
    bVar3 = ((undefined *)&DAT_0000_d27f)[uVar13] + bVar9;
    if (CARRY1(((undefined *)&DAT_0000_d27f)[uVar13],bVar9)) {
      bVar3 = 0xff;
    }
  }
  else {
    FUN_1000_adeb(uVar13,0x1200,0x2e,&pcStack_2,0x804,0x1418,iVar6);
    cVar5 = (char)extraout_DX;
    bVar9 = (char)((uint)extraout_DX >> 8) + 1;
    bVar8 = bVar9 * '\x10';
    bVar4 = ((undefined *)&DAT_0000_d27f)[uVar13] + bVar9;
    bVar3 = bVar4 + bVar9;
    if (CARRY1(bVar4,bVar9)) {
      bVar3 = 0xff;
    }
  }
  ((undefined *)&DAT_0000_d27f)[uVar13] = bVar3;
  if (bVar3 <= bVar8) goto LAB_1000_3531;
  if (bVar9 < 9) {
    if (cVar5 == '\0') {
      bVar16 = (byte)((undefined *)&DAT_0000_d27e)[uVar13] < 8;
      FUN_1000_b7cf();
      if (bVar16) goto LAB_1000_346a;
    }
    *(uint *)((undefined *)&DAT_0000_d27e + iVar10) =
         CONCAT11(100,((undefined *)&DAT_0000_d27e)[uVar13] + '\x04');
    if ((byte)((undefined *)&DAT_0000_d27f)[uVar13] < 200) goto LAB_1000_3531;
  }
LAB_1000_346a:
  iVar6 = *(int *)((undefined *)&DAT_0000_e47e + uVar13);
  bVar16 = false;
  if (iVar6 == 0) {
    FUN_1000_add0();
    if (!bVar16) {
      uVar2 = CONCAT11((char)((uVar13 >> 1) / 0x30),(char)((uVar13 >> 1) % 0x30));
      *(undefined2 *)0x2 = uVar2;
      *(uint *)0x4 = uVar13;
      *(undefined2 *)0x8 = uVar2;
      *(undefined1 *)0x0 = 0;
      *(undefined1 *)0x1 = 6;
      *(undefined2 *)((undefined *)&DAT_0000_e47e + uVar13) = 0;
      *(undefined1 *)0xa = 1;
      LOCK();
      bVar3 = ((undefined *)&DAT_0000_d27f)[uVar13];
      ((undefined *)&DAT_0000_d27f)[uVar13] = 1;
      UNLOCK();
      *(int *)0x6 = bVar3 - 1;
      *(char *)0xc = ((undefined *)&DAT_0000_d27e)[uVar13] + -8;
    }
  }
  else if ((char)(((undefined *)&DAT_0000_d27e)[uVar13] + -8) == *(char *)(iVar6 + 0xc)) {
    LOCK();
    bVar3 = ((undefined *)&DAT_0000_d27f)[uVar13];
    ((undefined *)&DAT_0000_d27f)[uVar13] = 1;
    uVar14 = (uint)bVar3;
    UNLOCK();
    puVar1 = (uint *)(iVar6 + 6);
    uVar13 = *puVar1;
    *puVar1 = *puVar1 + uVar14;
    if (CARRY2(uVar13,uVar14)) {
      *(undefined2 *)(iVar6 + 6) = 0xffff;
    }
  }
LAB_1000_3531:
  return CONCAT22(uVar17,uVar18);
}



/* 1000:3608  FUN_1000_3608  511 bytes, 1 callers */

void __cdecl16near FUN_1000_3608(void)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined2 extraout_DX;
  int in_BX;
  uint uVar6;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool bVar7;
  undefined1 uVar8;
  
  FUN_1000_a98d();
  if ((bool)in_CF) {
    return;
  }
  FUN_1000_41b5();
  bVar7 = *(char *)(unaff_SI + 0xb) != -1;
  if (*(char *)(unaff_SI + 0xb) != -1) {
    bVar5 = FUN_1000_c291();
    uVar8 = *(byte *)(unaff_SI + 1) < bVar5;
    if (*(byte *)(unaff_SI + 1) != bVar5) {
      *(byte *)(unaff_SI + 0xe) = bVar5;
      *(byte *)(unaff_SI + 1) = bVar5;
      return;
    }
    FUN_1000_9ad3();
    FUN_1000_ad80();
    if ((bool)uVar8) {
      *(undefined1 *)(unaff_SI + 10) = 1;
      *(undefined1 *)(unaff_SI + 0xb) = 0xff;
      return;
    }
    FUN_1000_9b34();
    bVar7 = (byte)((undefined *)&DAT_0000_d27e)[in_BX] < 0x30;
    if (bVar7) {
      FUN_1000_3d5e();
      if (!bVar7) {
        return;
      }
      FUN_1000_3e21();
      if (!bVar7) {
        return;
      }
      bVar7 = false;
      if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0) {
        FUN_1000_4163();
        if (!bVar7) {
          return;
        }
        *(int *)((undefined *)&DAT_0000_e47e + in_BX) = unaff_SI;
        LOCK();
        iVar2 = *(int *)(unaff_SI + 4);
        *(int *)(unaff_SI + 4) = in_BX;
        UNLOCK();
        *(undefined2 *)((undefined *)&DAT_0000_e47e + iVar2) = 0;
        *(undefined2 *)(unaff_SI + 2) = extraout_DX;
        FUN_1000_c2c0();
        return;
      }
    }
    bVar7 = false;
    pcVar1 = (char *)(unaff_SI + 0xf);
    *pcVar1 = *pcVar1 + -1;
    if (*pcVar1 == '\0') {
      *(undefined1 *)(unaff_SI + 0xf) = 1;
      FUN_1000_adbe();
      if (!bVar7) {
        FUN_1000_48df();
        return;
      }
    }
    return;
  }
  FUN_1000_3d2c();
  if (!bVar7) {
    return;
  }
  uVar6 = *(byte *)(unaff_SI + 10) & 0xf;
  uVar8 = CARRY2(uVar6,uVar6);
  bVar7 = (*(byte *)(unaff_SI + 10) & 0xf) == 0;
  switch(uVar6) {
  default:
    *(undefined1 *)(unaff_SI + 1) = 6;
    return;
  case 1:
  case 3:
    FUN_1000_adbe();
    if (!(bool)uVar8) {
      FUN_1000_4881();
      return;
    }
    bVar7 = 0xf7 < *(byte *)(unaff_SI + 0xc);
    uVar8 = FUN_1000_af42();
    if (!bVar7) {
      *(undefined1 *)(unaff_SI + 1) = uVar8;
      uVar8 = FUN_1000_b78c();
      *(undefined1 *)(unaff_SI + 0xb) = uVar8;
      FUN_1000_c231();
      return;
    }
    return;
  case 2:
    FUN_1000_3ec7();
    *(undefined1 *)(unaff_SI + 1) = 6;
    return;
  case 4:
    FUN_1000_3e98();
    if ((bool)uVar8) {
      FUN_1000_3807();
      bVar5 = FUN_1000_a61d();
      bVar7 = 0xf7 < bVar5;
      cVar3 = FUN_1000_b037();
      if (!bVar7) {
        *(char *)(unaff_SI + 1) = cVar3 << 1;
        uVar8 = FUN_1000_b78c();
        *(undefined1 *)(unaff_SI + 0xb) = uVar8;
        if (-1 < cVar3) {
          FUN_1000_c231();
          return;
        }
        FUN_1000_c25c();
        return;
      }
      FUN_1000_adbe();
      if ((!bVar7) && (FUN_1000_44dc(), bVar7)) break;
    }
    return;
  case 5:
    FUN_1000_3ec7();
    if (!(bool)uVar8) {
      return;
    }
    if (!bVar7) {
      FUN_1000_3807();
      bVar5 = FUN_1000_a61d();
      bVar7 = 0xf7 < bVar5;
      uVar8 = FUN_1000_af6f();
      if (!bVar7) {
        *(undefined1 *)(unaff_SI + 1) = uVar8;
        uVar8 = FUN_1000_b78c();
        *(undefined1 *)(unaff_SI + 0xb) = uVar8;
        FUN_1000_c25c();
        return;
      }
      FUN_1000_adbe();
      if (bVar7) {
        return;
      }
      FUN_1000_4497();
      if (!bVar7) {
        return;
      }
    }
    break;
  case 6:
    FUN_1000_3f62();
    if ((bool)uVar8) {
      if (!bVar7) {
        FUN_1000_9b34();
        FUN_1000_4163();
        if ((bool)uVar8) {
          FUN_1000_3807();
        }
      }
    }
    else if (bVar7) {
      FUN_1000_3807();
    }
    return;
  case 7:
    FUN_1000_4040();
    if ((bool)uVar8) {
      if (!bVar7) {
        FUN_1000_3807();
      }
    }
    else if (bVar7) {
      FUN_1000_3807();
    }
    return;
  case 8:
    FUN_1000_3f2a();
    if (((bool)uVar8) || (bVar7)) {
      FUN_1000_3807();
      uVar4 = FUN_1000_af05();
      if (!(bool)uVar8) {
        *(undefined1 *)(unaff_SI + 1) = uVar4;
        uVar8 = FUN_1000_b78c();
        *(undefined1 *)(unaff_SI + 0xb) = uVar8;
        FUN_1000_c231();
        return;
      }
      FUN_1000_adbe();
      if ((!(bool)uVar8) && (FUN_1000_4516(), (bool)uVar8)) break;
    }
    return;
  case 9:
    FUN_1000_41dc();
    if ((bool)uVar8) {
      FUN_1000_3807();
      FUN_1000_adbe();
      if ((!(bool)uVar8) && (FUN_1000_45e7(), (bool)uVar8)) break;
    }
    else if (bVar7) {
      FUN_1000_3807();
      FUN_1000_adbe();
      if ((!(bool)uVar8) && (FUN_1000_45e7(), (bool)uVar8)) break;
    }
    return;
  case 10:
    FUN_1000_4247();
    if (!(bool)uVar8) {
      if (bVar7) {
        FUN_1000_3807();
      }
      return;
    }
    FUN_1000_3807();
    break;
  case 0xb:
    FUN_1000_4304();
    if ((!(bool)uVar8) && (!bVar7)) {
      return;
    }
    FUN_1000_3807();
    FUN_1000_adbe();
    if ((bool)uVar8) {
      return;
    }
    FUN_1000_461e();
    if (!(bool)uVar8) {
      return;
    }
    break;
  case 0xc:
    *(undefined1 *)(unaff_SI + 0xc) =
         *(undefined1 *)
          (*(int *)((undefined *)&DAT_0000_12ef + (uint)*(byte *)(unaff_SI + 0xc) * 2) + 0x15);
    *(undefined1 *)(unaff_SI + 10) = 1;
    return;
  }
  *(undefined1 *)(unaff_SI + 10) = 1;
  return;
}



/* 1000:3807  FUN_1000_3807  23 bytes, 1 callers */

void __cdecl16near FUN_1000_3807(void)

{
  int unaff_SI;
  undefined2 unaff_DS;
  
  if ((*(byte *)(unaff_SI + 10) & 0x80) != 0) {
    return;
  }
  if ((*(byte *)(unaff_SI + 10) & 0x40) == 0) {
    *(undefined1 *)(unaff_SI + 10) = 1;
    return;
  }
  *(undefined1 *)(unaff_SI + 10) = 0x10;
  return;
}



/* 1000:383e  FUN_1000_383e  520 bytes, 1 callers */

void __cdecl16near FUN_1000_383e(void)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  int extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 extraout_DX_01;
  int in_BX;
  uint uVar4;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool bVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  
  iVar1 = *(int *)(unaff_SI + 4);
  FUN_1000_a98d();
  if ((bool)in_CF) {
    return;
  }
  FUN_1000_41b5();
  bVar5 = *(char *)(unaff_SI + 0xb) != -1;
  if (*(char *)(unaff_SI + 0xb) != -1) {
    bVar3 = FUN_1000_c291();
    uVar7 = *(byte *)(unaff_SI + 1) < bVar3;
    if (*(byte *)(unaff_SI + 1) != bVar3) {
      *(byte *)(unaff_SI + 0xe) = bVar3;
      *(byte *)(unaff_SI + 1) = bVar3;
      return;
    }
    FUN_1000_9ad3();
    FUN_1000_ad80();
    if (!(bool)uVar7) {
      FUN_1000_9b34();
      bVar5 = (byte)((undefined *)&DAT_0000_d27e)[in_BX] < 0x30;
      if (bVar5) {
        FUN_1000_3d5e();
        if (!bVar5) {
          return;
        }
        FUN_1000_3e21();
        if (!bVar5) {
          return;
        }
        bVar5 = false;
        if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0) {
          FUN_1000_4163();
          if (!bVar5) {
            return;
          }
          *(int *)((undefined *)&DAT_0000_e47e + in_BX) = unaff_SI;
          LOCK();
          iVar1 = *(int *)(unaff_SI + 4);
          *(int *)(unaff_SI + 4) = in_BX;
          UNLOCK();
          *(undefined2 *)((undefined *)&DAT_0000_e47e + iVar1) = 0;
          *(undefined2 *)(unaff_SI + 2) = extraout_DX_01;
          FUN_1000_c2c0();
          return;
        }
      }
      else if (*(char *)0x3c00 != *(char *)(unaff_SI + 0xc)) {
        uVar7 = 7;
        if (((undefined *)&DAT_0000_d27e)[in_BX] != 'z') {
          if (((undefined *)&DAT_0000_d27e)[in_BX] != '{') goto LAB_1000_3a3e;
          uVar7 = 9;
        }
        *(undefined1 *)(unaff_SI + 10) = uVar7;
        *(undefined2 *)(unaff_SI + 8) = extraout_DX_00;
        *(undefined1 *)(unaff_SI + 0xb) = 0xff;
        return;
      }
    }
LAB_1000_3a3e:
    *(undefined1 *)(unaff_SI + 10) = 1;
    *(undefined1 *)(unaff_SI + 0xb) = 0xff;
    return;
  }
  FUN_1000_3d2c();
  if (!bVar5) {
    return;
  }
  uVar4 = *(byte *)(unaff_SI + 10) & 0xf;
  uVar6 = CARRY2(uVar4,uVar4);
  uVar7 = (*(byte *)(unaff_SI + 10) & 0xf) == 0;
  switch(uVar4) {
  default:
    *(undefined1 *)(unaff_SI + 1) = 6;
    return;
  case 1:
  case 3:
    FUN_1000_3ec7();
    if (!(bool)uVar6) {
      return;
    }
    FUN_1000_adbe();
    if (!(bool)uVar6) {
      FUN_1000_4881();
      return;
    }
    bVar5 = 0xf7 < *(byte *)(unaff_SI + 0xc);
    uVar7 = FUN_1000_af42();
    if (!bVar5) {
      *(undefined1 *)(unaff_SI + 1) = uVar7;
      uVar7 = FUN_1000_b78c();
      *(undefined1 *)(unaff_SI + 0xb) = uVar7;
      FUN_1000_c231();
      return;
    }
    return;
  case 2:
    FUN_1000_3ec7();
    *(undefined1 *)(unaff_SI + 1) = 6;
    bVar3 = ((undefined *)&DAT_0000_d27e)[iVar1] - 0x14;
    if (bVar3 < 4) {
      bVar5 = bVar3 < *(byte *)(unaff_SI + 0xc);
      if (bVar3 != *(byte *)(unaff_SI + 0xc)) {
        return;
      }
    }
    else {
      bVar3 = ((undefined *)&DAT_0000_d27a)[iVar1] - 0x14;
      bVar5 = false;
      if ((bVar3 < 4) &&
         (bVar5 = bVar3 < *(byte *)(unaff_SI + 0xc), bVar3 != *(byte *)(unaff_SI + 0xc))) {
        if (*(int *)((undefined *)&DAT_0000_e47a + iVar1) == 0) {
          return;
        }
        uVar4 = *(uint *)(*(int *)((undefined *)&DAT_0000_e47a + iVar1) + 6);
        if ((extraout_DX << 1 | (uint)((int)uVar4 < 0)) + extraout_DX +
            (uint)CARRY2(uVar4 * 2,uVar4) != 0) {
          return;
        }
        if (*(uint *)(unaff_SI + 6) <= uVar4 * 3) {
          return;
        }
        FUN_1000_47e9();
        return;
      }
    }
    FUN_1000_adbe();
    if (!bVar5) {
      FUN_1000_4881();
    }
    return;
  case 4:
    bVar3 = FUN_1000_a61d();
    bVar5 = 0xf7 < bVar3;
    cVar2 = FUN_1000_b037();
    if (!bVar5) {
      *(char *)(unaff_SI + 1) = cVar2 << 1;
      uVar7 = FUN_1000_b78c();
      *(undefined1 *)(unaff_SI + 0xb) = uVar7;
      if (-1 < cVar2) {
        FUN_1000_c231();
        return;
      }
      FUN_1000_c25c();
      return;
    }
    break;
  case 5:
    FUN_1000_3ec7();
    if (!(bool)uVar6) {
      return;
    }
    if (!(bool)uVar7) {
      bVar3 = FUN_1000_a61d();
      bVar5 = 0xf7 < bVar3;
      uVar7 = FUN_1000_af6f();
      if (!bVar5) {
        *(undefined1 *)(unaff_SI + 1) = uVar7;
        uVar7 = FUN_1000_b78c();
        *(undefined1 *)(unaff_SI + 0xb) = uVar7;
        FUN_1000_c25c();
        return;
      }
    }
    break;
  case 6:
    FUN_1000_3f62();
    if ((bool)uVar6) {
      if ((bool)uVar7) break;
      FUN_1000_9b34();
      FUN_1000_4163();
      uVar7 = uVar6;
    }
    if (!(bool)uVar7) {
      return;
    }
    break;
  case 7:
    FUN_1000_4040();
    if ((!(bool)uVar6) && (!(bool)uVar7)) {
      return;
    }
    break;
  case 8:
    FUN_1000_3f2a();
    if (((!(bool)uVar6) && (!(bool)uVar7)) || (FUN_1000_3ec7(), !(bool)uVar6)) {
      return;
    }
    uVar7 = FUN_1000_af05();
    if (!(bool)uVar6) {
      *(undefined1 *)(unaff_SI + 1) = uVar7;
      uVar7 = FUN_1000_b78c();
      *(undefined1 *)(unaff_SI + 0xb) = uVar7;
      FUN_1000_c231();
      return;
    }
    break;
  case 9:
    FUN_1000_41dc();
    if ((!(bool)uVar6) && (!(bool)uVar7)) {
      return;
    }
    break;
  case 10:
    FUN_1000_4247();
    if ((!(bool)uVar6) && (!(bool)uVar7)) {
      return;
    }
    break;
  case 0xb:
    FUN_1000_4304();
    if ((!(bool)uVar6) && (!(bool)uVar7)) {
      return;
    }
    break;
  case 0xc:
    *(undefined1 *)(unaff_SI + 0xc) =
         *(undefined1 *)
          (*(int *)((undefined *)&DAT_0000_12ef + (uint)*(byte *)(unaff_SI + 0xc) * 2) + 0x15);
  }
  *(undefined1 *)(unaff_SI + 10) = 1;
  return;
}



/* 1000:3a67  FUN_1000_3a67  287 bytes, 1 callers */

void __cdecl16near FUN_1000_3a67(void)

{
  char *pcVar1;
  int iVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  int in_BX;
  int iVar5;
  int unaff_SI;
  undefined2 unaff_DS;
  bool bVar6;
  undefined1 uVar7;
  
  iVar5 = *(int *)(unaff_SI + 4);
  bVar3 = *(char *)(unaff_SI + 0xc) + 0x14;
  bVar6 = bVar3 < (byte)((undefined *)&DAT_0000_d27e)[iVar5];
  if (bVar3 != ((undefined *)&DAT_0000_d27e)[iVar5]) {
    FUN_1000_a98d();
    if (bVar6) {
      return;
    }
  }
  FUN_1000_3c7f();
  FUN_1000_41b5();
  bVar6 = *(char *)(unaff_SI + 0xb) != -1;
  if (*(char *)(unaff_SI + 0xb) == -1) {
    FUN_1000_3d2c();
    if (!bVar6) {
      return;
    }
    *(undefined1 *)(unaff_SI + 1) = 6;
    if ((((*(int *)0x3bce == 0) || (0x13 < *(uint *)0x3bc2)) &&
        (*(char *)(unaff_SI + 0xc) != *(char *)0x3c00)) &&
       ((*(char *)(unaff_SI + 0xc) == (char)(((undefined *)&DAT_0000_d27e)[iVar5] + -0x14) &&
        (iVar5 = *(int *)((undefined *)&DAT_0000_e482 + iVar5), iVar5 != 0)))) {
      uVar4 = FUN_1000_a61d();
      if (((char)uVar4 != *(char *)(iVar5 + 0xc)) &&
         (((char)((uint)uVar4 >> 8) != *(char *)(iVar5 + 0xc) &&
          (uVar7 = *(uint *)(iVar5 + 6) < *(uint *)(unaff_SI + 6), (bool)uVar7)))) {
        FUN_1000_9ad3();
        FUN_1000_ad80();
        if (!(bool)uVar7) {
          FUN_1000_9b34();
          if (((byte)((undefined *)&DAT_0000_d27e)[iVar5] < 0x30) &&
             (*(int *)((undefined *)&DAT_0000_e47e + iVar5) == 0)) {
            *(int *)((undefined *)&DAT_0000_e47e + iVar5) = unaff_SI;
            LOCK();
            iVar2 = *(int *)(unaff_SI + 4);
            *(int *)(unaff_SI + 4) = iVar5;
            UNLOCK();
            *(undefined2 *)((undefined *)&DAT_0000_e47e + iVar2) = 0;
            *(undefined2 *)(unaff_SI + 2) = extraout_DX;
            *(undefined1 *)(unaff_SI + 1) = 2;
            uVar7 = FUN_1000_b78c();
            *(undefined1 *)(unaff_SI + 0xb) = uVar7;
            FUN_1000_c231();
            return;
          }
        }
      }
    }
    return;
  }
  bVar3 = FUN_1000_c291();
  uVar7 = *(byte *)(unaff_SI + 1) < bVar3;
  if (*(byte *)(unaff_SI + 1) != bVar3) {
    *(byte *)(unaff_SI + 0xe) = bVar3;
    *(byte *)(unaff_SI + 1) = bVar3;
    return;
  }
  FUN_1000_9ad3();
  FUN_1000_ad80();
  if (!(bool)uVar7) {
    FUN_1000_9b34();
    bVar6 = (byte)((undefined *)&DAT_0000_d27e)[in_BX] < 0x30;
    if (bVar6) {
      FUN_1000_3d5e();
      if (!bVar6) {
        return;
      }
      FUN_1000_3e21();
      if (!bVar6) {
        return;
      }
      bVar6 = false;
      if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0) {
        FUN_1000_4163();
        if (!bVar6) {
          return;
        }
        *(int *)((undefined *)&DAT_0000_e47e + in_BX) = unaff_SI;
        LOCK();
        iVar5 = *(int *)(unaff_SI + 4);
        *(int *)(unaff_SI + 4) = in_BX;
        UNLOCK();
        *(undefined2 *)((undefined *)&DAT_0000_e47e + iVar5) = 0;
        *(undefined2 *)(unaff_SI + 2) = extraout_DX_00;
        FUN_1000_c2c0();
        return;
      }
    }
    bVar6 = false;
    pcVar1 = (char *)(unaff_SI + 0xf);
    *pcVar1 = *pcVar1 + -1;
    if (*pcVar1 == '\0') {
      *(undefined1 *)(unaff_SI + 0xf) = 1;
      FUN_1000_adbe();
      if (!bVar6) {
        FUN_1000_48df();
        return;
      }
    }
    return;
  }
  *(undefined1 *)(unaff_SI + 0xb) = 0xff;
  return;
}



/* 1000:3b86  FUN_1000_3b86  249 bytes, 1 callers */

void __cdecl16near FUN_1000_3b86(void)

{
  char *pcVar1;
  uint uVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  int iVar7;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  byte in_CF;
  bool bVar8;
  undefined1 uVar9;
  
  FUN_1000_41b5();
  FUN_1000_9ad3();
  FUN_1000_ad80();
  FUN_1000_9b34();
  if ((((in_CF & 1) == 0) && (bVar4 = ((undefined *)&DAT_0000_d27e)[in_BX], bVar4 < 0x30)) &&
     (bVar8 = bVar4 < 0x1d, bVar4 != 0x1d)) {
    FUN_1000_3d5e();
    if (!bVar8) {
      return;
    }
    FUN_1000_3e21();
    if (!bVar8) {
      return;
    }
    bVar8 = false;
    if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0) {
      FUN_1000_4163();
      if (!bVar8) {
        return;
      }
      pcVar1 = (char *)(unaff_SI + 0xf);
      *pcVar1 = *pcVar1 + -1;
      if (*pcVar1 != '\0') {
        *(int *)((undefined *)&DAT_0000_e47e + in_BX) = unaff_SI;
        LOCK();
        iVar7 = *(int *)(unaff_SI + 4);
        *(int *)(unaff_SI + 4) = in_BX;
        UNLOCK();
        *(undefined2 *)((undefined *)&DAT_0000_e47e + iVar7) = 0;
        *(undefined2 *)(unaff_SI + 2) = extraout_DX;
        return;
      }
    }
  }
  cVar3 = FUN_1000_9a24();
  *(char *)(unaff_SI + 0xf) = cVar3 + '\x01';
  cVar3 = *(byte *)(unaff_SI + 1) < 4;
  uVar5 = (uint)(byte)(*(byte *)(unaff_SI + 1) - 4);
  iVar7 = 4;
  do {
    FUN_1000_9ad3();
    FUN_1000_ada4();
    bVar8 = cVar3 == '\0';
    uVar2 = uVar5 >> 8;
    bVar4 = (byte)(uVar2 << 1);
    bVar6 = bVar4 | bVar8;
    cVar3 = 0xfd < (byte)uVar5;
    uVar5 = CONCAT11(bVar6,(byte)uVar5 + 2);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar9 = 0;
  if (bVar6 == 0) {
    cVar3 = *(char *)(unaff_SI + 1);
    iVar7 = 4;
    while( true ) {
      FUN_1000_9ad3();
      FUN_1000_ad80();
      if (!(bool)uVar9) {
        FUN_1000_9b34();
      }
      if ((!(bool)uVar9) &&
         (uVar9 = (byte)((undefined *)&DAT_0000_d27e)[in_BX] < 0x7b,
         ((undefined *)&DAT_0000_d27e)[in_BX] == 0x7b)) break;
      cVar3 = cVar3 + '\x01';
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) {
        return;
      }
    }
    *(char *)(unaff_SI + 1) = cVar3;
    pcVar1 = (undefined *)&DAT_0000_d27f + in_BX;
    cVar3 = *pcVar1;
    *pcVar1 = *pcVar1 + -1;
    if (cVar3 != '\0') {
      return;
    }
    *(undefined **)((undefined *)&DAT_0000_d27e + in_BX) = (undefined *)&DAT_0000_6400;
    FUN_1000_484a();
    return;
  }
  if ((uVar2 & 3) != 0 || bVar8) {
    bVar4 = bVar4 & 7 | bVar8;
    cVar3 = '\0';
    if (((bVar4 == 2) || (cVar3 = '\x02', bVar4 == 1)) || (cVar3 = -2, bVar4 == 4))
    goto LAB_1000_3c25;
  }
  bVar4 = FUN_1000_9a24();
  cVar3 = '\x02';
  if (0x31 < bVar4) {
    cVar3 = -2;
  }
LAB_1000_3c25:
  *(byte *)(unaff_SI + 1) = cVar3 + *(char *)(unaff_SI + 1) & 6;
  return;
}



/* 1000:3c7f  FUN_1000_3c7f  173 bytes, 1 callers */

void __cdecl16near FUN_1000_3c7f(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  bool bVar7;
  
  *unaff_SI = *unaff_SI & 0xfb;
  uVar4 = *(uint *)(*(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_SI[0xc] * 2) + 8);
  iVar5 = *(int *)(*(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_SI[0xc] * 2) + 10);
  uVar1 = (uint)(*(uint *)(unaff_SI + 6) >> 1 < uVar4);
  uVar2 = -iVar5;
  if (((iVar5 == 0 && uVar1 <= uVar2) && uVar2 != uVar1) ||
     ((uVar2 == uVar1 && (*(uint *)(unaff_SI + 6) >> 1 != uVar4)))) {
    if ((byte)(unaff_SI[0xc] + 0x14) == ((undefined *)&DAT_0000_d27e)[unaff_DI]) {
      bVar7 = false;
      if (*(int *)((undefined *)&DAT_0000_e480 + unaff_DI) == 0) {
        pbVar6 = unaff_SI;
        FUN_1000_add0();
        if ((!bVar7) && (uVar4 = *(uint *)(pbVar6 + 6) >> 2, uVar4 != 0)) {
          *(uint *)(unaff_SI + 6) = uVar4;
          *(uint *)(pbVar6 + 6) = *(int *)(pbVar6 + 6) - uVar4;
          uVar4 = unaff_DI + 2U >> 1;
          uVar3 = CONCAT11((char)(uVar4 / 0x30),(char)(uVar4 % 0x30));
          *(undefined2 *)(unaff_SI + 2) = uVar3;
          *(undefined2 *)(unaff_SI + 8) = uVar3;
          *(uint *)(unaff_SI + 4) = unaff_DI + 2U;
          *unaff_SI = 0;
          unaff_SI[1] = 6;
          *(byte **)((undefined *)&DAT_0000_e480 + unaff_DI) = unaff_SI;
          unaff_SI[10] = 1;
          unaff_SI[0xc] = pbVar6[0xc];
        }
      }
    }
  }
  else if ((byte)(unaff_SI[0xc] + 0x14) == ((undefined *)&DAT_0000_d27e)[unaff_DI]) {
    if (iVar5 != 0) {
      uVar4 = 0xffff;
    }
    uVar1 = *(uint *)(unaff_SI + 6);
    if (uVar1 <= uVar4 && uVar4 - uVar1 != 0) {
      uVar4 = (uVar4 - uVar1 >> 2) + 1;
      iVar5 = uVar4 + uVar1;
      if (CARRY2(uVar4,uVar1)) {
        iVar5 = -1;
      }
      *(int *)(unaff_SI + 6) = iVar5;
    }
  }
  return;
}



/* 1000:3d2c  FUN_1000_3d2c  50 bytes, 3 callers */

undefined4 __cdecl16near FUN_1000_3d2c(void)

{
  byte bVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  bVar1 = *(byte *)(unaff_SI + 1);
  iVar2 = 4;
  do {
    FUN_1000_9ad3();
    FUN_1000_ad80();
    if (!(bool)in_CF) {
      FUN_1000_9b34();
      FUN_1000_3d5e();
      if (!(bool)in_CF) {
        *(byte *)(unaff_SI + 1) = bVar1 & 7;
        break;
      }
    }
    in_CF = 0xfd < bVar1;
    bVar1 = bVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:3d5e  FUN_1000_3d5e  195 bytes, 6 callers */

undefined4 __cdecl16near FUN_1000_3d5e(void)

{
  uint *puVar1;
  int iVar2;
  undefined2 in_AX;
  undefined2 uVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  undefined2 in_DX;
  uint extraout_DX;
  uint uVar7;
  uint uVar8;
  uint extraout_DX_00;
  int in_BX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  
  bVar6 = ((undefined *)&DAT_0000_d27e)[unaff_DI] - 0x14;
  bVar5 = ((undefined *)&DAT_0000_d27e)[in_BX] - 0x14;
  iVar2 = *(int *)((undefined *)&DAT_0000_e47e + in_BX);
  if (iVar2 != 0) {
    uVar3 = FUN_1000_a61d();
    if ((*(char *)(iVar2 + 0xc) != (char)uVar3) &&
       (*(char *)(iVar2 + 0xc) != (char)((uint)uVar3 >> 8))) {
      if (*(char *)(iVar2 + 0xb) == -1) {
        *(byte *)(iVar2 + 1) = *(char *)(unaff_SI + 1) + 4U & 6;
      }
      uVar7 = *(uint *)(iVar2 + 6);
      uVar8 = *(uint *)(unaff_SI + 6);
      if (bVar6 < 4) {
        uVar8 = (uVar8 >> 2) + 1;
        puVar1 = (uint *)(iVar2 + 6);
        uVar7 = *puVar1;
        *puVar1 = *puVar1 - uVar8;
        if (uVar7 < uVar8 || *puVar1 == 0) {
          FUN_1000_4924();
        }
      }
      else if (bVar5 < 4) {
        uVar4 = (uVar8 >> 3) + 1;
        puVar1 = (uint *)(iVar2 + 6);
        uVar8 = *puVar1;
        *puVar1 = *puVar1 - uVar4;
        if (uVar8 < uVar4 || *puVar1 == 0) {
          FUN_1000_4924();
          uVar7 = extraout_DX_00;
        }
        uVar8 = (uVar7 >> 3) + 1;
        puVar1 = (uint *)(unaff_SI + 6);
        uVar7 = *puVar1;
        *puVar1 = *puVar1 - uVar8;
        if (uVar7 < uVar8 || *puVar1 == 0) {
          FUN_1000_4924();
        }
      }
      else {
        uVar4 = (uVar8 >> 3) + 1;
        puVar1 = (uint *)(iVar2 + 6);
        uVar8 = *puVar1;
        *puVar1 = *puVar1 - uVar4;
        if (uVar8 < uVar4 || *puVar1 == 0) {
          FUN_1000_4924();
          uVar7 = extraout_DX;
        }
        uVar8 = (uVar7 >> 4) + 1;
        puVar1 = (uint *)(unaff_SI + 6);
        uVar7 = *puVar1;
        *puVar1 = *puVar1 - uVar8;
        if (uVar7 < uVar8 || *puVar1 == 0) {
          FUN_1000_4924();
        }
      }
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:3e21  FUN_1000_3e21  119 bytes, 5 callers */

undefined4 __cdecl16near FUN_1000_3e21(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined2 in_AX;
  int iVar4;
  undefined2 in_DX;
  uint uVar5;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  pbVar3 = *(byte **)((undefined *)&DAT_0000_e47e + in_BX);
  if ((((pbVar3 == (byte *)0x0) || (*(byte *)(unaff_SI + 0xc) != pbVar3[0xc])) ||
      ((*pbVar3 & 2) != 0)) ||
     (iVar4 = *(uint *)(unaff_SI + 6) + *(uint *)(pbVar3 + 6),
     CARRY2(*(uint *)(unaff_SI + 6),*(uint *)(pbVar3 + 6)))) goto LAB_1000_3e94;
  bVar1 = *(byte *)(unaff_SI + 10);
  bVar2 = pbVar3[10];
  if ((bVar1 & 0x20) == 0) {
    if ((bVar2 & 0x20) == 0) {
      if ((CONCAT11(bVar1,bVar2) & 0x1010) != 0) {
        if ((bVar2 & 0x10) == 0) goto LAB_1000_3e86;
        if ((bVar1 & 0x10) == 0) goto LAB_1000_3e7d;
      }
      uVar5 = CONCAT11(bVar1,bVar2) & 0xf0f;
      if (uVar5 != 0x303) {
        if ((char)(uVar5 >> 8) == '\x03') goto LAB_1000_3e7d;
        if ((char)uVar5 == '\x03') goto LAB_1000_3e86;
      }
      if (*(uint *)(pbVar3 + 6) <= *(uint *)(unaff_SI + 6)) goto LAB_1000_3e86;
    }
LAB_1000_3e7d:
    *(int *)(pbVar3 + 6) = iVar4;
    FUN_1000_a9ca();
  }
  else {
LAB_1000_3e86:
    *(int *)(unaff_SI + 6) = iVar4;
    FUN_1000_a9ca();
  }
LAB_1000_3e94:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:3e98  FUN_1000_3e98  47 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_3e98(void)

{
  uint *puVar1;
  uint uVar2;
  byte bVar3;
  undefined2 in_AX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  
  bVar3 = ((undefined *)&DAT_0000_d27e)[unaff_DI] - 8;
  if (((7 < (byte)((undefined *)&DAT_0000_d27e)[unaff_DI]) && (bVar3 < 4)) &&
     (bVar3 == *(byte *)(unaff_SI + 0xc))) {
    bVar3 = ((undefined *)&DAT_0000_d27f)[unaff_DI];
    puVar1 = (uint *)(unaff_SI + 6);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + (uint)bVar3;
    if (CARRY2(uVar2,(uint)bVar3)) {
      *(undefined2 *)(unaff_SI + 6) = 0xffff;
    }
    *(undefined **)((undefined *)&DAT_0000_d27e + unaff_DI) = (undefined *)&DAT_0000_6400;
    return in_AX;
  }
  return in_AX;
}



/* 1000:3ec7  FUN_1000_3ec7  99 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_3ec7(void)

{
  uint *puVar1;
  uint uVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined2 in_AX;
  undefined2 in_DX;
  uint uVar5;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  bool bVar6;
  
  if ((((undefined *)&DAT_0000_d27e)[unaff_DI] == '\0') ||
     ((byte)(((undefined *)&DAT_0000_d27e)[unaff_DI] - 0xc) < 4)) {
    bVar3 = FUN_1000_a61d();
    bVar6 = 0xf7 < bVar3;
    uVar4 = FUN_1000_ae9e();
    if (!bVar6) {
      bVar6 = false;
      FUN_1000_abc7();
      if (!bVar6) {
        uVar5 = *(uint *)(unaff_SI + 6);
        if (200 < uVar5) {
          uVar5 = 200;
        }
        *(uint *)((undefined *)&DAT_0000_d27e + *(int *)(unaff_SI + 4)) =
             CONCAT11(((byte)uVar5 >> 1) + 1,uVar4);
        puVar1 = (uint *)(unaff_SI + 6);
        uVar2 = *puVar1;
        *puVar1 = *puVar1 - uVar5;
        if (uVar2 < uVar5 || *puVar1 == 0) {
          FUN_1000_a9ca();
        }
        return CONCAT22(in_DX,in_AX);
      }
      return CONCAT22(in_DX,in_AX);
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:3f2a  FUN_1000_3f2a  56 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_3f2a(void)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  
  if (3 < (byte)(((undefined *)&DAT_0000_d27e)[unaff_DI] - 1)) {
    return CONCAT22(in_DX,in_AX);
  }
  bVar3 = (byte)(*(uint *)(unaff_SI + 6) >> 1);
  if ((byte)(*(uint *)(unaff_SI + 6) >> 9) == 0) {
    pbVar1 = (undefined *)&DAT_0000_d27f + unaff_DI;
    bVar2 = *pbVar1;
    *pbVar1 = *pbVar1 - bVar3;
    if (bVar3 <= bVar2 && *pbVar1 != 0) {
      return CONCAT22(in_DX,in_AX);
    }
  }
  *(undefined **)((undefined *)&DAT_0000_d27e + unaff_DI) = (undefined *)&DAT_0000_6400;
  FUN_1000_a7e9();
  return CONCAT22(in_DX,in_AX);
}



/* 1000:3f62  FUN_1000_3f62  222 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_3f62(void)

{
  undefined2 in_AX;
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined2 in_DX;
  uint uVar4;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  bool bVar5;
  
  iVar1 = FUN_1000_aa93();
  if (iVar1 == 0) {
    FUN_1000_4947();
    return CONCAT22(in_DX,in_AX);
  }
  if (iVar1 != 1) {
LAB_1000_402c:
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_9b34();
  cVar3 = ((undefined *)&DAT_0000_d27e)[in_BX];
  if (cVar3 == '{') {
    uVar4 = -((byte)((undefined *)&DAT_0000_d27f)[in_BX] - 0xff);
    uVar2 = *(uint *)(unaff_SI + 6) >> 4;
    if (uVar4 < uVar2) {
      uVar2 = uVar4;
    }
    bVar5 = (uVar2 >> 1 & 1) != 0;
    FUN_1000_abc7();
    if (!bVar5) {
      ((undefined *)&DAT_0000_d27f)[in_BX] = ((undefined *)&DAT_0000_d27f)[in_BX] + (char)uVar2;
      goto LAB_1000_4011;
    }
  }
  else {
    if (cVar3 != '\0') {
      if (3 < (byte)(cVar3 - 0xcU)) goto LAB_1000_402c;
      if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) != 0) goto LAB_1000_4025;
    }
    uVar4 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] + 0xff;
    uVar2 = *(uint *)(unaff_SI + 6) >> 4;
    if (uVar4 < uVar2) {
      uVar2 = uVar4;
    }
    bVar5 = (uVar2 >> 1 & 1) != 0;
    FUN_1000_abc7();
    if (!bVar5) {
      iVar1 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] - uVar2;
      cVar3 = (char)iVar1;
      if (uVar2 <= (byte)((undefined *)&DAT_0000_d27f)[in_BX] && iVar1 != 0) {
        ((undefined *)&DAT_0000_d27f)[in_BX] = cVar3;
        FUN_1000_9ae1();
        return CONCAT22(in_DX,in_AX);
      }
      *(uint *)((undefined *)&DAT_0000_d27e + in_BX) = CONCAT11(-cVar3,0x7b);
      FUN_1000_bcf4();
LAB_1000_4011:
      FUN_1000_9ae1();
      return CONCAT22(in_DX,in_AX);
    }
  }
LAB_1000_4025:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4040  FUN_1000_4040  291 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_4040(void)

{
  undefined2 in_AX;
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined2 in_DX;
  char cVar5;
  uint uVar4;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  bool bVar6;
  
  iVar1 = FUN_1000_aa93();
  if (iVar1 == 0) {
    FUN_1000_4947();
    return CONCAT22(in_DX,in_AX);
  }
  if (iVar1 == 1) {
    cVar5 = (char)((uint)*(undefined2 *)(unaff_SI + 8) >> 8);
    cVar3 = (char)*(undefined2 *)(unaff_SI + 8);
    if ((((cVar5 != '\0') && (cVar5 != '/')) && (cVar3 != '\0')) && (cVar3 != '/')) {
      FUN_1000_9b34();
      if (((undefined *)&DAT_0000_d27e)[in_BX] == 'z') {
        uVar4 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] + 0xff;
        uVar2 = *(uint *)(unaff_SI + 6) >> 4;
        if (uVar4 < uVar2) {
          uVar2 = uVar4;
        }
        bVar6 = CARRY2(uVar2,uVar2);
        FUN_1000_abc7();
        if (!bVar6) {
          iVar1 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] - uVar2;
          cVar3 = (char)iVar1;
          if ((byte)((undefined *)&DAT_0000_d27f)[in_BX] < uVar2 || iVar1 == 0) {
            *(uint *)((undefined *)&DAT_0000_d27e + in_BX) = CONCAT11(-cVar3,0x20);
            FUN_1000_a7e9();
            FUN_1000_484a();
LAB_1000_412f:
            FUN_1000_9ae1();
            return CONCAT22(in_DX,in_AX);
          }
          ((undefined *)&DAT_0000_d27f)[in_BX] = cVar3;
LAB_1000_4139:
          FUN_1000_9ae1();
          return CONCAT22(in_DX,in_AX);
        }
      }
      else {
        if (0x2f < (byte)(((undefined *)&DAT_0000_d27e)[in_BX] - 0x30)) goto LAB_1000_414d;
        uVar4 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] + 1;
        uVar2 = *(uint *)(unaff_SI + 6) >> 4;
        if (uVar4 < uVar2) {
          uVar2 = uVar4;
        }
        bVar6 = false;
        if (*(int *)0x347e == 0) {
          bVar6 = (long)(int)((long)(int)uVar2 * 0x1e) != (long)(int)uVar2 * 0x1e;
        }
        FUN_1000_abc7();
        if (!bVar6) {
          cVar3 = ((undefined *)&DAT_0000_d27f)[in_BX] - (char)uVar2;
          if ((byte)((undefined *)&DAT_0000_d27f)[in_BX] < uVar2) {
            *(uint *)((undefined *)&DAT_0000_d27e + in_BX) = CONCAT11(-cVar3,0x20);
            FUN_1000_a7e9();
            FUN_1000_484a();
            goto LAB_1000_412f;
          }
          ((undefined *)&DAT_0000_d27f)[in_BX] = cVar3;
          goto LAB_1000_4139;
        }
      }
      return CONCAT22(in_DX,in_AX);
    }
  }
LAB_1000_414d:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4163  FUN_1000_4163  82 bytes, 5 callers */

undefined2 __cdecl16near FUN_1000_4163(void)

{
  uint *puVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  undefined2 in_AX;
  undefined2 uVar5;
  byte bVar6;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  bVar6 = ((undefined *)&DAT_0000_d27e)[in_BX] - 8;
  if (((bVar6 < 4) && (uVar5 = FUN_1000_a61d(), bVar6 != (byte)uVar5)) &&
     (bVar6 != (byte)((uint)uVar5 >> 8))) {
    bVar6 = ((undefined *)&DAT_0000_d27f)[in_BX];
    uVar5 = *(undefined2 *)(unaff_SI + 6);
    puVar1 = (uint *)(unaff_SI + 6);
    uVar4 = *puVar1;
    *puVar1 = *puVar1 - (uint)bVar6;
    if (uVar4 < bVar6 || *puVar1 == 0) {
      FUN_1000_4924();
    }
    bVar6 = (byte)uVar5;
    if ((char)((uint)uVar5 >> 8) == '\0') {
      pbVar2 = (undefined *)&DAT_0000_d27f + in_BX;
      bVar3 = *pbVar2;
      *pbVar2 = *pbVar2 - bVar6;
      if (bVar6 <= bVar3 && *pbVar2 != 0) {
        return in_AX;
      }
    }
    *(undefined **)((undefined *)&DAT_0000_d27e + in_BX) = (undefined *)&DAT_0000_6400;
  }
  return in_AX;
}



/* 1000:41b5  FUN_1000_41b5  39 bytes, 4 callers */

undefined2 __cdecl16near FUN_1000_41b5(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  byte bVar2;
  int unaff_DI;
  undefined2 unaff_DS;
  
  bVar2 = ((undefined *)&DAT_0000_d27e)[unaff_DI] - 0xc;
  if (bVar2 < 4) {
    uVar1 = FUN_1000_a61d();
    if ((bVar2 != (byte)uVar1) && (bVar2 != (byte)((uint)uVar1 >> 8))) {
      *(undefined **)((undefined *)&DAT_0000_d27e + unaff_DI) = (undefined *)&DAT_0000_6400;
    }
  }
  return in_AX;
}



/* 1000:41dc  FUN_1000_41dc  107 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_41dc(void)

{
  undefined2 in_AX;
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined2 in_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  iVar1 = FUN_1000_aa93();
  if (iVar1 == 0) {
    FUN_1000_4947();
    return CONCAT22(in_DX,in_AX);
  }
  if (iVar1 == 1) {
    FUN_1000_9b34();
    if (((undefined *)&DAT_0000_d27e)[in_BX] == '{') {
      uVar2 = *(uint *)(unaff_SI + 6) >> 5;
      iVar1 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] - uVar2;
      cVar3 = (char)iVar1;
      if (uVar2 <= (byte)((undefined *)&DAT_0000_d27f)[in_BX] && iVar1 != 0) {
        ((undefined *)&DAT_0000_d27f)[in_BX] = cVar3;
        FUN_1000_9ae1();
        return CONCAT22(in_DX,in_AX);
      }
      *(uint *)((undefined *)&DAT_0000_d27e + in_BX) = (uint)(byte)-cVar3 << 8;
      FUN_1000_484a();
      FUN_1000_9ae1();
      return CONCAT22(in_DX,in_AX);
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4247  FUN_1000_4247  189 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_4247(void)

{
  undefined2 in_AX;
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined2 in_DX;
  uint uVar4;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  iVar1 = FUN_1000_aa93();
  if (iVar1 == 0) {
    FUN_1000_4947();
    return CONCAT22(in_DX,in_AX);
  }
  if (iVar1 == 1) {
    FUN_1000_9b34();
    if (((undefined *)&DAT_0000_d27e)[in_BX] == 'z') {
      uVar2 = (uint)(byte)((undefined *)&DAT_0000_d27f)[in_BX] + (*(uint *)(unaff_SI + 6) >> 5);
      if (0xff < uVar2) {
        uVar2 = 0xff;
      }
      ((undefined *)&DAT_0000_d27f)[in_BX] = (char)uVar2;
    }
    else {
      if (0xf < (byte)(((undefined *)&DAT_0000_d27e)[in_BX] - 0x20)) goto LAB_1000_42f4;
      uVar4 = (uint)(byte)((undefined *)&DAT_0000_d27f)[in_BX];
      uVar2 = *(uint *)(unaff_SI + 6) >> 5;
      if (uVar4 + 0xff < uVar2) {
        uVar2 = uVar4 + 0xff;
      }
      cVar3 = (char)(uVar4 - uVar2);
      if (uVar2 <= uVar4 && uVar4 - uVar2 != 0) {
        ((undefined *)&DAT_0000_d27f)[in_BX] = cVar3;
        FUN_1000_9ae1();
        return CONCAT22(in_DX,in_AX);
      }
      *(uint *)((undefined *)&DAT_0000_d27e + in_BX) = CONCAT11(-cVar3,0x7a);
      FUN_1000_bcf4();
      if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) != 0) {
        FUN_1000_4924();
      }
    }
    FUN_1000_9ae1();
    return CONCAT22(in_DX,in_AX);
  }
LAB_1000_42f4:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4304  FUN_1000_4304  112 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_4304(void)

{
  undefined2 in_AX;
  int iVar1;
  uint uVar2;
  undefined2 in_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  iVar1 = FUN_1000_aa93();
  if (iVar1 == 0) {
    FUN_1000_4947();
    return CONCAT22(in_DX,in_AX);
  }
  if (iVar1 == 1) {
    FUN_1000_9b34();
    if (((undefined *)&DAT_0000_d27e)[in_BX] == '\x05') {
      if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0) {
        uVar2 = *(uint *)(unaff_SI + 6) >> 3;
        iVar1 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] - uVar2;
        if ((byte)((undefined *)&DAT_0000_d27f)[in_BX] < uVar2 || iVar1 == 0) {
          *(undefined2 *)((undefined *)&DAT_0000_d27e + in_BX) = 0x60;
          FUN_1000_a7e9();
          FUN_1000_484a();
          FUN_1000_9ae1();
          return CONCAT22(in_DX,in_AX);
        }
        ((undefined *)&DAT_0000_d27f)[in_BX] = (char)iVar1;
      }
      FUN_1000_9ae1();
      return CONCAT22(in_DX,in_AX);
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4374  FUN_1000_4374  172 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_4374(void)

{
  byte bVar1;
  undefined1 uVar2;
  uint in_AX;
  uint uVar3;
  uint uVar4;
  undefined1 in_CL;
  undefined2 in_DX;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar8;
  undefined4 uVar9;
  
  FUN_1000_4814();
  uVar9 = FUN_1000_b876();
  uVar5 = (undefined2)((ulong)uVar9 >> 0x10);
  uVar3 = (uint)uVar9;
  if ((bool)in_CF) {
    uVar3 = 0x3fff;
  }
  else {
    bVar1 = ((undefined *)&DAT_0000_d27e)[unaff_DI];
    in_CL = 5;
    if ((((bVar1 != 0) && ((bVar1 < 0xc || (0xf < bVar1)))) &&
        ((in_CL = 4, bVar1 < 8 || (0xb < bVar1)))) && (in_CL = 0xb, bVar1 != 5)) {
      in_CL = 8;
    }
  }
  uVar6 = uVar5;
  uVar9 = FUN_1000_baaf(uVar5);
  uVar7 = uVar6;
  uVar4 = FUN_1000_bb70((int)((ulong)uVar9 >> 0x10));
  uVar2 = 7;
  if ((uint)uVar9 <= uVar4) {
    uVar2 = 9;
    uVar4 = (uint)uVar9;
    uVar7 = uVar6;
  }
  if (uVar3 <= uVar4) {
    uVar4 = uVar3;
    uVar7 = uVar5;
    uVar2 = in_CL;
  }
  if ((uVar4 < in_AX) &&
     (uVar8 = *(uint *)(unaff_SI + 6) == uVar4 * 2, uVar4 * 2 <= *(uint *)(unaff_SI + 6))) {
    *(undefined1 *)(unaff_SI + 10) = uVar2;
    *(undefined2 *)(unaff_SI + 8) = uVar7;
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    FUN_1000_b78c();
    uVar2 = FUN_1000_c0bd();
    if ((!(bool)uVar8) &&
       (*(undefined1 *)(unaff_SI + 0xb) = uVar2, *(char *)(unaff_SI + 10) == '\v')) {
      FUN_1000_c2e7();
    }
    return CONCAT22(in_DX,in_AX);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4420  FUN_1000_4420  119 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_4420(void)

{
  byte bVar1;
  undefined1 uVar2;
  uint in_AX;
  undefined2 in_DX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar3;
  undefined4 uVar4;
  
  FUN_1000_4814();
  uVar4 = FUN_1000_b876();
  if (((!(bool)in_CF) && ((uint)uVar4 < in_AX)) && ((uint)uVar4 * 2 <= *(uint *)(unaff_SI + 6))) {
    bVar1 = ((undefined *)&DAT_0000_d27e)[unaff_DI];
    uVar2 = 5;
    uVar3 = bVar1 == 0;
    if ((((!(bool)uVar3) && ((bVar1 < 0xc || (uVar3 = bVar1 == 0x10, 0xf < bVar1)))) &&
        ((uVar2 = 4, bVar1 < 8 || (uVar3 = bVar1 == 0xc, 0xb < bVar1)))) &&
       ((uVar2 = 8, bVar1 == 0 || (uVar3 = bVar1 == 5, 4 < bVar1)))) {
      uVar2 = 0xb;
      uVar3 = bVar1 == 5;
      if (!(bool)uVar3) goto LAB_1000_4492;
    }
    *(undefined1 *)(unaff_SI + 10) = uVar2;
    *(undefined2 *)(unaff_SI + 8) = (int)((ulong)uVar4 >> 0x10);
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    FUN_1000_b78c();
    uVar2 = FUN_1000_c0bd();
    if ((!(bool)uVar3) &&
       (*(undefined1 *)(unaff_SI + 0xb) = uVar2, *(char *)(unaff_SI + 10) == '\v')) {
      FUN_1000_c2e7();
    }
    return CONCAT22(in_DX,in_AX);
  }
LAB_1000_4492:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4497  FUN_1000_4497  69 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_4497(void)

{
  uint uVar1;
  undefined1 uVar2;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 uVar3;
  undefined4 uVar4;
  
  uVar3 = false;
  FUN_1000_b4d8();
  if (!(bool)uVar3) {
    FUN_1000_4814();
    uVar4 = FUN_1000_b9a7();
    if ((!(bool)uVar3) &&
       (uVar1 = (int)uVar4 * 2, uVar3 = *(uint *)(unaff_SI + 6) == uVar1,
       uVar1 <= *(uint *)(unaff_SI + 6))) {
      *(undefined2 *)(unaff_SI + 8) = (int)((ulong)uVar4 >> 0x10);
      FUN_1000_b78c();
      uVar2 = FUN_1000_c0bd();
      if (!(bool)uVar3) {
        *(undefined1 *)(unaff_SI + 0xb) = uVar2;
      }
      *(byte *)(unaff_SI + 10) = *(byte *)(unaff_SI + 10) & 0xd0 | 5;
      *(undefined1 *)(unaff_SI + 0xf) = 4;
      return CONCAT22(in_DX,in_AX);
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:44dc  FUN_1000_44dc  58 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_44dc(void)

{
  uint uVar1;
  undefined1 uVar2;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar3;
  undefined4 uVar4;
  
  FUN_1000_4814();
  uVar4 = FUN_1000_ba12();
  if ((!(bool)in_CF) &&
     (uVar1 = (int)uVar4 * 2, uVar3 = *(uint *)(unaff_SI + 6) == uVar1,
     uVar1 <= *(uint *)(unaff_SI + 6))) {
    *(undefined2 *)(unaff_SI + 8) = (int)((ulong)uVar4 >> 0x10);
    FUN_1000_b78c();
    uVar2 = FUN_1000_c0bd();
    if (!(bool)uVar3) {
      *(undefined1 *)(unaff_SI + 0xb) = uVar2;
    }
    *(byte *)(unaff_SI + 10) = *(byte *)(unaff_SI + 10) & 0xd0 | 4;
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    return CONCAT22(in_DX,in_AX);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4516  FUN_1000_4516  67 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_4516(void)

{
  uint uVar1;
  undefined1 uVar2;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 uVar3;
  undefined4 uVar4;
  
  uVar3 = *(uint *)(unaff_SI + 6) < 0x14;
  if (!(bool)uVar3) {
    FUN_1000_4814();
    uVar4 = FUN_1000_ba67();
    if ((!(bool)uVar3) &&
       (uVar1 = (int)uVar4 * 2, uVar3 = *(uint *)(unaff_SI + 6) == uVar1,
       uVar1 <= *(uint *)(unaff_SI + 6))) {
      *(undefined2 *)(unaff_SI + 8) = (int)((ulong)uVar4 >> 0x10);
      FUN_1000_b78c();
      uVar2 = FUN_1000_c0bd();
      if (!(bool)uVar3) {
        *(undefined1 *)(unaff_SI + 0xb) = uVar2;
      }
      *(byte *)(unaff_SI + 10) = *(byte *)(unaff_SI + 10) & 0xd0 | 8;
      *(undefined1 *)(unaff_SI + 0xf) = 4;
      return CONCAT22(in_DX,in_AX);
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4559  FUN_1000_4559  53 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_4559(void)

{
  uint uVar1;
  undefined1 uVar2;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar3;
  undefined4 uVar4;
  
  FUN_1000_4814();
  uVar4 = FUN_1000_bbed();
  if ((!(bool)in_CF) &&
     (uVar1 = (int)uVar4 * 2, uVar3 = *(uint *)(unaff_SI + 6) == uVar1,
     uVar1 <= *(uint *)(unaff_SI + 6))) {
    *(undefined2 *)(unaff_SI + 8) = (int)((ulong)uVar4 >> 0x10);
    FUN_1000_b78c();
    uVar2 = FUN_1000_c0bd();
    if (!(bool)uVar3) {
      *(undefined1 *)(unaff_SI + 0xb) = uVar2;
    }
    *(undefined1 *)(unaff_SI + 10) = 3;
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    return CONCAT22(in_DX,in_AX);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:458e  FUN_1000_458e  89 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_458e(void)

{
  uint uVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 uVar4;
  undefined4 uVar5;
  
  bVar2 = *(char *)(unaff_SI + 0xc) + 8;
  uVar4 = bVar2 < (byte)((undefined *)&DAT_0000_d27e)[*(int *)(unaff_SI + 4)];
  if (bVar2 == ((undefined *)&DAT_0000_d27e)[*(int *)(unaff_SI + 4)]) {
    *(undefined1 *)(unaff_SI + 0xb) = 0xff;
    *(undefined2 *)(unaff_SI + 8) = *(undefined2 *)(unaff_SI + 2);
    *(undefined1 *)(unaff_SI + 10) = 2;
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_4814();
  uVar5 = FUN_1000_bc56();
  if ((!(bool)uVar4) &&
     (uVar1 = (int)uVar5 * 2, uVar4 = *(uint *)(unaff_SI + 6) == uVar1,
     uVar1 <= *(uint *)(unaff_SI + 6))) {
    *(undefined2 *)(unaff_SI + 8) = (int)((ulong)uVar5 >> 0x10);
    FUN_1000_b78c();
    uVar3 = FUN_1000_c0bd();
    if (!(bool)uVar4) {
      *(undefined1 *)(unaff_SI + 0xb) = uVar3;
    }
    *(undefined1 *)(unaff_SI + 10) = 2;
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    return CONCAT22(in_DX,in_AX);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:45e7  FUN_1000_45e7  55 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_45e7(void)

{
  undefined1 uVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar3;
  
  FUN_1000_4814();
  iVar2 = FUN_1000_baaf();
  if ((!(bool)in_CF) &&
     (uVar3 = *(uint *)(unaff_SI + 6) == iVar2 * 2, (uint)(iVar2 * 2) <= *(uint *)(unaff_SI + 6))) {
    *(undefined2 *)(unaff_SI + 8) = in_BX;
    FUN_1000_b78c();
    uVar1 = FUN_1000_c0bd();
    if (!(bool)uVar3) {
      *(undefined1 *)(unaff_SI + 0xb) = uVar1;
    }
    *(byte *)(unaff_SI + 10) = *(byte *)(unaff_SI + 10) & 0xd0 | 9;
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    return CONCAT22(in_DX,in_AX);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:461e  FUN_1000_461e  58 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_461e(void)

{
  uint uVar1;
  undefined1 uVar2;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar3;
  undefined4 uVar4;
  
  FUN_1000_4814();
  uVar4 = FUN_1000_bb2c();
  if ((!(bool)in_CF) &&
     (uVar1 = (int)uVar4 * 2, uVar3 = *(uint *)(unaff_SI + 6) == uVar1,
     uVar1 <= *(uint *)(unaff_SI + 6))) {
    *(undefined2 *)(unaff_SI + 8) = (int)((ulong)uVar4 >> 0x10);
    FUN_1000_b78c();
    uVar2 = FUN_1000_c0bd();
    if (!(bool)uVar3) {
      *(undefined1 *)(unaff_SI + 0xb) = uVar2;
      FUN_1000_c2e7();
    }
    *(byte *)(unaff_SI + 10) = *(byte *)(unaff_SI + 10) & 0xd0 | 0xb;
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    return CONCAT22(in_DX,in_AX);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4658  FUN_1000_4658  123 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_4658(void)

{
  undefined2 in_AX;
  int iVar1;
  int iVar2;
  undefined2 in_DX;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  bool bVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
  bVar3 = false;
  FUN_1000_b4d8();
  if (!bVar3) {
    FUN_1000_4814();
    iVar2 = 0x10;
    do {
      FUN_1000_9a36();
      FUN_1000_9b34();
      bVar3 = false;
      if (((undefined *)&DAT_0000_d27e)[in_BX] == '\0') {
        iVar1 = FUN_1000_aac4();
        if (bVar3) break;
        uVar4 = *(uint *)(unaff_SI + 6) < (uint)(iVar1 * 2);
        uVar5 = *(uint *)(unaff_SI + 6) == iVar1 * 2;
        if ((bool)uVar4) break;
        FUN_1000_a61d();
        FUN_1000_ae9e();
        if (!(bool)uVar4) {
          *(undefined2 *)(unaff_SI + 8) = extraout_DX;
          FUN_1000_b78c();
          uVar4 = FUN_1000_c0bd();
          if (!(bool)uVar5) {
            *(undefined1 *)(unaff_SI + 0xb) = uVar4;
          }
          *(byte *)(unaff_SI + 10) = *(byte *)(unaff_SI + 10) & 0xd0 | 5;
          *(undefined1 *)(unaff_SI + 0xf) = 4;
          return CONCAT22(in_DX,in_AX);
        }
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:46d3  FUN_1000_46d3  278 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_46d3(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  byte bVar3;
  uint uVar2;
  int iVar4;
  char cVar5;
  undefined2 in_DX;
  uint uVar6;
  int unaff_SI;
  byte *pbVar7;
  byte *unaff_DI;
  undefined2 unaff_DS;
  bool bVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  
  FUN_1000_4814();
  uVar1 = FUN_1000_a61d();
  pbVar7 = (byte *)&DAT_0000_c800;
  iVar4 = 0x40;
  uVar6 = 0xffff;
  do {
    if ((((((*pbVar7 & 0x80) == 0) && ((pbVar7[10] & 0x20) != 0)) && ((byte)uVar1 != pbVar7[0xc]))
        && ((bVar3 = (byte)((uint)uVar1 >> 8), bVar8 = bVar3 < pbVar7[0xc], bVar3 != pbVar7[0xc] &&
            (uVar2 = FUN_1000_aaae(), !bVar8)))) && (uVar2 < uVar6)) {
      uVar6 = uVar2;
      unaff_DI = pbVar7;
    }
    pbVar7 = pbVar7 + 0x10;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if ((uVar6 < 0x1f0) && (uVar6 * 2 <= *(uint *)(unaff_SI + 6))) {
    if ((byte)(unaff_DI[0xc] + 0x14) == ((undefined *)&DAT_0000_d27e)[*(int *)(unaff_DI + 4)]) {
      uVar6 = *(uint *)(unaff_DI + 6);
      if (((char)(((int)uVar6 < 0) + CARRY2(uVar6 * 2,uVar6)) != '\0') ||
         (uVar9 = uVar6 * 3 == *(uint *)(unaff_SI + 6), *(uint *)(unaff_SI + 6) <= uVar6 * 3)) {
        if ((uVar6 >> 1) + (uVar6 >> 2) < *(uint *)(unaff_SI + 6)) {
          uVar1 = *(undefined2 *)
                   (*(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_DI[0xc] * 2) + 2);
          cVar5 = (char)uVar1 + '\x02';
          uVar10 = cVar5 == '\0';
          *(undefined2 *)(unaff_SI + 8) = CONCAT11((char)((uint)uVar1 >> 8),cVar5);
          FUN_1000_b78c();
          uVar9 = FUN_1000_c0bd();
          if (!(bool)uVar10) {
            *(undefined1 *)(unaff_SI + 0xb) = uVar9;
            *(undefined1 *)(unaff_SI + 10) = 2;
            *(undefined1 *)(unaff_SI + 0xf) = 4;
            return CONCAT22(in_DX,in_AX);
          }
        }
        goto LAB_1000_47e6;
      }
    }
    else {
      uVar9 = *(uint *)(unaff_DI + 6) == *(uint *)(unaff_SI + 6);
      if (*(uint *)(unaff_SI + 6) <= *(uint *)(unaff_DI + 6)) {
        uVar10 = unaff_DI[0xc] == 0;
        *(undefined2 *)(unaff_SI + 8) =
             *(undefined2 *)(*(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_DI[0xc] * 2) + 2);
        FUN_1000_b78c();
        uVar9 = FUN_1000_c0bd();
        if (!(bool)uVar10) {
          *(undefined1 *)(unaff_SI + 0xb) = uVar9;
          *(undefined1 *)(unaff_SI + 10) = 2;
          *(undefined1 *)(unaff_SI + 0xf) = 4;
          return CONCAT22(in_DX,in_AX);
        }
        goto LAB_1000_47e6;
      }
    }
    *(undefined2 *)(unaff_SI + 8) = *(undefined2 *)(unaff_DI + 8);
    FUN_1000_b78c();
    uVar10 = FUN_1000_c0bd();
    if (!(bool)uVar9) {
      *(undefined1 *)(unaff_SI + 0xb) = uVar10;
      *(undefined1 *)(unaff_SI + 10) = 1;
      *(undefined1 *)(unaff_SI + 0xf) = 4;
      return CONCAT22(in_DX,in_AX);
    }
  }
LAB_1000_47e6:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:47e9  FUN_1000_47e9  43 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_47e9(void)

{
  undefined1 uVar1;
  int in_AX;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_ZF;
  
  FUN_1000_4814();
  *(undefined2 *)(unaff_SI + 8) = *(undefined2 *)(in_AX + 2);
  FUN_1000_b78c();
  uVar1 = FUN_1000_c0bd();
  if (!(bool)in_ZF) {
    *(undefined1 *)(unaff_SI + 0xb) = uVar1;
    *(undefined1 *)(unaff_SI + 10) = 2;
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    return CONCAT22(in_DX,in_AX);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4814  FUN_1000_4814  54 bytes, 12 callers */

void __cdecl16near FUN_1000_4814(void)

{
  int in_DX;
  undefined2 extraout_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  *(undefined1 *)(unaff_SI + 0xb) = 0xff;
  if (in_DX != *(int *)0x32bb) {
    FUN_1000_bd1e();
    if (((*(int *)0x3bce == 0) || (9 < *(uint *)0x3bc2)) ||
       (*(char *)(unaff_SI + 0xc) == *(char *)0x3c00)) {
      FUN_1000_bd84();
    }
    else {
      FUN_1000_bd3b();
    }
    FUN_1000_be36();
    *(undefined2 *)0x32bb = extraout_DX;
  }
  return;
}



/* 1000:484a  FUN_1000_484a  55 bytes, 4 callers */

undefined4 __cdecl16near FUN_1000_484a(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined2 unaff_DS;
  undefined4 uVar4;
  
  uVar4 = FUN_1000_bcf4();
  pbVar3 = (byte *)&DAT_0000_c800;
  iVar2 = 0x40;
  bVar1 = *(byte *)0x3c00;
  do {
    if ((((*pbVar3 & 0x80) == 0) && (pbVar3[0xb] == 0xff)) &&
       ((pbVar3[10] == 0 || ((bVar1 != pbVar3[0xc] && (pbVar3[10] == 2)))))) {
      pbVar3[10] = 1;
    }
    pbVar3 = pbVar3 + 0x10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return uVar4;
}



/* 1000:4881  FUN_1000_4881  84 bytes, 3 callers */

void __cdecl16near FUN_1000_4881(void)

{
  byte bVar1;
  byte *unaff_SI;
  undefined2 unaff_DS;
  bool bVar2;
  undefined1 uVar3;
  
  if (*(byte *)0x3c00 == unaff_SI[0xc]) {
    uVar3 = 0;
    if (*(int *)0x3480 != 0) {
      *unaff_SI = *unaff_SI | 1;
      return;
    }
  }
  else {
    bVar2 = *(uint *)(unaff_SI + 6) < 1000;
    if ((!bVar2) && (FUN_1000_46d3(), !bVar2)) {
      return;
    }
    bVar1 = FUN_1000_9a24();
    bVar2 = bVar1 < 0x5a;
    if (!bVar2) {
      FUN_1000_4374();
      if (!bVar2) {
        return;
      }
      FUN_1000_4559();
      if (!bVar2) {
        return;
      }
      FUN_1000_458e();
      return;
    }
    uVar3 = bVar1 < 0x50;
    if ((!(bool)uVar3) && (FUN_1000_4658(), !(bool)uVar3)) {
      return;
    }
  }
  FUN_1000_4420();
  if (((bool)uVar3) && (FUN_1000_4559(), (bool)uVar3)) {
    FUN_1000_458e();
    return;
  }
  return;
}



/* 1000:48df  FUN_1000_48df  69 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_48df(void)

{
  undefined1 uVar1;
  byte bVar2;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_ZF;
  
  FUN_1000_bd1e();
  FUN_1000_c316();
  FUN_1000_bd84();
  FUN_1000_be36();
  FUN_1000_b78c();
  uVar1 = FUN_1000_c0bd();
  if (!(bool)in_ZF) {
    *(undefined1 *)(unaff_SI + 0xb) = uVar1;
    bVar2 = *(byte *)(unaff_SI + 10) & 0xf;
    if ((((bVar2 == 10) || (bVar2 == 7)) || (bVar2 == 9)) || ((bVar2 == 0xb || (bVar2 == 6)))) {
      FUN_1000_c2e7();
    }
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    return CONCAT22(in_DX,in_AX);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4924  FUN_1000_4924  22 bytes, 4 callers */

void __cdecl16near FUN_1000_4924(void)

{
  byte in_AL;
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  if ((*unaff_SI & 2) == 0) {
    *unaff_SI = *unaff_SI | 2;
    unaff_SI[0xf] = in_AL;
    unaff_SI[0xe] = 0;
  }
  (unaff_SI + 6)[0] = 0;
  (unaff_SI + 6)[1] = 0;
  return;
}



/* 1000:493a  FUN_1000_493a  13 bytes, 1 callers */

void __cdecl16near FUN_1000_493a(void)

{
  int unaff_SI;
  undefined2 unaff_DS;
  
  *(char *)(unaff_SI + 0xe) = *(char *)(unaff_SI + 0xe) + '\x01';
  if (*(byte *)(unaff_SI + 0xe) < 4) {
    return;
  }
  FUN_1000_a9ca();
  return;
}



/* 1000:4947  FUN_1000_4947  95 bytes, 5 callers */

undefined4 __cdecl16near FUN_1000_4947(void)

{
  byte bVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool bVar3;
  
  bVar1 = *(byte *)(unaff_SI + 1);
  iVar2 = 4;
  while( true ) {
    FUN_1000_9ad3();
    FUN_1000_ad80();
    if ((!(bool)in_CF) && (FUN_1000_9b34(), (byte)((undefined *)&DAT_0000_d27e)[in_BX] < 0x30))
    break;
    in_CF = 0xfd < bVar1;
    bVar1 = bVar1 + 2;
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
LAB_1000_49a2:
      return CONCAT22(in_DX,in_AX);
    }
  }
  bVar3 = false;
  *(byte *)(unaff_SI + 1) = bVar1 & 7;
  FUN_1000_3d5e();
  if ((bVar3) &&
     (((FUN_1000_3e21(), bVar3 &&
       (bVar3 = false, *(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0)) &&
      (FUN_1000_4163(), bVar3)))) {
    *(int *)((undefined *)&DAT_0000_e47e + in_BX) = unaff_SI;
    LOCK();
    iVar2 = *(int *)(unaff_SI + 4);
    *(int *)(unaff_SI + 4) = in_BX;
    UNLOCK();
    *(undefined2 *)((undefined *)&DAT_0000_e47e + iVar2) = 0;
    *(undefined2 *)(unaff_SI + 2) = extraout_DX;
  }
  goto LAB_1000_49a2;
}



/* 1000:49bb  FUN_1000_49bb  146 bytes, 5 callers */

void FUN_1000_49bb(void)

{
  byte bVar1;
  byte bVar4;
  uint uVar2;
  uint uVar3;
  int unaff_SI;
  undefined2 *puVar5;
  undefined2 uVar6;
  char *unaff_DI;
  undefined2 unaff_DS;
  
  bVar4 = *(char *)(unaff_SI + 4) - 1;
  bVar1 = (byte)*(undefined2 *)unaff_DI;
  if (bVar4 < bVar1) {
    unaff_DI[0] = '\0';
    unaff_DI[1] = '\0';
  }
  else if ((bVar1 != bVar4) &&
          ((byte)(bVar1 - (char)((uint)*(undefined2 *)unaff_DI >> 8)) ==
           (byte)((*(byte *)(unaff_SI + 2) & 0x7f) - 1))) {
    *unaff_DI = *unaff_DI + -1;
  }
  uVar3 = *(uint *)(unaff_SI + 2);
  puVar5 = (undefined2 *)(unaff_SI + 6);
  bVar1 = unaff_DI[1];
  *(int *)0xc54c = bVar1 + 1;
  if (-1 < (char)uVar3) {
    puVar5 = puVar5 + bVar1;
  }
  FUN_1000_4b61();
  uVar2 = uVar3 & 0xff;
  if (-1 < (char)(byte)uVar3) {
    do {
      puVar5 = puVar5 + 1;
      FUN_1000_759b(puVar5);
      *(int *)0xc54c = *(int *)0xc54c + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    FUN_1000_9239();
    return;
  }
  uVar6 = *puVar5;
  uVar3 = (uint)((byte)uVar3 & 0x7f);
  do {
    FUN_1000_759b(uVar6);
    *(int *)0xc54c = *(int *)0xc54c + 1;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  FUN_1000_9239();
  return;
}



/* 1000:4a4d  FUN_1000_4a4d  52 bytes, 13 callers */

undefined4 __cdecl16near FUN_1000_4a4d(void)

{
  undefined2 in_AX;
  uint uVar1;
  undefined2 in_DX;
  int unaff_SI;
  int iVar2;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)(unaff_SI + 2);
  iVar2 = unaff_SI + 4;
  FUN_1000_4b61();
  uVar1 = uVar1 & 0xff;
  do {
    iVar2 = iVar2 + 2;
    FUN_1000_759b(iVar2);
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4a81  FUN_1000_4a81  100 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_4a81(void)

{
  undefined *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  uint in_CX;
  byte bVar3;
  undefined2 in_DX;
  int iVar4;
  int iVar5;
  uint in_BX;
  byte bVar8;
  int iVar6;
  int iVar7;
  undefined2 *puVar9;
  undefined *puVar10;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  bVar8 = (byte)(in_BX >> 8);
  bVar3 = (byte)(in_CX >> 8);
  if (*(int *)0x3288 == 0) {
    puVar10 = (undefined *)&DAT_0000_648c + (uint)bVar8 * 0x60 + (in_BX & 0xff) * 2;
    iVar7 = (in_CX & 0xff) + 1;
    iVar5 = (bVar3 + 1) * 2;
    iVar4 = iVar7 * 2;
    iVar6 = iVar4;
    do {
      for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        puVar1 = puVar10;
        puVar10 = puVar10 + 1;
        *puVar1 = 0xff;
      }
      puVar10 = puVar10 + iVar7 * -2 + 0x30;
      iVar5 = iVar5 + -1;
      iVar6 = iVar4;
    } while (iVar5 != 0);
  }
  else {
    puVar9 = (undefined2 *)((undefined *)&DAT_0000_648c + ((uint)bVar8 * 0x18 + (in_BX & 0xff)) * 2)
    ;
    iVar4 = bVar3 + 1;
    iVar6 = (in_CX & 0xff) + 1;
    iVar5 = iVar6;
    do {
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        puVar2 = puVar9;
        puVar9 = puVar9 + 1;
        *puVar2 = 0xffff;
      }
      puVar9 = puVar9 + (0x18 - iVar6);
      iVar4 = iVar4 + -1;
      iVar5 = iVar6;
    } while (iVar4 != 0);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4ae5  FUN_1000_4ae5  15 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_4ae5(void)

{
  undefined2 in_AX;
  int in_CX;
  undefined2 in_DX;
  int unaff_SI;
  
  do {
    unaff_SI = unaff_SI + 2;
    FUN_1000_759b(unaff_SI);
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4af4  FUN_1000_4af4  109 bytes, 1 callers */

void FUN_1000_4af4(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int unaff_SI;
  undefined2 *puVar4;
  undefined2 uVar5;
  int unaff_DI;
  undefined2 unaff_DS;
  
  uVar3 = *(uint *)(unaff_SI + 2);
  puVar4 = (undefined2 *)(unaff_SI + 6);
  bVar1 = *(byte *)(unaff_DI + 1);
  *(int *)0xc54c = bVar1 + 1;
  if (-1 < (char)uVar3) {
    puVar4 = puVar4 + bVar1;
  }
  FUN_1000_91ea();
  uVar2 = uVar3 & 0xff;
  if (-1 < (char)(byte)uVar3) {
    do {
      puVar4 = puVar4 + 1;
      FUN_1000_759b(puVar4);
      *(int *)0xc54c = *(int *)0xc54c + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    FUN_1000_9239();
    return;
  }
  uVar5 = *puVar4;
  uVar3 = (uint)((byte)uVar3 & 0x7f);
  do {
    FUN_1000_759b(uVar5);
    *(int *)0xc54c = *(int *)0xc54c + 1;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  FUN_1000_9239();
  return;
}



/* 1000:4b61  FUN_1000_4b61  136 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_4b61(void)

{
  undefined *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  uint in_CX;
  byte bVar3;
  undefined2 in_DX;
  int iVar4;
  int iVar5;
  uint in_BX;
  byte bVar8;
  int iVar6;
  int iVar7;
  undefined2 *puVar9;
  undefined *puVar10;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  bVar8 = (byte)(in_BX >> 8);
  bVar3 = (byte)(in_CX >> 8);
  if (*(int *)0x3288 == 0) {
    puVar10 = (undefined *)&DAT_0000_648c + (uint)bVar8 * 0x60 + (in_BX & 0xff) * 2;
    iVar7 = (in_CX & 0xff) + 1;
    iVar5 = (bVar3 + 1) * 2;
    iVar4 = iVar7 * 2;
    iVar6 = iVar4;
    do {
      for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        puVar1 = puVar10;
        puVar10 = puVar10 + 1;
        *puVar1 = 0xff;
      }
      puVar10 = puVar10 + iVar7 * -2 + 0x30;
      iVar5 = iVar5 + -1;
      iVar6 = iVar4;
    } while (iVar5 != 0);
  }
  else {
    puVar9 = (undefined2 *)((undefined *)&DAT_0000_648c + ((uint)bVar8 * 0x18 + (in_BX & 0xff)) * 2)
    ;
    iVar4 = bVar3 + 1;
    iVar6 = (in_CX & 0xff) + 1;
    iVar5 = iVar6;
    do {
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        puVar2 = puVar9;
        puVar9 = puVar9 + 1;
        *puVar2 = 0xffff;
      }
      puVar9 = puVar9 + (0x18 - iVar6);
      iVar4 = iVar4 + -1;
      iVar5 = iVar6;
    } while (iVar4 != 0);
  }
  FUN_1000_9167();
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4be9  FUN_1000_4be9  184 bytes, 5 callers */

undefined2 __cdecl16near FUN_1000_4be9(void)

{
  undefined2 uVar1;
  byte bVar2;
  undefined1 uVar3;
  uint in_AX;
  undefined2 uVar4;
  char cVar5;
  uint uVar6;
  undefined2 *unaff_DI;
  undefined2 unaff_DS;
  bool bVar7;
  
  uVar6 = in_AX & 0xff00;
  *(undefined2 *)0x32e6 = 0;
  *(undefined2 *)0x32e8 = 0;
  *(undefined2 *)0x32ea = 0;
  *(undefined2 *)0x32ec = 0;
LAB_1000_4c0d:
  while( true ) {
    do {
      bVar2 = FUN_1000_c8b0();
      bVar2 = bVar2 & (byte)(uVar6 >> 8);
    } while (bVar2 == 0);
    if ((bVar2 & 0x20) != 0) break;
    if (((bVar2 & 0x40) != 0) || ((bVar2 & 3) == 0)) goto LAB_1000_4c9a;
    bVar7 = false;
    if (*(char *)0x32e5 != '\0') goto LAB_1000_4c4f;
    uVar4 = FUN_1000_4ca1();
    if (!bVar7) {
      FUN_1000_0d12();
      if ((char)((uint)uVar4 >> 8) == -1) {
        uVar3 = FUN_1000_9295();
        *(undefined1 *)unaff_DI = uVar3;
        goto LAB_1000_4c0a;
      }
      *unaff_DI = uVar4;
      FUN_1000_727a();
      FUN_1000_4af4();
      FUN_1000_72ad();
    }
  }
  FUN_1000_0d12();
LAB_1000_4c9a:
  return CONCAT11(bVar2,*(undefined1 *)unaff_DI);
LAB_1000_4c4f:
  uVar4 = FUN_1000_4ca1();
  if (!bVar7) {
    uVar1 = *unaff_DI;
    do {
      cVar5 = (char)((uint)uVar4 >> 8);
      if (cVar5 != -1) {
        *(char *)((int)unaff_DI + 1) = cVar5;
      }
      *(char *)unaff_DI = (char)uVar4;
      bVar2 = FUN_1000_c8d8();
      bVar7 = false;
    } while (((bVar2 & 3) != 0) && (uVar4 = FUN_1000_4ca1(), !bVar7));
    uVar4 = *unaff_DI;
    *unaff_DI = uVar1;
    if ((char)((uint)uVar4 >> 8) == *(char *)((int)unaff_DI + 1)) {
      uVar3 = FUN_1000_9295();
      *(undefined1 *)unaff_DI = uVar3;
LAB_1000_4c0a:
      FUN_1000_9239();
    }
    else {
      *unaff_DI = uVar4;
      FUN_1000_727a();
      FUN_1000_4af4();
      FUN_1000_72ad();
    }
  }
  goto LAB_1000_4c0d;
}



/* 1000:4ca1  FUN_1000_4ca1  60 bytes, 1 callers */

void __cdecl16near FUN_1000_4ca1(void)

{
  byte in_AL;
  byte in_CH;
  char *unaff_DI;
  undefined2 unaff_DS;
  
  if ((in_AL & 2) == 0) {
    if ((char)(*unaff_DI + -1) < '\0') {
      return;
    }
  }
  else if (in_CH < (byte)(*unaff_DI + 1U)) {
    return;
  }
  return;
}



/* 1000:4cdd  FUN_1000_4cdd  109 bytes, 4 callers */

undefined4 __cdecl16near FUN_1000_4cdd(void)

{
  char cVar1;
  undefined2 in_AX;
  int iVar2;
  char cVar3;
  undefined2 in_DX;
  int iVar4;
  int extraout_DX;
  int extraout_DX_00;
  undefined2 unaff_DS;
  
  cVar3 = 'v';
  if (((*(int *)0x3bc2 != -1) && (cVar3 = '\0', *(int *)0x3bd4 != 0)) &&
     (cVar3 = '\x03', *(int *)0x3bd6 != 0)) {
    cVar3 = -10;
  }
  LOCK();
  cVar1 = *(char *)0x32c1;
  *(char *)0x32c1 = cVar3;
  iVar4 = CONCAT11(cVar1,cVar3);
  UNLOCK();
  if (cVar3 != cVar1) {
    cVar3 = *(char *)0x328a;
    if (cVar3 != -1) {
      FUN_1000_4d86();
      iVar4 = extraout_DX;
    }
    iVar2 = 8;
    do {
      if ((char)((byte)((uint)iVar4 >> 8) ^ (byte)iVar4) < '\0') {
        FUN_1000_8738();
        FUN_1000_727a();
        FUN_1000_8738();
        FUN_1000_727a();
        iVar4 = extraout_DX_00;
      }
      iVar4 = iVar4 * 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (cVar3 != -1) {
      FUN_1000_4d4a();
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4d4a  FUN_1000_4d4a  60 bytes, 4 callers */

undefined2 __cdecl16near FUN_1000_4d4a(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  if (*(char *)0x328a != -1) {
    if (*(char *)0x328a == *(char *)0x3bee) {
      return in_AX;
    }
    FUN_1000_4d86();
  }
  *(undefined1 *)0x328a = *(undefined1 *)0x3bee;
  FUN_1000_97e3();
  FUN_1000_727a();
  FUN_1000_8738();
  FUN_1000_727a();
  FUN_1000_8738();
  return in_AX;
}



/* 1000:4d86  FUN_1000_4d86  44 bytes, 3 callers */

undefined2 __cdecl16near FUN_1000_4d86(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  if (*(char *)0x328a != -1) {
    FUN_1000_727a();
    FUN_1000_8738();
    FUN_1000_727a();
    FUN_1000_8738();
    *(undefined1 *)0x328a = 0xff;
  }
  return in_AX;
}



/* 1000:4db2  FUN_1000_4db2  151 bytes, 1 callers */

uint __cdecl16near FUN_1000_4db2(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  byte bVar4;
  undefined2 unaff_DS;
  
  uVar2 = *(undefined2 *)0x32f0;
  uVar3 = *(undefined2 *)0x32ee;
  *(undefined2 *)0x32e6 = 0;
  *(undefined2 *)0x32e8 = 0;
  *(undefined2 *)0x32ea = 0;
  *(undefined2 *)0x32ec = 0;
  *(undefined2 *)0x32ee = 9;
  *(undefined2 *)0x32f0 = 0x3c;
LAB_1000_4ddb:
  do {
    bVar4 = FUN_1000_c8b0();
  } while ((bVar4 & 0x6f) == 0);
  if ((bVar4 & 0x20) != 0) {
    FUN_1000_0d12();
LAB_1000_4e39:
    uVar1 = *(undefined1 *)0x3bee;
    *(undefined2 *)0x32ee = uVar3;
    *(undefined2 *)0x32f0 = uVar2;
    return CONCAT11(bVar4,uVar1) & 0x6fff;
  }
  if ((bVar4 & 0x40) != 0) goto LAB_1000_4e39;
  if ((bVar4 & 2) != 0) goto LAB_1000_4dfc;
  if ((bVar4 & 4) == 0) {
    if ((bVar4 & 8) != 0) {
      if ((*(byte *)0x3bee & 1) == 0) {
        bVar4 = *(byte *)0x3bee | 1;
        goto LAB_1000_4e26;
      }
      goto LAB_1000_4ddb;
    }
    if (((bVar4 & 1) == 0) || (bVar4 = *(byte *)0x3bee - 2, *(byte *)0x3bee < 2))
    goto LAB_1000_4ddb;
  }
  else {
    if ((*(byte *)0x3bee & 1) == 0) goto LAB_1000_4ddb;
    bVar4 = *(byte *)0x3bee & 0xfe;
  }
LAB_1000_4e26:
  *(byte *)0x3bee = bVar4;
  FUN_1000_4d4a();
  goto LAB_1000_4ddb;
LAB_1000_4dfc:
  bVar4 = *(char *)0x3bee + 2;
  if (0xd < bVar4) goto LAB_1000_4ddb;
  goto LAB_1000_4e26;
}



/* 1000:5bbe  FUN_1000_5bbe  11 bytes, 1 callers */

void __cdecl16near FUN_1000_5bbe(void)

{
  FUN_1000_5bd4();
  FUN_1000_4a4d();
  return;
}



/* 1000:5bc9  FUN_1000_5bc9  11 bytes, 1 callers */

void __cdecl16near FUN_1000_5bc9(void)

{
  FUN_1000_5bf2();
  FUN_1000_4a4d();
  return;
}



/* 1000:5bd4  FUN_1000_5bd4  30 bytes, 2 callers */

undefined2 __cdecl16near FUN_1000_5bd4(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  if ((byte)(*(char *)((int)(undefined2 *)&DAT_0000_3be4 + 1) -
             *(char *)((int)(undefined2 *)&DAT_0000_3be2 + 1) << (*(byte *)0x3288 & 0x1f)) < 0x18) {
    FUN_1000_5c10();
  }
  else {
    FUN_1000_5c1b();
  }
  return in_AX;
}



/* 1000:5bf2  FUN_1000_5bf2  30 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_5bf2(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  if ((byte)(*(char *)&DAT_0000_3be4 - *(char *)&DAT_0000_3be2 << (*(byte *)0x3288 & 0x1f)) < 0x18)
  {
    FUN_1000_5c20();
  }
  else {
    FUN_1000_5c2a();
  }
  return in_AX;
}



/* 1000:5c10  FUN_1000_5c10  11 bytes, 1 callers */

void __cdecl16near FUN_1000_5c10(void)

{
  int in_BX;
  undefined2 unaff_DS;
  
  *(char *)(in_BX + 1) = '\x16' - *(char *)(in_BX + 3);
  return;
}



/* 1000:5c1b  FUN_1000_5c1b  5 bytes, 1 callers */

void __cdecl16near FUN_1000_5c1b(void)

{
  int in_BX;
  undefined2 unaff_DS;
  
  *(undefined1 *)(in_BX + 1) = 1;
  return;
}



/* 1000:5c20  FUN_1000_5c20  10 bytes, 1 callers */

void __cdecl16near FUN_1000_5c20(void)

{
  char *in_BX;
  undefined2 unaff_DS;
  
  *in_BX = '\x16' - in_BX[2];
  return;
}



/* 1000:5c2a  FUN_1000_5c2a  4 bytes, 1 callers */

void __cdecl16near FUN_1000_5c2a(void)

{
  undefined1 *in_BX;
  undefined2 unaff_DS;
  
  *in_BX = 1;
  return;
}



/* 1000:5c2e  FUN_1000_5c2e  59 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_5c2e(void)

{
  undefined2 in_AX;
  byte extraout_DL;
  undefined2 in_DX;
  undefined2 unaff_DS;
  
  FUN_1000_c5bb();
  FUN_1000_ac00();
  *(undefined1 *)0x10f8 = 1;
  FUN_1000_5bc9((uint)extraout_DL * 4 + 0x400);
  FUN_1000_8738();
  return CONCAT22(in_DX,in_AX);
}



/* 1000:5c69  FUN_1000_5c69  57 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_5c69(void)

{
  undefined2 in_AX;
  byte extraout_DL;
  undefined2 in_DX;
  undefined2 unaff_DS;
  
  FUN_1000_c5bb();
  FUN_1000_ac00();
  *(undefined1 *)0x10f7 = 1;
  FUN_1000_5bbe((uint)extraout_DL * 4 + 0x400);
  FUN_1000_8738();
  return CONCAT22(in_DX,in_AX);
}



/* 1000:5ca2  FUN_1000_5ca2  77 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_5ca2(void)

{
  char cVar1;
  undefined2 in_AX;
  int iVar2;
  int iVar3;
  undefined2 in_DX;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  FUN_1000_6c3f();
  FUN_1000_687e();
  if (!(bool)in_CF) {
    FUN_1000_6f4b();
    FUN_1000_68a0();
    if (!(bool)in_CF) goto LAB_1000_5ced;
  }
  puVar5 = (undefined1 *)0x5200;
  iVar2 = 0xa0;
  do {
    cVar1 = FUN_1000_72d0();
    puVar4 = (undefined1 *)0x3e50;
    iVar3 = 0x10;
    do {
      puVar6 = puVar5;
      puVar5 = puVar6 + 1;
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 2;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (0x7f < (byte)(cVar1 + 1U)) {
      puVar5 = puVar6 + 0x201;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
LAB_1000_5ced:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:5cef  FUN_1000_5cef  31 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_5cef(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  undefined1 in_CF;
  undefined1 uVar1;
  
  do {
    do {
      uVar1 = in_CF;
      FUN_1000_6c3f();
      FUN_1000_687e();
      in_CF = 1;
    } while ((bool)uVar1);
    FUN_1000_6f4b();
    FUN_1000_68a0();
    in_CF = 1;
  } while ((bool)uVar1);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:5d0e  FUN_1000_5d0e  122 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_5d0e(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar1;
  
  do {
    do {
      do {
        do {
          do {
            do {
              do {
                do {
                  uVar1 = in_CF;
                  FUN_1000_6c3f();
                  *(undefined1 *)0x3376 = 0x42;
                  FUN_1000_687e();
                  in_CF = 1;
                } while ((bool)uVar1);
                FUN_1000_6f4b();
                FUN_1000_68a0();
                in_CF = 1;
              } while ((bool)uVar1);
              *(undefined1 *)0x3376 = 0x52;
              FUN_1000_687e();
              in_CF = 1;
            } while ((bool)uVar1);
            FUN_1000_6f4b();
            FUN_1000_68a0();
            in_CF = 1;
          } while ((bool)uVar1);
          *(undefined1 *)0x3376 = 0x47;
          FUN_1000_687e();
          in_CF = 1;
        } while ((bool)uVar1);
        FUN_1000_6f4b();
        FUN_1000_68a0();
        in_CF = 1;
      } while ((bool)uVar1);
      *(undefined1 *)0x3376 = 0x45;
      FUN_1000_687e();
      in_CF = 1;
    } while ((bool)uVar1);
    FUN_1000_6f4b();
    FUN_1000_68a0();
    in_CF = 1;
  } while ((bool)uVar1);
  *(undefined1 *)0x32c1 = 0;
  return CONCAT22(in_DX,in_AX);
}



/* 1000:5dfd  FUN_1000_5dfd  90 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_5dfd(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar1;
  
  do {
    do {
      do {
        do {
          do {
            do {
              uVar1 = in_CF;
              FUN_1000_6c3f();
              *(undefined1 *)0x33a6 = 0x42;
              FUN_1000_687e();
              in_CF = 1;
            } while ((bool)uVar1);
            FUN_1000_6f4b();
            FUN_1000_68a0();
            in_CF = 1;
          } while ((bool)uVar1);
          *(undefined1 *)0x33a6 = 0x52;
          FUN_1000_687e();
          in_CF = 1;
        } while ((bool)uVar1);
        FUN_1000_6f4b();
        FUN_1000_68a0();
        in_CF = 1;
      } while ((bool)uVar1);
      *(undefined1 *)0x33a6 = 0x47;
      FUN_1000_687e();
      in_CF = 1;
    } while ((bool)uVar1);
    FUN_1000_6f4b();
    FUN_1000_68a0();
    in_CF = 1;
  } while ((bool)uVar1);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:5e57  FUN_1000_5e57  141 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_5e57(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  FUN_1000_6c3f();
  *(undefined1 *)0x33b2 = 0x42;
  FUN_1000_687e();
  if (!(bool)in_CF) {
    FUN_1000_6f4b();
    FUN_1000_68a0();
    if (!(bool)in_CF) {
      FUN_1000_9836();
      *(undefined1 *)0x33b2 = 0x52;
      FUN_1000_687e();
      if (!(bool)in_CF) {
        FUN_1000_6f4b();
        FUN_1000_68a0();
        if (!(bool)in_CF) {
          FUN_1000_9836();
          *(undefined1 *)0x33b2 = 0x47;
          FUN_1000_687e();
          if (!(bool)in_CF) {
            FUN_1000_6f4b();
            FUN_1000_68a0();
            if (!(bool)in_CF) {
              FUN_1000_9836();
              *(undefined1 *)0x33b2 = 0x45;
              FUN_1000_687e();
              if (!(bool)in_CF) {
                FUN_1000_6f4b();
                FUN_1000_68a0();
                if (!(bool)in_CF) {
                  FUN_1000_9836();
                }
              }
            }
          }
        }
      }
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:5ee4  FUN_1000_5ee4  26 bytes, 2 callers */

void __cdecl16near FUN_1000_5ee4(void)

{
  undefined1 in_CF;
  undefined1 uVar1;
  
  do {
    do {
      uVar1 = in_CF;
      FUN_1000_6c3f();
      FUN_1000_687e();
      in_CF = 1;
    } while ((bool)uVar1);
    FUN_1000_6f4b();
    FUN_1000_68a0();
    in_CF = 1;
  } while ((bool)uVar1);
  return;
}



/* 1000:5efe  FUN_1000_5efe  128 bytes, 7 callers */

undefined4 __cdecl16near FUN_1000_5efe(void)

{
  uint in_AX;
  uint uVar1;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 uVar2;
  undefined1 uVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = &stack0xfff0 < (undefined1 *)0x2;
  uVar1 = in_AX;
  FUN_1000_6c3f();
  do {
    do {
      uVar3 = uVar2;
      *(undefined1 *)(unaff_SI + 8) = 0x42;
      FUN_1000_687e();
      uVar2 = 1;
    } while ((bool)uVar3);
    uVar3 = 0;
    FUN_1000_6f4b();
    FUN_1000_68a0();
    uVar2 = 1;
  } while ((bool)uVar3);
  uVar5 = uVar1 + 0x800;
  bVar4 = 0xf7ff < uVar1;
  do {
    do {
      uVar2 = bVar4;
      *(undefined1 *)(unaff_SI + 8) = 0x52;
      FUN_1000_687e();
      bVar4 = true;
    } while ((bool)uVar2);
    FUN_1000_6f4b();
    FUN_1000_68a0();
    bVar4 = true;
  } while ((bool)uVar2);
  iVar6 = uVar5 + 0x800;
  bVar4 = 0xf7ff < uVar5;
  do {
    do {
      uVar2 = bVar4;
      *(undefined1 *)(unaff_SI + 8) = 0x47;
      FUN_1000_687e();
      bVar4 = true;
    } while ((bool)uVar2);
    FUN_1000_6f4b();
    FUN_1000_68a0();
    bVar4 = true;
  } while ((bool)uVar2);
  uVar1 = iVar6 + 0x800;
  bVar4 = uVar1 < 0xb800;
  if (0xb800 < uVar1) {
    bVar4 = 0xdfff < uVar1;
    uVar1 = iVar6 + 0x2800;
  }
  do {
    do {
      uVar2 = bVar4;
      *(undefined1 *)(unaff_SI + 8) = 0x45;
      FUN_1000_687e(uVar1);
      bVar4 = true;
    } while ((bool)uVar2);
    FUN_1000_6f4b();
    FUN_1000_68a0();
    bVar4 = true;
  } while ((bool)uVar2);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:5f7e  FUN_1000_5f7e  100 bytes, 8 callers */

undefined * __cdecl16near FUN_1000_5f7e(void)

{
  uint uVar1;
  undefined *puVar2;
  uint in_DX;
  uint extraout_DX;
  undefined2 unaff_DS;
  undefined1 uVar3;
  undefined1 uVar4;
  
  if ((undefined *)*(undefined2 *)0x3b44 == (undefined *)&DAT_0000_4f1c) {
    FUN_1000_0d0a();
    in_DX = extraout_DX;
  }
  uVar1 = *(uint *)&DAT_0000_3bc6;
  if (uVar1 == *(uint *)0x3470) {
    puVar2 = (undefined *)&DAT_0000_3f1c;
  }
  else {
    uVar3 = uVar1 < *(uint *)0x3472;
    uVar4 = uVar1 == *(uint *)0x3472;
    if (!(bool)uVar4) {
      FUN_1000_6c3f(uVar1);
      FUN_1000_c492();
      FUN_1000_c449();
      do {
        FUN_1000_687e();
        if (!(bool)uVar3) {
          FUN_1000_6f4b();
          FUN_1000_68a0();
          if (!(bool)uVar3) {
            *(undefined2 *)0x3472 = *(undefined2 *)&DAT_0000_3bc6;
            break;
          }
        }
        FUN_1000_6cb5();
        if (!(bool)uVar4) {
          return (undefined *)((ulong)in_DX << 0x10);
        }
      } while( true );
    }
    puVar2 = (undefined *)&DAT_0000_4f1c;
  }
  return (undefined *)CONCAT22(in_DX,puVar2);
}



/* 1000:5fe2  FUN_1000_5fe2  81 bytes, 1 callers */

undefined * __cdecl16near FUN_1000_5fe2(void)

{
  uint in_DX;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 in_ZF;
  undefined1 uVar1;
  
  FUN_1000_6c3f();
  *(undefined2 *)0x3b44 = 0;
  FUN_1000_0ccc();
  FUN_1000_0ce3();
  FUN_1000_c492();
  FUN_1000_c449();
  do {
    FUN_1000_687e();
    uVar1 = in_ZF;
    if (!(bool)in_CF) {
      FUN_1000_6f4b();
      FUN_1000_68a0();
      uVar1 = in_ZF;
      if (!(bool)in_CF) {
        *(undefined2 *)0x3472 = *(undefined2 *)&DAT_0000_3bc6;
        return (undefined *)CONCAT22(in_DX,(undefined *)&DAT_0000_3f1c);
      }
    }
    FUN_1000_6cb5();
    in_ZF = 1;
  } while ((bool)uVar1);
  return (undefined *)((ulong)in_DX << 0x10);
}



/* 1000:6033  FUN_1000_6033  178 bytes, 3 callers */

undefined4 __cdecl16near FUN_1000_6033(void)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 in_AX;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  undefined2 in_DX;
  undefined2 *puVar7;
  undefined1 *puVar8;
  undefined2 *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 uVar10;
  undefined1 uVar11;
  
  uVar10 = *(int *)0x3bc2 != -1;
  uVar11 = *(int *)0x3bc2 == -1;
  if ((bool)uVar11) {
LAB_1000_60dc:
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_6c3f();
  *(undefined2 *)0x346e = 0xffff;
  FUN_1000_662c();
  FUN_1000_c492();
  FUN_1000_c449();
  do {
    FUN_1000_687e();
    if (!(bool)uVar10) {
      FUN_1000_6f4b();
      FUN_1000_68a0();
      if (!(bool)uVar10) {
        *(undefined2 *)0x3bc4 = *(undefined2 *)0xdb7e;
        uVar4 = *(uint *)0x3bc2;
        if (0x33 < uVar4) {
          uVar4 = uVar4 - 100;
        }
        puVar7 = (undefined2 *)((undefined *)&DAT_0000_fa3e + uVar4 * 0x10);
        puVar9 = (undefined2 *)0x3c08;
        for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
          puVar3 = puVar9;
          puVar9 = puVar9 + 1;
          puVar2 = puVar7;
          puVar7 = puVar7 + 1;
          *puVar3 = *puVar2;
        }
        uVar10 = false;
        *(undefined1 *)puVar9 = 0;
        *(undefined2 *)0x3bce = 0;
        FUN_1000_6d3a();
        if ((!(bool)uVar10) && (uVar10 = 0, *(int *)(*(int *)0x3e94 + 0xc) == 0)) {
          *(undefined2 *)0x3bce = 1;
        }
        FUN_1000_60e5();
        if (!(bool)uVar10) {
          puVar8 = (undefined1 *)0xdb7d;
          puVar7 = (undefined2 *)0xe47c;
          iVar6 = 0x900;
          puVar5 = (undefined *)&DAT_0000_6400;
          do {
            puVar1 = puVar8;
            puVar8 = puVar8 + -1;
            puVar5 = (undefined *)CONCAT11((char)((uint)puVar5 >> 8),*puVar1);
            puVar2 = puVar7;
            puVar7 = puVar7 + -1;
            *puVar2 = puVar5;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          *(undefined2 *)0x346e = *(undefined2 *)0x3bc2;
          goto LAB_1000_60dc;
        }
LAB_1000_60df:
        FUN_1000_051b();
        return CONCAT22(in_DX,in_AX);
      }
    }
    FUN_1000_6cb5();
    if (!(bool)uVar11) goto LAB_1000_60df;
  } while( true );
}



/* 1000:60e5  FUN_1000_60e5  434 bytes, 1 callers */

int __cdecl16near FUN_1000_60e5(void)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  int in_AX;
  int iVar4;
  undefined2 *puVar5;
  char *pcVar6;
  undefined2 *puVar7;
  undefined1 *puVar8;
  char *pcVar9;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  int iStack_2;
  
  iStack_2 = in_AX;
  FUN_1000_6c3f();
  iVar4 = *(int *)0x3bc4;
  if ((iVar4 != -1) && (iVar4 != *(int *)0x346a)) {
    *(undefined2 *)0x346a = 0xffff;
    uVar10 = (undefined1 *)0xfffd < &iStack_2;
    uVar11 = &stack0x0000 == (undefined1 *)0x0;
    iStack_2 = iVar4;
    FUN_1000_c492();
    FUN_1000_c449();
    do {
      *(undefined1 *)0x331f = 0x53;
      FUN_1000_687e();
      uVar12 = uVar11;
      if (!(bool)uVar10) {
        FUN_1000_6f4b();
        FUN_1000_68a0();
        uVar12 = uVar11;
        if (!(bool)uVar10) {
          do {
            *(undefined1 *)0x331f = 0x4d;
            FUN_1000_687e();
            uVar12 = uVar11;
            if (!(bool)uVar10) {
              FUN_1000_6f4b();
              FUN_1000_68a0();
              uVar12 = uVar11;
              if (!(bool)uVar10) {
                do {
                  *(undefined1 *)0x331f = 0x4c;
                  FUN_1000_687e();
                  uVar12 = uVar11;
                  if (!(bool)uVar10) {
                    FUN_1000_6f4b();
                    FUN_1000_68a0();
                    uVar12 = uVar11;
                    if (!(bool)uVar10) {
                      puVar5 = (undefined2 *)0x7ca0;
                      puVar7 = (undefined2 *)&DAT_0000_3c20;
                      for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
                        puVar3 = puVar7;
                        puVar7 = puVar7 + 1;
                        puVar1 = puVar5;
                        puVar5 = puVar5 + 1;
                        *puVar3 = *puVar1;
                      }
                      puVar7 = (undefined2 *)0xc632;
                      for (iVar4 = 0xb0; iVar4 != 0; iVar4 = iVar4 + -1) {
                        puVar3 = puVar7;
                        puVar7 = puVar7 + 1;
                        puVar1 = puVar5;
                        puVar5 = puVar5 + 1;
                        *puVar3 = *puVar1;
                      }
                      puVar8 = (undefined1 *)0x3eea;
                      for (iVar4 = 0x2d; iVar4 != 0; iVar4 = iVar4 + -1) {
                        puVar2 = puVar8;
                        puVar8 = puVar8 + 1;
                        puVar1 = puVar5;
                        puVar5 = (undefined2 *)((int)puVar5 + 1);
                        *puVar2 = *(undefined1 *)puVar1;
                      }
                      pcVar6 = (char *)0xc642;
                      pcVar9 = (char *)0x3485;
                      iVar4 = 5;
                      do {
                        *pcVar9 = *pcVar6 + -0x10;
                        pcVar6 = pcVar6 + 0x10;
                        uVar10 = (char *)0xfff6 < pcVar9 + 1;
                        pcVar9 = pcVar9 + 10;
                        uVar11 = pcVar9 == (char *)0x0;
                        iVar4 = iVar4 + -1;
                      } while (iVar4 != 0);
                      FUN_1000_c492();
                      FUN_1000_c449();
                      do {
                        *(undefined1 *)0x3313 = 0x4d;
                        *(undefined1 *)0x3314 = 0x20;
                        FUN_1000_687e();
                        uVar12 = uVar11;
                        if (!(bool)uVar10) {
                          FUN_1000_6f4b();
                          FUN_1000_68a0();
                          uVar12 = uVar11;
                          if (!(bool)uVar10) {
                            do {
                              *(undefined1 *)0x3313 = 0x4c;
                              *(undefined1 *)0x3314 = 0x31;
                              FUN_1000_687e();
                              uVar12 = uVar11;
                              if (!(bool)uVar10) {
                                FUN_1000_6f4b();
                                FUN_1000_68a0();
                                uVar12 = uVar11;
                                if (!(bool)uVar10) {
                                  do {
                                    *(undefined1 *)0x3313 = 0x4c;
                                    *(undefined1 *)0x3314 = 0x32;
                                    FUN_1000_687e();
                                    uVar12 = uVar11;
                                    if (!(bool)uVar10) {
                                      FUN_1000_6f4b();
                                      FUN_1000_68a0();
                                      uVar12 = uVar11;
                                      if (!(bool)uVar10) {
                                        do {
                                          *(undefined1 *)0x3313 = 0x4c;
                                          *(undefined1 *)0x3314 = 0x33;
                                          FUN_1000_687e();
                                          uVar12 = uVar11;
                                          if (!(bool)uVar10) {
                                            FUN_1000_6f4b();
                                            FUN_1000_68a0();
                                            uVar12 = uVar11;
                                            if (!(bool)uVar10) {
                                              do {
                                                *(undefined1 *)0x3313 = 0x4c;
                                                *(undefined1 *)0x3314 = 0x34;
                                                FUN_1000_687e();
                                                uVar12 = uVar11;
                                                if (!(bool)uVar10) {
                                                  FUN_1000_6f4b();
                                                  FUN_1000_68a0();
                                                  uVar12 = uVar11;
                                                  if (!(bool)uVar10) {
                                                    *(undefined2 *)0x346a = *(undefined2 *)0x3bc4;
                                                    return iStack_2;
                                                  }
                                                }
                                                FUN_1000_6cb5();
                                                uVar11 = 1;
                                              } while ((bool)uVar12);
                                              return iStack_2;
                                            }
                                          }
                                          FUN_1000_6cb5();
                                          uVar11 = 1;
                                        } while ((bool)uVar12);
                                        return iStack_2;
                                      }
                                    }
                                    FUN_1000_6cb5();
                                    uVar11 = 1;
                                  } while ((bool)uVar12);
                                  return iStack_2;
                                }
                              }
                              FUN_1000_6cb5();
                              uVar11 = 1;
                            } while ((bool)uVar12);
                            return iStack_2;
                          }
                        }
                        FUN_1000_6cb5();
                        uVar11 = 1;
                      } while ((bool)uVar12);
                      return iStack_2;
                    }
                  }
                  FUN_1000_6cb5();
                  uVar11 = 1;
                } while ((bool)uVar12);
                return iStack_2;
              }
            }
            FUN_1000_6cb5();
            uVar11 = 1;
          } while ((bool)uVar12);
          return iStack_2;
        }
      }
      FUN_1000_6cb5();
      uVar11 = 1;
    } while ((bool)uVar12);
    return iStack_2;
  }
  return iStack_2;
}



/* 1000:6315  FUN_1000_6315  38 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_6315(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  undefined2 unaff_DS;
  bool bVar1;
  
  *(undefined2 *)0x3bc2 = *(undefined2 *)0xce70;
  bVar1 = false;
  *(undefined2 *)0x3bd6 = 0;
  *(undefined2 *)0xc52c = 0;
  *(undefined2 *)0x346e = 0xffff;
  FUN_1000_6033();
  if (bVar1) {
    FUN_1000_7c9e();
    FUN_1000_72ad();
    FUN_1000_7c9e();
    FUN_1000_72ad();
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:633b  FUN_1000_633b  46 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_633b(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined1 in_CF;
  
  FUN_1000_6c3f();
  FUN_1000_687e();
  if (!(bool)in_CF) {
    unaff_DI = (undefined2 *)&DAT_0000_cc00;
    FUN_1000_68bb();
    if (!(bool)in_CF) goto LAB_1000_6363;
  }
  for (iVar2 = 0x13a; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *puVar1 = 0;
  }
LAB_1000_6363:
  FUN_1000_acbb();
  return CONCAT22(in_DX,in_AX);
}



/* 1000:662c  FUN_1000_662c  62 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_662c(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 *puVar3;
  undefined2 unaff_ES;
  undefined1 in_CF;
  undefined1 in_ZF;
  undefined1 uVar4;
  
  do {
    uVar4 = in_ZF;
    FUN_1000_6c3f();
    FUN_1000_69df();
    if (!(bool)in_CF) goto LAB_1000_663f;
    FUN_1000_6cb5();
    in_ZF = 1;
  } while ((bool)uVar4);
  goto LAB_1000_665e;
  while( true ) {
    FUN_1000_687e();
    if (!(bool)in_CF) {
      FUN_1000_6f4b();
      FUN_1000_68a0();
      if (!(bool)in_CF) goto LAB_1000_6668;
    }
    FUN_1000_6cb5();
    if (!(bool)uVar4) break;
LAB_1000_663f:
    FUN_1000_6d3a();
    if ((bool)in_CF) break;
  }
LAB_1000_665e:
  puVar3 = (undefined2 *)&DAT_0000_fa3e;
  for (iVar2 = 0x1a0; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0;
  }
LAB_1000_6668:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:6808  FUN_1000_6808  26 bytes, 1 callers */

void __cdecl16near FUN_1000_6808(void)

{
  undefined1 in_CF;
  undefined1 in_ZF;
  undefined1 uVar1;
  
  while( true ) {
    FUN_1000_6c3f();
    FUN_1000_69df();
    uVar1 = in_ZF;
    if ((!(bool)in_CF) && (FUN_1000_6d3a(), uVar1 = in_ZF, !(bool)in_CF)) break;
    FUN_1000_6cf8();
    in_ZF = 1;
    if (!(bool)uVar1) {
      return;
    }
  }
  return;
}



/* 1000:6822  FUN_1000_6822  92 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_6822(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int iVar3;
  char extraout_DL;
  undefined2 in_DX;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 in_ZF;
  undefined1 uVar6;
  
  FUN_1000_6c3f();
  FUN_1000_705b();
  do {
    iVar3 = 0x9a;
    uVar6 = in_ZF;
    do {
      FUN_1000_6c08();
      if ((bool)in_CF) goto LAB_1000_6876;
      uVar6 = extraout_DL == -1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    puVar4 = (undefined2 *)0x247d;
    puVar5 = (undefined2 *)&DAT_0000_b98e;
    for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = *puVar1;
    }
    in_CF = false;
    uVar6 = 1;
    for (iVar3 = 0x1f1; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      *puVar1 = 0;
    }
    FUN_1000_6aea();
    if (!(bool)in_CF) {
      puVar5 = (undefined2 *)*(undefined2 *)0x3e82;
      puVar4 = (undefined2 *)*(undefined2 *)0x3e86 + 1;
      *(undefined2 *)*(undefined2 *)0x3e86 = 0xfffe;
      *puVar4 = 0xff;
      for (iVar3 = 0x3fe; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
      }
      in_CF = false;
      uVar6 = 1;
      for (iVar3 = 0xc00; iVar3 != 0; iVar3 = iVar3 + -1) {
        puVar1 = puVar5;
        puVar5 = puVar5 + 1;
        *puVar1 = 0;
      }
      FUN_1000_6a55();
      if (!(bool)in_CF) break;
    }
LAB_1000_6876:
    FUN_1000_6cb5();
    in_ZF = 1;
  } while ((bool)uVar6);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:687e  FUN_1000_687e  34 bytes, 15 callers */

undefined4 __cdecl16near FUN_1000_687e(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  undefined2 in_DX;
  undefined2 unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  *(undefined2 *)0x3e8c = unaff_SI;
  *(undefined2 *)0x3e8e = (undefined *)&DAT_0000_b98e;
  *(undefined2 *)0x3e90 = 0;
  FUN_1000_69df();
  if (!(bool)in_CF) {
    uVar1 = FUN_1000_6d3a();
    if (!(bool)in_CF) {
      *(undefined2 *)0x3e8a = uVar1;
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:68a0  FUN_1000_68a0  27 bytes, 13 callers */

undefined2 __cdecl16near FUN_1000_68a0(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  uint in_CX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined2 *puVar7;
  undefined2 *unaff_DI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool bVar8;
  undefined1 in_ZF;
  undefined4 uVar9;
  
  uVar3 = FUN_1000_6f55();
  if ((bool)in_ZF) {
    FUN_1000_6f4b();
    FUN_1000_68bb();
    if ((bool)in_CF) {
      return uVar3;
    }
    uVar3 = FUN_1000_c33e();
    return uVar3;
  }
  puVar7 = (undefined2 *)*(undefined2 *)0x3e8e;
  uVar6 = *(uint *)0x3e90;
  do {
    if (uVar6 == 0) {
      bVar8 = *(int *)0x3e8a != -1;
      if (*(int *)0x3e8a == -1) {
        return uVar3;
      }
      FUN_1000_6fda();
      if (bVar8) {
        return uVar3;
      }
      uVar9 = FUN_1000_6e3a();
      in_CX = (uint)((ulong)uVar9 >> 0x10);
      *(undefined2 *)0x3e8a = (int)uVar9;
      if (bVar8) {
        return uVar3;
      }
      puVar7 = (undefined2 *)&DAT_0000_b98e;
      uVar6 = 0x400;
    }
    uVar4 = in_CX;
    if (uVar6 < in_CX) {
      uVar4 = uVar6;
    }
    in_CX = in_CX - uVar4;
    uVar6 = uVar6 - uVar4;
    uVar5 = uVar4 >> 1;
    if (uVar5 != 0) {
      for (; uVar5 != 0; uVar5 = uVar5 - 1) {
        puVar2 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        puVar1 = puVar7;
        puVar7 = puVar7 + 1;
        *puVar2 = *puVar1;
      }
    }
    if ((uVar4 & 1) != 0) {
      puVar2 = unaff_DI;
      unaff_DI = (undefined2 *)((int)unaff_DI + 1);
      puVar1 = puVar7;
      puVar7 = (undefined2 *)((int)puVar7 + 1);
      *(undefined1 *)puVar2 = *(undefined1 *)puVar1;
    }
    if (in_CX == 0) {
      *(undefined2 *)0x3e8e = puVar7;
      *(uint *)0x3e90 = uVar6;
      return uVar3;
    }
  } while( true );
}



/* 1000:68bb  FUN_1000_68bb  91 bytes, 3 callers */

undefined4 __cdecl16near FUN_1000_68bb(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  uint in_CX;
  uint uVar3;
  uint uVar4;
  undefined2 in_DX;
  uint uVar5;
  undefined2 *puVar6;
  undefined2 *unaff_DI;
  undefined2 unaff_DS;
  bool bVar7;
  undefined4 uVar8;
  
  puVar6 = (undefined2 *)*(undefined2 *)0x3e8e;
  uVar5 = *(uint *)0x3e90;
  do {
    if (uVar5 == 0) {
      bVar7 = *(int *)0x3e8a != -1;
      if ((*(int *)0x3e8a == -1) || (FUN_1000_6fda(), bVar7)) goto LAB_1000_6911;
      uVar8 = FUN_1000_6e3a();
      in_CX = (uint)((ulong)uVar8 >> 0x10);
      *(undefined2 *)0x3e8a = (int)uVar8;
      if (bVar7) goto LAB_1000_6911;
      puVar6 = (undefined2 *)&DAT_0000_b98e;
      uVar5 = 0x400;
    }
    uVar3 = in_CX;
    if (uVar5 < in_CX) {
      uVar3 = uVar5;
    }
    in_CX = in_CX - uVar3;
    uVar5 = uVar5 - uVar3;
    uVar4 = uVar3 >> 1;
    if (uVar4 != 0) {
      for (; uVar4 != 0; uVar4 = uVar4 - 1) {
        puVar2 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        puVar1 = puVar6;
        puVar6 = puVar6 + 1;
        *puVar2 = *puVar1;
      }
    }
    if ((uVar3 & 1) != 0) {
      puVar2 = unaff_DI;
      unaff_DI = (undefined2 *)((int)unaff_DI + 1);
      puVar1 = puVar6;
      puVar6 = (undefined2 *)((int)puVar6 + 1);
      *(undefined1 *)puVar2 = *(undefined1 *)puVar1;
    }
  } while (in_CX != 0);
  *(undefined2 *)0x3e8e = puVar6;
  *(uint *)0x3e90 = uVar5;
LAB_1000_6911:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:6916  FUN_1000_6916  57 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_6916(void)

{
  int iVar1;
  undefined2 in_AX;
  undefined2 uVar2;
  undefined2 in_CX;
  undefined2 in_DX;
  undefined2 extraout_DX;
  undefined2 unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  *(undefined2 *)0x3e8c = unaff_SI;
  *(undefined2 *)0x3e8e = (undefined *)&DAT_0000_b98e;
  *(undefined2 *)0x3e90 = 0x400;
  FUN_1000_69df();
  if (!(bool)in_CF) {
    uVar2 = FUN_1000_6d3a();
    if ((bool)in_CF) {
      FUN_1000_6d7b();
    }
    else {
      *(undefined2 *)0x3e8a = uVar2;
      FUN_1000_6df8();
      if (!(bool)in_CF) {
        FUN_1000_6f65();
        iVar1 = *(int *)0x3e94;
        *(undefined2 *)(iVar1 + 0x18) = extraout_DX;
        *(undefined2 *)(iVar1 + 0x16) = in_CX;
      }
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:694f  FUN_1000_694f  115 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_694f(void)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  undefined2 in_AX;
  uint in_CX;
  uint uVar4;
  undefined2 in_DX;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  undefined1 *unaff_DI;
  undefined2 unaff_DS;
  bool bVar8;
  undefined4 uVar9;
  
  if (in_CX != 0) {
    puVar7 = (undefined *)*(undefined2 *)0x3e8e;
    uVar6 = *(uint *)0x3e90;
    uVar5 = in_CX;
    do {
      if (uVar6 == 0) {
        bVar8 = *(int *)0x3e8a != -1;
        if ((*(int *)0x3e8a == -1) || (FUN_1000_6aaa(), bVar8)) goto LAB_1000_69c0;
        uVar9 = FUN_1000_6e3a();
        uVar5 = (uint)((ulong)uVar9 >> 0x10);
        *(int *)0x3e8a = (int)uVar9;
        if (bVar8) goto LAB_1000_69c0;
        if ((int)uVar9 == -1) {
          uVar9 = FUN_1000_6e73();
          uVar5 = (uint)((ulong)uVar9 >> 0x10);
          *(undefined2 *)0x3e8a = (int)uVar9;
        }
        puVar7 = (undefined *)&DAT_0000_b98e;
        uVar6 = 0x400;
      }
      uVar4 = uVar5;
      if (uVar6 < uVar5) {
        uVar4 = uVar6;
      }
      uVar5 = uVar5 - uVar4;
      uVar6 = uVar6 - uVar4;
      do {
        *puVar7 = *unaff_DI;
        puVar7 = puVar7 + 1;
        unaff_DI = unaff_DI + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    } while (uVar5 != 0);
    *(undefined2 *)0x3e8e = puVar7;
    *(uint *)0x3e90 = uVar6;
    iVar3 = *(int *)0x3e94;
    puVar1 = (uint *)(iVar3 + 0x1c);
    uVar6 = *puVar1;
    *puVar1 = *puVar1 + in_CX;
    piVar2 = (int *)(iVar3 + 0x1e);
    *piVar2 = *piVar2 + (uint)CARRY2(uVar6,in_CX);
  }
LAB_1000_69c0:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:69c2  FUN_1000_69c2  29 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_69c2(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  undefined2 unaff_DS;
  bool bVar1;
  
  bVar1 = *(int *)0x3e8a != -1;
  if ((*(int *)0x3e8a != -1) && (FUN_1000_6aaa(), !bVar1)) {
    FUN_1000_6a55();
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:69df  FUN_1000_69df  118 bytes, 6 callers */

undefined4 __cdecl16near FUN_1000_69df(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined2 in_AX;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined2 in_DX;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_DS;
  bool bVar5;
  
  if ((((undefined *)&DAT_0000_32f2)[(uint)*(byte *)&DAT_0000_3e80 * 2] & 8) != 0) {
    FUN_1000_705b();
    bVar5 = false;
    uVar3 = 0x800;
    uVar2 = *(undefined4 *)0x3e86;
    pcVar1 = (code *)swi(0x1b);
    (*pcVar1)();
    *(undefined1 *)0x3e92 = extraout_AH;
    if (!bVar5) {
      bVar5 = CARRY2((uint)uVar2,uVar3);
      uVar4 = 0xc00;
      pcVar1 = (code *)swi(0x1b);
      (*pcVar1)();
      *(undefined1 *)0x3e92 = extraout_AH_00;
      if (!bVar5) {
        bVar5 = CARRY2((uint)uVar2 + uVar3,uVar4);
        pcVar1 = (code *)swi(0x1b);
        (*pcVar1)();
        *(undefined1 *)0x3e92 = extraout_AH_01;
        if (!bVar5) {
          ((undefined *)&DAT_0000_32f2)[(uint)*(byte *)&DAT_0000_3e80 * 2] = 0;
        }
      }
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:6a55  FUN_1000_6a55  85 bytes, 3 callers */

undefined4 __cdecl16near FUN_1000_6a55(void)

{
  code *pcVar1;
  undefined2 in_AX;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined2 unaff_DS;
  bool bVar2;
  undefined2 in_stack_00000000;
  undefined1 *puVar3;
  
  puVar3 = &stack0xfffe;
  bVar2 = false;
  pcVar1 = (code *)swi(0x1b);
  (*pcVar1)();
  *(undefined1 *)0x3e92 = extraout_AH;
  if (!bVar2) {
    bVar2 = false;
    pcVar1 = (code *)swi(0x1b);
    (*pcVar1)(puVar3);
    *(undefined1 *)0x3e92 = extraout_AH_00;
    if (!bVar2) {
      pcVar1 = (code *)swi(0x1b);
      (*pcVar1)();
      *(undefined1 *)0x3e92 = extraout_AH_01;
    }
  }
  return CONCAT22(in_AX,in_stack_00000000);
}



/* 1000:6aaa  FUN_1000_6aaa  64 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_6aaa(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  undefined2 uVar3;
  int iVar4;
  undefined2 in_DX;
  char extraout_DH;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  FUN_1000_6c69();
  FUN_1000_6aea();
  if ((bool)in_CF) {
    FUN_1000_712c();
    if (!(bool)in_CF) {
      FUN_1000_70df();
    }
  }
  else {
    FUN_1000_712c();
    if (!(bool)in_CF) {
      uVar3 = FUN_1000_707a();
      puVar6 = (undefined2 *)((uint)(byte)(extraout_DH - 1) << 10);
      puVar5 = (undefined2 *)&DAT_0000_b98e;
      for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
        puVar2 = puVar6;
        puVar6 = puVar6 + 1;
        puVar1 = puVar5;
        puVar5 = puVar5 + 1;
        *puVar2 = *puVar1;
      }
      FUN_1000_70a6();
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:6aea  FUN_1000_6aea  40 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_6aea(void)

{
  code *pcVar1;
  undefined2 in_AX;
  undefined1 extraout_AH;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  pcVar1 = (code *)swi(0x1b);
  (*pcVar1)();
  *(undefined1 *)0x3e92 = extraout_AH;
  return CONCAT22(in_AX,in_stack_00000000);
}



/* 1000:6b12  FUN_1000_6b12  11 bytes, 1 callers */

void __cdecl16near FUN_1000_6b12(void)

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0x3480 = 0;
  return;
}



/* 1000:6c08  FUN_1000_6c08  55 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_6c08(undefined2 param_1)

{
  code *pcVar1;
  undefined2 in_AX;
  uint uVar2;
  undefined1 extraout_AH;
  int iVar3;
  byte in_DL;
  uint *puVar4;
  undefined2 unaff_DS;
  
  uVar2 = 0x301;
  puVar4 = (uint *)0xbd8e;
  iVar3 = 8;
  do {
    *puVar4 = CONCAT11(in_DL,in_DL >> 1) & 0x1ff;
    puVar4[1] = uVar2;
    uVar2 = CONCAT11((char)(uVar2 >> 8),(char)uVar2 + '\x01');
    puVar4 = puVar4 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pcVar1 = (code *)swi(0x1b);
  (*pcVar1)();
  *(undefined1 *)0x3e92 = extraout_AH;
  return CONCAT22(in_AX,param_1);
}



/* 1000:6c3f  FUN_1000_6c3f  42 bytes, 19 callers */

undefined4 __cdecl16near FUN_1000_6c3f(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  undefined *puVar1;
  undefined *puVar2;
  undefined2 unaff_DS;
  
  *(char *)&DAT_0000_3e80 = (char)in_AX;
  puVar2 = (undefined *)&DAT_0000_818e;
  puVar1 = (undefined *)&DAT_0000_798e;
  if ((char)in_AX != '\0') {
    puVar2 = (undefined *)&DAT_0000_a18e;
    puVar1 = (undefined *)&DAT_0000_998e;
  }
  *(undefined2 *)0x3e82 = puVar2;
  *(undefined2 *)0x3e84 = unaff_DS;
  *(undefined2 *)0x3e86 = puVar1;
  *(undefined2 *)0x3e88 = unaff_DS;
  return CONCAT22(in_DX,in_AX);
}



/* 1000:6c69  FUN_1000_6c69  24 bytes, 2 callers */

undefined2 __cdecl16near FUN_1000_6c69(void)

{
  undefined2 in_AX;
  
  return in_AX;
}



/* 1000:6cb5  FUN_1000_6cb5  67 bytes, 7 callers */

undefined1 __cdecl16near FUN_1000_6cb5(void)

{
  undefined1 uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_9650();
  FUN_1000_4a4d();
  *(undefined1 *)0x3bfe = 0;
  FUN_1000_49bb();
  FUN_1000_4be9();
  uVar1 = FUN_1000_96a1();
  return uVar1;
}



/* 1000:6cf8  FUN_1000_6cf8  66 bytes, 1 callers */

undefined1 __cdecl16near FUN_1000_6cf8(void)

{
  undefined1 uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_9650();
  FUN_1000_4a4d();
  *(undefined1 *)0x3bfe = 0;
  FUN_1000_49bb();
  FUN_1000_4be9();
  uVar1 = FUN_1000_96a1();
  return uVar1;
}



/* 1000:6d3a  FUN_1000_6d3a  65 bytes, 8 callers */

void __cdecl16near FUN_1000_6d3a(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *unaff_SI;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  bool bVar8;
  
  pcVar7 = (char *)*(undefined2 *)0x3e82;
  iVar3 = 0xc0;
  do {
    if (*pcVar7 == '\0') break;
    iVar4 = 0xb;
    bVar8 = false;
    pcVar5 = unaff_SI;
    pcVar6 = pcVar7;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar2 = pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
      bVar8 = *pcVar1 == *pcVar2;
    } while (bVar8);
    if (bVar8) {
      *(undefined2 *)0x3e94 = pcVar7;
      return;
    }
    pcVar7 = pcVar7 + 0x20;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined1 *)0x3e92 = 0x80;
  return;
}



/* 1000:6d7b  FUN_1000_6d7b  74 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_6d7b(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined2 in_AX;
  undefined2 uVar3;
  undefined2 in_CX;
  int iVar4;
  undefined2 in_DX;
  undefined2 extraout_DX;
  undefined1 *puVar5;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  FUN_1000_6ecd();
  if (!(bool)in_CF) {
    uVar3 = FUN_1000_6efd();
    if (!(bool)in_CF) {
      *(undefined2 *)0x3e94 = unaff_DI;
      *(undefined2 *)0x3e8a = uVar3;
      *(undefined2 *)(unaff_DI + 0x1a) = uVar3;
      unaff_DI[0xb] = 0x20;
      FUN_1000_6f1f();
      *(undefined2 *)(unaff_DI + 0x1c) = 0;
      *(undefined2 *)(unaff_DI + 0x1e) = 0;
      FUN_1000_6f65();
      *(undefined2 *)(unaff_DI + 0x18) = extraout_DX;
      *(undefined2 *)(unaff_DI + 0x16) = in_CX;
      puVar5 = (undefined1 *)*(undefined2 *)0x3e8c;
      for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
        puVar2 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        puVar1 = puVar5;
        puVar5 = puVar5 + 1;
        *puVar2 = *puVar1;
      }
      *unaff_DI = 0x20;
      for (iVar4 = 10; unaff_DI = unaff_DI + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
        *unaff_DI = 0;
      }
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:6df8  FUN_1000_6df8  66 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_6df8(void)

{
  undefined2 in_AX;
  int iVar1;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar2;
  
  iVar1 = FUN_1000_6e3a();
  if (!(bool)in_CF) {
    uVar2 = iVar1 != -1;
    if (iVar1 != -1) {
      FUN_1000_6f1f(iVar1);
      do {
        iVar1 = FUN_1000_6e3a();
        if ((bool)uVar2) {
          return in_AX;
        }
        FUN_1000_6f1f();
        uVar2 = iVar1 != -1;
      } while (iVar1 != -1);
    }
    iVar1 = *(int *)0x3e94;
    *(undefined2 *)(iVar1 + 0x1c) = 0;
    *(undefined2 *)(iVar1 + 0x1e) = 0;
  }
  return in_AX;
}



/* 1000:6e3a  FUN_1000_6e3a  51 bytes, 3 callers */

uint __cdecl16near FUN_1000_6e3a(void)

{
  int in_AX;
  uint uVar1;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)(((uint)(in_AX * 3) >> 1) + *(int *)0x3e86);
  if ((in_AX * 3 & 1U) == 0) {
    uVar1 = uVar1 & 0xfff;
  }
  else {
    uVar1 = uVar1 >> 4;
  }
  if ((1 < uVar1) && (0xff6 < uVar1)) {
    uVar1 = 0xffff;
  }
  return uVar1;
}



/* 1000:6e73  FUN_1000_6e73  38 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_6e73(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  undefined2 in_DX;
  undefined1 uVar2;
  undefined2 local_2;
  
  uVar2 = &stack0xfff0 < (undefined1 *)0x2;
  uVar1 = FUN_1000_6e99();
  uVar1 = FUN_1000_6ecd(uVar1);
  local_2 = in_AX;
  if (!(bool)uVar2) {
    FUN_1000_6f1f();
    FUN_1000_6f1f();
    local_2 = uVar1;
  }
  return CONCAT22(in_DX,local_2);
}



/* 1000:6e99  FUN_1000_6e99  52 bytes, 1 callers */

uint __cdecl16near FUN_1000_6e99(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 unaff_DS;
  
  uVar3 = *(uint *)(*(int *)0x3e94 + 0x1a);
  do {
    uVar2 = uVar3;
    uVar1 = uVar2 * 3;
    uVar3 = *(uint *)((uVar1 >> 1) + *(int *)0x3e86);
    if ((uVar1 & 1) == 0) {
      uVar3 = uVar3 & 0xfff;
    }
    else {
      uVar3 = uVar3 >> 4;
    }
  } while (uVar3 < 0xff7);
  return uVar2;
}



/* 1000:6ecd  FUN_1000_6ecd  48 bytes, 2 callers */

uint __cdecl16near FUN_1000_6ecd(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  iVar4 = *(int *)0x3e86;
  uVar3 = 2;
  iVar2 = 0x262;
  while( true ) {
    iVar4 = iVar4 + 1;
    if ((*(uint *)(uVar3 + iVar4) & 0xfff) == 0) {
      return uVar3;
    }
    uVar1 = *(uint *)(uVar3 + 1 + iVar4);
    if ((uVar1 & 0xfff0) == 0) break;
    uVar3 = uVar3 + 2;
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      *(undefined1 *)0x3e92 = 0xd0;
      return uVar1;
    }
  }
  return uVar3 + 1;
}



/* 1000:6efd  FUN_1000_6efd  34 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_6efd(void)

{
  undefined2 in_AX;
  int iVar1;
  char *pcVar2;
  undefined2 unaff_DS;
  
  pcVar2 = (char *)*(undefined2 *)0x3e82;
  iVar1 = 0xc0;
  while( true ) {
    if (*pcVar2 == '\0') {
      return in_AX;
    }
    if (*pcVar2 == -0x1b) break;
    pcVar2 = pcVar2 + 0x20;
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) {
      *(undefined1 *)0x3e92 = 0xd0;
      return in_AX;
    }
  }
  return in_AX;
}



/* 1000:6f1f  FUN_1000_6f1f  44 bytes, 3 callers */

uint __cdecl16near FUN_1000_6f1f(void)

{
  uint *puVar1;
  int iVar2;
  uint in_AX;
  uint uVar3;
  uint uVar4;
  int in_BX;
  uint uVar5;
  undefined2 unaff_DS;
  
  uVar3 = in_AX & 0xfff;
  uVar5 = (uint)(in_BX * 3) >> 1;
  uVar4 = 0xf000;
  if ((in_BX * 3 & 1U) != 0) {
    uVar3 = in_AX << 4;
    uVar4 = 0xf;
  }
  iVar2 = *(int *)0x3e86;
  puVar1 = (uint *)(uVar5 + iVar2);
  *puVar1 = *puVar1 & uVar4;
  puVar1 = (uint *)(uVar5 + iVar2);
  *puVar1 = *puVar1 | uVar3;
  return in_AX;
}



/* 1000:6f4b  FUN_1000_6f4b  10 bytes, 15 callers */

void __cdecl16near FUN_1000_6f4b(void)

{
  return;
}



/* 1000:6f55  FUN_1000_6f55  16 bytes, 1 callers */

void __cdecl16near FUN_1000_6f55(void)

{
  return;
}



/* 1000:6f65  FUN_1000_6f65  95 bytes, 2 callers */

undefined2 __cdecl16near FUN_1000_6f65(void)

{
  code *pcVar1;
  undefined2 in_stack_00000000;
  
  pcVar1 = (code *)swi(0x1c);
  (*pcVar1)();
  FUN_1000_6fc4();
  FUN_1000_6fc4();
  FUN_1000_6fc4();
  FUN_1000_6fc4();
  FUN_1000_6fc4();
  return in_stack_00000000;
}



/* 1000:6fc4  FUN_1000_6fc4  22 bytes, 3 callers */

undefined4 __cdecl16near FUN_1000_6fc4(void)

{
  byte in_AL;
  undefined2 in_DX;
  
  return CONCAT22(in_DX,(uint)(byte)((in_AL >> 4) * '\n' + (in_AL & 0xf)));
}



/* 1000:6fda  FUN_1000_6fda  42 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_6fda(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  undefined2 uVar3;
  int iVar4;
  undefined2 in_DX;
  char extraout_DH;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 unaff_ES;
  undefined1 in_CF;
  
  FUN_1000_6c69();
  FUN_1000_7004();
  if (!(bool)in_CF) {
    uVar3 = FUN_1000_707a();
    puVar5 = (undefined2 *)((uint)(byte)(extraout_DH - 1) << 10);
    puVar6 = (undefined2 *)&DAT_0000_b98e;
    for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar6;
      puVar6 = puVar6 + 1;
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      *puVar2 = *puVar1;
    }
    FUN_1000_70a6();
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:7004  FUN_1000_7004  87 bytes, 1 callers */

void __cdecl16near FUN_1000_7004(void)

{
  code *pcVar1;
  undefined1 extraout_AH;
  undefined2 in_CX;
  int in_BX;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar2;
  undefined4 uVar3;
  
  FUN_1000_712c();
  if (!(bool)in_CF) {
    FUN_1000_70df();
    FUN_1000_7105();
    return;
  }
  FUN_1000_70bc();
  uVar3 = FUN_1000_70df();
  FUN_1000_707a((int)uVar3,in_BX,in_CX,(int)((ulong)uVar3 >> 0x10));
  *(undefined2 *)((undefined *)&DAT_0000_c016 + in_BX) = 0;
  uVar2 = 0;
  pcVar1 = (code *)swi(0x1b);
  (*pcVar1)();
  *(undefined1 *)0x3e92 = extraout_AH;
  FUN_1000_70a6();
  if (!(bool)uVar2) {
    FUN_1000_7105();
  }
  return;
}



/* 1000:705b  FUN_1000_705b  31 bytes, 2 callers */

undefined2 __cdecl16near FUN_1000_705b(void)

{
  undefined2 in_AX;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  iVar3 = 0;
  iVar2 = *(int *)&DAT_0000_c4e6;
  iVar1 = (uint)*(byte *)&DAT_0000_3e80 << 8;
  do {
    if ((char)((uint)iVar1 >> 8) == *(char *)(iVar3 + -0x3fe9)) {
      iVar1 = FUN_1000_70df();
    }
    iVar3 = iVar3 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return in_AX;
}



/* 1000:707a  FUN_1000_707a  44 bytes, 3 callers */

uint __cdecl16near FUN_1000_707a(void)

{
  int iVar1;
  byte bVar3;
  uint uVar2;
  undefined1 uVar4;
  int in_BX;
  undefined2 unaff_DS;
  
  uVar2 = *(uint *)((undefined *)&DAT_0000_bdae + in_BX);
  bVar3 = (byte)(uVar2 >> 8);
  if (bVar3 < 0xa0) {
    if ((char)uVar2 != '\0') {
      out(0xec,(char)uVar2);
    }
  }
  else {
    iVar1 = (uVar2 & 0xff) * 4;
    out(0x8e9,(char)((uint)iVar1 >> 8));
    uVar4 = (undefined1)iVar1;
    uVar2 = CONCAT11(bVar3,uVar4);
    out(0x8e1,uVar4);
  }
  return uVar2 & 0xff00;
}



/* 1000:70a6  FUN_1000_70a6  22 bytes, 3 callers */

undefined2 __cdecl16near FUN_1000_70a6(void)

{
  undefined2 in_AX;
  int in_BX;
  undefined2 unaff_DS;
  
  if ((byte)((uint)*(undefined2 *)((undefined *)&DAT_0000_bdae + in_BX) >> 8) < 0xa0) {
    if ((char)*(undefined2 *)((undefined *)&DAT_0000_bdae + in_BX) != '\0') {
      out(0xec,0);
    }
  }
  return in_AX;
}



/* 1000:70bc  FUN_1000_70bc  35 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_70bc(void)

{
  undefined2 in_AX;
  uint uVar1;
  int iVar2;
  undefined2 in_DX;
  int iVar3;
  undefined2 unaff_DS;
  
  iVar3 = 0;
  uVar1 = 0xffff;
  iVar2 = *(int *)&DAT_0000_c4e6;
  do {
    if (*(uint *)((undefined *)&DAT_0000_c27e + iVar3) < uVar1) {
      uVar1 = *(uint *)((undefined *)&DAT_0000_c27e + iVar3);
    }
    iVar3 = iVar3 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:70df  FUN_1000_70df  38 bytes, 3 callers */

undefined2 __cdecl16near FUN_1000_70df(void)

{
  uint uVar1;
  undefined2 in_AX;
  int iVar2;
  int in_BX;
  int iVar3;
  undefined2 unaff_DS;
  
  *(undefined2 *)((undefined *)&DAT_0000_c016 + in_BX) = 0;
  LOCK();
  uVar1 = *(uint *)((undefined *)&DAT_0000_c27e + in_BX);
  *(uint *)((undefined *)&DAT_0000_c27e + in_BX) = 0;
  UNLOCK();
  iVar3 = 0;
  iVar2 = *(int *)&DAT_0000_c4e6;
  do {
    if (*(uint *)((undefined *)&DAT_0000_c27e + iVar3) <= uVar1) {
      *(int *)((undefined *)&DAT_0000_c27e + iVar3) =
           *(int *)((undefined *)&DAT_0000_c27e + iVar3) + 1;
    }
    iVar3 = iVar3 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return in_AX;
}



/* 1000:7105  FUN_1000_7105  39 bytes, 1 callers */

void __cdecl16near FUN_1000_7105(void)

{
  undefined2 in_AX;
  int iVar1;
  int in_BX;
  int iVar2;
  undefined2 unaff_DS;
  
  iVar2 = 0;
  iVar1 = *(int *)&DAT_0000_c4e6;
  do {
    if (*(int *)((undefined *)&DAT_0000_c27e + iVar2) != 0) {
      *(int *)((undefined *)&DAT_0000_c27e + iVar2) =
           *(int *)((undefined *)&DAT_0000_c27e + iVar2) + -1;
    }
    iVar2 = iVar2 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined2 *)((undefined *)&DAT_0000_c016 + in_BX) = in_AX;
  *(undefined2 *)((undefined *)&DAT_0000_c27e + in_BX) = 0xffff;
  return;
}



/* 1000:712c  FUN_1000_712c  21 bytes, 2 callers */

void __cdecl16near FUN_1000_712c(void)

{
  int in_AX;
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  iVar2 = 0;
  iVar1 = *(int *)&DAT_0000_c4e6;
  do {
    if (in_AX == *(int *)((undefined *)&DAT_0000_c016 + iVar2)) {
      return;
    }
    iVar2 = iVar2 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}



/* 1000:7141  FUN_1000_7141  202 bytes, 1 callers */

/* WARNING: Removing unreachable block (ram,0x00017188) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16near FUN_1000_7141(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_DS;
  bool bVar6;
  
  *(undefined2 *)&DAT_0000_c4e6 = 0;
  FUN_1000_720b();
  iVar4 = 0xff;
  cVar3 = '\x01';
  do {
    out(0xec,cVar3);
    bVar1 = in(0xec);
    if ((bVar1 & 2) != 0) {
      _DAT_8000_0000 = _DAT_8000_0000 + -0x6928;
      out(0xec,0);
    }
    cVar3 = cVar3 + '\x01';
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 0x1000;
  do {
    out(0xec,0);
    bVar1 = in(0xec);
    if (((bVar1 & 2) != 0) || ((bVar1 & 1) != 0)) break;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  out(0x467,0);
  iVar4 = 4;
  bVar1 = 0;
  do {
    out(0x8e9,bVar1);
    iVar5 = -0x8000;
    do {
      bVar2 = in(0x8e9);
      bVar6 = (bVar2 & 1) != 0;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0 && bVar6);
    if (!bVar6) {
      out(0x8e1,0);
      _DAT_c000_0000 = _DAT_c000_0000 + -0x6928;
      iVar5 = 0x40;
      bVar2 = (byte)(bVar1 >> 1 | bVar1 << 7) >> 1 | (bVar1 >> 1) << 7;
      do {
        FUN_1000_720b(bVar2);
        bVar2 = bVar2 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    bVar1 = bVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}



/* 1000:720b  FUN_1000_720b  63 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_720b(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  uint in_CX;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_DS;
  bool bVar5;
  
  uVar2 = *(int *)&DAT_0000_c4e6 + in_CX;
  uVar3 = uVar2 - 0x134;
  if ((uVar2 < 0x134 || uVar3 == 0) ||
     (bVar5 = uVar3 <= in_CX, in_CX = in_CX - uVar3, bVar5 && in_CX != 0)) {
    iVar4 = *(int *)&DAT_0000_c4e6;
    *(int *)&DAT_0000_c4e6 = *(int *)&DAT_0000_c4e6 + in_CX;
    iVar4 = iVar4 * 2;
    uVar1 = in_AX;
    do {
      *(undefined2 *)((undefined *)&DAT_0000_bdae + iVar4) = uVar1;
      *(undefined2 *)((undefined *)&DAT_0000_c27e + iVar4) = 0;
      *(undefined2 *)((undefined *)&DAT_0000_c016 + iVar4) = 0;
      iVar4 = iVar4 + 2;
      uVar1 = CONCAT11((char)((uint)uVar1 >> 8) + '\x02',(char)uVar1);
      in_CX = in_CX - 1;
    } while (in_CX != 0);
  }
  return in_AX;
}



/* 1000:724a  FUN_1000_724a  24 bytes, 21 callers */

uint __cdecl16near FUN_1000_724a(void)

{
  uint in_AX;
  byte bVar1;
  int iVar2;
  byte bVar3;
  
  bVar1 = (byte)((in_AX & 0xff0f) >> 8);
  out(0x7c,(byte)(in_AX & 0xff0f) ^ 0xf | 0xc0);
  iVar2 = 4;
  do {
    bVar3 = bVar1 & 1;
    bVar1 = bVar1 >> 1;
    out(0x7e,-bVar3);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return in_AX;
}



/* 1000:7262  FUN_1000_7262  24 bytes, 2 callers */

uint __cdecl16near FUN_1000_7262(void)

{
  uint in_AX;
  byte bVar1;
  int iVar2;
  byte bVar3;
  
  bVar1 = (byte)((in_AX & 0xff0f) >> 8);
  out(0x7c,(byte)(in_AX & 0xff0f) ^ 0xf | 0x80);
  iVar2 = 4;
  do {
    bVar3 = bVar1 & 1;
    bVar1 = bVar1 >> 1;
    out(0x7e,-bVar3);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return in_AX;
}



/* 1000:727a  FUN_1000_727a  32 bytes, 11 callers */

undefined2 __cdecl16near FUN_1000_727a(void)

{
  undefined2 uVar1;
  byte bVar2;
  undefined2 *puVar3;
  undefined2 in_AX;
  int iVar4;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  bVar2 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar2 ^ 1;
  out(0xa6,bVar2 ^ 1);
  puVar5 = (undefined2 *)&DAT_0000_648c;
  iVar4 = 0x480;
  do {
    LOCK();
    uVar1 = puVar5[0x480];
    puVar5[0x480] = *puVar5;
    UNLOCK();
    puVar3 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar3 = uVar1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return in_AX;
}



/* 1000:729a  FUN_1000_729a  13 bytes, 3 callers */

undefined2 __cdecl16near FUN_1000_729a(void)

{
  byte bVar1;
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  return in_AX;
}



/* 1000:72a7  FUN_1000_72a7  6 bytes, 8 callers */

void __cdecl16near FUN_1000_72a7(void)

{
  undefined1 in_AL;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x3482 = in_AL;
  out(0xa6,in_AL);
  return;
}



/* 1000:72ad  FUN_1000_72ad  20 bytes, 18 callers */

undefined2 __cdecl16near FUN_1000_72ad(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  *(byte *)0x3483 = *(byte *)0x3483 ^ 1;
  do {
  } while (*(int *)0x32da == *(int *)0x32da);
  return in_AX;
}



/* 1000:72c1  FUN_1000_72c1  15 bytes, 8 callers */

undefined2 __cdecl16near FUN_1000_72c1(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x3483 = (char)in_AX;
  do {
  } while (*(int *)0x32da == *(int *)0x32da);
  return in_AX;
}



/* 1000:72d0  FUN_1000_72d0  119 bytes, 3 callers */

undefined4 __cdecl16near FUN_1000_72d0(void)

{
  undefined2 *puVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint in_AX;
  char cVar5;
  uint uVar4;
  int iVar6;
  byte bVar7;
  undefined2 in_DX;
  undefined2 *puVar8;
  undefined2 unaff_ES;
  
  cVar5 = (char)(in_AX >> 8);
  if (in_AX < 0x3021) {
    out(0xa1,(char)in_AX);
    out(0xa3,cVar5 + -0x20);
    puVar8 = (undefined2 *)0x3e50;
    bVar7 = 0;
    iVar6 = 0x10;
    do {
      out(0xa5,bVar7);
      uVar2 = in(0xa9);
      out(0xa5,bVar7 | 0x20);
      uVar3 = in(0xa9);
      uVar4 = CONCAT11(uVar3,uVar2) * 2 | CONCAT11(uVar3,uVar2);
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar1 = CONCAT11((char)uVar4,(char)(uVar4 >> 8));
      bVar7 = bVar7 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  else {
    out(0xa1,(char)in_AX);
    out(0xa3,cVar5 + -0x20);
    puVar8 = (undefined2 *)0x3e50;
    bVar7 = 0;
    iVar6 = 0x10;
    do {
      out(0xa5,bVar7);
      uVar2 = in(0xa9);
      out(0xa5,bVar7 | 0x20);
      uVar3 = in(0xa9);
      uVar4 = CONCAT11(uVar3,uVar2);
      uVar4 = (uint)(((ulong)~(uVar4 << 2 & uVar4) | 0x10000) >> 1) & uVar4 * 2 | uVar4;
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar1 = CONCAT11((char)uVar4,(char)(uVar4 >> 8));
      bVar7 = bVar7 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:73f8  FUN_1000_73f8  21 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_73f8(void)

{
  byte bVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  
  iVar2 = 0x1000;
  do {
    bVar1 = in(0x188);
    if ((bVar1 & 0x80) == 0) break;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:740d  FUN_1000_740d  44 bytes, 2 callers */

void __cdecl16near FUN_1000_740d(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  if (*(char *)0x3b43 == '\0') {
    uVar1 = FUN_1000_7455();
    out(0x188,(char)uVar1);
    out(0x18a,(char)((uint)uVar1 >> 8));
  }
  return;
}



/* 1000:7455  FUN_1000_7455  13 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_7455(void)

{
  byte bVar1;
  undefined2 in_AX;
  undefined2 in_DX;
  
  do {
    bVar1 = in(0x188);
  } while ((bVar1 & 0x80) != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:74c6  FUN_1000_74c6  82 bytes, 11 callers */

undefined2 __cdecl16near FUN_1000_74c6(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 unaff_DS;
  
  FUN_1000_724a();
  puVar4 = (undefined2 *)0x0;
  for (puVar2 = (undefined2 *)&DAT_0000_3e80; puVar2 != (undefined2 *)0x0;
      puVar2 = (undefined2 *)((int)puVar2 + -1)) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = 0xffff;
  }
  FUN_1000_727a();
  puVar4 = (undefined2 *)0x0;
  for (puVar2 = (undefined2 *)&DAT_0000_3e80; puVar2 != (undefined2 *)0x0;
      puVar2 = (undefined2 *)((int)puVar2 + -1)) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = 0xffff;
  }
  FUN_1000_727a();
  out(0x7c,0);
  iVar5 = 0x3484;
  iVar3 = 6;
  do {
    *(undefined2 *)(iVar5 + 2) = 0;
    *(undefined2 *)(iVar5 + 4) = 0;
    *(undefined2 *)(iVar5 + 6) = 0;
    *(undefined2 *)(iVar5 + 8) = 0;
    iVar5 = iVar5 + 10;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return in_AX;
}



/* 1000:7518  FUN_1000_7518  35 bytes, 3 callers */

undefined2 __cdecl16near FUN_1000_7518(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  FUN_1000_724a();
  puVar3 = (undefined2 *)0x0;
  for (puVar2 = (undefined2 *)&DAT_0000_3e80; puVar2 != (undefined2 *)0x0;
      puVar2 = (undefined2 *)((int)puVar2 + -1)) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0xffff;
  }
  out(0x7c,0);
  return in_AX;
}



/* 1000:753b  FUN_1000_753b  54 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_753b(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  FUN_1000_724a();
  puVar3 = (undefined2 *)0x0;
  for (puVar2 = (undefined2 *)&DAT_0000_3e80; puVar2 != (undefined2 *)0x0;
      puVar2 = (undefined2 *)((int)puVar2 + -1)) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0xffff;
  }
  FUN_1000_727a();
  puVar3 = (undefined2 *)0x0;
  for (puVar2 = (undefined2 *)&DAT_0000_3e80; puVar2 != (undefined2 *)0x0;
      puVar2 = (undefined2 *)((int)puVar2 + -1)) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0xffff;
  }
  FUN_1000_727a();
  out(0x7c,0);
  return in_AX;
}



/* 1000:7571  FUN_1000_7571  42 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_7571(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 *in_BX;
  undefined2 *puVar3;
  
  FUN_1000_724a();
  puVar3 = (undefined2 *)0x168e;
  do {
    for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
      puVar1 = puVar3;
      puVar3 = puVar3 + 1;
      *puVar1 = 0xffff;
    }
    puVar3 = puVar3 + 0xf;
  } while (puVar3 < in_BX);
  out(0x7c,0);
  return in_AX;
}



/* 1000:759b  FUN_1000_759b  195 bytes, 8 callers */

undefined4 __cdecl16near FUN_1000_759b(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined2 in_AX;
  uint uVar3;
  int iVar4;
  undefined2 in_DX;
  byte *unaff_SI;
  byte *pbVar5;
  int unaff_DI;
  byte *pbVar6;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  bool bVar7;
  undefined4 uVar8;
  uint local_14;
  undefined2 uVar9;
  
  uVar9 = 0;
  local_14 = 0x50;
  iVar4 = 0xa0;
  pbVar5 = unaff_SI;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pbVar1 = pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (*pbVar1 != 0);
LAB_1000_75d1:
  do {
    pbVar5 = unaff_SI + 1;
    bVar2 = *unaff_SI;
    if (bVar2 < 0x20) {
      if ((bVar2 == 0) || (bVar2 < 0x10)) goto LAB_1000_78b0;
      *(char *)0x32a9 = bVar2 - 0x10;
      unaff_SI = pbVar5;
      goto LAB_1000_75d1;
    }
    if (bVar2 == 0x20) {
joined_r0x0001762c:
      unaff_SI = pbVar5;
      local_14 = local_14 - 1;
      unaff_DI = unaff_DI + 1;
      if (local_14 == 0) goto LAB_1000_78b0;
    }
    else {
      if (bVar2 == 0x40) {
        pbVar1 = pbVar5;
        pbVar5 = unaff_SI + 2;
        bVar2 = *pbVar1;
        iVar4 = 0x1c;
        pbVar6 = (byte *)0x2847;
        bVar7 = true;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          pbVar1 = pbVar6;
          pbVar6 = pbVar6 + 1;
          bVar7 = bVar2 == *pbVar1;
        } while (!bVar7);
        if (bVar7) {
                    /* WARNING: Could not recover jumptable at 0x00017664. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar8 = (*(code *)*(undefined2 *)((int)(pbVar6 + -0x2848) * 2 + 0x78bb))(uVar9);
          return uVar8;
        }
      }
      if ((bVar2 < 0x80) || ((0x9f < bVar2 && (bVar2 < 0xe0)))) {
        FUN_1000_7a52();
        goto joined_r0x0001762c;
      }
      if (CONCAT11(bVar2,*pbVar5) != 0x4081) {
        uVar3 = FUN_1000_9a54();
        if ((0x2920 < uVar3) && (uVar3 < 0x2b7f)) {
          FUN_1000_72d0();
          FUN_1000_79f5();
          pbVar5 = pbVar5 + 1;
          goto joined_r0x0001762c;
        }
        FUN_1000_72d0();
        FUN_1000_7958();
      }
      unaff_DI = unaff_DI + 2;
      bVar7 = local_14 < 2;
      unaff_SI = pbVar5 + 1;
      local_14 = local_14 - 2;
      if (bVar7) {
LAB_1000_78b0:
        *(int *)0x3e76 = unaff_DI;
        return CONCAT22(in_DX,in_AX);
      }
    }
  } while( true );
}



/* 1000:78f3  FUN_1000_78f3  29 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_78f3(void)

{
  int *piVar1;
  undefined2 in_AX;
  undefined2 in_DX;
  int *unaff_SI;
  undefined2 unaff_DS;
  
  while( true ) {
    piVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    if ((char)*piVar1 == '\0') break;
    if (*piVar1 != 0x4081) {
      FUN_1000_9a54();
      FUN_1000_72d0();
      FUN_1000_79a6();
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:7958  FUN_1000_7958  78 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_7958(void)

{
  undefined2 in_AX;
  undefined2 *unaff_DI;
  undefined2 unaff_DS;
  
  FUN_1000_724a();
  *unaff_DI = *(undefined2 *)0x3e50;
  unaff_DI[0x28] = *(undefined2 *)0x3e52;
  unaff_DI[0x50] = *(undefined2 *)0x3e54;
  unaff_DI[0x78] = *(undefined2 *)0x3e56;
  unaff_DI[0xa0] = *(undefined2 *)0x3e58;
  unaff_DI[200] = *(undefined2 *)0x3e5a;
  unaff_DI[0xf0] = *(undefined2 *)0x3e5c;
  unaff_DI[0x118] = *(undefined2 *)0x3e5e;
  unaff_DI[0x140] = *(undefined2 *)0x3e60;
  unaff_DI[0x168] = *(undefined2 *)0x3e62;
  unaff_DI[400] = *(undefined2 *)0x3e64;
  unaff_DI[0x1b8] = *(undefined2 *)0x3e66;
  unaff_DI[0x1e0] = *(undefined2 *)0x3e68;
  unaff_DI[0x208] = *(undefined2 *)0x3e6a;
  unaff_DI[0x230] = *(undefined2 *)0x3e6c;
  unaff_DI[600] = *(undefined2 *)0x3e6e;
  out(0x7c,0);
  return in_AX;
}



/* 1000:79a6  FUN_1000_79a6  79 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_79a6(void)

{
  uint *puVar1;
  uint uVar2;
  undefined2 in_AX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  undefined2 *unaff_DI;
  undefined2 unaff_DS;
  
  FUN_1000_724a();
  puVar6 = (uint *)0x3e50;
  iVar5 = 0x10;
  do {
    puVar1 = puVar6;
    puVar6 = puVar6 + 1;
    uVar2 = *puVar1;
    unaff_DI[-0x28] = uVar2;
    unaff_DI[0x28] = uVar2;
    uVar3 = CONCAT11((char)uVar2,(char)(uVar2 >> 8));
    uVar4 = uVar3 | uVar3 * 2 | uVar3 >> 1;
    *(bool *)((int)unaff_DI + -1) = CARRY2(uVar3,uVar3);
    *unaff_DI = CONCAT11((char)uVar4,(char)(uVar4 >> 8));
    *(char *)((int)unaff_DI + 1) = ((uVar2 & 0x100) != 0) << 7;
    unaff_DI = unaff_DI + 0x28;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  out(0x7c,0);
  return in_AX;
}



/* 1000:79f5  FUN_1000_79f5  93 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_79f5(void)

{
  undefined2 in_AX;
  undefined1 *unaff_DI;
  undefined2 unaff_DS;
  
  FUN_1000_724a();
  *unaff_DI = *(undefined1 *)0x3e50;
  unaff_DI[0x50] = *(undefined1 *)0x3e52;
  unaff_DI[0xa0] = *(undefined1 *)0x3e54;
  unaff_DI[0xf0] = *(undefined1 *)0x3e56;
  unaff_DI[0x140] = *(undefined1 *)0x3e58;
  unaff_DI[400] = *(undefined1 *)0x3e5a;
  unaff_DI[0x1e0] = *(undefined1 *)0x3e5c;
  unaff_DI[0x230] = *(undefined1 *)0x3e5e;
  unaff_DI[0x280] = *(undefined1 *)0x3e60;
  unaff_DI[0x2d0] = *(undefined1 *)0x3e62;
  unaff_DI[800] = *(undefined1 *)0x3e64;
  unaff_DI[0x370] = *(undefined1 *)0x3e66;
  unaff_DI[0x3c0] = *(undefined1 *)0x3e68;
  unaff_DI[0x410] = *(undefined1 *)0x3e6a;
  unaff_DI[0x460] = *(undefined1 *)0x3e6c;
  unaff_DI[0x4b0] = *(undefined1 *)0x3e6e;
  out(0x7c,0);
  return in_AX;
}



/* 1000:7a52  FUN_1000_7a52  89 bytes, 1 callers */

uint __cdecl16near FUN_1000_7a52(void)

{
  uint in_AX;
  int iVar1;
  undefined1 *unaff_DI;
  
  iVar1 = (in_AX & 0xff) + 0x2500;
  FUN_1000_724a();
  *unaff_DI = *(undefined1 *)0x0;
  unaff_DI[0x50] = *(undefined1 *)0x1;
  unaff_DI[0xa0] = *(undefined1 *)0x2;
  unaff_DI[0xf0] = *(undefined1 *)0x3;
  unaff_DI[0x140] = *(undefined1 *)0x4;
  unaff_DI[400] = *(undefined1 *)0x5;
  unaff_DI[0x1e0] = *(undefined1 *)0x6;
  unaff_DI[0x230] = *(undefined1 *)0x7;
  unaff_DI[0x280] = *(undefined1 *)0x8;
  unaff_DI[0x2d0] = *(undefined1 *)0x9;
  unaff_DI[800] = *(undefined1 *)0xa;
  unaff_DI[0x370] = *(undefined1 *)0xb;
  unaff_DI[0x3c0] = *(undefined1 *)0xc;
  unaff_DI[0x410] = *(undefined1 *)0xd;
  unaff_DI[0x460] = *(undefined1 *)0xe;
  unaff_DI[0x4b0] = *(undefined1 *)0xf;
  out(0x7c,0);
  return in_AX;
}



/* 1000:7aab  FUN_1000_7aab  40 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_7aab(void)

{
  undefined1 *puVar1;
  undefined2 in_AX;
  char cVar2;
  int in_CX;
  int iVar3;
  undefined2 in_DX;
  undefined1 *unaff_DI;
  
  FUN_1000_724a();
  cVar2 = '\x10';
  iVar3 = in_CX;
  do {
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar1 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      *puVar1 = 0xff;
    }
    unaff_DI = unaff_DI + (0x50 - in_CX);
    cVar2 = cVar2 + -1;
    iVar3 = in_CX;
  } while (cVar2 != '\0');
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:7ad3  FUN_1000_7ad3  195 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_7ad3(void)

{
  undefined2 in_AX;
  byte bVar1;
  int in_CX;
  int iVar2;
  undefined2 in_DX;
  uint in_BX;
  uint unaff_SI;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int unaff_DI;
  uint uVar6;
  byte *pbVar7;
  byte bVar8;
  bool bVar9;
  
  FUN_1000_724a();
  iVar2 = in_CX;
  uVar4 = in_BX;
  if (unaff_SI < in_BX) {
    iVar2 = unaff_DI;
    uVar4 = unaff_SI;
    unaff_SI = in_BX;
    unaff_DI = in_CX;
  }
  uVar3 = unaff_SI - uVar4;
  uVar6 = unaff_DI - iVar2;
  bVar1 = (byte)uVar4 & 7;
  bVar1 = 0x80U >> bVar1 | -0x80 << 8 - bVar1;
  pbVar7 = (byte *)(iVar2 * 0x50 + (uVar4 >> 3));
  if ((int)uVar6 < 0) {
    uVar4 = -uVar6;
    if (uVar3 < uVar4) {
      uVar6 = uVar4 >> 1;
      iVar2 = uVar4 + 1;
      do {
        *pbVar7 = bVar1;
        pbVar7 = pbVar7 + -0x50;
        bVar9 = uVar6 < uVar3;
        uVar6 = uVar6 - uVar3;
        if (bVar9) {
          uVar6 = uVar6 + uVar4;
          bVar8 = bVar1 & 1;
          bVar1 = bVar1 >> 1 | bVar1 << 7;
          pbVar7 = pbVar7 + bVar8;
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    else {
      uVar5 = uVar3 >> 1;
      iVar2 = uVar3 + 1;
      do {
        *pbVar7 = bVar1;
        bVar8 = bVar1 & 1;
        bVar1 = bVar1 >> 1 | bVar1 << 7;
        pbVar7 = pbVar7 + bVar8;
        bVar9 = uVar5 < uVar4;
        uVar5 = uVar5 + uVar6;
        if (bVar9) {
          uVar5 = uVar5 + uVar3;
          pbVar7 = pbVar7 + -0x50;
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  else if (uVar3 < uVar6) {
    uVar4 = uVar6 >> 1;
    iVar2 = uVar6 + 1;
    do {
      *pbVar7 = bVar1;
      pbVar7 = pbVar7 + 0x50;
      bVar9 = uVar4 < uVar3;
      uVar4 = uVar4 - uVar3;
      if (bVar9) {
        uVar4 = uVar4 + uVar6;
        bVar8 = bVar1 & 1;
        bVar1 = bVar1 >> 1 | bVar1 << 7;
        pbVar7 = pbVar7 + bVar8;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  else {
    uVar4 = uVar3 >> 1;
    iVar2 = uVar3 + 1;
    do {
      *pbVar7 = bVar1;
      bVar8 = bVar1 & 1;
      bVar1 = bVar1 >> 1 | bVar1 << 7;
      pbVar7 = pbVar7 + bVar8;
      bVar9 = uVar4 < uVar6;
      uVar4 = uVar4 - uVar6;
      if (bVar9) {
        uVar4 = uVar4 + uVar3;
        pbVar7 = pbVar7 + 0x50;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:7c1c  FUN_1000_7c1c  130 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_7c1c(void)

{
  byte *pbVar1;
  undefined2 in_AX;
  byte bVar2;
  byte bVar3;
  uint in_CX;
  uint uVar4;
  uint uVar5;
  undefined2 in_DX;
  uint in_BX;
  uint uVar6;
  uint unaff_SI;
  byte *pbVar7;
  uint unaff_DI;
  byte *pbVar8;
  bool bVar9;
  int local_16;
  
  FUN_1000_724a();
  uVar6 = in_BX;
  if (unaff_SI < in_BX) {
    uVar6 = unaff_SI;
    unaff_SI = in_BX;
  }
  uVar4 = in_CX;
  if (unaff_DI < in_CX) {
    uVar4 = unaff_DI;
    unaff_DI = in_CX;
  }
  bVar3 = (byte)uVar6 & 7;
  pbVar7 = (byte *)(uVar4 * 0x50 + (uVar6 >> 3));
  local_16 = (unaff_DI - uVar4) + 1;
  do {
    uVar4 = (unaff_SI - uVar6) + 1;
    bVar2 = 0x80U >> bVar3 | -0x80 << 8 - bVar3;
    do {
      *pbVar7 = bVar2;
      uVar4 = uVar4 - 1;
      if (uVar4 == 0) goto LAB_1000_7c8d;
      bVar9 = (bool)(bVar2 & 1);
      bVar2 = bVar2 >> 1 | bVar2 << 7;
    } while (!bVar9);
    pbVar8 = pbVar7 + 1;
    uVar5 = uVar4 >> 3;
    if (uVar5 != 0) {
      for (; uVar5 != 0; uVar5 = uVar5 - 1) {
        pbVar1 = pbVar8;
        pbVar8 = pbVar8 + 1;
        *pbVar1 = 0xff;
      }
    }
    for (uVar4 = uVar4 & 7; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pbVar8 = bVar2;
      bVar2 = bVar2 >> 1 | bVar2 << 7;
    }
LAB_1000_7c8d:
    pbVar7 = pbVar7 + 0x50;
    local_16 = local_16 + -1;
    if (local_16 == 0) {
      out(0x7c,0);
      return CONCAT22(in_DX,in_AX);
    }
  } while( true );
}



/* 1000:7c9e  FUN_1000_7c9e  330 bytes, 15 callers */

undefined4 __cdecl16near FUN_1000_7c9e(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  int in_BX;
  undefined2 unaff_DS;
  
  if (*(int *)0x34c8 != 0) {
    FUN_1000_727a();
    if (*(int *)0x3bc4 == -1) {
      FUN_1000_7de8();
    }
    else {
      FUN_1000_7fa8();
    }
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_727a();
  if (*(int *)0x3bc2 == -1) {
    FUN_1000_7de8();
    FUN_1000_7aab();
    FUN_1000_7aab();
    FUN_1000_7aab();
    FUN_1000_7aab();
    FUN_1000_7aab();
    FUN_1000_7aab();
    FUN_1000_7aab();
    goto LAB_1000_7dcf;
  }
  if (*(int *)0x3288 == 1) {
    FUN_1000_81d6();
  }
  else if (*(int *)0x3288 == 2) {
    FUN_1000_83fb();
  }
  else {
    FUN_1000_7e3e();
  }
  FUN_1000_93c5();
  FUN_1000_7aab();
  FUN_1000_759b();
  FUN_1000_7aab();
  FUN_1000_759b();
  FUN_1000_7aab();
  FUN_1000_7aab();
  FUN_1000_9b34();
  if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0) {
    if (*(int *)&DAT_0000_32bf != 0) goto LAB_1000_7d1c;
  }
  else {
    *(int *)&DAT_0000_32bf = *(int *)((undefined *)&DAT_0000_e47e + in_BX);
LAB_1000_7d1c:
    FUN_1000_ac00();
    FUN_1000_8738();
    FUN_1000_c5bb();
    FUN_1000_759b();
    FUN_1000_759b();
  }
  FUN_1000_8756();
  FUN_1000_7aab();
  *(uint *)0x34c2 = (uint)(byte)((undefined *)&DAT_0000_d27f)[in_BX];
  *(undefined2 *)0x34c4 = *(undefined2 *)&DAT_0000_3be4;
  FUN_1000_759b();
  FUN_1000_7aab();
  FUN_1000_759b();
LAB_1000_7dcf:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:7de8  FUN_1000_7de8  86 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_7de8(void)

{
  uint *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int iVar3;
  undefined2 in_DX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  undefined2 *puVar9;
  
  puVar8 = (uint *)0x28c;
  iVar7 = 0xc0;
  uVar4 = 0x4444;
  do {
    for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar1 = 0;
    }
    puVar8 = puVar8 + 0x10;
    for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar1 = uVar4;
    }
    puVar8 = puVar8 + 0x10;
    uVar4 = (uVar4 >> 1 | (uint)((uVar4 & 1) != 0) << 0xf) >> 1 |
            (uint)((uVar4 >> 1 & 1) != 0) << 0xf;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar4 = 0xb000;
  do {
    uVar5 = uVar4;
    puVar9 = (undefined2 *)0x28c;
    iVar7 = 0x180;
    do {
      for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
        puVar2 = puVar9;
        puVar9 = puVar9 + 1;
        *puVar2 = 0;
      }
      puVar9 = puVar9 + 0x10;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    uVar6 = uVar5 + 0x800;
    uVar4 = uVar6;
  } while ((uVar6 < 0xb801) || (uVar4 = uVar5 + 0x2800, uVar6 < 0xe000));
  return CONCAT22(in_DX,in_AX);
}



/* 1000:7e3e  FUN_1000_7e3e  362 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_7e3e(void)

{
  char cVar1;
  byte bVar2;
  undefined2 in_AX;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 in_DX;
  int extraout_DX;
  int extraout_DX_00;
  byte *pbVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined2 unaff_SS;
  
  puVar8 = (undefined1 *)0x28c;
  iVar7 = 0;
  pbVar6 = (byte *)&DAT_0000_648c;
  iVar4 = 0x30;
  do {
    iVar5 = 0x30;
    do {
      puVar9 = puVar8;
      bVar2 = ((undefined *)&DAT_0000_d27e)[iVar7];
      iVar3 = *(int *)((undefined *)&DAT_0000_e47e + iVar7);
      if (iVar3 != 0) {
        cVar1 = *(char *)(iVar3 + 0xc) * '\x04';
        bVar2 = cVar1 + 0x80;
        if (bVar2 != 0x90) {
          if ((*(byte *)(iVar3 + 10) & 0x20) == 0) {
            if ((999 < *(uint *)(iVar3 + 6)) &&
               (bVar2 = cVar1 + 0x81,
               (undefined2 *)&DAT_0000_270f < (undefined2 *)*(undefined2 *)(iVar3 + 6))) {
              bVar2 = cVar1 + 0x82;
            }
          }
          else {
            bVar2 = cVar1 + 0x83;
          }
        }
      }
      if (bVar2 != *pbVar6) {
        *pbVar6 = bVar2;
        iVar3 = (uint)bVar2 * 2 + 0x7000;
        *puVar9 = *(undefined1 *)0x0;
        puVar9[0x50] = *(undefined1 *)0x1;
        puVar9[0xa0] = *(undefined1 *)0x2;
        puVar9[0xf0] = *(undefined1 *)0x3;
        puVar9[0x140] = *(undefined1 *)0x4;
        puVar9[400] = *(undefined1 *)0x5;
        puVar9[0x1e0] = *(undefined1 *)0x6;
        puVar9[0x230] = *(undefined1 *)0x7;
        *puVar9 = *(undefined1 *)0x8;
        puVar9[0x50] = *(undefined1 *)0x9;
        puVar9[0xa0] = *(undefined1 *)0xa;
        puVar9[0xf0] = *(undefined1 *)0xb;
        puVar9[0x140] = *(undefined1 *)0xc;
        puVar9[400] = *(undefined1 *)0xd;
        puVar9[0x1e0] = *(undefined1 *)0xe;
        puVar9[0x230] = *(undefined1 *)0xf;
        *puVar9 = *(undefined1 *)0x10;
        puVar9[0x50] = *(undefined1 *)0x11;
        puVar9[0xa0] = *(undefined1 *)0x12;
        puVar9[0xf0] = *(undefined1 *)0x13;
        puVar9[0x140] = *(undefined1 *)0x14;
        puVar9[400] = *(undefined1 *)0x15;
        puVar9[0x1e0] = *(undefined1 *)0x16;
        puVar9[0x230] = *(undefined1 *)0x17;
        *puVar9 = *(undefined1 *)0x18;
        puVar9[0x50] = *(undefined1 *)0x19;
        puVar9[0xa0] = *(undefined1 *)0x1a;
        puVar9[0xf0] = *(undefined1 *)0x1b;
        puVar9[0x140] = *(undefined1 *)0x1c;
        puVar9[400] = *(undefined1 *)0x1d;
        puVar9[0x1e0] = *(undefined1 *)0x1e;
        puVar9[0x230] = *(undefined1 *)0x1f;
      }
      pbVar6 = pbVar6 + 1;
      iVar7 = iVar7 + 2;
      iVar5 = iVar5 + -1;
      puVar8 = puVar9 + 0x280;
    } while (iVar5 != 0);
    puVar8 = puVar9 + -0x757f;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = DAT_0000_3be4 * 0x200 + (DAT_0000_3be4 & 0xff) * 0x80 + (DAT_0000_3be4 >> 8);
  ((undefined *)&DAT_0000_648c)[(DAT_0000_3be4 & 0xff) + (DAT_0000_3be4 >> 8) * 0x30] = 0xff;
  FUN_1000_724a();
  *(undefined1 *)(iVar4 + 0x28c) = DAT_0000_26bb;
  puVar8 = (undefined1 *)(iVar4 + 0x28d + extraout_DX);
  *puVar8 = DAT_0000_26bc;
  puVar8 = puVar8 + extraout_DX + 1;
  *puVar8 = DAT_0000_26bd;
  puVar8 = puVar8 + extraout_DX + 1;
  *puVar8 = DAT_0000_26be;
  puVar8 = puVar8 + extraout_DX + 1;
  *puVar8 = DAT_0000_26bf;
  puVar8 = puVar8 + extraout_DX + 1;
  *puVar8 = DAT_0000_26c0;
  puVar8[extraout_DX + 1] = DAT_0000_26c1;
  (puVar8 + extraout_DX + 1)[extraout_DX + 1] = DAT_0000_26c2;
  FUN_1000_724a();
  *(undefined1 *)(iVar4 + 0x28c) = DAT_0000_26c3;
  puVar8 = (undefined1 *)(iVar4 + 0x28d + extraout_DX_00);
  *puVar8 = DAT_0000_26c4;
  puVar8 = puVar8 + extraout_DX_00 + 1;
  *puVar8 = DAT_0000_26c5;
  puVar8 = puVar8 + extraout_DX_00 + 1;
  *puVar8 = DAT_0000_26c6;
  puVar8 = puVar8 + extraout_DX_00 + 1;
  *puVar8 = DAT_0000_26c7;
  puVar8 = puVar8 + extraout_DX_00 + 1;
  *puVar8 = DAT_0000_26c8;
  puVar8[extraout_DX_00 + 1] = DAT_0000_26c9;
  (puVar8 + extraout_DX_00 + 1)[extraout_DX_00 + 1] = DAT_0000_26ca;
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:7fa8  FUN_1000_7fa8  558 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_7fa8(void)

{
  byte bVar1;
  undefined2 in_AX;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 in_DX;
  int extraout_DX;
  int extraout_DX_00;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  undefined2 unaff_SS;
  
  pbVar7 = (byte *)0x28c;
  iVar6 = 0;
  pbVar5 = (byte *)&DAT_0000_648c;
  iVar3 = 0x30;
  do {
    iVar4 = 0x30;
    do {
      pbVar8 = pbVar7;
      bVar1 = ((undefined *)&DAT_0000_d27e)[iVar6];
      if (bVar1 != *pbVar5) {
        *pbVar5 = bVar1;
        if (CARRY1(bVar1,bVar1)) {
          iVar2 = (byte)(bVar1 * '\x02') + 0x7000;
          *pbVar8 = *(byte *)0x0 | 0x55;
          pbVar8[0x50] = *(byte *)0x1 | 0x55;
          pbVar8[0xa0] = *(byte *)0x2 | 0x55;
          pbVar8[0xf0] = *(byte *)0x3 | 0x55;
          pbVar8[0x140] = *(byte *)0x4 | 0x55;
          pbVar8[400] = *(byte *)0x5 | 0x55;
          pbVar8[0x1e0] = *(byte *)0x6 | 0x55;
          pbVar8[0x230] = *(byte *)0x7 | 0x55;
          *pbVar8 = *(byte *)0x8 | 0x55;
          pbVar8[0x50] = *(byte *)0x9 | 0x55;
          pbVar8[0xa0] = *(byte *)0xa | 0x55;
          pbVar8[0xf0] = *(byte *)0xb | 0x55;
          pbVar8[0x140] = *(byte *)0xc | 0x55;
          pbVar8[400] = *(byte *)0xd | 0x55;
          pbVar8[0x1e0] = *(byte *)0xe | 0x55;
          pbVar8[0x230] = *(byte *)0xf | 0x55;
          *pbVar8 = *(byte *)0x10 | 0x55;
          pbVar8[0x50] = *(byte *)0x11 | 0x55;
          pbVar8[0xa0] = *(byte *)0x12 | 0x55;
          pbVar8[0xf0] = *(byte *)0x13 | 0x55;
          pbVar8[0x140] = *(byte *)0x14 | 0x55;
          pbVar8[400] = *(byte *)0x15 | 0x55;
          pbVar8[0x1e0] = *(byte *)0x16 | 0x55;
          pbVar8[0x230] = *(byte *)0x17 | 0x55;
          *pbVar8 = *(byte *)0x18 | 0x55;
          pbVar8[0x50] = *(byte *)0x19 | 0x55;
          pbVar8[0xa0] = *(byte *)0x1a | 0x55;
          pbVar8[0xf0] = *(byte *)0x1b | 0x55;
          pbVar8[0x140] = *(byte *)0x1c | 0x55;
          pbVar8[400] = *(byte *)0x1d | 0x55;
          pbVar8[0x1e0] = *(byte *)0x1e | 0x55;
          pbVar8[0x230] = *(byte *)0x1f | 0x55;
        }
        else {
          iVar2 = (byte)(bVar1 * '\x02') + 0x7000;
          *pbVar8 = *(byte *)0x0;
          pbVar8[0x50] = *(byte *)0x1;
          pbVar8[0xa0] = *(byte *)0x2;
          pbVar8[0xf0] = *(byte *)0x3;
          pbVar8[0x140] = *(byte *)0x4;
          pbVar8[400] = *(byte *)0x5;
          pbVar8[0x1e0] = *(byte *)0x6;
          pbVar8[0x230] = *(byte *)0x7;
          *pbVar8 = *(byte *)0x8;
          pbVar8[0x50] = *(byte *)0x9;
          pbVar8[0xa0] = *(byte *)0xa;
          pbVar8[0xf0] = *(byte *)0xb;
          pbVar8[0x140] = *(byte *)0xc;
          pbVar8[400] = *(byte *)0xd;
          pbVar8[0x1e0] = *(byte *)0xe;
          pbVar8[0x230] = *(byte *)0xf;
          *pbVar8 = *(byte *)0x10;
          pbVar8[0x50] = *(byte *)0x11;
          pbVar8[0xa0] = *(byte *)0x12;
          pbVar8[0xf0] = *(byte *)0x13;
          pbVar8[0x140] = *(byte *)0x14;
          pbVar8[400] = *(byte *)0x15;
          pbVar8[0x1e0] = *(byte *)0x16;
          pbVar8[0x230] = *(byte *)0x17;
          *pbVar8 = *(byte *)0x18;
          pbVar8[0x50] = *(byte *)0x19;
          pbVar8[0xa0] = *(byte *)0x1a;
          pbVar8[0xf0] = *(byte *)0x1b;
          pbVar8[0x140] = *(byte *)0x1c;
          pbVar8[400] = *(byte *)0x1d;
          pbVar8[0x1e0] = *(byte *)0x1e;
          pbVar8[0x230] = *(byte *)0x1f;
        }
      }
      pbVar5 = pbVar5 + 1;
      iVar6 = iVar6 + 2;
      iVar4 = iVar4 + -1;
      pbVar7 = pbVar8 + 0x280;
    } while (iVar4 != 0);
    pbVar7 = pbVar8 + -0x757f;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (DAT_0000_3298 == -1) {
    iVar3 = DAT_0000_3be4 * 0x200 + (DAT_0000_3be4 & 0xff) * 0x80 + (DAT_0000_3be4 >> 8);
    ((undefined *)&DAT_0000_648c)[(DAT_0000_3be4 & 0xff) + (DAT_0000_3be4 >> 8) * 0x30] = 0xff;
    FUN_1000_724a();
    *(undefined1 *)(iVar3 + 0x28c) = DAT_0000_26bb;
    puVar9 = (undefined1 *)(iVar3 + 0x28d + extraout_DX);
    *puVar9 = DAT_0000_26bc;
    puVar9 = puVar9 + extraout_DX + 1;
    *puVar9 = DAT_0000_26bd;
    puVar9 = puVar9 + extraout_DX + 1;
    *puVar9 = DAT_0000_26be;
    puVar9 = puVar9 + extraout_DX + 1;
    *puVar9 = DAT_0000_26bf;
    puVar9 = puVar9 + extraout_DX + 1;
    *puVar9 = DAT_0000_26c0;
    puVar9[extraout_DX + 1] = DAT_0000_26c1;
    (puVar9 + extraout_DX + 1)[extraout_DX + 1] = DAT_0000_26c2;
    FUN_1000_724a();
    *(undefined1 *)(iVar3 + 0x28c) = DAT_0000_26c3;
    puVar9 = (undefined1 *)(iVar3 + 0x28d + extraout_DX_00);
    *puVar9 = DAT_0000_26c4;
    puVar9 = puVar9 + extraout_DX_00 + 1;
    *puVar9 = DAT_0000_26c5;
    puVar9 = puVar9 + extraout_DX_00 + 1;
    *puVar9 = DAT_0000_26c6;
    puVar9 = puVar9 + extraout_DX_00 + 1;
    *puVar9 = DAT_0000_26c7;
    puVar9 = puVar9 + extraout_DX_00 + 1;
    *puVar9 = DAT_0000_26c8;
    puVar9[extraout_DX_00 + 1] = DAT_0000_26c9;
    (puVar9 + extraout_DX_00 + 1)[extraout_DX_00 + 1] = DAT_0000_26ca;
    out(0x7c,0);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:81d6  FUN_1000_81d6  549 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_81d6(void)

{
  undefined2 *puVar1;
  uint *puVar2;
  byte bVar3;
  undefined2 in_AX;
  uint uVar4;
  byte bVar6;
  int iVar5;
  int iVar7;
  int iVar8;
  undefined2 in_DX;
  int extraout_DX;
  int extraout_DX_00;
  int in_BX;
  int *piVar9;
  int *piVar10;
  undefined2 *puVar11;
  uint *puVar12;
  undefined2 *puVar13;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  puVar11 = (undefined2 *)&DAT_0000_788e;
  for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {
    puVar1 = puVar11;
    puVar11 = puVar11 + 1;
    *puVar1 = 0;
  }
  FUN_1000_9b34();
  puVar12 = (uint *)0x600c;
  iVar7 = 0x18;
  do {
    iVar8 = 0x18;
    do {
      iVar5 = in_BX;
      uVar4 = (uint)(byte)((undefined *)&DAT_0000_d27e)[iVar5];
      if (*(int *)((undefined *)&DAT_0000_e47e + iVar5) != 0) {
        FUN_1000_ac00();
        uVar4 = FUN_1000_9c09();
        puVar12[0x240] = 0xffff;
      }
      puVar2 = puVar12;
      puVar12 = puVar12 + 1;
      *puVar2 = uVar4;
      iVar8 = iVar8 + -1;
      in_BX = iVar5 + 2;
    } while (iVar8 != 0);
    in_BX = iVar5 + 0x32;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar11 = (undefined2 *)0x28c;
  piVar9 = (int *)0x600a;
  iVar7 = 0x18;
  do {
    iVar8 = 0x18;
    piVar10 = piVar9;
    do {
      puVar13 = puVar11;
      piVar9 = piVar10 + 1;
      iVar5 = *piVar9;
      if (iVar5 != piVar10[0x241]) {
        piVar10[0x241] = iVar5;
        iVar5 = iVar5 * 8 + 0x3000;
        *puVar13 = *(undefined2 *)0x0;
        puVar13[0x28] = *(undefined2 *)0x2;
        puVar13[0x50] = *(undefined2 *)0x4;
        puVar13[0x78] = *(undefined2 *)0x6;
        puVar13[0xa0] = *(undefined2 *)0x8;
        puVar13[200] = *(undefined2 *)0xa;
        puVar13[0xf0] = *(undefined2 *)0xc;
        puVar13[0x118] = *(undefined2 *)0xe;
        puVar13[0x140] = *(undefined2 *)0x10;
        puVar13[0x168] = *(undefined2 *)0x12;
        puVar13[400] = *(undefined2 *)0x14;
        puVar13[0x1b8] = *(undefined2 *)0x16;
        puVar13[0x1e0] = *(undefined2 *)0x18;
        puVar13[0x208] = *(undefined2 *)0x1a;
        puVar13[0x230] = *(undefined2 *)0x1c;
        puVar13[600] = *(undefined2 *)0x1e;
        *puVar13 = *(undefined2 *)0x20;
        puVar13[0x28] = *(undefined2 *)0x22;
        puVar13[0x50] = *(undefined2 *)0x24;
        puVar13[0x78] = *(undefined2 *)0x26;
        puVar13[0xa0] = *(undefined2 *)0x28;
        puVar13[200] = *(undefined2 *)0x2a;
        puVar13[0xf0] = *(undefined2 *)0x2c;
        puVar13[0x118] = *(undefined2 *)0x2e;
        puVar13[0x140] = *(undefined2 *)0x30;
        puVar13[0x168] = *(undefined2 *)0x32;
        puVar13[400] = *(undefined2 *)0x34;
        puVar13[0x1b8] = *(undefined2 *)0x36;
        puVar13[0x1e0] = *(undefined2 *)0x38;
        puVar13[0x208] = *(undefined2 *)0x3a;
        puVar13[0x230] = *(undefined2 *)0x3c;
        puVar13[600] = *(undefined2 *)0x3e;
        *puVar13 = *(undefined2 *)0x40;
        puVar13[0x28] = *(undefined2 *)0x42;
        puVar13[0x50] = *(undefined2 *)0x44;
        puVar13[0x78] = *(undefined2 *)0x46;
        puVar13[0xa0] = *(undefined2 *)0x48;
        puVar13[200] = *(undefined2 *)0x4a;
        puVar13[0xf0] = *(undefined2 *)0x4c;
        puVar13[0x118] = *(undefined2 *)0x4e;
        puVar13[0x140] = *(undefined2 *)0x50;
        puVar13[0x168] = *(undefined2 *)0x52;
        puVar13[400] = *(undefined2 *)0x54;
        puVar13[0x1b8] = *(undefined2 *)0x56;
        puVar13[0x1e0] = *(undefined2 *)0x58;
        puVar13[0x208] = *(undefined2 *)0x5a;
        puVar13[0x230] = *(undefined2 *)0x5c;
        puVar13[600] = *(undefined2 *)0x5e;
        *puVar13 = *(undefined2 *)0x60;
        puVar13[0x28] = *(undefined2 *)0x62;
        puVar13[0x50] = *(undefined2 *)0x64;
        puVar13[0x78] = *(undefined2 *)0x66;
        puVar13[0xa0] = *(undefined2 *)0x68;
        puVar13[200] = *(undefined2 *)0x6a;
        puVar13[0xf0] = *(undefined2 *)0x6c;
        puVar13[0x118] = *(undefined2 *)0x6e;
        puVar13[0x140] = *(undefined2 *)0x70;
        puVar13[0x168] = *(undefined2 *)0x72;
        puVar13[400] = *(undefined2 *)0x74;
        puVar13[0x1b8] = *(undefined2 *)0x76;
        puVar13[0x1e0] = *(undefined2 *)0x78;
        puVar13[0x208] = *(undefined2 *)0x7a;
        puVar13[0x230] = *(undefined2 *)0x7c;
        puVar13[600] = *(undefined2 *)0x7e;
      }
      iVar8 = iVar8 + -1;
      piVar10 = piVar9;
      puVar11 = puVar13 + 0x280;
    } while (iVar8 != 0);
    puVar11 = puVar13 + -0x397f;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  bVar6 = (char)((uint)DAT_0000_3be4 >> 8) - (char)((uint)DAT_0000_3be2 >> 8);
  if ((bVar6 < 0x18) && (bVar3 = (char)DAT_0000_3be4 - (char)DAT_0000_3be2, bVar3 < 0x18)) {
    iVar7 = (uint)bVar3 * 0x500 + (uint)bVar6 * 2;
    *(undefined2 *)((undefined *)&DAT_0000_648c + ((uint)bVar3 + (uint)bVar6 * 0x18) * 2) = 0xffff;
    FUN_1000_724a();
    *(undefined2 *)(iVar7 + 0x28c) = DAT_0000_26cb;
    puVar11 = (undefined2 *)(iVar7 + 0x28e + extraout_DX);
    *puVar11 = DAT_0000_26cd;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26cf;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26d1;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26d3;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26d5;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26d7;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26d9;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26db;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26dd;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26df;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26e1;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26e3;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26e5;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26e7;
    *(undefined2 *)((int)puVar11 + extraout_DX + 2) = DAT_0000_26e9;
    FUN_1000_724a();
    *(undefined2 *)(iVar7 + 0x28c) = DAT_0000_26eb;
    puVar11 = (undefined2 *)(iVar7 + 0x28e + extraout_DX_00);
    *puVar11 = DAT_0000_26ed;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26ef;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26f1;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26f3;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26f5;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26f7;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26f9;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26fb;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26fd;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26ff;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_2701;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_2703;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_2705;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_2707;
    *(undefined2 *)((int)puVar11 + extraout_DX_00 + 2) = DAT_0000_2709;
    out(0x7c,0);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:83fb  FUN_1000_83fb  829 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_83fb(void)

{
  byte bVar1;
  undefined2 in_AX;
  uint uVar2;
  byte bVar4;
  int iVar3;
  int iVar5;
  int iVar6;
  undefined2 in_DX;
  int extraout_DX;
  int extraout_DX_00;
  int in_BX;
  int iVar7;
  int *piVar8;
  int *piVar9;
  uint *puVar10;
  uint *puVar11;
  undefined2 *puVar12;
  undefined2 *puVar13;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_9b34();
  puVar10 = (uint *)0x600c;
  iVar5 = 0xc;
  do {
    iVar6 = 0xc;
    do {
      puVar11 = puVar10;
      iVar7 = in_BX;
      iVar3 = (*(uint *)((undefined *)&DAT_0000_d27e + iVar7) & 0xff) * 4;
      *puVar11 = (uint)(byte)((undefined *)&DAT_0000_3c20)[iVar3];
      puVar11[1] = (uint)(byte)((undefined *)&DAT_0000_3c21)[iVar3];
      puVar11[0x18] = (uint)(byte)((undefined *)&DAT_0000_3c22)[iVar3];
      puVar11[0x19] = (uint)(byte)((undefined *)&DAT_0000_3c23)[iVar3];
      if (*(int *)((undefined *)&DAT_0000_e47e + iVar7) != 0) {
        FUN_1000_ac00();
        uVar2 = FUN_1000_a13d();
        *puVar11 = uVar2;
        puVar11[0x240] = 0xffff;
        uVar2 = FUN_1000_a13d();
        puVar11[0x18] = uVar2;
        puVar11[0x240] = 0xffff;
        uVar2 = FUN_1000_a13d();
        puVar11[1] = uVar2;
        puVar11[0x241] = 0xffff;
        uVar2 = FUN_1000_a13d();
        puVar11[0x19] = uVar2;
        puVar11[0x259] = 0xffff;
      }
      iVar6 = iVar6 + -1;
      in_BX = iVar7 + 2;
      puVar10 = puVar11 + 2;
    } while (iVar6 != 0);
    in_BX = iVar7 + 0x4a;
    puVar10 = puVar11 + 0x1a;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  puVar12 = (undefined2 *)0x28c;
  piVar8 = (int *)0x600a;
  iVar5 = 0x18;
  do {
    iVar6 = 0x18;
    piVar9 = piVar8;
    do {
      puVar13 = puVar12;
      piVar8 = piVar9 + 1;
      iVar3 = *piVar8;
      if (iVar3 != piVar9[0x241]) {
        piVar9[0x241] = iVar3;
        iVar3 = iVar3 * 8 + 0x4000;
        *puVar13 = *(undefined2 *)0x0;
        puVar13[0x28] = *(undefined2 *)0x2;
        puVar13[0x50] = *(undefined2 *)0x4;
        puVar13[0x78] = *(undefined2 *)0x6;
        puVar13[0xa0] = *(undefined2 *)0x8;
        puVar13[200] = *(undefined2 *)0xa;
        puVar13[0xf0] = *(undefined2 *)0xc;
        puVar13[0x118] = *(undefined2 *)0xe;
        puVar13[0x140] = *(undefined2 *)0x10;
        puVar13[0x168] = *(undefined2 *)0x12;
        puVar13[400] = *(undefined2 *)0x14;
        puVar13[0x1b8] = *(undefined2 *)0x16;
        puVar13[0x1e0] = *(undefined2 *)0x18;
        puVar13[0x208] = *(undefined2 *)0x1a;
        puVar13[0x230] = *(undefined2 *)0x1c;
        puVar13[600] = *(undefined2 *)0x1e;
        *puVar13 = *(undefined2 *)0x20;
        puVar13[0x28] = *(undefined2 *)0x22;
        puVar13[0x50] = *(undefined2 *)0x24;
        puVar13[0x78] = *(undefined2 *)0x26;
        puVar13[0xa0] = *(undefined2 *)0x28;
        puVar13[200] = *(undefined2 *)0x2a;
        puVar13[0xf0] = *(undefined2 *)0x2c;
        puVar13[0x118] = *(undefined2 *)0x2e;
        puVar13[0x140] = *(undefined2 *)0x30;
        puVar13[0x168] = *(undefined2 *)0x32;
        puVar13[400] = *(undefined2 *)0x34;
        puVar13[0x1b8] = *(undefined2 *)0x36;
        puVar13[0x1e0] = *(undefined2 *)0x38;
        puVar13[0x208] = *(undefined2 *)0x3a;
        puVar13[0x230] = *(undefined2 *)0x3c;
        puVar13[600] = *(undefined2 *)0x3e;
        *puVar13 = *(undefined2 *)0x40;
        puVar13[0x28] = *(undefined2 *)0x42;
        puVar13[0x50] = *(undefined2 *)0x44;
        puVar13[0x78] = *(undefined2 *)0x46;
        puVar13[0xa0] = *(undefined2 *)0x48;
        puVar13[200] = *(undefined2 *)0x4a;
        puVar13[0xf0] = *(undefined2 *)0x4c;
        puVar13[0x118] = *(undefined2 *)0x4e;
        puVar13[0x140] = *(undefined2 *)0x50;
        puVar13[0x168] = *(undefined2 *)0x52;
        puVar13[400] = *(undefined2 *)0x54;
        puVar13[0x1b8] = *(undefined2 *)0x56;
        puVar13[0x1e0] = *(undefined2 *)0x58;
        puVar13[0x208] = *(undefined2 *)0x5a;
        puVar13[0x230] = *(undefined2 *)0x5c;
        puVar13[600] = *(undefined2 *)0x5e;
        *puVar13 = *(undefined2 *)0x60;
        puVar13[0x28] = *(undefined2 *)0x62;
        puVar13[0x50] = *(undefined2 *)0x64;
        puVar13[0x78] = *(undefined2 *)0x66;
        puVar13[0xa0] = *(undefined2 *)0x68;
        puVar13[200] = *(undefined2 *)0x6a;
        puVar13[0xf0] = *(undefined2 *)0x6c;
        puVar13[0x118] = *(undefined2 *)0x6e;
        puVar13[0x140] = *(undefined2 *)0x70;
        puVar13[0x168] = *(undefined2 *)0x72;
        puVar13[400] = *(undefined2 *)0x74;
        puVar13[0x1b8] = *(undefined2 *)0x76;
        puVar13[0x1e0] = *(undefined2 *)0x78;
        puVar13[0x208] = *(undefined2 *)0x7a;
        puVar13[0x230] = *(undefined2 *)0x7c;
        puVar13[600] = *(undefined2 *)0x7e;
      }
      iVar6 = iVar6 + -1;
      piVar9 = piVar8;
      puVar12 = puVar13 + 0x280;
    } while (iVar6 != 0);
    puVar12 = puVar13 + -0x397f;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  bVar4 = (char)((uint)DAT_0000_3be4 >> 8) - (char)((uint)DAT_0000_3be2 >> 8);
  if ((bVar4 < 0xc) && (bVar1 = (char)DAT_0000_3be4 - (char)DAT_0000_3be2, bVar1 < 0xc)) {
    iVar6 = (uint)bVar1 * 0xa00 + (uint)bVar4 * 4;
    iVar5 = ((uint)bVar1 * 2 + (uint)bVar4 * 0x30) * 2;
    *(undefined2 *)((undefined *)&DAT_0000_648c + iVar5) = 0xffff;
    *(undefined2 *)((undefined *)&DAT_0000_648e + iVar5) = 0xffff;
    *(undefined2 *)((undefined *)&DAT_0000_64bc + iVar5) = 0xffff;
    *(undefined2 *)((undefined *)&DAT_0000_64be + iVar5) = 0xffff;
    FUN_1000_724a();
    *(undefined2 *)(iVar6 + 0x28c) = DAT_0000_270b;
    *(undefined2 *)(iVar6 + 0x28e) = DAT_0000_270d;
    puVar12 = (undefined2 *)(iVar6 + 0x290 + extraout_DX);
    *puVar12 = DAT_0000_270f;
    puVar12[1] = DAT_0000_2711;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2713;
    puVar12[1] = DAT_0000_2715;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2717;
    puVar12[1] = DAT_0000_2719;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_271b;
    puVar12[1] = DAT_0000_271d;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_271f;
    puVar12[1] = DAT_0000_2721;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2723;
    puVar12[1] = DAT_0000_2725;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2727;
    puVar12[1] = DAT_0000_2729;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_272b;
    puVar12[1] = DAT_0000_272d;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_272f;
    puVar12[1] = DAT_0000_2731;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2733;
    puVar12[1] = DAT_0000_2735;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2737;
    puVar12[1] = DAT_0000_2739;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_273b;
    puVar12[1] = DAT_0000_273d;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_273f;
    puVar12[1] = DAT_0000_2741;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2743;
    puVar12[1] = DAT_0000_2745;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2747;
    puVar12[1] = DAT_0000_2749;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_274b;
    puVar12[1] = DAT_0000_274d;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_274f;
    puVar12[1] = DAT_0000_2751;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2753;
    puVar12[1] = DAT_0000_2755;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2757;
    puVar12[1] = DAT_0000_2759;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_275b;
    puVar12[1] = DAT_0000_275d;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_275f;
    puVar12[1] = DAT_0000_2761;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2763;
    puVar12[1] = DAT_0000_2765;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2767;
    puVar12[1] = DAT_0000_2769;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_276b;
    puVar12[1] = DAT_0000_276d;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_276f;
    puVar12[1] = DAT_0000_2771;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2773;
    puVar12[1] = DAT_0000_2775;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2777;
    puVar12[1] = DAT_0000_2779;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_277b;
    puVar12[1] = DAT_0000_277d;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_277f;
    puVar12[1] = DAT_0000_2781;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2783;
    puVar12[1] = DAT_0000_2785;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX + 4);
    *puVar12 = DAT_0000_2787;
    puVar12[1] = DAT_0000_2789;
    FUN_1000_724a();
    *(undefined2 *)(iVar6 + 0x28c) = DAT_0000_278b;
    *(undefined2 *)(iVar6 + 0x28e) = DAT_0000_278d;
    puVar12 = (undefined2 *)(iVar6 + 0x290 + extraout_DX_00);
    *puVar12 = DAT_0000_278f;
    puVar12[1] = DAT_0000_2791;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_2793;
    puVar12[1] = DAT_0000_2795;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_2797;
    puVar12[1] = DAT_0000_2799;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_279b;
    puVar12[1] = DAT_0000_279d;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_279f;
    puVar12[1] = DAT_0000_27a1;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27a3;
    puVar12[1] = DAT_0000_27a5;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27a7;
    puVar12[1] = DAT_0000_27a9;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27ab;
    puVar12[1] = DAT_0000_27ad;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27af;
    puVar12[1] = DAT_0000_27b1;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27b3;
    puVar12[1] = DAT_0000_27b5;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27b7;
    puVar12[1] = DAT_0000_27b9;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27bb;
    puVar12[1] = DAT_0000_27bd;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27bf;
    puVar12[1] = DAT_0000_27c1;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27c3;
    puVar12[1] = DAT_0000_27c5;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27c7;
    puVar12[1] = DAT_0000_27c9;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27cb;
    puVar12[1] = DAT_0000_27cd;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27cf;
    puVar12[1] = DAT_0000_27d1;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27d3;
    puVar12[1] = DAT_0000_27d5;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27d7;
    puVar12[1] = DAT_0000_27d9;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27db;
    puVar12[1] = DAT_0000_27dd;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27df;
    puVar12[1] = DAT_0000_27e1;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27e3;
    puVar12[1] = DAT_0000_27e5;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27e7;
    puVar12[1] = DAT_0000_27e9;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27eb;
    puVar12[1] = DAT_0000_27ed;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27ef;
    puVar12[1] = DAT_0000_27f1;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27f3;
    puVar12[1] = DAT_0000_27f5;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27f7;
    puVar12[1] = DAT_0000_27f9;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27fb;
    puVar12[1] = DAT_0000_27fd;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_27ff;
    puVar12[1] = DAT_0000_2801;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_2803;
    puVar12[1] = DAT_0000_2805;
    puVar12 = (undefined2 *)((int)puVar12 + extraout_DX_00 + 4);
    *puVar12 = DAT_0000_2807;
    puVar12[1] = DAT_0000_2809;
    out(0x7c,0);
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:8738  FUN_1000_8738  30 bytes, 8 callers */

undefined2 __cdecl16near FUN_1000_8738(void)

{
  undefined2 in_AX;
  
  FUN_1000_8789();
  FUN_1000_8789();
  FUN_1000_8789();
  FUN_1000_8789();
  return in_AX;
}



/* 1000:8756  FUN_1000_8756  51 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_8756(void)

{
  undefined2 in_AX;
  
  FUN_1000_8789();
  FUN_1000_8789();
  FUN_1000_8789();
  FUN_1000_8789();
  return in_AX;
}



/* 1000:8789  FUN_1000_8789  1009 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_8789(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int in_AX;
  int iVar5;
  undefined2 in_DX;
  uint uVar6;
  undefined1 *unaff_DI;
  
  iVar5 = in_AX * 8 + 0x3000;
  out(0x7c,0xc0);
  uVar2 = *(uint *)0x60;
  uVar3 = *(uint *)0x40;
  uVar4 = *(uint *)0x20;
  uVar1 = *(uint *)0x0;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  *unaff_DI = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[1] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x62;
  uVar3 = *(uint *)0x42;
  uVar4 = *(uint *)0x22;
  uVar1 = *(uint *)0x2;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[0x50] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0x51] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x64;
  uVar3 = *(uint *)0x44;
  uVar4 = *(uint *)0x24;
  uVar1 = *(uint *)0x4;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[0xa0] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0xa1] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x66;
  uVar3 = *(uint *)0x46;
  uVar4 = *(uint *)0x26;
  uVar1 = *(uint *)0x6;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[0xf0] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0xf1] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x68;
  uVar3 = *(uint *)0x48;
  uVar4 = *(uint *)0x28;
  uVar1 = *(uint *)0x8;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[0x140] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0x141] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x6a;
  uVar3 = *(uint *)0x4a;
  uVar4 = *(uint *)0x2a;
  uVar1 = *(uint *)0xa;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[400] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0x191] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x6c;
  uVar3 = *(uint *)0x4c;
  uVar4 = *(uint *)0x2c;
  uVar1 = *(uint *)0xc;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[0x1e0] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0x1e1] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x6e;
  uVar3 = *(uint *)0x4e;
  uVar4 = *(uint *)0x2e;
  uVar1 = *(uint *)0xe;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[0x230] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0x231] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x70;
  uVar3 = *(uint *)0x50;
  uVar4 = *(uint *)0x30;
  uVar1 = *(uint *)0x10;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[0x280] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0x281] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x72;
  uVar3 = *(uint *)0x52;
  uVar4 = *(uint *)0x32;
  uVar1 = *(uint *)0x12;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[0x2d0] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0x2d1] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x74;
  uVar3 = *(uint *)0x54;
  uVar4 = *(uint *)0x34;
  uVar1 = *(uint *)0x14;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[800] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0x321] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x76;
  uVar3 = *(uint *)0x56;
  uVar4 = *(uint *)0x36;
  uVar1 = *(uint *)0x16;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[0x370] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0x371] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x78;
  uVar3 = *(uint *)0x58;
  uVar4 = *(uint *)0x38;
  uVar1 = *(uint *)0x18;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[0x3c0] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0x3c1] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x7a;
  uVar3 = *(uint *)0x5a;
  uVar4 = *(uint *)0x3a;
  uVar1 = *(uint *)0x1a;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[0x410] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0x411] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x7c;
  uVar3 = *(uint *)0x5c;
  uVar4 = *(uint *)0x3c;
  uVar1 = *(uint *)0x1c;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[0x460] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0x461] = (char)(uVar6 >> 8);
  uVar2 = *(uint *)0x7e;
  uVar3 = *(uint *)0x5e;
  uVar4 = *(uint *)0x3e;
  uVar1 = *(uint *)0x1e;
  uVar6 = ~(uVar1 & uVar4 & uVar3 & uVar2);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar4);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  unaff_DI[0x4b0] = (char)uVar6;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar4 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  unaff_DI[0x4b1] = (char)(uVar6 >> 8);
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:9167  FUN_1000_9167  56 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_9167(void)

{
  undefined2 in_AX;
  uint in_CX;
  int iVar1;
  int iVar2;
  undefined2 in_DX;
  
  iVar1 = (in_CX & 0xff) << 3;
  iVar2 = 8;
  do {
    FUN_1000_919f();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  do {
    FUN_1000_919f();
    FUN_1000_919f();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar2 = 8;
  do {
    FUN_1000_919f();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:919f  FUN_1000_919f  75 bytes, 1 callers */

void __cdecl16near FUN_1000_919f(void)

{
  undefined1 uVar1;
  int iVar2;
  int in_DX;
  undefined1 *unaff_SI;
  undefined1 *unaff_DI;
  undefined1 *puVar3;
  undefined2 unaff_DS;
  
  *unaff_DI = *unaff_SI;
  uVar1 = unaff_SI[1];
  puVar3 = unaff_DI;
  for (iVar2 = in_DX; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = uVar1;
  }
  *puVar3 = unaff_SI[2];
  *unaff_DI = unaff_SI[0x30];
  uVar1 = unaff_SI[0x31];
  puVar3 = unaff_DI;
  for (iVar2 = in_DX; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = uVar1;
  }
  *puVar3 = unaff_SI[0x32];
  *unaff_DI = unaff_SI[0x60];
  uVar1 = unaff_SI[0x61];
  puVar3 = unaff_DI;
  for (iVar2 = in_DX; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = uVar1;
  }
  *puVar3 = unaff_SI[0x62];
  *unaff_DI = unaff_SI[0x90];
  uVar1 = unaff_SI[0x91];
  for (; unaff_DI = unaff_DI + 1, in_DX != 0; in_DX = in_DX + -1) {
    *unaff_DI = uVar1;
  }
  *unaff_DI = unaff_SI[0x92];
  return;
}



/* 1000:91ea  FUN_1000_91ea  79 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_91ea(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  uint in_CX;
  int iVar3;
  int iVar4;
  undefined2 in_DX;
  int extraout_DX;
  uint in_BX;
  undefined1 *puVar5;
  
  puVar5 = (undefined1 *)(((in_BX & 0xff) * 0x280 + (in_BX >> 8)) * 2 + 0x50d);
  iVar3 = (in_CX & 0xff) << 4;
  FUN_1000_724a();
  do {
    puVar1 = (undefined2 *)(puVar5 + 1);
    *puVar5 = 0xff;
    for (iVar4 = extraout_DX; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar1;
      puVar1 = puVar1 + 1;
      *puVar2 = 0xffff;
    }
    *(undefined1 *)puVar1 = 0xff;
    puVar5 = (undefined1 *)((int)puVar1 + (0x27 - ((in_CX >> 8) - 1)) * 2 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:9239  FUN_1000_9239  92 bytes, 3 callers */

undefined4 __cdecl16near FUN_1000_9239(void)

{
  undefined2 uVar1;
  undefined2 in_CX;
  int iVar2;
  int extraout_DX;
  int extraout_DX_00;
  undefined2 *puVar3;
  int iVar4;
  uint *unaff_SI;
  char *unaff_DI;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 uVar6;
  
  puVar3 = (undefined2 *)
           (((uint)(byte)(((char)*unaff_SI + *unaff_DI) - unaff_DI[1]) * 0x280 + (*unaff_SI >> 8)) *
            2 + 0x50d);
  iVar4 = 0x10;
  do {
    uVar6 = 0x926e;
    FUN_1000_7262();
    iVar2 = extraout_DX;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_1000_724a(uVar6);
    iVar2 = extraout_DX_00;
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + -1;
      *puVar3 = uVar1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    puVar3 = puVar5 + 0x27;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  out(0x7c,0);
  return CONCAT22(in_CX,unaff_ES);
}



/* 1000:9295  FUN_1000_9295  92 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_9295(void)

{
  undefined2 uVar1;
  undefined2 in_CX;
  int iVar2;
  int extraout_DX;
  int extraout_DX_00;
  undefined2 *puVar3;
  int iVar4;
  uint *unaff_SI;
  char *unaff_DI;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 uVar6;
  
  puVar3 = (undefined2 *)
           (((uint)(byte)(((char)*unaff_SI + *unaff_DI) - unaff_DI[1]) * 0x280 + (*unaff_SI >> 8)) *
            2 + 0x50d);
  iVar4 = 0x10;
  do {
    uVar6 = 0x92ca;
    FUN_1000_7262();
    iVar2 = extraout_DX;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_1000_724a(uVar6);
    iVar2 = extraout_DX_00;
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + -1;
      *puVar3 = uVar1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    puVar3 = puVar5 + 0x27;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  out(0x7c,0);
  return CONCAT22(in_CX,unaff_ES);
}



/* 1000:9355  FUN_1000_9355  112 bytes, 4 callers */

undefined4 __cdecl16near FUN_1000_9355(void)

{
  undefined2 in_AX;
  int iVar1;
  int iVar2;
  undefined2 in_DX;
  int iVar3;
  undefined2 *puVar4;
  undefined2 unaff_DS;
  
  if (*(int *)0x34c8 != 0) {
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_724a();
  puVar4 = (undefined2 *)0x666f;
  iVar1 = 0x80;
  do {
    *puVar4 = 0xffff;
    *(undefined2 *)((int)puVar4 + 3) = 0xffff;
    puVar4[3] = 0xffff;
    *(undefined2 *)((int)puVar4 + 9) = 0xffff;
    *(undefined1 *)(puVar4 + 6) = 0xff;
    puVar4 = puVar4 + -0x28;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  out(0x7c,0);
  iVar3 = 0x3484;
  iVar1 = 2;
  if ((*(byte *)0x3482 & 1) != 0) {
    iVar1 = 6;
  }
  iVar2 = 4;
  do {
    *(undefined2 *)(iVar1 + iVar3) = 0;
    *(undefined2 *)(iVar1 + iVar3 + 2) = 0;
    FUN_1000_97c3();
    iVar3 = iVar3 + 10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)(iVar1 + iVar3) = 0;
  *(undefined2 *)(iVar1 + iVar3 + 2) = 0;
  return CONCAT22(in_DX,in_AX);
}



/* 1000:93c5  FUN_1000_93c5  347 bytes, 3 callers */

undefined4 __cdecl16near FUN_1000_93c5(void)

{
  undefined2 in_AX;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined2 in_DX;
  uint uVar4;
  int extraout_DX;
  int extraout_DX_00;
  uint uVar5;
  int extraout_DX_01;
  int extraout_DX_02;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  iVar6 = -0x386e;
  iVar2 = 5;
  uVar1 = 0;
  uVar4 = 0;
  do {
    if ((uVar4 < *(uint *)(iVar6 + 10)) ||
       ((uVar4 == *(uint *)(iVar6 + 10) && (uVar1 < *(uint *)(iVar6 + 8))))) {
      uVar4 = *(uint *)(iVar6 + 10);
      uVar1 = *(uint *)(iVar6 + 8);
    }
    iVar6 = iVar6 + 0x16;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0;
  for (; uVar4 != 0; uVar4 = uVar4 >> 1) {
    iVar2 = iVar2 + 1;
  }
  *(int *)0xc4f4 = iVar2 + 1;
  *(uint *)0xc4f6 = ~(-1 << ((byte)(iVar2 + 1) & 0x1f));
  iVar2 = 2;
  if ((*(byte *)0x3482 & 1) != 0) {
    iVar2 = 6;
  }
  iVar9 = 0x666f;
  iVar8 = 0x3484;
  iVar7 = -0x386e;
  iVar6 = 5;
  do {
    uVar4 = *(uint *)(iVar7 + 8);
    uVar1 = *(uint *)(iVar7 + 10);
    for (iVar3 = *(int *)0xc4f4; iVar3 != 0; iVar3 = iVar3 + -1) {
      uVar5 = uVar1 & 1;
      uVar1 = uVar1 >> 1;
      uVar4 = (uint)(CONCAT12(uVar5 != 0,uVar4) >> 1);
    }
    uVar1 = uVar4 >> 8;
    if ((*(uint *)(iVar7 + 8) & *(uint *)0xc4f6) != 0 || (uVar4 & 0xff) != 0) {
      uVar1 = uVar1 + 1;
    }
    if ((uVar1 & 0xff80) != 0) {
      uVar1 = 0x7f;
    }
    uVar4 = *(uint *)(iVar2 + iVar8);
    *(uint *)(iVar2 + iVar8) = uVar1;
    iVar3 = uVar1 - uVar4;
    if (iVar3 != 0) {
      if (uVar1 < uVar4) {
        iVar3 = -iVar3;
        puVar10 = (undefined1 *)(iVar9 + (uVar4 - 1) * -0x50);
        FUN_1000_724a();
        do {
          *puVar10 = 0xff;
          puVar10 = puVar10 + extraout_DX_00;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      else {
        puVar10 = (undefined1 *)(iVar9 + uVar4 * -0x50);
        FUN_1000_724a();
        do {
          *puVar10 = 0x5a;
          puVar10 = puVar10 + -extraout_DX;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      out(0x7c,0);
    }
    iVar7 = iVar7 + 0x16;
    iVar8 = iVar8 + 10;
    iVar9 = iVar9 + 3;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar9 = 0x6670;
  iVar8 = 0x3484;
  iVar7 = -0x386e;
  iVar6 = 5;
  do {
    uVar4 = 0;
    if (*(int *)(iVar7 + 6) != 0) {
      uVar4 = *(uint *)(*(int *)(iVar7 + 6) + 6);
    }
    uVar5 = uVar4 >> ((byte)*(undefined2 *)0xc4f4 & 0x1f);
    uVar1 = CONCAT11((char)((uint)*(undefined2 *)0xc4f4 >> 8),(char)(uVar5 >> 8));
    if ((uVar4 & *(uint *)0xc4f6) != 0 || (uVar5 & 0xff) != 0) {
      uVar1 = uVar1 + 1;
    }
    if ((uVar1 & 0xff80) != 0) {
      uVar1 = 0x7f;
    }
    uVar4 = *(uint *)(iVar2 + 2 + iVar8);
    *(uint *)(iVar2 + 2 + iVar8) = uVar1;
    iVar3 = uVar1 - uVar4;
    if (iVar3 != 0) {
      if (uVar1 < uVar4) {
        iVar3 = -iVar3;
        puVar10 = (undefined1 *)(iVar9 + (uVar4 - 1) * -0x50);
        FUN_1000_724a();
        do {
          *puVar10 = 0xff;
          puVar10 = puVar10 + extraout_DX_02;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      else {
        puVar10 = (undefined1 *)(iVar9 + uVar4 * -0x50);
        FUN_1000_724a();
        do {
          *puVar10 = 0x5a;
          puVar10 = puVar10 + -extraout_DX_01;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      out(0x7c,0);
    }
    iVar7 = iVar7 + 0x16;
    iVar8 = iVar8 + 10;
    iVar9 = iVar9 + 3;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:9520  FUN_1000_9520  27 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_9520(void)

{
  undefined2 in_AX;
  
  FUN_1000_953b();
  FUN_1000_953b();
  FUN_1000_953b();
  FUN_1000_953b();
  return in_AX;
}



/* 1000:953b  FUN_1000_953b  37 bytes, 1 callers */

void __cdecl16near FUN_1000_953b(void)

{
  int iVar1;
  undefined2 unaff_SS;
  
  iVar1 = 0xb;
  do {
    *(undefined1 *)0x32d3 = (char)*(undefined2 *)0x3e78;
    FUN_1000_9560();
    do {
    } while (*(char *)0x32d3 != '\0');
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}



/* 1000:9560  FUN_1000_9560  29 bytes, 1 callers */

byte __cdecl16near FUN_1000_9560(void)

{
  byte bVar1;
  int iVar2;
  undefined1 *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  iVar2 = 0xb5e;
  bVar1 = *(byte *)0x3482;
  do {
    out(0xa6,bVar1 ^ 1);
    out(0xa6,bVar1);
    *unaff_SI = *unaff_SI;
    unaff_SI = unaff_SI + 0xb;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return bVar1;
}



/* 1000:95f7  FUN_1000_95f7  59 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_95f7(void)

{
  undefined2 in_AX;
  int iVar1;
  undefined2 in_DX;
  
  iVar1 = 4;
  do {
    FUN_1000_9632();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 4;
  do {
    FUN_1000_9632();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 4;
  do {
    FUN_1000_9632();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:9632  FUN_1000_9632  30 bytes, 1 callers */

uint __cdecl16near FUN_1000_9632(void)

{
  uint in_AX;
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined2 unaff_ES;
  
  puVar4 = (uint *)0x500;
  iVar2 = 0x128;
  uVar1 = in_AX;
  do {
    iVar3 = 0x28;
    do {
      *puVar4 = *puVar4 & uVar1;
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar1 = (uVar1 >> 1 | (uint)((uVar1 & 1) != 0) << 0xf) >> 1 |
            (uint)((uVar1 >> 1 & 1) != 0) << 0xf;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return in_AX;
}



/* 1000:9650  FUN_1000_9650  81 bytes, 2 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl16near FUN_1000_9650(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int in_CX;
  int iVar3;
  int in_DX;
  undefined2 *unaff_SI;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  puVar5 = (undefined2 *)0x8006;
  iVar3 = in_DX;
  _DAT_7000_8000 = unaff_SI;
  _DAT_7000_8002 = in_CX;
  _DAT_7000_8004 = in_DX;
  do {
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      *puVar2 = *puVar1;
    }
    puVar4 = unaff_SI + -in_DX;
    for (iVar3 = in_DX; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = *puVar1;
    }
    puVar4 = puVar4 + -in_DX;
    for (iVar3 = in_DX; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = *puVar1;
    }
    puVar4 = puVar4 + -in_DX;
    for (iVar3 = in_DX; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = *puVar1;
    }
    unaff_SI = puVar4 + (0x28 - in_DX);
    in_CX = in_CX + -1;
    iVar3 = in_DX;
  } while (in_CX != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:96a1  FUN_1000_96a1  81 bytes, 2 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl16near FUN_1000_96a1(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 in_AX;
  int iVar4;
  int iVar5;
  undefined2 in_DX;
  undefined2 *puVar6;
  undefined2 *puVar7;
  
  iVar3 = _DAT_7000_8004;
  puVar6 = (undefined2 *)0x8006;
  iVar4 = iVar3;
  puVar7 = _DAT_7000_8000;
  iVar5 = _DAT_7000_8002;
  do {
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar7 = *puVar1;
      puVar7 = puVar7 + 1;
    }
    puVar7 = puVar7 + -iVar3;
    for (iVar4 = iVar3; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar7;
      puVar7 = puVar7 + 1;
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar2 = *puVar1;
    }
    puVar7 = puVar7 + -iVar3;
    for (iVar4 = iVar3; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar7;
      puVar7 = puVar7 + 1;
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar2 = *puVar1;
    }
    puVar7 = puVar7 + -iVar3;
    for (iVar4 = iVar3; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar7;
      puVar7 = puVar7 + 1;
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar2 = *puVar1;
    }
    puVar7 = puVar7 + (0x28 - iVar3);
    iVar5 = iVar5 + -1;
    iVar4 = iVar3;
  } while (iVar5 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:96f2  FUN_1000_96f2  47 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_96f2(void)

{
  undefined2 in_AX;
  int iVar1;
  undefined2 in_DX;
  
  iVar1 = 8;
  do {
    FUN_1000_97e3();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 8;
  do {
    FUN_1000_97e3();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:977e  FUN_1000_977e  41 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_977e(void)

{
  undefined2 *puVar1;
  uint uVar2;
  undefined2 in_AX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined2 in_DX;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 unaff_ES;
  
  puVar7 = (undefined2 *)0x5f1c;
  uVar2 = 0xa800;
  do {
    uVar3 = uVar2;
    puVar6 = (undefined2 *)0x28c;
    iVar5 = 0x10;
    do {
      puVar1 = puVar7 + 1;
      *puVar7 = *puVar6;
      puVar7 = (undefined2 *)((int)puVar7 + 3);
      *(undefined1 *)puVar1 = *(undefined1 *)(puVar6 + 1);
      puVar6 = puVar6 + 0x28;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    uVar4 = uVar3 + 0x800;
    uVar2 = uVar4;
  } while ((uVar4 < 0xb801) || (uVar2 = uVar3 + 0x2800, uVar4 < 0xe000));
  return CONCAT22(in_DX,in_AX);
}



/* 1000:97a7  FUN_1000_97a7  28 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_97a7(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 unaff_ES;
  
  puVar4 = (undefined2 *)0x5fdc;
  puVar3 = (undefined2 *)0x66be;
  iVar2 = 0x10;
  do {
    puVar1 = puVar4 + 1;
    *puVar4 = *puVar3;
    puVar4 = (undefined2 *)((int)puVar4 + 3);
    *(undefined1 *)puVar1 = *(undefined1 *)(puVar3 + 1);
    puVar3 = puVar3 + 0x28;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:97c3  FUN_1000_97c3  32 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_97c3(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 *puVar3;
  undefined2 *unaff_DI;
  undefined2 unaff_DS;
  
  FUN_1000_724a();
  puVar3 = (undefined2 *)0x5fdc;
  iVar2 = 0x10;
  do {
    puVar1 = puVar3 + 1;
    *unaff_DI = *puVar3;
    puVar3 = (undefined2 *)((int)puVar3 + 3);
    *(undefined1 *)(unaff_DI + 1) = *(undefined1 *)puVar1;
    unaff_DI = unaff_DI + 0x28;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:97e3  FUN_1000_97e3  30 bytes, 2 callers */

undefined2 __cdecl16near FUN_1000_97e3(void)

{
  undefined2 in_AX;
  
  FUN_1000_9801();
  FUN_1000_9801();
  FUN_1000_9801();
  FUN_1000_9801();
  return in_AX;
}



/* 1000:9801  FUN_1000_9801  53 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_9801(void)

{
  undefined2 *puVar1;
  uint uVar2;
  int in_AX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined2 in_DX;
  undefined2 *puVar6;
  undefined2 *unaff_DI;
  undefined2 *puVar7;
  
  puVar7 = (undefined2 *)0x0;
  uVar2 = 0xa800;
  do {
    uVar3 = uVar2;
    iVar5 = 0x10;
    puVar6 = unaff_DI;
    do {
      puVar1 = puVar7;
      puVar7 = puVar7 + 1;
      *puVar1 = *puVar6;
      puVar6 = puVar6 + 0x28;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    uVar4 = uVar3 + 0x800;
    uVar2 = uVar4;
  } while ((uVar4 < 0xb801) || (uVar2 = uVar3 + 0x2800, uVar4 < 0xe000));
  return CONCAT22(in_DX,in_AX);
}



/* 1000:9836  FUN_1000_9836  35 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_9836(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int iVar3;
  int iVar4;
  undefined2 in_DX;
  undefined2 *puVar5;
  undefined2 *puVar6;
  
  puVar6 = (undefined2 *)0xc8e;
  puVar5 = (undefined2 *)&DAT_0000_8000;
  iVar3 = 0x130;
  do {
    for (iVar4 = 0x16; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar6;
      puVar6 = puVar6 + 1;
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      *puVar2 = *puVar1;
    }
    puVar6 = puVar6 + 0x12;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:9859  FUN_1000_9859  71 bytes, 7 callers */

undefined4 __cdecl16near FUN_1000_9859(void)

{
  undefined2 uVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  undefined2 in_AX;
  int iVar9;
  undefined2 in_DX;
  int iVar10;
  undefined2 *unaff_SI;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined2 unaff_DS;
  
  iVar8 = unaff_SI[2];
  iVar10 = unaff_SI[3];
  uVar1 = unaff_SI[1];
  pbVar13 = (byte *)0x0;
  pbVar12 = (byte *)*unaff_SI;
  iVar9 = iVar8;
  pbVar11 = pbVar12;
  do {
    do {
      bVar5 = *pbVar12;
      *pbVar13 = bVar5;
      bVar6 = pbVar12[-0x8000];
      pbVar13[1] = bVar6;
      bVar7 = *pbVar12;
      pbVar13[2] = bVar7;
      pbVar2 = pbVar12;
      pbVar12 = pbVar12 + 1;
      bVar3 = *pbVar2;
      pbVar4 = pbVar13 + 4;
      pbVar13[3] = bVar3;
      pbVar13 = pbVar13 + 5;
      *pbVar4 = ~(bVar3 & bVar5 & bVar6 & bVar7);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    pbVar12 = pbVar11 + 0x50;
    iVar10 = iVar10 + -1;
    iVar9 = iVar8;
    pbVar11 = pbVar12;
  } while (iVar10 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:98a0  FUN_1000_98a0  166 bytes, 6 callers */

undefined4 __cdecl16near FUN_1000_98a0(void)

{
  undefined2 uVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  uint uVar9;
  undefined2 in_AX;
  byte bVar10;
  uint uVar11;
  undefined2 in_DX;
  int unaff_SI;
  byte *pbVar12;
  undefined1 *unaff_DI;
  undefined1 *puVar13;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int local_18;
  
  uVar9 = *(uint *)(unaff_SI + 4);
  local_18 = *(int *)(unaff_SI + 6);
  uVar1 = *(undefined2 *)(unaff_SI + 2);
  pbVar12 = (byte *)*(undefined2 *)0xc560;
  out(0x7c,0xc0);
  uVar11 = uVar9;
  puVar13 = unaff_DI;
  do {
    do {
      uVar4 = ((undefined *)&DAT_0000_cf74)[*pbVar12];
      out(0x7e,((undefined *)&DAT_0000_ce74)[*pbVar12]);
      uVar5 = ((undefined *)&DAT_0000_cf74)[pbVar12[1]];
      out(0x7e,((undefined *)&DAT_0000_ce74)[pbVar12[1]]);
      uVar6 = ((undefined *)&DAT_0000_cf74)[pbVar12[2]];
      out(0x7e,((undefined *)&DAT_0000_ce74)[pbVar12[2]]);
      pbVar2 = pbVar12 + 4;
      uVar7 = ((undefined *)&DAT_0000_cf74)[pbVar12[3]];
      out(0x7e,((undefined *)&DAT_0000_ce74)[pbVar12[3]]);
      pbVar12 = pbVar12 + 5;
      bVar10 = *pbVar2;
      uVar8 = ((undefined *)&DAT_0000_ce74)[bVar10];
      unaff_DI[0x50] = uVar8;
      puVar3 = unaff_DI + 1;
      *unaff_DI = uVar8;
      out(0x7e,uVar4);
      out(0x7e,uVar5);
      out(0x7e,uVar6);
      out(0x7e,uVar7);
      uVar4 = ((undefined *)&DAT_0000_cf74)[bVar10];
      unaff_DI[0x51] = uVar4;
      unaff_DI = unaff_DI + 2;
      *puVar3 = uVar4;
      bVar10 = (char)uVar11 - 1;
      uVar11 = (uint)bVar10;
    } while (bVar10 != 0);
    unaff_DI = puVar13 + 0xa0;
    local_18 = local_18 + -1;
    uVar11 = uVar9;
    puVar13 = unaff_DI;
  } while (local_18 != 0);
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:9946  FUN_1000_9946  54 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_9946(void)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined2 in_AX;
  int iVar5;
  undefined2 in_DX;
  int iVar6;
  int unaff_SI;
  undefined1 *puVar7;
  undefined1 *unaff_DI;
  undefined2 unaff_SS;
  
  uVar1 = *(undefined2 *)(unaff_SI + 2);
  puVar7 = (undefined1 *)0x0;
  out(0x7c,0xc0);
  iVar6 = *(int *)(unaff_SI + 6);
  iVar4 = *(int *)(unaff_SI + 4);
  do {
    iVar5 = *(int *)(unaff_SI + 4);
    do {
      out(*puVar7,0x7e);
      out(puVar7[1],0x7e);
      out(puVar7[2],0x7e);
      puVar2 = puVar7 + 4;
      out(puVar7[3],0x7e);
      puVar3 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      puVar7 = puVar7 + 5;
      *puVar3 = *puVar2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    unaff_DI = unaff_DI + (0x50 - iVar4);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:99a0  FUN_1000_99a0  44 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_99a0(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  undefined2 uVar2;
  int iVar3;
  undefined2 in_DX;
  undefined2 *puVar4;
  undefined2 unaff_DS;
  
  out(0x68,1);
  puVar4 = (undefined2 *)0x0;
  for (iVar3 = 2000; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = 0;
  }
  uVar2 = 0x11;
  if (*(char *)&DAT_0000_3286 != '\0') {
    uVar2 = 0xf1;
  }
  puVar4 = (undefined2 *)0x2000;
  for (iVar3 = 2000; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = uVar2;
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:99cc  FUN_1000_99cc  35 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_99cc(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 *puVar3;
  
  out(0x68,0);
  puVar3 = (undefined2 *)0x0;
  for (iVar2 = 2000; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0x20;
  }
  puVar3 = (undefined2 *)0x2000;
  for (iVar2 = 2000; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0xe1;
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:99ef  FUN_1000_99ef  30 bytes, 3 callers */

undefined2 __cdecl16near FUN_1000_99ef(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int in_CX;
  int iVar2;
  int in_DX;
  undefined2 *unaff_DI;
  undefined2 *puVar3;
  
  iVar2 = in_DX;
  puVar3 = unaff_DI;
  do {
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      puVar1 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      *puVar1 = in_AX;
    }
    unaff_DI = puVar3 + 0x50;
    in_CX = in_CX + -1;
    iVar2 = in_DX;
    puVar3 = unaff_DI;
  } while (in_CX != 0);
  return in_AX;
}



/* 1000:9a0d  FUN_1000_9a0d  23 bytes, 3 callers */

undefined2 __cdecl16near FUN_1000_9a0d(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)0x0;
  for (iVar2 = 2000; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0;
  }
  return in_AX;
}



/* 1000:9a24  FUN_1000_9a24  18 bytes, 2 callers */

undefined1 __cdecl16near FUN_1000_9a24(void)

{
  char in_AL;
  undefined1 uVar1;
  ulong uVar2;
  
  uVar1 = 0;
  if (in_AL != '\0') {
    uVar2 = FUN_1000_9a36();
    uVar1 = (undefined1)((uint)((int)(uVar2 & 0xff00ff) * (int)((uVar2 & 0xff00ff) >> 0x10)) >> 8);
  }
  return uVar1;
}



/* 1000:9a36  FUN_1000_9a36  21 bytes, 4 callers */

void __cdecl16near FUN_1000_9a36(void)

{
  uint uVar1;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)0x3c06;
  *(int *)0x3c06 =
       uVar1 * 2 + (uint)((((int)(uVar1 << 1 | (uint)((int)uVar1 < 0)) < 0 ^ uVar1) & 1) != 0);
  return;
}



/* 1000:9a54  FUN_1000_9a54  32 bytes, 2 callers */

undefined2 __cdecl16near FUN_1000_9a54(void)

{
  byte in_AL;
  byte bVar1;
  char in_AH;
  byte bVar2;
  char cVar3;
  
  bVar2 = in_AH + 0x8f;
  if (0x2e < bVar2) {
    bVar2 = in_AH + 0x4f;
  }
  cVar3 = bVar2 * '\x02' + '\x01';
  if (0x7f < in_AL) {
    in_AL = in_AL - 1;
  }
  bVar1 = in_AL - 0x1f;
  if (0x7e < bVar1) {
    bVar1 = in_AL + 0x83;
    cVar3 = bVar2 * '\x02' + '\x02';
  }
  return CONCAT11(cVar3,bVar1);
}



/* 1000:9aa6  FUN_1000_9aa6  8 bytes, 15 callers */

void __cdecl16near FUN_1000_9aa6(void)

{
  undefined2 unaff_DS;
  
  do {
  } while (*(char *)0x32d3 != '\0');
  return;
}



/* 1000:9aae  FUN_1000_9aae  11 bytes, 8 callers */

void __cdecl16near FUN_1000_9aae(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x32d8 = in_AX;
  do {
  } while (*(int *)0x32d8 != 0);
  return;
}



/* 1000:9ab9  FUN_1000_9ab9  26 bytes, 2 callers */

void __cdecl16near FUN_1000_9ab9(void)

{
  return;
}



/* 1000:9ad3  FUN_1000_9ad3  14 bytes, 6 callers */

void __cdecl16near FUN_1000_9ad3(void)

{
  return;
}



/* 1000:9ae1  FUN_1000_9ae1  14 bytes, 5 callers */

undefined4 __cdecl16near FUN_1000_9ae1(void)

{
  undefined1 uVar1;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  uVar1 = FUN_1000_9aef();
  *(undefined1 *)(unaff_SI + 1) = uVar1;
  return CONCAT22(in_DX,in_AX);
}



/* 1000:9aef  FUN_1000_9aef  30 bytes, 1 callers */

undefined1 __cdecl16near FUN_1000_9aef(void)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  char in_DL;
  char in_DH;
  int unaff_SI;
  undefined2 unaff_DS;
  
  cVar2 = (char)*(undefined2 *)(unaff_SI + 2);
  if (cVar2 == in_DL) {
    bVar3 = (char)((uint)*(undefined2 *)(unaff_SI + 2) >> 8) - in_DH;
    uVar1 = 6;
    if ((bVar3 != 0) && (uVar1 = 4, -1 < (int)((uint)bVar3 << 8))) {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 6;
    if (-1 < (char)(cVar2 - in_DL)) {
      uVar1 = 2;
    }
  }
  return uVar1;
}



/* 1000:9b34  FUN_1000_9b34  14 bytes, 23 callers */

void __cdecl16near FUN_1000_9b34(void)

{
  return;
}



/* 1000:9b42  FUN_1000_9b42  199 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_9b42(void)

{
  uint uVar1;
  byte bVar2;
  undefined2 in_AX;
  byte bVar3;
  undefined1 uVar5;
  undefined2 in_DX;
  uint uVar6;
  undefined2 unaff_DS;
  byte bVar4;
  
  if (*(int *)0x3288 == 0) {
    *(undefined2 *)&DAT_0000_3be2 = 0;
    return CONCAT22(in_DX,in_AX);
  }
  if (*(int *)0x3288 != 1) {
    uVar1 = *(uint *)&DAT_0000_3be2;
    bVar4 = (byte)((uint)*(undefined2 *)&DAT_0000_3be4 >> 8);
    bVar2 = (byte)*(undefined2 *)&DAT_0000_3be4;
    bVar3 = bVar4 - (char)(uVar1 >> 8);
    uVar5 = (undefined1)uVar1;
    if ((char)bVar3 < '\x03') {
      uVar6 = CONCAT11(bVar4 - 3,uVar5);
      if (bVar4 < 3) {
        uVar6 = uVar1 & 0xff;
      }
    }
    else {
      uVar6 = uVar1;
      if ((7 < bVar3) && (uVar6 = CONCAT11(bVar4 - 8,uVar5), 0x23 < (byte)(bVar4 - 8))) {
        uVar6 = CONCAT11(0x24,uVar5);
      }
    }
    bVar3 = bVar2 - (char)uVar6;
    bVar4 = (byte)(uVar6 >> 8);
    if ((char)bVar3 < '\x03') {
      uVar6 = CONCAT11(bVar4,bVar2 - 3);
      if (bVar2 < 3) {
        uVar6 = (uint)bVar4 << 8;
      }
    }
    else if ((7 < bVar3) && (uVar6 = CONCAT11(bVar4,bVar2 - 8), 0x23 < (byte)(bVar2 - 8))) {
      uVar6 = CONCAT11(bVar4,0x24);
    }
    *(uint *)&DAT_0000_3be2 = uVar6;
    return CONCAT22(in_DX,in_AX);
  }
  uVar1 = *(uint *)&DAT_0000_3be2;
  bVar4 = (byte)((uint)*(undefined2 *)&DAT_0000_3be4 >> 8);
  bVar2 = (byte)*(undefined2 *)&DAT_0000_3be4;
  bVar3 = bVar4 - (char)(uVar1 >> 8);
  uVar5 = (undefined1)uVar1;
  if ((char)bVar3 < '\x06') {
    uVar6 = CONCAT11(bVar4 - 6,uVar5);
    if (bVar4 < 6) {
      uVar6 = uVar1 & 0xff;
    }
  }
  else {
    uVar6 = uVar1;
    if ((0x10 < bVar3) && (uVar6 = CONCAT11(bVar4 - 0x11,uVar5), 0x17 < (byte)(bVar4 - 0x11))) {
      uVar6 = CONCAT11(0x18,uVar5);
    }
  }
  bVar3 = bVar2 - (char)uVar6;
  bVar4 = (byte)(uVar6 >> 8);
  if ((char)bVar3 < '\x06') {
    uVar6 = CONCAT11(bVar4,bVar2 - 6);
    if (bVar2 < 6) {
      uVar6 = (uint)bVar4 << 8;
    }
  }
  else if ((0x10 < bVar3) && (uVar6 = CONCAT11(bVar4,bVar2 - 0x11), 0x17 < (byte)(bVar2 - 0x11))) {
    uVar6 = CONCAT11(bVar4,0x18);
  }
  *(uint *)&DAT_0000_3be2 = uVar6;
  return CONCAT22(in_DX,in_AX);
}



/* 1000:9c09  FUN_1000_9c09  1332 bytes, 1 callers */

/* WARNING: Unable to track spacebase fully for stack */

undefined4 __cdecl16near FUN_1000_9c09(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint in_AX;
  int iVar4;
  int in_DX;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  undefined1 *unaff_BP;
  int *piVar40;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_ZF;
  bool bVar41;
  undefined1 auStack_16 [2];
  
  iVar5 = CONCAT11((char)in_DX,(char)in_AX);
  piVar40 = (int *)&DAT_0000_768e;
  iVar4 = 0x80;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    piVar1 = piVar40;
    piVar40 = piVar40 + 1;
    in_ZF = iVar5 == *piVar1;
  } while (!(bool)in_ZF);
  if ((bool)in_ZF) {
    iVar4 = 0xff - iVar4;
  }
  else {
    uVar6 = *(uint *)0x768c;
    iVar4 = 0x80;
    do {
      uVar6 = uVar6 + 1 & 0x7f;
      bVar41 = ((undefined *)&DAT_0000_788e)[uVar6] != '\0';
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0 && bVar41);
    iVar4 = in_DX;
    if (bVar41) goto LAB_1000_a138;
    *(uint *)0x768c = uVar6;
    *(int *)((undefined *)&DAT_0000_768e + uVar6 * 2) = iVar5;
    iVar5 = in_DX * 8 + 0x3000;
    puVar7 = (uint *)((uint)(byte)(((char)uVar6 + -0x80) - (char)in_AX) * 0x80);
    iVar4 = (in_AX & 0xff) * 8 + 0x3000;
    *(undefined1 **)0xc54a = auStack_16;
    uVar6 = *(uint *)0x0;
    uVar2 = *(uint *)0x20;
    uVar3 = *(uint *)0x40;
    uVar8 = *(uint *)0x60 & uVar3 & uVar2 & uVar6;
    uVar9 = ~uVar8;
    puVar7[0x30] = *(uint *)0x60 & uVar8 | *(uint *)0x60 & uVar9;
    puVar7[0x20] = *(uint *)0x40 & uVar8 | uVar3 & uVar9;
    puVar7[0x10] = *(uint *)0x20 & uVar8 | uVar2 & uVar9;
    *puVar7 = *(uint *)0x0 & uVar8 | uVar6 & uVar9;
    uVar6 = *(uint *)0x2;
    uVar2 = *(uint *)0x22;
    uVar3 = *(uint *)0x42;
    uVar10 = *(uint *)0x62 & uVar3 & uVar2 & uVar6;
    uVar11 = ~uVar10;
    puVar7[0x31] = *(uint *)0x62 & uVar10 | *(uint *)0x62 & uVar11;
    puVar7[0x21] = *(uint *)0x42 & uVar10 | uVar3 & uVar11;
    puVar7[0x11] = *(uint *)0x22 & uVar10 | uVar2 & uVar11;
    puVar7[1] = *(uint *)0x2 & uVar10 | uVar6 & uVar11;
    uVar6 = *(uint *)0x4;
    uVar2 = *(uint *)0x24;
    uVar3 = *(uint *)0x44;
    uVar12 = *(uint *)0x64 & uVar3 & uVar2 & uVar6;
    uVar13 = ~uVar12;
    puVar7[0x32] = *(uint *)0x64 & uVar12 | *(uint *)0x64 & uVar13;
    puVar7[0x22] = *(uint *)0x44 & uVar12 | uVar3 & uVar13;
    puVar7[0x12] = *(uint *)0x24 & uVar12 | uVar2 & uVar13;
    puVar7[2] = *(uint *)0x4 & uVar12 | uVar6 & uVar13;
    uVar6 = *(uint *)0x6;
    uVar2 = *(uint *)0x26;
    uVar3 = *(uint *)0x46;
    uVar14 = *(uint *)0x66 & uVar3 & uVar2 & uVar6;
    uVar15 = ~uVar14;
    puVar7[0x33] = *(uint *)0x66 & uVar14 | *(uint *)0x66 & uVar15;
    puVar7[0x23] = *(uint *)0x46 & uVar14 | uVar3 & uVar15;
    puVar7[0x13] = *(uint *)0x26 & uVar14 | uVar2 & uVar15;
    puVar7[3] = *(uint *)0x6 & uVar14 | uVar6 & uVar15;
    uVar6 = *(uint *)0x8;
    uVar2 = *(uint *)0x28;
    uVar3 = *(uint *)0x48;
    uVar16 = *(uint *)0x68 & uVar3 & uVar2 & uVar6;
    uVar17 = ~uVar16;
    puVar7[0x34] = *(uint *)0x68 & uVar16 | *(uint *)0x68 & uVar17;
    puVar7[0x24] = *(uint *)0x48 & uVar16 | uVar3 & uVar17;
    puVar7[0x14] = *(uint *)0x28 & uVar16 | uVar2 & uVar17;
    puVar7[4] = *(uint *)0x8 & uVar16 | uVar6 & uVar17;
    uVar6 = *(uint *)0xa;
    uVar2 = *(uint *)0x2a;
    uVar3 = *(uint *)0x4a;
    uVar18 = *(uint *)0x6a & uVar3 & uVar2 & uVar6;
    uVar19 = ~uVar18;
    puVar7[0x35] = *(uint *)0x6a & uVar18 | *(uint *)0x6a & uVar19;
    puVar7[0x25] = *(uint *)0x4a & uVar18 | uVar3 & uVar19;
    puVar7[0x15] = *(uint *)0x2a & uVar18 | uVar2 & uVar19;
    puVar7[5] = *(uint *)0xa & uVar18 | uVar6 & uVar19;
    uVar6 = *(uint *)0xc;
    uVar2 = *(uint *)0x2c;
    uVar3 = *(uint *)0x4c;
    uVar20 = *(uint *)0x6c & uVar3 & uVar2 & uVar6;
    uVar21 = ~uVar20;
    puVar7[0x36] = *(uint *)0x6c & uVar20 | *(uint *)0x6c & uVar21;
    puVar7[0x26] = *(uint *)0x4c & uVar20 | uVar3 & uVar21;
    puVar7[0x16] = *(uint *)0x2c & uVar20 | uVar2 & uVar21;
    puVar7[6] = *(uint *)0xc & uVar20 | uVar6 & uVar21;
    uVar6 = *(uint *)0xe;
    uVar2 = *(uint *)0x2e;
    uVar3 = *(uint *)0x4e;
    uVar22 = *(uint *)0x6e & uVar3 & uVar2 & uVar6;
    uVar23 = ~uVar22;
    puVar7[0x37] = *(uint *)0x6e & uVar22 | *(uint *)0x6e & uVar23;
    puVar7[0x27] = *(uint *)0x4e & uVar22 | uVar3 & uVar23;
    puVar7[0x17] = *(uint *)0x2e & uVar22 | uVar2 & uVar23;
    puVar7[7] = *(uint *)0xe & uVar22 | uVar6 & uVar23;
    uVar6 = *(uint *)0x10;
    uVar2 = *(uint *)0x30;
    uVar3 = *(uint *)0x50;
    uVar24 = *(uint *)0x70 & uVar3 & uVar2 & uVar6;
    uVar25 = ~uVar24;
    puVar7[0x38] = *(uint *)0x70 & uVar24 | *(uint *)0x70 & uVar25;
    puVar7[0x28] = *(uint *)0x50 & uVar24 | uVar3 & uVar25;
    puVar7[0x18] = *(uint *)0x30 & uVar24 | uVar2 & uVar25;
    puVar7[8] = *(uint *)0x10 & uVar24 | uVar6 & uVar25;
    uVar6 = *(uint *)0x12;
    uVar2 = *(uint *)0x32;
    uVar3 = *(uint *)0x52;
    uVar26 = *(uint *)0x72 & uVar3 & uVar2 & uVar6;
    uVar27 = ~uVar26;
    puVar7[0x39] = *(uint *)0x72 & uVar26 | *(uint *)0x72 & uVar27;
    puVar7[0x29] = *(uint *)0x52 & uVar26 | uVar3 & uVar27;
    puVar7[0x19] = *(uint *)0x32 & uVar26 | uVar2 & uVar27;
    puVar7[9] = *(uint *)0x12 & uVar26 | uVar6 & uVar27;
    uVar6 = *(uint *)0x14;
    uVar2 = *(uint *)0x34;
    uVar3 = *(uint *)0x54;
    uVar28 = *(uint *)0x74 & uVar3 & uVar2 & uVar6;
    uVar29 = ~uVar28;
    puVar7[0x3a] = *(uint *)0x74 & uVar28 | *(uint *)0x74 & uVar29;
    puVar7[0x2a] = *(uint *)0x54 & uVar28 | uVar3 & uVar29;
    puVar7[0x1a] = *(uint *)0x34 & uVar28 | uVar2 & uVar29;
    puVar7[10] = *(uint *)0x14 & uVar28 | uVar6 & uVar29;
    uVar6 = *(uint *)0x16;
    uVar2 = *(uint *)0x36;
    uVar3 = *(uint *)0x56;
    uVar30 = *(uint *)0x76 & uVar3 & uVar2 & uVar6;
    uVar31 = ~uVar30;
    puVar7[0x3b] = *(uint *)0x76 & uVar30 | *(uint *)0x76 & uVar31;
    puVar7[0x2b] = *(uint *)0x56 & uVar30 | uVar3 & uVar31;
    puVar7[0x1b] = *(uint *)0x36 & uVar30 | uVar2 & uVar31;
    puVar7[0xb] = *(uint *)0x16 & uVar30 | uVar6 & uVar31;
    uVar6 = *(uint *)0x18;
    uVar2 = *(uint *)0x38;
    uVar3 = *(uint *)0x58;
    uVar32 = *(uint *)0x78 & uVar3 & uVar2 & uVar6;
    uVar33 = ~uVar32;
    puVar7[0x3c] = *(uint *)0x78 & uVar32 | *(uint *)0x78 & uVar33;
    puVar7[0x2c] = *(uint *)0x58 & uVar32 | uVar3 & uVar33;
    puVar7[0x1c] = *(uint *)0x38 & uVar32 | uVar2 & uVar33;
    puVar7[0xc] = *(uint *)0x18 & uVar32 | uVar6 & uVar33;
    uVar6 = *(uint *)0x1a;
    uVar2 = *(uint *)0x3a;
    uVar3 = *(uint *)0x5a;
    uVar34 = *(uint *)0x7a & uVar3 & uVar2 & uVar6;
    uVar35 = ~uVar34;
    puVar7[0x3d] = *(uint *)0x7a & uVar34 | *(uint *)0x7a & uVar35;
    puVar7[0x2d] = *(uint *)0x5a & uVar34 | uVar3 & uVar35;
    puVar7[0x1d] = *(uint *)0x3a & uVar34 | uVar2 & uVar35;
    puVar7[0xd] = *(uint *)0x1a & uVar34 | uVar6 & uVar35;
    uVar6 = *(uint *)0x1c;
    uVar2 = *(uint *)0x3c;
    uVar3 = *(uint *)0x5c;
    uVar36 = *(uint *)0x7c & uVar3 & uVar2 & uVar6;
    uVar37 = ~uVar36;
    puVar7[0x3e] = *(uint *)0x7c & uVar36 | *(uint *)0x7c & uVar37;
    puVar7[0x2e] = *(uint *)0x5c & uVar36 | uVar3 & uVar37;
    puVar7[0x1e] = *(uint *)0x3c & uVar36 | uVar2 & uVar37;
    puVar7[0xe] = *(uint *)0x1c & uVar36 | uVar6 & uVar37;
    uVar6 = *(uint *)0x1e;
    uVar2 = *(uint *)0x3e;
    uVar3 = *(uint *)0x5e;
    uVar38 = *(uint *)0x7e & uVar3 & uVar2 & uVar6;
    uVar39 = ~uVar38;
    puVar7[0x3f] = *(uint *)0x7e & uVar38 | *(uint *)0x7e & uVar39;
    puVar7[0x2f] = *(uint *)0x5e & uVar38 | uVar3 & uVar39;
    puVar7[0x1f] = *(uint *)0x3e & uVar38 | uVar2 & uVar39;
    puVar7[0xf] = *(uint *)0x1e & uVar38 | uVar6 & uVar39;
    iVar4 = *(int *)*(int *)0xc54a;
    unaff_DS = ((int *)*(int *)0xc54a)[1];
  }
  unaff_BP = &stack0xfff0;
  ((undefined *)&DAT_0000_780e)[iVar4] = 1;
LAB_1000_a138:
  *(int *)(unaff_BP + 0xe) = iVar4;
  return CONCAT22(in_DX,in_AX);
}



/* 1000:a13d  FUN_1000_a13d  1248 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_a13d(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint in_AX;
  int iVar6;
  int in_DX;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  undefined2 unaff_DS;
  
  iVar7 = CONCAT11((char)((uint)*(undefined2 *)0x768c >> 8),(char)*(undefined2 *)0x768c + '\x01');
  *(int *)0x768c = iVar7;
  iVar7 = iVar7 + 0x100;
  puVar11 = (undefined2 *)0x0;
  iVar8 = iVar7 * 8 + 0x4000;
  puVar12 = (undefined2 *)0x0;
  for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar2 = puVar12;
    puVar12 = puVar12 + 1;
    puVar1 = puVar11;
    puVar11 = puVar11 + 1;
    *puVar2 = *puVar1;
  }
  iVar6 = in_DX * 8 + 0x4000;
  uVar3 = *(uint *)0x0;
  uVar4 = *(uint *)0x20;
  uVar5 = *(uint *)0x40;
  uVar9 = *(uint *)0x60 & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x60 = *(uint *)0x60 & uVar9 | *(uint *)0x60 & uVar10;
  *(uint *)0x40 = *(uint *)0x40 & uVar9 | uVar5 & uVar10;
  *(uint *)0x20 = *(uint *)0x20 & uVar9 | uVar4 & uVar10;
  *(uint *)0x0 = *(uint *)0x0 & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0x2;
  uVar4 = *(uint *)0x22;
  uVar5 = *(uint *)0x42;
  uVar9 = *(uint *)0x62 & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x62 = *(uint *)0x62 & uVar9 | *(uint *)0x62 & uVar10;
  *(uint *)0x42 = *(uint *)0x42 & uVar9 | uVar5 & uVar10;
  *(uint *)0x22 = *(uint *)0x22 & uVar9 | uVar4 & uVar10;
  *(uint *)0x2 = *(uint *)0x2 & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0x4;
  uVar4 = *(uint *)0x24;
  uVar5 = *(uint *)0x44;
  uVar9 = *(uint *)0x64 & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x64 = *(uint *)0x64 & uVar9 | *(uint *)0x64 & uVar10;
  *(uint *)0x44 = *(uint *)0x44 & uVar9 | uVar5 & uVar10;
  *(uint *)0x24 = *(uint *)0x24 & uVar9 | uVar4 & uVar10;
  *(uint *)0x4 = *(uint *)0x4 & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0x6;
  uVar4 = *(uint *)0x26;
  uVar5 = *(uint *)0x46;
  uVar9 = *(uint *)0x66 & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x66 = *(uint *)0x66 & uVar9 | *(uint *)0x66 & uVar10;
  *(uint *)0x46 = *(uint *)0x46 & uVar9 | uVar5 & uVar10;
  *(uint *)0x26 = *(uint *)0x26 & uVar9 | uVar4 & uVar10;
  *(uint *)0x6 = *(uint *)0x6 & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0x8;
  uVar4 = *(uint *)0x28;
  uVar5 = *(uint *)0x48;
  uVar9 = *(uint *)0x68 & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x68 = *(uint *)0x68 & uVar9 | *(uint *)0x68 & uVar10;
  *(uint *)0x48 = *(uint *)0x48 & uVar9 | uVar5 & uVar10;
  *(uint *)0x28 = *(uint *)0x28 & uVar9 | uVar4 & uVar10;
  *(uint *)0x8 = *(uint *)0x8 & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0xa;
  uVar4 = *(uint *)0x2a;
  uVar5 = *(uint *)0x4a;
  uVar9 = *(uint *)0x6a & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x6a = *(uint *)0x6a & uVar9 | *(uint *)0x6a & uVar10;
  *(uint *)0x4a = *(uint *)0x4a & uVar9 | uVar5 & uVar10;
  *(uint *)0x2a = *(uint *)0x2a & uVar9 | uVar4 & uVar10;
  *(uint *)0xa = *(uint *)0xa & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0xc;
  uVar4 = *(uint *)0x2c;
  uVar5 = *(uint *)0x4c;
  uVar9 = *(uint *)0x6c & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x6c = *(uint *)0x6c & uVar9 | *(uint *)0x6c & uVar10;
  *(uint *)0x4c = *(uint *)0x4c & uVar9 | uVar5 & uVar10;
  *(uint *)0x2c = *(uint *)0x2c & uVar9 | uVar4 & uVar10;
  *(uint *)0xc = *(uint *)0xc & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0xe;
  uVar4 = *(uint *)0x2e;
  uVar5 = *(uint *)0x4e;
  uVar9 = *(uint *)0x6e & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x6e = *(uint *)0x6e & uVar9 | *(uint *)0x6e & uVar10;
  *(uint *)0x4e = *(uint *)0x4e & uVar9 | uVar5 & uVar10;
  *(uint *)0x2e = *(uint *)0x2e & uVar9 | uVar4 & uVar10;
  *(uint *)0xe = *(uint *)0xe & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0x10;
  uVar4 = *(uint *)0x30;
  uVar5 = *(uint *)0x50;
  uVar9 = *(uint *)0x70 & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x70 = *(uint *)0x70 & uVar9 | *(uint *)0x70 & uVar10;
  *(uint *)0x50 = *(uint *)0x50 & uVar9 | uVar5 & uVar10;
  *(uint *)0x30 = *(uint *)0x30 & uVar9 | uVar4 & uVar10;
  *(uint *)0x10 = *(uint *)0x10 & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0x12;
  uVar4 = *(uint *)0x32;
  uVar5 = *(uint *)0x52;
  uVar9 = *(uint *)0x72 & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x72 = *(uint *)0x72 & uVar9 | *(uint *)0x72 & uVar10;
  *(uint *)0x52 = *(uint *)0x52 & uVar9 | uVar5 & uVar10;
  *(uint *)0x32 = *(uint *)0x32 & uVar9 | uVar4 & uVar10;
  *(uint *)0x12 = *(uint *)0x12 & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0x14;
  uVar4 = *(uint *)0x34;
  uVar5 = *(uint *)0x54;
  uVar9 = *(uint *)0x74 & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x74 = *(uint *)0x74 & uVar9 | *(uint *)0x74 & uVar10;
  *(uint *)0x54 = *(uint *)0x54 & uVar9 | uVar5 & uVar10;
  *(uint *)0x34 = *(uint *)0x34 & uVar9 | uVar4 & uVar10;
  *(uint *)0x14 = *(uint *)0x14 & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0x16;
  uVar4 = *(uint *)0x36;
  uVar5 = *(uint *)0x56;
  uVar9 = *(uint *)0x76 & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x76 = *(uint *)0x76 & uVar9 | *(uint *)0x76 & uVar10;
  *(uint *)0x56 = *(uint *)0x56 & uVar9 | uVar5 & uVar10;
  *(uint *)0x36 = *(uint *)0x36 & uVar9 | uVar4 & uVar10;
  *(uint *)0x16 = *(uint *)0x16 & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0x18;
  uVar4 = *(uint *)0x38;
  uVar5 = *(uint *)0x58;
  uVar9 = *(uint *)0x78 & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x78 = *(uint *)0x78 & uVar9 | *(uint *)0x78 & uVar10;
  *(uint *)0x58 = *(uint *)0x58 & uVar9 | uVar5 & uVar10;
  *(uint *)0x38 = *(uint *)0x38 & uVar9 | uVar4 & uVar10;
  *(uint *)0x18 = *(uint *)0x18 & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0x1a;
  uVar4 = *(uint *)0x3a;
  uVar5 = *(uint *)0x5a;
  uVar9 = *(uint *)0x7a & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x7a = *(uint *)0x7a & uVar9 | *(uint *)0x7a & uVar10;
  *(uint *)0x5a = *(uint *)0x5a & uVar9 | uVar5 & uVar10;
  *(uint *)0x3a = *(uint *)0x3a & uVar9 | uVar4 & uVar10;
  *(uint *)0x1a = *(uint *)0x1a & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0x1c;
  uVar4 = *(uint *)0x3c;
  uVar5 = *(uint *)0x5c;
  uVar9 = *(uint *)0x7c & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x7c = *(uint *)0x7c & uVar9 | *(uint *)0x7c & uVar10;
  *(uint *)0x5c = *(uint *)0x5c & uVar9 | uVar5 & uVar10;
  *(uint *)0x3c = *(uint *)0x3c & uVar9 | uVar4 & uVar10;
  *(uint *)0x1c = *(uint *)0x1c & uVar9 | uVar3 & uVar10;
  uVar3 = *(uint *)0x1e;
  uVar4 = *(uint *)0x3e;
  uVar5 = *(uint *)0x5e;
  uVar9 = *(uint *)0x7e & uVar5 & uVar4 & uVar3;
  uVar10 = ~uVar9;
  *(uint *)0x7e = *(uint *)0x7e & uVar9 | *(uint *)0x7e & uVar10;
  *(uint *)0x5e = *(uint *)0x5e & uVar9 | uVar5 & uVar10;
  *(uint *)0x3e = *(uint *)0x3e & uVar9 | uVar4 & uVar10;
  *(uint *)0x1e = *(uint *)0x1e & uVar9 | uVar3 & uVar10;
  return CONCAT22(in_DX,iVar7);
}



/* 1000:a61d  FUN_1000_a61d  16 bytes, 14 callers */

void __cdecl16near FUN_1000_a61d(void)

{
  return;
}



/* 1000:a62d  FUN_1000_a62d  41 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_a62d(void)

{
  undefined2 in_AX;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  pcVar2 = (char *)&DAT_0000_d27e;
  iVar1 = 0x900;
  do {
    pcVar3 = pcVar2 + 1;
    if ((char)(*(char *)0x3c00 + '\x14') == *pcVar2) break;
    pcVar2 = pcVar2 + 2;
    iVar1 = iVar1 + -1;
    pcVar3 = pcVar2;
  } while (iVar1 != 0);
  *(undefined2 *)&DAT_0000_3be4 =
       CONCAT11((char)(((uint)(pcVar3 + 0x2d81) >> 1) / 0x30),
                (char)(((uint)(pcVar3 + 0x2d81) >> 1) % 0x30));
  return in_AX;
}



/* 1000:a656  FUN_1000_a656  79 bytes, 3 callers */

undefined2 __cdecl16near FUN_1000_a656(void)

{
  uint uVar1;
  byte bVar2;
  undefined2 in_AX;
  uint uVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  undefined1 uVar5;
  
  if (*(int *)0x3c04 != 1) {
    uVar1 = *(uint *)&DAT_0000_3be4;
    bVar2 = (byte)(uVar1 >> 8);
    uVar3 = CONCAT11(bVar2 - 6,(char)uVar1);
    if (bVar2 < 6) {
      uVar3 = uVar1 & 0xff;
    }
    if (0x23 < (byte)(uVar3 >> 8)) {
      uVar3 = CONCAT11(0x24,(char)uVar3);
    }
    uVar5 = (undefined1)(uVar3 >> 8);
    bVar2 = (byte)uVar3 - 6;
    if ((byte)uVar3 < 6) {
      bVar2 = 0;
    }
    uVar4 = CONCAT11(uVar5,bVar2);
    if (0x23 < bVar2) {
      uVar4 = CONCAT11(uVar5,0x24);
    }
    *(undefined2 *)&DAT_0000_3be2 = uVar4;
    return in_AX;
  }
  uVar1 = *(uint *)&DAT_0000_3be4;
  bVar2 = (byte)(uVar1 >> 8);
  uVar3 = CONCAT11(bVar2 - 0xc,(char)uVar1);
  if (bVar2 < 0xc) {
    uVar3 = uVar1 & 0xff;
  }
  if (0x17 < (byte)(uVar3 >> 8)) {
    uVar3 = CONCAT11(0x18,(char)uVar3);
  }
  uVar5 = (undefined1)(uVar3 >> 8);
  bVar2 = (byte)uVar3 - 0xc;
  if ((byte)uVar3 < 0xc) {
    bVar2 = 0;
  }
  uVar4 = CONCAT11(uVar5,bVar2);
  if (0x17 < bVar2) {
    uVar4 = CONCAT11(uVar5,0x18);
  }
  *(undefined2 *)&DAT_0000_3be2 = uVar4;
  return in_AX;
}



/* 1000:a6a5  FUN_1000_a6a5  140 bytes, 5 callers */

undefined4 __cdecl16near FUN_1000_a6a5(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  char cVar5;
  byte bVar6;
  undefined2 in_AX;
  int iVar7;
  undefined2 in_DX;
  uint *puVar8;
  int iVar9;
  byte *pbVar10;
  undefined2 unaff_DS;
  
  iVar9 = -0x386e;
  iVar7 = 5;
  do {
    *(undefined2 *)(iVar9 + 8) = 0;
    *(undefined2 *)(iVar9 + 10) = 0;
    iVar9 = iVar9 + 0x16;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar8 = (uint *)&DAT_0000_d27e;
  iVar7 = 0x900;
  do {
    puVar4 = puVar8;
    puVar8 = puVar8 + 1;
    cVar5 = (char)*puVar4;
    uVar3 = *puVar4 >> 8;
    if (cVar5 == '\x05') {
      bVar6 = 4;
LAB_1000_a6ce:
      iVar9 = *(int *)((undefined *)&DAT_0000_12ef + (uint)bVar6 * 2);
      puVar4 = (uint *)(iVar9 + 8);
      uVar2 = *puVar4;
      *puVar4 = *puVar4 + uVar3;
      if (CARRY2(uVar2,uVar3)) {
        piVar1 = (int *)(iVar9 + 10);
        *piVar1 = *piVar1 + 1;
      }
    }
    else {
      bVar6 = cVar5 - 8;
      if (bVar6 < 4) goto LAB_1000_a6ce;
    }
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) {
      pbVar10 = (byte *)&DAT_0000_c800;
      iVar7 = 0x40;
      do {
        if (((*pbVar10 & 0x80) == 0) && ((pbVar10[10] & 0x20) == 0)) {
          iVar9 = *(int *)((undefined *)&DAT_0000_12ef + (uint)pbVar10[0xc] * 2);
          uVar2 = *(uint *)(pbVar10 + 6);
          puVar4 = (uint *)(iVar9 + 8);
          uVar3 = *puVar4;
          *puVar4 = *puVar4 + uVar2;
          if (CARRY2(uVar3,uVar2)) {
            piVar1 = (int *)(iVar9 + 10);
            *piVar1 = *piVar1 + 1;
          }
        }
        pbVar10 = pbVar10 + 0x10;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      puVar8 = (uint *)0xc792;
      iVar7 = 4;
      do {
        if (puVar8[4] == 0 && puVar8[5] == 0) {
          *puVar8 = *puVar8 | 4;
          *(undefined1 *)((int)puVar8 + 0x15) = 4;
        }
        puVar8 = puVar8 + 0xb;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      return CONCAT22(in_DX,in_AX);
    }
  } while( true );
}



/* 1000:a731  FUN_1000_a731  44 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_a731(void)

{
  int *piVar1;
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  if ((*(byte *)0x3be8 & ~(-2 << (*(byte *)0x3c02 & 0x1f))) == 0) {
    piVar1 = (int *)0x3bcc;
    *piVar1 = *piVar1 + 1;
    if (*piVar1 == 0) {
      *(undefined2 *)0x3bcc = 0xffff;
    }
    if (*(int *)0x3bca != 0) {
      *(int *)0x3bca = *(int *)0x3bca + -1;
    }
  }
  return in_AX;
}



/* 1000:a75d  FUN_1000_a75d  140 bytes, 1 callers */

void __cdecl16near FUN_1000_a75d(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 unaff_DS;
  bool bVar6;
  
  if (3 < *(byte *)0x3c00) {
    return;
  }
  iVar1 = *(int *)((undefined *)&DAT_0000_12ef + (uint)*(byte *)0x3c00 * 2);
  iVar5 = -0x386e;
  iVar3 = 4;
  uVar4 = 0;
  uVar2 = 0;
  do {
    if (iVar1 != iVar5) {
      bVar6 = CARRY2(uVar2,*(uint *)(iVar5 + 8));
      uVar2 = uVar2 + *(uint *)(iVar5 + 8);
      uVar4 = uVar4 + *(int *)(iVar5 + 10) + (uint)bVar6;
    }
    iVar5 = iVar5 + 0x16;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (*(uint *)(iVar1 + 10) < uVar4) {
LAB_1000_a7b2:
    if ((*(uint *)&DAT_0000_3bc6 & 1) != 0) {
      *(uint *)&DAT_0000_3bc6 = *(uint *)&DAT_0000_3bc6 & 0xfffe;
      FUN_1000_0ccc();
      FUN_1000_5f7e();
      FUN_1000_0ceb();
    }
  }
  else {
    if (*(uint *)(iVar1 + 10) <= uVar4) {
      if (*(uint *)(iVar1 + 8) < uVar2) goto LAB_1000_a7b2;
      if (*(uint *)(iVar1 + 8) <= uVar2) {
        return;
      }
    }
    uVar4 = ((uVar4 * 2 + (uint)CARRY2(uVar2,uVar2)) * 2 + (uint)CARRY2(uVar2 * 2,uVar2 * 2)) * 2 +
            (uint)CARRY2(uVar2 * 4,uVar2 * 4);
    if (((uVar4 < *(uint *)(iVar1 + 10)) ||
        ((uVar4 <= *(uint *)(iVar1 + 10) && (uVar2 * 8 < *(uint *)(iVar1 + 8))))) &&
       ((*(uint *)&DAT_0000_3bc6 & 1) == 0)) {
      *(uint *)&DAT_0000_3bc6 = *(uint *)&DAT_0000_3bc6 | 1;
      FUN_1000_0ccc();
      FUN_1000_5f7e();
      FUN_1000_0ceb();
    }
  }
  return;
}



/* 1000:a7e9  FUN_1000_a7e9  84 bytes, 3 callers */

undefined4 __cdecl16near FUN_1000_a7e9(void)

{
  undefined2 in_AX;
  int iVar1;
  int iVar2;
  byte bVar3;
  undefined2 in_DX;
  int in_BX;
  undefined2 unaff_DS;
  uint uVar4;
  
  bVar3 = (char)in_DX - 1;
  iVar1 = 3;
  do {
    uVar4 = (uint)bVar3;
    iVar2 = 3;
    do {
      FUN_1000_9b34(iVar1,uVar4);
      bVar3 = ((undefined *)&DAT_0000_d27e)[in_BX];
      if ((bVar3 < 0x30) || (0x5f < bVar3)) {
        if ((bVar3 < 0x20) || (0x2f < bVar3)) {
          if ((bVar3 == 0) || (4 < bVar3)) {
            if ((0x5f < bVar3) && (bVar3 < 0x70)) {
              FUN_1000_a93f();
            }
          }
          else {
            FUN_1000_a904();
          }
        }
        else {
          FUN_1000_a8b6();
        }
      }
      else {
        FUN_1000_a83d();
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    bVar3 = (char)uVar4 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:a83d  FUN_1000_a83d  121 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_a83d(void)

{
  undefined2 in_AX;
  uint uVar1;
  byte bVar2;
  char extraout_DL;
  char extraout_DH;
  int in_BX;
  undefined2 unaff_DS;
  
  FUN_1000_b4a8();
  FUN_1000_b4a8();
  FUN_1000_b4a8();
  FUN_1000_b4a8();
  FUN_1000_b4a8();
  FUN_1000_b4a8();
  bVar2 = 0;
  uVar1 = FUN_1000_b4a8();
  bVar2 = (((uint)bVar2 << 7 | uVar1 & 0xff00) & 0x100) != 0;
  uVar1 = FUN_1000_b4a8();
  bVar2 = (byte)(((uint)bVar2 << 8 | uVar1 >> 8) >> 1);
  if (extraout_DH == '\0') {
    bVar2 = bVar2 & 0x7c;
  }
  if (extraout_DH == '/') {
    bVar2 = bVar2 & 199;
  }
  if (extraout_DL == '\0') {
    bVar2 = bVar2 & 0xf1;
  }
  if (extraout_DL == '/') {
    bVar2 = bVar2 & 0x1f;
  }
  ((undefined *)&DAT_0000_d27e)[in_BX] = ((undefined *)&DAT_0000_2321)[bVar2];
  return in_AX;
}



/* 1000:a8b6  FUN_1000_a8b6  78 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_a8b6(void)

{
  undefined2 in_AX;
  byte extraout_AH;
  byte bVar1;
  byte extraout_AH_00;
  byte extraout_AH_01;
  byte extraout_AH_02;
  char in_DL;
  char extraout_DL;
  byte extraout_DL_00;
  byte extraout_DL_01;
  byte bVar2;
  char in_DH;
  byte extraout_DH;
  byte extraout_DH_00;
  byte bVar3;
  int in_BX;
  undefined2 unaff_DS;
  bool bVar4;
  
  bVar1 = 0;
  bVar4 = false;
  bVar3 = 0;
  if (in_DH != '\0') {
    FUN_1000_b4c4();
    in_DL = extraout_DL;
    bVar3 = extraout_DH;
    bVar1 = extraout_AH;
    if (bVar4) {
      bVar1 = extraout_AH | 1;
    }
  }
  bVar4 = false;
  bVar2 = 0;
  if (in_DL != '\0') {
    FUN_1000_b4c4();
    bVar2 = extraout_DL_00;
    bVar3 = extraout_DH_00;
    bVar1 = extraout_AH_00;
    if (bVar4) {
      bVar1 = extraout_AH_00 | 2;
    }
  }
  bVar4 = bVar3 < 0x2f;
  if (bVar4) {
    FUN_1000_b4c4();
    bVar2 = extraout_DL_01;
    bVar1 = extraout_AH_01;
    if (bVar4) {
      bVar1 = extraout_AH_01 | 4;
    }
  }
  bVar4 = bVar2 < 0x2f;
  if (bVar4) {
    FUN_1000_b4c4();
    bVar1 = extraout_AH_02;
    if (bVar4) {
      bVar1 = extraout_AH_02 | 8;
    }
  }
  ((undefined *)&DAT_0000_d27e)[in_BX] = bVar1 + 0x20;
  return in_AX;
}



/* 1000:a904  FUN_1000_a904  59 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_a904(void)

{
  char cVar1;
  undefined2 in_AX;
  byte bVar2;
  byte in_DL;
  int in_BX;
  undefined2 unaff_DS;
  
  bVar2 = 0;
  if ((in_DL != 0) && (bVar2 = 0, 3 < (byte)(((undefined *)&DAT_0000_d27c)[in_BX] - 1))) {
    bVar2 = 1;
  }
  if ((in_DL < 0x2f) && (3 < (byte)(((undefined *)&DAT_0000_d280)[in_BX] - 1))) {
    bVar2 = bVar2 | 2;
  }
  LOCK();
  cVar1 = ((undefined *)&DAT_0000_d27e)[in_BX];
  ((undefined *)&DAT_0000_d27e)[in_BX] = bVar2 + 1;
  UNLOCK();
  if ((byte)(cVar1 - 1U) < 4) {
    ((undefined *)&DAT_0000_d27f)[in_BX] = 100;
  }
  return in_AX;
}



/* 1000:a93f  FUN_1000_a93f  78 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_a93f(void)

{
  undefined2 in_AX;
  byte extraout_AH;
  byte bVar1;
  byte extraout_AH_00;
  byte extraout_AH_01;
  byte extraout_AH_02;
  char in_DL;
  char extraout_DL;
  byte extraout_DL_00;
  byte extraout_DL_01;
  byte bVar2;
  char in_DH;
  byte extraout_DH;
  byte extraout_DH_00;
  byte bVar3;
  int in_BX;
  undefined2 unaff_DS;
  bool bVar4;
  
  bVar1 = 0;
  bVar4 = false;
  bVar3 = 0;
  if (in_DH != '\0') {
    FUN_1000_b494();
    in_DL = extraout_DL;
    bVar3 = extraout_DH;
    bVar1 = extraout_AH;
    if (bVar4) {
      bVar1 = extraout_AH | 1;
    }
  }
  bVar4 = false;
  bVar2 = 0;
  if (in_DL != '\0') {
    FUN_1000_b494();
    bVar2 = extraout_DL_00;
    bVar3 = extraout_DH_00;
    bVar1 = extraout_AH_00;
    if (bVar4) {
      bVar1 = extraout_AH_00 | 2;
    }
  }
  bVar4 = bVar3 < 0x2f;
  if (bVar4) {
    FUN_1000_b494();
    bVar2 = extraout_DL_01;
    bVar1 = extraout_AH_01;
    if (bVar4) {
      bVar1 = extraout_AH_01 | 4;
    }
  }
  bVar4 = bVar2 < 0x2f;
  if (bVar4) {
    FUN_1000_b494();
    bVar1 = extraout_AH_02;
    if (bVar4) {
      bVar1 = extraout_AH_02 | 8;
    }
  }
  ((undefined *)&DAT_0000_d27e)[in_BX] = bVar1 + 0x60;
  return in_AX;
}



/* 1000:a98d  FUN_1000_a98d  61 bytes, 3 callers */

void __cdecl16near FUN_1000_a98d(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  bool bVar4;
  
  if (((byte)(((undefined *)&DAT_0000_d27e)[unaff_DI] - 0x14) < 4) ||
     ((char)(((undefined *)&DAT_0000_d27e)[unaff_DI] + -8) == *(char *)(unaff_SI + 0xc))) {
    bVar4 = false;
    FUN_1000_abc7();
    if (!bVar4) {
      return;
    }
  }
  uVar3 = (*(uint *)(unaff_SI + 6) >> 8) + 1;
  puVar1 = (uint *)(unaff_SI + 6);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 - uVar3;
  if (uVar3 <= uVar2 && *puVar1 != 0) {
    return;
  }
  FUN_1000_4924();
  return;
}



/* 1000:a9ca  FUN_1000_a9ca  201 bytes, 4 callers */

undefined2 __cdecl16near FUN_1000_a9ca(void)

{
  byte bVar1;
  uint *puVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 in_AX;
  undefined2 in_CX;
  int iVar5;
  undefined1 *unaff_SI;
  byte *pbVar6;
  undefined2 unaff_DS;
  
  *(undefined2 *)(unaff_SI + 6) = 0;
  unaff_SI[0xb] = 0xff;
  if ((unaff_SI[10] & 0x20) != 0) {
    unaff_SI[0xe] = 3;
    bVar1 = unaff_SI[0xc];
    *(undefined2 *)0xc546 = *(undefined2 *)((undefined *)&DAT_0000_12ad + (uint)bVar1 * 2);
    puVar2 = *(uint **)((undefined *)&DAT_0000_12ef + (uint)bVar1 * 2);
    *puVar2 = *puVar2 | 1;
    *(undefined1 *)((int)puVar2 + 0x15) = unaff_SI[0xf];
    puVar2[3] = 0;
    uVar3 = *(undefined2 *)&DAT_0000_3be2;
    uVar4 = *(undefined2 *)&DAT_0000_3be4;
    *(undefined2 *)&DAT_0000_3be4 = *(undefined2 *)(unaff_SI + 2);
    FUN_1000_a656();
    bVar1 = unaff_SI[0xc];
    pbVar6 = (byte *)&DAT_0000_c800;
    iVar5 = 0x40;
    do {
      if (((*pbVar6 & 0x80) == 0) && (bVar1 == pbVar6[0xc])) {
        pbVar6[10] = pbVar6[10] & 0x20 | 0xc;
        pbVar6[1] = 6;
        *pbVar6 = *pbVar6 | 1;
        pbVar6[0xb] = 0xff;
      }
      pbVar6 = pbVar6 + 0x10;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_1000_0d12(CONCAT11(0x80,bVar1),in_CX);
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    FUN_1000_72ad();
    FUN_1000_c921();
    *(undefined2 *)((undefined *)&DAT_0000_e47e + *(int *)(unaff_SI + 4)) = 0;
    FUN_1000_b102();
    *(undefined2 *)&DAT_0000_3be4 = uVar4;
    *(undefined2 *)&DAT_0000_3be2 = uVar3;
    FUN_1000_7c9e();
    FUN_1000_72ad();
  }
  *(undefined2 *)((undefined *)&DAT_0000_e47e + *(int *)(unaff_SI + 4)) = 0;
  *unaff_SI = 0x80;
  if (unaff_SI == (undefined1 *)*(undefined2 *)&DAT_0000_32bf) {
    *(undefined2 *)&DAT_0000_32bf = 0;
  }
  return in_AX;
}



/* 1000:aa93  FUN_1000_aa93  27 bytes, 5 callers */

void __cdecl16near FUN_1000_aa93(void)

{
  return;
}



/* 1000:aaae  FUN_1000_aaae  22 bytes, 2 callers */

undefined2 __cdecl16near FUN_1000_aaae(void)

{
  undefined2 *in_BX;
  
  FUN_1000_9b34();
  return *in_BX;
}



/* 1000:aac4  FUN_1000_aac4  17 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_aac4(void)

{
  undefined2 *in_BX;
  
  return *in_BX;
}



/* 1000:aad5  FUN_1000_aad5  86 bytes, 1 callers */

uint __cdecl16near FUN_1000_aad5(void)

{
  byte bVar1;
  uint uVar2;
  uint *in_BX;
  undefined2 unaff_DS;
  
  uVar2 = *in_BX;
  if (0x1ef < uVar2) {
    bVar1 = (byte)in_BX[-0x16c1];
    uVar2 = CONCAT11((char)(uVar2 >> 8),bVar1);
    if (((bVar1 == 0x7a) || (bVar1 == 0x7b)) || ((0x2f < bVar1 && (bVar1 < 0x60)))) {
      uVar2 = in_BX[-0x30];
      if (in_BX[0x30] < in_BX[-0x30]) {
        uVar2 = in_BX[0x30];
      }
      if (in_BX[-1] < uVar2) {
        uVar2 = in_BX[-1];
      }
      if (in_BX[1] < uVar2) {
        uVar2 = in_BX[1];
      }
      uVar2 = uVar2 + 1;
    }
  }
  return uVar2;
}



/* 1000:ab3e  FUN_1000_ab3e  137 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_ab3e(void)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  undefined2 in_AX;
  int iVar4;
  undefined2 in_DX;
  uint uVar5;
  int in_BX;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  FUN_1000_9b34();
  bVar2 = ((undefined *)&DAT_0000_d27e)[in_BX];
  iVar6 = 0;
  if (((((bVar2 != 0) && ((iVar6 = 1, bVar2 < 8 || (0xb < bVar2)))) &&
       ((iVar6 = 2, bVar2 < 0xc || (0xf < bVar2)))) &&
      ((((((iVar6 = 3, bVar2 == 0 || (4 < bVar2)) && (iVar6 = 4, bVar2 != 0x7b)) &&
         ((iVar6 = 5, bVar2 < 0x20 || (0x2f < bVar2)))) &&
        ((iVar6 = 6, bVar2 != 5 && (iVar6 = 7, bVar2 != 0x7a)))) &&
       ((iVar6 = 8, bVar2 < 0x30 || (0x5f < bVar2)))))) &&
     ((iVar6 = 9, bVar2 < 0x14 || (0x17 < bVar2)))) {
    iVar6 = 10;
  }
  uVar5 = *(uint *)(iVar6 * 4 + 0x22f5);
  iVar4 = 0xc;
  piVar8 = (int *)0xc4f8;
  do {
    piVar7 = piVar8;
    uVar3 = uVar5 & 1;
    uVar5 = uVar5 >> 1;
    *piVar7 = -(uint)(uVar3 != 0);
    iVar4 = iVar4 + -1;
    piVar8 = piVar7 + 1;
  } while (iVar4 != 0);
  piVar8 = piVar7 + 2;
  piVar7[1] = -1;
  uVar5 = *(uint *)(iVar6 * 4 + 0x22f7);
  iVar6 = 0xc;
  do {
    uVar3 = uVar5 & 1;
    uVar5 = uVar5 >> 1;
    piVar1 = piVar8;
    piVar8 = piVar8 + 1;
    *piVar1 = -(uint)(uVar3 != 0);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *piVar8 = -1;
  return CONCAT22(in_DX,in_AX);
}



/* 1000:abc7  FUN_1000_abc7  57 bytes, 4 callers */

void __cdecl16near FUN_1000_abc7(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint in_AX;
  uint in_DX;
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  iVar1 = *(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_SI[0xc] * 2);
  uVar2 = (uint)(*(uint *)(iVar1 + 0xe) < in_AX);
  uVar3 = *(uint *)(iVar1 + 0x10) - in_DX;
  if (*(uint *)(iVar1 + 0x10) < in_DX || uVar3 < uVar2) {
    if (*(byte *)0x3c00 == unaff_SI[0xc]) {
      *(undefined2 *)0xc52c = 0xffff;
      *unaff_SI = *unaff_SI | 1;
    }
  }
  else {
    *(int *)(iVar1 + 0xe) = *(uint *)(iVar1 + 0xe) - in_AX;
    *(int *)(iVar1 + 0x10) = uVar3 - uVar2;
  }
  return;
}



/* 1000:ac00  FUN_1000_ac00  187 bytes, 5 callers */

void __cdecl16near FUN_1000_ac00(void)

{
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  if (unaff_SI[0xc] == 4) {
    if ((*unaff_SI & 2) != 0) {
      return;
    }
    return;
  }
  if ((*unaff_SI & 2) == 0) {
    if ((*unaff_SI & 1) != 0) {
      return;
    }
    return;
  }
  return;
}



/* 1000:acbb  FUN_1000_acbb  155 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_acbb(void)

{
  int iVar1;
  undefined2 in_AX;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 in_DX;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined2 unaff_DS;
  
  iVar4 = *(int *)0xce70;
  if (iVar4 != 0) {
    uVar3 = 0;
    piVar7 = (int *)&DAT_0000_cc00;
    do {
      piVar6 = piVar7;
      iVar5 = uVar3 + 0xc80;
      if (0xf37f < uVar3) {
        iVar5 = -1;
      }
      iVar1 = *piVar6;
      piVar6[2] = iVar5 - iVar1;
      uVar2 = (uint)(((ulong)((piVar6[1] & 0xffU) * 10 + ((uint)piVar6[1] >> 8)) *
                     (ulong)(uint)(iVar5 - iVar1)) / 1000);
      piVar6[3] = uVar2;
      piVar6[4] = 0;
      iVar5 = uVar2 - uVar3;
      if (uVar2 < uVar3) {
        piVar6[4] = -1;
        iVar5 = -iVar5;
      }
      piVar6[5] = iVar5;
      piVar7 = piVar6 + 6;
      iVar4 = iVar4 + -1;
      uVar3 = uVar2;
    } while (iVar4 != 0);
    if ((*(int *)0xce70 == 0x33) && (*piVar7 != 0)) {
      iVar4 = uVar2 + 0xc80;
      if (0xf37f < uVar2) {
        iVar4 = -1;
      }
      iVar5 = *piVar7;
      piVar6[8] = iVar4 - iVar5;
      uVar3 = (uint)(((ulong)((piVar6[7] & 0xffU) * 10 + ((uint)piVar6[7] >> 8)) *
                     (ulong)(uint)(iVar4 - iVar5)) / 1000);
      piVar6[9] = uVar3;
      piVar6[10] = 0;
      iVar4 = uVar3 - uVar2;
      if (uVar3 < uVar2) {
        piVar6[10] = -1;
        iVar4 = -iVar4;
      }
      piVar6[0xb] = iVar4;
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:ad56  FUN_1000_ad56  42 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_ad56(void)

{
  undefined *puVar1;
  undefined2 in_AX;
  undefined2 in_DX;
  byte bVar2;
  undefined *puVar3;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  bVar2 = 0;
  puVar3 = (undefined *)&DAT_0000_ce74;
  do {
    puVar3[0x100] = *(undefined1 *)ZEXT24((undefined1 *)&DAT_0000_2d3d + (bVar2 & 0xf));
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = *(undefined1 *)ZEXT24((undefined1 *)&DAT_0000_2d3d + (bVar2 >> 4));
    bVar2 = bVar2 + 1;
  } while (bVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:ad80  FUN_1000_ad80  22 bytes, 9 callers */

void __cdecl16near FUN_1000_ad80(void)

{
  return;
}



/* 1000:ada4  FUN_1000_ada4  26 bytes, 1 callers */

void __cdecl16near FUN_1000_ada4(void)

{
  int in_BX;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  FUN_1000_ad80();
  if (!(bool)in_CF) {
    FUN_1000_9b34();
    if (((byte)((undefined *)&DAT_0000_d27e)[in_BX] < 0x30) &&
       (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0)) {
      return;
    }
  }
  return;
}



/* 1000:adbe  FUN_1000_adbe  18 bytes, 4 callers */

void __cdecl16near FUN_1000_adbe(void)

{
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  if (*(int *)0xc4f2 != 0) {
    *(int *)0xc4f2 = *(int *)0xc4f2 + -1;
    return;
  }
  *unaff_SI = *unaff_SI | 1;
  return;
}



/* 1000:add0  FUN_1000_add0  27 bytes, 3 callers */

undefined4 __cdecl16near FUN_1000_add0(void)

{
  undefined2 in_AX;
  int iVar1;
  undefined2 in_DX;
  byte *pbVar2;
  undefined2 unaff_DS;
  
  pbVar2 = (byte *)&DAT_0000_c800;
  iVar1 = 0x40;
  do {
    if ((*pbVar2 & 0x80) != 0) break;
    pbVar2 = pbVar2 + 0x10;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:adeb  FUN_1000_adeb  179 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_adeb(void)

{
  char cVar1;
  undefined2 in_AX;
  undefined2 uVar2;
  char cVar3;
  int unaff_DI;
  undefined2 unaff_DS;
  
  uVar2 = 0;
  cVar1 = (char)in_AX;
  if (((undefined *)&DAT_0000_d2e0)[unaff_DI] == '\0') {
    uVar2 = 1;
  }
  else if (((undefined *)&DAT_0000_d2e0)[unaff_DI] == cVar1) {
    uVar2 = 0x100;
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d2dc)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d2dc)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d220)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d220)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d21c)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d21c)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d280)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d280)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d27c)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d27c)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d2de)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d2de)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d21e)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d21e)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  return CONCAT22(uVar2,in_AX);
}



/* 1000:ae9e  FUN_1000_ae9e  103 bytes, 5 callers */

void __cdecl16near FUN_1000_ae9e(void)

{
  return;
}



/* 1000:af05  FUN_1000_af05  61 bytes, 2 callers */

byte __cdecl16near FUN_1000_af05(void)

{
  byte bVar1;
  char cVar2;
  int unaff_DI;
  undefined2 unaff_DS;
  
  cVar2 = '\0';
  if (((3 < (byte)(((undefined *)&DAT_0000_d21e)[unaff_DI] - 1)) &&
      (cVar2 = '\x02', 3 < (byte)(((undefined *)&DAT_0000_d2de)[unaff_DI] - 1))) &&
     (cVar2 = '\x01', 3 < (byte)(((undefined *)&DAT_0000_d27c)[unaff_DI] - 1))) {
    cVar2 = '\x03';
    bVar1 = ((undefined *)&DAT_0000_d280)[unaff_DI] - 1;
    if (3 < bVar1) {
      return bVar1;
    }
  }
  return cVar2 * '\x02';
}



/* 1000:af42  FUN_1000_af42  45 bytes, 2 callers */

void __cdecl16near FUN_1000_af42(void)

{
  return;
}



/* 1000:af6f  FUN_1000_af6f  200 bytes, 2 callers */

char __cdecl16near FUN_1000_af6f(void)

{
  char cVar1;
  char in_AL;
  char in_AH;
  char extraout_AH;
  char extraout_AH_00;
  char extraout_AH_01;
  undefined2 uVar2;
  uint unaff_DI;
  undefined2 unaff_DS;
  bool bVar3;
  
  uVar2 = 0x808;
  if (((byte)((undefined *)&DAT_0000_d21e)[unaff_DI] < 0x30) &&
     ((cVar1 = ((undefined *)&DAT_0000_d1be)[unaff_DI], cVar1 == '\0' ||
      (((cVar1 != in_AL && (cVar1 != in_AH)) && ((byte)(cVar1 - 8U) < 8)))))) {
    bVar3 = 0xbf < unaff_DI;
    in_AL = FUN_1000_ae9e();
    in_AH = extraout_AH;
    if (!bVar3) {
      return '\0';
    }
  }
  if (((byte)((undefined *)&DAT_0000_d2de)[unaff_DI] < 0x30) &&
     ((cVar1 = ((undefined *)&DAT_0000_d33e)[unaff_DI], cVar1 == '\0' ||
      (((cVar1 != in_AL && (cVar1 != in_AH)) &&
       ((byte)(cVar1 - (char)((uint)uVar2 >> 8)) < (byte)uVar2)))))) {
    bVar3 = 0xff3f < unaff_DI;
    in_AL = FUN_1000_ae9e();
    in_AH = extraout_AH_00;
    if (!bVar3) {
      return '\x04';
    }
  }
  if (((byte)((undefined *)&DAT_0000_d27c)[unaff_DI] < 0x30) &&
     ((cVar1 = ((undefined *)&DAT_0000_d27a)[unaff_DI], cVar1 == '\0' ||
      (((cVar1 != in_AL && (cVar1 != in_AH)) &&
       ((byte)(cVar1 - (char)((uint)uVar2 >> 8)) < (byte)uVar2)))))) {
    bVar3 = 3 < unaff_DI;
    in_AL = FUN_1000_ae9e();
    in_AH = extraout_AH_01;
    if (!bVar3) {
      return '\x02';
    }
  }
  if (((byte)((undefined *)&DAT_0000_d280)[unaff_DI] < 0x30) &&
     ((cVar1 = ((undefined *)&DAT_0000_d282)[unaff_DI], cVar1 == '\0' ||
      (((cVar1 != in_AL && (cVar1 != in_AH)) &&
       ((byte)(cVar1 - (char)((uint)uVar2 >> 8)) < (byte)uVar2)))))) {
    bVar3 = 0xfffb < unaff_DI;
    in_AL = FUN_1000_ae9e();
    if (!bVar3) {
      return '\x06';
    }
  }
  return in_AL;
}



/* 1000:b037  FUN_1000_b037  203 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_b037(void)

{
  byte bVar1;
  undefined2 in_AX;
  byte bVar4;
  int iVar2;
  undefined2 uVar3;
  undefined1 uVar5;
  byte bVar6;
  undefined2 in_DX;
  int unaff_DI;
  undefined2 unaff_DS;
  
  bVar1 = ((undefined *)&DAT_0000_d21e)[unaff_DI];
  bVar4 = (byte)((uint)in_AX >> 8);
  bVar6 = (byte)in_AX;
  if (bVar1 < 0x30) {
    if (((bVar1 != bVar4) && (bVar1 != bVar6)) && ((byte)(bVar1 - 8) < 4)) {
      iVar2 = (uint)bVar4 << 8;
      goto LAB_1000_b0ff;
    }
    bVar1 = ((undefined *)&DAT_0000_d1be)[unaff_DI];
    if (((bVar1 != bVar4) && (bVar1 != bVar6)) && ((byte)(bVar1 - 8) < 4)) {
      iVar2 = CONCAT11(bVar4,0x80);
      goto LAB_1000_b0ff;
    }
  }
  bVar1 = ((undefined *)&DAT_0000_d2de)[unaff_DI];
  if (bVar1 < 0x30) {
    if (((bVar1 != bVar4) && (bVar1 != bVar6)) && ((byte)(bVar1 - 8) < 4)) {
      iVar2 = CONCAT11(bVar4,2);
      goto LAB_1000_b0ff;
    }
    bVar1 = ((undefined *)&DAT_0000_d33e)[unaff_DI];
    if (((bVar1 != bVar4) && (bVar1 != bVar6)) && ((byte)(bVar1 - 8) < 4)) {
      iVar2 = CONCAT11(bVar4,0x82);
      goto LAB_1000_b0ff;
    }
  }
  bVar1 = ((undefined *)&DAT_0000_d27c)[unaff_DI];
  if (bVar1 < 0x30) {
    if (((bVar1 != bVar4) && (bVar1 != bVar6)) && ((byte)(bVar1 - 8) < 4)) {
      iVar2 = CONCAT11(bVar4,1);
      goto LAB_1000_b0ff;
    }
    bVar1 = ((undefined *)&DAT_0000_d27a)[unaff_DI];
    if (((bVar1 != bVar4) && (bVar1 != bVar6)) && ((byte)(bVar1 - 8) < 4)) {
      iVar2 = CONCAT11(bVar4,0x81);
      goto LAB_1000_b0ff;
    }
  }
  bVar1 = ((undefined *)&DAT_0000_d280)[unaff_DI];
  uVar3 = CONCAT11(bVar4,bVar1);
  if (bVar1 < 0x30) {
    if (((bVar1 == bVar4) || (bVar1 == bVar6)) ||
       (uVar3 = CONCAT11(bVar4,bVar1 - 8), 3 < (byte)(bVar1 - 8))) {
      bVar1 = ((undefined *)&DAT_0000_d282)[unaff_DI];
      uVar5 = (undefined1)((uint)uVar3 >> 8);
      uVar3 = CONCAT11(uVar5,bVar1);
      if (((bVar1 == bVar4) || (bVar1 == bVar6)) ||
         (uVar3 = CONCAT11(uVar5,bVar1 - 8), 3 < (byte)(bVar1 - 8))) goto LAB_1000_b0fc;
      iVar2 = CONCAT11(uVar5,0x83);
    }
    else {
      iVar2 = CONCAT11(bVar4,3);
    }
LAB_1000_b0ff:
    return CONCAT22(in_DX,iVar2);
  }
LAB_1000_b0fc:
  return CONCAT22(in_DX,uVar3);
}



/* 1000:b102  FUN_1000_b102  395 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_b102(void)

{
  uint *puVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined2 in_AX;
  int iVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  int iVar12;
  undefined2 in_DX;
  uint *puVar13;
  byte *pbVar14;
  undefined2 unaff_DS;
  undefined1 uVar15;
  
  puVar13 = (uint *)0xc792;
  iVar12 = 4;
  while (((*puVar13 & 8) != 0 || ((*puVar13 & 5) == 0))) {
    puVar13 = puVar13 + 0xb;
    iVar12 = iVar12 + -1;
    if (iVar12 == 0) goto LAB_1000_b28a;
  }
  uVar11 = *(undefined2 *)&DAT_0000_3be2;
  uVar5 = *(undefined2 *)&DAT_0000_3be4;
  iVar9 = (uint)*(byte *)((int)puVar13 + 0x15) * 0x16;
  uVar6 = puVar13[7];
  puVar1 = (uint *)((undefined *)&DAT_0000_c7a0 + iVar9);
  uVar4 = *puVar1;
  *puVar1 = *puVar1 + uVar6;
  uVar7 = puVar13[8];
  puVar1 = (uint *)((undefined *)&DAT_0000_c7a2 + iVar9);
  uVar6 = (uint)CARRY2(uVar4,uVar6);
  uVar4 = *puVar1;
  uVar8 = *puVar1 + uVar7;
  *puVar1 = uVar8 + uVar6;
  if (CARRY2(uVar4,uVar7) || CARRY2(uVar8,uVar6)) {
    *(undefined2 *)((undefined *)&DAT_0000_c7a0 + iVar9) = 0xffff;
    *(uint *)((undefined *)&DAT_0000_c7a2 + iVar9) =
         *(int *)((undefined *)&DAT_0000_c7a2 + iVar9) + -1 +
         (uint)(CARRY2(uVar4,uVar7) || CARRY2(uVar8,uVar6));
  }
  puVar13[7] = 0;
  puVar13[8] = 0;
  *(undefined1 *)(puVar13 + 9) = 0;
  *puVar13 = *puVar13 | 8;
  puVar13[3] = 0;
  *(uint *)&DAT_0000_3be4 = puVar13[1];
  FUN_1000_a656();
  uVar4 = puVar13[2];
  LOCK();
  bVar3 = (byte)puVar13[10];
  *(byte *)(puVar13 + 10) = 0x80;
  UNLOCK();
  if (bVar3 < 4) {
    *(undefined1 *)(*(int *)((undefined *)&DAT_0000_12ef + (uint)bVar3 * 2) + 0x14) = 0x80;
  }
  iVar12 = 4 - iVar12;
  *(undefined2 *)0xc536 = *(undefined2 *)((undefined *)&DAT_0000_12ad + iVar12 * 2);
  FUN_1000_7c9e();
  uVar15 = (undefined1)iVar12;
  FUN_1000_93c5();
  uVar10 = FUN_1000_4a4d();
  FUN_1000_0d12(uVar10);
  FUN_1000_72ad();
  FUN_1000_c921();
  *(undefined **)((undefined *)&DAT_0000_d21c + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d21e + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d220 + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d27c + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d27e + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d280 + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d2dc + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d2de + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d2e0 + uVar4) = (undefined *)&DAT_0000_6400;
  FUN_1000_bcf4();
  uVar10 = CONCAT11(0x80,uVar15);
  pbVar14 = (byte *)&DAT_0000_c800;
  iVar12 = 0x40;
  do {
    if ((((*pbVar14 & (byte)((uint)uVar10 >> 8)) == 0) && ((byte)uVar10 == pbVar14[0xc])) &&
       ((pbVar14[10] & 0x20) != 0)) {
      pbVar14[10] = 1;
      uVar10 = FUN_1000_a9ca();
    }
    pbVar14 = pbVar14 + 0x10;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  FUN_1000_0d12(uVar10);
  FUN_1000_7c9e();
  FUN_1000_727a();
  FUN_1000_9520();
  FUN_1000_026a();
  *(undefined2 *)&DAT_0000_3be4 = uVar5;
  *(undefined2 *)&DAT_0000_3be2 = uVar11;
  FUN_1000_7c9e();
  FUN_1000_72ad();
  puVar13 = (uint *)0xc792;
  iVar12 = 4;
  iVar9 = 0;
  do {
    if ((*puVar13 & 8) != 0) {
      iVar9 = iVar9 + 1;
    }
    puVar13 = puVar13 + 0xb;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  if (iVar9 == 2) {
    puVar13 = (uint *)0xc792;
    iVar12 = 4;
    do {
      if ((*puVar13 & 8) == 0) break;
      puVar13 = puVar13 + 0xb;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    LOCK();
    bVar3 = (byte)puVar13[10];
    *(byte *)(puVar13 + 10) = 0x80;
    UNLOCK();
    if (bVar3 < 4) {
      iVar12 = (uint)bVar3 * 2;
      *(undefined2 *)0xc530 = *(undefined2 *)((undefined *)&DAT_0000_12ad + iVar12);
      LOCK();
      pbVar2 = (byte *)(*(int *)((undefined *)&DAT_0000_12ef + iVar12) + 0x14);
      bVar3 = *pbVar2;
      *pbVar2 = 0x80;
      UNLOCK();
      *(undefined2 *)0xc52e = *(undefined2 *)((undefined *)&DAT_0000_12ad + (uint)bVar3 * 2);
      FUN_1000_7c9e();
      FUN_1000_4a4d();
      uVar11 = FUN_1000_72ad();
      FUN_1000_0d12(uVar11);
      FUN_1000_c921();
    }
  }
LAB_1000_b28a:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:b28d  FUN_1000_b28d  101 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_b28d(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  undefined2 in_DX;
  undefined2 unaff_DS;
  byte bVar2;
  uint uVar3;
  
  if (*(byte *)0x3c00 < 4) {
    bVar2 = 0;
    if ((**(uint **)((undefined *)&DAT_0000_12ef + (uint)*(byte *)0x3c00 * 2) & 8) != 0) {
      FUN_1000_0ccc();
      *(undefined2 *)&DAT_0000_3bc6 = 2;
      FUN_1000_5f7e();
      FUN_1000_0ceb();
      FUN_1000_7c9e();
      FUN_1000_93c5();
      FUN_1000_4a4d();
      FUN_1000_0d0a();
      uVar1 = FUN_1000_72ad();
      FUN_1000_0d12(uVar1);
      FUN_1000_c90f();
      *(undefined2 *)0x3bd6 = 0xffff;
      *(undefined2 *)0x346e = 0xffff;
      FUN_1000_6033();
      uVar3 = (uint)(bVar2 & 1);
      FUN_1000_c5f4();
      if ((uVar3 & 1) == 0) {
        FUN_1000_04b8();
      }
      return CONCAT22(in_DX,in_AX);
    }
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:b2f2  FUN_1000_b2f2  418 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_b2f2(void)

{
  uint uVar1;
  undefined2 in_AX;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined2 in_DX;
  int iVar6;
  uint *puVar7;
  undefined2 unaff_DS;
  bool bVar8;
  char cVar9;
  
  bVar8 = false;
  puVar7 = (uint *)0xc792;
  iVar6 = 0;
  iVar5 = 4;
  do {
    if ((*puVar7 & 0xc) == 0xc) {
      iVar6 = iVar6 + 1;
    }
    puVar7 = puVar7 + 0xb;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (iVar6 != 3) {
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_0ccc();
  *(undefined2 *)&DAT_0000_3bc6 = 1;
  FUN_1000_5f7e();
  FUN_1000_0ceb();
  puVar7 = (uint *)0xc792;
  iVar5 = 4;
  do {
    if ((*puVar7 & 8) == 0) break;
    puVar7 = puVar7 + 0xb;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = 4 - iVar5;
  *(undefined2 *)0xc538 = *(undefined2 *)((undefined *)&DAT_0000_12ad + iVar5 * 2);
  uVar2 = FUN_1000_bc99();
  cVar9 = (char)iVar5;
  *(uint *)0xc53e = uVar2;
  if (uVar2 == 0) {
    *(undefined2 *)0xc53a = 0;
    uVar2 = 0;
    uVar4 = 0;
  }
  else {
    uVar3 = FUN_1000_bcce();
    *(uint *)0xc53a = uVar3;
    uVar2 = (uint)(((ulong)uVar3 * 1000) / (ulong)uVar2);
    uVar4 = CONCAT11((char)(uVar2 % 10),(char)(uVar2 / 10));
  }
  *(undefined2 *)0xc53c = uVar4;
  uVar2 = (uint)(((ulong)*(uint *)0x3bca * (ulong)uVar2) / 1000);
  *(uint *)0xc4f0 = uVar2;
  if ((cVar9 == *(char *)0x3c00) && (uVar3 = *(uint *)0x3bc2, uVar3 < 0x34)) {
    *(undefined2 *)0xc540 = 0;
    iVar5 = 0;
    iVar6 = uVar3 * 0xc;
    if (iVar6 != 0) {
      iVar5 = *(int *)((undefined *)&DAT_0000_cbfa + iVar6);
    }
    iVar5 = uVar2 - iVar5;
    if (iVar5 < 0) {
      *(undefined2 *)0xc540 = 1;
      iVar5 = -iVar5;
    }
    *(int *)0xc542 = iVar5;
    *(int *)0xc544 = *(int *)0xc4f0 - *(int *)((undefined *)&DAT_0000_cc06 + iVar6);
    if ((*(uint *)((undefined *)&DAT_0000_cc06 + iVar6) < uVar2) && (*(int *)0xc4f0 != 0)) {
      uVar2 = *(uint *)0x3bc2;
      uVar1 = *(uint *)0xce70;
      if (uVar1 <= uVar2) {
        *(int *)0xce70 = *(int *)0xce70 + 1;
      }
      bVar8 = uVar1 > uVar2;
      ((undefined2 *)&DAT_0000_cc00)[uVar3 * 6] = *(undefined2 *)0x3bcc;
      *(undefined2 *)((undefined *)&DAT_0000_cc04 + iVar6) = *(undefined2 *)0x3bca;
      ((undefined2 *)&DAT_0000_cc02)[uVar3 * 6] = *(undefined2 *)0xc53c;
      FUN_1000_acbb();
    }
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    if (bVar8) {
      FUN_1000_4a4d();
    }
    FUN_1000_0d0a();
    uVar4 = FUN_1000_72ad();
    FUN_1000_0d12(uVar4);
    FUN_1000_c90f();
    *(undefined2 *)0x3bd6 = 0xffff;
    if (*(int *)0x3bc2 == 0x33) {
      *(undefined2 *)0xce70 = 0x33;
      FUN_1000_b661();
      FUN_1000_ca4a();
    }
    else {
      FUN_1000_b58f();
      bVar8 = *(int *)0x3bc2 + 1U < *(uint *)0xce70;
      if ((*(int *)0x3bc2 + 1U == *(uint *)0xce70) && (FUN_1000_6315(), !bVar8)) {
        FUN_1000_c5f4();
        FUN_1000_04b8();
      }
    }
  }
  else {
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    FUN_1000_0d0a();
    uVar4 = FUN_1000_72ad();
    FUN_1000_0d12(uVar4);
    FUN_1000_c90f();
    *(undefined2 *)0x3bd6 = 0xffff;
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:b494  FUN_1000_b494  20 bytes, 1 callers */

void __cdecl16near FUN_1000_b494(void)

{
  byte in_AL;
  
  if (((in_AL < 0x60) || (0x6f < in_AL)) && ((in_AL < 5 || (5 < in_AL)))) {
    return;
  }
  return;
}



/* 1000:b4a8  FUN_1000_b4a8  28 bytes, 1 callers */

void __cdecl16near FUN_1000_b4a8(void)

{
  byte in_AL;
  
  if ((((in_AL < 0x30) || (0x5f < in_AL)) && ((in_AL < 0x20 || (0x2f < in_AL)))) &&
     ((in_AL < 0x7a || (0x7a < in_AL)))) {
    return;
  }
  return;
}



/* 1000:b4c4  FUN_1000_b4c4  20 bytes, 1 callers */

void __cdecl16near FUN_1000_b4c4(void)

{
  byte in_AL;
  
  if (((in_AL < 0x30) || (0x5f < in_AL)) && ((in_AL < 0x60 || (0x6f < in_AL)))) {
    return;
  }
  return;
}



/* 1000:b4d8  FUN_1000_b4d8  49 bytes, 4 callers */

void __cdecl16near FUN_1000_b4d8(void)

{
  uint uVar1;
  uint in_AX;
  uint in_DX;
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)(*(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_SI[0xc] * 2) + 0x10);
  if ((uVar1 < in_DX ||
       uVar1 - in_DX <
       (uint)(*(uint *)(*(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_SI[0xc] * 2) + 0xe) <
             in_AX)) && (*(byte *)0x3c00 == unaff_SI[0xc])) {
    *(undefined2 *)0xc52c = 0xffff;
    *unaff_SI = *unaff_SI | 1;
  }
  return;
}



/* 1000:b58f  FUN_1000_b58f  210 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_b58f(void)

{
  code *pcVar1;
  byte bVar2;
  byte bVar3;
  undefined2 in_AX;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined2 in_DX;
  undefined2 *puVar7;
  undefined2 unaff_DS;
  undefined1 uVar8;
  
  iVar6 = *(int *)0xce70 + 1;
  uVar4 = 0;
  puVar7 = (undefined2 *)&DAT_0000_cc00;
  do {
    if (uVar4 < (uint)puVar7[3]) {
      uVar4 = puVar7[3];
    }
    puVar7 = puVar7 + 6;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_1000_c492();
  if ((byte)((char *)s_0000000000_0000_32b0)[5] < 0x31) {
    bVar2 = ((char *)s_0000000000_0000_32b0)[6] - 0x30;
  }
  else {
    bVar2 = ((char *)s_0000000000_0000_32b0)[5] - 0x27;
  }
  if (*(uint *)0xce72 < (uint)bVar2) {
    FUN_1000_0ccc();
    *(undefined2 *)&DAT_0000_3bc6 = 3;
    FUN_1000_5f7e();
    FUN_1000_0ceb();
    *(int *)0xce72 = *(int *)0xce72 + 1;
    iVar6 = 0x3e70;
    pcVar1 = (code *)swi(0x1c);
    (*pcVar1)();
    bVar2 = FUN_1000_6fc4();
    bVar3 = bVar2 + 0xa8;
    if (bVar2 < 0x58) {
      bVar3 = bVar2 + 0xc;
    }
    uVar4 = (uint)bVar3;
    if (0x1f < uVar4) {
      uVar4 = 0x20;
    }
    *(uint *)0xc54e = uVar4;
    uVar8 = (*(byte *)(iVar6 + 1) >> 3 & 1) != 0;
    uVar5 = FUN_1000_6fc4();
    *(undefined2 *)0xc550 = uVar5;
    uVar5 = FUN_1000_6fc4();
    *(undefined2 *)0xc552 = uVar5;
    FUN_1000_7c9e();
    FUN_1000_5e57();
    if ((bool)uVar8) {
      FUN_1000_4a4d();
      FUN_1000_8738();
    }
    else {
      FUN_1000_4a81();
      *(undefined2 *)0x32a8 = 0xf;
      FUN_1000_4ae5();
      *(undefined2 *)0x32a8 = 0x70f;
      FUN_1000_8738();
    }
    FUN_1000_0d0a();
    FUN_1000_72ad();
    FUN_1000_c90f();
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:b661  FUN_1000_b661  200 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_b661(undefined2 param_1)

{
  code *pcVar1;
  byte bVar2;
  byte bVar3;
  undefined2 in_AX;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined2 unaff_DS;
  undefined1 uVar8;
  
  iVar6 = *(int *)0xce70 + 1;
  uVar4 = 0;
  puVar7 = (undefined2 *)&DAT_0000_cc00;
  do {
    if (uVar4 < (uint)puVar7[3]) {
      uVar4 = puVar7[3];
    }
    puVar7 = puVar7 + 6;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_1000_c492();
  if ((byte)((char *)s_0000000000_0000_32b0)[5] < 0x31) {
    bVar2 = ((char *)s_0000000000_0000_32b0)[6] - 0x30;
  }
  else {
    bVar2 = ((char *)s_0000000000_0000_32b0)[5] - 0x27;
  }
  *(uint *)0xce72 = (uint)bVar2;
  FUN_1000_0ccc();
  *(undefined2 *)&DAT_0000_3bc6 = 3;
  FUN_1000_5f7e();
  FUN_1000_0ceb();
  iVar6 = 0x3e70;
  pcVar1 = (code *)swi(0x1c);
  (*pcVar1)();
  bVar2 = FUN_1000_6fc4();
  bVar3 = bVar2 + 0xa8;
  if (bVar2 < 0x58) {
    bVar3 = bVar2 + 0xc;
  }
  uVar4 = (uint)bVar3;
  if (0x1f < uVar4) {
    uVar4 = 0x20;
  }
  *(uint *)0xc54e = uVar4;
  uVar8 = (*(byte *)(iVar6 + 1) >> 3 & 1) != 0;
  uVar5 = FUN_1000_6fc4();
  *(undefined2 *)0xc550 = uVar5;
  uVar5 = FUN_1000_6fc4();
  *(undefined2 *)0xc552 = uVar5;
  FUN_1000_7c9e();
  FUN_1000_5e57();
  if ((bool)uVar8) {
    FUN_1000_4a4d();
    FUN_1000_8738();
  }
  else {
    FUN_1000_4a81();
    *(undefined2 *)0x32a8 = 0xf;
    FUN_1000_4ae5();
    *(undefined2 *)0x32a8 = 0x70f;
    FUN_1000_8738();
  }
  FUN_1000_0d0a();
  FUN_1000_72ad();
  FUN_1000_c90f();
  return CONCAT22(in_AX,param_1);
}



/* 1000:b729  FUN_1000_b729  98 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_b729(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  int iVar3;
  undefined2 in_DX;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 unaff_DS;
  
  puVar4 = (undefined2 *)0x0;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = 0xffff;
  }
  iVar2 = 0x17;
  do {
    *puVar4 = 0xffff;
    for (iVar3 = 0x2e; puVar5 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0x4000;
      puVar4 = puVar5;
    }
    *puVar5 = 0xffff;
    puVar4[2] = 0xffff;
    iVar3 = 0x17;
    puVar4 = puVar4 + 3;
    do {
      puVar5 = puVar4;
      *puVar5 = 0x4000;
      puVar5[1] = 0xffff;
      iVar3 = iVar3 + -1;
      puVar4 = puVar5 + 2;
    } while (iVar3 != 0);
    puVar4 = puVar5 + 3;
    puVar5[2] = 0xffff;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = 0xffff;
  }
  do {
  } while (*(int *)0x32da == *(int *)0x32da);
  iVar2 = *(int *)0x32da;
  FUN_1000_be36();
  iVar3 = 3 - (iVar2 - *(int *)0x32da);
  if (3 < (uint)(iVar2 - *(int *)0x32da)) {
    iVar3 = 0;
  }
  *(int *)0x3c1e = iVar3 + 1;
  return CONCAT22(in_DX,in_AX);
}



/* 1000:b78c  FUN_1000_b78c  14 bytes, 17 callers */

uint __cdecl16near FUN_1000_b78c(void)

{
  int unaff_SI;
  
  return unaff_SI + 0x3800U >> 4;
}



/* 1000:b7cf  FUN_1000_b7cf  167 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_b7cf(void)

{
  char cVar1;
  undefined2 in_AX;
  int unaff_DI;
  undefined2 unaff_DS;
  
  cVar1 = (char)in_AX + '\f';
  if (((((((((undefined *)&DAT_0000_d21e)[unaff_DI] == cVar1) ||
          (3 < (byte)(((undefined *)&DAT_0000_d21e)[unaff_DI] - 0xc))) &&
         ((((undefined *)&DAT_0000_d2de)[unaff_DI] == cVar1 ||
          (3 < (byte)(((undefined *)&DAT_0000_d2de)[unaff_DI] - 0xc))))) &&
        ((((undefined *)&DAT_0000_d27c)[unaff_DI] == cVar1 ||
         (3 < (byte)(((undefined *)&DAT_0000_d27c)[unaff_DI] - 0xc))))) &&
       ((((undefined *)&DAT_0000_d280)[unaff_DI] == cVar1 ||
        (3 < (byte)(((undefined *)&DAT_0000_d280)[unaff_DI] - 0xc))))) &&
      ((((((undefined *)&DAT_0000_d21c)[unaff_DI] == cVar1 ||
         (3 < (byte)(((undefined *)&DAT_0000_d21c)[unaff_DI] - 0xc))) &&
        ((((undefined *)&DAT_0000_d220)[unaff_DI] == cVar1 ||
         (3 < (byte)(((undefined *)&DAT_0000_d220)[unaff_DI] - 0xc))))) &&
       ((((undefined *)&DAT_0000_d2dc)[unaff_DI] == cVar1 ||
        (3 < (byte)(((undefined *)&DAT_0000_d2dc)[unaff_DI] - 0xc))))))) &&
     ((((undefined *)&DAT_0000_d2e0)[unaff_DI] == cVar1 ||
      (3 < (byte)(((undefined *)&DAT_0000_d2e0)[unaff_DI] - 0xc))))) {
    return in_AX;
  }
  return in_AX;
}



/* 1000:b876  FUN_1000_b876  305 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_b876(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  byte bVar4;
  undefined2 uVar5;
  byte bVar6;
  undefined2 in_CX;
  int iVar7;
  undefined1 uVar9;
  undefined2 uVar8;
  undefined2 in_BX;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *unaff_SI;
  uint *puVar14;
  undefined2 unaff_DS;
  bool bVar15;
  undefined4 uVar16;
  
  bVar15 = false;
  FUN_1000_b4d8();
  if (!bVar15) {
    uVar5 = FUN_1000_a61d(in_BX,in_CX);
    puVar14 = (uint *)0x0;
    uVar10 = 0x200;
    iVar7 = 0x900;
    uVar3 = CONCAT22(0x2000,CONCAT11((char)((uint)uVar5 >> 8) + '\b',(char)uVar5 + '\b'));
    do {
      uVar5 = (undefined2)uVar3;
      uVar11 = *puVar14;
      uVar9 = (undefined1)((ulong)uVar3 >> 0x18);
      uVar16 = CONCAT22(CONCAT11(uVar9,(char)puVar14[-0x16c1]),uVar5);
      uVar2 = uVar16;
      if ((char)puVar14[-0x16c1] == '\x05') {
        if (uVar11 < uVar10) goto LAB_1000_b8f2;
      }
      else {
        uVar12 = uVar11 + 8;
        if ((uVar11 < 0xfff8) && (uVar12 < uVar10)) {
          bVar4 = (byte)puVar14[-0x16c1];
          uVar8 = CONCAT11(uVar9,bVar4);
          uVar16 = CONCAT22(uVar8,uVar5);
          uVar2 = CONCAT22(uVar8,uVar5);
          if ((bVar4 != (byte)uVar3) &&
             (uVar2 = CONCAT22(uVar8,uVar5), bVar4 != (byte)((ulong)uVar3 >> 8))) {
            bVar15 = false;
            uVar11 = uVar12;
            if ((bVar4 == 0) || ((0xb < bVar4 && (bVar15 = true, bVar4 < 0x10)))) {
              uVar16 = FUN_1000_ae9e();
              uVar2 = uVar16;
              if (bVar15) goto LAB_1000_b8f6;
            }
            else if ((bVar4 == 0) || (4 < bVar4)) {
              uVar8 = CONCAT11(uVar9,bVar4 - 8);
              uVar16 = CONCAT22(uVar8,uVar5);
              uVar2 = CONCAT22(uVar8,uVar5);
              if (3 < (byte)(bVar4 - 8)) goto LAB_1000_b8f6;
            }
LAB_1000_b8f2:
            uVar10 = uVar11;
            unaff_SI = puVar14;
            uVar2 = uVar16;
          }
        }
      }
LAB_1000_b8f6:
      puVar14 = puVar14 + 1;
      iVar7 = iVar7 + -1;
      uVar3 = uVar2;
      if (iVar7 == 0) {
        uVar11 = uVar10 - 8;
        if (uVar10 < 8) {
          uVar11 = 0;
        }
        else if (0x1ef < uVar11) {
          return uVar2;
        }
        return CONCAT22(CONCAT11((char)(((uint)unaff_SI >> 1) / 0x30),
                                 (char)(((uint)unaff_SI >> 1) % 0x30)),uVar11);
      }
    } while( true );
  }
  uVar5 = FUN_1000_a61d(in_BX,in_CX);
  bVar6 = (char)((uint)uVar5 >> 8) + 8;
  bVar4 = (char)uVar5 + 8;
  uVar10 = CONCAT11(bVar6,bVar4);
  uVar5 = 0x2000;
  puVar14 = (uint *)0x0;
  uVar11 = 0x1f9;
  iVar7 = 0x900;
  do {
    uVar12 = *puVar14;
    uVar9 = (undefined1)((uint)uVar5 >> 8);
    uVar5 = CONCAT11(uVar9,(char)puVar14[-0x16c1]);
    if ((char)puVar14[-0x16c1] == '\x05') {
      if (uVar12 < uVar11) {
LAB_1000_b977:
        uVar11 = uVar12;
        unaff_SI = puVar14;
      }
    }
    else {
      uVar13 = uVar12 + 8;
      if ((uVar12 < 0xfff8) && (uVar13 < uVar11)) {
        bVar1 = (byte)puVar14[-0x16c1];
        uVar5 = CONCAT11(uVar9,bVar1);
        if (((bVar1 != bVar4) && (bVar1 != bVar6)) &&
           (((uVar12 = uVar13, bVar1 != 0 && (bVar1 < 5)) ||
            (uVar5 = CONCAT11(uVar9,bVar1 - 8), (byte)(bVar1 - 8) < 4)))) goto LAB_1000_b977;
      }
    }
    puVar14 = puVar14 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if (uVar11 < 8) {
    uVar12 = 0;
  }
  else {
    uVar12 = uVar11 - 8;
    if (0x1ef < uVar11 - 8) goto LAB_1000_b9a1;
  }
  uVar10 = uVar12;
  uVar5 = CONCAT11((char)(((uint)unaff_SI >> 1) / 0x30),(char)(((uint)unaff_SI >> 1) % 0x30));
LAB_1000_b9a1:
  return CONCAT22(uVar5,uVar10);
}



/* 1000:b9a7  FUN_1000_b9a7  107 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_b9a7(void)

{
  uint uVar1;
  undefined2 in_AX;
  undefined2 in_CX;
  int iVar2;
  undefined2 in_DX;
  undefined2 in_BX;
  uint uVar3;
  uint *unaff_SI;
  uint *puVar4;
  undefined2 unaff_DS;
  bool bVar5;
  
  bVar5 = false;
  FUN_1000_b4d8();
  if (bVar5) {
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_a61d(in_BX,in_CX);
  puVar4 = (uint *)0x0;
  uVar3 = 0x1f1;
  iVar2 = 0x900;
  do {
    uVar1 = *puVar4;
    if (uVar1 < uVar3) {
      bVar5 = false;
      if (((char)puVar4[-0x16c1] == '\0') ||
         (bVar5 = true, (byte)((char)puVar4[-0x16c1] - 0xcU) < 4)) {
        FUN_1000_ae9e();
        if (!bVar5) {
          uVar3 = uVar1;
          unaff_SI = puVar4;
        }
      }
    }
    puVar4 = puVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(CONCAT11((char)(((uint)unaff_SI >> 1) / 0x30),(char)(((uint)unaff_SI >> 1) % 0x30)
                          ),uVar3);
}



/* 1000:ba12  FUN_1000_ba12  85 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_ba12(void)

{
  undefined2 uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint *unaff_SI;
  uint *puVar5;
  undefined2 unaff_DS;
  
  uVar1 = FUN_1000_a61d();
  puVar5 = (uint *)0x0;
  uVar4 = 0x1f1;
  iVar2 = 0x900;
  do {
    if ((((*puVar5 < uVar4) && (bVar3 = (char)puVar5[-0x16c1] - 8, bVar3 < 4)) &&
        (bVar3 != (byte)uVar1)) && (bVar3 != (byte)((uint)uVar1 >> 8))) {
      uVar4 = *puVar5;
      unaff_SI = puVar5;
    }
    puVar5 = puVar5 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(CONCAT11((char)(((uint)unaff_SI >> 1) / 0x30),(char)(((uint)unaff_SI >> 1) % 0x30)
                          ),uVar4);
}



/* 1000:ba67  FUN_1000_ba67  72 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_ba67(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  undefined2 unaff_DS;
  
  puVar2 = (uint *)0x2000;
  puVar4 = (uint *)0x0;
  uVar3 = 0x1f1;
  iVar1 = 0x900;
  do {
    if ((*puVar4 < uVar3) && ((byte)((char)puVar4[-0x16c1] - 1U) < 4)) {
      puVar2 = puVar4;
      uVar3 = *puVar4;
    }
    puVar4 = puVar4 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return CONCAT22(CONCAT11((char)(((uint)puVar2 >> 1) / 0x30),(char)(((uint)puVar2 >> 1) % 0x30)),
                  uVar3);
}



/* 1000:baaf  FUN_1000_baaf  125 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_baaf(void)

{
  int iVar1;
  uint uVar2;
  undefined2 in_BX;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_DS;
  
  uVar2 = 0x2000;
  uVar3 = 0;
  uVar4 = 0x1f1;
  iVar1 = 0x900;
  do {
    if (((undefined *)&DAT_0000_d27e)[uVar3] == '{') {
      if (*(uint *)((undefined *)&DAT_0000_ffa0 + uVar3) < uVar4) {
        in_BX = 0xff00;
        uVar2 = uVar3;
        uVar4 = *(uint *)((undefined *)&DAT_0000_ffa0 + uVar3);
      }
      if (*(uint *)(uVar3 - 2) < uVar4) {
        in_BX = 0xff;
        uVar2 = uVar3;
        uVar4 = *(uint *)(uVar3 - 2);
      }
      if (*(uint *)(uVar3 + 2) < uVar4) {
        in_BX = 1;
        uVar2 = uVar3;
        uVar4 = *(uint *)(uVar3 + 2);
      }
      if (*(uint *)(uVar3 + 0x60) < uVar4) {
        in_BX = 0x100;
        uVar2 = uVar3;
        uVar4 = *(uint *)(uVar3 + 0x60);
      }
    }
    uVar3 = uVar3 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return CONCAT22(CONCAT11((char)((uVar2 >> 1) / 0x30) + (char)((uint)in_BX >> 8),
                           (char)((uVar2 >> 1) % 0x30) + (char)in_BX),uVar4);
}



/* 1000:bb2c  FUN_1000_bb2c  68 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_bb2c(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  undefined2 unaff_DS;
  
  puVar2 = (uint *)0x2000;
  puVar4 = (uint *)0x0;
  uVar3 = 0x1f1;
  iVar1 = 0x900;
  do {
    if (((char)puVar4[-0x16c1] == '\x05') && (*puVar4 < uVar3)) {
      puVar2 = puVar4;
      uVar3 = *puVar4;
    }
    puVar4 = puVar4 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return CONCAT22(CONCAT11((char)(((uint)puVar2 >> 1) / 0x30),(char)(((uint)puVar2 >> 1) % 0x30)),
                  uVar3);
}



/* 1000:bb70  FUN_1000_bb70  125 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_bb70(void)

{
  int iVar1;
  uint uVar2;
  undefined2 in_BX;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_DS;
  
  uVar2 = 0x2000;
  uVar3 = 0;
  uVar4 = 0x1f1;
  iVar1 = 0x900;
  do {
    if (((undefined *)&DAT_0000_d27e)[uVar3] == 'z') {
      if (*(uint *)((undefined *)&DAT_0000_ffa0 + uVar3) < uVar4) {
        in_BX = 0xff00;
        uVar2 = uVar3;
        uVar4 = *(uint *)((undefined *)&DAT_0000_ffa0 + uVar3);
      }
      if (*(uint *)(uVar3 - 2) < uVar4) {
        in_BX = 0xff;
        uVar2 = uVar3;
        uVar4 = *(uint *)(uVar3 - 2);
      }
      if (*(uint *)(uVar3 + 2) < uVar4) {
        in_BX = 1;
        uVar2 = uVar3;
        uVar4 = *(uint *)(uVar3 + 2);
      }
      if (*(uint *)(uVar3 + 0x60) < uVar4) {
        in_BX = 0x100;
        uVar2 = uVar3;
        uVar4 = *(uint *)(uVar3 + 0x60);
      }
    }
    uVar3 = uVar3 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return CONCAT22(CONCAT11((char)((uVar2 >> 1) / 0x30) + (char)((uint)in_BX >> 8),
                           (char)((uVar2 >> 1) % 0x30) + (char)in_BX),uVar4);
}



/* 1000:bbed  FUN_1000_bbed  105 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_bbed(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte extraout_AL;
  uint in_AX;
  byte bVar4;
  byte extraout_AH;
  int iVar5;
  undefined2 in_DX;
  uint *in_BX;
  uint uVar6;
  byte *unaff_SI;
  byte *pbVar7;
  undefined2 unaff_DS;
  undefined2 local_8;
  uint local_4;
  
  pbVar7 = (byte *)&DAT_0000_c800;
  bVar3 = (byte)in_AX;
  bVar4 = 0x80;
  iVar5 = 0x40;
  uVar6 = 0x1f1;
  uVar1 = *(uint *)(unaff_SI + 6);
  do {
    if (((((*pbVar7 & bVar4) == 0) && (bVar3 == pbVar7[0xc])) &&
        (in_BX = (uint *)(CONCAT11((char)((uint)in_BX >> 8),pbVar7[10]) & 0xff0f),
        (char)in_BX == '\x02')) &&
       ((uVar1 <= *(uint *)(pbVar7 + 6) && (!CARRY2(uVar1,*(uint *)(pbVar7 + 6)))))) {
      FUN_1000_9b34();
      uVar2 = *in_BX;
      bVar3 = extraout_AL;
      bVar4 = extraout_AH;
      if ((uVar2 != 1) && (uVar2 <= uVar6)) {
        uVar6 = uVar2;
        unaff_SI = pbVar7;
      }
    }
    pbVar7 = pbVar7 + 0x10;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  local_8 = in_DX;
  local_4 = in_AX;
  if (uVar6 < 0x1f0) {
    local_8 = *(undefined2 *)(unaff_SI + 8);
    local_4 = uVar6;
  }
  return CONCAT22(local_8,local_4);
}



/* 1000:bc56  FUN_1000_bc56  67 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_bc56(void)

{
  char in_AL;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  undefined2 unaff_DS;
  
  puVar2 = (uint *)0x2000;
  puVar4 = (uint *)0x0;
  uVar3 = 0x1f1;
  iVar1 = 0x900;
  do {
    if (((char)(in_AL + '\b') == (char)puVar4[-0x16c1]) && (*puVar4 <= uVar3)) {
      uVar3 = *puVar4;
      puVar2 = puVar4;
    }
    puVar4 = puVar4 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return CONCAT22(CONCAT11((char)(((uint)puVar2 >> 1) / 0x30),(char)(((uint)puVar2 >> 1) % 0x30)),
                  uVar3);
}



/* 1000:bc99  FUN_1000_bc99  53 bytes, 1 callers */

int __cdecl16near FUN_1000_bc99(void)

{
  undefined2 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined2 unaff_DS;
  
  puVar5 = (undefined2 *)&DAT_0000_d27e;
  iVar4 = 0;
  iVar3 = 0x900;
  do {
    puVar1 = puVar5;
    puVar5 = puVar5 + 1;
    cVar2 = (char)*puVar1;
    if ((((cVar2 == '\0') || (cVar2 == '{')) || ((byte)(cVar2 - 8U) < 4)) ||
       (((byte)(cVar2 - 0xcU) < 4 || ((byte)(cVar2 - 1U) < 4)))) {
      iVar4 = iVar4 + 1;
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar4;
}



/* 1000:bcce  FUN_1000_bcce  38 bytes, 1 callers */

int __cdecl16near FUN_1000_bcce(void)

{
  char in_AL;
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined2 unaff_DS;
  
  pcVar3 = (char *)&DAT_0000_d27e;
  iVar2 = 0;
  iVar1 = 0x900;
  do {
    if (((char)(in_AL + '\f') == *pcVar3) || ((char)(in_AL + '\b') == *pcVar3)) {
      iVar2 = iVar2 + 1;
    }
    pcVar3 = pcVar3 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return iVar2;
}



/* 1000:bcf4  FUN_1000_bcf4  42 bytes, 8 callers */

undefined4 __cdecl16near FUN_1000_bcf4(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined2 in_DX;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 unaff_DS;
  
  puVar6 = (undefined2 *)0x1200;
  puVar5 = (undefined2 *)&DAT_0000_d27e;
  iVar3 = 0x30;
  do {
    iVar4 = 0x30;
    do {
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      uVar2 = 0x4000;
      if (0x2f < (byte)*puVar1) {
        uVar2 = 0xffff;
      }
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar1 = uVar2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:bd1e  FUN_1000_bd1e  29 bytes, 4 callers */

void __cdecl16near FUN_1000_bd1e(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  puVar5 = (undefined2 *)0x0;
  puVar4 = (undefined2 *)0x1200;
  for (iVar3 = 0x900; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar2 = *puVar1;
  }
  return;
}



/* 1000:bd3b  FUN_1000_bd3b  73 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_bd3b(void)

{
  uint uVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  byte *unaff_SI;
  byte *pbVar3;
  undefined2 unaff_DS;
  undefined4 uVar4;
  
  pbVar3 = (byte *)&DAT_0000_c800;
  iVar2 = 0x40;
  uVar4 = FUN_1000_a61d();
  uVar1 = *(uint *)(unaff_SI + 6);
  do {
    if (((((*pbVar3 & (byte)((ulong)uVar4 >> 0x18)) == 0) && (unaff_SI != pbVar3)) &&
        ((byte)((ulong)uVar4 >> 0x10) == pbVar3[0xb])) &&
       (((byte)((ulong)uVar4 >> 8) == pbVar3[0xc] ||
        (((byte)uVar4 == pbVar3[0xc] && (CARRY2(*(uint *)(pbVar3 + 6),uVar1))))))) {
      **(undefined2 **)(pbVar3 + 4) = 0xffff;
    }
    pbVar3 = pbVar3 + 0x10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:bd84  FUN_1000_bd84  127 bytes, 3 callers */

undefined4 __cdecl16near FUN_1000_bd84(void)

{
  uint uVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int iVar3;
  undefined2 in_DX;
  byte *unaff_SI;
  byte *pbVar4;
  undefined2 unaff_DS;
  undefined4 uVar5;
  
  pbVar4 = (byte *)&DAT_0000_c800;
  iVar3 = 0x40;
  uVar5 = FUN_1000_a61d();
  uVar1 = *(uint *)(unaff_SI + 6);
  do {
    if ((((*pbVar4 & (byte)((ulong)uVar5 >> 0x18)) == 0) && (unaff_SI != pbVar4)) &&
       ((byte)((ulong)uVar5 >> 0x10) == pbVar4[0xb])) {
      if ((byte)((ulong)uVar5 >> 8) == pbVar4[0xc]) {
LAB_1000_bdbb:
        **(undefined2 **)(pbVar4 + 4) = 0xffff;
      }
      else if ((byte)uVar5 == pbVar4[0xc]) {
        if (CARRY2(*(uint *)(pbVar4 + 6),uVar1)) goto LAB_1000_bdbb;
      }
      else if ((CARRY2(*(uint *)(pbVar4 + 6) >> 1,*(uint *)(pbVar4 + 6))) ||
              (uVar1 <= (*(uint *)(pbVar4 + 6) >> 1) + *(uint *)(pbVar4 + 6))) {
        puVar2 = *(undefined2 **)(pbVar4 + 4);
        *puVar2 = 0xffff;
        puVar2[-0x30] = 0xffff;
        puVar2[0x30] = 0xffff;
        puVar2[-1] = 0xffff;
        puVar2[1] = 0xffff;
      }
    }
    pbVar4 = pbVar4 + 0x10;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return CONCAT22(in_DX,in_AX);
    }
  } while( true );
}



/* 1000:be03  FUN_1000_be03  51 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_be03(void)

{
  byte bVar1;
  uint in_AX;
  uint uVar2;
  int iVar4;
  undefined2 in_DX;
  undefined2 *puVar5;
  undefined2 unaff_DS;
  byte bVar3;
  
  puVar5 = (undefined2 *)0x0;
  iVar4 = 0x900;
  uVar2 = in_AX;
  do {
    bVar1 = (byte)uVar2;
    bVar3 = *(char *)(puVar5 + -0x16c1) - 8;
    uVar2 = CONCAT11(bVar3,bVar1);
    if ((bVar3 < 8) && (uVar2 = CONCAT11(bVar3,bVar1) & 0x3ff, bVar1 != (bVar3 & 3))) {
      *puVar5 = 0xffff;
    }
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:be36  FUN_1000_be36  267 bytes, 5 callers */

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl16near FUN_1000_be36(void)

{
  byte bVar1;
  uint in_CX;
  undefined1 extraout_DL;
  uint in_DX;
  char cVar3;
  undefined2 uVar2;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 extraout_DX_01;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  uint *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar11;
  
  *(undefined2 *)0x32bb = 0xffff;
  *(undefined1 **)0xc4ec = &stack0xffec;
  *(undefined2 *)&DAT_0000_c4ea = unaff_SS;
  puVar9 = (undefined1 *)0x0;
  uVar10 = (in_DX >> 8) * 0x60;
  iVar5 = (in_DX & 0xff) * 2;
  piRam0002fffe = (int *)((undefined *)&DAT_0000_ffa0 + uVar10 + iVar5);
  bVar11 = true;
  LOCK();
  iRam0002fffc = *piRam0002fffe;
  *piRam0002fffe = 0;
  UNLOCK();
  uRam0002fffa = 0xbe78;
  FUN_1000_bf41();
  *piRam0002fffe = iRam0002fffc;
  if (!bVar11) {
    in_CX = in_CX & 0xff;
    piRam0002fffe = (int *)0xbe86;
    FUN_1000_c050();
    cVar3 = (char)in_CX + (char)(in_CX >> 8);
    piRam0002fffe = (int *)CONCAT11(cVar3,extraout_DL);
    uVar2 = CONCAT11(cVar3,0xa0);
    puVar8 = (undefined1 *)0xfffa;
    uRam0002fffa = uVar10;
    iRam0002fffc = iVar5;
LAB_1000_be8f:
    do {
      uVar10 = uVar10 + (int)(char)uVar2;
      if (((int)uVar10 < 0) || (bVar11 = uVar10 == 0x1200, 0x11ff < uVar10)) goto LAB_1000_bf1c;
      in_CX = CONCAT11((char)((uint)uVar2 >> 8),(char)in_CX);
      *(undefined2 *)(puVar8 + -2) = 0xbea4;
      FUN_1000_bf41();
      if (bVar11) goto LAB_1000_bf1c;
      uVar4 = in_CX >> 8;
      in_CX = in_CX & 0xff;
      uVar2 = extraout_DX;
      if ((char)((uint)extraout_DX >> 8) == (char)uVar4) {
        *(undefined2 *)(puVar8 + -2) = 0xbeaf;
        FUN_1000_c050();
        uVar2 = extraout_DX_00;
      }
      if (puVar8 < (undefined1 *)0x6040) break;
      bVar1 = (byte)(in_CX >> 8);
      *(uint *)(puVar8 + -2) = CONCAT11((char)in_CX + bVar1,(char)uVar2);
      *(int *)(puVar8 + -4) = iVar5;
      puVar6 = puVar8 + -6;
      *(uint *)(puVar8 + -6) = uVar10;
      if (bVar1 < 2) goto LAB_1000_bed4;
      if (puVar8 + -6 < (undefined1 *)0x6040) break;
      *(uint *)(puVar8 + -8) = CONCAT11(bVar1 - 1,-(char)uVar2);
      *(int *)(puVar8 + -10) = iVar5;
      puVar6 = puVar8 + -0xc;
      *(uint *)(puVar8 + -0xc) = uVar10;
LAB_1000_bed4:
      while( true ) {
        cVar3 = (char)((uint)uVar2 >> 8);
        bVar1 = ((char)in_CX - cVar3) + 1;
        puVar8 = puVar6;
        if (bVar1 < 3) break;
        if (-1 < (char)bVar1) {
          cVar3 = cVar3 + '\x01';
          iVar5 = _DAT_2000_4400 + cVar3 * 2;
          uVar2 = CONCAT11(-(cVar3 - (char)in_CX),-(char)uVar2);
          goto LAB_1000_be8f;
        }
        uVar4 = _DAT_2000_4402 + 2;
        bVar11 = uVar4 == 0x60;
        if (0x5f < uVar4) break;
        *(undefined2 *)(puVar6 + -2) = 0xbef5;
        FUN_1000_bf41();
        if (bVar11) break;
        if (puVar6 < (undefined1 *)0x6040) goto LAB_1000_bf2f;
        *(uint *)(puVar6 + -2) = CONCAT11((char)in_CX,(char)extraout_DX_01);
        *(uint *)(puVar6 + -4) = uVar4;
        puVar7 = (uint *)(puVar6 + -6);
        puVar6 = puVar6 + -6;
        *puVar7 = uVar10;
        uVar2 = extraout_DX_01;
      }
LAB_1000_bf1c:
      if (puVar8 == puVar9) break;
      uVar2 = *(undefined2 *)(puVar9 + -2);
      iVar5 = *(int *)(puVar9 + -4);
      uVar10 = *(uint *)(puVar9 + -6);
      puVar9 = puVar9 + -6;
    } while( true );
  }
LAB_1000_bf2f:
  return CONCAT22(*(undefined2 *)(DAT_0000_c4ec + 10),*(undefined2 *)(DAT_0000_c4ec + 0xe));
}



/* 1000:bf41  FUN_1000_bf41  271 bytes, 1 callers */

void __cdecl16near FUN_1000_bf41(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int in_DX;
  char cVar4;
  byte bVar5;
  uint in_BX;
  int unaff_DI;
  undefined2 unaff_DS;
  
  if (-1 < (char)in_DX) {
    uVar2 = *(uint *)((undefined *)&DAT_0000_ffa0 + in_BX + unaff_DI);
    while( true ) {
      while( true ) {
        cVar4 = (char)((uint)in_DX >> 8);
        if ((int)*(uint *)(in_BX + unaff_DI) < 0) break;
        uVar1 = *(uint *)((undefined *)&DAT_0000_ffa0 + in_BX + unaff_DI);
        uVar3 = uVar2;
        if (((uVar2 <= uVar1) || (uVar2 = uVar2 - uVar1, uVar3 = uVar1, uVar2 < 3)) &&
           (uVar2 = uVar3 + 1, uVar2 < *(uint *)(in_BX + unaff_DI))) {
          *(uint *)0x4400 = in_BX;
          goto LAB_1000_bf95;
        }
        bVar5 = cVar4 - 1;
        in_DX = (uint)bVar5 << 8;
        if (bVar5 == 0) goto LAB_1000_bf83;
        in_BX = in_BX + 2;
      }
      bVar5 = cVar4 - 1;
      in_DX = (uint)bVar5 << 8;
      if (bVar5 == 0) break;
      in_BX = in_BX + 2;
      uVar2 = *(uint *)((undefined *)&DAT_0000_ffa0 + in_BX + unaff_DI);
    }
LAB_1000_bf83:
    *(uint *)0x4402 = in_BX;
    return;
  }
  uVar2 = *(uint *)(in_BX + unaff_DI + 0x60);
  while( true ) {
    while( true ) {
      cVar4 = (char)((uint)in_DX >> 8);
      if ((int)*(uint *)(in_BX + unaff_DI) < 0) break;
      uVar1 = *(uint *)(in_BX + unaff_DI + 0x60);
      uVar3 = uVar2;
      if (((uVar2 <= uVar1) || (uVar2 = uVar2 - uVar1, uVar3 = uVar1, uVar2 < 3)) &&
         (uVar2 = uVar3 + 1, uVar2 < *(uint *)(in_BX + unaff_DI))) {
        *(uint *)0x4400 = in_BX;
        goto LAB_1000_c018;
      }
      bVar5 = cVar4 - 1;
      in_DX = (uint)bVar5 << 8;
      if (bVar5 == 0) goto LAB_1000_c006;
      in_BX = in_BX + 2;
    }
    bVar5 = cVar4 - 1;
    in_DX = (uint)bVar5 << 8;
    if (bVar5 == 0) break;
    in_BX = in_BX + 2;
    uVar2 = *(uint *)(in_BX + unaff_DI + 0x60);
  }
LAB_1000_c006:
  *(uint *)0x4402 = in_BX;
  return;
  while (uVar2 = uVar3 + 1, uVar2 < *(uint *)(in_BX + unaff_DI)) {
LAB_1000_bf95:
    *(uint *)(in_BX + unaff_DI) = uVar2;
    in_BX = in_BX + 2;
    if (((0x5f < in_BX) || ((int)*(uint *)(in_BX + unaff_DI) < 0)) ||
       ((uVar1 = *(uint *)((undefined *)&DAT_0000_ffa0 + in_BX + unaff_DI), uVar3 = uVar2,
        uVar1 < uVar2 && (uVar3 = uVar1, 2 < uVar2 - uVar1)))) break;
  }
  *(uint *)0x4402 = in_BX;
  return;
  while (uVar2 = uVar3 + 1, uVar2 < *(uint *)(in_BX + unaff_DI)) {
LAB_1000_c018:
    *(uint *)(in_BX + unaff_DI) = uVar2;
    in_BX = in_BX + 2;
    if (((0x5f < in_BX) || ((int)*(uint *)(in_BX + unaff_DI) < 0)) ||
       ((uVar1 = *(uint *)(in_BX + unaff_DI + 0x60), uVar3 = uVar2, uVar1 < uVar2 &&
        (uVar3 = uVar1, 2 < uVar2 - uVar1)))) break;
  }
  *(uint *)0x4402 = in_BX;
  return;
}



/* 1000:c050  FUN_1000_c050  109 bytes, 1 callers */

void __cdecl16near FUN_1000_c050(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char in_DL;
  uint in_BX;
  int unaff_DI;
  undefined2 unaff_DS;
  bool bVar4;
  
  uVar2 = *(uint *)(in_BX + unaff_DI);
  if (-1 < in_DL) {
    while (((bVar4 = 1 < in_BX, in_BX = in_BX - 2, bVar4 && (-1 < (int)*(uint *)(in_BX + unaff_DI)))
           && (((uVar1 = *(uint *)((undefined *)&DAT_0000_ffa0 + in_BX + unaff_DI), uVar3 = uVar2,
                uVar2 <= uVar1 || (uVar3 = uVar1, uVar2 - uVar1 < 3)) &&
               (uVar2 = uVar3 + 1, uVar2 < *(uint *)(in_BX + unaff_DI)))))) {
      *(uint *)(in_BX + unaff_DI) = uVar2;
    }
    return;
  }
  while ((((bVar4 = 1 < in_BX, in_BX = in_BX - 2, bVar4 && (-1 < (int)*(uint *)(in_BX + unaff_DI)))
          && ((uVar1 = *(uint *)(in_BX + unaff_DI + 0x60), uVar3 = uVar2, uVar2 <= uVar1 ||
              (uVar3 = uVar1, uVar2 - uVar1 < 3)))) &&
         (uVar2 = uVar3 + 1, uVar2 < *(uint *)(in_BX + unaff_DI)))) {
    *(uint *)(in_BX + unaff_DI) = uVar2;
  }
  return;
}



/* 1000:c0bd  FUN_1000_c0bd  201 bytes, 14 callers */

undefined4 __cdecl16near FUN_1000_c0bd(void)

{
  uint in_AX;
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint in_DX;
  byte bVar5;
  int *piVar6;
  undefined *puVar7;
  byte *pbVar8;
  
  iVar1 = (in_AX & 0xff) * 0x80;
  piVar6 = (int *)(((in_DX >> 8) * 0x30 + (in_DX & 0xff)) * 2);
  uVar2 = *piVar6 - 1;
  if ((uVar2 == 0) || (0x1ef < uVar2)) {
LAB_1000_c180:
    return CONCAT22(in_DX,in_AX);
  }
  *(uint *)((undefined *)&DAT_0000_247c + iVar1) = uVar2;
  *(undefined2 *)((undefined *)&DAT_0000_247e + iVar1) = 0;
  pbVar8 = (undefined *)&DAT_0000_2400 + (uVar2 >> 2) + iVar1;
  uVar2 = uVar2 & 3;
  if (uVar2 != 0) {
    pbVar8 = pbVar8 + 1;
    puVar7 = (undefined *)0x2;
    bVar4 = 1;
    goto LAB_1000_c121;
  }
  puVar7 = (undefined *)0x2;
  bVar4 = 1;
  do {
    uVar2 = 4;
LAB_1000_c121:
    bVar5 = 0;
    do {
      uVar3 = *(uint *)((int)piVar6 + (int)puVar7);
      if ((uint)piVar6[-0x30] < *(uint *)((int)piVar6 + (int)puVar7)) {
        bVar4 = 2;
        puVar7 = (undefined *)&DAT_0000_ffa0;
        uVar3 = piVar6[-0x30];
      }
      if ((uint)piVar6[-1] < uVar3) {
        bVar4 = 3;
        puVar7 = (undefined *)0xfffe;
        uVar3 = piVar6[-1];
      }
      if ((uint)piVar6[0x30] < uVar3) {
        bVar4 = 0;
        puVar7 = (undefined *)0x60;
        uVar3 = piVar6[0x30];
      }
      if ((uint)piVar6[1] < uVar3) {
        bVar4 = 1;
        puVar7 = (undefined *)0x2;
        uVar3 = piVar6[1];
      }
      bVar5 = bVar5 << 2 | bVar4;
      if (uVar3 == 1) {
        pbVar8[-1] = bVar5;
        goto LAB_1000_c180;
      }
      piVar6 = (int *)((int)piVar6 + (int)puVar7);
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    pbVar8 = pbVar8 + -1;
    *pbVar8 = bVar5;
  } while( true );
}



/* 1000:c231  FUN_1000_c231  43 bytes, 3 callers */

uint __cdecl16near FUN_1000_c231(void)

{
  uint in_AX;
  int iVar1;
  int unaff_SI;
  undefined2 unaff_DS;
  
  iVar1 = (in_AX & 0xff) * 0x80;
  *(undefined2 *)((undefined *)&DAT_0000_247e + iVar1) = 0;
  *(undefined2 *)((undefined *)&DAT_0000_247c + iVar1) = 1;
  ((undefined *)&DAT_0000_2400)[iVar1] = *(byte *)(unaff_SI + 1) >> 1;
  return in_AX;
}



/* 1000:c25c  FUN_1000_c25c  53 bytes, 2 callers */

uint __cdecl16near FUN_1000_c25c(void)

{
  byte bVar1;
  uint in_AX;
  int iVar2;
  int unaff_SI;
  undefined2 unaff_DS;
  
  iVar2 = (in_AX & 0xff) * 0x80;
  *(undefined2 *)((undefined *)&DAT_0000_247e + iVar2) = 0;
  *(undefined2 *)((undefined *)&DAT_0000_247c + iVar2) = 2;
  bVar1 = *(byte *)(unaff_SI + 1) >> 1;
  ((undefined *)&DAT_0000_2400)[iVar2] = bVar1 << 2 | bVar1;
  return in_AX;
}



/* 1000:c291  FUN_1000_c291  47 bytes, 3 callers */

undefined2 __cdecl16near FUN_1000_c291(void)

{
  int iVar1;
  int unaff_SI;
  undefined2 unaff_DS;
  
  iVar1 = (uint)*(byte *)(unaff_SI + 0xb) * 0x80;
  return CONCAT11(3,((byte)((undefined *)&DAT_0000_2400)
                           [iVar1 + (*(uint *)((undefined *)&DAT_0000_247e + iVar1) >> 2)] >>
                     ((byte)*(uint *)((undefined *)&DAT_0000_247e + iVar1) & 3) * '\x02' & 3) *
                    '\x02');
}



/* 1000:c2c0  FUN_1000_c2c0  39 bytes, 3 callers */

undefined2 __cdecl16near FUN_1000_c2c0(void)

{
  undefined2 in_AX;
  int iVar1;
  int unaff_SI;
  undefined2 unaff_DS;
  
  iVar1 = (uint)*(byte *)(unaff_SI + 0xb) * 0x80;
  *(int *)((undefined *)&DAT_0000_247e + iVar1) = *(int *)((undefined *)&DAT_0000_247e + iVar1) + 1;
  if (*(uint *)((undefined *)&DAT_0000_247c + iVar1) <=
      *(uint *)((undefined *)&DAT_0000_247e + iVar1)) {
    *(undefined1 *)(unaff_SI + 0xb) = 0xff;
  }
  return in_AX;
}



/* 1000:c2e7  FUN_1000_c2e7  47 bytes, 5 callers */

undefined2 __cdecl16near FUN_1000_c2e7(void)

{
  undefined2 in_AX;
  int iVar1;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (*(byte *)(unaff_SI + 0xb) != 0xff) {
    iVar1 = (uint)*(byte *)(unaff_SI + 0xb) * 0x80;
    *(int *)((undefined *)&DAT_0000_247c + iVar1) =
         *(int *)((undefined *)&DAT_0000_247c + iVar1) + -1;
    if (*(uint *)((undefined *)&DAT_0000_247c + iVar1) <=
        *(uint *)((undefined *)&DAT_0000_247e + iVar1)) {
      *(undefined1 *)(unaff_SI + 0xb) = 0xff;
    }
  }
  return in_AX;
}



/* 1000:c316  FUN_1000_c316  39 bytes, 2 callers */

undefined2 __cdecl16near FUN_1000_c316(void)

{
  char cVar1;
  undefined2 in_AX;
  undefined2 *in_BX;
  undefined2 unaff_DS;
  
  FUN_1000_9b34();
  cVar1 = *(char *)(in_BX + -0x16c1);
  if (((cVar1 == 'z') || (cVar1 == '{')) || ((byte)(cVar1 - 0x30U) < 0x30)) {
    *in_BX = 0x4000;
  }
  return in_AX;
}



/* 1000:c33e  FUN_1000_c33e  165 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl16near FUN_1000_c33e(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  undefined2 in_AX;
  uint uVar6;
  int iVar7;
  undefined2 in_DX;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *unaff_DI;
  
  pbVar8 = (byte *)(_DAT_2000_6000 + 0x6000);
  pbVar10 = (byte *)0x6002;
  while (pbVar10 != pbVar8) {
    pbVar9 = pbVar10 + 1;
    bVar3 = *pbVar10;
    if ((bVar3 & 0x80) == 0) {
      if ((bVar3 & 0x40) == 0) {
        if ((bVar3 & 0x20) == 0) {
          for (uVar6 = (uint)bVar3; pbVar10 = pbVar9, uVar6 != 0; uVar6 = uVar6 - 1) {
            pbVar5 = unaff_DI;
            unaff_DI = unaff_DI + 1;
            pbVar1 = pbVar9;
            pbVar9 = pbVar9 + 1;
            *pbVar5 = *pbVar1;
          }
        }
        else {
          for (uVar6 = CONCAT11(bVar3,*pbVar9) & 0x1fff; pbVar9 = pbVar9 + 1, pbVar10 = pbVar9,
              uVar6 != 0; uVar6 = uVar6 - 1) {
            pbVar1 = unaff_DI;
            unaff_DI = unaff_DI + 1;
            *pbVar1 = *pbVar9;
          }
        }
      }
      else if ((bVar3 & 0x10) == 0) {
        pbVar10 = pbVar10 + 2;
        bVar4 = *pbVar9;
        for (iVar7 = (bVar3 & 0xf) + 4; iVar7 != 0; iVar7 = iVar7 + -1) {
          pbVar1 = unaff_DI;
          unaff_DI = unaff_DI + 1;
          *pbVar1 = bVar4;
        }
      }
      else {
        pbVar2 = pbVar10 + 3;
        bVar4 = pbVar10[2];
        for (iVar7 = (CONCAT11(bVar3,*pbVar9) & 0xfff) + 4; pbVar10 = pbVar2, iVar7 != 0;
            iVar7 = iVar7 + -1) {
          pbVar1 = unaff_DI;
          unaff_DI = unaff_DI + 1;
          *pbVar1 = bVar4;
        }
      }
    }
    else {
      pbVar10 = pbVar10 + 2;
      pbVar9 = (byte *)-((CONCAT11(bVar3,*pbVar9) & 0x1fff) - (int)unaff_DI);
      for (uVar6 = (uint)(byte)((((char)((bVar3 & 0x60) << 1) < '\0') << 1 | (bVar3 & 0x20) != 0) +
                               4); uVar6 != 0; uVar6 = uVar6 - 1) {
        pbVar5 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        pbVar1 = pbVar9;
        pbVar9 = pbVar9 + 1;
        *pbVar5 = *pbVar1;
      }
      while( true ) {
        if (pbVar10 == pbVar8) goto LAB_1000_c3df;
        if ((*pbVar10 & 0xe0) != 0x60) break;
        pbVar1 = pbVar10;
        pbVar10 = pbVar10 + 1;
        for (uVar6 = (uint)(*pbVar1 & 0x1f); uVar6 != 0; uVar6 = uVar6 - 1) {
          pbVar5 = unaff_DI;
          unaff_DI = unaff_DI + 1;
          pbVar1 = pbVar9;
          pbVar9 = pbVar9 + 1;
          *pbVar5 = *pbVar1;
        }
      }
    }
  }
LAB_1000_c3df:
  return CONCAT22(in_DX,in_AX);
}



/* 1000:c449  FUN_1000_c449  12 bytes, 4 callers */

void __cdecl16near FUN_1000_c449(void)

{
  char *pcVar1;
  char *pcVar2;
  int in_CX;
  char *pcVar3;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  pcVar3 = (char *)s_0000000000_0000_32b0 + 10 + -in_CX;
  for (; in_CX != 0; in_CX = in_CX + -1) {
    pcVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    pcVar1 = pcVar3;
    pcVar3 = pcVar3 + 1;
    *pcVar2 = *pcVar1;
  }
  return;
}



/* 1000:c492  FUN_1000_c492  74 bytes, 6 callers */

undefined4 __cdecl16near FUN_1000_c492(void)

{
  char cVar1;
  undefined2 in_AX;
  undefined2 in_CX;
  int iVar2;
  undefined2 in_DX;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  iVar2 = 0x10;
  do {
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_3 = (undefined1)((uint)in_CX >> 8);
  *(uint *)(char *)s_0000000000_0000_32b0 = CONCAT11(local_3,local_3);
  *(uint *)((char *)s_0000000000_0000_32b0 + 2) = CONCAT11(local_3,local_3);
  FUN_1000_c585();
  FUN_1000_c585();
  cVar1 = FUN_1000_c585();
  if (cVar1 == ' ') {
    ((char *)s_0000000000_0000_32b0)[3] = '0';
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:c585  FUN_1000_c585  27 bytes, 1 callers */

void __cdecl16near FUN_1000_c585(void)

{
  byte bVar1;
  uint in_AX;
  char in_CH;
  char *unaff_DI;
  undefined2 unaff_ES;
  
  bVar1 = ((byte)(in_AX >> 1) & 0x7f) >> 3;
  if (bVar1 != 0) {
    in_CH = '0';
  }
  *unaff_DI = bVar1 + in_CH;
  if ((in_AX & 0xf) != 0) {
    in_CH = '0';
  }
  unaff_DI[1] = ((byte)in_AX & 0xf) + in_CH;
  return;
}



/* 1000:c5bb  FUN_1000_c5bb  56 bytes, 3 callers */

undefined2 __cdecl16near FUN_1000_c5bb(void)

{
  byte bVar1;
  undefined2 in_AX;
  undefined *puVar2;
  int unaff_SI;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x34b6 =
       *(undefined2 *)((undefined *)&DAT_0000_12ad + (*(byte *)(unaff_SI + 0xc) & 0xf) * 2);
  *(undefined2 *)0x34b8 = *(undefined2 *)(unaff_SI + 6);
  *(undefined2 *)0x34be = *(undefined2 *)(unaff_SI + 2);
  bVar1 = *(byte *)(unaff_SI + 10);
  puVar2 = (undefined *)&DAT_0000_1308;
  if ((bVar1 & 0x10) != 0) {
    puVar2 = (undefined *)&DAT_0000_1306;
  }
  *(undefined2 *)0x34bc = puVar2;
  *(uint *)0x34ba = bVar1 & 0xf;
  return in_AX;
}



/* 1000:c5f4  FUN_1000_c5f4  30 bytes, 13 callers */

undefined2 __cdecl16near FUN_1000_c5f4(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  while( true ) {
    *(undefined1 *)0x32d3 = 1;
    if (*(byte *)0x34d6 < *(byte *)0x34d7) break;
    *(char *)0x34d6 = *(byte *)0x34d6 - *(byte *)0x34d7;
    FUN_1000_9aa6();
  }
  *(undefined1 *)0x34d6 = 0;
  return in_AX;
}



/* 1000:c612  FUN_1000_c612  30 bytes, 9 callers */

undefined2 __cdecl16near FUN_1000_c612(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  while( true ) {
    *(undefined1 *)0x32d3 = 1;
    if (CARRY1(*(byte *)0x34d6,*(byte *)0x34d7)) break;
    *(char *)0x34d6 = *(byte *)0x34d6 + *(byte *)0x34d7;
    FUN_1000_9aa6();
  }
  *(undefined1 *)0x34d6 = 0xff;
  return in_AX;
}



/* 1000:c630  FUN_1000_c630  67 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_c630(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int iVar3;
  undefined2 in_DX;
  int iVar4;
  int unaff_SI;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  *(int *)0x34da = unaff_SI;
  iVar4 = 0;
  iVar3 = 0x30;
  do {
    *(char *)(iVar4 + 0x3eba) =
         *(char *)((int)(undefined2 *)&DAT_0000_3e20 + iVar4) - *(char *)(iVar4 + unaff_SI);
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined1 *)0x34d8 = 0xff;
  while( true ) {
    *(undefined1 *)0x32d3 = 1;
    if (*(byte *)0x34d8 < *(byte *)0x34d7) break;
    *(char *)0x34d8 = *(byte *)0x34d8 - *(byte *)0x34d7;
    FUN_1000_c673();
    FUN_1000_9aa6();
  }
  puVar5 = (undefined2 *)*(undefined2 *)0x34da;
  puVar6 = (undefined2 *)&DAT_0000_3e20;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    puVar1 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = *puVar1;
  }
  return CONCAT22(in_DX,in_AX);
}



/* 1000:c673  FUN_1000_c673  45 bytes, 1 callers */

void __cdecl16near FUN_1000_c673(void)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_DS;
  
  iVar2 = *(int *)0x34da;
  iVar5 = 0;
  iVar4 = 0x30;
  bVar1 = *(byte *)0x34d8;
  do {
    cVar3 = *(char *)(iVar5 + 0x3eba);
    if (cVar3 < '\0') {
      cVar3 = -(char)((uint)(byte)(1 - cVar3) * (uint)bVar1 >> 8);
    }
    else {
      cVar3 = (char)((uint)(byte)(cVar3 + 1) * (uint)bVar1 >> 8);
    }
    *(char *)((int)(undefined2 *)&DAT_0000_3e20 + iVar5) = cVar3 + *(char *)(iVar5 + iVar2);
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}



/* 1000:c6a0  FUN_1000_c6a0  13 bytes, 2 callers */

void __cdecl16near FUN_1000_c6a0(void)

{
  int iVar1;
  int in_AX;
  undefined2 unaff_DS;
  
  iVar1 = *(int *)0x3288;
  *(int *)0x3288 = in_AX;
  if (in_AX == iVar1) {
    return;
  }
  FUN_1000_026a();
  return;
}



/* 1000:c6ad  FUN_1000_c6ad  6 bytes, 8 callers */

void __cdecl16near FUN_1000_c6ad(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x28 = in_AX;
  return;
}



/* 1000:c6b3  FUN_1000_c6b3  9 bytes, 9 callers */

void __cdecl16near FUN_1000_c6b3(void)

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0x28 = 0x755;
  return;
}



/* 1000:c6bc  FUN_1000_c6bc  21 bytes, 1 callers */

void __cdecl16near FUN_1000_c6bc(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  puVar4 = (undefined2 *)0x280b;
  puVar5 = (undefined2 *)0xd276;
  for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar2 = *puVar1;
  }
  return;
}



/* 1000:c6d1  FUN_1000_c6d1  41 bytes, 2 callers */

undefined4 __cdecl16near FUN_1000_c6d1(void)

{
  uint uVar1;
  int in_AX;
  undefined2 in_DX;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)&DAT_0000_d274;
  *(uint *)0xd278 = in_AX * 0x10 | uVar1;
  *(uint *)&DAT_0000_d27c = in_AX * -0x10 + 0x1900U | uVar1;
  return CONCAT22(in_DX,in_AX);
}



/* 1000:c6fa  FUN_1000_c6fa  52 bytes, 9 callers */

undefined4 __cdecl16near FUN_1000_c6fa(void)

{
  uint uVar1;
  int in_AX;
  undefined2 in_DX;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)&DAT_0000_d274;
  *(int *)0xd276 = in_AX * 0x28;
  *(undefined2 *)&DAT_0000_d27a = 0;
  *(uint *)0xd278 = in_AX * -0x10 + 0x1900U | uVar1;
  *(uint *)&DAT_0000_d27c = in_AX * 0x10 | uVar1;
  return CONCAT22(in_DX,in_AX);
}



/* 1000:c72e  FUN_1000_c72e  60 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_c72e(void)

{
  uint uVar1;
  int in_AX;
  uint uVar2;
  undefined2 in_DX;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)&DAT_0000_d274;
  *(int *)0xd276 = in_AX * 0x28;
  *(undefined2 *)&DAT_0000_d27a = 0;
  uVar2 = in_AX * -0x10 + 0x1920;
  if (0x1900 < uVar2) {
    uVar2 = 0x1900;
  }
  *(uint *)0xd278 = uVar2 | uVar1;
  *(uint *)&DAT_0000_d27c = in_AX * 0x10 | uVar1;
  return CONCAT22(in_DX,in_AX);
}



/* 1000:c76a  FUN_1000_c76a  9 bytes, 1 callers */

int __cdecl16near FUN_1000_c76a(void)

{
  int in_AX;
  undefined2 unaff_DS;
  
  *(int *)0xd276 = in_AX * 0x28;
  return in_AX;
}



/* 1000:c79d  FUN_1000_c79d  24 bytes, 5 callers */

void __cdecl16near FUN_1000_c79d(void)

{
  undefined2 unaff_DS;
  
  do {
  } while ((*(byte *)0x3483 & 1) == 0);
  do {
  } while ((*(byte *)0x3483 & 1) != 0);
  do {
  } while (*(int *)0x32da == *(int *)0x32da);
  return;
}



/* 1000:c7b5  FUN_1000_c7b5  24 bytes, 5 callers */

void __cdecl16near FUN_1000_c7b5(void)

{
  undefined2 unaff_DS;
  
  do {
  } while ((*(byte *)0x3483 & 1) != 0);
  do {
  } while ((*(byte *)0x3483 & 1) == 0);
  do {
  } while (*(int *)0x32da == *(int *)0x32da);
  return;
}



/* 1000:c7ce  FUN_1000_c7ce  226 bytes, 4 callers */

undefined4 __cdecl16near FUN_1000_c7ce(void)

{
  uint uVar1;
  int iVar2;
  undefined2 in_AX;
  uint uVar3;
  undefined2 in_DX;
  byte bVar4;
  undefined2 unaff_DS;
  bool bVar5;
  
  *(undefined1 *)0x32e5 = 0;
  *(byte *)0x32ce = *(byte *)0x32cb | *(byte *)0x32cc;
  bVar4 = *(byte *)0x32e4;
  uVar1 = *(uint *)0x32f0;
  iVar2 = *(int *)0x32ea;
  uVar3 = *(uint *)0x32e6;
  if (uVar3 != 0) {
    if ((int)uVar3 < 0) {
      if (uVar3 < -*(uint *)0x32ee) {
        if (((iVar2 == 0) || (iVar2 < 0)) || (uVar3 = uVar3 + iVar2, (int)uVar3 < 0)) {
          bVar4 = bVar4 | 4;
          bVar5 = CARRY2(uVar3,uVar1);
          uVar3 = uVar3 + uVar1;
          if (!bVar5) {
LAB_1000_c829:
            *(uint *)0x32e6 = uVar3;
            *(undefined2 *)0x32ea = 0;
            goto LAB_1000_c83d;
          }
        }
LAB_1000_c834:
        *(undefined2 *)0x32e6 = 0;
        *(uint *)0x32ea = uVar3;
      }
    }
    else if (*(uint *)0x32ee <= uVar3) {
      if (((iVar2 == 0) || (-1 < iVar2)) || (uVar3 = uVar3 + iVar2, -1 < (int)uVar3)) {
        bVar4 = bVar4 | 8;
        bVar5 = uVar1 <= uVar3;
        uVar3 = uVar3 - uVar1;
        if (bVar5) goto LAB_1000_c829;
      }
      goto LAB_1000_c834;
    }
  }
LAB_1000_c83d:
  iVar2 = *(int *)0x32ec;
  uVar3 = *(uint *)0x32e8;
  if (uVar3 == 0) goto LAB_1000_c892;
  if ((int)uVar3 < 0) {
    if (-*(uint *)0x32ee <= uVar3) goto LAB_1000_c892;
    if (((iVar2 == 0) || (iVar2 < 0)) || (uVar3 = uVar3 + iVar2, (int)uVar3 < 0)) {
      bVar4 = bVar4 | 1;
      bVar5 = CARRY2(uVar3,uVar1);
      uVar3 = uVar3 + uVar1;
      if (!bVar5) {
LAB_1000_c87e:
        *(uint *)0x32e8 = uVar3;
        *(undefined2 *)0x32ec = 0;
        goto LAB_1000_c892;
      }
    }
  }
  else {
    if (uVar3 < *(uint *)0x32ee) goto LAB_1000_c892;
    if (((iVar2 == 0) || (-1 < iVar2)) || (uVar3 = uVar3 + iVar2, -1 < (int)uVar3)) {
      bVar4 = bVar4 | 2;
      bVar5 = uVar1 <= uVar3;
      uVar3 = uVar3 - uVar1;
      if (bVar5) goto LAB_1000_c87e;
    }
  }
  *(undefined2 *)0x32e8 = 0;
  *(uint *)0x32ec = uVar3;
LAB_1000_c892:
  if ((bVar4 != 0) && (*(undefined1 *)0x32e5 = 1, (bVar4 & 0x60) == 0)) {
    *(undefined1 *)0x32d0 = 0;
  }
  *(byte *)0x32ce = *(byte *)0x32ce | bVar4;
  return CONCAT22(in_DX,CONCAT11((char)((uint)in_AX >> 8),*(undefined1 *)0x32ce));
}



/* 1000:c8b0  FUN_1000_c8b0  40 bytes, 3 callers */

byte __cdecl16near FUN_1000_c8b0(void)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  undefined2 unaff_DS;
  undefined1 in_ZF;
  bool bVar4;
  
  iVar2 = (uint)*(byte *)0x32ce << 8;
  do {
    bVar1 = FUN_1000_c7ce();
    if ((bool)in_ZF) goto LAB_1000_c8c9;
    if (((byte)((uint)iVar2 >> 8) & bVar1) == 0) goto LAB_1000_c8ce;
    in_ZF = *(char *)0x32d0 == '\0';
  } while (!(bool)in_ZF);
  uVar3 = 2;
LAB_1000_c8d0:
  *(undefined1 *)0x32d0 = uVar3;
  return bVar1;
LAB_1000_c8c9:
  do {
    bVar4 = true;
    bVar1 = FUN_1000_c7ce();
  } while (bVar4);
LAB_1000_c8ce:
  uVar3 = 0x14;
  goto LAB_1000_c8d0;
}



/* 1000:c8d8  FUN_1000_c8d8  37 bytes, 4 callers */

byte __cdecl16near FUN_1000_c8d8(void)

{
  byte bVar1;
  byte bVar2;
  undefined2 unaff_DS;
  undefined1 in_ZF;
  
  bVar2 = *(byte *)0x32ce;
  bVar1 = FUN_1000_c7ce();
  if (!(bool)in_ZF) {
    if ((bVar2 & bVar1) == 0) {
      bVar2 = 0x14;
    }
    else {
      bVar2 = 2;
      if (*(char *)0x32d0 != '\0') {
        return 0;
      }
    }
  }
  *(byte *)0x32d0 = bVar2;
  return bVar1;
}



/* 1000:c8fd  FUN_1000_c8fd  18 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_c8fd(void)

{
  undefined1 uVar1;
  char cVar2;
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  uVar1 = *(undefined1 *)0x32ce;
  do {
    cVar2 = FUN_1000_c7ce();
  } while (cVar2 != '\0');
  *(undefined1 *)0x32ce = uVar1;
  return in_AX;
}



/* 1000:c90f  FUN_1000_c90f  18 bytes, 6 callers */

undefined2 __cdecl16near FUN_1000_c90f(void)

{
  undefined2 in_AX;
  uint uVar1;
  
  do {
    uVar1 = FUN_1000_c8b0();
  } while ((uVar1 & 0x60) == 0);
  FUN_1000_0d12(uVar1);
  return in_AX;
}



/* 1000:c921  FUN_1000_c921  37 bytes, 2 callers */

undefined2 __cdecl16near FUN_1000_c921(void)

{
  undefined2 in_AX;
  uint uVar1;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x32d4 = 0xf0;
  do {
    uVar1 = FUN_1000_c8d8();
    if ((uVar1 & 0x60) != 0) {
      FUN_1000_0d12(uVar1);
      break;
    }
  } while (*(char *)0x32d4 != '\0');
  *(undefined1 *)0x32d4 = 0;
  return in_AX;
}



/* 1000:c946  FUN_1000_c946  260 bytes, 1 callers */

void __cdecl16near FUN_1000_c946(void)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  undefined2 uVar7;
  uint *puVar8;
  undefined *puVar9;
  int *piVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  FUN_1000_c5f4();
  FUN_1000_74c6();
  uVar5 = FUN_1000_c7ce();
  if ((uVar5 & 0x60) != 0) {
    FUN_1000_0ccc();
    return;
  }
  uVar5 = 0x80;
  iVar6 = 3 - *(uint *)0x3c1e;
  if (*(uint *)0x3c1e < 4 && iVar6 != 0) {
    uVar5 = 0x80 >> ((byte)iVar6 & 0x1f);
  }
  *(uint *)0x3bb4 = uVar5;
  *(undefined2 *)0x3bb6 = (undefined *)&DAT_0000_ce74 + uVar5 * 8;
  puVar8 = (uint *)&DAT_0000_ce74;
  iVar6 = *(int *)0x3bb4 * 2;
  do {
    uVar5 = FUN_1000_9a36();
    *puVar8 = uVar5 & 0x7fff;
    puVar8 = puVar8 + 2;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  puVar9 = (undefined *)&DAT_0000_ce74;
  iVar6 = *(int *)0x3bb4 * 2;
  do {
    bVar4 = FUN_1000_9a36();
    uVar7 = 0x50;
    if (((bVar4 & 7) != 0) && (uVar7 = 0xa0, 1 < (bVar4 & 7))) {
      uVar7 = 0xf0;
    }
    *(undefined2 *)(puVar9 + 2) = uVar7;
    puVar9 = puVar9 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_1000_5dfd();
  FUN_1000_7c1c();
  FUN_1000_7ad3();
  FUN_1000_7ad3();
  piVar10 = (int *)0x3b4f;
  while (piVar1 = piVar10, piVar10 = piVar10 + 1, *piVar1 != -1) {
    FUN_1000_759b();
  }
  *(undefined2 *)0x32e0 = 0;
  puVar11 = (undefined2 *)0x24cb;
  puVar12 = (undefined2 *)&DAT_0000_3e20;
  for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar3 = puVar12;
    puVar12 = puVar12 + 1;
    puVar2 = puVar11;
    puVar11 = puVar11 + 1;
    *puVar3 = *puVar2;
  }
  FUN_1000_c6ad();
  FUN_1000_c612();
  *(undefined1 *)0x32d3 = 0x1e;
  do {
    bVar4 = FUN_1000_c7ce();
    if ((bVar4 & 0x60) != 0) goto LAB_1000_ca35;
  } while (*(char *)0x32d3 != '\0');
  FUN_1000_c630();
  do {
    bVar4 = FUN_1000_c7ce();
  } while ((bVar4 & 0x60) == 0);
LAB_1000_ca35:
  FUN_1000_0ccc();
  FUN_1000_95f7();
  FUN_1000_c5f4();
  *(undefined2 *)0x32e0 = 1;
  FUN_1000_c6b3();
  return;
}



/* 1000:ca4a  FUN_1000_ca4a  207 bytes, 1 callers */

undefined2 __cdecl16near FUN_1000_ca4a(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  uVar3 = FUN_1000_6808();
  if ((bool)in_CF) {
    return uVar3;
  }
  FUN_1000_0ccc();
  FUN_1000_c5f4();
  *(undefined2 *)&DAT_0000_3bc6 = 6;
  FUN_1000_5fe2();
  FUN_1000_0ceb();
  FUN_1000_74c6();
  FUN_1000_026a();
  FUN_1000_99a0();
  FUN_1000_ad56();
  *(undefined2 *)0xc560 = 0;
  *(undefined2 *)0x32e0 = 0;
  *(undefined2 *)0x346a = 0xffff;
  *(undefined2 *)0x346e = 0xffff;
  FUN_1000_cb19();
  FUN_1000_cdf0();
  FUN_1000_d205();
  FUN_1000_d45a();
  FUN_1000_da07();
  FUN_1000_db5b();
  FUN_1000_ddbb();
  FUN_1000_e137();
  FUN_1000_99cc();
  *(undefined2 *)0x32e0 = 1;
  puVar5 = (undefined2 *)&DAT_0000_249b;
  puVar6 = (undefined2 *)&DAT_0000_3e20;
  for (iVar4 = 0x18; iVar4 != 0; iVar4 = iVar4 + -1) {
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    puVar1 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = *puVar1;
  }
  FUN_1000_0ccc();
  *(undefined2 *)0x3bd4 = 0;
  *(undefined2 *)0x3bd6 = 0;
  *(undefined2 *)0xc52c = 0;
  *(undefined2 *)&DAT_0000_32bf = 0;
  *(undefined2 *)0x3bc2 = 0xffff;
  FUN_1000_02c3();
  FUN_1000_bcf4();
  FUN_1000_026a();
  FUN_1000_9355();
  FUN_1000_02e1();
  FUN_1000_02f9();
  FUN_1000_027c();
  FUN_1000_0296();
  FUN_1000_a6a5();
  FUN_1000_5cef();
  FUN_1000_5d0e();
  FUN_1000_96f2();
  FUN_1000_9355();
  FUN_1000_727a();
  FUN_1000_5d0e();
  FUN_1000_9355();
  FUN_1000_727a();
  FUN_1000_4cdd();
  *(undefined2 *)&DAT_0000_3bc6 = 5;
  FUN_1000_5f7e();
  FUN_1000_7c9e();
  FUN_1000_7c9e();
  FUN_1000_4d4a();
  return uVar3;
}



/* 1000:cb19  FUN_1000_cb19  685 bytes, 1 callers */

void __cdecl16near FUN_1000_cb19(void)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined2 uVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 uVar12;
  undefined4 uVar13;
  
  FUN_1000_5ee4();
  puVar10 = (undefined2 *)0x0;
  uVar8 = 0xa800;
  do {
    uVar5 = uVar8;
    puVar11 = (undefined2 *)0x0;
    for (iVar6 = 4000; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    uVar4 = uVar5 + 0x800;
    uVar8 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar8 = uVar5 + 0x2800, uVar4 < 0xe000));
  FUN_1000_5ee4();
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  puVar10 = (undefined2 *)0x0;
  uVar8 = 0xa800;
  do {
    uVar5 = uVar8;
    puVar11 = (undefined2 *)0x0;
    for (iVar6 = 4000; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    uVar4 = uVar5 + 0x800;
    uVar8 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar8 = uVar5 + 0x2800, uVar4 < 0xe000));
  bVar1 = *(byte *)0x3482;
  uVar12 = 0;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  FUN_1000_5ee4();
  FUN_1000_c6fa();
  FUN_1000_99ef();
  FUN_1000_c6ad();
  puVar10 = (undefined2 *)0x252b;
  puVar11 = (undefined2 *)&DAT_0000_3e20;
  for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar3 = puVar11;
    puVar11 = puVar11 + 1;
    puVar2 = puVar10;
    puVar10 = puVar10 + 1;
    *puVar3 = *puVar2;
  }
  *(undefined1 *)0x34d6 = 0xff;
  FUN_1000_9aae();
  uVar8 = 1;
  do {
    FUN_1000_cdc6();
  } while (!(bool)uVar12);
  uVar13 = FUN_1000_cdc6();
  FUN_1000_99ef((int)uVar13,uVar8,(int)((ulong)uVar13 >> 0x10));
  do {
    uVar5 = FUN_1000_cdc6();
  } while (99 < uVar5);
  iVar6 = uVar8 - (uVar8 >> 2);
  do {
    FUN_1000_cddb();
    uVar9 = 0;
  } while (iVar6 != 0);
  do {
    uVar8 = FUN_1000_cdc6();
  } while (0x9f < uVar8);
  FUN_1000_9aa6();
  FUN_1000_c6fa();
  FUN_1000_99ef();
  FUN_1000_99ef();
  FUN_1000_c6d1();
  *(undefined2 *)0xd276 = (undefined *)&DAT_0000_2ff8;
  *(undefined2 *)&DAT_0000_d27a = 0;
  FUN_1000_9aae();
  puVar10 = (undefined2 *)0x0;
  uVar8 = 0xa800;
  do {
    uVar5 = uVar8;
    puVar11 = (undefined2 *)0x2e40;
    for (iVar6 = 0x18d8; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    uVar4 = uVar5 + 0x800;
    uVar8 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar8 = uVar5 + 0x2800, uVar4 < 0xe000));
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  puVar10 = (undefined2 *)0x0;
  uVar8 = 0xa800;
  do {
    uVar5 = uVar8;
    puVar11 = (undefined2 *)0x2e40;
    for (iVar6 = 0x18d8; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    uVar4 = uVar5 + 0x800;
    uVar8 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar8 = uVar5 + 0x2800, uVar4 < 0xe000));
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  iVar6 = 0xcf;
  do {
    FUN_1000_9aa6();
    *(undefined1 *)0x32d3 = 1;
    uVar13 = FUN_1000_c76a();
    uVar12 = (undefined1)((ulong)uVar13 >> 0x18);
    if ((char)((ulong)uVar13 >> 0x10) == '\x01') {
      FUN_1000_99ef((int)uVar13 + -1,uVar9,iVar6,CONCAT11(uVar12,uVar12));
    }
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  do {
  } while (*(uint *)0x3f1a < 0x500);
  iVar7 = 0x28;
  iVar6 = 4000;
  do {
    *(int *)0xd276 = iVar6 + 1;
    uVar13 = FUN_1000_9aa6();
    iVar6 = (int)uVar13;
    *(undefined1 *)0x32d3 = 1;
    FUN_1000_99ef(iVar6,uVar9,iVar7,(int)((ulong)uVar13 >> 0x10));
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  FUN_1000_5ee4();
  puVar10 = (undefined2 *)0x0;
  uVar8 = 0xa800;
  do {
    uVar5 = uVar8;
    puVar11 = (undefined2 *)0x2e40;
    for (iVar6 = 0x18d8; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    uVar4 = uVar5 + 0x800;
    uVar8 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar8 = uVar5 + 0x2800, uVar4 < 0xe000));
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  puVar10 = (undefined2 *)0x0;
  uVar8 = 0xa800;
  do {
    uVar5 = uVar8;
    puVar11 = (undefined2 *)0x2e40;
    for (iVar6 = 0x18d8; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    uVar4 = uVar5 + 0x800;
    uVar8 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar8 = uVar5 + 0x2800, uVar4 < 0xe000));
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  iVar7 = 0x28;
  iVar6 = 0xfc8;
  do {
    *(int *)0xd276 = iVar6 + -1;
    uVar13 = FUN_1000_9aa6();
    iVar6 = (int)uVar13;
    *(undefined1 *)0x32d3 = 1;
    FUN_1000_99ef(iVar6,uVar9,iVar7,(int)((ulong)uVar13 >> 0x10));
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  FUN_1000_9aae();
  FUN_1000_c5f4();
  FUN_1000_c6fa();
  FUN_1000_c6b3();
  FUN_1000_72c1();
  FUN_1000_72a7();
  FUN_1000_74c6();
  FUN_1000_9a0d();
  return;
}



/* 1000:cdc6  FUN_1000_cdc6  21 bytes, 1 callers */

undefined3 __cdecl16near FUN_1000_cdc6(void)

{
  int iVar1;
  char extraout_DL;
  char cVar2;
  char extraout_DH;
  int in_BX;
  undefined2 unaff_DS;
  
  FUN_1000_9aa6();
  *(undefined1 *)0x32d3 = 1;
  iVar1 = FUN_1000_c6fa();
  cVar2 = extraout_DL + -1;
  if (cVar2 == '\0') {
    in_BX = in_BX + 1;
    cVar2 = extraout_DH;
  }
  return CONCAT12(cVar2,iVar1 - in_BX);
}



/* 1000:cddb  FUN_1000_cddb  21 bytes, 1 callers */

undefined3 __cdecl16near FUN_1000_cddb(void)

{
  int iVar1;
  char extraout_DL;
  char cVar2;
  char extraout_DH;
  int in_BX;
  undefined2 unaff_DS;
  
  FUN_1000_9aa6();
  *(undefined1 *)0x32d3 = 1;
  iVar1 = FUN_1000_c6fa();
  cVar2 = extraout_DL + -1;
  if (cVar2 == '\0') {
    in_BX = in_BX + -1;
    cVar2 = extraout_DH;
  }
  return CONCAT12(cVar2,iVar1 + in_BX);
}



/* 1000:cdf0  FUN_1000_cdf0  1045 bytes, 1 callers */

void __cdecl16near FUN_1000_cdf0(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  puVar4 = (undefined2 *)0x255b;
  puVar5 = (undefined2 *)&DAT_0000_3e20;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar2 = *puVar1;
  }
  FUN_1000_5efe();
  iVar3 = 0x18;
  do {
    FUN_1000_9859();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_1000_74c6();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_729a();
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_c6ad();
  FUN_1000_c612();
  FUN_1000_9aae();
  *(undefined2 *)0x34e0 = 3;
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 2;
  *(undefined1 *)0x32d3 = 4;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 4;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 3;
  FUN_1000_c7b5();
  FUN_1000_98a0();
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x3e43 = 10;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 4;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 4;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x5a;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x5a;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x5a;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x3c;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_c7b5();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  FUN_1000_9aae();
  *(undefined1 *)0x32d3 = 4;
  FUN_1000_98a0();
  FUN_1000_9aa6();
  *(undefined1 *)0x32d3 = 4;
  FUN_1000_98a0();
  FUN_1000_9aa6();
  *(undefined1 *)0x32d3 = 4;
  FUN_1000_98a0();
  FUN_1000_9aa6();
  *(undefined1 *)0x32d3 = 4;
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_9aae();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_72ad();
  FUN_1000_9aae();
  FUN_1000_c5f4();
  FUN_1000_c6b3();
  FUN_1000_74c6();
  FUN_1000_72c1();
  FUN_1000_72a7();
  return;
}



/* 1000:d205  FUN_1000_d205  597 bytes, 1 callers */

void __cdecl16near FUN_1000_d205(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  int extraout_DX;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  bool bVar8;
  
  puVar6 = (undefined2 *)0x258b;
  puVar7 = (undefined2 *)&DAT_0000_3e20;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar7;
    puVar7 = puVar7 + 1;
    puVar1 = puVar6;
    puVar6 = puVar6 + 1;
    *puVar2 = *puVar1;
  }
  FUN_1000_5efe();
  iVar3 = 0xc;
  do {
    FUN_1000_9859();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_1000_74c6();
  *(undefined1 *)0x34d6 = 0xff;
  FUN_1000_99ef();
  FUN_1000_99ef();
  FUN_1000_c6fa();
  FUN_1000_98a0();
  iVar3 = 200;
  do {
    FUN_1000_9aa6();
    *(undefined1 *)0x32d3 = 1;
    FUN_1000_c6fa();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined1 *)0x34d6 = 0;
  do {
  } while (*(int *)0x32da == *(int *)0x32da);
  FUN_1000_c6fa();
  FUN_1000_7518();
  FUN_1000_9a0d();
  FUN_1000_98a0();
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_729a();
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_c6ad();
  FUN_1000_c612();
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_c7b5();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_c79d();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_7518();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x3c;
  FUN_1000_72a7();
  FUN_1000_7518();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x78;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x3c;
  FUN_1000_72a7();
  FUN_1000_7518();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  FUN_1000_9aae();
  uVar5 = 399;
  do {
    FUN_1000_9aa6();
    *(undefined1 *)0x32d3 = 1;
    FUN_1000_c6fa();
    uVar4 = extraout_DX + 1;
    if (uVar4 >> 3 != 0) {
      FUN_1000_99ef();
    }
    bVar8 = uVar4 <= uVar5;
    uVar5 = uVar5 - uVar4;
  } while (bVar8);
  FUN_1000_7518();
  FUN_1000_9a0d();
  FUN_1000_c6fa();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_9aae();
  FUN_1000_c5f4();
  FUN_1000_c6b3();
  FUN_1000_74c6();
  FUN_1000_72c1();
  FUN_1000_72a7();
  return;
}



/* 1000:d45a  FUN_1000_d45a  1453 bytes, 1 callers */

void __cdecl16near FUN_1000_d45a(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 extraout_DX_01;
  undefined2 extraout_DX_02;
  int extraout_DX_03;
  int extraout_DX_04;
  int extraout_DX_05;
  int extraout_DX_06;
  int iVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  uVar3 = *(undefined2 *)0x2eab;
  uVar4 = *(undefined2 *)0x2ea3;
  uVar5 = *(undefined2 *)0x2e93;
  uVar6 = *(undefined2 *)0x2e7b;
  puVar11 = (undefined2 *)0x25bb;
  puVar12 = (undefined2 *)&DAT_0000_3e20;
  for (iVar9 = 0x18; iVar9 != 0; iVar9 = iVar9 + -1) {
    puVar2 = puVar12;
    puVar12 = puVar12 + 1;
    puVar1 = puVar11;
    puVar11 = puVar11 + 1;
    *puVar2 = *puVar1;
  }
  FUN_1000_5efe();
  iVar9 = 10;
  do {
    FUN_1000_9859();
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  FUN_1000_5efe();
  iVar9 = 0x16;
  do {
    FUN_1000_9859();
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  *(undefined2 *)0x34e0 = 3;
  FUN_1000_c6ad();
  FUN_1000_74c6();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_72a7();
  FUN_1000_c612();
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 2;
  iVar9 = 8;
  do {
    *(undefined1 *)0x32d3 = 8;
    FUN_1000_72a7();
    FUN_1000_7571();
    *(undefined2 *)0x2e7b = extraout_DX;
    FUN_1000_98a0();
    FUN_1000_98a0();
    FUN_1000_9aa6();
    FUN_1000_72c1();
    *(undefined1 *)0x32d3 = 8;
    FUN_1000_72a7();
    FUN_1000_7571();
    *(undefined2 *)0x2e7b = extraout_DX_00;
    FUN_1000_98a0();
    FUN_1000_98a0();
    FUN_1000_9aa6();
    FUN_1000_72c1();
    *(undefined1 *)0x32d3 = 8;
    FUN_1000_72a7();
    FUN_1000_7571();
    *(undefined2 *)0x2e7b = extraout_DX_01;
    FUN_1000_98a0();
    FUN_1000_98a0();
    FUN_1000_9aa6();
    FUN_1000_72c1();
    *(undefined1 *)0x32d3 = 8;
    FUN_1000_72a7();
    FUN_1000_7571();
    *(undefined2 *)0x2e7b = extraout_DX_02;
    FUN_1000_98a0();
    FUN_1000_98a0();
    FUN_1000_9aa6();
    FUN_1000_72c1();
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  FUN_1000_72a7();
  FUN_1000_98a0();
  *(undefined1 *)0x32d3 = 2;
  FUN_1000_72c1();
  FUN_1000_9aa6();
  FUN_1000_72c1();
  FUN_1000_9aae();
  *(undefined1 *)0x32d3 = 2;
  FUN_1000_72c1();
  FUN_1000_9aa6();
  *(undefined1 *)0x32d3 = 4;
  FUN_1000_72c1();
  FUN_1000_9aa6();
  *(undefined1 *)0x32d3 = 2;
  FUN_1000_72c1();
  FUN_1000_9aa6();
  FUN_1000_72c1();
  FUN_1000_9aae();
  *(undefined1 *)0x32d3 = 2;
  FUN_1000_72c1();
  FUN_1000_9aa6();
  *(undefined1 *)0x32d3 = 4;
  FUN_1000_72c1();
  FUN_1000_9aa6();
  *(undefined1 *)0x32d3 = 2;
  FUN_1000_9aa6();
  FUN_1000_72c1();
  *(undefined1 *)0x32d3 = 4;
  FUN_1000_72c1();
  FUN_1000_9aa6();
  *(undefined1 *)0x32d3 = 0x1e;
  FUN_1000_72c1();
  FUN_1000_9aa6();
  FUN_1000_72c1();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_9aae();
  FUN_1000_c5f4();
  *(undefined2 *)0x34e0 = 0;
  puVar11 = (undefined2 *)0x25bb;
  puVar12 = (undefined2 *)&DAT_0000_3e20;
  for (iVar9 = 0x18; iVar9 != 0; iVar9 = iVar9 + -1) {
    puVar2 = puVar12;
    puVar12 = puVar12 + 1;
    puVar1 = puVar11;
    puVar11 = puVar11 + 1;
    *puVar2 = *puVar1;
  }
  FUN_1000_c6fa();
  FUN_1000_72a7();
  FUN_1000_7518();
  FUN_1000_98a0();
  FUN_1000_72a7();
  FUN_1000_7518();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_c612();
  iVar9 = 0x50;
  do {
    *(undefined1 *)0x32d3 = 8;
    FUN_1000_72a7();
    iVar7 = extraout_DX_03 + -2;
    iVar10 = extraout_DX_03;
    if (-0x10 < iVar7) {
      if (iVar7 < 0) {
        *(int *)0x2e93 = extraout_DX_03 + 0xe;
      }
      else {
        *(int *)0xc560 = iVar7 * 0x7d;
        uVar8 = 0x80 - iVar7;
        if (0x10 < uVar8) {
          uVar8 = 0x10;
        }
        *(uint *)0x2e93 = uVar8;
      }
      FUN_1000_98a0();
      *(undefined2 *)0xc560 = 0;
      iVar10 = extraout_DX_04;
    }
    if (iVar10 < 0) {
      *(int *)0x2eab = iVar10 + 0x20;
      *(int *)0xc560 = iVar10 * -0x7d;
LAB_1000_d757:
      FUN_1000_98a0();
      *(undefined2 *)0xc560 = 0;
    }
    else {
      uVar8 = 0x80 - iVar10;
      if (uVar8 != 0) {
        if (0x20 < uVar8) {
          uVar8 = 0x20;
        }
        *(uint *)0x2eab = uVar8;
        goto LAB_1000_d757;
      }
    }
    FUN_1000_9aa6();
    FUN_1000_72c1();
    *(undefined1 *)0x32d3 = 8;
    FUN_1000_72a7();
    iVar7 = extraout_DX_05 + -2;
    iVar10 = extraout_DX_05;
    if (-0x10 < iVar7) {
      if (iVar7 < 0) {
        *(int *)0x2e93 = extraout_DX_05 + 0xe;
      }
      else {
        *(int *)0xc560 = iVar7 * 0x7d;
        uVar8 = 0x80 - iVar7;
        if (0x10 < uVar8) {
          uVar8 = 0x10;
        }
        *(uint *)0x2e93 = uVar8;
      }
      FUN_1000_98a0();
      *(undefined2 *)0xc560 = 0;
      iVar10 = extraout_DX_06;
    }
    if (iVar10 < 0) {
      *(int *)0x2ea3 = iVar10 + 0x20;
      *(int *)0xc560 = iVar10 * -0x7d;
LAB_1000_d7ee:
      FUN_1000_98a0();
      *(undefined2 *)0xc560 = 0;
    }
    else {
      uVar8 = 0x80 - iVar10;
      if (uVar8 != 0) {
        if (0x20 < uVar8) {
          uVar8 = 0x20;
        }
        *(uint *)0x2ea3 = uVar8;
        goto LAB_1000_d7ee;
      }
    }
    FUN_1000_9aa6();
    FUN_1000_72c1();
    iVar9 = iVar9 + -1;
    if (iVar9 == 0) {
      FUN_1000_9aae();
      FUN_1000_c5f4();
      FUN_1000_c6fa();
      FUN_1000_72a7();
      FUN_1000_7518();
      FUN_1000_98a0();
      FUN_1000_98a0();
      FUN_1000_72a7();
      FUN_1000_7518();
      FUN_1000_98a0();
      FUN_1000_98a0();
      puVar11 = (undefined2 *)0x25eb;
      puVar12 = (undefined2 *)&DAT_0000_3e20;
      for (iVar9 = 0x18; iVar9 != 0; iVar9 = iVar9 + -1) {
        puVar2 = puVar12;
        puVar12 = puVar12 + 1;
        puVar1 = puVar11;
        puVar11 = puVar11 + 1;
        *puVar2 = *puVar1;
      }
      FUN_1000_c612();
      *(undefined1 *)0x32d3 = 4;
      FUN_1000_9aa6();
      FUN_1000_72c1();
      *(undefined1 *)0x32d3 = 4;
      FUN_1000_72a7();
      FUN_1000_98a0();
      FUN_1000_98a0();
      FUN_1000_9aa6();
      FUN_1000_72c1();
      *(undefined1 *)0x32d3 = 4;
      FUN_1000_72a7();
      FUN_1000_98a0();
      FUN_1000_98a0();
      FUN_1000_9aa6();
      FUN_1000_72c1();
      *(undefined1 *)0x32d3 = 4;
      FUN_1000_72a7();
      FUN_1000_98a0();
      FUN_1000_98a0();
      FUN_1000_9aa6();
      FUN_1000_72c1();
      *(undefined1 *)0x32d3 = 4;
      FUN_1000_72a7();
      FUN_1000_98a0();
      FUN_1000_98a0();
      FUN_1000_9aa6();
      FUN_1000_72c1();
      *(undefined1 *)0x32d3 = 4;
      FUN_1000_72a7();
      FUN_1000_98a0();
      FUN_1000_98a0();
      FUN_1000_9aa6();
      FUN_1000_72c1();
      *(undefined1 *)0x32d3 = 4;
      FUN_1000_72a7();
      FUN_1000_98a0();
      FUN_1000_98a0();
      FUN_1000_9aa6();
      FUN_1000_72c1();
      *(undefined1 *)0x32d3 = 4;
      FUN_1000_72a7();
      FUN_1000_98a0();
      FUN_1000_98a0();
      FUN_1000_9aa6();
      FUN_1000_72c1();
      *(undefined1 *)0x32d3 = 4;
      FUN_1000_72a7();
      FUN_1000_98a0();
      FUN_1000_9aa6();
      FUN_1000_72c1();
      FUN_1000_9aae();
      FUN_1000_c5f4();
      FUN_1000_72a7();
      FUN_1000_98a0();
      FUN_1000_72a7();
      FUN_1000_98a0();
      puVar11 = (undefined2 *)0x25bb;
      puVar12 = (undefined2 *)&DAT_0000_3e20;
      for (iVar9 = 0x18; iVar9 != 0; iVar9 = iVar9 + -1) {
        puVar2 = puVar12;
        puVar12 = puVar12 + 1;
        puVar1 = puVar11;
        puVar11 = puVar11 + 1;
        *puVar2 = *puVar1;
      }
      *(undefined2 *)0x34e0 = 3;
      FUN_1000_c612();
      FUN_1000_9aae();
      FUN_1000_72a7();
      FUN_1000_c79d();
      FUN_1000_98a0();
      FUN_1000_72a7();
      FUN_1000_c7b5();
      FUN_1000_98a0();
      FUN_1000_9aae();
      FUN_1000_c5f4();
      FUN_1000_c6b3();
      FUN_1000_74c6();
      FUN_1000_72c1();
      FUN_1000_72a7();
      *(undefined2 *)0x2e7b = uVar6;
      *(undefined2 *)0x2e93 = uVar5;
      *(undefined2 *)0x2ea3 = uVar4;
      *(undefined2 *)0x2eab = uVar3;
      return;
    }
  } while( true );
}



/* 1000:da07  FUN_1000_da07  340 bytes, 1 callers */

void __cdecl16near FUN_1000_da07(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 extraout_DX;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  uVar3 = *(undefined2 *)0x2f83;
  puVar5 = (undefined2 *)0x261b;
  puVar6 = (undefined2 *)&DAT_0000_3e20;
  for (iVar4 = 0x18; iVar4 != 0; iVar4 = iVar4 + -1) {
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    puVar1 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = *puVar1;
  }
  FUN_1000_5efe();
  iVar4 = 4;
  do {
    FUN_1000_9859();
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_1000_5efe();
  iVar4 = 3;
  do {
    FUN_1000_9859();
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_1000_74c6();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_c612();
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_c72e();
  FUN_1000_72c1();
  FUN_1000_9aae();
  iVar4 = 200;
  *(undefined2 *)0x2f83 = 1;
  do {
    FUN_1000_9aa6();
    *(undefined1 *)0x32d3 = 1;
    *(undefined2 *)0xc560 = extraout_DX;
    FUN_1000_98a0();
    FUN_1000_c72e();
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_1000_9aa6();
  FUN_1000_c6fa();
  *(undefined2 *)0xc560 = 0;
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_9aae();
  FUN_1000_c5f4();
  FUN_1000_c6b3();
  FUN_1000_74c6();
  FUN_1000_72c1();
  FUN_1000_72a7();
  *(undefined2 *)0x2f83 = uVar3;
  return;
}



/* 1000:db5b  FUN_1000_db5b  608 bytes, 1 callers */

void __cdecl16near FUN_1000_db5b(void)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  undefined1 *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  puVar6 = (undefined2 *)0x264b;
  puVar8 = (undefined2 *)&DAT_0000_3e20;
  for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {
    puVar4 = puVar8;
    puVar8 = puVar8 + 1;
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    *puVar4 = *puVar2;
  }
  *(undefined2 *)0x32a8 = 0x80f;
  FUN_1000_5efe();
  iVar5 = 4;
  do {
    FUN_1000_9859();
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  FUN_1000_5efe();
  iVar5 = 4;
  do {
    FUN_1000_9859();
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  FUN_1000_74c6();
  *(undefined2 *)0x34e0 = 0;
  FUN_1000_c6ad();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_c612();
  FUN_1000_9aae();
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  puVar7 = (undefined1 *)0x2ff5;
  puVar9 = (undefined1 *)0x3e35;
  for (iVar5 = 3; iVar5 != 0; iVar5 = iVar5 + -1) {
    puVar3 = puVar9;
    puVar9 = puVar9 + 1;
    puVar1 = puVar7;
    puVar7 = puVar7 + 1;
    *puVar3 = *puVar1;
  }
  FUN_1000_72c1();
  FUN_1000_9aae();
  *(undefined2 *)0x34de = 0;
  *(undefined2 *)0x34e0 = 1;
  do {
  } while (*(uint *)0x34de < 0x30);
  *(undefined2 *)0x34e0 = 0;
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  puVar7 = (undefined1 *)0x2660;
  puVar9 = (undefined1 *)0x3e35;
  for (iVar5 = 3; iVar5 != 0; iVar5 = iVar5 + -1) {
    puVar3 = puVar9;
    puVar9 = puVar9 + 1;
    puVar1 = puVar7;
    puVar7 = puVar7 + 1;
    *puVar3 = *puVar1;
  }
  FUN_1000_72c1();
  FUN_1000_9aae();
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_72c1();
  *(undefined1 *)0x32d3 = 4;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72c1();
  *(undefined1 *)0x32d3 = 4;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72c1();
  FUN_1000_9aae();
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_9aae();
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_9aae();
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_78f3();
  FUN_1000_759b();
  FUN_1000_9aae();
  FUN_1000_c5f4();
  FUN_1000_c6b3();
  FUN_1000_74c6();
  FUN_1000_72c1();
  FUN_1000_72a7();
  *(undefined2 *)0x32a8 = 0x70f;
  return;
}



/* 1000:ddbb  FUN_1000_ddbb  892 bytes, 1 callers */

void __cdecl16near FUN_1000_ddbb(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  bool bVar6;
  uint local_2;
  
  puVar4 = (undefined2 *)0x267b;
  puVar5 = (undefined2 *)&DAT_0000_3e20;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar2 = *puVar1;
  }
  FUN_1000_5efe();
  iVar3 = 0xb;
  do {
    FUN_1000_9859();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_1000_5efe();
  iVar3 = 2;
  do {
    FUN_1000_9859();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_1000_753b();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_729a();
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_c6ad();
  FUN_1000_c612();
  FUN_1000_9aae();
  local_2 = 0x60;
  do {
    FUN_1000_c79d();
    *(undefined2 *)0x34e0 = 0;
    *(undefined1 *)0x32d3 = 0x10;
    FUN_1000_72a7();
    FUN_1000_98a0();
    FUN_1000_98a0();
    FUN_1000_98a0();
    FUN_1000_98a0();
    FUN_1000_9aa6();
    FUN_1000_72ad();
    *(undefined1 *)0x32d3 = 0x10;
    FUN_1000_72a7();
    FUN_1000_98a0();
    FUN_1000_98a0();
    FUN_1000_98a0();
    FUN_1000_9aa6();
    FUN_1000_72ad();
    *(undefined2 *)0x34dc = 0x10;
    *(undefined2 *)0x34e0 = 1;
    FUN_1000_9aae();
    FUN_1000_c79d();
    *(undefined2 *)0x34e0 = 0;
    *(undefined1 *)0x32d3 = 0x10;
    FUN_1000_72a7();
    FUN_1000_98a0();
    FUN_1000_98a0();
    FUN_1000_98a0();
    FUN_1000_9aa6();
    FUN_1000_72ad();
    *(undefined1 *)0x32d3 = 0x10;
    FUN_1000_72a7();
    FUN_1000_98a0();
    FUN_1000_98a0();
    FUN_1000_9aa6();
    FUN_1000_72ad();
    *(undefined2 *)0x34dc = 0x10;
    *(undefined2 *)0x34e0 = 1;
    FUN_1000_9aae();
    bVar6 = 0x1f < local_2;
    local_2 = local_2 - 0x20;
  } while (bVar6);
  FUN_1000_c7b5();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  FUN_1000_9aae();
  FUN_1000_c5f4();
  FUN_1000_c6b3();
  FUN_1000_74c6();
  FUN_1000_72c1();
  FUN_1000_72a7();
  return;
}



/* 1000:e137  FUN_1000_e137  516 bytes, 1 callers */

void __cdecl16near FUN_1000_e137(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined2 *puVar8;
  int iVar9;
  undefined2 *puVar10;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 uVar11;
  undefined4 uVar12;
  
  FUN_1000_5efe();
  iVar6 = 4;
  do {
    FUN_1000_9859();
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_1000_5ee4();
  puVar8 = (undefined2 *)0x0;
  uVar7 = 0xa800;
  do {
    uVar5 = uVar7;
    puVar10 = (undefined2 *)0x0;
    for (iVar6 = 4000; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar2 = *puVar1;
    }
    uVar4 = uVar5 + 0x800;
    uVar7 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar7 = uVar5 + 0x2800, uVar4 < 0xe000));
  FUN_1000_5ee4();
  bVar3 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar3 ^ 1;
  out(0xa6,bVar3 ^ 1);
  puVar8 = (undefined2 *)0x0;
  uVar7 = 0xa800;
  do {
    uVar5 = uVar7;
    puVar10 = (undefined2 *)0x0;
    for (iVar6 = 4000; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar2 = *puVar1;
    }
    uVar4 = uVar5 + 0x800;
    uVar7 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar7 = uVar5 + 0x2800, uVar4 < 0xe000));
  bVar3 = *(byte *)0x3482;
  uVar11 = 0;
  *(byte *)0x3482 = bVar3 ^ 1;
  out(0xa6,bVar3 ^ 1);
  do {
    do {
      FUN_1000_6c3f();
      FUN_1000_687e();
    } while ((bool)uVar11);
    FUN_1000_6f4b();
    FUN_1000_68a0();
  } while ((bool)uVar11);
  FUN_1000_c6fa();
  FUN_1000_99ef();
  FUN_1000_c6ad();
  puVar8 = (undefined2 *)0x252b;
  puVar10 = (undefined2 *)&DAT_0000_3e20;
  for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar2 = puVar10;
    puVar10 = puVar10 + 1;
    puVar1 = puVar8;
    puVar8 = puVar8 + 1;
    *puVar2 = *puVar1;
  }
  *(undefined1 *)0x34d6 = 0xff;
  FUN_1000_9aae();
  uVar7 = 1;
  do {
    FUN_1000_e33b();
  } while (!(bool)uVar11);
  uVar12 = FUN_1000_e33b();
  FUN_1000_99ef((int)uVar12,uVar7,(int)((ulong)uVar12 >> 0x10));
  do {
    uVar5 = FUN_1000_e33b();
  } while (99 < uVar5);
  iVar6 = uVar7 - (uVar7 >> 2);
  do {
    FUN_1000_e350();
  } while (iVar6 != 0);
  do {
    uVar7 = FUN_1000_e33b();
  } while (0x9f < uVar7);
  FUN_1000_9aa6();
  FUN_1000_c6fa();
  FUN_1000_c6d1();
  *(undefined2 *)0xd276 = (undefined *)&DAT_0000_1720;
  *(undefined2 *)&DAT_0000_d27a = 0;
  do {
    iVar9 = 0x3a3a;
    iVar6 = 6;
    bVar3 = 0x80;
    do {
      bVar3 = bVar3 & *(byte *)(iVar9 + 0x1f);
      iVar9 = iVar9 + 0x20;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  } while (bVar3 == 0);
  FUN_1000_c79d();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_c7b5();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_9aae();
  FUN_1000_c79d();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_c7b5();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_9aae();
  FUN_1000_c79d();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_c7b5();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_9aae();
  FUN_1000_c79d();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_c7b5();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_9aae();
  FUN_1000_c5f4();
  FUN_1000_c6fa();
  FUN_1000_c6b3();
  FUN_1000_72c1();
  FUN_1000_72a7();
  FUN_1000_74c6();
  FUN_1000_9a0d();
  return;
}



/* 1000:e33b  FUN_1000_e33b  21 bytes, 1 callers */

undefined3 __cdecl16near FUN_1000_e33b(void)

{
  int iVar1;
  char extraout_DL;
  char cVar2;
  char extraout_DH;
  int in_BX;
  undefined2 unaff_DS;
  
  FUN_1000_9aa6();
  *(undefined1 *)0x32d3 = 1;
  iVar1 = FUN_1000_c6fa();
  cVar2 = extraout_DL + -1;
  if (cVar2 == '\0') {
    in_BX = in_BX + 1;
    cVar2 = extraout_DH;
  }
  return CONCAT12(cVar2,iVar1 - in_BX);
}



/* 1000:e350  FUN_1000_e350  21 bytes, 1 callers */

undefined3 __cdecl16near FUN_1000_e350(void)

{
  int iVar1;
  char extraout_DL;
  char cVar2;
  char extraout_DH;
  int in_BX;
  undefined2 unaff_DS;
  
  FUN_1000_9aa6();
  *(undefined1 *)0x32d3 = 1;
  iVar1 = FUN_1000_c6fa();
  cVar2 = extraout_DL + -1;
  if (cVar2 == '\0') {
    in_BX = in_BX + -1;
    cVar2 = extraout_DH;
  }
  return CONCAT12(cVar2,iVar1 + in_BX);
}



/* 1000:e365  FUN_1000_e365  55 bytes, 1 callers */

undefined4 __cdecl16near FUN_1000_e365(void)

{
  byte *pbVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  int extraout_DX;
  int iVar3;
  byte *pbVar4;
  undefined2 unaff_DS;
  undefined1 uVar5;
  
  uVar5 = 0;
  FUN_1000_6c3f();
  FUN_1000_6d3a();
  iVar3 = extraout_DX;
  if (!(bool)uVar5) {
    iVar2 = *(int *)(*(int *)0x3e94 + 0x1c);
    pbVar4 = (byte *)0x0;
    iVar3 = 0;
    do {
      pbVar1 = pbVar4;
      pbVar4 = pbVar4 + 1;
      iVar3 = iVar3 + (uint)*pbVar1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar3 = iVar3 - *(int *)(*(int *)0x3e94 + 0x12);
  }
  *(int *)0x347e = iVar3;
  return CONCAT22(in_DX,in_AX);
}


