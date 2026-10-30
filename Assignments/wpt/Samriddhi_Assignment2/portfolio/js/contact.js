function validateName() {
    const name = document.getElementById("full-name").value.trim();
    document.getElementById("name-error").innerHTML = name === "" ? "Name is required." : "";
}

function validateEmail() {
    const email = document.getElementById("email").value.trim();
    const pattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    document.getElementById("email-error").innerHTML = pattern.test(email) ? "" : "Enter a valid email.";
}

function validate() {
    validateName();
    validateEmail();
    const phone = document.getElementById("phone").value.trim();
    const message = document.getElementById("message").value.trim();
    document.getElementById("phone-error").innerHTML = /^\d{10}$/.test(phone) ? "" : "Phone must contain exactly 10 digits.";
    document.getElementById("message-error").innerHTML = message.length >= 20 ? "" : "Message must contain at least 20 characters.";
    const valid = document.querySelectorAll(".error-span");
    for (const item of valid) {
        if (item.innerHTML !== "") {
            document.getElementById("thank-you").innerHTML = "";
            return false;
        }
    }
    document.getElementById("thank-you").innerHTML = `Thank you, ${document.getElementById("full-name").value.trim()}! Your message is ready.`;
    return false;
}
