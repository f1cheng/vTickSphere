# vTickSphere
os over x86 architecture, drive from one to one, lifting little by little.
```  
bootloader stage1 & stage2 + kernel:
framework: 
  print, heap, paging, gdt, isr, task switch (within kernel for poc only),
  next: syscall(allow for user mode inject into kernel mode for the permission),
        user mode task creation then context switch from kernel->user->kernel...
        kernel/user mode permission isolation: paging for user and kernel mode, gdt for user code/data, kernel code/data.
        simple file system in disk and memory layout for the files structure.   
```

# guide
## build
```
make
```

## run
```
qemu-system-i386 -drive format=raw,file=disk.img -vnc 172.23.245.135:5901

```

## ui
```
To check exact port used by qemu process via netstat -lntup in server,
e.g
netstat -lntup
tcp        0      0 172.23.245.135:11801    0.0.0.0:*               LISTEN      1289/qemu-system-i3

Then in client as RealVNC Viewer, login via:
121.43.133.208:11801

```

![prompt for entering kernel](image/enter_kernel.png "enter_kernel")

![prompt for task switch](image/task-switch.png "switch tasks")

![prompt for qemu-gdb](image/qemu-gdb.png "qemu gdb")


