/* 1000:ca4a */

undefined2 __cdecl16near FUN_1000_ca4a(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  uVar3 = FUN_1000_6808();
  if ((bool)in_CF) {
    return uVar3;
  }
  FUN_1000_0ccc();
  FUN_1000_c5f4();
  *(undefined2 *)&DAT_0000_3bc6 = 6;
  FUN_1000_5fe2();
  FUN_1000_0ceb();
  FUN_1000_74c6();
  FUN_1000_026a();
  FUN_1000_99a0();
  FUN_1000_ad56();
  *(undefined2 *)0xc560 = 0;
  *(undefined2 *)0x32e0 = 0;
  *(undefined2 *)0x346a = 0xffff;
  *(undefined2 *)0x346e = 0xffff;
  FUN_1000_cb19();
  FUN_1000_cdf0();
  FUN_1000_d205();
  FUN_1000_d45a();
  FUN_1000_da07();
  FUN_1000_db5b();
  FUN_1000_ddbb();
  FUN_1000_e137();
  FUN_1000_99cc();
  *(undefined2 *)0x32e0 = 1;
  puVar5 = (undefined2 *)&DAT_0000_249b;
  puVar6 = (undefined2 *)&DAT_0000_3e20;
  for (iVar4 = 0x18; iVar4 != 0; iVar4 = iVar4 + -1) {
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    puVar1 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = *puVar1;
  }
  FUN_1000_0ccc();
  *(undefined2 *)0x3bd4 = 0;
  *(undefined2 *)0x3bd6 = 0;
  *(undefined2 *)0xc52c = 0;
  *(undefined2 *)&DAT_0000_32bf = 0;
  *(undefined2 *)0x3bc2 = 0xffff;
  FUN_1000_02c3();
  FUN_1000_bcf4();
  FUN_1000_026a();
  FUN_1000_9355();
  FUN_1000_02e1();
  FUN_1000_02f9();
  FUN_1000_027c();
  FUN_1000_0296();
  FUN_1000_a6a5();
  FUN_1000_5cef();
  FUN_1000_5d0e();
  FUN_1000_96f2();
  FUN_1000_9355();
  FUN_1000_727a();
  FUN_1000_5d0e();
  FUN_1000_9355();
  FUN_1000_727a();
  FUN_1000_4cdd();
  *(undefined2 *)&DAT_0000_3bc6 = 5;
  FUN_1000_5f7e();
  FUN_1000_7c9e();
  FUN_1000_7c9e();
  FUN_1000_4d4a();
  return uVar3;
}


