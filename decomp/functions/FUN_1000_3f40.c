/* 1000:3f40 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00013f3e) */

void FUN_1000_3f40(uint param_1)

{
  undefined1 uVar1;
  uint *puVar2;
  byte bVar3;
  uint in_AX;
  int in_DX;
  int unaff_BP;
  undefined2 *unaff_SI;
  undefined1 *unaff_DI;
  uint *puVar4;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar5;
  undefined2 in_stack_00000000;
  
  puVar4 = (uint *)(unaff_DI + 1);
  uVar1 = in(in_DX);
  *unaff_DI = uVar1;
  do {
    if ((in_AX & 0x40) != 0) {
      unaff_SI[-0x30] = unaff_SI[-0x30] + in_DX;
      out(in_DX,(byte)in_AX);
      *(undefined2 *)0x32ee = in_stack_00000000;
      *(uint *)0x32f0 = param_1;
      return;
    }
    if ((in_AX & 2) == 0) {
      if ((in_AX & 4) == 0) {
        if ((in_AX & 8) == 0) {
          if (((in_AX & 1) == 0) || (bVar3 = *(byte *)0x3bee - 2, *(byte *)0x3bee < 2)) {
LAB_1000_3f37:
            out(*unaff_SI,in_DX);
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
        }
        else {
          puVar2 = puVar4;
          puVar4 = puVar4 + 1;
          *puVar2 = in_AX;
          if (&stack0x0000 != (undefined1 *)0xfffc) goto LAB_1000_3f37;
          bVar3 = (byte)in_AX | 1;
          in_stack_00000000 = unaff_SS;
          param_1 = unaff_BP + 1U;
        }
      }
      else {
        if ((*(byte *)0x3bee & 1) == 0) goto LAB_1000_3f37;
        bVar3 = *(byte *)0x3bee & 0xfe;
      }
    }
    else {
      bVar3 = *(char *)0x3bee + 2;
      if (0xd < bVar3) goto LAB_1000_3f37;
    }
    *(byte *)0x3bee = bVar3;
    uVar5 = func_0x0001ba0e();
    in_DX = (int)((ulong)uVar5 >> 0x10);
    in_AX = (uint)uVar5 & 0xff6f;
    swi(4);
    *(uint *)((int)unaff_SI + 0x45) = *(uint *)((int)unaff_SI + 0x45) & unaff_BP + 1U;
  } while( true );
}


