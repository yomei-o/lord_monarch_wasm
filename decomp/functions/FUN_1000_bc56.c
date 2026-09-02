/* 1000:bc56 */

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


