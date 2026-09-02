/* 1000:8ffe */

/* WARNING: Instruction at (ram,0x00018fff) overlaps instruction at (ram,0x00018ffe)
    */

undefined2 FUN_1000_8ffe(void)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  undefined2 uVar4;
  char cVar5;
  undefined2 in_AX;
  undefined2 in_CX;
  int iVar6;
  undefined2 in_DX;
  int in_BX;
  byte unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  undefined1 uStack_9;
  byte bStack_7;
  byte bStack_6;
  
  uVar9 = CONCAT22(in_DX,in_AX);
  iVar6 = (uint)(byte)((byte)((uint)in_CX >> 8) ^ (byte)in_AX) << 8;
  uVar4 = *(undefined2 *)(unaff_SI + 0xf);
  do {
    if ((byte)((byte)((uint)iVar6 >> 8) & (byte)uVar9) == 0) goto LAB_1000_9018;
    uVar7 = *(char *)0x32d0 == '\0';
    if ((bool)uVar7) {
      uVar7 = 2;
      goto LAB_1000_901a;
    }
    uVar9 = FUN_1000_8f18();
  } while (!(bool)uVar7);
  do {
    uVar8 = uVar7;
    uVar9 = FUN_1000_8f18();
    uVar7 = 1;
  } while ((bool)uVar8);
LAB_1000_9018:
  uVar7 = 0x14;
LAB_1000_901a:
  *(undefined1 *)0x32d0 = uVar7;
  pcVar1 = (char *)(in_BX + unaff_SI + 0x10);
  bStack_7 = (byte)uVar9;
  *pcVar1 = *pcVar1 - bStack_7;
  out((int)((ulong)uVar9 >> 0x10),bStack_7);
  *(char *)(unaff_SI + 0x13) = *(char *)(unaff_SI + 0x13) + '\x01';
  bStack_6 = (byte)((ulong)uVar9 >> 8);
  if (((byte)((uint)uVar4 >> 8) & bStack_7) == 0) {
    uStack_9 = *(undefined1 *)0x32ce;
  }
  else {
    pbVar2 = (byte *)(in_BX + unaff_SI);
    bVar3 = *pbVar2;
    *pbVar2 = *pbVar2 - bStack_6;
    *(char *)(unaff_DI + 0x7402) =
         *(char *)(unaff_DI + 0x7402) + (char)((ulong)uVar9 >> 0x18) + (bVar3 < bStack_6);
    bStack_7 = (byte)((uint)unaff_ES >> 8);
    bStack_6 = unaff_BP;
  }
  do {
    cVar5 = FUN_1000_8f0d();
  } while (cVar5 != '\0');
  *(undefined1 *)0x32ce = uStack_9;
  return CONCAT11(bStack_6,bStack_7);
}


