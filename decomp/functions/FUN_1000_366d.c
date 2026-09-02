/* 1000:366d */

/* WARNING: Instruction at (ram,0x000136b7) overlaps instruction at (ram,0x000136b5)
    */

void FUN_1000_366d(undefined2 param_1,undefined2 param_2)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  int in_DX;
  int in_BX;
  int iVar4;
  int unaff_BP;
  int unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar5;
  bool in_PF;
  undefined4 uVar6;
  int in_stack_00000000;
  
  if (in_PF) {
    bVar3 = (byte)in_stack_00000000 & *(byte *)(unaff_BP + unaff_SI);
    pcVar1 = (char *)(unaff_BP + unaff_SI + 0x22);
    *pcVar1 = *pcVar1 + bVar3;
    pbVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *pbVar2 = bVar3;
code_r0x00013685:
    iVar4 = CONCAT11((char)((uint)in_BX >> 8),(byte)in_BX ^ unaff_DI[in_BX + -0x7e]);
    FUN_1000_98d3();
    FUN_1000_8f5c();
    in(0x22);
    in_BX = CONCAT11((char)((uint)iVar4 >> 8),(char)iVar4 + *(char *)(iVar4 + unaff_SI + 0x293e));
    param_2 = 0x36c3;
    uVar6 = func_0x0001e104();
    in_DX = (int)((ulong)uVar6 >> 0x10);
    bVar3 = ((byte)uVar6 | 0x55) - 0x20;
    in_stack_00000000 = CONCAT11((char)((ulong)uVar6 >> 8),bVar3);
    bVar5 = bVar3 < 0x10;
  }
  else {
    if (in_stack_00000000 == 0) {
      *(undefined2 *)(unaff_DI + in_BX + 0x12a7) = unaff_SS;
      goto code_r0x000136cc;
    }
    bVar5 = in_stack_00000000 == 0;
    if (in_stack_00000000 == 1) {
      in_BX = in_BX + 1;
      if (in_BX == 0) {
        in(0x42);
      }
      goto code_r0x00013685;
    }
  }
  if (bVar5) {
    *(int *)unaff_DI = in_stack_00000000;
    unaff_DI[2] = (byte)in_stack_00000000;
    FUN_1000_8f07();
    return;
  }
code_r0x000136cc:
  *(undefined2 *)(unaff_DI + (in_BX - in_DX) + 0x12a7) = param_2;
  return;
}


