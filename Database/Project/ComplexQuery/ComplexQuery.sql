-- Complex Query Scenario
-- แสดง ราคาเฉลี่ยของ hotel ที่อยู่ในจังหวัด กรุงเทพ ที่มี rating มากกว่า 4.0 มา 3 อันดับแรก โดยเรียงจากมากไปน้อย โดยนำข้อมูล rating จาก Review 
-- ที่มี hotelId ตรงกับ hotelId ที่ต้องการหา
SELECT h.name AS HotelName, ROUND(AVG(rt.price),2) AS AveragePrice
FROM Hotel h
JOIN Room ro ON h.hotelId = ro.hotelId
JOIN Review re ON h.hotelId = re.hotelId
JOIN RoomType rt ON ro.typeName = rt.typeName
WHERE h.province = 'Bangkok' AND re.rating > 4.0
GROUP BY h.hotelId, h.name
ORDER BY AVG(rt.price) DESC
LIMIT 3;