package logic;

import java.util.ArrayList;

public class Order {
	private ArrayList<OrderItem> orderItemList;
	private static int totalOrderCount = 0;
	private int orderNumber;
	
	public Order() {
		orderItemList = new ArrayList<>();
		orderNumber = totalOrderCount;
		totalOrderCount++;

	}

	public OrderItem addItem(Item item, int amount) {
		for(OrderItem o : orderItemList){
			if(o.getItem() == item){
				o.increaseItemAmount(amount);
				return o;
			}
		}
		OrderItem newOrderItem = new OrderItem(item,amount);
		orderItemList.add(newOrderItem);
		return newOrderItem;
	}

	public int calculateOrderTotalPrice() {
		int total = 0;
		for(OrderItem o : orderItemList){
			total+= o.calculateTotalPrice();
		}
		return total;
	}

	public static int getTotalOrderCount() {
		return totalOrderCount;
	}
	
	public static void resetTotalOrderCount() {
		totalOrderCount = 0;
	}

	public int getOrderNumber() {
		return orderNumber;
	}

	public ArrayList<OrderItem> getOrderItemList() {
		return orderItemList;
	}
	
	
}
