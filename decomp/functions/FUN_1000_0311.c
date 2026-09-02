/* 1000:0311 */

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


