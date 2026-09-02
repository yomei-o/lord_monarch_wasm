/* 1000:b876 */

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


