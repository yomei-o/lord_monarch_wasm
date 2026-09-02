/* 1000:3332 */

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


