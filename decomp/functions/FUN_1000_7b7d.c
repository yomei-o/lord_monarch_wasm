/* 1000:7b7d */

/* WARNING: Control flow encountered bad instruction data */

undefined2 FUN_1000_7b7d(void)

{
  int iVar1;
  byte bVar2;
  int in_CX;
  uint in_BX;
  uint uVar3;
  int iVar4;
  int *unaff_SI;
  uint unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar5;
  
  do {
    iVar4 = -1;
    uVar3 = in_BX;
    do {
      iVar1 = *unaff_SI;
      unaff_SI[2] = iVar4 - iVar1;
      in_BX = (uint)(((ulong)((unaff_SI[1] & 0xffU) * 10 + ((uint)unaff_SI[1] >> 8)) *
                     (ulong)(uint)(iVar4 - iVar1)) / (ulong)unaff_DI);
      unaff_SI[3] = in_BX;
      unaff_SI[4] = 0;
      iVar4 = in_BX - uVar3;
      if (in_BX < uVar3) {
        unaff_SI[4] = -1;
        iVar4 = -iVar4;
      }
      unaff_SI[5] = iVar4;
      unaff_SI = unaff_SI + 6;
      in_CX = in_CX + -1;
      if (in_CX == 0) {
        bVar5 = *(uint *)0xce70 < 0x33;
        if ((*(uint *)0xce70 == 0x33) && (bVar5 = false, *unaff_SI != 0)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        bVar2 = (byte)iVar4 + 0xaf;
        *(undefined1 *)((int)unaff_SI + in_BX + 0x62aa) = 0;
        return CONCAT11((char)((uint)iVar4 >> 8),
                        bVar2 + bVar5 + '\x12' + (0x50 < (byte)iVar4 || CARRY1(bVar2,bVar5)));
      }
      iVar4 = in_BX + 0xc80;
      uVar3 = in_BX;
    } while (in_BX < 0xf380);
  } while( true );
}


