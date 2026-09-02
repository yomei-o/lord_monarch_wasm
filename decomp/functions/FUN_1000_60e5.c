/* 1000:60e5 */

int __cdecl16near FUN_1000_60e5(void)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  int in_AX;
  int iVar4;
  undefined2 *puVar5;
  char *pcVar6;
  undefined2 *puVar7;
  undefined1 *puVar8;
  char *pcVar9;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  int iStack_2;
  
  iStack_2 = in_AX;
  FUN_1000_6c3f();
  iVar4 = *(int *)0x3bc4;
  if ((iVar4 != -1) && (iVar4 != *(int *)0x346a)) {
    *(undefined2 *)0x346a = 0xffff;
    uVar10 = (undefined1 *)0xfffd < &iStack_2;
    uVar11 = &stack0x0000 == (undefined1 *)0x0;
    iStack_2 = iVar4;
    FUN_1000_c492();
    FUN_1000_c449();
    do {
      *(undefined1 *)0x331f = 0x53;
      FUN_1000_687e();
      uVar12 = uVar11;
      if (!(bool)uVar10) {
        FUN_1000_6f4b();
        FUN_1000_68a0();
        uVar12 = uVar11;
        if (!(bool)uVar10) {
          do {
            *(undefined1 *)0x331f = 0x4d;
            FUN_1000_687e();
            uVar12 = uVar11;
            if (!(bool)uVar10) {
              FUN_1000_6f4b();
              FUN_1000_68a0();
              uVar12 = uVar11;
              if (!(bool)uVar10) {
                do {
                  *(undefined1 *)0x331f = 0x4c;
                  FUN_1000_687e();
                  uVar12 = uVar11;
                  if (!(bool)uVar10) {
                    FUN_1000_6f4b();
                    FUN_1000_68a0();
                    uVar12 = uVar11;
                    if (!(bool)uVar10) {
                      puVar5 = (undefined2 *)0x7ca0;
                      puVar7 = (undefined2 *)&DAT_0000_3c20;
                      for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
                        puVar3 = puVar7;
                        puVar7 = puVar7 + 1;
                        puVar1 = puVar5;
                        puVar5 = puVar5 + 1;
                        *puVar3 = *puVar1;
                      }
                      puVar7 = (undefined2 *)0xc632;
                      for (iVar4 = 0xb0; iVar4 != 0; iVar4 = iVar4 + -1) {
                        puVar3 = puVar7;
                        puVar7 = puVar7 + 1;
                        puVar1 = puVar5;
                        puVar5 = puVar5 + 1;
                        *puVar3 = *puVar1;
                      }
                      puVar8 = (undefined1 *)0x3eea;
                      for (iVar4 = 0x2d; iVar4 != 0; iVar4 = iVar4 + -1) {
                        puVar2 = puVar8;
                        puVar8 = puVar8 + 1;
                        puVar1 = puVar5;
                        puVar5 = (undefined2 *)((int)puVar5 + 1);
                        *puVar2 = *(undefined1 *)puVar1;
                      }
                      pcVar6 = (char *)0xc642;
                      pcVar9 = (char *)0x3485;
                      iVar4 = 5;
                      do {
                        *pcVar9 = *pcVar6 + -0x10;
                        pcVar6 = pcVar6 + 0x10;
                        uVar10 = (char *)0xfff6 < pcVar9 + 1;
                        pcVar9 = pcVar9 + 10;
                        uVar11 = pcVar9 == (char *)0x0;
                        iVar4 = iVar4 + -1;
                      } while (iVar4 != 0);
                      FUN_1000_c492();
                      FUN_1000_c449();
                      do {
                        *(undefined1 *)0x3313 = 0x4d;
                        *(undefined1 *)0x3314 = 0x20;
                        FUN_1000_687e();
                        uVar12 = uVar11;
                        if (!(bool)uVar10) {
                          FUN_1000_6f4b();
                          FUN_1000_68a0();
                          uVar12 = uVar11;
                          if (!(bool)uVar10) {
                            do {
                              *(undefined1 *)0x3313 = 0x4c;
                              *(undefined1 *)0x3314 = 0x31;
                              FUN_1000_687e();
                              uVar12 = uVar11;
                              if (!(bool)uVar10) {
                                FUN_1000_6f4b();
                                FUN_1000_68a0();
                                uVar12 = uVar11;
                                if (!(bool)uVar10) {
                                  do {
                                    *(undefined1 *)0x3313 = 0x4c;
                                    *(undefined1 *)0x3314 = 0x32;
                                    FUN_1000_687e();
                                    uVar12 = uVar11;
                                    if (!(bool)uVar10) {
                                      FUN_1000_6f4b();
                                      FUN_1000_68a0();
                                      uVar12 = uVar11;
                                      if (!(bool)uVar10) {
                                        do {
                                          *(undefined1 *)0x3313 = 0x4c;
                                          *(undefined1 *)0x3314 = 0x33;
                                          FUN_1000_687e();
                                          uVar12 = uVar11;
                                          if (!(bool)uVar10) {
                                            FUN_1000_6f4b();
                                            FUN_1000_68a0();
                                            uVar12 = uVar11;
                                            if (!(bool)uVar10) {
                                              do {
                                                *(undefined1 *)0x3313 = 0x4c;
                                                *(undefined1 *)0x3314 = 0x34;
                                                FUN_1000_687e();
                                                uVar12 = uVar11;
                                                if (!(bool)uVar10) {
                                                  FUN_1000_6f4b();
                                                  FUN_1000_68a0();
                                                  uVar12 = uVar11;
                                                  if (!(bool)uVar10) {
                                                    *(undefined2 *)0x346a = *(undefined2 *)0x3bc4;
                                                    return iStack_2;
                                                  }
                                                }
                                                FUN_1000_6cb5();
                                                uVar11 = 1;
                                              } while ((bool)uVar12);
                                              return iStack_2;
                                            }
                                          }
                                          FUN_1000_6cb5();
                                          uVar11 = 1;
                                        } while ((bool)uVar12);
                                        return iStack_2;
                                      }
                                    }
                                    FUN_1000_6cb5();
                                    uVar11 = 1;
                                  } while ((bool)uVar12);
                                  return iStack_2;
                                }
                              }
                              FUN_1000_6cb5();
                              uVar11 = 1;
                            } while ((bool)uVar12);
                            return iStack_2;
                          }
                        }
                        FUN_1000_6cb5();
                        uVar11 = 1;
                      } while ((bool)uVar12);
                      return iStack_2;
                    }
                  }
                  FUN_1000_6cb5();
                  uVar11 = 1;
                } while ((bool)uVar12);
                return iStack_2;
              }
            }
            FUN_1000_6cb5();
            uVar11 = 1;
          } while ((bool)uVar12);
          return iStack_2;
        }
      }
      FUN_1000_6cb5();
      uVar11 = 1;
    } while ((bool)uVar12);
    return iStack_2;
  }
  return iStack_2;
}


