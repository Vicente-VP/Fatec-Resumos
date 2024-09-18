var button = document.getElementById('productForm').children[6]; // sexta tag dentro do forms



//console.log(button);

document.getElementById('productForm').addEventListener("submit", (event)=>{
    event.preventDefault();
});


// Função pra adicionar e fazer a conta do preço do produto comprado e adcionar em uma lista
button.addEventListener("click", ()=>{
    var nome_prod = document.getElementById('productName').value;
    var preco = document.getElementById('productPrice').value;
    var quant = document.getElementById('productQuantity').value;

    var carrinho = document.getElementById("cart");

    // Uma maneira de fazer: carrinho.insertAdjacentHTML('afterEnd','nome =' + nome_prod + '<br>' + 'Preço =' + preco*quant + '<br>');

    var elementProduto = document.createElement('div');
    elementProduto.innerHTML = `Nome: ${nome_prod} <br> Preço: ${preco} X ${quant} = ${preco*quant}`;
    carrinho.appendChild(elementProduto);


    // Função pra retirar o elemento quando clicado 2x
    elementProduto.addEventListener('dblclick',(event) =>{
        carrinho.removeChild(event.target);
    });
});