/* 1000:99a0 */

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


