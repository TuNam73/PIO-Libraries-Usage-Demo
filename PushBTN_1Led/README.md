## Bài toán 
- Phần cứng: Một nút bấm nhả (push button) và một đèn LED
- Chương trình có các chức năng sau:
    + Bấm nút một lần (single click) để bật/tắt LED (đảo trạng thái). 
    + Nhấn giữ >2s (hold) thì LED sẽ chuyển sang trạng thái nhấp nháy liên tục (blink 1000ms một lần)
    + Nhấn 2 lần liên tiếp (thời gian cách nhau không quá 300ms) thì LED nhấp nháy liên tục (blink 200ms một lần)
    + Nếu tiếp tục nhấn single click thì LED lại chuyển trạng thái bật/tắt 
    + Lưu ý: khử rung phím bấm 

## Mục đích DEMO
Project này sử dụng hai thư viện được cải tiến từ hai thư viện đã được fork về là PushBTN.h và LED.h:
- `PushBTN.h` Để đọc phím bấm các tình huống khác nhau (single click, hold, double click). Mã chương trình đã có chức năng khử rung (debouncing) phím.
- `LED.h` Cung cấp API sáng sủa để khởi tạo và điều khiển LED (đảo trạng thái - flip, và nháy - blink)
- Việc gom các chức năng đọc phím bấm và điều khiển LED như trên vào các thư viện để có thể tái sử dụng, và giúp mã sáng sủa hơn. Các chức năng như trong yêu cầu xuất hiện rất phổ biến ở hầu hết tất cả các project vi điều khiển. 

