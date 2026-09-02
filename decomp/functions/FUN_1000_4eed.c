/* 1000:4eed */

void FUN_1000_4eed(void)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  int in_CX;
  int iVar4;
  undefined2 *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 *puVar5;
  undefined1 *puVar6;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  for (; in_CX != 0; in_CX = in_CX + -1) {
    puVar3 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    puVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    *puVar3 = *puVar1;
  }
  puVar5 = (undefined2 *)0xc632;
  for (iVar4 = 0xb0; iVar4 != 0; iVar4 = iVar4 + -1) {
    puVar3 = puVar5;
    puVar5 = puVar5 + 1;
    puVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    *puVar3 = *puVar1;
  }
  puVar6 = (undefined1 *)0x3eea;
  for (iVar4 = 0x2d; iVar4 != 0; iVar4 = iVar4 + -1) {
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    puVar1 = unaff_SI;
    unaff_SI = (undefined2 *)((int)unaff_SI + 1);
    *puVar2 = *(undefined1 *)puVar1;
  }
  return;
}


