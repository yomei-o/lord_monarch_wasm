/* 1000:919f */

void __cdecl16near FUN_1000_919f(void)

{
  undefined1 uVar1;
  int iVar2;
  int in_DX;
  undefined1 *unaff_SI;
  undefined1 *unaff_DI;
  undefined1 *puVar3;
  undefined2 unaff_DS;
  
  *unaff_DI = *unaff_SI;
  uVar1 = unaff_SI[1];
  puVar3 = unaff_DI;
  for (iVar2 = in_DX; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = uVar1;
  }
  *puVar3 = unaff_SI[2];
  *unaff_DI = unaff_SI[0x30];
  uVar1 = unaff_SI[0x31];
  puVar3 = unaff_DI;
  for (iVar2 = in_DX; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = uVar1;
  }
  *puVar3 = unaff_SI[0x32];
  *unaff_DI = unaff_SI[0x60];
  uVar1 = unaff_SI[0x61];
  puVar3 = unaff_DI;
  for (iVar2 = in_DX; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = uVar1;
  }
  *puVar3 = unaff_SI[0x62];
  *unaff_DI = unaff_SI[0x90];
  uVar1 = unaff_SI[0x91];
  for (; unaff_DI = unaff_DI + 1, in_DX != 0; in_DX = in_DX + -1) {
    *unaff_DI = uVar1;
  }
  *unaff_DI = unaff_SI[0x92];
  return;
}


