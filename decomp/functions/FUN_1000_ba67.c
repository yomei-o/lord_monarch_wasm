/* 1000:ba67 */

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


