const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

function setText(id, text) {
    document.getElementById(id).textContent = text;
}

function validateForm() {
    const name = document.getElementById("fullname").value.trim();
    const email = document.getElementById("email").value.trim();
    const qualification = document.getElementById("qualification").value;
    const department = document.getElementById("department").value;
    const status = document.getElementById("status");
    const submitButton = document.querySelector('button[type="submit"]');
    let valid = true;
    setText("nameerror", "");
    setText("emailerror", "");
    setText("qualerror", "");
    setText("deperror", "");
    if (name === "") {
        setText("nameerror", "Full name is required.");
        valid = false;
    }
    if (!emailPattern.test(email)) {
        setText("emailerror", "Enter a valid email.");
        valid = false;
    }
    if (qualification === "") {
        setText("qualerror", "Select qualification.");
        valid = false;
    }
    if (department === "") {
        setText("deperror", "Select department.");
        valid = false;
    }
    if (!valid) return false;
    submitButton.disabled = true;
    status.style.color = "black";
    createAccount(name).then(sendEmail).then(assignLaptop).then(function (employeeName) {
        status.style.color = "green";
        status.textContent = `Welcome aboard, ${employeeName}!`;
    }).catch(function (error) {
        status.style.color = "red";
        status.textContent = error;
    }).finally(function () {
        submitButton.disabled = false;
    });
    return false;
}

function createAccount(name) {
    return new Promise(function (resolve, reject) {
        setText("status", "Creating your account...");
        setTimeout(function () {
            if (name.length < 3) reject("Name must contain at least 3 characters.");
            else resolve(name);
        }, 1000);
    });
}

function sendEmail(name) {
    return new Promise(function (resolve) {
        setText("status", "Sending welcome email...");
        setTimeout(function () { resolve(name); }, 2000);
    });
}

function assignLaptop(name) {
    return new Promise(function (resolve) {
        setText("status", "Assigning your laptop...");
        setTimeout(function () { resolve(name); }, 1500);
    });
}

function clearStatus() {
    setText("status", "");
    setText("nameerror", "");
    setText("emailerror", "");
    setText("qualerror", "");
    setText("deperror", "");
}
