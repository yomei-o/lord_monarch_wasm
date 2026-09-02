/* 1000:4040 */

undefined4 __cdecl16near FUN_1000_4040(void)

{
  undefined2 in_AX;
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined2 in_DX;
  char cVar5;
  uint uVar4;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  bool bVar6;
  
  iVar1 = FUN_1000_aa93();
  if (iVar1 == 0) {
    FUN_1000_4947();
    return CONCAT22(in_DX,in_AX);
  }
  if (iVar1 == 1) {
    cVar5 = (char)((uint)*(undefined2 *)(unaff_SI + 8) >> 8);
    cVar3 = (char)*(undefined2 *)(unaff_SI + 8);
    if ((((cVar5 != '\0') && (cVar5 != '/')) && (cVar3 != '\0')) && (cVar3 != '/')) {
      FUN_1000_9b34();
      if (((undefined *)&DAT_0000_d27e)[in_BX] == 'z') {
        uVar4 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] + 0xff;
        uVar2 = *(uint *)(unaff_SI + 6) >> 4;
        if (uVar4 < uVar2) {
          uVar2 = uVar4;
        }
        bVar6 = CARRY2(uVar2,uVar2);
        FUN_1000_abc7();
        if (!bVar6) {
          iVar1 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] - uVar2;
          cVar3 = (char)iVar1;
          if ((byte)((undefined *)&DAT_0000_d27f)[in_BX] < uVar2 || iVar1 == 0) {
            *(uint *)((undefined *)&DAT_0000_d27e + in_BX) = CONCAT11(-cVar3,0x20);
            FUN_1000_a7e9();
            FUN_1000_484a();
LAB_1000_412f:
            FUN_1000_9ae1();
            return CONCAT22(in_DX,in_AX);
          }
          ((undefined *)&DAT_0000_d27f)[in_BX] = cVar3;
LAB_1000_4139:
          FUN_1000_9ae1();
          return CONCAT22(in_DX,in_AX);
        }
      }
      else {
        if (0x2f < (byte)(((undefined *)&DAT_0000_d27e)[in_BX] - 0x30)) goto LAB_1000_414d;
        uVar4 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] + 1;
        uVar2 = *(uint *)(unaff_SI + 6) >> 4;
        if (uVar4 < uVar2) {
          uVar2 = uVar4;
        }
        bVar6 = false;
        if (*(int *)0x347e == 0) {
          bVar6 = (long)(int)((long)(int)uVar2 * 0x1e) != (long)(int)uVar2 * 0x1e;
        }
        FUN_1000_abc7();
        if (!bVar6) {
          cVar3 = ((undefined *)&DAT_0000_d27f)[in_BX] - (char)uVar2;
          if ((byte)((undefined *)&DAT_0000_d27f)[in_BX] < uVar2) {
            *(uint *)((undefined *)&DAT_0000_d27e + in_BX) = CONCAT11(-cVar3,0x20);
            FUN_1000_a7e9();
            FUN_1000_484a();
            goto LAB_1000_412f;
          }
          ((undefined *)&DAT_0000_d27f)[in_BX] = cVar3;
          goto LAB_1000_4139;
        }
      }
      return CONCAT22(in_DX,in_AX);
    }
  }
LAB_1000_414d:
  return CONCAT22(in_DX,in_AX);
}


