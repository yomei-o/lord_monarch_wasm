/* 1000:4719 */

/* WARNING: Instruction at (ram,0x00014727) overlaps instruction at (ram,0x00014726)
    */

void FUN_1000_4719(int param_1,int param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,
                  undefined2 param_6)

{
  int *piVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  int in_BX;
  int unaff_SI;
  undefined1 *unaff_SS;
  undefined2 unaff_DS;
  undefined1 *in_stack_00000000;
  undefined2 uStack000e;
  
  do {
    uVar2 = *(undefined2 *)(in_BX + unaff_SI);
    in_BX = CONCAT11((char)((uint)param_4 >> 8),(char)param_4 + (char)((uint)param_6 >> 8));
    do {
      uStack000e = 0x472e;
      thunk_FUN_1000_47c8();
      bVar4 = func_0x0001b68c();
    } while ((bVar4 & 0xf) != 0);
    *(undefined2 *)0x3bdc = extraout_DX_00;
    *(undefined1 *)0x3289 = 0x2f;
    param_6 = 0x4712;
    uStack000e = uVar2;
    func_0x0001b778();
    uVar3 = in(extraout_DX);
    *in_stack_00000000 = uVar3;
    piVar1 = (int *)(in_BX + param_1 + 0x7440);
    *piVar1 = *piVar1 - param_2;
    unaff_SI = param_1;
    in_stack_00000000 = unaff_SS;
  } while( true );
}


