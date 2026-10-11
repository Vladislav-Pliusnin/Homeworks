struct Month {
    std::string value;
};

struct BudgetExceeded : DomainError {
    std::int64_t department_id;
    Month month;
    Money spent, requested, limit;
    BudgetExceeded(std::int64_t dept, Month m, Money s, Money r, Money l)
        : DomainError("Budget exceeded"), department_id(dept), month(m), spent(s), requested(r), limit(l) {}
};

class DepartmentBudget {
    std::int64_t department_id_;
    Month month_;
    Money limit_;
    Money spent_;
public:
    DepartmentBudget(std::int64_t dept, Month month, Money limit)
        : department_id_(dept), month_(month), limit_(limit), spent_(0) {}

    void allocate(Money amount) {
        if (amount.kopecks() > limit_.kopecks() - spent_.kopecks())
            throw BudgetExceeded(department_id_, month_, spent_, amount, limit_);
        spent_ = Money{spent_.kopecks() + amount.kopecks()};
    }

    void release(Money amount) {
        spent_ = Money{spent_.kopecks() - amount.kopecks()};
    }
};

struct DepartmentBudgetRepository {
    virtual std::optional<DepartmentBudget> load(std::int64_t dept, Month month) = 0;
    virtual void update(std::int64_t dept, Month month, const std::function<void(DepartmentBudget&)>& change) = 0;
    virtual ~DepartmentBudgetRepository() = default;
};

void ProcurementService::submit_request(RequestId req_id, std::int64_t dept_id, Month month) {
    requests.update(req_id, [&](PurchaseRequest& r) {
        r.submit(); 
    });
    budgets.update(dept_id, month, [&](DepartmentBudget& b) {
        b.allocate(r.total_amount()); 
    });
};