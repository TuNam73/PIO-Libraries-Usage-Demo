## Bài toán 
- Phần cứng: Một nút bấm nhả (push button) và một đèn LED
- Chương trình có các chức năng sau:
    + Khi double click sẽ chuyển chế độ điều khiển giữa hai LED (LED1 và LED2)
    + Khi single click sẽ bật tắt cái LED đang được điều khiển (LED1 hoặc 2, đã chọn ở bước 1)
    + Khi giữ nút nhấn sẽ làm cái LED đang được điều khiển nhấp nháy 200ms một lần.
    + Lưu ý: khử rung phím bấm 

## Mục đích DEMO
Project này sử dụng hai thư viện được cải tiến từ hai thư viện được fork về là PushBTN.h và LED.h:
- `PushBTN.h` Để đọc phím bấm các tình huống khác nhau (single click, hold, double click). Mã chương trình đã có chức năng khử rung (debouncing) phím.
- `LED.h` Cung cấp API sáng sủa để khởi tạo và điều khiển LED (đảo trạng thái - flip, và nháy - blink)
- Việc gom các chức năng đọc phím bấm và điều khiển LED như trên vào các thư viện để có thể tái sử dụng, và giúp mã sáng sủa hơn. Các chức năng như trong yêu cầu xuất hiện rất phổ biến ở hầu hết tất cả các project vi điều khiển. 

