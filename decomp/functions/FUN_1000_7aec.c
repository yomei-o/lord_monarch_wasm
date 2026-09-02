/* 1000:7aec */

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_1000_7aec(void)

{
  byte *pbVar1;
  int iVar2;
  ulong uVar3;
  char cVar4;
  undefined2 in_AX;
  int iVar5;
  undefined2 in_DX;
  uint uVar6;
  byte bVar8;
  undefined2 uVar7;
  int in_BX;
  uint unaff_BP;
  int iVar9;
  undefined1 *unaff_SI;
  int *piVar10;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar11;
  
  cVar4 = (char)in_AX + '\x01';
  iVar9 = CONCAT11((char)((uint)in_AX >> 8),cVar4);
  if (cVar4 == '\0') {
    uVar6 = CONCAT11((char)((uint)in_DX >> 8),0x60);
    if ((((uVar6 & 0x2000) == 0) && (uVar6 = 0, 999 < *(uint *)(unaff_SI + 6))) &&
       (uVar6 = 0x20, 9999 < *(uint *)(unaff_SI + 6))) {
      uVar6 = 0x40;
    }
    uVar6 = CONCAT11(*(byte *)0x3be8 >> 1,(byte)uVar6 | unaff_SI[0xc] << 3) & 0x1ff;
    uVar6 = CONCAT11(unaff_SI[1],(byte)uVar6 | (byte)(uVar6 >> 8)) & 0x6ff;
    bVar8 = (byte)(uVar6 >> 8);
    return CONCAT22(CONCAT11(bVar8,(byte)uVar6 | bVar8),iVar9);
  }
  *(char *)0xb2c3 = *(char *)0xb2c3 + cVar4;
  piVar10 = (int *)(unaff_SI + 1);
  *unaff_DI = *unaff_SI;
  uVar7 = CONCAT11((char)((uint)(in_BX + (int)piVar10) >> 8) +
                   *(char *)((int)piVar10 + unaff_BP + 0x7ba0),
                   (char)(undefined1 *)(in_BX + (int)piVar10));
  pbVar1 = (byte *)((int)piVar10 + unaff_BP + 0x10);
  bVar11 = false;
  *pbVar1 = *pbVar1 | 0xbe;
  iVar5 = *(int *)0xce70;
  if (iVar5 != 0) {
    piVar10 = (int *)0xcc00;
    uVar6 = 0;
    do {
      iVar9 = uVar6 + 0xc80;
      if (0xf37f < uVar6) {
        iVar9 = -1;
      }
      iVar2 = *piVar10;
      piVar10[2] = iVar9 - iVar2;
      uVar3 = (ulong)((piVar10[1] & 0xffU) * 10 + ((uint)piVar10[1] >> 8)) *
              (ulong)(uint)(iVar9 - iVar2);
      unaff_BP = (uint)(uVar3 / 1000);
      uVar7 = (undefined2)(uVar3 % 1000);
      piVar10[3] = unaff_BP;
      piVar10[4] = 0;
      iVar9 = unaff_BP - uVar6;
      if (unaff_BP < uVar6) {
        piVar10[4] = -1;
        iVar9 = -iVar9;
      }
      piVar10[5] = iVar9;
      piVar10 = piVar10 + 6;
      iVar5 = iVar5 + -1;
      uVar6 = unaff_BP;
    } while (iVar5 != 0);
    bVar11 = *(uint *)0xce70 < 0x33;
    if ((*(uint *)0xce70 == 0x33) && (bVar11 = false, *piVar10 != 0)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  bVar8 = (byte)iVar9 + 0xaf;
  *(undefined1 *)((int)piVar10 + unaff_BP + 0x62aa) = 0;
  return CONCAT22(uVar7,CONCAT11((char)((uint)iVar9 >> 8),
                                 bVar8 + bVar11 + '\x12' +
                                 (0x50 < (byte)iVar9 || CARRY1(bVar8,bVar11))));
}


