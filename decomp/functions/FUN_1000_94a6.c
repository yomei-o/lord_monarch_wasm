/* 1000:94a6 */

void FUN_1000_94a6(undefined2 param_1,byte *param_2)

{
  byte *pbVar1;
  code *pcVar2;
  int in_AX;
  int in_CX;
  byte in_DL;
  byte extraout_DH;
  undefined2 extraout_DX;
  int in_BX;
  undefined2 unaff_DS;
  byte in_stack_0000000e;
  
  *(byte *)(in_BX + in_AX) = *(byte *)(in_BX + in_AX) & in_DL;
  if (in_CX != 0) {
    FUN_1000_6095();
    func_0x0001389c();
    *(byte *)(in_BX + in_AX) = *(byte *)(in_BX + in_AX) & (byte)((uint)extraout_DX >> 8);
    pbVar1 = (byte *)(in_BX + in_AX + 8);
    *pbVar1 = *pbVar1 & (byte)extraout_DX;
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *(byte *)(in_BX + 0x5675) = *(byte *)(in_BX + 0x5675) & in_DL;
  FUN_1000_60a5();
  FUN_1000_38a8();
  *(byte *)(in_BX + 0x5675) = *(byte *)(in_BX + 0x5675) & extraout_DH;
  *param_2 = *param_2 | in_stack_0000000e;
  return;
}


