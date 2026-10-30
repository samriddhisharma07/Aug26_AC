const menu = [
            {id: 1, name: "Strawberry Cake", price: 450},
            {id: 2, name: "Chocolate Drip Fruit Cake", price: 550},
            {id: 3, name: "Caramel Cake", price: 400},
            {id: 4, name: "Blueberry Cake", price: 500},
            {id: 5, name: "Fruit Cake", price: 350},
            {id: 6, name: "White Chocolate Pastry", price: 90},
            {id: 7, name: "Chocolate Pastry", price: 80},
            {id: 8, name: "Vanilla Pastry", price: 70},
            {id: 9, name: "Mousse Pastry", price: 100},
            {id: 10, name: "Berry Cream Pastry", price: 90},
            {id: 11, name: "White Bread", price: 40},
            {id: 12, name: "Brown Bread", price: 50},
            {id: 13, name: "Whole Grain Bread", price: 60},
            {id: 14, name: "Bun Bread", price: 30},
            {id: 15, name: "Seed Sliced Bread", price: 65}
        ];

        let cart = [];
        let count = 1;

        const dropdown = document.getElementById("item");

        menu.forEach(function(product) {
            let option = document.createElement("option");
            option.setAttribute("value", product.id);
            option.innerHTML = product.name + " - ₹" + product.price;
            dropdown.appendChild(option);
        });

        function addOrder() {
            let id = parseInt(document.getElementById("item").value);
            let quantity = parseInt(document.getElementById("quantity").value);

            if (isNaN(quantity) || quantity <= 0) {
                document.getElementById("error").innerHTML =
                    "Please enter a valid quantity.";
                return;
            }

            document.getElementById("error").innerHTML = "";

            const product = menu.find(function(item) {
                return item.id === id;
            });

            const order = {
                id: product.id,
                name: product.name,
                price: product.price,
                quantity: quantity,
                lineId: count
            };

            count++;
            cart.push(order);

            showOrders();
            showBill();
        }

        function showOrders() {
            let list = document.getElementById("orderlist");
            list.innerHTML = "";

            cart.forEach(function(order) {
                let li = document.createElement("li");
                li.innerHTML = order.name + " x " + order.quantity +
                    " = ₹" + (order.price * order.quantity) + " ";

                let btn = document.createElement("button");
                btn.innerHTML = "Remove";

                btn.onclick = function() {
                    cart = cart.filter(function(item) {
                        return item.lineId !== order.lineId;
                    });

                    showOrders();
                    showBill();
                };

                li.appendChild(btn);
                list.appendChild(li);
            });
        }

        function applyRule(amount, rule) {
            return rule(amount);
        }

        function showBill() {
            const subtotal = cart.reduce(function(total, order) {
                return total + order.price * order.quantity;
            }, 0);

            const totalItems = cart.reduce(function(total, order) {
                return total + order.quantity;
            }, 0);

            const itemText = totalItems === 1 ? "item" : "items";

            document.getElementById("itemcount").innerHTML =
                "Total Items: " + totalItems + " " + itemText;

            const area = document.getElementById("area").value;
            let delivery = 0;

            switch (area) {
                case "local":
                    delivery = 30;
                    break;
                case "nearby":
                    delivery = 60;
                    break;
                case "far":
                    delivery = 100;
                    break;
                default:
                    delivery = 30;
            }

            let discount = 0;

            if (subtotal >= 2000) {
                discount = applyRule(subtotal, function(amount) {
                    return amount * 0.15;
                });
            } else if (subtotal >= 1000) {
                discount = applyRule(subtotal, amount => amount * 0.10);
            } else if (subtotal >= 500) {
                discount = applyRule(subtotal, amount => amount * 0.05);
            }

            const total = subtotal - discount + delivery;

            document.getElementById("bill").innerHTML =
                "Subtotal: ₹" + subtotal +
                "<br>Discount: ₹" + discount.toFixed(2) +
                "<br>Delivery Charge: ₹" + delivery +
                "<br>Total Bill: ₹" + total.toFixed(2);
        }

        function makeOrder() {
            return new Promise(function(resolve, reject) {
                setTimeout(function() {
                    if (cart.length === 0) {
                        reject("Please add an item to your order first.");
                    } else {
                        resolve("Order placed successfully! Order Number: " +
                            Math.floor(Math.random() * 10000));
                    }
                }, 2000);
            });
        }

        async function placeOrder() {
            document.getElementById("result").innerHTML = "Placing your order...";

            try {
                const message = await makeOrder();
                document.getElementById("result").innerHTML = message;
            } catch (error) {
                document.getElementById("result").innerHTML = error;
            }
        }

        setTimeout(function() {
            document.getElementById("offer").innerHTML =
                "Special Offer: Get 15% off on orders above ₹2000!";
        }, 3000);

        showBill();
