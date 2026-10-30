let employees = [];

async function load() {
    try {
        document.getElementById("errorid").innerHTML = "";
        const response = await fetch("https://jsonplaceholder.typicode.com/users");
        console.log(response.status);
        if (!response.ok) {
            throw new Error("Request failed");
        }
        const data = await response.json();
        employees = data.map(({ id, name, username, email, phone }) => {
            const employee = { id, name, username, email, phone };
            return { ...employee, department: "-" };
        });
        renderTable();
    } catch (error) {
        document.getElementById("errorid").innerHTML = "Error loading employees. Please check your internet connection.";
    }
}

function renderTable() {
    const table = document.getElementById("tbodyid");
    table.innerHTML = "";
    const field = document.getElementById("field").value;
    const text = document.getElementById("searchbox").value.toLowerCase();
    const search = { [field]: text };
    const filteredEmployees = employees.filter(employee => String(employee[field] || "").toLowerCase().includes(search[field]));
    filteredEmployees.forEach(employee => {
        const { id, name, department, email, phone } = employee;
        const row = document.createElement("tr");
        [id, name, department, email, phone].forEach(value => {
            const cell = document.createElement("td");
            cell.textContent = value;
            row.appendChild(cell);
        });
        const actionCell = document.createElement("td");
        const removeButton = document.createElement("button");
        removeButton.textContent = "Remove";
        removeButton.onclick = function () {
            employees = employees.filter(item => item.id !== id);
            row.remove();
            updateTotal();
            renderTable();
        };
        actionCell.appendChild(removeButton);
        row.appendChild(actionCell);
        table.appendChild(row);
    });
    updateTotal();
}

function updateTotal() {
    document.getElementById("pid").innerHTML = `Total employees: ${employees.length}`;
}

function searchEmployee() {
    renderTable();
}

document.getElementById("addform").addEventListener("submit", function (event) {
    event.preventDefault();
    const name = document.getElementById("empname").value.trim();
    const department = document.getElementById("department").value.trim();
    if (name === "" || department === "") return;
    const id = employees.length > 0 ? Math.max(...employees.map(employee => employee.id)) + 1 : 1;
    const username = name.toLowerCase().replace(/\s+/g, "");
    const email = "-";
    const phone = "-";
    const employee = { id, name, username, email, phone };
    const newEmployee = { ...employee, department };
    employees.push(newEmployee);
    renderTable();
    document.getElementById("addform").reset();
});
