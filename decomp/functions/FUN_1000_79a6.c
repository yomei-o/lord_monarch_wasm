/* 1000:79a6 */

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


