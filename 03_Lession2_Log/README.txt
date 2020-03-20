Hôm nay ko phải cuối tuần nên anh soạn bài chậm em đừng giận nhé.  =)) 

Hôm nay vẫn chưa đi vào RTOS, anh định sẽ dẫn em đi giải 1 số vấn đề thực tế, 
mà khi đó RTOS sẽ hiệu quả hơn là bare-mental. Hi vọng em ko chán =)). Yêu em.

Bài số 2 mà anh muốn dẫn em đi là tạo ra 1 cái thư viện lưu trữ log. 
Nghe thì có vẻ củ chuối nhưng lấy Log, đọc Log, dùng Log để tìm ra vấn đề là kĩ 
năng sống còn của nghề. Không sớm hay muộn anh tin em cũng sẽ phải đối mặt với việc 
ko dc dùng debuger để debug nên việc có thêm kĩ năng debug như này anh nghĩ sẽ cần thiết.

1/ Bước 1 : tập merger
- Em sync code anh về, mở project lên chạy thử, check xem mọi thứ ok ko.
- Merger qua code của em.

2/ Chỉnh sửa
- Mèo lấy code mới về, theo lý thì nó đã build được rồi
- Mèo comply rồi nạp thử. Log sẽ hiện theo cú pháp sau 
[Type] Context
- Type : debug/infor/warning/error
- Context : Nội dung log


Trong code thì mèo để ý: 
Folder : User/Config
	chứa những #define dùng để config project theo ý mình
	VD em muốn bật hết log thì #define LOG_ON, muốn tắt thì comment dòng đó lại
	VD trong code khi em muốn debug em sẽ để rất nhiều log, những log này là log debug
		khi đó em dùng hàm LOG_DEBUG. Có những LOG dùng để cảnh báo LOG_WARNING, log báo lỗi
		LOG_ERROR, Log thông báo LOG_INFOR. Trừ LOG_DEBUG các log còn lại thường ko nhiều, 
		khi release đa phần em sẽ tắt log debug đi -> #defien DEBUG false
	
Util/Log : Util là folder dùng để sp tính năng chính của project, dc xài chung bởi nhiều thành phần 
	
Bài 1 : Giờ anh cần em chỉnh code lại để log in ra có cú pháp sau 

[Type][File:Line] Context
- Type : debug/infor/warning/error
- File : tên file chứa đoạn code log
- Line : Log ở dòng nào trong file
- Context : Nội dung log

Bài 2:  Với log error, anh muốn nếu như cờ DEBUG bật thì em treo luôn chương trình, không cho thoát ra khỏi dòng LOG_ERROR
		Nếu cờ DEBUG tắt thì em reset chương trình 
		
Tạm thời 2 bài nhé, anh phần bổ thời gian kém nên ra bài chậm, sẽ tiến bộ. Yêu em.

Anh đã update đáp án, em xem file diff nhé. <3 em 
