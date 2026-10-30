function validateUsername() {
    const username = document.getElementById("username").value.trim();
    document.getElementById("error").innerHTML = username === "" ? "Username is required." : "";
}

function validatePassword() {
    const password = document.getElementById("pswd").value;
    const pattern = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$/;
    document.getElementById("error1").innerHTML = pattern.test(password) ? "" : "Use 8+ characters with uppercase, lowercase, number and special character.";
}

function validate() {
    validateUsername();
    validatePassword();
    return document.getElementById("error").innerHTML === "" && document.getElementById("error1").innerHTML === "";
}

function show() {
    const password = document.getElementById("pswd");
    const button = document.getElementById("btn-show");
    if (button.innerHTML.toLowerCase() === "show") {
        password.setAttribute("type", "text");
        button.innerHTML = "Hide";
    } else {
        password.setAttribute("type", "password");
        button.innerHTML = "Show";
    }
}
