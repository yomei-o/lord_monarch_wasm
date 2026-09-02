/* 1000:be03 */

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


