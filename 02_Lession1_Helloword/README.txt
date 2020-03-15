OK, h mình sẽ bắt đầu nhé em. Bài đầu tiên mình sẽ làm quen với những chức căn bản nhất.
TOOL 

Do STM đã phát triển công cụ MXSTM32Cube phải nói là rất tuyệt vời nên anh muốn bám sát 
theo tool này trong quá trình code. Code theo kiểu cũ không hấp dẫn bằng :D 

Bài 1: Hello word
- Yêu cầu: STM32 in 1 dòng "Helloword" qua UART-USB, hiển thị dòng này lên terminal 

:'( Anh biết bài 1 rất cùi bắp nhưng mình cứ đi từng bước cho ấm chân em nhé. 

Bước 1: Mở Tool MXCube lên. 
Bước 2: Khi tool vừa mở lên, nó sẽ hỏi em là muốn bắt đầu từ MCU hay board :( Chọn 
Board em nhé.
Bước 3: Board của mình là NucleoL4 cho nên bên mục "Board Filter" chỗ "MCU Series" 
chọn STM32L4+, chỗ Type chọn "Nucleo144". Lúc này bên BoardList em sẽ dễ tìm thấy 
NUCLEO-L4R5ZI ( Xem anh1 nếu gặp vấn đề, Update: Trong ảnh anh chọn nhầm sang
NUCLEO-L4R5ZI-P :v Board mình là NUCLEO-L4R5ZI nhé )
Bước 4: Sau khi chọn Board, tool sẽ hỏi em muốn cài đặt mọi thứ theo mặc định ko 
-> NO
Bước 5: Tại mục "System Core" -> "RCC" -> Chọn Crystal cho HSE và LSE (anh2)
Bước 6: Tại mục "Connectivity" -> "LPUART1". Mode chọn Asynchronous 
		+ Baudrate 115200
		+ Word Length : 8 bits ( including Parity )
		+ Parity : None 
		+ Stop Bits : 1
Bước 6: Chọn chân 
		+ Search "LPUART" -> Em sẽ thấy 2 chân PG8 PG7 nhấp nháy, bật 2 chân đó 
		  lên thành LPUART1_TX LPUART1_RX
		+ Các chân còn lại để nguyên.
Bước 7: Tại "Clock Configuration" -> quất HCLK lên 120Mhz. Ấn enter để nó tự tính lại.
Bước 8: Tại "Project Manager" 
		*Mục Project
		+ Bỏ dấu tick "Do not generate the main()" -> Hàm main nó gen ổn.
		+ IDE -> MDK-ARM V5 
		+ Heap Size 0x2000
		+ Stack Size 0x4000 ( Đoạn heap-stack chỉnh lại sau)
		+ chỉnh đường dẫn đến cái FW_L4 mình đã tải
		*Mục Code Generator 
		+ Tick Enable Full Assert
		+ Tick Set all free pin are analog
Bước 9 : ấn Generate code
Bước 10: Comply code -> Nạp thử ( nhớ chỉnh flash device theo anh5)

Base source đến đây thôi, em tự Hello word nhé. OK thì qua bài tiếp.
